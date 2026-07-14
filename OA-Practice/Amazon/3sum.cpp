
        //sort array
        //hard fix i to be the first value in the triplet

        //find every number that matches with it
        //advance i 
        //set 2-pointers to the next two values starting form the new ith position \

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3){
            return {};
        }

        vector<vector<int>> store;
        sort(nums.begin(), nums.end());
   

        for(int fixed = 0; fixed < nums.size() - 2; fixed++){

                    if(nums[fixed] > 0){
                        break;
                    }
                    
                    if(fixed > 0 && nums[fixed] == nums[fixed - 1]) continue;

                    int left = fixed + 1;
                    int right = nums.size() - 1;

                    while(left < right){

                    
                        int sum = nums[fixed] + nums[left] + nums[right];
                        
                        if(sum == 0){
                            store.push_back({nums[fixed], nums[left], nums[right]});

                            while(left < right && nums[left] == nums[left + 1]) left++;
                            while(left < right && nums[right] == nums[right - 1]) right--;

                            left++;
                            right--;

                        }
                        else if (sum < 0){
                            left++;
                        }
                        else {
                            right--;
                        }

                    }
            
        }

        return store;
    }
};