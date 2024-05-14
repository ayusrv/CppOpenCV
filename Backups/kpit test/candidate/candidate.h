#ifndef CANDIDATE
#define CANDIDATE

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

enum Job
{
    Clerk,
    Manager,
    Engineer
};

class Code_Test1
{
protected:
    int codeTestId1;  
    string examDate1;
    const int maxMarks1 = 100;
    int marks1;

public:
    Code_Test1();
    Code_Test1(int codeTestId1, string examDate1, int marks1);
    void setCodeTestId1(int codeTestId1);
    void setDate1(string date1);
    void setMarks1(int marks1);
    int getCodeTestId1();
    string getExamDate1();
    int getMarks1();
    void accept();
    friend ostream &operator<<(ostream &out, Code_Test1 &ct1);
    ~Code_Test1();
};

class Code_Test2
{
protected:
    int codeTestId2;
    string examDate2;
    const int maxMarks2 = 200;
    int marks2;

public:
    Code_Test2();
    Code_Test2(int codeTestId2, string examDate2, int marks2);
    void setCodeTestId2(int codeTestId2);
    void setDate2(string date2);
    void setMarks2(int marks2);
    int getCodeTestId2();
    string getExamDate2();
    int getMarks2();
    void accept();
    friend ostream &operator<<(ostream &out, Code_Test2 &ct2);
    ~Code_Test2();
};

class candidate : public Code_Test1, public Code_Test2
{
protected:
    string candidate_name;
    int candidate_id;
    Job j;

public:
    candidate();
    candidate(int codeTestId1, string examDate1, int marks1, int codeTestId2, string examDate2, int marks2, string candidate_name, int candidate_id, Job j);
    candidate(const candidate &c);
    void setCandidateName(string candidate_name);
    void setCandidateId(int candidate_id);
    void setJob(Job j);
    string getCandidate_name();
    int getCandidate_id();
    string getJob();

    void accept();
    friend ostream &operator<<(ostream &out, candidate &can);
    ~candidate();
};

#endif