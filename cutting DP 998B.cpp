#include <bits/stdc++.h>
using namespace std;

int main() {
    //DECLARING VARIABLES
    vector<int> breakPoint, cutPrice;
    int numSequence, bitcoins, evenNum=0, cutAns=0;
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
    //SORT FROM THE CHEAPEST PRICE
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
    }
    //OUTPUT ANSWER
    cout<<cutAns<<endl;

    return 0;
}
