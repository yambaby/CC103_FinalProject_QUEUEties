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

### ↩️ Undo Order

### 🔍 Search Order

### 📊 Display Orders

### 🚪 Exit System

## 🔁 Iterative vs Recursive Comparison

## 🎨 Design Decisions

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








