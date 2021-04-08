
/*Implemented a Shopping cart class and Console program that has the following features:
    1. add a single item to the cart
    2. add several items (possibly different kinds) at a time to the shopping cart
    3. display the contents of the cart on the computer screen
    4. write the contents of the shopping cart to a file
    5. summarize the price of the shopping cart.
*/
#include<iostream>
#include<fstream>
#include<vector>

struct Item {
    std::string name;
    int quantity;
    double price;
};

//template<class T>
class ShoppingCart {

public:
    std::vector <Item> Cart;

    double totalPrice() const;
    void Display() const;
    void WritetoFile() const;
};

void ShoppingCart::Display() const
{
    /* function display the items added to the cart in the console*/
    
    std::cout << "Display of Cart content" << '\n';
    std::cout << "Name" << '\t' << "Quantity" << '\t' << "Price" << '\n';

    for (const auto& elem : Cart)
    {
        std::cout << elem.name << "\t " << elem.quantity << "\t " << elem.price << "\n";
    }
}
void ShoppingCart::WritetoFile() const
{
    /* writes the items added to the shopping cart to the cart.txt file */
    std::ofstream oStream;// writes in the text (Registration)




    oStream.open("cart.txt");
    oStream << "Display of Cart content" << '\n';
    oStream << "Name" << '\t' << "Quantity" << '\t' << "Price" << '\n';
    for (const auto& elem : Cart)
    {
        oStream << elem.name << "\t " << elem.quantity << "\t " << elem.price << "\n";
    }
    oStream.close();
    std::cout << "Cart content has been added to cart.txt" << '\n';
}
double ShoppingCart::totalPrice() const
{   /* function calculates the total price added to the cart*/
    double total = 0;

    for (const auto& elem : Cart) //repeat until end of Cart
    {


        total += (elem.quantity * elem.price); //calling price and quantity to calculate total price
    }
    return total;
}


bool readMore() {
    /* function to ask more items  to add the cart*/
    char choice = 'y';
    bool moreItems = true;
    std::cout << "Would you like to add more items to cart(y/n)?";
    std::cin >> choice;

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

    std::cout << "Enter the item details:" << '\n';
    std::string nm;
    int qn;
    double pr;
    ShoppingCart sc1;

    do {
        std::cout << "Name:";
        std::cin >> nm;
        std::cout << "Quantity:";
        std::cin >> qn;
        std::cout << "price:";
        std::cin >> pr;

        sc1.Cart.push_back({ nm,qn,pr });
    } while (readMore() == true);

    sc1.Display();
    sc1.WritetoFile();
    double diff = sc1.totalPrice();
    std::cout << "Total price is : " << diff << '\n';

    return 0;



}