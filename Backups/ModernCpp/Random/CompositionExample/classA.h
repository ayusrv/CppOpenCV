#ifndef CLASSA_H
#define CLASSA_H

class classA
{
private:
    int _id{0};
    int _age{0};
public:
    classA()=default;
    classA(int id, int age):_id{id}, _age{age}{}
    ~classA()=default;

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }
};

#endif // CLASSA_H
