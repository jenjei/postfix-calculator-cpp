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

void instructions();
bool isOperator(const string& input);
void performOp(const string& input, stack<double>& calculatorStack);
void performReverseOp(const string& input, stack<double>& calculatorStack);
void sum(stack<double>& calculatorStack);

int main() {
    cout << "Welcome to the PostFix Calculator!" << endl;
    instructions();

    stack<double> calculatorStack;
    string input;

    while(true) {
        cout << ">> ";
        cin >> input;

        double num;
        if(istringstream(input) >> num) { // checking if user input was double
            calculatorStack.push(num);
        }
        else if (isOperator(input)) { // checking if user input was operator + - * /
            performOp(input, calculatorStack); // if input was operator -> calculate!
        }
        else if (input == "x") {
            cout << ">> ";
            cin >> input;
            isOperator(input);
            performReverseOp(input, calculatorStack);
        }
        else if (input == "s") {
            sum(calculatorStack);
        }
        else if (input == "q") { // checking if user input was "quit"
            cout << "Quitting PostFix Calculator..." << endl;
            return 0;
        }
        else { // error handling for invalid input
            cout << "invalid input" << endl;
        }

    }
}

void instructions() {
    cout << "Enter some valid command:\n"
        << "Numbers or decimals to add into calculation stack \n"
        << "+ - * / -> as operations\n"
        << "x -> for changing the order of operations\n"
        << "s -> for summing up all the values in the stack\n"
        << "a -> for calculating average of all the values in the stack\n"
        << "q -> for quit the calculator\n";
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

double calculate(double right, double left, string input) {
    if (input == "-") {
        return (left - right);
    }
    else if (input == "+") {
        return (left + right);
    }
    else if (input == "*") {
        return left * right;
    }
    else if (input == "/") {
        return (left / right);
    }
}

void performOp(const string& input, stack<double>& calculatorStack) {
    double leftValue, rightValue, result;

    rightValue = calculatorStack.top(); // saving the last stack value to a variable
    calculatorStack.pop(); // removing value from stack

    leftValue = calculatorStack.top();
    calculatorStack.pop();

    calculate(rightValue, leftValue, input);

    cout << "result: " << result << endl;
    calculatorStack.push(result);
}

void performReverseOp(const string& input, stack<double>& calculatorStack) {
    double leftValue, rightValue, result;

    leftValue = calculatorStack.top(); // saving the last stack value to a variable
    calculatorStack.pop(); // removing value from stack

    rightValue = calculatorStack.top();
    calculatorStack.pop();

    calculate(rightValue, leftValue, input);

    cout << "result: " << result << endl;
    calculatorStack.push(result);
}

void sum(stack<double>& calculatorStack) {
    // calculate sum here
    double sum;
    while(!calculatorStack.empty()){
        sum += calculatorStack.top();
        calculatorStack.pop();
    }
    cout << "result: " << sum << endl;
    calculatorStack.push(sum);
}