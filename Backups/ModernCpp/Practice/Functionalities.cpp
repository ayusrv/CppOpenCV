#include "Functionalities.h"

void CreateData(Container &data)
{

    EmployeePtr ep1 = std::make_shared<CorporateEmployee>("Ayush", "Pune", 21, Gender::MALE, 20000, EmployeeType::EMPLOYEE, "123");

    EmployeePtr ep2 = std::make_shared<CorporateEmployee>("Preeti", "CHandigarh", 25, Gender::FEMALE, 50000, EmployeeType::EMPLOYEE, "124");

    EmployeePtr ep3 = std::make_shared<CorporateEmployee>("Oory", "Mumbai", 21, Gender::OTHER, 40000, EmployeeType::EMPLOYEE, "125");

    std::vector<EmployeePtr> e1{ep1, ep2, ep3};

    data.emplace(std::make_shared<CorporateEmployee>("Nidhi", "Mumbai", 21, Gender::OTHER, 40000, EmployeeType::EMPLOYEE, "125"), e1);

    data.emplace(std::make_shared<Government>("Harshit", "Mumbai", 21, Gender::OTHER, 40000, EmployeeType::EMPLOYEE, 126), EmployeeVector{std::make_shared<Government>("Himanshu", "Rorkee", 21, Gender::MALE, 80000, EmployeeType::EMPLOYEE, 211), std::make_shared<Government>("Shreya", "Hyderabad", 25, Gender::FEMALE, 50000, EmployeeType::EMPLOYEE, 212), std::make_shared<Government>("Deepak Kalal", "Dekhi", 21, Gender::OTHER, 40000, EmployeeType::EMPLOYEE, 213)});

    data.emplace(std::make_shared<CorporateEmployee>("Shreya", "Mumbai", 21, Gender::OTHER, 40000, EmployeeType::EMPLOYEE, "175"), EmployeeVector{std::make_shared<CorporateEmployee>("Mausi", "Argentina", 36, Gender::MALE, 20000, EmployeeType::EMPLOYEE, "311"), std::make_shared<CorporateEmployee>("Rashmika", "Shimla", 28, Gender::FEMALE, 30000, EmployeeType::EMPLOYEE, "312"), std::make_shared<CorporateEmployee>("Saurav", "Assam", 21, Gender::OTHER, 40000, EmployeeType::EMPLOYEE, "313")});
}

void DisplayObject(Container &data)
{
    std::for_each(data.begin(), data.end(), [](const std::pair<EmployeePtr, EmployeeVector>& pr)
    {
        std::for_each(pr.second.begin(), pr.second.end(), [](const EmployeePtr& ep)
        {
            std::cout<<*ep<<"\n";
        });
    });
}

float AverageSalary(Container &data, std::string nm)
{

    Container::iterator itr = std::find_if(data.begin(), data.end(),[&](std::pair<EmployeePtr, EmployeeVector> pq) 
    {
        return pq.first->name() == nm;
    });

    EmployeeVector ev = (*itr).second;

    float sum = std::accumulate(ev.begin(), ev.end(), 0.0f, [](float stVal, const EmployeePtr& ep)
    {
        return stVal + ep->salary();
    });

    return sum/ev.size();
}

std::string findManagerId(Container &data, std::variant<std::string, int> ide)
{
    std::string ans;
    Container::iterator itr = std::find_if(data.begin(), data.end(), [&](std::pair<EmployeePtr, EmployeeVector> pr) {
        bool flag = false;
        if(std::holds_alternative<std::string>(ide))
        {
            std::for_each(pr.second.begin(), pr.second.end(), [&](const EmployeePtr& eptr)
            {
                if(std::dynamic_pointer_cast<CorporateEmployee>(eptr))
                {
                    std::shared_ptr<CorporateEmployee> ep = std::dynamic_pointer_cast<CorporateEmployee>(eptr);

                    if(ep->id()==std::get<std::string>(ide)){
                        ans = pr.first->name();
                        flag = true;
                    }
                }
            });
        }
        else{
            std::for_each(pr.second.begin(), pr.second.end(), [&](const EmployeePtr& eptr)
            {
                if(std::dynamic_pointer_cast<Government>(eptr))
                {
                    std::shared_ptr<Government> ep = std::dynamic_pointer_cast<Government>(eptr);

                    if(ep->id()==std::get<int>(ide))
                    {
                        ans = pr.first->name();
                        flag = true;
                    }
                }
            });
        }
        return flag;
    });

    return ans;
}

int countEmployee(Container &data, std::string name)
{
    auto itr = std::find_if(data.begin(), data.end(), [&](std::pair<EmployeePtr, EmployeeVector> ep)
    {
        return ep.first->name() == name;
    });

    return itr->second.size();
}

EmployeePtr ManagerDetails(Container &data, std::string name)
{
    auto itr = std::find_if(data.begin(), data.end(), [&](std::pair<EmployeePtr, EmployeeVector> ep)
    {
        bool flag = false;
        std::for_each(ep.second.begin(), ep.second.end(), [&](const EmployeePtr& eptr)
        {
            if(eptr->name() == name)
            {
                flag = true;
            }
        });
        return flag;
    });
    return itr->first;
}

float getTax(Container &data, std::string name)
{
    auto itr = std::find_if(data.begin(), data.end(), [&](std::pair<EmployeePtr, EmployeeVector> ep)
    {
        return ep.first->name() == name;
    });

    EmployeeVector ev = itr->second;

    auto itr2 = std::max_element(
        ev.begin(),
        ev.end(),
        [](const EmployeePtr& ep1, const EmployeePtr& ep2)
        {
            return ep1->CalculateTax() < ep2->CalculateTax();
        }
    );

    return itr2->get()->CalculateTax();
}