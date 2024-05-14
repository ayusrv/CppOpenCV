#include <iostream>
#include <stdexcept>
class Parent
{
private:
    /* data */
public:
    Parent(/* args */) {}
    virtual void magic() = 0;
    ~Parent() {}
};

class Child : public Parent
{
private:
    /* data */
public:
    Child(/* args */) {}
    ~Child() {}
    void ChildDisplay() { std::cout << "Done\n"; }
    void magic() override
    {
        std::cout << "Magic from child\n";
    }
};

class Child1 : public Parent
{
private:
    /* data */
public:
    Child1(/* args */) {}
    ~Child1() {}
    void ChildDisplay() { std::cout << "Done\n"; }
    void magic() override
    {
        std::cout << "Magic from child\n";
    }
};


//Upcasting mai base class destructor has to be marked as virtual

int main()
{
    float f1 = 10.8f;
    // int n1 = (float) "jii"; //c style cast and this is not possible
    int n1 = static_cast<int>('A');
    // if working on two types there is no virtual, dynamic, inheritance
    // then do static cast with additional benift of assertion
    // static_cast connot remove const
    //  static_assert(); //It has assertion valriable
    std::cout << n1 << "\n"; // lossy conversion //10

    // Type 2: This cast when parent-child runtime polymorphism is in picture
    // a) Converting reference
    // b) Converting pointer

    // Converting reference
    try{
        Parent *ptr = new Child1();
        Child &ch = dynamic_cast<Child &>(*ptr);
        ch.ChildDisplay();
    }
    catch(std::bad_cast &p){
        std::cout<<p.what()<<"\n";
    }
    // Converting pointer -> if conversion fails, we get nullptr
    Parent *ptr2 = new Child(); // UPCASTING
    ptr2->magic();              // ptr type is Parent. Function in virtual
    // ptr->ChildDisplay() // THis will give error kyuki ye virtual mark nahi hai
    Child *temp = dynamic_cast<Child *>(ptr2); //DOWNCASTING
    if (temp != nullptr)
        temp->ChildDisplay();
}


//DYNAMIC
    //Inheritance
    //Upcasting
    //koi ek function missing hai parent mai
    //Virtual


//