#include<iostream>
#include<array>
#include<vector>
#include<algorithm>

/*	Demonstration of Strategy Pattern through template specialization. The program uses sorting algorithms as a context. */

template<typename T>
void order(T&);	// Function template to be used for specializing and implementing our own algorithm.


#define PRINT(str) std::cout << str << std::endl;


/*
	Function template specialization for different types.
*/
template<>
void order(std::array<int, 10>& ar){
	PRINT("Using array specialization implementation to sort array");
	std::sort(ar.begin(), ar.end());
	for(int i : ar)
		PRINT(i);
}

template<>
void order(std::vector<int>& v){
	PRINT("Using vector specialization implementation to sort vector");
	std::sort(v.begin(), v.end());
	for(int i : v)
		PRINT(i);
}

template<>
void order(std::array<double, 7>& ar){
	PRINT("Using array double specialization implementation to sort array of double");
	std::sort(ar.begin(), ar.end());
	for(double i : ar)
		PRINT(i);
}


/*
	Class template for storing data.
	It doesn't take an object representing custom
	implementation as it will be automatically
	determined which function to call depending on
	type of data.
*/
template<typename T>
class sort{

	private:
		T elems;

	public:
		sort(const T& _e) : elems{_e} {}
		void shuffle(){
			order(elems);
		}
};

int main(){

	std::array<int, 10> ar{45, 67, 2, 65, 76, 87, 42, 32, 57, 85};
	std::vector<int> v{45, 67, 23, 54, 94};

	sort<std::array<int, 10>> s1{ar};
	sort<std::vector<int>> s2{v};
	sort<std::array<double, 7>> s3{{4.5, 78.3, 37.36, 58.2, 74.58, 26.47, 64.37}};

	//	sort the data using appropriate specialization
	s1.shuffle();
	s2.shuffle();
	s3.shuffle();

	return 0;
}
