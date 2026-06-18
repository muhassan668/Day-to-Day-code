#include<iostream>
using namespace std;
 
struct IssueRecord{                 // struct
    int itemID;
    int userID;
};
class LibraryItem{                  // base class
    protected:       
        int item_id;
        string title;
        bool availability;
    public:
        LibraryItem(int id, string t){
            item_id = id;
            title = t;
            availability = true;
        }
        virtual void displayDetails(){      // virtual function
            cout<<"Item Id: "<<item_id<<",  Title: "<<title<<endl;
            cout<<"Availability: "<<(availability ? "Yes" : "No")<<endl;
        }
        int getId(){
            return item_id;
        }
        bool is_available(){
            return availability;
        }
        bool set_availability(bool status){
            availability = status;
        }
};
class Book: public LibraryItem{     // derived class of library item
    protected:    
        string Author;
        int pages;
    public:
        Book(string a, int p, int id, string t): LibraryItem(id,t){
            Author = a;
            pages = p;
        }
        void displayDetails(){
            cout<<"Author Name: "<<Author<<",  Total Pages: "<<pages<<endl;
        }
 
};
class Magazine: public LibraryItem{  // derived class of library item
    protected:
        int issue_no;
    public:
        Magazine(int num,int id, string t): LibraryItem(id,t){
            issue_no = num;
        }
        void displayDetails(){
            cout<<"Issue Number: "<<issue_no<<endl;
        }
};
class EBook: public LibraryItem{      // derived class of library item
    protected:
        int file_size;
        string format;
    public:
        EBook(int f, int id, string t): LibraryItem(id,t){
            file_size = f;
        }
        void displayDetails(){
            cout<<"File Size: "<<file_size<<endl;
        }
};
class User{                // base class
    protected:
        int user_id;
        string name;
    public:
        User(int id, string naam){
            user_id = id;
            name = naam;
        }
        virtual void displayDetails(){
            cout<<"User Id: "<<user_id<<",  Name: "<<name<<endl;
        }
        int gerId(){
            return user_id;
        }
 
};
class Student: public User{     // derived class of user
    protected:
        string department;
    public:
        Student(string dep, int id, string naam): User(id, naam){
            department = dep;
        }
        void displayDetails(){
            cout<<"Department: "<<department<<endl;
        }
};
class Teacher: public User{     // derived class of user
    protected:
        string designation;
    public:
        Teacher(string des, int id, string naam): User(id,naam){
            designation = des;
        }
        void displayDetails(){
            cout<<"Designation: "<<designation<<endl;
        }
};
 
 
int main(){
    LibraryItem *items[100];
    User *users[100];
    IssueRecord records[100];
 
    int itemCount = 0, userCount = 0, recordCount = 0;
    int choice;
 
    do{
        cout << "\n1. Add Item\n2. Add User\n3. Display Items\n4. Issue Item\n5. Return Item\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1){
            int type, id;
            string title;
            cout << "1. Book 2. Magazine 3. EBook\n";
            cin >> type;
            cout << "Enter ID and Title: ";
            cin >> id >> title;
            if (type == 1){
                string author;
                int pages;
                cout << "Enter Author and Pages: ";
                cin >> author >> pages;
                items[itemCount++] = new Book(author, pages, id, title);
            }
            else if (type == 2){
                int issue;
                cout << "Enter Issue Number: ";
                cin >> issue;
                items[itemCount++] = new Magazine(issue, id, title);
            }
            else if (type == 3){
                int size;
                cout << "Enter File Size: ";
                cin >> size;
                items[itemCount++] = new EBook(size, id, title);
            }
        }
        else if (choice == 2){
            int type, id;
            string name;
            cout << "1. Student 2. Teacher\n";
            cin >> type;
            cout << "Enter ID and Name: ";
            cin >> id >> name;
            if (type == 1){
                string dept;
                cout << "Enter Department: ";
                cin >> dept;
                users[userCount++] = new Student(dept, id, name);
            }
            else{
                string des;
                cout << "Enter Designation: ";
                cin >> des;
                users[userCount++] = new Teacher(des, id, name);
            }
        }
        else if (choice == 3){
            for (int i = 0; i < itemCount; i++){
                items[i]->displayDetails();
                cout << "------------------\n";
            }
        }
        else if (choice == 4){
            int itemID, userID;
            cout << "Enter Item ID and User ID: ";
            cin >> itemID >> userID;
            for (int i = 0; i < itemCount; i++){
                if (items[i]->getId() == itemID && items[i]->is_available()){
                    items[i]->set_availability(false);
                    records[recordCount].itemID = itemID;
                    records[recordCount].userID = userID;
                    recordCount++;
                    cout << "Item Issued Successfully\n";
                    break;
                }
            }
        }
        else if (choice == 5){
            int itemID;
            cout << "Enter Item ID to return: ";
            cin >> itemID;
            for (int i = 0; i < itemCount; i++){
                if (items[i]->getId() == itemID){
                    items[i]->set_availability(true);
                    cout << "Item Returned Successfully\n";
                    break;
                }
            }
        }
    } while (choice != 6);
    return 0;
}
