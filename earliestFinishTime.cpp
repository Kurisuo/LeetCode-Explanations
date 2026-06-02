//LeetCode 3633 Earliest Finish Time for Land and Water Rides I
class Solution {
public:

    int findTime(vector<int>& firstTime, vector<int>& firstDuration, vector<int>& secondTime, vector<int>& secondDuration){ 

        int earliest = INT_MAX;

        for(int i = 0; i < firstTime.size(); i++){ 
            earliest = min(earliest, firstTime[i] + firstDuration[i]); //find smallest time in land rides
        }

        int ans = INT_MAX;

        for(int i = 0; i < secondTime.size(); i++){ 

            int start = max(earliest, secondTime[i]); //get max water times start, cannot go back in time

            int finish = start + secondDuration[i];

            ans = min(ans, finish);
        }
        return ans;
    }


    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
     
        return min(findTime(landStartTime, landDuration, waterStartTime, waterDuration), findTime(waterStartTime, waterDuration, landStartTime, landDuration));

    }
};