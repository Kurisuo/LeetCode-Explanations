//LeetCode 2574 Left and Right Sum Differences 
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        vector<int>leftSum(nums.size());
        vector<int>rightSum(nums.size());
        vector<int>answer;

        leftSum[0] = 0;
        rightSum[nums.size() - 1] = 0;

    //    int sum = 0;
        for (int i = 1; i < nums.size(); i++){ 
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = nums.size() - 2; i >= 0; i--){ 
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for(int i = 0; i < nums.size(); i++){ 
            answer.push_back(abs(leftSum[i] - rightSum[i]));
        
        }
 
        return answer;
    }
};