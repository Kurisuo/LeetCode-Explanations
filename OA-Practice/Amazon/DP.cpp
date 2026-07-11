#include <vector>
#include <bits/stdc++>

using namespace std;

int fib_bottom_up(int n){

    if(n == 1 || n == 2){
        return 1;
    }

    vector<int> bottom_up;
    bottom_up.reserve(n+1);

    bottom_up.insert(1, 1);
    bottom_up.insert(2, 1);

    for(int i = 3; i < n; i++){
        bottom_up[i] = bottom_up[i - 1] + bottom_up[i - 2];
    }


    return bottom_up[n];

}