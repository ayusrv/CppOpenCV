#include <iostream>
#include <functional>
#include <optional>
#include <memory>

class EkClass
{
private:
    /* data */
    int id;

public:
    EkClass(/* args */) {}
    ~EkClass() {}
    EkClass(int is) : id{is} {}

    friend std::ostream &operator<<(std::ostream &os, const EkClass &rhs)
    {
        os << "id: " << rhs.id;
        return os;
    }
};

using EkClassPointer = std::shared_ptr<EkClass>;

int main()
{

    EkClassPointer **arr = new EkClassPointer *[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = new EkClassPointer[3];
        for (int j = 0; j < 3; j++)
        {
            int temp;
            while (!(std::cin >> temp))
            {
                std::cout << "Wrong imput!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            arr[i][j] = std::make_shared<EkClass>(temp);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << *arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < 3; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}