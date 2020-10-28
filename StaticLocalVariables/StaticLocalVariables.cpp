#include <iostream>
int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

void newItem()
{
    std::cout << "Please insert new number:";
    int x{};
    std::cin >> x;
    std::cout << "The new generated ID for inserted number " << x << " is " << generateID() << "\n";

}


int main()
{
    std::cout << "Hello World!\n";
    newItem();
    newItem();
    newItem();

    return 0;
}
