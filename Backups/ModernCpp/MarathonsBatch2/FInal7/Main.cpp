#include "classB.h"
#include "calssC.h"

#include <vector>
#include <memory>

int main()
{
    std::vector<ClassA*> obj;
    obj.push_back(new classB(12, "Aaa"));
    obj.push_back(new classB(13, "Aba"));
    obj.push_back(new classC(14, "Ana"));
    obj.push_back(new classC(15, "Ama"));

    // for(ClassA* cc : obj)
    // {
    //     classB* cb = dynamic_cast<classB*>(cc);
    //     if(cb)
    //     {
    //         cb->vechicle();
    //     }else{
    //         cc->vechicle();
    //     }
    // }
    for(int i=0;i<obj.size();i++)
    {
        delete obj[i];
    }
    // delete obj;
}