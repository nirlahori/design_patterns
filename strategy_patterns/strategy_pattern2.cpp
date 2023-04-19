#include<iostream>
#include<functional>
#include<array>
#include<algorithm>


/*	Program for demonstration of strategy pattern using std::function. The program uses sorting algorithms to demonstrate	*/


#define PRINT(str) std::cout << str << std::endl;

/*
	class for managing data and std::function object
	This class takes data and sorting algorithm as
	arguments. Provide the own implementation as
	an argument to std::function parameter. 

*/
class sort{

	private:
		std::array<int, 10> elems;
		std::function<void(std::array<int, 10>)> sort_ptr;	// stores user provided implementation
	public:
		sort(const std::array<int, 10>& data, const std::function<void(std::array<int, 10>)>& _ptr) : elems{data}, sort_ptr{_ptr} {}
		void shuffle(){		// call this function on sort object for sorting data
			sort_ptr(elems);
		}
};


/*	Implementation of different sorting algorithms	*/
void mysort(std::array<int, 10> ar){
	PRINT("Using mysort implementation to sort array");
	std::sort(begin(ar), end(ar));
	for(int i : ar)
		PRINT(i);
}

void speedsort(std::array<int, 10> ar){
	PRINT("Using speedsort implementation to sort array");
	std::sort(begin(ar), end(ar));
	for(int i : ar)
		PRINT(i);
}

int main(){

	std::array<int, 10> x{24, 56, 75, 76, 32, 43, 64, 43, 53, 2};	

	sort s1{x, mysort};		// create sort object with mysort strategy
	sort s2{x, speedsort};	// create sort object with speedsort strategy

	s1.shuffle();	// sort the data using mysort strategy
	s2.shuffle();	// sort the data using speedsort strategy
	return 0;	
	
}
