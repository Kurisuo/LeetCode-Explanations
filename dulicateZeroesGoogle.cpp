//LeetCode Dupe Zeroes - Google Assessment 

class Solution {

public:
    void duplicateZeros(vector<int>& arr) {
        
        int length = arr.size();
        int i = 0;
        
        while(i < length){
            if(arr[i] == 0){
                arr.insert(arr.begin() + i, 0);
                i+=2; //skip new zero  
       
            }
            else{ 
                i++;
            }
        
        }
        arr.resize(length);
    }
    
};