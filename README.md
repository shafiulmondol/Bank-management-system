# SKS Bank Management System

## Overview
The **SKS Bank Management System** is a comprehensive software application designed to streamline banking operations. This system replicates key banking functionalities, offering secure and user-friendly features for customers, employees, and administrators. The project is built using **C++**, with a focus on modularity, security, and scalability.

---

## Features
### Customer Section
1. **Account Management**
   - Sign up with personal details, secure passwords, and unique account numbers.
   - Log in to access account dashboards.
2. **Transactions**
   - Deposit and withdraw funds with validations.
   - View transaction history and account details.
3. **Loan Requests**
   - Apply for loans with dynamic interest rates based on user type (Student/Professional).
   - Manage loan repayments.

### Employee Section
1. **Customer Account Management**
   - Assist customers with account issues.
   - Delete customer accounts when necessary.
2. **Employee Management**
   - Add new employees with educational backgrounds.
   - Delete and view employee details.

### Admin Section
1. **System Monitoring**
   - View total number of customers, employees, and loan receivers.
2. **Employee Management**
   - Add or terminate employees.
3. **Reports and Logs**
   - Access customer and employee reports.
4. **Bank Management**
   - Close the system for daily operations.

### Help Section
- Guided walkthroughs for account creation and password management.
- Security tips and troubleshooting guides.
- Reporting system for customer issues.

---

## Technical Details
### Programming Language: **C++**
### Tools Used:
- **Visual Studio**
- **GitHub Desktop**

### Libraries:
- `<iostream>` for input/output operations.
- `<fstream>` for file handling.
- `<string>` for text management.

### Data Handling
- **File-based Storage**:
  - `customer_data.txt`: Stores customer information.
  - `balances.txt`: Manages account balances.
  - `transactions.txt`: Tracks transaction history.
  - `Loan.txt`: Maintains loan details.
  - `issues.txt`: Records reported issues.
  - `loan_history.txt`: Tracks loan payment history.

### Key Concepts Implemented:
1. **Object-Oriented Programming (OOP):**
   - Classes and inheritance (e.g., `employee`, `bank_lone`).
   - Polymorphism for dynamic behavior.
2. **File Handling:**
   - Reading and writing customer and transaction data.
3. **Validation Mechanisms:**
   - Secure password validation and error handling.
4. **Control Structures:**
   - Conditional statements and loops for user interaction.

---

## Limitations
1. **Database Integration**: Currently relies on file-based storage, limiting scalability.
2. **Feature Expansion**: Future iterations can include:
   - More diverse account and loan types.
   - Enhanced security features.

---

## How to Use
### Setup:
1. Clone the repository: `git clone https://github.com/shafiulmondol/Bank-management-system`.
2. Open the project in Visual Studio.
3. Compile and run the `BankOriginal.cpp` file.

### Navigation:
1. Choose a user role (Customer, Employee, Admin) from the main menu.
2. Follow on-screen prompts to:
   - Create or log in to accounts.
   - Perform transactions or manage loans.
   - Access help and report issues.

---

## Team Members
| Name              | ID         |
|-------------------|------------|
| Md. Kawsar Miah   | 23303105   |
| Md. Shafiul Islam | 23303106   |
| Sumaiya Haq       | 23303137   |

---

## Conclusion
The SKS Banking System is a secure, scalable, and user-friendly platform designed to modernize banking operations. By integrating key banking functions and emphasizing data security, it provides a solid foundation for further development and innovation in digital banking solutions.

---

For any inquiries or support, please contact:
- Email: mdshafiulmondol02@gmail.com 
