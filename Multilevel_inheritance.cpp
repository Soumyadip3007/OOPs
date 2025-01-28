
/**
 * @file Multilevel_inheritance.cpp
 * @brief This file contains an example of multilevel inheritance in C++.
 * 
 * Multilevel inheritance is a type of inheritance where a class is derived from another derived class.
 * In this example, the class `Person` is the base class, `Employee` is derived from `Person`, and `Manager` is derived from `Employee`.
 * 
 * Important Notes:
 * - Multilevel inheritance allows the creation of a hierarchy of classes that inherit properties and behaviors from their parent classes.
 * - The derived class inherits all the public and protected members of its base class.
 * - Constructors of the base classes are not inherited but can be called from the derived class constructors.
 * - Proper use of access specifiers (public, protected, private) is crucial to control the visibility of class members.
 * 
 * Classes:
 * - Person: The base class with a protected member `name` and a public method `get_name()`.
 * - Employee: Derived from `Person`, with an additional protected member `salary` and a public method `get_salary()`.
 * - Manager: Derived from `Employee`, with an additional protected member `department` and a public method `get_department()`.
 * 
 * Example Usage:
 * @code
 * Manager m1("Soumyadip", 100000, "Engineering");
 * m1.get_name();       // Outputs: My name is Soumyadip
 * m1.get_salary();     // Outputs: My salary is 100000
 * m1.get_department(); // Outputs: My department is Engineering
 * @endcode
 */
//This is a simple example of multilevel inheritance. Here, class Person is the base class, 
//Employee is derived from Person and Manager is derived from Employee.
#include<iostream>
using namespace std;

class Person
{
    protected:
        string name;
    public:
        void get_name()
        {
            cout<<"My name is "<<name<<endl;
        }
};

class Employee: public Person
{
    protected:
        int salary;
    public:
        void get_salary()
        {
            cout<<"My salary is "<<salary<<endl;
        }
};

class Manager: public Employee{
    protected:
        string department;
    public:
        Manager(string name, int salary, string department)
        {
            this->name = name;
            this->salary = salary;
            this->department = department;
        }
        void get_department()
        {
            cout<<"My department is "<<department<<endl;
        }
};

int main()
{
    Manager m1("Soumyadip", 100000, "Engineering");
    m1.get_name();
    m1.get_salary();
    m1.get_department();
    return 0;
}