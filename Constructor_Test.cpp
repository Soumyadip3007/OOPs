#include<iostream>
using namespace std;

class Book{
    string Book_id;
    int price;
    float volume;
public:
    Book()   //Default Constructor
    {
        this->Book_id="C++ For All";
        this->price=300;
        this->volume=35.4;
    }
    Book(string s, int a, float b)  //Parameterized Constructor
    {
        Book_id=s;
        price=a;
        volume=b;
    }

    //Constructor overloading--> Name is same but differs in passed arguments
    Book(string s, int a)
    {
        Book_id=s;
        price=a;
        volume=30.67;
    }
    //Copy Constructor
    Book(Book &B)
    {
        Book_id=B.Book_id;
        price=B.price;
        volume=B.volume;
    }
    void display()
    {
        cout<<Book_id<<"-->"<<price<<"-->"<<volume<<endl;
    }
// Constructors can be overloaded but not overridden.
// Constructors can be overloaded but not inherited.
// Constructors can be overloaded but not abstracted.
// Constructors can be overloaded but not finalised.
// Constructors can be used to check the required resources are available or not.
};

int main()
{
    Book B1;
    Book B2("Maths for ML",450,34.10);
    Book B3("Stats for ML",350);
    Book B4(B3);
    Book B5=B1;
    B1.display();
    B2.display();
    B3.display();
    B4.display();
    B5.display();
    return 0;
}