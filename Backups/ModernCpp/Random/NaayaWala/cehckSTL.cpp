#include <iostream>

class checkSTL
{
private:
    int _sum{0};
    float _val{0.0f};
    std::string _name{""};
public:
    checkSTL() = delete;
    checkSTL(const checkSTL&) = delete;
    checkSTL(checkSTL&&) = delete;
    checkSTL& operator=(const checkSTL&) = delete;
    checkSTL& operator=(checkSTL&&) = delete;
    checkSTL(int sum, float val, std::string name) : _sum{sum}, _val{val}, _name{name} {}

    int sum() const { return _sum; }
    void setSum(int sum) { _sum = sum; }

    float val() const { return _val; }
    void setVal(float val) { _val = val; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }
};

 