/*******************************************************************************
*
* Program: Savings Calculator
* 
* Description: A C++ savings calculator program which creates a table showing 
* the growth in savings year over year given an initial deposit, annual 
* contribution, rate of return and number of years.
*
* YouTube Lesson: https://www.youtube.com/watch?v=nXkYoNkmkZA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double balance = 0;
  double annualContribution = 0;
  double rateOfReturn = 0;
  int totalYears = 0;
  
  do
  {
    cout << "Initial Deposit: ";
    cin >> balance;
    if (balance < 0)
    {
      cout << "Initial deposit must be >= 0" << endl;
    }
  } while (balance < 0);
    
  do
  {
    cout << "Annual Contribution: ";
    cin >> annualContribution;
    if (annualContribution < 0)
    {
      cout << "Annual contribution must be >= 0" << endl;
    }
  } while (annualContribution < 0);
  
  do
  {
    cout << "Rate Of Return: ";
    cin >> rateOfReturn;
    if (rateOfReturn <= 0)
    {
      cout << "Rate of return must be > 0" << endl;
    }
  } while (rateOfReturn <= 0);
  
  do
  {
    cout << "Years To Grow: ";
    cin >> totalYears;
    if (totalYears <= 0)
    {
      cout << "Years to grow must be > 0" << endl;
    }
  } while (totalYears <= 0);
  
  
  cout << endl;
  cout << setw(10) << "Year";
  cout << setw(18) << "Start Balance";
  cout << setw(16) << "Interest";
  cout << setw(16) << "End Balance";
  cout << endl;
  
  for (int i = 0; i < 60; i++) cout << "*";
  cout << endl;
  
  for (int year = 1; year <= totalYears; year++)
  {
    cout << setw(10) << year;
    cout << setw(18) << fixed << setprecision(2) << balance;
    
    double interest = balance * (rateOfReturn / 100);
    balance += interest + annualContribution;
    
    cout << setw(16) << fixed << setprecision(2) << interest;
    cout << setw(16) << fixed << setprecision(2) << balance;
    cout << endl;
    
  }
  
  return 0;
}

// Initial Deposit = 10,000
// Annual Contribution = 1,000
// Rate Of Return = 7.25
// Years To Grow = 10
//
// Year     Start Balance        Interest     End Balance
// ************************************************************
//   1          10000.00          725.00        11725.00
//   2          11725.00          850.06        13575.06
//   3          13575.06          984.19        15559.25
//   4          15559.25         1128.05        17687.30
//   5          17687.30         1282.33        19969.63
//   6          19969.63         1447.80        22417.43
//   7          22417.43         1625.26        25042.69
//   8          25042.69         1815.60        27858.29
//   9          27858.29         2019.73        30878.01
//  10          30878.01         2238.66        34116.67
