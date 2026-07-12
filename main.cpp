#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

// EmployeePayroll Class
class EmployeePayroll {
	private:
		string employeeID;
		string employeeName;
		string department;
		double basicSalary;
		double allowance;
		double deduction;
		double grossSalary;
		double netSalary;
		string salaryStatus;
		
	public:
		// Set employee details
		void setEmployeeDetails(string id, string name, string dept,
		double basic, double allow, double deduct ) {
			employeeID = id;
			employeeName = name;
			department = dept;
			basicSalary = basic;
			allowance = allow;
			deduction = deduct;
		}
		
		// Validate details
		bool validateDetails() {
			if (basicSalary< 0 || allowance <0 || deduction < 0) {
				return false;
			}
			return  true;
		}
		
		// Calculate gross salary
		void calculateGrossSalary(){
			grossSalary = basicSalary + allowance;
		}
		
		// Calculate net salary
		void calculateNetSalary(){
			netSalary = grossSalary - deduction;
		}
		
		// Check salary status
		void checkSalaryStatus() {
			if (deduction > grossSalary) {
				salaryStatus = "Review Required";
			} else {
				salaryStatus = "Ready for Payment";
			}
		}
		
		// Get net salary
		double getNetSalary() {
			return netSalary;
		}
		
		// Display payroll report
		void displayPayrollReport() {
			cout << "\n<================================"<< "\n";
        	cout << "PAYROLL REPORT"<< "\n";
        	cout << "================================" << "\n";
        	cout << fixed << setprecision(2);
        	cout << "Employee ID   : "<< employeeID << "\n";
	        cout << "Employee Name : "<< employeeName<< "\n";
	        cout << "Department    : "<< department<< "\n";
        	cout << "Basic Salary  : GHS "<<basicSalary<< "\n";
        	cout << "Allowance     : GHS "<< allowance << "\n";
	        cout << "Deduction     : GHS "<< deduction << "\n";
         	cout << "Gross Salary  : GHS "<< grossSalary<< "\n";
         	cout << "Net Salary    : GHS "<< netSalary<< "\n";
        	cout << "Status        : "<< salaryStatus<< "\n";
        	cout << "================================" << "\n";
		}
		
		// Save payroll report to file
		void savePayrollReport(ofstream& file, int empNumber) {
			file << "Employee " << empNumber << "\n";
			file << "-------------------" << "\n";
	        file << fixed << setprecision(2);
	        file << "Employee ID   : "<< employeeID << "\n";
	        file << "Employee Name : "<< employeeName<< "\n";
         	file << "Department    : "<< department<< "\n";
	        file << "Basic Salary  : GHS "<<basicSalary<< "\n";
	        file << "Allowance     : GHS "<< allowance << "\n";
        	file << "Deduction     : GHS "<< deduction << "\n";
        	file << "Gross Salary  : GHS "<< grossSalary<< "\n";
	        file << "Net Salary    : GHS "<< netSalary<< "\n";
	        file << "Status        : "<< salaryStatus<< "\n";
	        file << "================================" << "\n\n";
		}
};

int main() {
	// Variables
	int numberofEmployees, employeeCount = 0;
	double totalPayroll = 0.0;
	string employeeID, employeeName, department;
	double basicSalary, allowance, deduction;
	
	// Welcome message
	cout << "================================"<< "\n";
	cout << "SIMPLE PAYROLL MANAGEMENT SYSTEM"<< "\n";
	cout << "================================"<< "\n\n";
	
	// Get  number of employees
	cout << "Enter number of employees: ";
	cin >> numberofEmployees;

	// Validate number of employees
	while (numberofEmployees <= 0) {
		cout << "Invalid input. Please enter a positive number: ";
		cin >> numberofEmployees;	
	}
	
// Open file for saving
ofstream payrollFile("payroll_report.txt");
payrollFile << "================================"<< "\n";
payrollFile << "SIMPLE PAYROLL MANAGEMENT SYSTEM"<< "\n";
payrollFile << "================================"<< "\n\n";

// Process each employee
for (int i =1; i <= numberofEmployees; i++) {
	
	cout << "\nEmployee "<< i << "\n";
	cout << "--------------------"<< "\n";
	
	// Input employee details
	cout << "Enter employee ID: ";
	cin >> employeeID;
	
	cout << "Enter employee name: ";
	cin.ignore();
	getline(cin, employeeName);
	
	cout << "Enter department: ";
	getline(cin, department);
	
	cout << "Enter basic salary: ";
	cin >> basicSalary;
	
	cout << "Enter allowance: ";
	cin >> allowance;
	
	cout << "Enter deduction: ";
	cin >> deduction;
	
	// Create employee object
	EmployeePayroll employee;
	
	// Set employee details
	employee.setEmployeeDetails(employeeID, employeeName, department,
	basicSalary, allowance, deduction);
	
	// Validate inputs
	if (!employee.validateDetails()) {
		cout << "Invalid payrollrecord - negative values not allowed\n";
		cout << "Skipping this employee...\n";
		continue;
	}
	
	// Calculate salaries
	employee.calculateGrossSalary();
	employee.calculateNetSalary();
	employee.checkSalaryStatus();
	
	// Update counters
	employeeCount++;
	if (employee.getNetSalary() > 0) {
		totalPayroll += employee.getNetSalary();
	}
	
	// Display payroll report
	employee.displayPayrollReport();
	
	// Save to file
	employee.savePayrollReport(payrollFile, i);
}

// Display summmary
cout << "\n================================" << "\n";
cout << "PAYROLL SUMMARY" << "\n";
cout << "================================" << "\n";
cout << "Total employees processed : " << employeeCount << "\n";
cout << fixed << setprecision(2);
cout << "Total payroll amount      : GHS "<< totalPayroll<< "\n";
cout << "================================"<< "\n";
cout << "Payroll report saved successfully to payroll_report.txt"<< "\n";
cout << "================================"<< "\n";

// Save summary to file
payrollFile << "================================"<< "\n";
payrollFile << "PAYROLL SUMMARY" << "\n";
payrollFile << "================================"<<"\n";
payrollFile << "Total employees processed : "<< employeeCount << "\n";
payrollFile << fixed << setprecision(2);
payrollFile << "Total payroll amount      : GHS "<< totalPayroll << "\n";
payrollFile << "================================" << "\n";

// Close file
payrollFile.close();

return 0;
}
