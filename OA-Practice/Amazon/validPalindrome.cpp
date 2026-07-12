class Solution {
public:
    bool isPalindrome(string s) {
 
        if(s == " "){
            return true;
        }

        int j = 0;

        //remove non alphabet figures
        for(int i = 0; i < s.size(); i++){
            if(  (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') ){
                s[j] = s[i];
                j++;
            }
        }

        for(auto& x : s){
            x = tolower(x);
        }

        int left = 0;
        int right = j - 1;


        while(left < right){
            if(s[left] != s[right]){
                return false;
            }

            left++;
            right--;
        }



        return true;
    }   
};