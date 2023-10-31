#include <iostream>
#include<cstdlib> 
#include<cstring>
#include <typeinfo>

using namespace std;
#pragma once

class Student {
private:
    int ID;
    char* name;

public:
    Student();
    ~Student();
    Student(int stud_id, const char* stud_name);
    int SetID(int stud_id);
    int SetName(char* stud_name);
    int GetID();
    char* GetName();
    void Print();
    void operator=(Student src);//等號(class=class)
};