#include <iostream>
#include "String.h"
using namespace std;

String::String(){
	
	ssize = 0;
	data = NULL;
	
}
String::String(char* str){
	int len = 0;
	while(str[len] != '\0'){
		len++;
	}
	ssize = len;
	data = new char[ssize + 1];
	for(int i=0; i<len; i++){
		data[i] = str[i];
	}
	data[len] = '\0';
	
}
char* String::getdata(){
	return data;
}
int String::length(){
	return ssize;
}
char String::getChar(int i){
	return data[i];
}
String::String(const String& original){
	
	ssize = original.ssize;
	data = new char[ssize + 1];
	for(int i=0; i<ssize; i++){
		data[i] = original.data[i];
	}
	data[ssize] = '\0';
}
String& String::assign_string(const String& original){
	
	if(data != NULL){
		delete[] data;
	}
	ssize = original.ssize;
	data = new char[ssize + 1];
	for(int i=0; i<ssize; i++){
		data[i] = original.data[i];
	}
	data[ssize] = '\0';
	return *this;
}
String::~String(){
	delete[] data;
}
bool String::isEmpty(){
	if(ssize == 0) return true;
	else return false;
	
}
bool String::isEqual(const String& other) const{
	
	if(ssize != other.ssize) return false;
	for(int i=0; i<ssize; i++){
		if(data[i] != other.data[i]) return false;
	}
	return true;
}
bool String::isEqual(char* other)const {
	
	int len = 0;
	while(other[len] != '\0'){
		len++;
	}
	if(ssize != len) return false;
	for(int i=0; i<ssize; i++){
		if(data[i] != other[i]) return false;
	}
	return true;
}
int String::index_at(char c)const{
	
	int index = 0; 
	for(int i=0; i<ssize; i++){
		if(data[i] == c){
			return i;
		}
	}
	return -1;
}
int String::index_at(const String& str)const {
	
	if(str.ssize > ssize) return -1;
	
	for(int i=0; i<=ssize - str.ssize; i++){
		bool match = true;
		for(int j=0; j<str.ssize; j++){
			if(data[i+j] != str.data[j]){
				match = false;
				break;
			}
		}
		if(match == true){
			return i;
		}
	}
	return -1;
}
int String::index_at(char* other) const{
	
	int len = 0;
	while(other[len] != '\0'){
		len++;
	}
	for(int i=0; i<=ssize - len; i++){
		bool match = true;
		for(int j=0; j<len; j++){
			if(data[i+j] != other[j]){
				match = false;
				break;
			}
		}
		if(match == true){
			return i;
		}
	}
	return -1;	
}
String String::append_string(const String &str){
	
	int newSize = ssize + str.ssize;
	char* temp = new char[newSize + 1];
	for(int i=0; i<ssize; i++){
		temp[i] = data[i];
	}
	for(int i=0; i<str.ssize; i++){
		temp[ssize + i] = str.data[i]; 
	}
	temp[newSize] = '\0';
	
	String combinedString(temp);
	delete[]temp;
	return combinedString;	
} 
String String::append_string(char *&str){
	
	int len = 0;
	while( str[len] != '\0'){
		len++;
	}
	int newSize = ssize + len;
	char* temp = new char[newSize + 1];
	for(int i=0; i<ssize; i++){
		temp[i] = data[i];
	}
	for(int i=0; i<len; i++){
		temp[ssize + i] = str[i]; 
	}
	temp[newSize] = '\0';	
	String combinedString(temp);
	delete[]temp;
	return combinedString;		
}
String String::append_string(const char &c){
	
	int newSize = ssize + 1;
	char* temp = new char[newSize + 1];
	for(int i=0; i<ssize; i++){
		temp[i] = data[i];
	}
	temp[ssize] = c;
	temp[newSize] = '\0';
	
	String combinedString(temp);
	delete[] temp;
	return combinedString;
}
String String::remove_string(const char &c){
	
	int newSize = 0;
	int index = 0;
	for(int i=0; i<ssize; i++){
		if(data[i] != c){
			newSize++;
		}
	}
	char *temp = new char[newSize + 1];
	for(int i=0; i<ssize; i++){
		if(data[i] != c){
			temp[index] = data[i];
			index++;
		}
	}
	temp[newSize] = '\0';
	String newString(temp);
	delete[] temp;
	return newString;
}
String String::remove_string(const String &substr){
	
	String result(*this); 
	int idx = result.index_at(substr);
	while(idx != -1) {
		
		int newLen = result.ssize - substr.ssize;
		char* temp = new char[newLen + 1];
		for(int i = 0; i < idx; i++){
			temp[i] = result.data[i];
		}
		for(int i = idx + substr.ssize; i < result.ssize; i++){
			temp[i - substr.ssize] = result.data[i];
		}
		temp[newLen] = '\0';
		
		delete[] result.data;
		result.data = temp;
		result.ssize = newLen;
		idx = result.index_at(substr);
	}
	return result;
}
String String::remove_string(const char*& substr) {
    
    int len = 0;
    while (substr[len] != '\0') {
        len++;
    }
    String result(*this);
    int idx = result.index_at((char*)substr);
    while (idx != -1) {
        int newLen = result.ssize - len;
        char* temp = new char[newLen + 1];
        for (int i = 0; i < idx; i++) {
            temp[i] = result.data[i];
        }
        for (int i = idx + len; i < result.ssize; i++) {
            temp[i - len] = result.data[i]; 
        }
        temp[newLen] = '\0';
        
        delete[] result.data;
        result.data = temp;
        result.ssize = newLen;
        
        idx = result.index_at((char*)substr);
    }    
    return result;
}
























