#include<iostream>
using namespace std;
class student{
    int std_id;
    string std_name;
    int roll_no;
public:
    student()
    {
        std_id = 100;
        std_name = "Bheem";
        roll_no = 1;
        cout<<"Constructor is called"<<"-->"<<std_name<<endl;
    }
    student(int std_id, string std_name, int roll_no)
    {
        this->std_id = std_id;
        this->std_name = std_name;
        this->roll_no = roll_no;
        cout<<"Constructor is called"<<"-->"<<std_name<<endl;
    }
    ~student()
    {
        cout<<"Destructor is called"<<"-->"<<std_name<<endl;
    }

    //The destructor is called when the object is destroyed. 
    //The destructor is called when the object goes out of scope or when the delete expression is applied to the object.
    //Constructors are called serially but destructors are called in reverse order of constructors.
};

int main()
{
    student s1;
    student s2(101, "Raju", 2);
    student *s3=new student(102, "Jaggu", 3);
    delete s3;
    return 0;
}