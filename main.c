#include <stdio.h>
#include "school.h"

int main() {
    Person student;
    initStudent(&student, "John Doe", 20, 3.5f);

    // Initialize some classes
    Class class1, class2, class3;

    // Give the classes some names
    strncpy(class1.name, "Math", NAME_LENGTH - 1);
    strncpy(class2.name, "Physics", NAME_LENGTH - 1);
    strncpy(class3.name, "Chemistry", NAME_LENGTH - 1);

    // Assign the student to some classes
    student.classes[0] = &class1;
    student.classes[1] = &class2;
    student.classes[2] = &class3;

    printPerson(&student);

    printf("Size of Person stuct: %lu bytes\n", sizeof(Person));
    printf("Size of Class: %lu bytes\n", sizeof(Class));
    
    return 0;
}