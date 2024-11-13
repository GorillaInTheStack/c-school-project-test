#include "school.h"
#include <stdio.h>

Person* initStudent(Person *p, char *name, int age, float grade)
{
    name[sizeof(name)-1] = "\0";
    int length = (int)strlen(name);

    if (p == NULL) {
        printf("Person is NULL\n");
        return NULL;
    }

    if (length >= NAME_LENGTH)
    {
        printf("Name is too long\n");
        return NULL;
    }else{
        strncpy(p->name, name, NAME_LENGTH-1);
        p->name[NAME_LENGTH - 1] = '\0';
    }

    if (age < 0)
    {
        printf("Age is invalid\n");
        return NULL;
    }

    p->age = age;
    p->isStudent = true;
    p->grade = grade;

    for (int i = 0; i < CLASS_COUNT; i++) {
        p->classes[i] = NULL;
    }

    return p;
}

Person* initTeacher(Person *p, const char *name, int age, float salary)
{
    int length = (int)strlen(name);

    if (p == NULL) {
        printf("Person is NULL\n");
        return NULL;
    }

    if (length >= NAME_LENGTH)
    {
        printf("Name is too long\n");
        return NULL;
    }else{
        strncpy(p->name, name, NAME_LENGTH-1);
        p->name[NAME_LENGTH - 1] = '\0';
    }

    if (age < 0)
    {
        printf("Age is invalid\n");
        return NULL;
    }

    p->age = age;
    p->isStudent = false;
    p->salary = salary;

    for (int i = 0; i < CLASS_COUNT; i++) {
        p->classes[i] = NULL;
    }

    return p;
}

void printPerson(const Person *p)
{
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Is student: %s\n", p->isStudent ? "true" : "false");
    if (p->isStudent)
        printf("Grade: %.2f\n", p->grade);
    else
        printf("Salary: %.2f\n", p->salary);

    // + CLASS_COUNT + 1 is for the spaces between the class names and the null terminator
    int length = CLASS_COUNT * NAME_LENGTH + CLASS_COUNT + 1;
    char classString[length];
    memset(classString, '\0', sizeof(classString));

    for (int i = 0; i<CLASS_COUNT; i++)
    {
        if(p->classes[i] != NULL)
        {
            strncat(classString, p->classes[i]->name, NAME_LENGTH-1);
            strcat(classString, " ");
        }
    }
    classString[length - 1] = '\0';

    if (p->classes[0] != NULL)
        printf("Classes: %s\n", classString);
    else
        printf("Classes: None\n");
}

Class* initClass(Class *c, const char *name, const Person *teacher)
{
    if (c == NULL)
    {
        printf("Class is NULL\n");
        return NULL;
    }

    int length = (int)strlen(name);
    if (length >= NAME_LENGTH)
    {
        printf("Name is too long\n");
        return NULL;
    }

    if (teacher == NULL)
    {
        printf("Teacher is NULL\n");
        return NULL;
    }

    strncpy(c->name, name, NAME_LENGTH-1);

    c->studentCount = 0;

    c->teacher = teacher;

    return c;

}

void printClass(const Class *c)
{
    if (c == NULL)
    {
        printf("Class is NULL\n");
        return;
    }

    printf("Class name: %s\n", c->name);
    printf("Teacher: %s\n", c->teacher->name);
    printf("Student count: %d\n", c->studentCount);
}

int addPersonToClass(Person *p, Class *c)
{
    if (p == NULL)
    {
        printf("Person is NULL\n");
        return -1;
    }
    if (c == NULL)
    {
        printf("Class is NULL\n");
        return -1;
    }

    if (c->studentCount >= CLASS_COUNT && p->isStudent)
    {
        printf("Class is full\n");
        return -1;
    }

    for (int i = 0; i < CLASS_COUNT; i++)
    {
        if (p->classes[i] == NULL)
        {
            p->classes[i] = c;
            break;
        }
    }

    if (p->isStudent == true)
    {
        c->studentCount++;
        return 0;
    }else if (p->isStudent == false)
    {
        if(c->teacher == NULL)
        {
            c->teacher = p;
            return 0;
        }else{
            printf("Class already has a teacher\n");
            return -1;
        }
    }

    return -1;
}

int removePersonFromClass(Person *p, Class *c)
{
    if (p == NULL)
    {
        printf("Person is NULL\n");
        return -1;
    }
    if (c == NULL)
    {
        printf("Class is NULL\n");
        return -1;
    }

    if (c->studentCount <= 0 && p->isStudent)
    {
        printf("Class is empty\n");
        return -1;
    }

    for (int i = 0; i < CLASS_COUNT; i++)
    {
        if(p->classes[i]->name == c->name)
        {
            p->classes[i] = NULL;
            break;
        }
    }

    if (p->isStudent == true)
    {
        c->studentCount--;
        return 0;
    }else if (p->isStudent == false)
    {
        c->teacher = NULL;
        return 0;
    }

    return -1;
}
