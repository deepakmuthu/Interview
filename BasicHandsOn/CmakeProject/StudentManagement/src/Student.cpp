#include "Student.h"
#include <iostream>

Student::Student(int id, std::string name, float marks)
{
    this->id = id;
    this->name = name;
    this->marks = marks;
}

void Student::display() const
{
    std::cout << "ID    : " << id << std::endl;
    std::cout << "Name  : " << name << std::endl;
    std::cout << "Marks : " << marks << std::endl;
}