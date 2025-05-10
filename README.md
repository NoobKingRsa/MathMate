# MathMate

MathMate is a versatile command-line calculator application written in C. It supports basic arithmetic operations, advanced mathematical functions, memory management, and a history log with timestamps. Designed to be intuitive and user-friendly, MathMate also includes cross-platform support and customizable logging paths.

---

## Features

1. **Basic Arithmetic Operations**:
   - Addition, Subtraction, Multiplication, and Division.
   
2. **Advanced Functions**:
   - Modulus, Power, and Square Root.

3. **Memory Management**:
   - Store multiple memory slots.
   - Recall and clear specific memory values.

4. **History Logging**:
   - Save all operations to a `history.log` file.
   - Logs include timestamps for each operation.
   - Option to specify a custom folder for the log file.
   - Clear history via the menu.

5. **Cross-Platform Support**:
   - Works on Windows and UNIX-based systems (`system("cls")` and `system("clear")`).

6. **UI/UX Enhancements**:
   - Visual separators for better readability.
   - Clear error messages for invalid inputs and operations.

---

## Installation

### Prerequisites
- A C compiler (e.g., GCC).
- Compatible with Linux, macOS, and Windows.

### Steps
1. Clone the repository or copy the source code.
2. Save the code as `enhanced_calculator_with_memory_and_ui.c`.
3. Compile the program using the following command:
   ```bash
   gcc enhanced_calculator_with_memory_and_ui.c -o mathmate -lm
   ```
   The `-lm` flag links the `math.h` library.

4. Run the program:
   ```bash
   ./mathmate
   ```

---

## Usage

### Menu Options
1. **Basic Operations**:
   - Perform addition, subtraction, multiplication, or division.

2. **Advanced Functions**:
   - Modulus: `%` for integers.
   - Power: `x^y`.
   - Square Root: `√x`.

3. **Memory Management**:
   - **Recall Memory (Option 8)**: View stored memory values.
   - **Add to Memory (Option 9)**: Add a value to memory.
   - **Clear Memory (Option 10)**: Reset all memory slots.

4. **History Management**:
   - Store all operations with timestamps in `history.log`.
   - Clear the history log via **Option 11**.

5. **Exit**:
   - Quit the program via **Option 12**.

### Example Commands
- **Addition**:
  ```text
  Enter your choice (1-12): 1
  Enter the first number: 5
  Enter the second number: 3
  Result: 5.00 + 3.00 = 8.00
  ```

- **Recall Memory**:
  ```text
  Enter your choice (1-12): 8
  Memory is empty.
  ```

- **Clear History**:
  ```text
  Enter your choice (1-12): 11
  History cleared successfully.
  ```

---

## History Logging

By default, the program saves the `history.log` file in the current directory. If you want to specify a custom folder for the history log, pass the folder path as an argument when running the program:
```bash
./mathmate /path/to/folder
```

Each history entry includes:
- Timestamp
- Operation performed
- Operands and result

Example log:
```
2025-05-10 18:40:12 | Addition: 5.00, 3.00 = 8.00
2025-05-10 18:41:15 | Modulus: 10.00, 3.00 = 1.00
```

---

## Error Handling
- **Division by Zero**:
  Displays an error message: `Error: Division by zero is undefined.`
  
- **Square Root of Negative Numbers**:
  Displays an error message: `Error: Cannot calculate square root of a negative number.`

- **Invalid Input**:
  Prompts the user to enter a valid numeric value.

---

## Contribution Guidelines

We welcome contributions to improve MathMate further! Here's how you can contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your message here"
   ```
4. Push your branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a pull request with a detailed description of your changes.

---

## Future Enhancements

1. **Advanced Memory Management**:
   - Store and manage multiple memory slots with user-friendly commands.

2. **Support for Trigonometric Functions**:
   - Add sine, cosine, and tangent operations.

3. **Graphical User Interface (GUI)**:
   - Develop a GUI for non-CLI users.

4. **Scientific Mode**:
   - Include features like logarithms, exponential functions, and more.

---

## License

This project is licensed under the MIT License. Feel free to use, modify, and distribute the application.

---

## Contact

For any questions or suggestions, feel free to reach out:
- GitHub: [NoobKingRsa](https://github.com/NoobKingRsa)

---
