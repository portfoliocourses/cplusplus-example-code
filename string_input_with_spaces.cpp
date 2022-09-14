/*******************************************************************************
*
* Program: Handlign String Input With Spaces
* 
* Description: A demonstration 
*
* YouTube Lesson: https://www.youtube.com/watch?v=ot2FyuT5xpg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  // We'll try to store the full name into the name string variable
  string name;
  
  // Prompt the user to enter their full name
  cout << "Enter Full Name: ";
  
  // If we try to store the string entered into name like this, we'll only store
  // what was entered up until the first space in the string.  So if a user 
  // enters a name like "Virat Kohli" only "Virat" will be stored into name!
  //
  // cin >> name;
  
  // Instead we can use the getline() function by passing cin as the first 
  // argument and the name of our string as the second argument (in this case 
  // "name").  The getline() function will store the string from user input into
  // the name variable up until the first newline character, i.e. when the user 
  // hits the enter key.  This will allow us to store strings with spaces such 
  // as "Virat Kholi".
  //
  getline(cin, name);
    
  // Output the name string so we can see the string was stored successfully
  cout << "Hello, " << name << "!" << endl;
  

  // There are variations on using getline(), for example...
  //
  // If we are using a char array to store a "C-style string" as below with 
  // char name[100], we can use the getline() member function of the cin 
  // object to store the string entered into the char array.  We need to pass
  // the char array as the first argument and the size of the char array as 
  // the second argument (we could either hardcode a size like 100 or use 
  // the sizeof() operator to get the size of the char array).
  //
  /*
  char name[100];
  
  cout << "Enter Full Name: ";

  cin.getline(name, sizeof(name));
  
  cout << "Hello, " << name << "!" << endl;
  */

  return 0;
}