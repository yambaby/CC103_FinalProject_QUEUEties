<h1 align = "center"> ⋆˚🚚⋆˚ DeliverEase: Food Delivery Management System ⋆˚🚚⋆˚ </h1>
<h2 align = center> by: ˚.📦🎀༘⋆ Queueties ˚.📦🎀༘⋆ </h2>

## 🧩 Problem Description

### ❓ What problem are you solving?
In real-world food delivery services, managing multiple customer orders at the same time is very important. Without a proper and efficient system, restaurants may experience the following problems:

- ⏱️ Delayed deliveries due to poor order prioritization  
- 📋 Orders are not organized properly  
- 🔄 No easy way to undo incorrect orders  
- 🔍 Difficulty in tracking and searching orders  

### 💡 Proposed Solution
This system uses data structures such as **Queue, Priority Queue, and Stack** to efficiently organize and manage food delivery orders. It prioritizes urgent deliveries, maintains proper order flow, and provides an undo feature for correcting mistakes.

The system ensures:
- ⚡ Faster processing of urgent orders  
- 📋 Organized handling of normal orders  
- ↩️ Undo functionality for error correction  
- 🔍 Easy searching and clear display of orders 

## 🧱 Data Structures Used
### 1️. Priority Queue
#### - ❓ What it is:
  - A special type of queue where elements are processed based on priority instead of their arrival order.
#### - 🤔 Why used:
  - Orders with short delivery ```time ≤ 5 hours``` are treated as urgent and are processed first to ensure faster delivery.
### 2️. Queue
#### - ❓ What it is:
  - A linear **First-In, First-Out (FIFO)** data structure where the first element added is the first one to be removed.
#### - 🤔 Why used:
  - Normal orders ```(> 5 hours)``` are processed in the exact order they were received, ensuring fair and organized handling of non-urgent deliveries.
### 3️. Stack
#### - ❓ What it is:
- A **Last-In, First-Out (LIFO)** data structure where the last element added is the first to be removed. 
#### - 🤔 Why used:
- Enables Undo functionality, allowing the system to remove the most recently added order.
### 4️. Array
#### - ❓ What it is:
- A fixed-size collection of elements stored in contiguous memory. 
#### - 🤔 Why used:
- Used to implement **Queue, Stack, and Priority Queue** due to simplicity fast access, and efficient handling of data in this system.

## ⚙️ Algorithm Explanation

### 📝 Step-by-Step Logic

## 📦 Order Structure

```cpp
struct Order {
    int id;
    string name;
    int hr;
};

```

The ```Order``` structure stores the details of each order:

```id``` → Unique order number
```name``` → Customer name
```hr (hours)``` → Delivery time

📌 If ```hr ≤ 5``` → **Priority Order**
📌 If ```hr > 5``` → **Normal Order**


### ➕ ```addOrder()```

```cpp
void addOrder() {
        Order o;

        cout << "Enter ID: ";
        cin >> o.id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, o.name);

        cout << "Enter Hours: ";
        cin >> o.hr;

        // Priority Queue
        if (o.hr <= 5) {
            priority[pSize++] = o;

            // Sort by shortest time
            for (int i = 0; i < pSize - 1; i++) {
                for (int j = i + 1; j < pSize; j++) {
                    if (priority[j].hr < priority[i].hr) {
                        swap(priority[i], priority[j]);
                    }
                }
            }
        }
        // Normal Queue
        else {
            normal[++rear] = o;
        }

        // Push to stack
        stack[++top] = o;

        cout << GREEN << "\nOrder Added Successfully!\n" << RESET;
    }

```
- Input order details ```(ID, Name, Hours)```  
- **If** ```hours ≤ 5:```  
  - Add to **Priority Queue** array  
  - Insert then sort Priority Queue using nested loops based on ```hr``` (shortest time first)  
- **Else**:  
  - Add order to **Normal Queue** (FIFO using rear++)  
  - Push order to **Stack** (for undo functionality)

### 🚚 ```Dispatch Order```

```cpp
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
```
- **If** Priority Queue is not empty ```(pSize > 0):```
   - Display and deliver the first element of Priority Queue ```(priority[0])```
   - Shift all remaining elements left
   - Decrease ```pSize```
