#include <iostream>
#include <iomanip>
using namespace std;

struct Order
{
    int id;
    string name;
    int hr;
};

class FoodDeliverySystem
{
private:
    // Priority Queue

    // Normal Queue

    // Stack (Undo)

public:
    void addOrder()

        void dispatchOrder()

            void undo()

                void display()

                    void search()
}

int
main()
{

    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "      FOOD DELIVERY SYSTEM MENU\n           ";
        cout << "\n========================================\n";

        cout << " [1] Add Order\n";
        cout << " [2] Dispatch Order\n";
        cout << " [3] Undo Last Order\n";
        cout << " [4] Display Orders\n";
        cout << " [5] Search Order\n";
        cout << " [6] Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin << choice;
    }
    return 0;
}
