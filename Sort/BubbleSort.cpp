/***************************************************************************
Bubble sort is a simple sorting algorithm. This sorting algorithm is comparison-based algorithm in which 
each pair of adjacent elements is compared and the elements are swapped if they are not in order. 
This algorithm is not suitable for large data sets as its average and worst case complexity are of Ο(n2) 
where n is the number of items.
***************************************************************************/

#include <iostream>

void BubbleSort(int* pArr, int len)
{
    bool swapped;
    for(int i=0; i<len-1; i++)
    {
        swapped = false;
        for(int j=len-1; j>i; j--)
        {
            if(pArr[j-1] > pArr[j])
            {
                int tmp = pArr[j];
                pArr[j] = pArr[j-1];
                pArr[j-1] = tmp;
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}