#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100

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
    Order priority[MAX];
    int pSize = 0;

    // Normal Queue
    Order normal[MAX];
    int front = 0, rear = -1;

    // Stack (Undo)
    Order stack[MAX];
    int top = -1;

public:
    void addOrder(){}

        void dispatchOrder(){}

            void undo(){}

                void display(){}

                    void search(){}
};

int main(){
    FoodDeliverySystem f; // Create an object of the FoodDeliverySystem Class
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "      FOOD DELIVERY MANAGEMENT SYSTEM MENU\n           ";
        cout << "\n========================================\n";

        cout << " [1] Add Order\n";
        cout << " [2] Dispatch Order\n";
        cout << " [3] Undo Last Order\n";
        cout << " [4] Display Orders\n";
        cout << " [5] Search Order\n";
        cout << " [6] Exit\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            f.addOrder();
            break;
        case 2:
            f.dispatchOrder();
            break;
        case 3:
            f.undo();
            break;
        case 4:
            f.display();
            break;
        case 5:
            f.search();
            break;
        case 6:
            cout << "\nExiting system...\n";
            break;
        default:
            cout << "\nInvalid Choice!\n"; // Error message for wrong input
        }
    } while (choice != 6);// loop continues until user chooses Exit
        return (0);
}
