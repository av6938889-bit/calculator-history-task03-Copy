# Task 03 — Calculator with History

An interactive C++ console calculator that keeps running until the user quits and can show the last ten successful calculations.

## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`), modulo/remainder (`%`), and power (`^`).
- Enter `h` to display the most recent ten successful calculations.
- Enter `q` to quit.
- Stores calculations in a `deque`; when more than ten are stored, the oldest one is removed.
- Handles invalid menu choices and non-numeric input without crashing.
- Prevents division by zero and modulo by zero.
- Detects non-finite results, such as overflow or invalid power results.

## Power and modulo

- `^` means exponentiation in this program. For example, `2 ^ 3` gives `8`.
- `%` gives the remainder. For example, `10 % 3` gives `1`. Decimal operands are supported using `fmod`.

## Compile and run

You need a C++ compiler such as `g++`.

On macOS or Linux, open Terminal in this folder and run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o calculator
./calculator
```

On Windows with MinGW, run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o calculator.exe
calculator.exe
```

## Example session

```text
=== Calculator with History ===

Choose an option:
  +  Add
  -  Subtract
  *  Multiply
  /  Divide
  %  Modulo (remainder)
  ^  Power
  h  Show last 10 calculations
  q  Quit
Your choice: +
Enter the first number: 12
Enter the second number: 5
12 + 5 = 17

Your choice: h

--- Last 1 calculation(s) ---
1. 12.000000 + 5.000000 = 17.000000
```

## Files

- `main.cpp` — source code.
- `README.md` — project overview and run instructions.
