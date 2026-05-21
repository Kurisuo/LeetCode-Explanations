#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = 0;
        int prevTwoHouses = 0;

        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }

        for(int current : nums){ 
            prevHouse = max(current + );

        }

        return prev1;
    }
};