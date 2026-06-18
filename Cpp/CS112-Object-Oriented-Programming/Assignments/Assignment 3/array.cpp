#include "array.h"
#include<iostream>
using namespace std;

Array::Array(){
	data = NULL;
	size = 0;
}
Array::Array(int size){
	this->size = size;
	data = new int[size];
	for(int i = 0; i<size; i++){
		data[i] = 0;
	}
}
Array::Array(int *arr, int size){
	this->size = size;
	data = new int[size];
	for(int i=0; i<size; i++){
		data[i] = arr[i];
	}
}
Array::Array(const Array& obj){
	this->size = obj.size;
	data = new int[this->size];
	for(int i=0; i<this->size; i++){
		data[i] = obj.data[i];
	}
}
int& Array::operator[](int i){
	if(i<0||i>=size){
		cout<<"Error! Invalid Size of Array!"<<endl;
	}
	return data[i];
}
int& Array::operator[](int i)const{
	if(i<0||i>=size){
		cout<<"Error! Invalid Size of Array!"<<endl;
	}
	return data[i];
}
const Array& Array::operator=(const Array& obj){
	if(this == &obj) return *this;
	delete[] data;
	this->size = obj.size;
	data = new int[this->size];
	for(int i=0;i<this->size;i++){
		data[i] = obj.data[i];
	}
	return *this;
}
Array Array::operator+(const Array& obj){
	Array temp(obj.size);
	for(int i=0; i<obj.size; i++){
		temp.data[i] = this->data[i] + obj.data[i];
	}
	return temp;
}
Array Array::operator-(const Array& obj){
	Array temp(obj.size);
	for(int i=0; i<obj.size; i++){
		temp.data[i] = this->data[i] - obj.data[i];
	}
	return temp;
}
void Array::operator+=(const Array& obj){
	for(int i=0; i<size; i++){
		this->data[i] += obj.data[i];
	}
}
void Array::operator-=(const Array& obj){
	for(int i=0; i<size; i++){
		this->data[i] -= obj.data[i];
	}
}
Array Array::operator++(){
	for(int i=0; i<size; i++){
		this->data[i] += 1;
	}
	return *this;
}
Array Array::operator++(int){
	Array temp(*this);
	for(int i=0;i<size; i++){
		this->data[i] += 1;
	}
	return temp;
}
Array& Array::operator--(int){
	Array* result= new Array(size);
	for(int i=0; i<size; i++){
		result->data[i] = data[i];
		data[i] = data[i] - 1;
	}
	return *result;
}
bool Array::operator==(const Array& obj)const{
	if(this->size != obj.size) return false;
	for(int i=0; i<size; i++){
		if(this->data[i] != obj.data[i]) return false;
	}
	return true;
}
bool Array::operator!(){
	if(size == 0) return true;
	else return false;
}
int Array::operator()(int idx, int val){
	if(idx<0||idx>=size) return -1;
	int *temp = new int[size - 1];
	for(int i=0; i<idx; i++){
		temp[i] = data[i];
	}
	for(int i=idx+1;i<size;i++){
		temp[i-1] = data[i];
	}
	delete[] data;
	data = temp;
	size--;
	return 1;
}
Array::~Array(){
	delete[] data;
}
