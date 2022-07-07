// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break. There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// For more description on this problem see wiki page

// Example 1:

// Input:
// N = 1, K = 2
// Output: 2
// Explanation: 
// 1. Drop the egg from floor 1. If it 
//    breaks, we know that f = 0.
// 2. Otherwise, drop the egg from floor 2.
//    If it breaks, we know that f = 1.
// 3. If it does not break, then we know f = 2.
// 4. Hence, we need at minimum 2 moves to
//    determine with certainty what the value of f is.

int eggFloor[n + 1][k + 1];
    int res;
    int i, j, x;
 
    // We need one trial for one floor and 0
    // trials for 0 floors
    for (i = 1; i <= n; i++) {
        eggFloor[i][1] = 1;
        eggFloor[i][0] = 0;
    }
 
    // We always need j trials for one egg
    // and j floors.
    for (j = 1; j <= k; j++)
        eggFloor[1][j] = j;
 
    // Fill rest of the entries in table using
    // optimal substructure property
    for (i = 2; i <= n; i++) {
        for (j = 2; j <= k; j++) {
            eggFloor[i][j] = INT_MAX;
            for (x = 1; x <= j; x++) {
                res = 1 + max(
                            eggFloor[i - 1][x - 1],
                            eggFloor[i][j - x]);
                if (res < eggFloor[i][j])
                    eggFloor[i][j] = res;
            }
        }
    }
 
    // eggFloor[n][k] holds the result
    return eggFloor[n][k];
    }
};