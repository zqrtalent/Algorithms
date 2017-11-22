#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
using namespace std;
#include "global.h"

void FindTheRunnigMedian(istream& input, istream& exactOutput)
{
    int n;
    input >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++)
    {
        input >> a[a_i];
    }

    vector<double> exactOutValues(n);
    for(int i=0; i<n; i++)
    {
        exactOutput >> exactOutValues[i];
    }
    
    int* pArr = new int[n];
    double dVal;
    cout.precision(1);
    
    int midValue;
    bool exists = false;
    for(int i=0; i<n; i++)
    {
        GlobalFunctionality::AddInSortedArray(pArr, n, i, a[i], exists);

        int ii = i+1;
        dVal = (double)pArr[ii/2];
        if(ii%2 == 0) // Even
        {
            dVal = (dVal + pArr[(ii/2) - 1])/2;
        }

        cout << fixed << dVal << " " << exactOutValues[i] << (exactOutValues[i] == dVal ? "" : "Fail") << endl;
        if(dVal != exactOutValues[i])
        {
            for(int j=0; j<ii/2; j++)
            {
                cout << pArr[j] << " ";
            }
            cout << endl;
            for(int j=ii/2; j<ii; j++)
            {
                cout << pArr[j] << " ";
            }
            break;
        }        
        //1, 2, 2, 3, 4, 5, 6
    }
    
    delete [] pArr;

}