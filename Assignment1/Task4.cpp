#include <iostream>
#include <string>

using namespace std;

//employee class
class Employee {

//private data members
private:
    string name;
    string jobTitle;
    string dateOfJoining;

//public constructor
public:
    Employee(string name, string jobTitle, string dateOfJoining)
        : name(name), jobTitle(jobTitle), dateOfJoining(dateOfJoining) {}

    //virtual function to display info which will be overridden in derived classes
    virtual void displayInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Job Title: " << jobTitle << "\n";
        cout << "Date of Joining: " << dateOfJoining << "\n";
    }
};
//manager class inheriting employee class
class Manager : public Employee {

private:
    int totalExperience;

//public constructor
public:
    Manager(string name, string jobTitle, string dateOfJoining, int totalExperience)
        : Employee(name, jobTitle, dateOfJoining), totalExperience(totalExperience) {}

    //overriding displayInfo function
    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Total Experience: " << totalExperience << " years\n";
    }

};
//teacher class inheriting employee class
class Teacher : public Employee {
    
private:
    string qualification;

public:
    Teacher(string name, string jobTitle, string dateOfJoining, string qualification)
        : Employee(name, jobTitle, dateOfJoining), qualification(qualification) {}

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Qualification: " << qualification << "\n";
    }

};
//regular teacher class inheriting teacher class
class RegularTeacher : public Teacher {
private:
    double monthlySalary;

public:
    RegularTeacher(string name, string jobTitle, string dateOfJoining, string qualification, double monthlySalary)
        : Teacher(name, jobTitle, dateOfJoining, qualification), monthlySalary(monthlySalary) {}

    void displayInfo() const override {
        Teacher::displayInfo();
        cout << "Monthly Salary: $" << monthlySalary << "\n";
    }

};

class VisitingTeacher : public Teacher {
private:
    double payRate;
    int hoursWorked;

public:
    VisitingTeacher(string name, string jobTitle, string dateOfJoining, string qualification, double payRate, int hoursWorked)
        : Teacher(name, jobTitle, dateOfJoining, qualification), payRate(payRate), hoursWorked(hoursWorked) {}

    void displayInfo() const override {
        Teacher::displayInfo();
        cout << "Pay Rate: $" << payRate << " per hour\n";
        cout << "Hours Worked: " << hoursWorked << " hours\n";
    }

};

int main() {

    //creating objects of all classes and passing values to their constructors
    Manager manager("Muhammad Abdullah", "Manager", "2023-10-08", 10);
    //calling displayInfo function of manager class
    manager.displayInfo();
    cout << "\n";

    RegularTeacher regularTeacher("Sultan Mehmood", "Regular Teacher", "2022-02-15", "Ph.D. in AI", 5000.0);
    regularTeacher.displayInfo();
    cout << "\n";

    VisitingTeacher visitingTeacher("Zohaib Afzaal", "Visiting Teacher", "2020-03-20", "M.S in Computer Science", 30.0, 20);
    visitingTeacher.displayInfo();

    return 0;
}
