#include <iostream>
#include <vector>
#include "Student.h"

int main()
{
    std::vector<Student> students;

    students.emplace_back(1, "Alice", 91.5);
    students.emplace_back(2, "Bob", 84.2);
    students.emplace_back(3, "Charlie", 76.8);

    std::cout << "Student List\n";
    std::cout << "------------\n";

    for (const auto &student : students)
    {
        student.display();
        std::cout << "----------------\n";
    }

    return 0;
}