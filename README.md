# 🔌 Energy Consumption Management System (in C)

This is a C-based console application that simulates a simple energy billing system for residential users. It allows up to 20 clients to register, track their monthly energy consumption (in kWh), calculate charges, and make payments based on their usage.

---

## 📋 Features

- 📝 **User Sign-up & Login System**
  - Creates a unique username based on the surname (e.g., `smith123`)
  - Password-based login authentication

- 📊 **Monthly Consumption Tracking**
  - Users input their monthly kWh consumption
  - Calculates energy cost based on consumption range:
    - Up to 1600 kWh → €0.005 per unit
    - 1601–2000 kWh → €0.008 per unit
    - Above 2000 kWh → €0.009 per unit
  - Cost is weighted by days in each month (e.g., February has 28 days)

- 💳 **Payment System**
  - Displays calculated cost per month
  - Allows the user to pay for any unpaid month (must input the exact amount)
  - Marks each month as "paid" upon successful payment

- 📈 **Most Expensive Month**
  - Identifies the month with the highest paid energy bill

- 🛠️ **Edit User Details**
  - Allows users to update their address and home size

---

## 🧠 How it Works

The system is entirely command-line based and consists of structured menus. Each user’s data is stored in memory using `struct`, and energy cost is stored in a 2D array.

Data is **not persistent** (not saved to files), so all progress resets on restart.

---

![image](https://github.com/user-attachments/assets/9c160e9b-3dfc-4028-bdd1-1b96bec6cf83)
---
![image](https://github.com/user-attachments/assets/37e194c0-46a1-48cd-a3e0-1a5459f88fa2)
