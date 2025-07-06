# ✈️ AHS Airplane Ticket Booking System

A console-based C++ application to simulate an airline ticket booking system. It allows users to register flight details, choose travel classes, and print out ticket information. This project is suitable for beginner-to-intermediate learners practicing file handling, arrays, conditionals, loops, and formatted output in C++.

---

## 📋 Features

- ✅ One-way & Two-way ticket support  
- 👨‍👩‍👧 Passenger types: Adults, Children, Infants  
- ⏰ Departure and Return time selection  
- 🛫 Choose departure and arrival countries from files  
- ✈️ Plane types and class (Business / Economy) options  
- 📄 Auto-generates formatted tickets in console  
- 🧾 Stores ticket data in `Record.xls` (can be opened in Excel)  
- 📂 Reads from external files like:
  - `ARRIVAL_COUNTRIES.txt`
  - `DEPARTURE_TIME.txt`
  - `AIRCRAFT_TYPES.txt`
  - `CLASS.txt`

---

## 🧑‍💻 How to Run

### 💻 Prerequisites

- C++ compiler (e.g. g++, Visual C++)
- Any terminal (Command Prompt, Bash, etc.)
- `Record.xls` and required `.txt` files in the same directory

### 🔧 Compile

```bash
g++ -o ticket_booking main.cpp
🚀 Run
bash
./ticket_booking


🗂 File Structure
pgsql
Copy
Edit
.
├── main.cpp                # Main application source code
├── ARRIVAL_COUNTRIES.txt  # List of destination countries
├── DEPARTURE_TIME.txt     # List of departure/return time options
├── AIRCRAFT_TYPES.txt     # Available aircraft types
├── CLASS.txt              # Ticket class info (Business / Economy)
└── Record.xls             # Auto-generated record of bookings
🧠 Concepts Covered
ofstream / ifstream for file I/O

setw() and left/right for formatting

String manipulation and user input handling

Arrays for storing passenger data

Conditional logic and loops

Functions with reference parameters

📌 Notes
All records are saved in Record.xls using tab-separated values.

Ensure all .txt files exist with valid data for smooth flow.

Designed for terminal use — uses system("cls"), system("pause"), and sleep().

🙋 Author
Developed by Muhammad Hussain as a console-based simulation project.

📸 Sample Output
markdown
**********************************************************
*    NAME: John Doe         FLIGHT: B707        DATE: 12/25/2025 *
*                                                         *
*    PAKISTAN      ------------------>>     GERMANY        *
*                                                         *
*    TIME: 08:00              CLASS: BUSINESS              *
*                                                         *
**********************************************************
✅ To-Do / Suggestions
 Convert data storage to .csv for better Excel compatibility

 Add error-handling for file reading

 Refactor repeated code into reusable functions

 Add GUI with Qt or migrate to web-based interface

📝 License
This project is educational and open for learning purposes. No license attached.
