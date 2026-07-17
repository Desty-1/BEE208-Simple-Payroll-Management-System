Simple Payroll Management System

BEE 208: C++ Programming | Mid-Semester Practical Project



Group Information



* Course: BEE 208 - C++ Programming
* Department: Electrical/Electronic Engineering
* Faculty: Faculty of Engineering
* Institution: Accra Technical University
* Lecturer: Douglas Ayitey





Project Overview

Many small organisations calculate salaries manually using notebooks or calculators. This method leads to errors in allowances, deductions and net pay. This project develops a C++ programme that helps calculate employee payroll accurately and saves a simple record for reporting.



Aim

To develop a Simple Payroll Management System in C++ that calculates employee gross salary, deductions, net salary and payment status, then saves the payroll report into a text file.



Objectives



* Allow the user to enter employee details
* Calculate gross salary from basic salary and allowances
* Calculate total deductions
* Calculate net salary
* Classify salary status based on payment condition
* Display a clear payroll report
* Save payroll records into a text file
* Use GitHub and Markdown to document the project





Formula and Decision Rule

|ITEM|FORMULA/RULE|
|-|-|
|Gross Salary |Basic Salary + Allowance|
|Net Salary|Gross Salary - Deduction|
|Invalid Record|Any negative salary, allowance or deduction value|
|Ready for Payment|If deduction is less than or equal to gross salary|
|Review Required|If deduction is greater than gross salary|



C++ Concepts Used



* Input/Output using cin and cout
* Variables and data types — string, int, double
* Arithmetic operators for payroll calculations
* Relational and logical operators for validation
* if, else if and else statements for decision making
* For loop for processing multiple employees
* While loop for input validation
* Functions for salary calculation and display
* Classes and objects — EmployeePayroll class with private data members and public member functions
* File handling using ofstream to save payroll\_report.txt





How to Run the Programme



* Open main.cpp in Dev C++ or any C++ compiler
* Compile the programme
* Run the programme
* Enter the number of employees when prompted
* Enter each employee's details as requested
* View the payroll report on screen
* Open payroll\_report.txt to see the saved report





Sample Output

================================
SIMPLE PAYROLL MANAGEMENT SYSTEM
================================

Employee 1
-------------------
Employee ID   : 01242516B
Employee Name : Anim Prince Duah
Department    : Engingineering Department
Basic Salary  : GHS 5000.00
Allowance     : GHS 1500.00
Deduction     : GHS 500.00
Gross Salary  : GHS 6500.00
Net Salary    : GHS 6000.00
Status        : Ready for Payment
================================

Employee 2
-------------------
Employee ID   : 01242959B
Employee Name : Essel Richmond
Department    : Engineering Department
Basic Salary  : GHS 4000.00
Allowance     : GHS 600.00
Deduction     : GHS 100.00
Gross Salary  : GHS 4600.00
Net Salary    : GHS 4500.00
Status        : Ready for Payment
================================

================================
PAYROLL SUMMARY
================================
Total employees processed : 2
Total payroll amount      : GHS 10500.00
================================

Files in This Repository

|FILE|DESCRIPTION|
|-|-|
|main.cpp|Main C++ source code|
|README.md|Project documentation and usage guide|
|algorithm.txt|Step by step algorithm|
|pseudocode.txt|Pseudocode for the programme logic|
|flowchart.png|Flowchart of the programme logic|
|payroll\_report.txt|Generated payroll report from the programme|



Individual Contribution Table

|STUDENT|ROLE|CONTRIBUTION|
|-|-|-|
|Apaabey Awenpagrim (01244078B)|Project Lead|Overall coordination and management|
|AnimPrince Duah (01242516B)|Algorithm writer|Wrote the step by step algorithm|
|Amponsah David Kweku (01244372B)|Pseudocode Writer|Wrote the pseudocode|
|Essel Richmond (01242959B)|Flowchart Designer|Designed the programme flowchart|
|Ibrahim Nyamikeh (01243690B)|C++ Programmer|Wrote the main C++ code|
|Israel Ashirifi Gogo (01241565B)|C++ Programmer|Assisted with coding and debugging|
|Faisel Ali (01242908B)|Testing Lead|Tested programme with multiple inputs|
|Adusu Destiny (01242847B)|GitHub Manager|Managed repository and uploads|
|Abdul Mutalib Nazir (01243260B)|Documentation Lead|Wrote README and documentation|
|Anti Patrick (01242896B)|Presentation Lead|Prepared group presentation|



Challenges and Solutions



* Challenge: Handling employee names with spaces using cin
* Solution: Used getline() after cin.ignore() to properly read full names
* Challenge: Saving formatted output to a text file
* Solution: Used ofstream and the same formatting as screen output





BEE 208 | Accra Technical University | Faculty of Engineering



