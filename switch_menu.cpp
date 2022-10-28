/*******************************************************************************
*
* Program: Create A Menu Using A Switch
*
* Description: Example of creating a menu with a switch statement (and do-while
* loop) in C++.
*
* YouTube Lesson: https://www.youtube.com/watch?v=APh9_Ot9ovE
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
  // The switch statement will present a menu for a "bank machine" (i.e ATM),
  // and will give the user options to deposit, withdraw, etc.  The menu will
  // be continually presented until the user decides to quit.

  // balance will store the bank account balance
  double balance = 0;

  // amount will store deposit and withdraw amounts
  double amount = 0;

  // choice will store the choice the user enters each time the menu is
  // presented
  int choice = 0;

  // quit will be used to help stop the loop, when quit is set to true the
  // loop will stop execution
  bool quit = false;


  // Loop to continually present the user with the menu and carry out requested
  // actions.  A do-while loop is used because we know the menu should be
  // presented to the user at least once (and the body of a do-while loop is
  // garaunteed to execute at least once).
  do
  {
    // Present the menu of options to the user, one option per line
    cout << "1) Deposit" << endl;
    cout << "2) Withdraw" << endl;
    cout << "3) Print Balance" << endl;
    cout << "4) Print Balance and Quit" << endl;
    cout << "5) Quit" << endl;

    // Prompt the user to enter their choice of options and store their entered
    // choice into the choice variable.
    cout << "Enter Choice: ";
    cin >> choice;

    // The switch statement will look at the value of choice, and attempt to
    // find a matching case.
    switch (choice)
    {
      // Carry out a deposit by requesting the user enter a deposit amount,
      // storing the deposit entered into amount, and then adding the amount
      // to the balance.
      case 1:
        cout << "Enter Amount: ";
        cin >> amount;
        balance += amount;
        break;

      // Withdraw is implemented in much the same way as deposit, except we
      // substract the entered amount from the balance.
      case 2:
        cout << "Enter Amount: ";
        cin >> amount;
        balance -= amount;
        break;

      // Output the balance
      case 3:
        cout << "Balance: " << balance << endl;
        break;

      // Output the balance AND quit... unlike the above cases, we don't use
      // break at the end of this case.  The break statement will break
      // execution out of the switch so that no remaining statements in the
      // switch are executed (the loop condition will be checked next).  This
      // is typical to see with cases inside a switch as we often want a
      // "group" of statements to execute for each case, and only that case.
      // But if we omit the break statement, execution will "fall-through"
      // to the staements of the case below.  The next case below implements
      // the logic required to quit, and this option (case 4) allows the user
      // to print the balance AND quit.  So we only implement the logic to
      // print the balance, and allow execution to fall through to the statement
      // below which will handle quitting!  This is called "fall-through" logic,
      // and though it can make switch statements more difficult to understand,
      // it can also reduce code duplication by including the execution of
      // "other case's" statements when a case above it matches.
      case 4:
        cout << "Balance: " << balance << endl;

      // Quit by setting quit to true which will cause the loop to stop, we
      // also output a goodbyte message.
      case 5:
        cout << "Goodbye!" << endl;
        quit = true;
        break;

      // If none of the cases above match the user must have entered an invalid
      // option and we output an error message.
      default:
        cout << "Invalid option entered!" << endl;
    }

  // quit is initialized to false and so !quit will be !false which is true,
  // we only set quit to true when the user decides to quit, and so we will
  // have !quit is !true which becomes false and the loop will stop.
  } while (!quit);

  return 0;
}