- **Else if** Normal Queue is not empty ```(front <= rear)```:
   - Display and deliver the first element in Normal Queue ```(normal[front])```
   - Increment front
- **Else**:
   - Display ```"No orders"```  

### ↩️ ```Undo Order```
```cpp
 void undo() {
//check if stack is empty 
        if (top == -1) {
            cout <<"\nNothing to undo.\n";
            return;
        }
//get the last order from the stack to remove it
        Order o = stack[top--];
        cout << "\nUndo Order ID: " << o.id << endl;

        // Remove from priority queue
        for (int i = 0; i < pSize; i++) {
            if (priority[i].id == o.id) {
                //shift elements to the left to fill the gap
                for (int j = i; j < pSize - 1; j++) {
                    priority[j] = priority[j + 1];
                }
                pSize--; //reduce size of priority queue
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
```
- Pop last order from Stack ```(top--)```
- **Search the order ID in Priority Queue:**
  - If found, remove it by shifting elements left and decrease ```pSize```
- **Else search in Normal Queue:**
  - If found, remove it by shifting elements left and decrease ```rear```
- Display confirmation message for removal  

### 🔍 ```Search Order```
```cpp
bool searchPriorityOrders(int index, int target, Order& found) {
    
    // Base case: reached end of priority queue (not found)
    if (index >= pSize) {
        return false;
    }

    // If current order matches target ID
    if (priority[index].id == target) {
        found = priority[index]; // store the found order
        return true;
    }

    // Recursive call: check next index
    return searchPriorityOrders(index + 1, target, found);
}
```
- This function **recursively searches** the priority queue.
- It starts from ```index 0``` and checks each order one by one.
- If the order ```ID``` matches, it stores the result and returns ```true```.
- If it reaches the end without finding it, it returns ```false```.

```cpp
bool searchNormalOrders(int index, int target, Order& found) {
    
    // Base case: reached end of normal queue (not found)
    if (index > rear) {
        return false;
    }

    // If current order matches target ID
    if (normal[index].id == target) {
        found = normal[index]; // store the found order
        return true;
    }

    // Recursive call: check next element
    return searchNormalOrders(index + 1, target, found);
}
```
- Works the same way as the priority search.
- Starts from ```front``` and goes until ```rear```.
- Uses recursion to move through the queue.
- Returns ```true``` if found, otherwise ```false```.

```cpp
void search() {
    int target;

    // Ask user for Order ID
    cout << "Enter Order ID: ";
    cin >> target;

    Order found; // variable to store result

    // First, search in priority queue
    if (searchPriorityOrders(0, target, found)) {
        cout << GREEN << "Order FOUND in PRIORITY QUEUE!" << RESET << endl;
        cout << "ID: " << found.id
             << " | Name: " << found.name
             << " | Hours: " << found.hr << endl;
    }

    // If not found, search in normal queue
    else if (searchNormalOrders(front, target, found)) {
        cout << GREEN << "Order FOUND in NORMAL QUEUE!" << RESET << endl;
        cout << "ID: " << found.id
             << " | Name: " << found.name
             << " | Hours: " << found.hr << endl;
    }

    // If not found in both queues
    else {
        cout << RED << "Order not found." << RESET << endl;
    }
}
```
- This is the main search handler.
- Takes user input ```(Order ID)```.
- First checks the**priority queue** (higher importance).
- If not found, checks the **normal queue**.
- Displays:
- Order details if ```found```
- Error message if ```not found```

### 📊```Display Orders```
```cpp
 void display() {
        cout << "\n=========== PRIORITY ORDERS ===========\n";

        //check if no priority orders
        if (pSize == 0) cout << "No priority orders.\n";

       //display all orders
        for (int i = 0; i < pSize; i++) {
            cout << "[" << priority[i].id << "] "
                 << priority[i].name << " (" << priority[i].hr << " hrs)\n";
        }

        cout << "\n=========== NORMAL ORDERS =============\n";

        //check if normal queue is empty
        if (front > rear) cout << "No normal orders.\n";

        //display all normal orders
        for (int i = front; i <= rear; i++) {
            cout << "[" << normal[i].id << "] "
                 << normal[i].name << " (" << normal[i].hr << " hrs)\n";
        }

        cout << "=======================================\n";
    }
```
- Display all elements in Priority Queue ```(from 0 to pSize-1)```
- Display all elements in Normal Queue ```(from front to rear)```
- Show order ```ID```, ```name```, and ```hours``` for each  

