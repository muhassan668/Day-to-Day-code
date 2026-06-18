#include <iostream>
using namespace std;
 
class BookPrice{
    private:
        int rupees;
        int paisa;
    public:
        BookPrice(int rs, int ps){          // constructor
            rupees = rs;
            paisa = ps;            
        }
        bool operator<(BookPrice &price){   // overloading the < operator
            if(rupees * 100 + paisa < price.rupees * 100 + price.paisa){        // converting rupees into paisa and then comparing
                return false;
            }
            return true;
        }
        void display(){
            cout<<rupees<<" Rupees and "<<paisa<<" Paisa."<<endl;
        }
};
int main(){
    BookPrice book1(200,20);
    BookPrice book2(200,121);
 
    if(book1 < book2){
        cout<<"Book 2 is cheaper: ";
        book2.display();
    }else{
        cout<<"Book 1 is cheaper: ";
        book1.display();
    }
    return 0;
}
