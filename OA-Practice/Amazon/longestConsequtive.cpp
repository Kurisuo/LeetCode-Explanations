class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int frequency = INT_MIN;
        if(nums.empty()){return 0;}

        unordered_set<int> set(nums.begin(), nums.end());

        // a number is the beginning when num - 1 does not exist or 
        // num at num - 1 != num - 1 

        for(int num : set) {
            //check if the number is the beginning
            if(set.count(num - 1) == 0){
                int current = num;
                int streak = 1;
                //checks if the next number + 1 exists
                while(set.count(current + 1)){
                    current++;
                    streak++;
                }      

                frequency = max(frequency, streak);
            }
        }

        return frequency;
    }   
};