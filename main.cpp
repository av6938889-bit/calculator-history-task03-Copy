#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using namespace std;

struct Calculation {
    double left;
    char operation;
    double right;
    double result;
};

bool readNumber(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return false;

        stringstream input(line);
        char extra;
        if ((input >> value) && !(input >> extra) && isfinite(value)) {
            return true;
        }
        cout << "Invalid number. Please enter a valid numeric value.\n";
    }
}

bool calculate(double left, char operation, double right, double& result,
               string& error) {
    switch (operation) {
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            if (right == 0.0) {
                error = "Division by zero is not allowed.";
                return false;
            }
            result = left / right;
            break;
        case '%':
            if (right == 0.0) {
                error = "Modulo by zero is not allowed.";
                return false;
            }
            result = fmod(left, right);
            break;
        case '^':
            result = pow(left, right);
            break;
        default:
            error = "Unknown operation.";
            return false;
    }

    if (!isfinite(result)) {
        error = "This operation does not produce a finite result.";
        return false;
    }
    return true;
}

void printHistory(const deque<Calculation>& history) {
    if (history.empty()) {
        cout << "History is empty. Perform a calculation first.\n";
        return;
    }

    cout << "\n--- Last " << history.size() << " calculation(s) ---\n";
    cout << fixed << setprecision(6);
    for (size_t i = 0; i < history.size(); ++i) {
        const Calculation& item = history[i];
        cout << i + 1 << ". " << item.left << ' ' << item.operation << ' '
             << item.right << " = " << item.result << '\n';
    }
}

int main() {
    deque<Calculation> history;
    cout << "=== Calculator with History ===\n";

    while (true) {
        cout << "\nChoose an option:\n"
             << "  +  Add\n"
             << "  -  Subtract\n"
             << "  *  Multiply\n"
             << "  /  Divide\n"
             << "  %  Modulo (remainder)\n"
             << "  ^  Power\n"
             << "  h  Show last 10 calculations\n"
             << "  q  Quit\n"
             << "Your choice: ";

        string choice;
        if (!getline(cin, choice)) {
            cout << "\nInput ended. Goodbye!\n";
            break;
        }

        if (choice == "q" || choice == "Q") {
            cout << "Goodbye!\n";
            break;
        }

        if (choice == "h" || choice == "H") {
            printHistory(history);
            continue;
        }

        if (choice.size() != 1 ||
            string("+-*/%^").find(choice[0]) == string::npos) {
            cout << "Invalid choice. Select +, -, *, /, %, ^, h, or q.\n";
            continue;
        }

        const char operation = choice[0];
        double left, right, result;
        if (!readNumber("Enter the first number: ", left)) {
            cout << "\nInput ended. Goodbye!\n";
            break;
        }
        if (!readNumber("Enter the second number: ", right)) {
            cout << "\nInput ended. Goodbye!\n";
            break;
        }

        string error;
        if (!calculate(left, operation, right, result, error)) {
            cout << "Error: " << error << "\n";
            continue;
        }

        cout << setprecision(10) << left << ' ' << operation << ' '
             << right << " = " << result << '\n';

        history.push_back({left, operation, right, result});
        if (history.size() > 10) {
            history.pop_front();
        }
    }

    return 0;
}
