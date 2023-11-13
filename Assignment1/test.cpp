#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    string jobTitle;
    string dateOfJoining;

public:
    Employee() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter job title: ";
        getline(cin, jobTitle);
        cout << "Enter date of joining: ";
        getline(cin, dateOfJoining);
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << "Date of Joining: " << dateOfJoining << endl;
    }
};

class RegularTeacher : public Employee {
protected:
    double monthlySalary;
    string qualification;

public:
    RegularTeacher() : Employee() {
        cout << "Enter monthly salary: ";
        cin >> monthlySalary;
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Enter qualification: ";
        getline(cin, qualification);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Monthly Salary: " << monthlySalary << endl;
        cout << "Qualification: " << qualification << endl;
    }
};

class VisitingTeacher : public Employee {
protected:
    double payRate;
    int hoursWorked;
    string qualification;

public:
    VisitingTeacher() : Employee() {
        cout << "Enter pay rate: ";
        cin >> payRate;
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Enter hours worked: ";
        cin >> hoursWorked;
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Enter qualification: ";
        getline(cin, qualification);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Pay Rate: " << payRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Qualification: " << qualification << endl;
    }
};

class Manager : public Employee {
protected:
    int totalExperience;

public:
    Manager() : Employee() {
        cout << "Enter total experience (in years): ";
        cin >> totalExperience;
        cin.ignore(); // Clear the newline character from the buffer
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Total Experience: " << totalExperience << " years" << endl;
    }
};

int main() {
    RegularTeacher regularTeacher;
    VisitingTeacher visitingTeacher;
    Manager manager;

    cout << "\nRegular Teacher Information:" << endl;
    regularTeacher.displayInfo();
    cout << endl;

    cout << "Visiting Teacher Information:" << endl;
    visitingTeacher.displayInfo();
    cout << endl;

    cout << "Manager Information:" << endl;
    manager.displayInfo();

    return 0;
}
