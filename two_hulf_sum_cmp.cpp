#include<iostream>
#include<vector>
#include<algorithm>


class two_half_summ_cmp{
public:
	template<typename T>
	int summ_of_elements(T& Array){
		int summ = 0;
		for(auto arg : Array){
			summ += arg;
		}
		//return ((summ & 1) == 1 ? false : true);
		return summ;
	}

	template<typename T>
	int get_max(T& Array){
		int max = 0;
		for(int i = 0; i < Array.size(); i++){
			if(Array[i] > max) max = Array[i];
		}
		for(int i = 0; i < Array.size(); i++){
			if(Array[i] == max){
				Array[i] = 0;
				return max;
			}
		}
		return max;
	}

	template<typename T>
	bool difference_foo(T& difference){

	}

	/*template<typename T, typename Q>
	bool recursion_foo(T& Array, int& difference, int j = 0){
		int tmp = get_max(Array);
		if(std::find(Array.begin(), Array.end(), difference) != Array.end()) return 1;
		for(int i = 0; i < Array.size() || difference > 0; i++){

		}
	}*/

	template<typename T>
	bool main_foo(T& Array){
		if(!isEven(summ_of_elements(Array))) return 0;
		int halh = summ_of_elements(Array) / 2;
		int max = get_max(Array);
		if(half < max) return 0;
		int difference = half - max;
		if(std::find(Array.begin(), Array.end(), difference) != Array.end()) return 1;
		//main algorithm
		std::vector<int> less_than_diff(0);
		int back_up = difference;
		for(int i = 0; i < Array.size(); i++){
			difference = half - max;
			difference -= Array[i];
			if(std::find(Array.begin(), Array.end(), difference) != Array.end()) return 1;
			//
			for(auto c : Array){
				if(c < difference) less_than_diff.push_back(c);
			}
			//
			for(int j = i + 1; j < Array.size(); j++){
				difference -= Array[j];
				if(std::find(Array.begin(), Array.end(), difference) != Array.end()) return 1;
				if(0 < difference){
					back_up = difference;
				} else{
					if(i < Array.size() - 1){
						break;
					} else{
						return 0;
					}
				}
			}
		}
		return (0 == half ? true : false);
	}

private:
};

int main(){



	return 0;
}


/*std::vector<char> v(50);
for(std::size_t i = 0; i < v.size(); i++){
	v[0] = 92;
	v[i] = 45;
	//v[v.size() - 1] = 47;
}

int n = 1;
while(n != 0){
	int g = 0;
	while(g != v.size() + 1){
		for(int i = 0; i < v.size(); i++){
			std::cout << v[i];
			v[g] = 32;
			v[g + 1] = 92;
			if(i > g + 1){
				v[i] = 45;
			}
		}
		g++;
		std::cout << std::endl;
	}
	while(g >= 0){
		for(int i = 0; i != v.size(); i++){
			std::cout << v[i];
			v[g] = 32;
			v[g - 1] = 47;
			if(i < g - 1){
				v[i] = 45;
			}
		}
		g--;
		std::cout << std::endl;	
	}

} */

std::vector<int> spare_ints(0);
int back_up = difference;
int back_up_2 = difference;
for(int i = 0; i < Array.size(); i++){
	for(int j = 0; j < Array.size(); j++){
		if(std::find(spare_ints.begin(), spare_ints.end(), Array[j]) != spare_ints.end()) continue;
		else{
			difference -= Array[j];
			if(difference == 0) return 1;
			else if(difference < 0){
				spare_ints.push_back(Array[j]);
				spot = j;
				if(j > 1){
					j -= 2;
					for(int g = 0; g < j; g++){
						back_up -= Array[g];
					}
				} else{
					j = 0;
				}
				difference = back_up;
			}
			if(std::find(Array.begin(), Array.end(), difference) != Array.end()) return 1;
		}
	}
}



//