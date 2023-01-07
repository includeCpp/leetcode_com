#include<iostream>
#include<vector>
#include<algorithm>

//https://leetcode.com/problems/fizz-buzz/


class Solution_2 {
public:
    std::vector<std::string> fizzBuzz(int n) {
    	if(n < 1){
    		throw std::invalid_argument{"n < 1"};
    	}
        std::vector<std::string> out(n);
        for(size_t i = 0; i < n; i++){
        	if(0 == ((i + 1) % 3)){
        		out[i] = "Fizz";
        	}
        	if(0 == ((i + 1) % 5)){
        		out[i] += "Buzz";
        	} 
        	if((i + 1) % 3 && (i + 1) % 5){
        		out[i] = std::to_string(i + 1);
        	}
        }
		return out;
    }
};


int main(){



	return 0;
}

//