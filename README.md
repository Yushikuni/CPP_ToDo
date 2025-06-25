# ✅ Console ToDo List (C++)

A simple task manager built in C++ that runs in the console and stores tasks in a text file.  
Allows users to add, list, and mark tasks as complete. Great practice for file I/O, CLI interaction and logic structuring in C++.

---

## 🛠️ Technologies

- C++17
- Standard Library only (`<iostream>`, `<fstream>`, `<string>`, `<sstream>`)
- Console UI
- File-based persistence (`example.txt`)

---

## 📋 Features

- ➕ Add a new task with name and description  
- 📄 List all tasks stored in file  
- ✔️ Mark a task as completed  
- 🧾 Each task has: ID, completed flag, title, and description  
- 💾 File I/O via `fstream` – tasks stored in `example.txt`

---

## ▶️ How to Run

### Compile (Linux/macOS):
```bash
g++ ToDoList.cpp -o todo
./todo
```

Compile (Windows):
```bash
g++ ToDoList.cpp -o todo.exe
todo.exe
```

Sample Output
```bash
Option Menu: 
ANY OTHER KEYS WILL IMMEDIATELY TERMINATE THE PROGRAM...
0 - For terminate program
1 - For Add New Task
2 - For Print All Tasks
3 - For Update Tasks
You Choose:
```

## 📂 File Structure
🔹ToDoList.cpp
🔹example.txt     ← generated automatically
🔹README.md

## 🧹 Possible Improvements
🔹Refactor into multiple source files (TaskManager.cpp, main.cpp)
🔹Add better parsing (support for multi-word input)
🔹Store tasks in CSV or JSON format
🔹Improve update logic (rewrite file instead of line edits)
🔹Add timestamps and task categories

👩‍💻 Author
Created by Květuše (Yushikuni) – practicing real-world C++ logic and data persistence.

