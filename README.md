# Smart-ATM-Simulator-in-C-File-based-CLI-App-
Developed a secure ATM system using C language that supports PIN-based login, balance checking, withdrawal and deposit functionalities. Integrated file storage to maintain account data persistently across sessions. Implemented input validation, transaction logging, and structured data handling using C structs and file operations.

 Smart ATM Simulator (C Language)

A command-line ATM simulation written in C. This project securely handles account verification using PINs, supports withdrawals, deposits, balance checks, and stores data in a persistent file.

 Features

- 🔐 PIN-based login (3 attempts)
- 💰 Balance Inquiry
- 💸 Cash Withdrawal
- 💵 Deposit Money
- 💾 File-based account storage (`accounts.txt`)
- 🔁 Logout system with menu-driven UI

## 📄 Account Format (`accounts.txt`)
Each line represents: `account_number name pin balance`

Create This File: accounts.txt (Example)
1010 John 1234 5000.00
1020 Riya 5678 8000.00



