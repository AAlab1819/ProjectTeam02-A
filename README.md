# Solving Codeforces 998 B using Greedy & Dynamic Programming
This repository will solve Codeforces' problem [998 B](https://codeforces.com/problemset/problem/998/B) using Greedy approach and Dynamic Programming. We will also compare which approach is better.

## Team Member
- Liang Cai
- Nadya Natasha Alimin
- Sebastian Aldi
- Winston Renatan

## Requirement
- [C++ 11](https://osdn.net/projects/mingw/releases/)

## Installation/running instruction
- Compile the source code from this repository and execute the program.
- If you want to know how to compile and execute the source code from scratch, refer to [this](https://www.youtube.com/watch?v=xuQL_BZydS0) video.
- This also uses TDM-GCC MinGW Compiler to count the run time of the program.

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

### Pre Processing
```c++
for(int i=0; i<numSequence; i++) {
        cin>>arraySeq[i];
        //IF IT IS EVEN NUMBER
        if(arraySeq[i]%2==0) {
            evenNum++;
        }
        //IF IT IS ODD NUMBER
        else {
            evenNum--;
        }
        //BREAK POINT BECAUSE THE SUM OF EVEN AND ODD IS EQUAL HERE
        if(evenNum==0) {
            breakPoint.push_back(i);
        }
```
In this part of the code, we input some number and put it in an array called `breakPoint`. Then, a number from that array will be executed, if the reminder of that number divided two is zero, then the sum of the even number will increased automatically and it it turned out to be an odd number,  the sum of the even number will be decreased. Next it, if the sum of the even and odd number is equal, it will reach the `breakPoint` and do the loop `for` again. <br>

```c++
for(int i=0; i<breakPoint.size(); i++) {
        //IF THE BREAKPOINT IS AT THE END OF SEQUENCE
        if(breakPoint[i]==numSequence-1) {
            break;
        }
        //FIND THE CUTTING PRICE AT THAT POINT
        else {
            cutPrice.push_back(abs(arraySeq[breakPoint[i]]-arraySeq[breakPoint[i]+1]));
        }
```
Meanwhile in this part, we will cheeck the `breakPoint`, if it is at the end of the sequence, check the previous number of the array. If the breakPoint is not at the end, that find the cutting price at that point directly. <br>

### Greedy Approach
The greedy solution is first to input all the sequence given while checking if it is an odd number or an even number using a counter. Here, we can found out if the counter is 0 then at that point it has equal odd and even numbers. After we got at which point it is equal, we store that point to an array (here it is called breakPoint). <br>
Then, we check for each point what is the cutting price and store it to an array (here it is called `cutPrice`). <br>
Then we sort the `cutPrice` vector in increasing order. <br>
If the break point is at the end of the sequence then it is not stored to the array. <br>
We loop the `cutPrice` array and substract our current bitcoins with the cutting price while it is positive. Where, each cut will add an answer for the end. If, when we subtract our current bitcoins with the cutting price but we get a negative number, then we stop it there. Overall complexity is O(*n log n*), because using STL sort has a complexity of *n log n*, and the traversal only takes O(*n*) time. <br>

Snippet of code <br>

```c++
sort(cutPrice.begin(), cutPrice.end());
    for(int i=0; i<cutPrice.size(); i++) {
        //IF THERE IS BITCOINS LEFT AFTER CUTTING AT THE CHEAPEST POINT
        if(bitcoins-cutPrice[i]>=0) {
            //ADD CUTTED SEGMENTS
            cutAns++;
            //REDUCE THE BITCOINS
            bitcoins=bitcoins-cutPrice[i];
        }
        else {
            break;
        }
```
The problem is to find how many times the `cutPrice` we can do, by using `Sort`, sort the price from the cheapest one. Then do loop to find the bitcoins left after cutting. If there is some bitcoins left, the counter will be added, then reduce the bitcoins by reduce the bitcoins.

The solution link is: https://codeforces.com/contest/998/submission/44893627 <br>

### Dynamic Programming Approach
Perform the same operation as the greedy one (find all the places we can cut, store it into an array that has the prices of each cut). This problem is solvable by using the knapsack method, but assign the worth as 1 for all of them (after all, a cut of price 5 and of price 1 is worth the same). Build the DP table from in bottom up fashion, and then just output `dp[how many cuts can we make][initial bitcoins we had]` as the answer. Overall complexity is O(*nB*), where B is the initial amount of bitcoins we had. <br>

Snippet of code

```c++
for(int i = 0; i <= cutPrice.size(); i++)
    {
        for(int w = 0; w <= bitcoins; w++)
        {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(cutPrice[i-1] <= w)
                dp[i][w] = max(1 + dp[i-1][w-cutPrice[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
```
And here is the different from Greedy Approach. As we mentioned before, this problem is solvable by using Knapsack, but it is kind of a bit different. In `dp[i][w]` i means the number of item and w is the weight of the item. The difference is, the worth of every “price” is equal to one. If from the `breakPoint` could find the `cutPrice`, then the counter will increased until the loop is break.  
We used tabulation technique in order to solve this problem. This means that every space in `dp` array is filled completely.

The solution link is: http://codeforces.com/contest/998/submission/45190198 <br>

### Comparison
The easier one to understand is greedy, because it is very straightforward (keep taking the cheapest cuts until we cannot take anything else). The knapsack approach seems faster (15 vs 31 ms), but if the initial amount of bitcoins we have is a very big number, we might run into some memory or time limit problems. In conclusion, if a problem is solvable by greedy, why not?
Here is the comparison of N and Time, together with B and Time using both Greedy and Dynamic Programming approach.
```c++
     GREEDY            |       DP		
N     B      TIME      |  N    B      TIME
2    100  0.00100017   |  2   100      0
4    10   0.000999928  |  4   10       0
6    100      0        |  6    4   0.000999928
6     4   0.000999928  |  6   100  0.000999928
10   50       0        | 10    1   0.00100017
10    1   0.000999928  | 10   100  0.00100017
10   100  0.000999928  | 10   50   0.00200009
10   10   0.000999928  | 10   10   0.00300002
100  10       0        | 100  100      0
100   1   0.00100017   | 100   1       0
100  100  0.00100017   | 100  100  0.00199986
100  50   0.00300002   | 100  10   0.00200009
100   1   0.000999928  | 100  50   0.00200009
100  100  0.000999928  | 100  100  0.00400019
100  100  0.000999928  | 100   1   0.000999928
```
At the graphs below blue line indicates the Greedy Solution while the orange one is DP Solution.

The first one is N to Time
![NtoTime]((https://raw.githubusercontent.com/AAlab1819/ProjectTeam02-A/Graph N to Time.PNG)

The second one is B to Time
![BtoTime](ProjectTeam02-A/Graph B to Time.PNG)
