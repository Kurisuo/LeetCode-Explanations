#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'performOperations' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. 2D_INTEGER_ARRAY operations
 */

vector<int> performOperations(vector<int> arr, vector<vector<int>> operations) {

    if(arr.empty() || operations.empty()){
        return arr;
    }
    
    vector<int> temp;

    
    for(int i = 0; i < operations.size(); i++){
        
        int left = operations[i][0];
        int right = operations[i][1];
            
        while(left < right){
        
            swap(arr[left], arr[right]);
            
            left++;
            right--;
                 
        }
        
    }   
    

    return arr;
}
