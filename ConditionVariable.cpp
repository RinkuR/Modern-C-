#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

/*
-A condition variable manages a list of threads waiting until another
thread notifies them.

- Each thread that wants to wait on the condition variable has to
acquire a lock first.The lock is then released when the thread
starts to wait on the condition and the lock is acquired again
when the thread is awakened.
*/
/*
Example:
A concurrent Bounded Buffer. It’s a cyclic buffer with a certain capacity with a start and an end.
*/
struct BoundedBuffer {
	int* buffer;
	int capacity;

	int front;
	int rear;
	int count;

	mutex lock;

	condition_variable not_full;
	condition_variable not_empty;

	BoundedBuffer(int capacity) : capacity(capacity), front(0), rear(0), count(0)
	{
		buffer = new int[capacity];
	}

	~BoundedBuffer()
	{
		delete[] buffer;
	}

	void deposit(int data)
	{
		unique_lock<std::mutex> l(lock);
		//The waiting will continue till predicate returns false
		not_full.wait(l, [this]() {return count != capacity; });

		buffer[rear] = data;
		rear = (rear + 1) % capacity;
		++count;

		l.unlock();
		not_empty.notify_one();
	}

	int fetch()
	{
		unique_lock<std::mutex> l(lock);

		not_empty.wait(l, [this]() {return count != 0; });

		int result = buffer[front];
		front = (front + 1) % capacity;
		--count;

		l.unlock();
		not_full.notify_one();

		return result;
	}
};

/*
- The mutexes are managed by a std::unique_lock.It is a wrapper to manage a lock.
- This is necessary to be used with the condition variables.
- To wake up a thread that is waiting on a condition variable, the notify_one()
function is used.
- The unlock before the notify_one is not totally necessary.
- If you omit it, it will be done automatically by destructor of the unique_lock.
- But, it is then possible that the notify_one() call will wake up a waiting thread
that will then directly block again since the lock itself is still locked by
the notifier thread.
- Therefore, if you do it before, the notified thread should be able to get the
lock directly.
- Therefore, it's a slight optimization, but it won't make a lot of differences.
- The wait function is a bit special.
- It takes as the first argument the unique lock and a the second one a predicate.
- The predicate must return false when the waiting must be continued


- We can use this structure to fix multiple consumers / multiple producers problem.
- This problem is very common in concurrent programming.
- Several threads(consumers) are waiting from data produced by another several
threads(producers).
*/
void consumer(int id, BoundedBuffer& buffer)
{
	for (int i = 0; i < 50; ++i)
	{
		int value = buffer.fetch();
		cout << "Consumer " << id << " fetched " << value << endl;
		this_thread::sleep_for(chrono::milliseconds(250));
	}
}

void producer(int id, BoundedBuffer& buffer)
{
	for (int i = 0; i < 75; ++i)
	{
		buffer.deposit(i);
		cout << "Produced " << id << " produced " << i << std::endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

int main()
{
	BoundedBuffer buffer(200);

	thread c1(consumer, 0, ref(buffer));
	thread c2(consumer, 1, ref(buffer));
	thread c3(consumer, 2, ref(buffer));
	thread p1(producer, 0, ref(buffer));
	thread p2(producer, 1, ref(buffer));

	c1.join();
	c2.join();
	c3.join();
	p1.join();
	p2.join();

	return 0;
}
