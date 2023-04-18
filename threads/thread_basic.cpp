#include<iostream>
#include<thread>
#include<vector>
#include<chrono>

using namespace std::chrono_literals;

void sum(){
	std::vector<std::string> v;
	for(int i=0; i<10000000; i++)
		v.push_back(std::to_string(i));
	int sum = 0;
	for(auto i : v)
		sum +=std::stoi(i);
	std::cout << sum << std::endl;
	std::this_thread::sleep_for(5s);
}

void add(){
	std::vector<std::string> v;
	for(int i=0; i<10000000; i++)
		v.push_back(std::to_string(i));
	int sum = 0;
	for(auto i : v)
		sum += std::stoi(i);
	std::cout << sum << std::endl;
	std::this_thread::sleep_for(5s);
}



int main(){


	std::thread t1{sum};
	std::thread t2{add};

	t1.join();
	t2.join();

	return 0;	
}
