/*******************************************************************************
*
* Program: Insertion Sort Algorithm Implementation
* 
* Description: Implementation of the insertion sort algorithm in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=PEhwXHEPbmI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

void insertion_sort(int a[], int length);

int main()
{
  // Example array to test algorithm
  int a[] = {8, 2, 7, 4, 5, 1, 9, 3};
  int length = 8;
  
  // Call insertion sort function
  insertion_sort(a, length);
  
  // Output each array index/value after it has been sorted to confirm the 
  // algorithm was successfully implemented
  for (int i = 0; i < length; i++)
  {
    cout << "a[" << i << "] = " << a[i] << endl;
  }
  
  return 0;
}

// Sorts the array 'a' with the provided length using the insertion sort 
// algorithm: https://en.wikipedia.org/wiki/Insertion_sort
void insertion_sort(int a[], int length)
{
  // The outer loop examines each 'key' element on the right-hand unsorted 
  // portion of the array from the 2nd element on to the end of the array
  for (int i = 1; i < length; i++)
  {
    // The element at the index is the current key value that we'll shift 
    // into its correct position in the left-hand sorted portion of the 
    // array.  We use the inner loop to do this, using the counter variable
    // j to keep track of our index in the left-hand sorted portion of the 
    // array, which is initially j-1, the index one to the left of the 
    // current key. 
    int key = a[i];
    int j = i - 1;

    // So long as we haven't reached the start of the array, and the value 
    // we are currently looking at in the sorted portion of the array is 
    // greater than our key, we haven't yet found the correct index to 
    // insert the key value.  So we shift over the value stored at the 
    // index j one to the right with a[j + 1] = a[j], and then keep looking 
    // at the next value to the left in the sorted portion of the array 
    // with j = j - 1.
    while (j >= 0 && a[j] > key) 
    {
      a[j + 1] = a[j];
      j = j - 1;
    }

    // The above loop will either stop when j = -1 and we have reached the 
    // start of the array (in which case we insert the key here 
    // as a[-1 + 1] = a[0] which will be assigned the key), OR the loop above
    // stops when a[j] <= key, in which case the key value should be placed 
    // at the index j + 1, i.e. the index one to the right of the value at a[j].
    a[j + 1] = key;
  }
}