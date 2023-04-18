#include<iostream>
#include<thread>
#include<unistd.h>
#include<mutex>

std::mutex m;
void add(int a, int b){
	sleep(5);
	m.lock();
	std::cout << a + b << "\n";
	m.unlock();
}


int main(){


	std::thread t1 (add, 100, 90);
	std::thread t2 (add, 26, 34);
	std::thread t3 (add, 76, 43);
	std::thread t4 (add, 93, 34);
	std::thread t5 (add, 12, 45);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();

	return 0;

}
