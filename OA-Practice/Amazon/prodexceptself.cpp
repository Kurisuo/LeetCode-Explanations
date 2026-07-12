class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
        
        int length = nums.size();
        
        vector<int>prefix(length, 1);
        vector<int>postfix(length, 1);
        vector<int>ans(length, 1);
    
        for(int i = 1; i < length; i++){
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        for(int i = length - 2; i >= 0; i--){
            postfix[i] = postfix[i + 1] * nums[i + 1];
        }
    
    
        for(int i = 0; i < length; i++){
            ans[i] = prefix[i] * postfix[i];
        }
    
                return ans;
        }
    };