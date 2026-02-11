#ifndef BASIC_OPS_H
#define BASIC_OPS_H									// BASIC FUNCTIONS 

inline double add(double a, double b){				// making the function of the addition function 
    return a+b;
}
inline double sub(double a, double b){				// making the function of the subtraction function 
    return a-b;
}
inline double mul(double a, double b){				// making the function of the multiplication function 
    return a*b;
}
inline double div(double a, double b){				// making the function of the division function
    if(b==0){
        return 0;
    }
    return a/b;
}
#endif
