# 998B Cutting
The problem here is to maximize the amount of cuts we can perform with the initial amount of bitcoins given. <br>
With every cut, all segments must consist of the same amount of odd and even numbers. <br>
The price for a cut will be the place it is divided, a(i+1)-a(i) bitcoins. <br>
```Java
For example:
6 4
1 2 7 10 13 20
```
The place we can cut will be:<br>
1. Between 2 and 7 which cost 5 (7-2) bitcoins. <br>
2. Between 10 and 13 which cost 3 (13-10) bitcoins. <br>

The total for two cut costs 8 bitcoins, while we only have 4 bitcoins. <br>
So, what we can do is to cut the sequence using the second choice. <br>
Then, the maximum cut we can get will be 1 so the output for this case is 1. <br>
The problem link is: https://codeforces.com/problemset/problem/998/B <br>

## GREEDY SOLUTION:
The greedy solution is first to input all the sequence given while checking if it is an odd number or an even number using a counter. Here, we can found out if the counter is 0 then at that point it has equal odd and even numbers. After we got at which point it is equal, we store that point to an array (here it is called breakPoint). <br>
Then, we check for each point what is the cutting price and store it to an array (here it is called cutPrice). <br>
Then we sort the cutPrice vector in increasing order. <br>
If the break point is at the end of the sequence then it is not stored to the array. <br>
We loop the cutPrice array and substract our current bitcoins with the cutting price while it is positive. Where, each cut will add an answer for the end. If, when we subtract our current bitcoins with the cutting price but we get a negative number, then we stop it there. Overall complexity is O(*n log n*), because using STL sort has a complexity of *n log n*, and the traversal only takes O(*n*) time. <br>
The solution link is: https://codeforces.com/contest/998/submission/44893627 <br>

## DYNAMIC PROGRAMMING SOLUTION:
Perform the same operation as the greedy one (find all the places we can cut, store it into an array that has the prices of each cut). This problem is solvable by using the knapsack method, but assign the worth as 1 for all of them (after all, a cut of price 5 and of price 1 is worth the same). Build the DP table from in bottom up fashion, and then just output `dp[how many cuts can we make][initial bitcoins we had]` as the answer. Overall complexity is O(*nB*), where B is the initial amount of bitcoins we had.
The solution link is: http://codeforces.com/contest/998/submission/45190198 <br>
## WHICH SOLUTION IS BETTER?
The easier one to understand is greedy, because it is very straightforward (keep taking the cheapest cuts until we cannot take anything else). The knapsack approach seems faster (15 vs 31 ms), but if the initial amount of bitcoins we have is a very big number, we might run into some memory or time limit problems. In conclusion, if a problem is solvable by greedy, why not?
