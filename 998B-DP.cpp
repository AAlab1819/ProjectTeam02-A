#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
int dp[101][101];
int main() {
    //DECLARING VARIABLES
    vector<int> breakPoint, cutPrice;
    int numSequence, bitcoins, evenNum=0, cutAns=0;
    memset(dp, 0, sizeof(dp));
    //INPUT NUMBER OF SEGMENTS AND BITCOINS
    cin>>numSequence>>bitcoins;
    int arraySeq[numSequence];
    //INPUT THE SEQUENCE
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
    }
    double startTime=omp_get_wtime();
    for(int i=0; i<breakPoint.size(); i++) {
        //IF THE BREAKPOINT IS AT THE END OF SEQUENCE
        if(breakPoint[i]==numSequence-1) {
            break;
        }
        //FIND THE CUTTING PRICE AT THAT POINT
        else {
            cutPrice.push_back(abs(arraySeq[breakPoint[i]]-arraySeq[breakPoint[i]+1]));
        }
    }
    for(int i=0; i<=cutPrice.size(); i++)
    {
        for(int w=0; w<=bitcoins; w++)
        {
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(cutPrice[i-1]<=w)
                dp[i][w]=max(1 + dp[i-1][w-cutPrice[i-1]], dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    cout<<dp[cutPrice.size()][bitcoins]<<endl;
    cout<<omp_get_wtime()-startTime<<endl;
    return 0;
}
