#include "Functionalities.h"

int main()
{
    Container data;
    CreateObject(data);
    Display(data);
    PassFaill(data);
    TeacherPointer tp = MaxMarks(data);
    std::cout<<"Marks marks that a teacher helped to score is: "<<tp->name()<<"\n";
    
    Priorities(data);
}