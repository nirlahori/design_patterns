#include<iostream>
#include<array>
#include<algorithm>


/*	Program for demonstration of strategy pattern using virtual functions. The program uses sorting algorithms to demonstrate	*/


#define PRINT(str) std::cout << str << std::endl;

/*	base class for custom implementation of sort algorithm using function overriding */
class sort_impl{

	public:
		virtual void order(const std::array<int, 10> ar) = 0;	//	Override the function in derived class to provide custom implementation
};

/*	
	class for managing data and custom implementation.
	It contains the data in the std::array object and
	takes pointer to sort_impl as an argument for
	supplying custom implementation for sorting.

*/
class sort{

	private:
		std::array<int, 10> ar;
		sort_impl* sort_stgy;
	public:
		sort() = default;
		sort(const std::array<int, 10>& _ar, sort_impl* si) : ar{_ar}, sort_stgy{si} {}
		void shuffle() const{		// call this function on sort object for sorting data
			sort_stgy->order(ar);
		}
};

/*
	Classes that override order function from sort_impl to provide their own implementation
*/
struct mysort : sort_impl{
	void order(std::array<int, 10> ar) override{
		PRINT("Using mysort algorithm to sort");
		std::sort(ar.begin(), ar.end());
		for(int p : ar)
			PRINT(p);
	}
};

struct speedsort : sort_impl{
	void order(std::array<int, 10> ar) override{
		PRINT("Using speedsort algorithm to sort");
		std::sort(ar.begin(), ar.end());
		for(int p : ar)
			PRINT(p);
	}
};

struct test_algo : sort_impl{
	void order(std::array<int, 10> ar) override{
		PRINT("For testing purpose");
		std::sort(ar.begin(), ar.end());
		for(int p : ar)
			PRINT(p);
	}
};

int main(){

	mysort ms;
	speedsort sps;
	test_algo test1;

	std::array<int, 10> x1 {23, 45, 76, 8, 48, 84, 72, 37, 29, 49};


	sort s1{x1, &ms};	// create sort object with mysort strategy
	sort s2{x1, &sps};	// create sort object with speedsort strategy
	sort s3{x1, &test1};	// create sort object with test_algo strategy
	
	s1.shuffle();	// sort the data using mysort algorithm
	s2.shuffle();	// sort the data using speedsort algorithm
	s3.shuffle();	// sort the data using test_algo algorithm
}
