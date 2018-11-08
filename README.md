# Solving Codeforces 998 B using Greedy & Dynamic Programming
This repository will solve Codeforces' problem [998 B](https://codeforces.com/problemset/problem/998/B) using Greedy approach and Dynamic Programming. We will also compare which approach is better.

## Team Member
- Liang Cai
- Nadya Alimin
- Sebastian Aldi
- Winston Renatan

## Requirement
- [C++ 11](https://osdn.net/projects/mingw/releases/)

## Installation/running instruction
- Compile the source code from this repository and execute the program.
- If you want to know how to compile and execute the source code from scratch, refer to [this](https://www.youtube.com/watch?v=xuQL_BZydS0) video.

## Sample I/O
**Sample #1:**  
_In:_  
```
6 4
1 2 5 10 15 20
```
_Out:_
```
1
```
---
**Sample #2:**  
_In:_
```
4 10
1 3 2 4
```
_Out:_
```
0
```
---
**Sample #3:**  
_In:_
```
6 100
1 2 3 4 5 6
```
_Out:_
```
2
```

## Explanation
### Problem Statement
The problem here is to maximize the amount of cuts we can perform with the initial amount of bitcoins given. 
With every cut, all segments must consist of the same amount of odd and even numbers. 
The price for a cut will be the place it is divided, a(i+1)-a(i) bitcoins. 

```
For example:
6 4
1 2 7 10 13 20
```
The place we can cut will be:

1. Between 2 and 7 which cost 5 (7-2) bitcoins. 
2. Between 10 and 13 which cost 3 (13-10) bitcoins.
 
The total for two cut costs 8 bitcoins, while we only have 4 bitcoins.  
So, what we can do is to cut the sequence using the second choice.  
Then, the maximum cut we can get will be 1 so the output for this case is 1.  
The problem link is: https://codeforces.com/problemset/problem/998/B 

### Greedy Approach
The greedy solution is first to input all the sequence given while checking if it is an odd number or an even number using a counter. Here, we can found out if the counter is 0 then at that point it has equal odd and even numbers. After we got at which point it is equal, we store that point to an array (here it is called breakPoint). <br>
Then, we check for each point what is the cutting price and store it to an array (here it is called `cutPrice`). <br>
Then we sort the `cutPrice` vector in increasing order. <br>
If the break point is at the end of the sequence then it is not stored to the array. <br>
We loop the `cutPrice` array and substract our current bitcoins with the cutting price while it is positive. Where, each cut will add an answer for the end. If, when we subtract our current bitcoins with the cutting price but we get a negative number, then we stop it there. Overall complexity is O(*n log n*), because using STL sort has a complexity of *n log n*, and the traversal only takes O(*n*) time. <br>
The solution link is: https://codeforces.com/contest/998/submission/44893627 <br>

### Dynamic Programming Approach
Perform the same operation as the greedy one (find all the places we can cut, store it into an array that has the prices of each cut). This problem is solvable by using the knapsack method, but assign the worth as 1 for all of them (after all, a cut of price 5 and of price 1 is worth the same). Build the DP table from in bottom up fashion, and then just output `dp[how many cuts can we make][initial bitcoins we had]` as the answer. Overall complexity is O(*nB*), where B is the initial amount of bitcoins we had. <br>
The solution link is: http://codeforces.com/contest/998/submission/45190198 <br>

### Comparison
The easier one to understand is greedy, because it is very straightforward (keep taking the cheapest cuts until we cannot take anything else). The knapsack approach seems faster (15 vs 31 ms), but if the initial amount of bitcoins we have is a very big number, we might run into some memory or time limit problems. In conclusion, if a problem is solvable by greedy, why not?
