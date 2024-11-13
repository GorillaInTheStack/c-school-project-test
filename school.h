#ifndef SCHOOL_H 
#define SCHOOL_H
#include <string.h>
#include <stdbool.h>

#define NAME_LENGTH 65
#define CLASS_COUNT 12

typedef struct Person Person;

typedef struct {
    char name[NAME_LENGTH];
    int studentCount;
    Person *teacher;
} Class;

typedef struct Person {
    char name[NAME_LENGTH];
    int age;
    bool isStudent;
    union{
        float grade;
        float salary;
    };
    Class *classes[CLASS_COUNT];
} Person;

Person* initStudent(Person *p, const char *name, int age, float grade);
Person* initTeacher(Person *p, const char *name, int age, float salary);
void printPerson(const Person *p);

Class* initClass(Class *c, const char *name, const Person *teacher);
void printClass(const Class *c);
int addPersonToClass(Person *p, Class *c);
int removePersonFromClass(Person *p, Class *c);

#endif
