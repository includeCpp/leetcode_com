#include<iostream>
#include<vector>
#include<algorithm>

//https://leetcode.com/problems/arithmetic-slices/


class Solution {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        if(nums.size() <= 2){
        	return 0;
        }
	    std::size_t sub_arrays_qty = 0;
        for(auto it_begin = nums.begin(); it_begin != nums.end() - 2; it_begin++){
	       	auto it_begin_copy = it_begin;
	        auto it_end = it_begin;
	        it_end++;
	        int difference = *it_end - *it_begin;
	        std::size_t sub_array_size = 1;
	        it_end++;
	        it_begin_copy++;
	       	while((difference == *it_end - *it_begin_copy) && (it_end != nums.end())){
        		sub_array_size++;
        		it_begin_copy++;
        		it_end++;
        	}
        	/*do{
        		sub_array_size++;
        		it_begin_copy++;
        		it_end++;
        	} while((difference == *it_end - *it_begin_copy) && (it_end != nums.end()));*/
        	sub_arrays_qty += sub_array_size - 2;
	    }
        return sub_arrays_qty;
    }
};

class Solution_3 {
public:
    int numberOfArithmeticSlices(std::vector<int>& nums) {
        if(nums.size() <= 2){
        	return 0;
        }
        int sub_arrays_qty = 0;
        for(std::size_t i = 0; i < nums.size() - 2; i++){
        	int difference = nums[i + 1] - nums[i];
        	int sub_array_size = 2;
        	//counts size of the biggest subarray with current index
        	for(int j = i + 1; j < nums.size() - 1; j++){
	    		if(difference == nums[j + 1] - nums[j]){
	    			sub_array_size++;
	    		} else{
	    			break;
	    		}
	    	}
	    	sub_arrays_qty += sub_array_size - 2;
        }
        return sub_arrays_qty;
    }
};



int main(){



	

	return 0;
}

//