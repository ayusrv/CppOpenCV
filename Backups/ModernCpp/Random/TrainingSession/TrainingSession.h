#ifndef TRAININGSESSION_H
#define TRAININGSESSION_H

#include <iostream>

class TrainingSession
{
private:
    unsigned int _hours;
    unsigned int _number_of_students;
    std::string _trainer_name;
    std::string _topic;
    std::string _date;
public:
    TrainingSession(/* args */) {}
    ~TrainingSession() {}

    std::string date() const { return _date; }
    void setDate(const std::string &date) { _date = date; }

    std::string topic() const { return _topic; }
    void setTopic(const std::string &topic) { _topic = topic; }

    std::string trainerName() const { return _trainer_name; }
    void setTrainerName(const std::string &trainer_name) { _trainer_name = trainer_name; }

    unsigned int numberOfStudents() const { return _number_of_students; }
    void setNumberOfStudents(unsigned int number_of_students) { _number_of_students = number_of_students; }

    unsigned int hours() const { return _hours; }
    void setHours(unsigned int hours) { _hours = hours; }

    TrainingSession(unsigned int _hours, unsigned int _number_of_students, std::string _trainer_name, std::string _topic, std::string _date);

    friend std::ostream &operator<<(std::ostream &os, const TrainingSession &rhs);
};

#endif // TRAININGSESSION_H
