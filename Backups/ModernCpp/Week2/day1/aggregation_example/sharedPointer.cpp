#include<iostream>
#include<memory>
#include<vector>
class Demo;
class Child;
using ChildPointer=std::shared_ptr<Child>;
using DemoPointer=std::shared_ptr<Demo>;
class Child
{
private:
    /* data */
    std::string _name;
public:
    Child(std::string name) :_name{name}{}
    ~Child() {}
 
    friend std::ostream &operator<<(std::ostream &os, Child &rhs);
};
class Demo
{
private:
    /* data */
    int _id;
    ChildPointer _childDetail;
public:
    Demo(int id,ChildPointer childDetail) :_id{id},_childDetail{childDetail}{}
    ~Demo() {}
    ChildPointer childDetail() const { return _childDetail; }
    int id() const { return _id; }
    friend std::ostream &operator<<(std::ostream &os, const Demo &rhs) {
        os << "_id: " << rhs._id
           << " _childDetail: " << *(rhs._childDetail);
        return os;
    }
};

std::ostream &operator<<(std::ostream &os, Child &rhs) {
        os << "_name: " << rhs._name;
        return os;
    }
using Container=std::vector<DemoPointer>;
 
 
int main(){
 
    Container data;
    
    
 
    data.push_back(std::make_shared<Demo>(12,std::make_shared<Child>("Ayush")));
 
 
    for(DemoPointer d:data){
        ChildPointer temp=d->childDetail();
        if(temp!=nullptr){
            std::cout<<*temp<<std::endl;
        }
        else {
            std::cout<<"Fas gaya"<<std::endl;
            return 0;
        }
        std::cout<<d->id()<<std::endl;
    }
    return 0;
 
}