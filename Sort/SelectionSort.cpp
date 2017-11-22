/***************************************************************************
Selection sort is a simple sorting algorithm. This sorting algorithm is an in-place 
comparison-based algorithm in which the list is divided into two parts, the sorted part 
at the left end and the unsorted part at the right end. Initially, the sorted part is 
empty and the unsorted part is the entire list.

The smallest element is selected from the unsorted array and swapped with the leftmost element, 
and that element becomes a part of the sorted array. This process continues moving unsorted array 
boundary by one element to the right.

This algorithm is not suitable for large data sets as its average and worst case complexities are of Ο(n2), 
where n is the number of items.

Step 1 − Set MIN to location 0
Step 2 − Search the minimum element in the list
Step 3 − Swap with value at location MIN
Step 4 − Increment MIN to point to next element
Step 5 − Repeat until list is sorted
***************************************************************************/

#include <iostream>

void SelectionSort(int* pArr, int len)
{
    for(int i=0; i<len-1; i++)
    {
        int min = i;
        /* check the element to be minimum */
        for(int j=i+1; j<len; j++)
        {
            if(pArr[j] < pArr[min])
                min = j;
        }

        /* swap the minimum element with the current element*/
        if(min != i)
        {
            int tmp = pArr[min];
            pArr[min] = pArr[i];
            pArr[i] = tmp;
        }
    }
}