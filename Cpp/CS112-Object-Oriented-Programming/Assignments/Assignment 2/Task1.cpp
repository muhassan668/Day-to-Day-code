#include<iostream>
#include "ZooChain.h"
using namespace std;

void ZooChain::add_Cage(char* name, int cageNumber){
	
	ZooCage* newCage = new ZooCage;
	newCage->cageNumber = cageNumber;
	newCage->link = NULL;
	
	int len = 0;
	while(name[len] != '\0'){
		len++;
	}
	newCage->name = new char[len + 1];
	
	for(int i=0; i<len; i++){
		newCage->name[i] = name[i];
	}
	newCage->name[len] = '\0';
	
	if(start == NULL){
		start = newCage;
	}else{
		ZooCage* temp = start;
		while(temp->link != NULL){
			temp = temp->link;
		}
		temp->link = newCage;
	}
}

void ZooChain::print_Chain(){
	
	ZooCage* temp = start;
	if(temp == NULL){
		cout<<"The zoo is enpty! Nothing to print."<<endl;
		return;
	}
	while(temp != NULL){
		cout<<"Cage Number: "<<temp->cageNumber<<", Animal: "<<temp->name<<endl;
		temp = temp->link;
	}
}

void ZooChain::delete_Chain(int cageNumber){
	
	ZooCage* temp = start;
	if(temp == NULL){
		cout<<"The zoo is empty! Nothing to print."<<endl;
		return;
	}
	if(temp->cageNumber == cageNumber){
		start = temp->link;
		delete[] temp->name;
		delete temp;
		return;
	}
	ZooCage* cur = start;
	ZooCage* pre = NULL;
	while(cur != NULL && cur->cageNumber != cageNumber){
		pre = cur;
		cur = cur->link;	
	}
	if(cur == NULL) return;
	pre->link = cur->link;
	
	delete[] cur->name;
	delete cur;
	
}

void ZooChain::update_name_at_cageNumber(int cageNumber, char* name){
	
	ZooCage* temp = start;
	while( temp != NULL){
		if(temp->cageNumber == cageNumber){
			delete[] temp->name;
			int len = 0;
			while(name[len] != '\0'){
				len++;
			}
			temp->name = new char[len + 1];
			for(int i=0; i<len; i++){
				temp->name[i] = name[i];
			}
			temp->name[len] = '\0';
			return;
		}
		temp = temp->link;
	}
}

void ZooChain::remove_Duplicate(){
	
	if( start == NULL || start->link == NULL){
		return;
	}
	ZooCage* anchor = start;
	while(anchor != NULL && anchor->link != NULL){
		ZooCage* runner = anchor;
		while(runner->link != NULL){
			if(anchor->cageNumber == runner->link->cageNumber){
				ZooCage* duplicate = runner->link;
				runner->link = duplicate->link;
				delete[] duplicate->name;
				delete duplicate;
				
			}else{
				runner = runner->link;
			}
		}
		anchor = anchor->link;
	}
}

void ZooChain::Sort_Chain(){
	
	if(start == NULL || start->link == NULL){
		return;
	}
	bool swapped;
	ZooCage* lptr = NULL;
	do{	
		swapped = false;
		ZooCage* ptr1 = start;
		
		while(ptr1->link != lptr){
			if(ptr1->cageNumber > ptr1->link->cageNumber){
				int tempNum;
				char* tempName;
				tempNum = ptr1->cageNumber;
				ptr1->cageNumber = ptr1->link->cageNumber;
				ptr1->link->cageNumber = tempNum;
				tempName = ptr1->name;
				ptr1->name = ptr1->link->name;
				ptr1->link->name = tempName;
				swapped = true;
			}
			ptr1 = ptr1->link;	
		}
		lptr = ptr1;
	}while(swapped);
}

ZooChain::~ZooChain(){
	ZooCage* cur = start;
	while(cur!= NULL){
		ZooCage* nextNode = cur->link;
		delete[] cur->name;
		delete cur;
		cur = nextNode;
	}
}

