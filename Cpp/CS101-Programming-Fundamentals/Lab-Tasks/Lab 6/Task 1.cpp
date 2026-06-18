#include<iostream>
using namespace std;

void borrowBook(int &books , int quantity = 1){
    books = books - quantity;
}
void returnBook(int &books , int quantity = 1){
    books = books + quantity;

}
void showBooks(int books){
    cout<<"currently available books:"<<books;
}
int main(){
    int initial , borrowed , returned;
    cout<<"Initial books:";
    cin>>initial;
    while (initial<0){
        cout<<"error please enter a positive integer"<<endl<<"initial books:";
        cin>>initial;
    }

    cout<<"Borrowed books:";
    cin>>borrowed;
    
    do{
    if(borrowed<0){
    cout<<"error please enter a positive integer"<<endl<<"borrowed books=";
    cin>>borrowed;
    }
    if(borrowed>initial){
        cout<<"error borrowed books cannot be greater than initial"<<endl<<"Borrowed books=";
        cin>>borrowed;
    }
    }while(borrowed < 0 || borrowed > initial);

    cout<<"Returned books:";
    cin>>returned;

    do{
    if(returned<0){
        cout<<"please enter positive number"<<endl<<"Returned books=";
        cin>>returned;
    }
    if(returned>borrowed){
        cout<<"error! returned books cannot be greater than borrowed books"<<endl<<"Returned books=";
        cin>>returned;
    }
    }while(returned<0 || returned > borrowed);


    borrowBook(initial , borrowed);
    returnBook(initial , returned);
    showBooks (initial);

    return 0;
}
