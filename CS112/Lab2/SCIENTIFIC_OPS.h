#ifndef SCIENTIFIC_OPS_H
#define SCIENTIFIC_OS_H									// SCIENTIFIC OPERATIONS
#include <math.h>

inline double power(double base, double exp){			// making the function for the power operation 
    return pow(base, exp);
}
inline double sq_root(double n){						// making the function for the square root operation 
    if(n<0){
        return 0;
    } 
    return sqrt(n);
}
inline double log(double n){							// making the function for the log operation 
    if(n<=0){
        return 0;
    }
    return log(n);
}
#endif
