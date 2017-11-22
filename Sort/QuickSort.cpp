/***************************************************************************
Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of 
data into smaller arrays. A large array is partitioned into two arrays one of which holds 
values smaller than the specified value, say pivot, based on which the partition is made and 
another array holds values greater than the pivot value.

Quick sort partitions an array and then calls itself recursively twice to sort the two resulting subarrays. 
This algorithm is quite efficient for large-sized data sets as its average and worst case complexity 
are of Ο(n2), where n is the number of items.

Step 1 − Make the right-most index value pivot
Step 2 − partition the array using pivot value
Step 3 − quicksort left partition recursively
Step 4 − quicksort right partition recursively
***************************************************************************/

#include <iostream>

void QuickSort(int* pArr, int len)
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

/*
function partitionFunc(left, right, pivot)
   leftPointer = left
   rightPointer = right - 1

   while True do
      while A[++leftPointer] < pivot do
         //do-nothing            
      end while
		
      while rightPointer > 0 && A[--rightPointer] > pivot do
         //do-nothing         
      end while
		
      if leftPointer >= rightPointer
         break
      else                
         swap leftPointer,rightPointer
      end if
		
   end while 
	
   swap leftPointer,right
   return leftPointer
	
end function

procedure quickSort(left, right)

   if right-left <= 0
      return
   else     
      pivot = A[right]
      partition = partitionFunc(left, right, pivot)
      quickSort(left,partition-1)
      quickSort(partition+1,right)    
   end if		
   
end procedure
*/