#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex m;

void fun()
{
	//A more fine grained approach to locking with the help of unique_lock.
	//This object instance cannot be copied, 
	//but can be moved with the help of 'move' function. Unline lock_guard which
	//cannot be copied nor moved.
	unique_lock<mutex> locker(m, defer_lock);  
	//... some business here which does not require a mutex locking here...

	//Code for synchronizing starts here....
	//Thereby now acquire the lock
	locker.lock();
	//Code to be executed upon lock here...
	//...
	locker.unlock();   //unlock the mutex 

	//... some business here which does not require a mutex locking here...

	//Code for synchronizing starts here....
	//Thereby now acquire the lock
	locker.lock();
	//Code to be executed upon lock here...
	//...
	locker.unlock();   //unlock the mutex 
}