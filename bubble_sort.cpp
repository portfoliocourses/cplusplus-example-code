/*******************************************************************************
*
* Program: Bubble Sort Implementation
* 
* Description: Implementation of the Bubble Sort algorithm in C++. See the 
* Wikipedia article on Bubble Sort: https://en.wikipedia.org/wiki/Bubble_sort
*
* YouTube Lesson: https://www.youtube.com/watch?v=62Ai0p1xUpE 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

void bubble_sort(int a[], int length);

int main()
{
  // Test array and array length
  int a[] = {1,4,5,0,2,7,3,6,8,9};
  int length = 10;
  
  // Call the function to sort the array using the bubble sort algorthim
  bubble_sort(a, length);
  
  // Output the array elements to see they have been sorted, separated by spaces
  // and followed by a couple end lines
  for (int i = 0; i < length; i++)
  {
    cout << a[i] << " ";
  }
  cout << endl << endl;
  
  return 0;
}

// Accepts an array and its length and sorts it using the bubble sort algorithm
//
// Bubble sort works by continually passing through the elemnts of an array 
// and swapping those that are found to be out of order, see:
//   https://en.wikipedia.org/wiki/Bubble_sort
//
void bubble_sort(int a[], int length)
{
  bool swapped;
  int i = 0;

  // The outer loop will continue to attempt to sort the array so long as it 
  // may still be out of order.  We know the array might still be out of order
  // if a swap has taken place... if no swap has taken place, we know that the
  // array is sorted.  So we use the bool swapped to keep track of whether a 
  // swap has taken place, and to decide when to stop the algorithm.
  do
  {
    swapped = false;

    // The inner loop makes a pass through the array elements, and if any 
    // element and the element next to it are out of order, it swaps them. 
    // After the first pass through the array, we know for sure that the last 
    // element of the array is sorted, and after the 2nd pass through we know 
    // for that the 2nd last element of the array is sorted... and so we can 
    // progressively pass through less elements of the array each time we run 
    // this loop.  We use i to keep track of how many passes through the array 
    // we have made, and lessen the number of elements we go through each time!    
    for (int j = 0; j < length - 1 - i; j++)
    {
      // we could flip < to > to have it sort in ascending order instead of 
      // descending order as it will now    	
      if (a[j] < a[j + 1])
      {
        // swaps elements that are detected to be out of order using a temporary
        // variable to store one value before we need to overwrite it with the
        // other, see: https://en.wikipedia.org/wiki/Swap_(computer_programming)      	
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      }
    }
    i++;
  } while (swapped);
}
