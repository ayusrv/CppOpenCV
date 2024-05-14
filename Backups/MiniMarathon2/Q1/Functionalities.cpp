#include "Functionalities.h"


//Counting the vowels and then checking if it is more than 3 or not
FType StringVowels = [](std::string s)
{
    std::cout<<"\nSTRING VALIDATION CHECK\n";
    int count = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    if (count >= 3)
    {
        std::cout << "String has atleast 3 Vowels" << std::endl;
    }
    else
    {
        std::cout << "String has less than 3 Vowels" << std::endl;
    }
};

//Checking the prefix if it starts with C++
FType CheckPrefix = [](std::string s)
{
    std::cout<<"\nSTRING PREFIX CHECKER\n";
    if (s.size() < 3)
    {
        throw SizeInvalidException("Size is not valid");
    }
    else
    {
        if (s[0] == 'C' && s[1] == '+' && s[2] == '+')
        {
            std::cout << "String starts with C++" << std::endl;
        }
        else
        {
            std::cout << "String doest not start with C++" << std::endl;
        }
    }
};

//Printing the last 3 characters of the string
FType LastCharacters = [](std::string s)
{
    std::cout<<"\nLAST THREE CHARACTERS PRINTING\n";
    if (s.size() < 3)
    {
        throw SizeInvalidException("Size is not valid");
    }
    else
    {
        std::cout << s[s.size() - 3] << s[s.size() - 2] << s[s.size() - 1] << std::endl;
    }
};

//Checking the fist character if it is 'a' / 'b' then printing the character, if ' ' then it is invalid else printing the first two character
FType FirstLetter = [](std::string s)
{
    std::cout<<"\n CHECKING FIRST TWO CHARACTERS\n";
    if (s.size() == 0)
    {
        throw SizeInvalidException("Size is not valid");
    }
    else
    {
        if (s[0] == 'a' || s[0] == 'b')
        {
            std::cout << s << std::endl;
        }
        else if (s[0] == ' ')
        {
            std::cout << "Invalid String" << std::endl;
        }
        else
        {
            if (s.size() < 2)
            {
                throw SizeInvalidException("Size is invalid");
            }
            else
            {
                std::cout << s[0] << s[1] << std::endl;
            }
        }
    }
};

//Checking the consecutive
FType Consecutive = [](std::string s)
{
    std::cout<<"\nCHECKING THE CONSECUTIVE CHARACTERS\n";
    if (s.size() <= 1)
    {
        throw SizeInvalidException("Size is not valid");
    }
    bool flag = false;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            std::cout << s[i] << std::endl;
            flag = true;
        }
    }
    if (!flag)
    {
        std::cout << s[s.size() - 2] << s[s.size() - 1] << std::endl;
    }
};

//Adapater function to validate the functions

void Adapter(ContainerFType& cFun, Container& data){
    for(int i=0;i<data.size();i++){
        cFun[i](data[i]);
    }
}


//Creating the objects
void CreateObjects(ContainerFType& fun, Container& data){
    data.push_back("Create");
    data.push_back("C++Program");
    data.push_back("Ayush");
    data.push_back("bucket");
    data.push_back("Common");

    fun.push_back(StringVowels);

    fun.push_back(CheckPrefix);

    fun.push_back(LastCharacters);

    fun.push_back(FirstLetter);
    
    fun.push_back(Consecutive);
}

Container Adapter(Container &data, unsigned int n)
{
    return Container();
}
