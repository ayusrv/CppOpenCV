//Tax payers -> Employees, bussinessOwnaers
#include <iostream>
#include <variant> //Algebraic data type (ADT) -> data type which is based on simple algebra like plus, minus
//This varient is called the functional pollymorphism
#include <array>

class BussinessOwner;
class Employee;
using VType = std::variant<Employee*, BussinessOwner*>;
using Container = std::array<VType,2>;

class BussinessOwner
{
private:
    std::string _name;
    std::string _companyGstNumber;
    float _revenue;
    float _expenses;
public:
    float CalculateTaxAmount() {return 0.3f * (_revenue - _expenses);}
    BussinessOwner(std::string name, std::string companyGstNumber, float revenue, float expenses) : _name{name}, _companyGstNumber{companyGstNumber}, _revenue{revenue}, _expenses{expenses} {}
    ~BussinessOwner() = default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }
};

class Employee
{
private:
    std::string _name;
    float _salary;
public:
    Employee(std::string name, float salary) : _name{name}, _salary{salary} {}
    ~Employee() =default;

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }
};

void CommonAction(Container &arr){
    for(VType v : arr)
    {
        std::visit([](auto &&val){std::cout<< val->name() <<"\n";}, v);
    }
}

//For eact vtype called "V" and 
    // a) open variant and check if v holds an alternative of type BussinessOwner*
    // b) if yes, get data from slot 1 of the varinet (bussinessOwner*) now, save this to a varient and access revenue
void DifferentAction(Container& arr){
    for(VType v : arr){
        if(std::holds_alternative<BussinessOwner*>(v)){
            BussinessOwner* ow = std::get<1>(v);
            std::cout<<ow->CalculateTaxAmount();
        }
    }
}

int main(){
    Employee* emp = new Employee("Ayush", 20000.f);
    BussinessOwner* business = new BussinessOwner("XYZ", "1910ahh", 100,50);
    Container arr {emp, business};
    CommonAction(arr);
    DifferentAction(arr);
}


/*

EMployee    Bussinessowner                            Employee    BussinessOwner
[ 0X100H |  ////          ]                        [ /////    |  0X987H       ]
<-------------------------------------arr--------------------------------------->

scenario 1 : I want to execute a function that is present in all types of the varient
            e.g getter for name

scenario 2: You want to call a function that only exists in some but not all types in the variant
*/

/*
    auto&& -> template parameter for lambda
*/

/*
    I want to use conatiner of variats where each variant is either of type Employee or Bussiness pointer
*/