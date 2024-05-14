#include <iostream>
#include <limits>
 
/*
 
conversion operator 
casting opreator 
    [
Yes, the terms "conversion operator" and "casting operator" are often used interchangeably in the context of C++ programming. Both refer to the same concept: a member function of a class that allows the class to be implicitly converted to another type.
    ]
 
    class MyClass {
public:
    operator OtherType() const {
        // Conversion logic
    }
};
*/
class Overload
{
private:
    int l;
    int b;
    std::string name{"a"} ;
 
public:
    Overload() = default;
    Overload(int l, int b) : l(l), b(b) {}
 
    static void* operator new(size_t size)
    {
        return std::malloc(size); 
    }
    static void* operator new[](size_t size)
    {
        return std::malloc(size); 
    }
    static void operator delete(void * ptr) noexcept 
    {
        free(ptr) ;
    }
    static void operator delete[](void * ptr) noexcept
    {
        free(ptr) ;
    }
 
    operator int() const 
    {
        int val = 0 ; 
        for(const auto& it : name)
        val += static_cast<int>(it); // Convert char to int (ASCII) and add to sum
 
 
        return val ;
    }   
 
    Overload operator+(const Overload &obj)
    {
        Overload temp;
        temp.l = this->l + obj.l;
        temp.b = this->b + obj.b;
        return temp;
    }
 
    Overload operator+(const int val)
    {
        Overload temp;
        temp.l = this->l + val;
        temp.b = this->b + val;
        return temp;
    }
 
    friend Overload operator+(int val, const Overload &obj)
    {
        Overload temp;
        temp.l = val + obj.l;
        temp.b = val + obj.b;
        return temp;
    }
    // a++
    Overload operator++(int)
    {
        Overload temp = *this;
        this->l++;
        this->b++;
        return temp;
    }
    // ++a
    Overload &operator++()
    {
        this->l++;
        this->b++;
        return *this;
    }
 
    Overload *operator->()
    {
        return this;
    }
 
    Overload& operator*()
    {
        return *this ;
    }
 
    Overload operator*(const Overload& obj)
    {
        Overload temp ; 
        temp.l = this->l * obj.l ;  
        temp.b = this->b * obj.b ;  
        return temp; 
    }
 
    friend std::ostream& operator<<(std::ostream& os, const Overload& obj)
    {
        os << "Length => " << obj.l << "\n";
        os << "Breadth => " << obj.b << "\n";
        return os ;
    }
 
    friend std::istream& operator>>(std::istream& is, Overload& obj)
    {
        int l , b  ;
        std::cout << "Input for length  => " ; 
        while(!(is >> l ) || (l <= 0))
        {
            is.clear(); 
            is.ignore(std::numeric_limits<std::streamsize>::max() ,'\n'); 
            std::cout << "Input Wrong !! Retry\n" ; 
        }
        std::cout << "Input for Breadth  => " ; 
        while(!(is >> b ) || (b <= 0))
        {
            is.clear(); 
            is.ignore(std::numeric_limits<std::streamsize>::max() ,'\n'); 
            std::cout << "Input Wrong !! Retry\n" ; 
        }
 
        obj.l = l; 
        obj.b = b ;
 
        return is ; 
    }
 
    Overload& operator+=(const Overload & obj)
    {
        this->l += obj.l ;
        this->b += obj.b ;
        return *this ; 
    }
 
    bool operator==(const Overload& obj)
    {
        return (l== obj.l && b == obj.b) ;
    }
 
    bool operator!=(const Overload& obj)
    {
        return !(l== obj.l && b == obj.b) ;
    }
 
    char& operator[](int idx)
    {
        return this->name[idx] ;
    }
 
    void display()
    {
        std::cout << "l => " << l << " b => " << b << "\n";
    }

 
 
    ~Overload(){};
 
    std::string getName() const { return name; }
 
};
 
int main()
{
    Overload o1(10, 20);
    Overload o2(10, 20);
 
    // Overload o3 = o1 + o2 ;
    // o3.display() ;
 
    Overload o4 = o1 + 10;
    // o4.display();
 
    Overload o5 = 10 + o2;
    // o5.display();
 
    Overload o6 = o4++;
    o6.display();
    o4.display();
    Overload o7 = ++o5;
    o7.display();
    o5.display();
 
std::cout << "Overloading -> \n" ;
    o1->display(); 
    o2->display(); 
    o4->display(); 
std::cout << "Overloading * \n" ;
    (*o5)->display(); 
    (*o6)->display(); 
std::cout << "Overloading * multiply\n" ;
    Overload o8 = o1 * o2 ; 
    o8.display();
 
std::cout << "Overloading <<\n" ; 
std::cout << o8 << " \n" ;
 
// Overload o10 ; 
// std::cout << "Overloading >> \n" ; 
// std::cin >> o10; 
// std::cout << o10 ;
 
// std::cout << "Overloading +=\n" ;
//  std::cout << o1 ; 
//  o1 += o2 ; 
//  std::cout << o1 ;
 
std::cout << "overloading ==\n" ; 
std::cout << std::boolalpha << (o1 == o2) << "\n" ;
 
std::cout << "overloading !=\n" ; 
std::cout << std::boolalpha << (o1 != o2) << "\n" ;
 
std::cout << "Overloading []\n" ;
std::cout<< "Before " << o1[0] << "\n" ;
o1[0] = 'P' ;
std::cout<< "After " << o1[0] << "\n" ;
std::cout << o1.getName()<< "\n" ;
 
 
o1[0] = 'a' ; 
std::cout << "Trying conversion operator\n" ; 
int ans = (int)o1 ;
std::cout << "ASCII value for name is => " << ans << "\n" ;
 
}