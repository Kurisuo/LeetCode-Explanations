//LeetCode 243 Shorted Word Distance

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
            int wrd1 = -1, wrd2 = -1;
            int minD = INT_MAX;

            for(int i = 0; i < wordsDict.size(); i++){ 
                if(wordsDict[i] == word1){ 
                    wrd1 = i;
                    if(wrd2 != -1){  //for when wrd2 has been found first
                        minD = min(minD, wrd1 - wrd2); 
                    }

                }
                else if(wordsDict[i] == word2){ 
                    wrd2 = i;
                    if(wrd1 != -1){ 
                        minD = min(minD, wrd2 - wrd1);
                    }
                }

            }

            return minD;
        }



    
};