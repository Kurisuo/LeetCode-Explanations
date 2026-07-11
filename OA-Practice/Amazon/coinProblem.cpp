
/*
minimum_coins(coins, m) returns min num of coins req for a sum n


minimum_coins(coins, 0) = 0
minimum_coins(coins, m)



solution(m) = min(solution(m - c) + 1) 

 */



int minimum_coins(int m, int coins){
    int answer {};
    vector<int>memo;

    if (memo.contains(m)){
        return memo[m];
    }


    if (m == 0) {
        answer = 0;
    }
    else{
        answer = -1;
        for(int coin = 0; coin < coins; coin++){
            int subproblem = m - coin;
            if(subproblem < 0){
                continue;
            }

            answer = min(answer, minimum_coins(subproblem, coins) + 1);

        }

    }

    if memo[m] = answer;
    return answer;
}   



//bottom up


