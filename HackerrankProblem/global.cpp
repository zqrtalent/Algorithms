#include "global.h"

// Return index of new value.
int GlobalFunctionality::AddInSortedArray(int* pArr, int len, int used, int newValue, bool& exists)
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
}