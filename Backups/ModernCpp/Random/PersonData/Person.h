#ifndef PERSON_H
#define PERSON_H

#include<iostream>

class Person{
    std::string _name{""};
    int _age{0};
    char _gender {'M'};
    long _aadhar{};

    public:
        Person() = default;
        Person(const Person&) = delete;
        Person(Person &&) = delete;
        Person& operator=(const Person&) = delete;
        Person& operator=(Person &&) = delete;

        Person(std::string name, int age, char gender, long aadhar);

        std::string name() const { return _name; }

        int roll() const { return _age; }
        void setRoll(int age) { _age = age; }

        char gender() const { return _gender; }
        void setGender(char gender) { _gender = gender; }

        long aadhar() const { return _aadhar; }

        friend std::ostream &operator<<(std::ostream &os, const Person &rhs);

        virtual ~Person();
};
#endif // PERSON_H