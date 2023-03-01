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
bool ErrorHandling(stack<double>& e, string err);
void performOp(const string& input, stack<double>& calculatorStack);
void performReverseOp(const string& input, stack<double>& calculatorStack);
void sum(stack<double>& calculatorStack);
void average(stack<double>& calculatorStack);
void PrintStack(stack<double> s);
double calculate(double right, double left, string input);

int main() {
    cout << "Welcome to the PostFix Calculator!" << endl;
    instructions();

    stack<double> calculatorStack;
    string input;

    while(true) {
        cout << ">> ";
        cin >> input;

        double num;
        if (istringstream(input) >> num) { // checking if user input was numeric
            calculatorStack.push(num);
        }
        else if (isOperator(input)) { // checking if user input was operator + - * /
            if (!ErrorHandling(calculatorStack, input)) { // checking for errors
                performOp(input, calculatorStack); // if input was operator -> calculate!
            }
        }
        else if (input == "x") {
            cout << ">> ";
            cin >> input;
            isOperator(input);
            performReverseOp(input, calculatorStack);
        }
        else if (input == "s") {
            if (!ErrorHandling(calculatorStack, input)) {
                sum(calculatorStack);
            }
        }
        else if (input == "a") {
            if (!ErrorHandling(calculatorStack, input)) {
                average(calculatorStack);
            }
        }
        else if (input == "p") {
            PrintStack(calculatorStack);
        }
        else if (input == "q") { // checking if user input was "quit"
            cout << "Quitting PostFix Calculator..." << endl;
            return 0;
        }
        else { // error handling for invalid input
            cout << "invalid input\n" << endl;
            instructions();
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
        << "p -> for printing the stack\n"
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
    stack<double> test;
    test.push(left);
    test.push(right);

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
        if (!ErrorHandling(test, input)) { // checking if divider is 0
            return (left / right);
        }
    }
    return 0;
}

void performOp(const string& input, stack<double>& calculatorStack) {
    double leftValue, rightValue, result;

    rightValue = calculatorStack.top(); // saving the last stack value to a variable
    calculatorStack.pop(); // removing value from stack

    leftValue = calculatorStack.top();
    calculatorStack.pop();

    result = (calculate(rightValue, leftValue, input));

    cout << "result: " << result << endl;
    calculatorStack.push(result);
}

void performReverseOp(const string& input, stack<double>& calculatorStack) {
    double leftValue, rightValue, result;

    leftValue = calculatorStack.top(); // saving the last stack value to a variable
    calculatorStack.pop(); // removing value from stack

    rightValue = calculatorStack.top();
    calculatorStack.pop();

    result = (calculate(rightValue, leftValue, input));

    cout << "result: " << result << endl;
    calculatorStack.push(result);
}

void sum(stack<double>& calculatorStack) {
    // calculate sum here
    double sum;
    while(!calculatorStack.empty()) {
        sum += calculatorStack.top();
        calculatorStack.pop();
    }
    cout << "result: " << sum << endl;
    calculatorStack.push(sum);
}

void average(stack<double>& calculatorStack) {
    double sum;
    int amount = calculatorStack.size();
    while(!calculatorStack.empty()) {
        sum += calculatorStack.top();
        calculatorStack.pop();
    }
    double average = sum/amount;
    cout << "result: " << average << endl;
    calculatorStack.push(average);
}

void PrintStack(stack<double> s)
{
    // If stack is empty then return
    if (s.empty()) {
        return;
    }

    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

bool ErrorHandling(stack<double>& stack, string input) { // returns true if any error found

    if (stack.empty() && input == "a") {
        cout << "Stack is empty. Average is NaN." << endl;
        return true;
    }
    else if (stack.empty())
    {
        cout << "Stack is empty. Cannot calculate without any numbers." << endl;
        return true;
    }
    else if (stack.size() == 1 && input == "a") {
        cout << "Stack has only one value." << endl;
        return false;
    }
    else if (stack.size() <= 1) {
        cout << "Stack has one or less entries. Cannot calculate." << endl;
        return true;
    }
    else if (stack.top() == 0 && input == "/") {
        cout << "Cannot divide by zero" << endl;
        return true;
    }
    else {
        return false;
    }

}