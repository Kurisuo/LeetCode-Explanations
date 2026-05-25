#include <vector>
using namespace std;


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //arrange so that all nested vectors are stacked on top of each other, all index 0s?
        //check through all index 0s, and index 1s?
        //we can sort from least to greatest to avoid double comparison
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right){
            return left[0] < right[0];});

        for (int x = 1; x < intervals.size(); x++){ 
            if(intervals[x][0] < intervals[x - 1][1]){ 
                return false;
            }
        }
        return true;
    }
};