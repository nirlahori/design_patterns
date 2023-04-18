#include<iostream>
#include<thread>
#include<unistd.h>

void add(){
	std::cout << "C++ Thread\n";
	sleep(5);
}


int main(){


	std::thread t1(add);

	std::cout << "thread created\n";

	t1.join();

	std::cout << "main thread waiting\n";
	std::cout << "main thread ended\n";
	return 0;

}
