#include<iostream>
#include "BigInt.h"
using namespace std;

BigInt::BigInt(int val){
	if(val <0){
		neg = true;
		val = -val;
	}else{
		neg = false;
	}
	if(val == 0){
		length = 1;
		digits = new int[1];
		digits[0] = 0;
		return;
	}
	int temp = val;
	length = 0;
	while(temp>0){
		length++;
		temp /= 10;
	}
	digits = new int[length];
	temp = val;
	for(int i=0;i<length;i++){
		digits[i] = temp%10;
		temp /=10;
	}
}
BigInt::BigInt(const string& text){
	int strlength = 0;
	while(text[strlength] != '\0'){
		strlength++;
	}
	int startindex = 0;
	if(strlength>0 && text[0] == '-'){
		neg = true;
		startindex = 1;
	}else{
		neg = false;
	}
	length = strlength - startindex;
	digits = new int[length];
	for(int i=0; i<length; i++){
		char currentchar = text[strlength -1 -i];
		digits[i] = currentchar - '0';
	}
}
BigInt::BigInt(const BigInt& copy) {
    length = copy.length;
    neg = copy.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = copy.digits[i];
    }
}
BigInt::~BigInt() {
    delete[] digits; 
}
bool BigInt::operator==(const BigInt& val) const {
    if (neg != val.neg) return false;
    if (length != val.length) return false;
    for (int i = 0; i < length; i++) {
        if (digits[i] != val.digits[i]) return false;
    }
    return true;
}
bool BigInt::operator<(const BigInt& val) const {
    if (neg && !val.neg) return true;
    if (!neg && val.neg) return false;
    if (length != val.length) {
        if (!neg) {
            return length < val.length;
        } else {
            return length > val.length;
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        if (digits[i] != val.digits[i]) {
            if (!neg) {
                return digits[i] < val.digits[i];
            } else {
                return digits[i] > val.digits[i];
            }
        }
    }
    return false;
}
bool BigInt::operator!=(const BigInt& val) const {
    return !(*this == val);
}
bool BigInt::operator<=(const BigInt& val) const {
    return (*this < val) || (*this == val);
}
bool BigInt::operator>(const BigInt& val) const {
    return !(*this <= val);
}
bool BigInt::operator>=(const BigInt& val) const {
    return !(*this < val);
}
bool BigInt::operator==(const char* val) const {
    BigInt temp(val);
    return *this == temp;
}
BigInt BigInt::operator-(const BigInt& val) const {
    if (neg != val.neg) {
        BigInt temp = val;
        temp.neg = neg;
        return *this + temp;
    }
    bool resultNeg = false;
    const BigInt* larger = this;
    const BigInt* smaller = &val;
    BigInt absThis = *this; absThis.neg = false;
    BigInt absVal = val; absVal.neg = false;
    if (absThis < absVal) {
        larger = &val;
        smaller = this;
        resultNeg = !neg;
    } else {
        resultNeg = neg;
    }
    BigInt result;
    delete[] result.digits;
    result.length = larger->length;
    result.digits = new int[result.length];
    result.neg = resultNeg;
    int borrow = 0;
    for (int i = 0; i < result.length; i++) {
        int diff = larger->digits[i] - borrow;
        if (i < smaller->length) {
            diff -= smaller->digits[i];
        }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }
    while (result.length > 1 && result.digits[result.length - 1] == 0) {
        result.length--;
    }
    int* tempDigits = new int[result.length];
    for (int i = 0; i < result.length; i++) {
        tempDigits[i] = result.digits[i];
    }
    delete[] result.digits;
    result.digits = tempDigits;
    if (result.length == 1 && result.digits[0] == 0) {
        result.neg = false;
    }
    return result;
}
BigInt BigInt::operator-(int val) const {
    BigInt temp(val);
    return *this - temp;
}
BigInt BigInt::operator*(const BigInt& val) const {
    BigInt result;
    delete[] result.digits;
    if ((length == 1 && digits[0] == 0) || (val.length == 1 && val.digits[0] == 0)) {
        result.length = 1;
        result.digits = new int[1]{0};
        result.neg = false;
        return result;
    }
    result.length = length + val.length;
    result.digits = new int[result.length];
    for (int i = 0; i < result.length; i++) {
        result.digits[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        int carry = 0;
        for (int j = 0; j < val.length; j++) {
            int product = digits[i] * val.digits[j] + result.digits[i + j] + carry;
            result.digits[i + j] = product % 10;
            carry = product / 10;
        }
        if (carry > 0) {
            result.digits[i + val.length] += carry;
        }
	}
    while (result.length > 1 && result.digits[result.length - 1] == 0) {
        result.length--;
    }
    int* tempDigits = new int[result.length];
    for (int i = 0; i < result.length; i++) {
        tempDigits[i] = result.digits[i];
    }
    delete[] result.digits;
    result.digits = tempDigits;
    result.neg = (neg != val.neg);
    return result;
}
BigInt BigInt::operator+(const BigInt& val) const {
    if (this->neg && !val.neg) {
        BigInt temp = *this;
        temp.neg = false; 
        return val - temp;
    } else if (!this->neg && val.neg) {
        BigInt temp = val;
        temp.neg = false;
        return *this - temp;
    }
    BigInt result;
    delete[] result.digits; 
    result.neg = this->neg;
    int maxLen = (length > val.length) ? length : val.length;
    result.digits = new int[maxLen + 1];
    int carry = 0;
    int i = 0;
    while (i < length || i < val.length || carry > 0) {
        int sum = carry;
        if (i < length) sum += digits[i];
        if (i < val.length) sum += val.digits[i];
        result.digits[i] = sum % 10; 
        carry = sum / 10;           
        i++;
    }
    result.length = i;
    return result;
}
BigInt BigInt::operator+(int val) const {   
    BigInt temp(val);
    return *this + temp; 
}
BigInt BigInt::operator+=(const BigInt& rhs) {
    BigInt temp = *this + rhs;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return *this;
}
BigInt BigInt::operator-=(const BigInt& rhs) {
    BigInt temp = *this - rhs;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return *this;
}
BigInt BigInt::operator*=(const BigInt& rhs) {
    BigInt temp = *this * rhs;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return *this;
}
BigInt& BigInt::operator++() {
    BigInt temp = *this + 1;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return *this;
}
BigInt BigInt::operator++(int) {
    BigInt oldState(*this);
    BigInt temp = *this + 1;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return oldState;
}
BigInt& BigInt::operator--() {
    BigInt temp = *this - 1;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return *this;
}
BigInt BigInt::operator--(int) {
    BigInt oldState(*this);
    BigInt temp = *this - 1;
    delete[] digits;
    length = temp.length;
    neg = temp.neg;
    digits = new int[length];
    for (int i = 0; i < length; i++) {
        digits[i] = temp.digits[i];
    }
    return oldState;
}
BigInt::operator string() {
    string result = "";
    if (neg && (length > 1 || digits[0] != 0)) {
        result += "-";
    }
    for (int i = length - 1; i >= 0; i--) {
        result += (char)(digits[i] + '0');
    }
    return result;
}

BigInt::operator int() {
    return length;
}
ostream& operator<<(ostream& output, const BigInt& val) {
    if (val.neg && (val.length > 1 || val.digits[0] != 0)) {
        output << "-";
    }
    for (int i = val.length - 1; i >= 0; i--) {
        output << val.digits[i];
    }
    return output;
}
istream& operator>>(istream& input, BigInt& val) {
    string text;
    input >> text;
    BigInt temp(text);
    delete[] val.digits;
    val.length = temp.length;
    val.neg = temp.neg;
    val.digits = new int[val.length];
    for (int i = 0; i < val.length; i++) {
        val.digits[i] = temp.digits[i];
    }
    return input;
}



























