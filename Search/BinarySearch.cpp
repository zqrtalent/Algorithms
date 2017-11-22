/***************************************************************************
Binary search is a fast search algorithm with run-time complexity of Ο(log n). 
This search algorithm works on the principle of divide and conquer. For this 
algorithm to work properly, the data collection should be in the sorted form.

Binary search looks for a particular item by comparing the middle most item of 
the collection. If a match occurs, then the index of item is returned. 
If the middle item is greater than the item, then the item is searched in the 
sub-array to the left of the middle item. Otherwise, the item is searched for in 
the sub-array to the right of the middle item. This process continues on the 
sub-array as well until the size of the subarray reduces to zero.
***************************************************************************/

#include <iostream>

int BinarySearch(int* pArrSorted, int len, int searchVal)
{
    bool found = false;
    int lower = 0;
    int upper = len-1;
    int mid = 0;

    while(!found)
    {
        if(upper < lower)
        {
            break;
        }

        mid = lower + (upper - lower)/2;
        if(pArrSorted[mid] < searchVal)
        {
            lower = mid + 1;
        }
        else
        {
            if(pArrSorted[mid] > searchVal)
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
    
    return found ? mid : -1;
}

/*
// Return index of new value.
int AddInSortedArray(int* pArr, int len, int used, int newValue)
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
    if(!found)
    {
        if(used > 0)
            newPos = newValue > pArr[mid] ? lower : upper+1;
        if(newPos < used)
            memmove(&pArr[newPos+1], &pArr[newPos], sizeof(int)*(used-newPos));
        pArr[newPos] = newValue;
    }
    else
        return -1;
    
    return newPos;
}
*/

/*
Procedure binary_search
   A ← sorted array
   n ← size of array
   x ← value to be searched

   Set lowerBound = 1
   Set upperBound = n 

   while x not found
      if upperBound < lowerBound 
         EXIT: x does not exists.
   
      set midPoint = lowerBound + ( upperBound - lowerBound ) / 2
      
      if A[midPoint] < x
         set lowerBound = midPoint + 1
         
      if A[midPoint] > x
         set upperBound = midPoint - 1 

      if A[midPoint] = x 
         EXIT: x found at location midPoint

   end while
   
end procedure
*/