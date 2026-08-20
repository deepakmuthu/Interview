#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
    private:
        int id;
        std::string name;
        float marks;

    public:
        Student(int id, std::string name, float marks);

        void display() const;
};

#endif