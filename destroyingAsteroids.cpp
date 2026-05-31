//LeetCode 2126 (Medium) Destoying Asteroids
#include <vector>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long track_mass = mass;
        sort(asteroids.begin(), asteroids.end());
        for(const long& x : asteroids){ 

            if(track_mass < x){ 
                return false;
            }
            track_mass += x;
        }
        return true; 
    }
};