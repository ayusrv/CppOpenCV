#include "Section.h"
std::ostream &operator<<(std::ostream &os, const Section &rhs) {
    os << "_uid: " << rhs._uid
       << " _section_name: " << rhs._section_name
       << " _branch: " << *rhs._branch;
    return os;
}

Section::Section(std::string uid, std::string section_name, std::shared_ptr<Branch> branch)
        : _uid{uid}, _section_name{section_name}, _branch{branch} {}