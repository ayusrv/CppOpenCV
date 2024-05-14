#include "TrainingSession.h"
std::ostream &operator<<(std::ostream &os, const TrainingSession &rhs) {
    os << "_hours: " << rhs._hours
       << " _number_of_students: " << rhs._number_of_students
       << " _trainer_name: " << rhs._trainer_name
       << " _topic: " << rhs._topic
       << " _date: " << rhs._date;
    return os;
}

TrainingSession::TrainingSession(unsigned int hours, unsigned int number_of_students, std::string trainer_name, std::string topic, std::string date)
                : _hours(hours), _number_of_students(number_of_students), _trainer_name(trainer_name), _topic(topic), _date(date) {}