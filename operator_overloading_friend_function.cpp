/*******************************************************************************
*
* Program: Operator Overloading Using Friend Functions Examples
* 
* Description: Examples of how to implement operator overloading using friend 
* functions in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=MzGC7H8ywZ0  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// A simple class to represent a counter that starts off at an specific int
// count value when it is created, where this counter value can be incremented 
// and printed.
class Counter
{
  // declare a friend function that will set a Counter object's count to zero
  friend void set_to_zero(Counter &counter);
  
  // declare a friend function that will overload the + operator for Counter 
  // objects, adding together their counts and creating a new Counter with this 
  // combined count
  friend Counter operator+(Counter c1, Counter c2);
  
  // declare a friend function that will multiply the count of a Counter object 
  // by an int value m, where Counter is the right operand and the int value m 
  // is the left operand, returning a new Counter object set to the resulting 
  // value
  friend Counter operator*(int m, Counter counter);
  
private:

  // the count of the Counter object
  int count;
  
public:
  
  // constructer sets the count of the Counter to the int argument its provided
  Counter(int count) : count(count) {}
  
  // print out the count of the Counter
  void print()
  {
    cout << count << endl;
  }
  
  // increment the count of the Counter by 1
  void increment()
  {
    count++;
  }
  
  // We could overload the + operator using a member function, but we comment 
  // it out here so we can overload it using a friend function instead.  If we 
  // left both functions uncommented, there would be an ambiguity as to which 
  // function to call when using the + operator, so we need to comment it out.
  //
  // The member function is called for the left operand of the + operator when 
  // it is used, so when we use the member variable 'count' it is the member 
  // variable count of the left operand.  The right operand Counter object is 
  // provided as a function argument, and so we use counter.count to access the 
  // right operand's count.  We create a new Counter with the sum of these 
  // values as its initial count, and we return this object.
  /*
  Counter operator+(Counter const &counter)
  {
    Counter new_counter(count + counter.count);
    return new_counter;
  }
  */
  
  // We cannot use a member function to implement operator overloading when the 
  // left operand is not a class, but we CAN implement operator overloading when
  // the right operand is not a class.  This is because the left operand is the 
  // object for which the member function which implements operator overloading 
  // is called.  We use a friend function (see below) to implement a situation 
  // where the left operand is not a class.  Here we use member function to 
  // implement a situation where the right opernad is not a class.
  //
  // This member function will handle the situation that we multiply:
  //
  //    counter_object * int_value
  //
  // Where the Counter object is the left operand (for which this member 
  // function is called), and the right operand is an int.  We create and return
  // a new Counter object with the count set to the count of the left operand 
  // Counter object by the int_value (m).
  //
  Counter operator*(int m)
  {
    int new_count = count * m;
    return Counter(new_count);
  }
  
};

// Implement the friend function declared in the Counter class.  This function
// is NOT a member of the Counter class, but as a friend function is has access
// to the protected and private members of Counter class.  The function is 
// passed a Counter object by reference, which means the Counter object passed 
// to this function as an argument can be modified.  We set the Counter object's
// count to 0... notably we're able to access and modify a private member 
// variable of Counter even though is is not a member function of Counter.
void set_to_zero(Counter &counter)
{
  counter.count = 0;
}

// Implement another friend function declared in the Counter class.  Here we 
// overload the + operator.  Unlike the member function commented out above to
// overload the + operator, we must have two parameters for each Counter object
// (in this case c1 and c2).  In the case of the member function implementation,
// the left operand is the object for which the member function is called and 
// so we only needed one parameter.  In this solution we add together the count
// member variables of each Counter object (and we're able to access these, as 
// this function is a friend of Counter), create a new Counter object with this
// sum, and return it.
Counter operator+(Counter c1, Counter c2)
{
  int new_count = c1.count + c2.count;
  return Counter(new_count);
}

// Implement the last friend function declared in the Counter.  We actually 
// CANNOT implement operator overloading using member functions if the left 
// operand is not a class, because the left operand is the object for which 
// the member function that implements operator overloading is called.  If 
// the left operand is not a class (or a class we can modify), we can't define
// a member function for it.  Here we implement operator overloading of the 
// * operator:
//
//     int_value * counter_object
//
// where the left operand is the int value m, and the right value is a Counter 
// object.  We multiply m by the Counter object's count, we create a new 
// Counter object with the result of this multiplication, and we return it.
Counter operator*(int m, Counter counter)
{
  int new_count = m * counter.count;
  return Counter(new_count);
}


int main()
{
  // Create a Counter object, increment the count, and print it, to test if 
  // the Counter objects are working correctly.
  Counter counter1(7);
  counter1.increment();
  counter1.print();
  
  // Create a 2nd Counter object and print it
  Counter counter2(3);
  counter2.print();
  
  // Use the overloaded + operator to add two Counters together
  Counter counter3 = counter1 + counter2;
  
  // Output the resulting Counter object (the count should be 11)
  counter3.print();
  
  // Use the friend function set_to_zero to set the Counter object's count 
  // to 0... notably the friend function can access the private member variable
  // count of the Counter object, and modify it by setting it to 0 too.
  set_to_zero(counter3);
  
  // Output the Counter object after setting it to 0 to verify it has worked
  counter3.print();
  
  // Create another Counter object with a count of 5
  Counter counter4(5);
  
  // Use the overloaded * operator to multiply the Counter object's count by 20 
  // and produce a new Counter object (which should have a count of 100).
  // 
  // Here we use the member function which overloads the * operator with an int 
  // as the right operand.
  //
  Counter counter5 = counter4 * 20;
  
  // We could also use the friend function with overloads the * operator with 
  // an int as the left operand.
  //
  // Counter counter5 = 20 * counter4;
  
  // Output to confirm the count of this Counter is set to 100
  counter5.print();
  
  return 0;
}

// There are some situations in which we MUST use either a friend function 
// or member function to implement operator overloading.
//
// We cannot use a member function for operator overloading when the left 
// member is not a class OR it is a class we can't modify.
//
// Notably, we cannot overload the << stream insertion operator as a member 
// function because doing so requires a function with << as the left operand!
//
// C++ does not allow these operators to be overloaded using a friend function:
//
//   assignment: =
//   function call: ()
//   member selection (arrow): ->
//
// So we must use a member function instead!


