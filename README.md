# 998B Cutting
The problem here is to find how many maximum cut we can get with the bitcoins given. <br>
The cut we want to find is to a segment consist of equal odd and even number. <br>
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
We loop the cutPrice array and substract our current bitcoins with the cutting price while it is positive. Where, each cut will add an answer for the end. If, when we subtract our current bitcoins with the cutting price but we get a negative number, then we stop it there. <br>
The solution link is: https://codeforces.com/contest/998/submission/44893627 <br>

## DYNAMIC PROGRAMMING SOLUTION:
xxx
