//LeetCode 3: Longest Substring without repeating characters

//Given a string s, find the length of the longest substring without duplicate characters.

//We can use a dynamic sliding window giving us close to O(N) time

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
        
            unordered_map<char, int> map;
            int longest = 0;
            int left = 0;


            for(int right = 0; right < s.size(); right++){

                while(map.contains(s[right])){
                    
                    map.erase(s[left]);
                    left++;
                }


                map.insert({s[right], 1});
                longest = max(longest, right - left + 1);

            }


                return longest;
            }
    
    
    };