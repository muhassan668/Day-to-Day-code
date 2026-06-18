#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
//#include <string> // Forced to include this because of the provided prototypes
using namespace std;

class BigInt {
private:
    int* digits;     // Dynamic array to hold each digit separately
    int length;      // How many digits the number has
    bool neg; // To handle negative numbers

public:
    BigInt(int val = 0); 
    BigInt(const string& text);
    BigInt(const BigInt& copy); 

    BigInt operator+(const BigInt& val) const;
    BigInt operator+(int val) const;
    BigInt operator-(const BigInt& val) const;
    BigInt operator-(int val) const;
    BigInt operator*(const BigInt& val) const;

    BigInt operator+=(const BigInt& rhs);
    BigInt operator-=(const BigInt& rhs);
    BigInt operator*=(const BigInt& rhs);

    bool operator==(const BigInt& val) const;
    bool operator==(const char* val) const;
    bool operator!=(const BigInt& val) const;
    bool operator<(const BigInt& val) const;
    bool operator<=(const BigInt& val) const;
    bool operator>(const BigInt& val) const;
    bool operator>=(const BigInt& val) const;

    BigInt& operator++(); 
    BigInt operator++(int); 
    BigInt& operator--();  
    BigInt operator--(int);

    operator string();
    operator int();   
    
    ~BigInt(); 

    friend ostream& operator<<(ostream& out, const BigInt& val);
    friend istream& operator>>(istream& in, BigInt& val);
};

#endif
