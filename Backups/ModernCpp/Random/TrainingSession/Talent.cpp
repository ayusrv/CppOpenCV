#include "Talent.h"
std::ostream &operator<<(std::ostream &os, const Talent &rhs) {
    os << "_talent_name: " << rhs._talent_name
       << " _talent_college: " << rhs._talent_college
       << " _trainee_id: " << rhs._talent_id;
    return os;
}

Talent::Talent(std::string talent_name, std::string talent_college, int talent_id)
        :_talent_name(talent_name), _talent_college(talent_college), _talent_id(talent_id) {}