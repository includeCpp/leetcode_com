#include<iostream>
#include<vector>
#include<algorithm>

//https://leetcode.com/problems/integer-to-roman/


class Solution_1 {
public:
    int romanToInt(std::string s) {
        int answer = 0;
        if(s.size() == 0){
            return 0;
        }
        else if(s.size() == 1){
        	answer += roman_to_int_map(s[s.size() - 1]);
        } else{
	        for(int i = 0; i < s.size() - 1; i++){
	        	std::cout << answer << std::endl;
	            if(roman_to_int_map(s[i]) >= roman_to_int_map(s[i + 1])){
	                answer += roman_to_int_map(s[i]);
	            } else{
	                answer -= roman_to_int_map(s[i]);
	            }
	        }
	        answer += roman_to_int_map(s[s.size() - 1]);
	    }
        return answer;
    }
    
private:
    int roman_to_int_map(char ch){
        switch(ch){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        throw std::invalid_argument{"Invalid symbol."};
    }
};


int main(){

	

	

	return 0;
}


//