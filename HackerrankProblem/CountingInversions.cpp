#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;
#include "global.h"

long long MergeSort_CountInversions(vector<long long>& arr, int startIndex, int len, vector<long long>& arrCopyInto);
long long Merge(vector<long long>& arrLeft, vector<long long>& arrRight, vector<long long>& mergeInto, int midIndex);

void MergeSortCountingInversions(istream& input, istream& exactOutput)
{
    int t;
    input >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        input >> n;
        vector<long long> arr(n), arrSorted(n);
        for(int arr_i = 0; arr_i < n; arr_i++)
        {
           input >> arr[arr_i];
        }

        long long result = MergeSort_CountInversions(arr, 0, arr.size(), arrSorted);
        cout << result << endl;
    }
}

long long MergeSort_CountInversions(vector<long long>& arr, int startIndex, int len, vector<long long>& arrCopyInto)
{
    vector<long> ret;
    if(len <= 1)
    {
        if(len == 1)
            arrCopyInto[0] = arr[startIndex];
        return 0;
    }

    int n = len/2;
    long long inversionCt = 0;
    vector<long long> a(n);
    inversionCt = MergeSort_CountInversions(arr, startIndex, n, a);
    
    vector<long long> b(len-n);
    inversionCt += MergeSort_CountInversions(arr, startIndex+n, len-n, b);

    inversionCt += Merge(a, b, arrCopyInto, startIndex+n-1);
    return inversionCt;
}

long long Merge(vector<long long>& arrLeft, vector<long long>& arrRight, vector<long long>& mergeInto, int midIndex)
{
    long long inversionCt = 0;
    int copyIndex = 0, startIndexLeft = 0, lenLeft = arrLeft.size(), startIndexRight = 0, lenRight = arrRight.size();
    while(lenLeft > 0 && lenRight > 0){
        if(arrLeft[startIndexLeft] <= arrRight[startIndexRight]){
            mergeInto[copyIndex++] = arrLeft[startIndexLeft];
            startIndexLeft ++;
            lenLeft --;
        }
        else{
            mergeInto[copyIndex++] = arrRight[startIndexRight];
            startIndexRight ++;
            lenRight --;

            inversionCt += (long long)(arrLeft.size() - startIndexLeft);// + mid - startIndexLeft;
            //inversionCt += (long long)(arrLeft.size() - startIndexLeft);
        }
    }

    while(lenLeft > 0)
    {
        mergeInto[copyIndex++] = arrLeft[startIndexLeft];
        startIndexLeft ++;
        lenLeft --;
    }

    while(lenRight > 0)
    {
        mergeInto[copyIndex++] = arrRight[startIndexRight];
        startIndexRight ++;
        lenRight --;
    }

    return inversionCt;
}