#include <bits/stdc++.h>
using namespace std;
// first idea (naive): 1) we realize we could use a greedy algorithm to repeatedly take the biggest coin that fits into the remaining amount
// 2) but quickly, we come to terms with the fact that this provides a *locally optimal solution*, not the global optimum
// 3) why: a) take for instance [1, 3, 4, 5]; we want to make "7 cents"
// b) greedy gives us the solution [5, 1, 1] -> sub-optimal because of 3 coins being used
// c) instead, we need the global optimum of 7 cents -> [4, 3] with only 2 coins being used
// 4) hence, we need a better algorithm, that gives us a "global optimum", and we move to DP

// second idea (optimal): 1) consider using each coin, and take whichever works the best
// 2) example: [1, 3, 4, 5] -> choose 1 cent coin, and try to make the remaining 6 cents in the best way possible (similarly for other coins (3 cents chosen, 4 cents in the best way possible))
// 3) algorithm starts here: start with making 0 cents (initially), and taking 0 coins (initially)
// 4) then we try to make 1 cent. how? -> first make (1 - coin_amount) cents, then add 1 cent
// 5) for invalid solutions (like we can't make 1 cent using 3 cent coins) -> put -1 into the table (in code, that would look like (if coin > curr_amount))

int coinChange(vector<int> &coins, int amount)
{
    if (amount <= 0)
        return 0;
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int curr_amt = 1; curr_amt <= amount; curr_amt++)
    {
        int curr_min = -1;
        for (int coin : coins)
        {
            if (curr_amt - coin < 0 || dp[curr_amt - coin] == -1)
                continue; // these are the invalid cases: if curr_amt - coin < 0 then we're trying to use a coin that's too big
                          // if dp[curr_amt - coin] == -1, the relevant subproblem has no valid solution
            int curr_cand = 1 + dp[curr_amt - coin];
            if (curr_min == -1)
                curr_min = curr_cand; // a valid solution, no matter how big, beats an invalid solution
            else if (curr_cand < curr_min)
                curr_min = curr_cand; // if our current min is valid and our current candidate is valid, we take the better one
        }
        dp[curr_amt] = curr_min;
    }
    return dp[amount];
}