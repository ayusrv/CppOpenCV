#ifndef TALENT_H
#define TALENT_H

#include <iostream>

class Talent
{
private:
    std::string _talent_name {""};
    std::string _talent_college {""};
    int _talent_id {0};
public:
    Talent() = default;
    Talent(const Talent&) = default;
    Talent(Talent&&) = delete;
    Talent& operator = (const Talent&) = delete;
    Talent&& operator = (Talent&&) = delete;
    Talent(std::string talent_name, std::string talent_college, int talent_id);

    int traineeId() const { return _talent_id;}
    std::string talentCollege() const { return _talent_college; }
    std::string talentName() const { return _talent_name; }

    friend std::ostream &operator<<(std::ostream &os, const Talent &rhs);
};

#endif // TALENT_H
