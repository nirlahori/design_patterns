#include<iostream>
#include<thread>
#include<utility>


int main(){


	std::thread t1 (
		[] {std::cout << "Thread t1\n";}
	);
	std::thread t2 (
		[] {std::cout << "Thread t2\n";}
	);

	t1.join();

	t1 = std::move(t2);

	t1.join();
	t2.join();

	return 0;

}
