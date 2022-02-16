/*******************************************************************************
*
* Program: Object Assignment
* 
* Description: Demonstration of how object assignment works in C++, including 
* an example of why we need to be careful with object assignment if our objects 
* contain member variables that are pointers to data on the heap.
*
* YouTube Lesson: https://www.youtube.com/watch?v=SJy4_Ci80No 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple object with a single public int member variable
class Simple
{
public:
  int x;
};

// An object with a member variable that is itself an object
class Stack
{
public:
  Simple simple;
};

// An object with a member variable that is a pointer to data on the heap
class Heap
{
public:
  Simple *simple;
  
  Heap(int set_x)
  {
    simple = new Simple;
    simple->x = set_x;
  }
  
};

int main()
{
  // See the visualizations of memory in the comment below the main function 
  // for these three examples...

  // Example 1
  //
  // Assign an object to another object.
  //

  // create two Simple objects, assign a value to member variable x
  Simple simpleA;
  simpleA.x = 4;
  Simple simpleB;
  simpleB.x = 0;

  // when we assign simpleA to simpleB, the value of member variable x for 
  // simpleA will be assigned to the value of the member variable x for 
  // simpleB, we call this a "shallow copy"
  simpleB = simpleA;

  // we'll find that both x values are the same (4)
  cout << "simpleA.x: " << simpleA.x << endl;
  cout << "simpleB.x: " << simpleB.x << endl;

  // if we alter the member variable x of simpleB, this will not effect the
  // member variable x of simpleA, as they are two distinct objects in 
  // memory 
  simpleB.x = 20;
  cout << "simpleA.x: " << simpleA.x << endl;
  cout << "simpleB.x: " << simpleB.x << endl;


  // Example 2
  //
  // Assign an object to another object when the object's have member variables
  // that are themselves objects.
  //

  // Create two Stack objects, both of which have Simple object's as member
  // variables... assign to the x member variable of these Simple objects
  Stack stackA;
  stackA.simple.x = 4;
  Stack stackB;
  stackB.simple.x = 0;

  // When we assign stackA to stackB, an assignment operation occurs with the 
  // Simple object member variables, and then as in Example 1 the member 
  // variable x value is assigned 
  stackB = stackA;
  cout << "stackA.simple.x: " << stackA.simple.x << endl;
  cout << "stackB.simple.x: " << stackB.simple.x << endl;

  // Again if we modify the x member variable of the Simple object of stackB,
  // we're going to find this does not modify the x member variable of the 
  // Simple object of stackB... because these are all distinct objects in 
  // memory... altering one does not effect the other.
  stackB.simple.x = 20;
  cout << "stackA.simple.x: " << stackA.simple.x << endl;
  cout << "stackB.simple.x: " << stackB.simple.x << endl;


  // Example 3
  //
  // Assign an object to another object when the object member variables 
  // include pointers to data on the heap.
  //
  
  // Create two heap objects, the constructor for heap objects will create 
  // a Simple object and assign to the Simple object pointer member variable
  // "simple" the memory address for this object on the heap. 
  Heap heapA(4);
  Heap heapB(0);

  // When we assign heapA to heapB, just as in the above two examples, 
  // the values of the member variables of heapA will be assigned to the 
  // member variables of heapB.  BUT the member variable simple in this 
  // case is a POINTER that stores a memory address for Simple objects on 
  // the HEAP.  So heapB's simple pointer member variable will store the 
  // SAME memory address as heapA's simple pointer member variable after 
  // the assignment... in other words, they will be pointing to the same 
  // object on the heap after this assignment!
  heapB = heapA;

  // Both x values will output as '4' which may give us the impression that 
  // we're getting the same behaviour as Examples 1 and 2, but what's really 
  // going on this time is that heapA and heapB's simple pointer member 
  // variable are both pointing to the SAME Simple object.
  cout << "heapA.simple->x: " << heapA.simple->x << endl;
  cout << "heapB.simple->x: " << heapB.simple->x << endl;

  // When we alter the x value of the object that heapB's simple pointer 
  // member variable is pointing to, we modify the object that BOTH heapA 
  // and heapB are now pointing to!  So we'll get the same result (20) as 
  // output for "both" x values (really they are the same object).
  heapB.simple->x = 20;
  cout << "heapA.simple->x: " << heapA.simple->x << endl;
  cout << "heapB.simple->x: " << heapB.simple->x << endl;

  return 0;
}

//
//
//   Example 1 Memory View:
//
//                                               STACK
//                                               =====
//
//    ------------       ------------
//   | simpleA    |     | simpleB    |
//   |            |     |            |
//   | int x = 4  |     | int x = 20 |
//    ------------       ------------
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//                                               HEAP
//                                               ====
//
//                Nothing
//
//
//
//
//
//   Example 2 Memory View:
//
//                                               STACK
//                                               =====
//
//    ---------------       ---------------
//   | stackA        |     | stackB        |
//   |               |     |               |
//   | Simple simple |     | Simple simple |
//    --------- | ---       --------- | ---
//              |                     |
//              |                     |
//          ------------       ------------
//         | simple     |     | simple     |
//         |            |     |            |
//         | int x = 4  |     | int x = 20 |
//          ------------       ------------
//
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//                                               HEAP
//                                               =====
//
//                     Nothing
//
//
//
//
//
//  Example 3 Memory View:
//
//                                               STACK
//                                               =====
//
//    ----------------       ----------------
//   | heapA          |     | heapB          |
//   |                |     |                |
//   | Simple *simple |     | Simple *simple |
//    --------- | ----       --------- | ----
//              |                     /
//              |           ----------
//              |          /
// ~~~~~~~~~~~~ | ~~~~~~~ / ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//              |        /
//              |       /                        HEAP
//              |      /                         =====
//         ------------        ------------
//        | simple     |      | simple     |
//        |            |      |            |
//        | int x = 20 |      | int x = 0  |
//        ------------         ------------
//

