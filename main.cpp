#include <iostream>
#include <iomanip> // Include this header for std::setprecision
#include <string>

double calculateWeeklySalary(double hourlyWage, double hoursWorked) {
    const double regularHours = std::min(hoursWorked, 60.0);
    const double overtimeHours = std::max(hoursWorked - 60.0, 0.0);
    const double regularPay = regularHours * hourlyWage;
    const double overtimePay = overtimeHours * (hourlyWage * 3);
    const double totalPay = regularPay + overtimePay;
    return totalPay;
}

std::string getEmployeeName() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    return name;
}

int main() {
    std::cout << "Weekly Salary for employees 2023\n";
    std::cout << "##############################################################\n";
    std::cout << "please enter your name, wage and worked per hours\n";

    std::string employeeName = getEmployeeName();

    double hourlyWage;
    double hoursWorked;

    std::cout << "Enter hourly salary: ";
    std::cin >> hourlyWage;
    std::cout << "Enter hours worked: ";
    std::cin >> hoursWorked;

    if (std::cin.fail() || hoursWorked >= 60) {
        std::cout << "Invalid input. Please enter valid numbers and ensure hours worked is less than 60.\n";
    } else {
        double weeklySalary = calculateWeeklySalary(hourlyWage, hoursWorked);
        std::cout << "Employee: " << employeeName << "\n";
        std::cout << "Weekly Salary: $" << std::fixed << std::setprecision(2) << weeklySalary << "\n";
    }

    return 0;
}
