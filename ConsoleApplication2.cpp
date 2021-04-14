
/*Implemented a Shopping cart class and Console program that has the following features:
    1. add a single item to the cart
    2. add several items (possibly different kinds) at a time to the shopping cart
    3. display the contents of the cart on the computer screen
    4. write the contents of the shopping cart to a file
    5. summarize the price of the shopping cart.
*/

#include <iostream>
#include <fstream>
#include<vector>
using namespace std;
struct Item {
    int var;
    string name;
    double qn;
};
class ShoppingCart {
private:
   vector<Item> cart;
public:
    void show() const ;
    void add(const int i, const string name, const double qn) ;
    double totalPrice() const;
    void WritetoFile() const;
};

void ShoppingCart::add(const int i, const string name, const double qn)
{
    cart.push_back({i,name,qn});
    
}
void ShoppingCart::show() const {
    
    cout << "Display of Cart content" << '\n';
    cout << "Name" << '\t' << "Price" << '\t' << "Quantity" << '\n';    
    
    for (const auto& it : cart)
        cout << it.name<<'\t' << it.var << '\t' << it.qn<< '\n';
    
}
double ShoppingCart::totalPrice() const
{   // function calculates the total price added to the cart
    double total = 0;

    for (const auto& elem : cart) //repeat until end of Cart
    {


        total += (elem.qn * elem.var); //calling price and quantity to calculate total price
    }
    return total;
}
void ShoppingCart::WritetoFile() const
{
    // writes the items added to the shopping cart to the cart.txt file 
    ofstream oStream;// writes in the text (Registration)




    oStream.open("cart.txt");
    oStream << "Display of Cart content" << '\n';
    oStream << "Name" << '\t' << "Quantity" << '\t' << "Price" << '\n';
    for (const auto&  elem : cart)
    {
        oStream << elem.name << "\t " << elem.qn << "\t " << elem.var << "\n";
    }
    oStream.close();
    cout << "Cart content has been added to cart.txt" << '\n';
}

static void help()
{
    cout << "Shopping cart application"<<'\n';

}
static bool readMore() {
    //function to ask more items  to add the cart
    char choice = 'y';
    bool moreItems = true;
    cout << "Would you like to add item to cart(y/n)?";
    cin >> choice;

    if (choice == 'y')
    {
        moreItems = true;
    }
    else
    {
        moreItems = false;
    }
    return moreItems;
}
int main()
{
    ShoppingCart obj;
    help();
    if(readMore()==true)
    { 
        do 
        {
            cout << "enter name: \t"; string name; cin >> name;
            cout << "enter price: \t"; int price; cin >> price;
            cout << "enter quantity: \t"; double qn; cin >> qn;
        
        
         obj.add(price,name,qn);
        } while (true==readMore());
    }
    
    obj.show();
    obj.WritetoFile();
    double diff = obj.totalPrice();
    cout << "Total price is : " << diff << '\n';
    
}

 