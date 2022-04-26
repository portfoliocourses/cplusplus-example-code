/*******************************************************************************
*
* Program: Provide An Implementation Of A Pure Virtual Function Demonstration
* 
* Description: It's a bit of a "hidden feature" in C++ that we can provide an 
* implementation of pure virtual member function in its own abstract class.  We
* demonstrate how to do so in the example below.
*
* YouTube Lesson: https://www.youtube.com/watch?v=NqP_tuFp3pQ  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

// The Logger base class is an abstract class due to the pure virtual member 
// function log
class Logger
{
public:
  
  // class variable total will keep track of the total character length of all 
  // log messages made from certain derived class objects
  static int total;
  
  // pure virtual member function, derived classes will implement this method 
  // in different ways to log to the console, files, database, etc. (or so is 
  // the intention)
  virtual void log(string message) = 0;
  
  // destructor 
  virtual ~Logger() { };
};

// initialize total to 0 as initially there are no log messages
int Logger::total = 0;

// We typically do not provide an implementation of a pure virtual member 
// function in the abstract class, typically it is left to be implemented 
// by concrete derived classes.  But C++ does allow us to do this, and if we 
// implement the function it can be called too (for example, in the derived 
// classes).  Here we have the log member function increment the total class 
// variable by the length of the log message so we can keep track of the total 
// character length of all log messages from certain derived class objects.
void Logger::log(string message)
{
  total += message.length();
}

// ConsoleLogger is a derived class of Logger, the intention is we could have 
// several more derived classes of Logger to implement different types of 
// logging (e.g. database, file, etc.)
class ConsoleLogger : public Logger
{
public:
  
  // logs a log message to the console, but also utilizes the base class 
  // implementation of log
  void log(string message)
  {
    // Call the base class Logger log function.  All ConsoleLogger objects 
    // will contribute to the total character count kept track of by Logger's 
    // total class variable.  The intention is that some derived classes of 
    // Logger will utilize the log() implementation in the Logger class and 
    // some will not.  Note that if it were a *requirement* for the derived 
    // class log member function to call the base class log member function 
    // then this would be an instance of the Call Super anti-pattern and 
    // we would want to refactor our code to avoid this situation: 
    // https://en.wikipedia.org/wiki/Call_super.  Because calling the base 
    // class log member function is 'optional' it is not an instance of the 
    // anti-pattern.
    //
    Logger::log(message);
    
    // Output the log message to the console
    cout << "Log: " << message << endl;
  }
  
};

int main()
{
  // We can't create an instance of the Logger class because it is an abstract 
  // class... so the below statement would cause an error:
  //
  // Logger logger;
  
  // We can create pointers of type Logger which is useful for dynamic binding 
  // (i.e. runtime polymorphism), and we can create an instance of the 
  // ConsoleLogger object.
  Logger *logger = new ConsoleLogger();
  
  // Call the log member function of the ConsoleLogger object twice
  logger->log("abc");
  logger->log("1234");
  
  // Because the log member function of ConsoleLogger calls the Logger base 
  // class log implementation, a total of the characters written to the log 
  // is kept in the class variable total, which we output below (it should be 7)
  cout << "Total: " << Logger::total << endl;
  
  // Free the dynamically allocated memory 
  delete logger;
  
  return 0;
}