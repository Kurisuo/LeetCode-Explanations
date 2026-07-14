class Solution {
    public:
        int maxArea(vector<int>& height) {
            
            int left = 0;
            int right = height.size() - 1;
            int maxArea = 0;
    
            while(left < right){
                int width = right - left;
    
                if(height[left] < height[right]){
                    maxArea = max(maxArea, width * height[left]);
                    left++;
                }
                else {
                   maxArea = max(maxArea, width * height[right]);
                   right--;
                }
            }
            return maxArea;
        }
    };