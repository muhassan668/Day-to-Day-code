#include <iostream>
using namespace std;
 
class Item{
    private:
        string itemName;
        int quantity;
    public:
        Item(){                         // default
            itemName = 'none';
            quantity = 0;
        }
        Item(string s, int q){          // perimeterized
            itemName = s;
            quantity = q;
        }
        Item operator=(Item &I){        // overloading the = operator
            itemName = I.itemName;
            quantity = I.quantity;
        }
        bool operator>=(Item &I){       // overloading the >= operator
            return quantity >= I.quantity ;
        }
        void display(){
            cout<<itemName<<" has quantity: "<<quantity<<endl;
        }
};
int main(){
    Item item1("Laptop",10);
    Item item2("Mobile",5);
 
    Item item3;
    item3 = item1;
    cout<<"Assigning item 1 to item 3"<<endl;
    item3.display();
 
    cout<<"Comparing."<<endl;
    if(item1>=item2){
        cout<<"More Laptops"<<endl;
    }else{
        cout<<"More Mobiles"<<endl;
    }
    return 0;
}
