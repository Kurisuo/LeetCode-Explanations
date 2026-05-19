//Leetcode Medium 1447
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    int num;
    int den;
    vector<string> fractions; //array

    vector<string> simplifiedFractions(int n){
      
        for (int i = 2; i <= n; i++){      
            den = i;
            for(int j = 1; j < i ; j++){
                num = j;
                if (std::gcd(num, den) == 1){
                    fractions.push_back(std::to_string(num) + "/" + std::to_string(den));
                }
            }
        }
        return fractions;
    }
};


//First attempt at this leetcode
//Redundant use of den & num, can substitute for i and j
//can also make our own gcd helper function to not rely on a library
