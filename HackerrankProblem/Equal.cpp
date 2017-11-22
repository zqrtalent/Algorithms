#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;
#include "global.h"
/*
int AddInSortedArray(int* pArr, int len, int used, int newValue, bool& exists)
{
    bool found = false;
    int lower = 0;
    int upper = used-1;
    int mid = 0;
    
    while(!found)
    {
        if(upper < lower)
            break;
        
        mid = lower + (upper-lower)/2;
        if(newValue > pArr[mid])
        {
            lower = mid + 1;
        }
        else
        {
            if(newValue < pArr[mid])
            {
                upper = mid - 1;
            }
            else
            {
                found = true;
                break;
            }
        }
    }
    
    int newPos = mid;
    if(used > 0 && !found)
    {
        newPos = newValue > pArr[mid] ? lower : upper+1;
    }

    if(newPos < used)
        memmove(&pArr[newPos+1], &pArr[newPos], sizeof(int)*(used-newPos));
    pArr[newPos] = newValue;
    
    exists = found;
    return newPos;
}*/

// Returns minimal operations count.
int calcMinOperationsCt(int* pArr, int len, int valueIdx, int greaterValueIdx, int greaterValueCt, bool on)
{
    // 1, 2, 5
    int greaterVal = pArr[greaterValueIdx];
    int diff = greaterVal - pArr[valueIdx];
    
    // x5, x2, x1
    int ops[] = {0, 0, 0};
    
    int inc = 0;
    if(valueIdx == 0 && on)
    {
        //5 + 2 + 1
        //-2 + 5 + 5   
        if(greaterValueCt > 1)
        {
            int reminder = diff%5;
            if( reminder == 4 || reminder == 3)
            {
                inc = (5 - reminder);
                pArr[greaterValueIdx] += inc;
                diff += inc;
            }
        }
    }
    
    int add = inc + (greaterValueCt*diff);
    for(int i=greaterValueIdx+1; i<len; i++)
        pArr[i] += add;
    
    ops[0] = diff/5;
    diff %= 5;
    ops[1] = diff/2;
    diff %= 2;
    ops[2] = diff;

    if(greaterValueCt > 1)
    {
        ops[0] *= greaterValueCt;
        ops[1] *= greaterValueCt;
        ops[2] *= greaterValueCt;
        pArr[greaterValueIdx] += (greaterValueCt-1)*(pArr[greaterValueIdx] - pArr[valueIdx]);
    }
    
    if(inc > 0)
    {
        if(inc%2)
            ops[2] ++;
        else
            ops[1] ++;
    }
    
    //cout << pArr[valueIdx] << " " << greaterVal << " " << pArr[greaterValueIdx] << " " << (ops[2] + ops[1] + ops[0]) 
    //    << " 5x" << ops[0] << " 2x" << ops[1] << " 1x" << ops[2] << endl;
    return ops[2] + ops[1] + ops[0];
}

void Equal(istream& input, istream& exactOutput)
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    input >> n;

    vector<int> exactOutputArr(n);
    for(int i=0; i<n; i++)
    {
        exactOutput >> exactOutputArr[i];
    }

    vector<int*> arrs(n);
    vector<int> arrSizes(n);
    
    for(int i=0; i<n; i++)
    {
        int nn;
        input >> nn;
        
        int* pArr = new int[nn];
        arrs[i] = pArr;
        arrSizes[i] = nn;
        
        int val;
        bool exists;
        for(int j=0; j<nn; j++)
        {
            input >> val;
            GlobalFunctionality::AddInSortedArray(pArr, nn, j, val, exists);   
        }
        /*
        for(int k=0; k<nn; k++)
            cout << pArr[k] << " ";
        cout << endl;*/
    }
    
    for(int i=0; i<n; i++)
    {
        int* pArr = arrs[i];
        
        int val = pArr[0];
        int valCt;
        int greaterVal = val;
        int greaterValCt;
        int nSize = arrSizes[i];
        
        int operationCt = 0;
        int operationCt2 = 0;
        
        int* pArr2 = new int[nSize];
        memcpy(pArr2, pArr, sizeof(int)*nSize);
        
        // 1 5 5 10 10
        int j = 1;
        int jMin = 0;
        
        int diffSum = 0;
        while(j<nSize)
        {   
            valCt = 1;
            while(j < nSize && pArr[j] == greaterVal)
            {
                valCt ++;
                j ++;
            }

            if(j < nSize)
            {
                greaterVal = pArr[j];
                greaterValCt = 1;
                j ++;
                
                while(j < nSize && pArr[j] == greaterVal)
                {
                    greaterValCt ++;
                    j ++;
                }
                j --;
            }
            else
                break;
            
            //cout << val << " x" << valCt << " " << greaterVal << " x" << greaterValCt << endl;
            operationCt += calcMinOperationsCt(pArr, nSize, jMin, j, greaterValCt, true);
            operationCt2 += calcMinOperationsCt(pArr2, nSize, jMin, j, greaterValCt, false);
                        
            jMin = j;
            val = pArr[j];
            j ++;            
        }
        
        delete [] pArr2;
        cout << min(operationCt, operationCt2) << " " << exactOutputArr[i] << (exactOutputArr[i] != min(operationCt, operationCt2) ? " Fail" : "") << endl;
    }
    
    // Clean up.
    for(int i=0; i<arrs.size(); i++)
        delete [] arrs[i];
}

/*
Let f(min) be sum of operations performed over all coworkers to reduce each of their chocolates to min.
However, sometimes f(min) might not always give the correct answer. It can also be a case when
f(min) > f(min-1)
but it is safe to assume that
f(min) < f(min-5)
as f(min-5) takes N operations more than f(min) where N is the number of coworkers.
Therefore, if
A = {min,min-1,min-2,min-3,min-4} 
then,
f(A) <= f(min) < f(min-5)
Compute f(y) ∀ y ∈ A and print the minimum as the answer.
*/
/*

#include<iostream>
#include<cstdio>
#define INT_MAX 2000000000
    
using namespace std;
    
long long int functn (long long int temp)  // similar to greedy Coin-change
{
    long long int x=0;
    if(temp>=5)
    {
        x = temp/5;
        temp = temp%5;
    }
    if(temp>=2)
    {
        x += temp/2;
        temp = temp%2;
    }
    x += temp;
    return x;
    
}
    
int array_smallest(long long int array[],int array_length)
{
    long long int smallest = INT_MAX;
    long long int i;
    for (i = 0; i < array_length; i++)
    {
        if (array[i] < smallest) {
            smallest = array[i];
        }
    }
    return smallest;
}
    
long long int mod(long long int x)
{
    if(x>0)
        return x;
    else
        return (-1)*x;
}
    
int main()
{
    long long int T,N,i,j,min,sum,temp;
    cin>>T;
    while(T--)
    {
        min = 1000000;
        cin>>N;
        int A[N];
        for(i=0 ; i< N ; i++)
        {
            cin>>A[i];
            if(A[i]<min)
                min = A[i];
        }
        long long int sum[6];
        for(j=0 ; j<=5 ; j++)
        {
            sum[j]=0;
            for(i=0 ; i< N ; i++)
            {
                temp = mod(A[i] - (min-j));
                sum[j] = sum[j] + functn(temp);
            }
        }
        cout<<array_smallest(sum,6)<<endl;
    }
    return 0;
}
*/