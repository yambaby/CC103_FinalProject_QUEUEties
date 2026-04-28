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
This system uses data structures such as Queue, Priority Queue, and Stack to efficiently organize and manage food delivery orders. It prioritizes urgent deliveries, maintains proper order flow, and provides an undo feature for correcting mistakes.

The system ensures:
- ⚡ Faster processing of urgent orders  
- 📋 Organized handling of normal orders  
- ↩️ Undo functionality for error correction  
- 🔍 Easy searching and clear display of orders 

## 🧱 Data Structures Used
### 1️. Priority Queue
#### - What it is:
- A special type of queue where elements are processed based on priority instead of their arrival order.
#### - Why used:
- Orders with short delivery time ≤ 5 hours are treated as urgent and are processed first to ensure faster delivery. 

## ⚙️ Algorithm Explanation

### 📝 Step-by-Step Logic

### ➕ Add Order
- Input order details (ID, Name, Hours)  
- If hours ≤ 5:  
  - Add to Priority Queue array  
  - Insert then sort Priority Queue using nested loops based on hr (shortest time first)  
- Else:  
  - Add order to Normal Queue (FIFO using rear++)  
  - Push order to Stack (for undo functionality)

### 🚚 Dispatch Order
- If Priority Queue is not empty (pSize > 0):
   - Display and deliver the first element of Priority Queue (priority[0])
   - Shift all remaining elements left
   - Decrease pSize
- Else if Normal Queue is not empty (front <= rear):
   - Display and deliver the first element in Normal Queue (normal[front])
   - Increment front
- Else:
   - Display "No orders"  

### ↩️ Undo Order
- Pop last order from Stack (top--)
- Search the order ID in Priority Queue:
  - If found, remove it by shifting elements left and decrease pSize
- Else search in Normal Queue:
  - If found, remove it by shifting elements left and decrease rear
- Display confirmation message for removal  

### 🔍 Search Order
- Input Order ID
- Search in Priority Queue from index 0 to pSize-1
- Display whether the order is found in Priority or Normal Queue
- If not found in both, display "Order not found"  

### 📊 Display Orders
- Display all elements in Priority Queue (from 0 to pSize-1)
- Display all elements in Normal Queue (from front to rear)
- Show order ID, name, and hours for each  

### 🚪 Exit System
- User selects option [6] Exit
- Program executes case 6 and displays "Exiting system..."
- Loop condition while(choice != 6) ends execution
- Program terminates safely   
  
## 🔁 Iterative vs Recursive Comparison

## 🎨 Design Decisions

### ✅ Choices Made:
- Used fixed-size arrays (MAX = 100) for all data structures  
  Arrays are used to implement the Priority Queue, Normal Queue, and Stack, providing simple implementation and fast data access without dynamic memory.

- Implemented Priority Queue using manual sorting (nested loops)  
  Orders with hr ≤ 5 are stored in the priority array and sorted using a nested loop comparison to ensure the shortest delivery time is always processed first.  

- Applied FIFO logic for Normal Queue using front and rear indices  
  Normal orders are processed in the order they arrive by incrementing rear during insertion and front during dispatch.  

- Used Stack (LIFO) with top pointer for Undo functionality  
  Each added order is pushed onto the stack, allowing the system to undo the most recent order using top--.  

- Used array shifting for deletion operations  
  Elements are shifted left when removing orders (during dispatch or undo) to maintain the correct structure of the arrays.  

- Console-based interface with ANSI color codes  
  Colors (RED, GREEN, BLUE) are used to highlight system messages, improving readability and user experience.   

### ⚖️ Trade-offs:
<h1 align = "center"> ⋆˚🚚⋆˚ DeliverEase: Delivery Management System ⋆˚🚚⋆˚ </h1>
<h2 align = center> by: ˚.📦🎀༘⋆ Queueties ˚.📦🎀༘⋆ </h2>

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

📌 If hr ≤ 5 → ```Priority Order```
📌 If hr > 5 → ```Normal Order```



## ˖᯽ Project Developers ᯽˖
|Name|Duties and Responsibilities|
|----|---------------------------|
|Buendia, Liam Keiji| Main Programmer|
|Carandang, Mary Yvonne C.|Documentation Lead|
|Lindo, Kristal Joy H.|Documentation II|
|Pasamba, Carl Kendy| Assistant Programmer|


## ‧₊˚ ┊ Acknowledgment
We sincerely express our gratitude to our instructor for the guidance, support, and valuable insights provided throughout the development of this project.

We also extend our appreciation to our classmates and peers for their cooperation, encouragement, and shared ideas, which contributed to the improvement of this system.

Lastly, we acknowledge the learning resources and materials that helped us strengthen our understanding of data structures and programming concepts used in this project.
