#include <iostream>
#include "Item.h"
#include "Bread.h"
#include "Egg.h"
#include "Socks.h"
#include "Pens.h"
#include "Cart.h"

using namespace std;

int main() {
    // example of non sale item.
    Bread p1(12, 3);
    cout << p1 << endl; 

    // example of sale item
    Egg p2(15, 1, true);

    // example of sale item with gift card
    Socks p3(20, 2, true, true);
    
    Cart c1;
    c1 += p1; //add bread to cart
    c1 += p1;
    c1 += p2; //add eggs to cart
    c1 += p3; //add socks to cart
    cout << c1 << endl;

    c1 = c1 - p1; // Delete all the unit of type bread
    cout << c1 << endl;

    Cart c2;
    c2 = c1 + p2; // Add item of type eggs
    cout << c2 << endl;

    // Delete all the units of item type food from the cart.
    c2 -= p2;
    cout << c2;
    
    return 0;
}
