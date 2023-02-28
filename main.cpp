#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;
using std::istringstream;

bool isOperator(const string& input);
void performOp(const string& input, stack<double>& calculatorStack);

int main() {
    cout << "Welcome to the PostFix Calculator!" << endl;

    stack<double> calculatorStack;
    string input;

    while(true) {
        cout << ">>";
        cin >> input;

        double num;
        if(istringstream(input) >> num) { // checking if user input was double
            calculatorStack.push(num);
        }
        else if (isOperator(input)) { // checking if user input was operator + - * /
            performOp(input, calculatorStack); // if input was operator -> calculate!
        }
        else if (input == "q") { // checking if user input was "quit"
            return 0;
        }
        else { // error handling for invalid input
            cout << "invalid input" << endl;
        }

    }
}

bool isOperator(const string& input) { // returning true or false
    string ops[] = {"+", "-", "*", "/"};

    for (int i=0; i<4; i++) { // finding out if user input was operator + - * /
        if (input==ops[i]) {
            return true;
        }
    }
    return false;
}

void performOp(const string& input, stack<double>& calculatorStack) {
    double leftValue, rightValue, result;

    rightValue = calculatorStack.top(); // saving the last stack value to a variable
    calculatorStack.pop(); // removing value from stack

    leftValue = calculatorStack.top();
    calculatorStack.pop();

    if (input == "-") {
        result = leftValue - rightValue;
    }
    else if (input == "+") {
        result = leftValue + rightValue;
    }
    else if (input == "*") {
        result = leftValue * rightValue;
    }
    else if (input == "/") {
        result = leftValue / rightValue;
    }

    cout << "result: " << result << endl;
    calculatorStack.push(result);
}