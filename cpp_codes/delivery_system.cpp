#include <iostream>
#include <string>
using namespace std;

#define MAX 100

//TEXT COLORS
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"


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
    void addOrder()
    {
        Order o; // Create a new Order Object

        cout << "Enter ID: ";
        cin >> o.id;
        cin.ignore(); // Clear Input buffer

        cout << "Enter Name: ";
        getline(cin, o.name);

        cout << "Enter Hours: ";
        cin >> o.hr; // get number of hours

        // Check if order should go to Priority Queue
        if (o.hr <= 5)
        {
            priority[pSize++] = o; // Add order to priority queue

            // Sort priority queue based on shortest hours (ascending)
            for (int i = 0; i < pSize - 1; i++)
            {
                for (int j = i + 1; j < pSize; j++)
                {
                    if (priority[j].hr < priority[i].hr)
                    {
                        swap(priority[i], priority[j]); // Swap if smaller value found
                    }
                }
            }
        }
        // if not priority, add to Normal Queue

        else
        {
            normal[++rear] = o; // insert at the end of the normal queue
        }

        // Push order into stack (for tracking or undo feature)
        stack[++top] = o;

        cout << GREEN << "\nOrder Added Successfully!\n" << RESET;
    }

    void dispatchOrder()
    {
        if (pSize > 0)
        {
            // check if there are priority order available
            cout << RED << "\nDelivered (Priority): " << priority[0].name << RESET << endl;
            // shift all remaining priority orders forward in the array
            for (int i = 0; i < pSize - 1; i++)
            {
                priority[i] = priority[i + 1];
            }

            // decrease size of priority queue
            pSize--;
        }
        // if no priority orders, check normal queue
        else if (front <= rear)
        {
            // deliver the order at front of normal queue
            cout << RED << "\nDelivered (Normal): " << normal[front].name << RESET << endl;

            front++;
        }
        else
        {
            cout << RED << "\nNo orders.\n" << RESET;
        }
    }

    void undo() {
        if (top == -1) {
            cout << BLUE << "\nNothing to undo.\n" << RESET;
            return;
        }

        Order o = stack[top--];
        cout << BLUE << "\nUndo Order ID: " << o.id << RESET << endl;

        // Remove from priority queue
        for (int i = 0; i < pSize; i++) {
            if (priority[i].id == o.id) {
                for (int j = i; j < pSize - 1; j++) {
                    priority[j] = priority[j + 1];
                }
                pSize--;
                cout << BLUE << "Removed from Priority Queue.\n" << RESET;
                return;
            }
        }

        // Remove from normal queue
        for (int i = front; i <= rear; i++) {
            if (normal[i].id == o.id) {
                for (int j = i; j < rear; j++) {
                    normal[j] = normal[j + 1];
                }
                rear--;
                cout << BLUE << "Removed from Normal Queue.\n" << RESET;
                return;
            }
        }
    }

    void display() {
        cout << "\n=========== PRIORITY ORDERS ===========\n";
        if (pSize == 0) cout << RED << "No priority orders.\n" << RESET;

        for (int i = 0; i < pSize; i++) {
            cout << "[" << priority[i].id << "] "
                 << priority[i].name << " (" << priority[i].hr << " hrs)\n";
        }

        cout << "\n=========== NORMAL ORDERS =============\n";
        if (front > rear) cout << RED << "No normal orders.\n" << RESET;

        for (int i = front; i <= rear; i++) {
            cout << "[" << normal[i].id << "] "
                 << normal[i].name << " (" << normal[i].hr << " hrs)\n";
        }

        cout << "=======================================\n";
    }

    bool searchPriorityOrders(int index, int target, Order& found) {
        if (index >= pSize) {
            return false;
        }
        if (priority[index].id == target) {
            found = priority[index];
            return true;
        }
        return searchPriorityOrders(index + 1, target, found);
    }

    bool searchNormalOrders(int index, int target, Order& found) {
        if (index > rear) {
            return false;
        }
        if (normal[index].id == target) {
            found = normal[index];
            return true;
        }
        return searchNormalOrders(index + 1, target, found);
    }

    void search() {
        int target;
        cout << "Enter Order ID: ";
        cin >> target;

        Order found;
        
        if (searchPriorityOrders(0, target, found)) {
            cout << GREEN << "Order FOUND in PRIORITY QUEUE!" << RESET << endl;
            cout << "ID: " << found.id
                << " | Name: " << found.name
                << " | Hours: " << found.hr << endl;
        }

        else if (searchNormalOrders(front, target, found)) {
            cout << GREEN << "Order FOUND in NORMAL QUEUE!" << RESET << endl;
                cout << "ID: " << found.id
                << " | Name: " << found.name
                << " | Hours: " << found.hr << endl;
        }
        else {
            cout << RED << "Order not found." << RESET << endl;
        }
    }
};

int main()
{
    FoodDeliverySystem f; // Create an object of the FoodDeliverySystem Class
    int choice;

    do
    {
        cout << GREEN << "\n========================================\n" << RESET;
        cout << GREEN << "  FOOD DELIVERY MANAGEMENT SYSTEM MENU\n" << RESET;
        cout << GREEN << "========================================\n" << RESET;

        cout << GREEN << " [1] Add Order\n" << RESET;
        cout << GREEN << " [2] Dispatch Order\n" << RESET;
        cout << GREEN << " [3] Undo Last Order\n" << RESET;
        cout << GREEN << " [4] Display Orders\n" << RESET;
        cout << GREEN << " [5] Search Order\n" << RESET;
        cout << RED << " [6] Exit\n" << RESET;
        cout << GREEN << "===========================================\n" << RESET;
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
            cout << RED << "\nExiting system...\n" << RESET;
            break;
        default:
            cout << RED << "\nInvalid Choice!\n" << RESET; // Error message for wrong input
        }
    } while (choice != 6); // loop continues until user chooses Exit

    return 0;
}
