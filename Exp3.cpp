#include <iostream>
#include <string>
using namespace std;
class Employee {
public:
    string name;
    int age;
    double salary;

    // Constructor to initialize the employee
    Employee(const string& empName, int empAge, double empSalary)
        : name(empName), age(empAge), salary(empSalary) {
    }

    // Default constructor
    Employee() {}

    void enterData() {
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Age: ";
        cin >> age;
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void displayData() {
        cout << "Employee Name: " << name <<endl;
        cout << "Employee Age: " << age << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main() {
    Employee employees[5]; // An array of 5 Employee objects

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Employee " << i + 1 << ":" <<endl;
        employees[i].enterData();
    }

    cout << "Employee Details:" <<endl;
    for (int i = 0; i < 5; i++) {
        cout << "Details of Employee " << i + 1 << ":" << endl;
        employees[i].displayData();
        }  
    return 0;
}