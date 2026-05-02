#include <iostream>
#include <string>
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

        cout << "\nOrder Added Successfully!\n";
    }

    void dispatchOrder()
    {
        if (pSize > 0)
        {
            // check if there are priority order available
            cout << "\nDelivered (Priority): " << priority[0].name << endl;
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
            cout << "\nDelivered (Normal): " << normal[front].name << endl;

            front++;
        }
        else
        {
            cout << "\nNo orders.\n";
        }
    }

    void undo() {
        if (top == -1) {
            cout <<"\nNothing to undo.\n";
            return;
        }

        Order o = stack[top--];
        cout << "\nUndo Order ID: " << o.id << endl;

        // Remove from priority queue
        for (int i = 0; i < pSize; i++) {
            if (priority[i].id == o.id) {
                for (int j = i; j < pSize - 1; j++) {
                    priority[j] = priority[j + 1];
                }
                pSize--;
                cout << "Removed from Priority Queue.\n";
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
                cout << "Removed from Normal Queue.\n";
                return;
            }
        }
    }

    void display() {
        cout << "\n=========== PRIORITY ORDERS ===========\n";
        if (pSize == 0) cout << "No priority orders.\n";

        for (int i = 0; i < pSize; i++) {
            cout << "[" << priority[i].id << "] "
                 << priority[i].name << " (" << priority[i].hr << " hrs)\n";
        }

        cout << "\n=========== NORMAL ORDERS =============\n";
        if (front > rear) cout << "No normal orders.\n";

        for (int i = front; i <= rear; i++) {
            cout << "[" << normal[i].id << "] "
                 << normal[i].name << " (" << normal[i].hr << " hrs)\n";
        }

        cout << "=======================================\n";
    }

    void search()
    {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        // Find order ID in Priority Queue first
        for (int i = 0; i < pSize; i++)
        {
            if (priority[i].id == id)
            {
                cout << "\nFound in PRIORITY QUEUE!\n";
                return;
            }
        }

        // If not found, find order ID in Normal Queue
        for (int i = front; i <= rear; i++)
        {
            if (normal[i].id == id)
            {
                cout << "\nFound in NORMAL QUEUE!\n";
                return;
            }
        }
        // If no order ID found
        cout << "\nOrder not found.\n";
    }
};

int main()
{
    FoodDeliverySystem f; // Create an object of the FoodDeliverySystem Class
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "  FOOD DELIVERY MANAGEMENT SYSTEM MENU\n";
        cout << "========================================\n";

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
    } while (choice != 6); // loop continues until user chooses Exit

    return 0;
}
