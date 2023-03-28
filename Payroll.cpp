#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeId;
    int scale;
    int workingHours;
public:
    void setName(string n) {
        name = n;
    }
    void setEmployeeId(int id) {
        employeeId = id;
    }
    void setScale(int s) {
        scale = s;
    }
    void setWorkingHours(int hours) {
        workingHours = hours;
    }
    string getName() {
        return name;
    }
    int getEmployeeId() {
        return employeeId;
    }
    int getScale() {
        return scale;
    }
    int getWorkingHours() {
        return workingHours;
    }
};

class Payroll {
private:
    Employee employee;
    double basicPay;
    double overtimePay;
    double grossPay;
    double netPay;
public:
    void setEmployee(Employee emp) {
        employee = emp;
    }
    void calculateBasicPay() {
        basicPay = employee.getScale() * employee.getWorkingHours();
    }
    void calculateOvertimePay() {
        if (employee.getWorkingHours() > 40) {
            overtimePay = (employee.getWorkingHours() - 40) * 1.5 * employee.getScale();
        }
        else {
            overtimePay = 0;
        }
    }
    void calculateGrossPay() {
        grossPay = basicPay + overtimePay;
    }
    void calculateNetPay() {
        double taxRate = 0.1;
        double taxAmount = grossPay * taxRate;
        netPay = grossPay - taxAmount;
    }
    double getBasicPay() {
        return basicPay;
    }
    double getOvertimePay() {
        return overtimePay;
    }
    double getGrossPay() {
        return grossPay;
    }
    double getNetPay() {
        return netPay;
    }
};

int main() {
    Employee emp;
    emp.setName("John Smith");
    emp.setEmployeeId(1001);
    emp.setScale(20);
    emp.setWorkingHours(45);

    Payroll payroll;
    payroll.setEmployee(emp);
    payroll.calculateBasicPay();
    payroll.calculateOvertimePay();
    payroll.calculateGrossPay();
    payroll.calculateNetPay();

    cout << "Name: " << emp.getName() << endl;
    cout << "Employee ID: " << emp.getEmployeeId() << endl;
    cout << "Scale: " << emp.getScale() << endl;
    cout << "Working Hours: " << emp.getWorkingHours() << endl;
    cout << "Basic Pay: " << payroll.getBasicPay() << endl;
    cout << "Overtime Pay: " << payroll.getOvertimePay() << endl;
    cout << "Gross Pay: " << payroll.getGrossPay() << endl;
    cout << "Net Pay: " << payroll.getNetPay() << endl;

    return 0;
}