### 🚪 ```Exit System```
- User selects option ```[6] Exit```
- Program executes case 6 and displays ```"Exiting system..."```
- Loop condition ```while(choice != 6)``` ends execution
- Program terminates safely   
  
## 🔁 Iterative vs Recursive Comparison
|Criteria|Iterative Approach|Recursive Approach|
|-----|----------|-----|
|⚡ Speed| Faster (no function call overhead)| Slightly slower (function call overhead)|
| 🧠 Memory Usage| Uses less memory| Uses more memory (call stack)|
| 📖 Readability| Easier to understand and implement| Can be complex for beginners|
| 🔧 Used in System| ✅ Used in add, dispatch, undo, display (loops)| ✅ Used in search function|

### Conclusion:
- The system primarily uses iteration for efficiency and control in managing queues and stack operations.
- Recursion is used specifically for searching, making the search logic cleaner and modular.
- Iteration is still more suitable for most operations such as searching.
- A hybrid approach (iteration + recursion) is used in this system.

## 🎨 Design Decisions

### ✅ Choices Made:
- Used fixed-size arrays ```(MAX = 100)``` for all data structures  
  Arrays are used to implement the **Priority Queue, Normal Queue, and Stack**, providing simple implementation and fast data access without dynamic memory.

- Implemented **Priority Queue** using manual sorting (nested loops)  
  Orders with ```hr ≤ 5``` are stored in the priority array and sorted using a nested loop comparison to ensure the shortest delivery time is always processed first.  

- Applied **FIFO** logic for Normal Queue using front and rear indices  
  Normal orders are processed in the order they arrive by incrementing rear during insertion and front during dispatch.  

- Used **Stack (LIFO)** with top pointer for Undo functionality  
  Each added order is pushed onto the stack, allowing the system to undo the most recent order using ```top--```.  

- Used array shifting for deletion operations  
  Elements are shifted left when removing orders (during dispatch or undo) to maintain the correct structure of the arrays.  

- Console-based interface with **ANSI** color codes  
  Colors **(RED, GREEN, BLUE)** are used to highlight system messages, improving readability and user experience.   

### ⚖️ Trade-offs:
- ❌ Fixed size limitation and lack of scalability
  The system can only store up to 100 orders due to static array allocation and cannot dynamically expand.

- ❌ Manual sorting is less efficient (O(n²))  
  The nested loop sorting used in the Priority Queue is slower compared to more advanced structures like heaps.  

- ❌ Deletion requires shifting elements 
  Removing elements from arrays requires shifting, which adds extra processing time.

- ✅ Simple and beginner-friendly implementation
  The use of arrays and basic logic makes the system easy to understand and suitable for learning data structures.  

- ✅ No dynamic memory complexity and predictable behavior 
  The use of static arrays avoids pointers and dynamic allocation, reducing the risk of memory errors while ensuring low memory overhead and stable performance.


## ˖᯽ Project Developers ᯽˖
|SR-Code|Name|Duties and Responsibilities|
|-----|----|---------------------------|
|25-00505|[Buendia, Liam Keiji](https://github.com/yambaby)| Main Programmer|
|25-05687|[Carandang, Mary Yvonne C.](https://github.com/maryyvonnecarandang-dev)|Documentation Lead|
|25-02469|[Lindo, Kristal Joy H.](https://github.com/Kristal29)|Documentation II|
|25-07065|[Pasamba, Carl Kendy](https://github.com/kendyow)| Main Programmer II|


## ‧₊˚ ┊ Acknowledgment
We sincerely express our gratitude to our instructor [Ms. Fatima Marie Agdon, MSCS](https://github.com/marieemoiselle) for the guidance, support, and valuable insights provided throughout the development of this project.

We also extend our appreciation to our classmates and peers for their cooperation, encouragement, and shared ideas, which contributed to the improvement of this system.

Lastly, we acknowledge the learning resources and materials that helped us strengthen our understanding of data structures and programming concepts used in this project.

![C++](https://img.shields.io/badge/Language-C++-blue)
![Status](https://img.shields.io/badge/Status-Completed-green)
