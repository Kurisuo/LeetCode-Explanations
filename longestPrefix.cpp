//LeetCode 14

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        //find the smallest string by taking strs[0] and comparing to rest in the arr
        //for (; i < smallestStr; ++i)
        // 
        string lngPrefix = ""; //string where longest prefix is stored

        int smallestStr = strs[0].length(); //gets us the starting length
        
        for(string &x : strs){ //string &x because we have a vector of string
            smallestStr = min(smallestStr, (int) x.size()); //must cast x to a int
        }

        for(int i = 0; i < smallestStr; i++){ //outer loop for iterating up until smallest str length and iterating through chars of first string

            auto currPrefix = strs[0][i]; //gets us char of the first string in arr
            for(string &s : strs){  //check all other strings

                if (s[i] != currPrefix){ //compare first char of current string to currPrefix
                    return lngPrefix; //if not equal to return current currPrefix 
                }

            }
            lngPrefix.push_back(currPrefix);
        }

        return lngPrefix;
    }
};