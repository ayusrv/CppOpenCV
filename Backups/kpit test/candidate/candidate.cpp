#include "candidate.h"
#include<iostream>
#include<string>
using namespace std;

Code_Test1::Code_Test1()
{
    this->codeTestId1 = 0;
    this->examDate1 = "";
    // const int maxMarks2 = 200;
    this->marks1 = 0;
}

Code_Test2::Code_Test2()
{
    this->codeTestId2 = 0;
    this->examDate2 = "";
    // const int maxMarks2 = 200;
    this->marks2 = 0;
}

Code_Test1::Code_Test1(int codeTestId1, string examDate1, int marks1) : codeTestId1(codeTestId1), examDate1(examDate1), marks1(marks1) {}

Code_Test2::Code_Test2(int codeTestId2, string examDate2, int marks2) : codeTestId2(codeTestId2), examDate2(examDate2), marks2(marks2) {}

void Code_Test1::accept()
{
    int codeTestId1;
    string examDate1;
    int marks1;

    cout << "Enter Code Test ID1: ";
    cin >> codeTestId1;
    cout << "Enter exam date 1: ";
    cin >> examDate1;
    cout << "Enter Marks 1: ";
    cin >> marks1;
    this->codeTestId1 = codeTestId1;
    this->examDate1 = examDate1;
    this->marks1 = marks1;
}
void Code_Test2::accept()
{
    int codeTestId2;
    string examDate2;
    int marks2;

    cout << "Enter Code Test ID2: ";
    cin >> codeTestId2;
    cout << "Enter exam date 2: ";
    cin >> examDate2;
    cout << "Enter Marks 2: ";
    cin >> marks2;
    this->codeTestId2 = codeTestId2;
    this->examDate2 = examDate2;
    this->marks2 = marks2;
}
ostream &operator<<(ostream &out, Code_Test1 &ct1)
{
    out << "Code Test 1 ID: " << ct1.codeTestId1 << "\n";
    out << "Code Test1 Date: " << ct1.examDate1 << "\n";
    out << "Code Test1 Marks: " << ct1.marks1 << "\n";
    return out;
}
ostream &operator<<(ostream &out, Code_Test2 &ct2)
{
    out << "Code Test2 ID: " << ct2.codeTestId2 << "\n";
    out << "Code Test2 Date: " << ct2.examDate2 << "\n";
    out << "Code Test2 Marks: " << ct2.marks2 << "\n";
    return out;
}

void Code_Test1::setCodeTestId1(int codeTestId1)
{
    this->codeTestId1 = codeTestId1;
}
void Code_Test1::setDate1(string date1)
{
    this->examDate1 = date1;
}
void Code_Test1::setMarks1(int marks1)
{
    this->marks1 = marks1;
}
int Code_Test1::getCodeTestId1()
{
    return codeTestId1;
}
string Code_Test1::getExamDate1()
{
    return examDate1;
}
int Code_Test1::getMarks1()
{
    return marks1;
}

Code_Test1::~Code_Test1() {}

void Code_Test2::setCodeTestId2(int codeTestId2)
{
    this->codeTestId2 = codeTestId2;
}
void Code_Test2::setDate2(string date2)
{
    this->examDate2 = date2;
}
void Code_Test2::setMarks2(int marks2)
{
    this->marks2 = marks2;
}
int Code_Test2::getCodeTestId2()
{
    return codeTestId2;
}
string Code_Test2::getExamDate2()
{
    return examDate2;
}
int Code_Test2::getMarks2()
{
    return marks2;
}
Code_Test2::~Code_Test2() {}

candidate::candidate()
{
    this->candidate_id = 0;
    this->candidate_name = "Ayush";
}

candidate::candidate(int codeTestId1, string examDate1, int marks1, int codeTestId2, string examDate2, int marks2, string candidate_name, int candidate_id, Job j)
    : Code_Test1(codeTestId1, examDate1, marks1), Code_Test2(codeTestId2, examDate2, marks2), candidate_name(candidate_name), candidate_id(candidate_id), j(j) {}

candidate::candidate(const candidate &c)
{
    this->candidate_name = c.candidate_name;
    this->candidate_id = c.candidate_id;
    this->j = c.j;
}

void candidate::setCandidateName(string candidate_name)
{
    this->candidate_name = candidate_name;
}

void candidate::setCandidateId(int candidate_id)
{
    this->candidate_id = candidate_id;
}

void candidate::setJob(Job j)
{
    this->j = j;
}

string candidate::getCandidate_name()
{
    return this->candidate_name;
}

int candidate::getCandidate_id()
{
    return candidate_id;
}

string candidate::getJob()
{
    if (j == Clerk)
        return "Clerk";
    else if (j == Manager)
        return "Manager";
    else
        return "Engineer";
}


Job getJob1(string jb)
{
    if (jb == "Clerk")
        return Clerk;
    else if (jb == "Manager")
        return Manager;
    else
        return Engineer;
}

void candidate::accept()
{
    string candidate_name;
    int candidate_id;
    string jb;
    cout<<"Enter candidate name: ";
    cin>>candidate_name;
    cout<<"ENter candidate id: ";
    cin>>candidate_id;
    cout<<"ENter job description: ";
    cin>>jb;
    Job j = getJob1(jb);
    Code_Test1::accept();
    Code_Test2::accept();
    this->candidate_name = candidate_name;
    this->candidate_id = candidate_id;
    this->j = j;
}

ostream &operator<<(ostream &out, candidate &c)
{
    out << "Candidate Name: " << c.candidate_name << "\n";
    out << "Candidate ID: " << c.candidate_id << "\n";
    out << "Candidate Job: " << c.getJob() << "\n";
    out << "Candidate CodeTestID1: " << c.getCodeTestId1() << "\n";
    out << "Candidate Code Test Exam Date: " << c.getExamDate1() << "\n";
    out << "Candidate Code Test Marks1: " << c.getMarks1() << "\n";
    out << "Candidate CodeTestID1: " << c.getCodeTestId2() << "\n";
    out << "Candidate Code Test Exam Date: " << c.getExamDate2() << "\n";
    out << "Candidate Code Test Marks1: " << c.getMarks2() << "\n";
    return out;
}

candidate::~candidate()
{
    cout << "Destructor Is called\n";
}