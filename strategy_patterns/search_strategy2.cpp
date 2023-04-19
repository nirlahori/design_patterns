#include<iostream>
#include<array>
#include<vector>
#include<functional>
#include<algorithm>
#include<chrono>
#include<fstream>
/*	
	This program is a demonstration of strategy pattern through std::function.
	It uses search algorithms as a context. Additionally, it is used to compare
	different searching algorithms for their performance.
*/


#define PRINT(str) std::cout << str << std::endl;


int linear_search(std::string k, std::vector<std::string>& v){

	for(size_t i=0; i<v.size(); i++){
		if(v[i] == k)
			return i - 1;
	}
	return -1;
}

bool str_sort(const std::string& s1, const std::string& s2){ 
	auto v1 = std::stoi(s1);
	auto v2 = std::stoi(s2);
	return v1 < v2;
}

int binary_search(std::string k, std::vector<std::string>& v){

	std::sort(v.begin(), v.end(), str_sort);
	int first = 0;
	int last = v.size() - 1;

	while(first <= last){
		int mid = (first + last) / 2;
		if(v[mid] == k)
			return mid - 1;
		else if(v[mid] > k){
			last = mid - 1;
		}
		else
			first = mid + 1;
	}	
	return -1;
}

int sorted_binary_search(std::string k, std::vector<std::string>& v){

	int first = 0;
	int last = v.size() - 1;
	
	while(first <= last){
		int mid = (first + last) / 2;
		if(v[mid] == k)
			return mid - 1;
		else if(v[mid] > k){
			last = mid - 1;
		}
		else
			first = mid + 1;
	}
	return -1;
}

/*
	class for managing data and search strategy implementation.
	It takes the std::function object as an argument for 
	providing different search implementations.
*/
class group{
	private:
		std::vector<std::string> g_items;
		std::function<int(std::string, std::vector<std::string>&)> g_srch;
	public:

		group(const std::vector<std::string>& v, const std::function<int(std::string, std::vector<std::string>&)>& g_func) : g_items{v}, g_srch{g_func} {}
	
		void attach(std::string value){		// Insert data into container
			g_items.push_back(value);
		}
		void show(){	// Print the container data
			for(std::string i : g_items)
				PRINT(i);
		}
		int find(std::string value){	// Call this function to search for the data in the container
			return g_srch(value, g_items);
		}
};

int main(){

	

	std::vector<std::string> vint2;
	for(int i=0; i<1000000; i++)
		vint2.push_back(std::to_string(i));
	group g2{vint2, sorted_binary_search};
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	PRINT(g2.find(std::to_string(688345)));
	PRINT(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start).count());

	return 0;	
}
