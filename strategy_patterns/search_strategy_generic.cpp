#include<iostream>
#include<array>
#include<vector>
#include<functional>
#include<algorithm>
#include<chrono>

#define PRINT(str) std::cout << str << std::endl;

/*
	This program is a demonstration of strategy pattern through function templates.
	It uses search algorithms as a context. Additionally, it is used to compare
	different searching algorithms for their performance.
*/

template<typename Find>
int linear_search(Find value, std::vector<Find>& v){

	for(size_t i=0; i<v.size(); i++){
		if(v[i] == value)
			return i - 1;
	}
	return -1;
}

template<typename Find>
int binary_search(Find value, std::vector<Find>& v){

	std::sort(v.begin(), v.end());

	int first = 0;
	int last = v.size() - 1;

	while(first <= last){
		int mid = (first + last) / 2;
		if(v[mid] == value)
			return mid - 1;
		else if(v[mid] > value){
			last = mid - 1;
		}
		else
			first = mid + 1;
	}	
	return -1;
}

template<typename Find>
int sorted_binary_search(Find value, std::vector<Find>& v){

	int first = 0;
	int last = v.size() - 1;
	
	while(first <= last){
		int mid = (first + last) / 2;
		if(v[mid] == value)
			return mid - 1;
		else if(v[mid] > value){
			last = mid - 1;
		}
		else
			first = mid + 1;
	}
	return -1;
}

/*
	Class template that stores container and std::function object.
	Initialize the class template with the type that will be an 
	underlying type of the container. It uses std::vector as
	container.
*/

template<typename Elem>
class group{
	private:
		std::vector<Elem> g_items;
		std::function<int(Elem, std::vector<Elem>&)> g_srch;
	public:

		group(const std::vector<Elem>& v, const std::function<int(Elem, std::vector<Elem>&)>& g_func) : g_items{v}, g_srch{g_func} {}
	
		void attach(Elem value){	// Insert data into container
			g_items.push_back(value);
		}
		void show(){	// Print the container data
			for(Elem i : g_items)
				PRINT(i);
		}
		int find(Elem value){	// Call this function to search for the data in the container
			return g_srch(value, g_items);
		}
};

int main(){


	std::vector<int> vint2;
	for(int i=0; i<1000000; i++)
		vint2.push_back(i);
	group<int> g2{vint2, sorted_binary_search<int>};
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	PRINT(g2.find(657436));
	PRINT(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count());

	return 0;	
}
