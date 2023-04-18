#include<iostream>
#include<utility>
#include<thread>
#include<initializer_list>

class add{

	private:
		int a;
		int b;
	public:
		void operator()(int x, int y){
			std::cout << x + y << "\n";
		}
		void operator()(auto var){
			std::cout << var << "\n";
		}
};


int main(){


	add a{};
	add a1;
	//a();
	std::thread t1 (a, 900);
	std::thread t2 (a1, "hello");
	//scoped_thread st1 = (t1);

	t1.join();
	t2.join();
}
