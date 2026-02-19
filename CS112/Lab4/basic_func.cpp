#ifndef BASIC_FUNC_CPP
#define BASIC_FUNC_CPP
#include "basic_func.h"

double avg(Student a[], int num){
    double sum = 0;
    for (int i = 0; i < num; i++){
        sum += a[i].marks;
    }
    return sum / num;
}

double max(Student a[], int num){
    double maxMarks = a[0].marks;
    for (int i = 1; i < num; i++){
        if (maxMarks < a[i].marks){
            maxMarks = a[i].marks;
        }
    }
    return maxMarks;
}

double min(Student a[], int num){
    double minMarks = a[0].marks;
    for (int i = 1; i < num; i++){
        if (minMarks > a[i].marks){
            minMarks = a[i].marks;
        }
    }
    return minMarks;
}

#endif