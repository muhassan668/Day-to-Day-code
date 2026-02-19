#ifndef BASIC_FUNC_H
#define BAASIC_FUNC_H  


struct Student{
    char name[40];
    int marks;
    int rollno;
};

double avg(Student a[], int count);
double max(Student a[], int count);
double min(Student a[], int count);

#endif