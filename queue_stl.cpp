/*******************************************************************************
*
* Program: Queue Data Structure In C++ STL Examples
* 
* Description: Examples of using the queue data structure built-in to the C++ 
* Standard Template Library.  The queue class template in the C++ STL is a 
* container class (specifically a container adapter) which allows us to store
* collections of data in a First In First Out (LIFO) order.
*
* Queues: https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
*
* YouTube Lesson: https://www.youtube.com/watch?v=juqhvOyMoeI
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

// A very basic class with a constructor, copy constructor, and destructor that
// will ouput to let us know when they have been called.
class Student
{
public:
  int grade;
  
  // Constructor to create a Student object
  Student(int grade)
  {
    this->grade = grade;
    cout << "Constructor called: " << grade << endl;
  }
  
  // Copy constructor to create a Student object as a copy of another
  Student(const Student &student)
  {
    this->grade = student.grade;
    cout << "Copy constructor called: " << this->grade;
    cout << endl;
  }
  
  // Destructor called when object is destroyed
  ~Student()
  {
    cout << "Destructor called: " << this->grade;
    cout << endl;
  }
};

int main()
{
  // Declare a queue called numbers to store int values
  queue<int> numbers;
  
  // Initially the queue will have a size of 0 because it has no elements, the 
  // size() method will return this size of the queue
  cout << "size: " << numbers.size() << endl;
  
  // The empty() method will return true because the queue size is 0
  if (numbers.empty())
  {
    cout << "Queue is empty" << endl;
  }
  
  // Push the element 8 on to the queue, elements will always be added to the
  // 'back' of the queue
  numbers.push(8);
  
  // Queue size should now be 1...
  cout << "size: " << numbers.size() << endl;
  
  // The Queue should now NOT be empty and empty() will return false
  if (!numbers.empty())
  {
    cout << "Queue is not empty" << endl;
  }
  
  // Because 8 is the only element in the queue it will be at the FRONT and 
  // BACK of the queue as returned by the front() and back() methods
  cout << "front: " << numbers.front() << endl;
  cout << "back: " << numbers.back() << endl;
  
  // Push 9 onto the queue, then 5.
  numbers.push(9);
  numbers.push(5);

  // Because elements are 'added to the back' of the queue, 5 will now be at
  // the back of the queue, and 8 will still be at the front of the queue, 
  // and the queue size will now be 3.
  cout << endl;
  cout << "front: " << numbers.front() << endl;
  cout << "back: " << numbers.back() << endl;
  cout << "size: " << numbers.size() << endl;
  
  // The pop() method below will 'pop' (i.e. remove) the element at the 
  // front of the queue, but the method does not return the element.  So if 
  // we want to save the element we have popped, we should call front() 
  // first and assign the returned value to a variable as we do here.
  int popped_value = numbers.front();
  
  // Removes the element at the front of the queue, 8 in this case
  numbers.pop();
   
  // The queue size will now be 2, with 9 at the front of the queue, and 5
  // still at the back of the queue.  We can also output the value we popped
  // from the front of the queue.
  cout << endl;
  cout << "front: " << numbers.front() << endl;
  cout << "back: " << numbers.back() << endl;
  cout << "size: " << numbers.size() << endl;
  cout << "popped_value: " << popped_value << endl;
  

  // Declare another queue to store int values named other_queue
  queue<int> other_queue;
  
  // Push the value 4 onto this queue
  other_queue.push(4);

  // Output the size of the queues, numbers will still be size 2 and other_queue
  // will be size 1
  cout << endl;
  cout << "numbers size: " << numbers.size() << endl;
  cout << "other_queue size: " << other_queue.size() << endl;
  
  // The swap() method will swap the elements stored in each queue, so 
  // other_queue will store the elements previously stored in numbers, and 
  // numbers will store the elements previously stored in other_queue
  other_queue.swap(numbers);
  
  // Now when we output the size of the queues, numbers will be size 1 and 
  // other_queue will be size 1 because their elements were swapped.
  cout << endl;
  cout << "numbers size: " << numbers.size() << endl;
  cout << "other_queue size: " << other_queue.size() << endl;
  

  // Declare a queue to store int values called x
  queue<int> x;
  
  // Push the values 4,5, and 6 onto x
  x.push(4);
  x.push(5);
  x.push(6);
  
  // Declare a queue to store int values called y
  queue<int> y;
  
  // Push the value 5, 4 and 6 onto y (notice the different order compared to x)
  y.push(5);
  y.push(4);
  y.push(6);
  
  // If we assign x to y, the elements of y will be replaced with the elements 
  // of x... so y will contain the elements 4 -> 5 -> 6 like x, going from 
  // back to front...
  //
  // y = x;

  // We can use comparison operators to compare queues, we will get that x != y
  // because the queues are not equal (the values stored are the same but in a
  // different order so they are not equal)..
  if (x == y) cout << "x == y" << endl;
  if (x != y) cout << "x != y" << endl;
  
  
  // int is a primitive type, but queues can store objects too like our Student
  // object, here we declare a queue to store Student objects
  queue<Student> classroom;
  
  // Create a Student object, notice how the constructor is called
  Student joe(90);
  
  // When we push the object onto the queue, a copy of the object will be 
  // created, notice how the copy constructor is called.  
  classroom.push(joe);
  
  // When we call the emplace() method, the arguments it is supplied will be 
  // forwarded to a constructor for the object stored by the queue... i.e. 
  // in the below example a Student object will be constructed using 
  // Student(80), and then this new object will be pushed onto the queue.
  // In this way, compared to the above example with push(), the copy 
  // constructor is not called, only one object was created and it exists 
  // on the queue.  
  classroom.emplace(80);
  
  // This will cause a copy constructor call, and a new object will be 
  // created that is a copy of the back element of the queue (the Student 
  // with grade set to 80).
  Student student_copy = classroom.back();
  
  // When we pop an object from the queue, it's destructor will be called, 
  // notice how the destructor is called in this case. 
  classroom.pop();
  
  // We'll see that the destructor is called for the remaining object on 
  // the stack and the other Student objects in the main function, but 
  // we output this text first so we can see those destructor calls occur
  // after the above call due to pop().  Those calls occur due to the 
  // main function completing execution.
  cout << "after the pop" << endl;
  
  return 0;
}