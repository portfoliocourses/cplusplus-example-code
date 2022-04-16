/*******************************************************************************
*
* Program: Virtual Destructors Example
* 
* Description: Demonstration of how to use virtual destructors in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ofZZW9zxJDQ 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple base class that dynamically allocates memory
class BaseData
{
public:
  
  // data is a pointer to the dynamically allocated memory
  int *data;
  
  // in the constructor will allocate space for an array of ints on the heap
  BaseData(int size)
  {
    data = new int[size];
  }
  
  // In the destructor we free the dynamically allocated memory... it's 
  // *essential* that the destructor run otherwise we would have a memory leak.
  // Notice how we use the virtual keyword to create a virtual destructor, this 
  // means that the destructor of any derived classes will be called using 
  // dynamic binding at runtime IF we have a BaseData (base class) pointer to 
  // that derived class instance on the heap.  Below we'll create a derived 
  // class so we can observe this behaviour.
  virtual ~BaseData()
  {
    cout << "BaseData destructor is running" << endl;
    delete data;
  }
};

// A simple derived class that inherits from our base class BaseData, and also 
// dynamically allocates memory
class DerivedData : public BaseData
{
public:
  
  // a pointer to the dynamically allocated memory
  int *extra_data;
  
  // Our DerivedData class inherits the member variables and functions of its 
  // base class BaseData, including the member variable data.  Below we call 
  // the base class constructor with BaseData(size), which means the member 
  // variable data will be made to point to dynamically allocated memory, and 
  // it will be essential that this memory is freed.  We *also* dynamically 
  // allocate additional memory and have the extra_data member variable point 
  // to this memory.
  DerivedData(int size, int extra_size) : BaseData(size)
  {
    // dynamically allocate an array of ints of size extra_size and have 
    // extra_data point to this data
    extra_data = new int[extra_size];
  }
  
  // The derived class constructor frees the memory pointed to by extra_data.
  // It does not free the memory allocated by the BaseData constructor, because
  // we expect the BaseData destructor to be called *after* the DerivedData 
  // destructor.  This is the "default behaviour" to expect with destructors 
  // and inheritance.  The issue is when we have a BaseData pointer to a 
  // DerivedData object on the heap... in this case, unless we declare the 
  // BaseData destructor using virtual as we have above, *only* the BaseData
  // destructor will run, and the memory allocated in DerivedData will never 
  // be freed!  Which means we'll have a memory leak bug in our program.
  ~DerivedData()
  {
    cout << "DerivedData destructor is running" << endl;
    delete extra_data;
  }
};


int main()
{
  // Create an array of BaseData pointers to BaseData and DerivedData objects
  // dynamically allocated on the heap
  BaseData *array[] =
  {
    new BaseData(5),
    new DerivedData(4,4)
  };
  
  // We typically have arrays of base class pointers to allow us to do some work
  // using polymorphism... so we could for example have a loop that would loop 
  // through the elements of the above array, calling some member function for 
  // each object instance, regardless of whether it is a base class object or a 
  // derived class object!  This technique relies on polymorphism and can reduce
  // code duplication.
  //
  // for (int i = 0; i < 2; i++) array[i].method();
  
  // Now when we're done working with the objects we'll want to free the 
  // dynamically allocated memory, so again we use a loop to go through the 
  // array of pointers and destroy each object.  The problem is if we *don't* 
  // use the virtual keyword when defining the BaseData destructor then in 
  // the case of the DerivedData object *only* the BaseData destructor will 
  // be called and NOT the DerivedData destructor, leaving the dynamically 
  // allocated data of that object (what extra_data is pointing to) still 
  // allocated and not freed!  This would be a memory leak.  Try removing the 
  // virtual keyword from the BaseData destructor to see the effect.  This is 
  // why it's important to use a virtual destructor when defining a class if 
  // it is possible the class will be inherited by another class.
  for (int i = 0; i < 2; i++)
    delete array[i];
    
  return 0;
}