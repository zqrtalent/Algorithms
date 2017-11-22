/***************************************************************************
Shell sort is a highly efficient sorting algorithm and is based on insertion sort algorithm. 
This algorithm avoids large shifts as in case of insertion sort, if the smaller value is to 
the far right and has to be moved to the far left.

This algorithm uses insertion sort on a widely spread elements, first to sort them and then sorts 
the less widely spaced elements. This spacing is termed as interval. This interval is calculated 
based on Knuth's formula as −

h = h * 3 + 1

where −
   h is interval with initial value 1

   This algorithm is quite efficient for medium-sized data sets as its average and worst case 
   complexity are of Ο(n), where n is the number of items.

Step 1 − Initialize the value of h
Step 2 − Divide the list into smaller sub-list of equal interval h
Step 3 − Sort these sub-lists using insertion sort
Step 3 − Repeat until complete list is sorted
***************************************************************************/

#include <iostream>

void ShellSort(int* pArr, int len)
{
    int holePosition;
    int valueToInsert;
    
    for(int i=0; i<len; i++)
    {
        /* select value to be inserted */
       valueToInsert = pArr[i];
       holePosition = i;

       /*locate hole position for the element to be inserted */
       while(holePosition > 0 && pArr[holePosition-1] > valueToInsert)
       {
            pArr[holePosition] = pArr[holePosition-1];
            holePosition --;
       }
       /* insert the number at hole position */
       pArr[holePosition] = valueToInsert;
    }
}

/*
procedure shellSort()
   A : array of items 
	
   /* calculate interval*/
   while interval < A.length /3 do:
   interval = interval * 3 + 1	    
end while

while interval > 0 do:

   for outer = interval; outer < A.length; outer ++ do:

   /* select value to be inserted */
   valueToInsert = A[outer]
   inner = outer;

      /*shift element towards right*/
      while inner > interval -1 && A[inner - interval] >= valueToInsert do:
         A[inner] = A[inner - interval]
         inner = inner - interval
      end while

   /* insert the number at hole position */
   A[inner] = valueToInsert

   end for

/* calculate interval*/
interval = (interval -1) /3;	  

end while

end procedure
*/