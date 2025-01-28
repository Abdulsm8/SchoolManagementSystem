#include <iostream> //header file for I/O manipulation
#include <cmath> // For scientific calculations

using namespace std; //allowing us to use ciout/cin without using std:: continuosly

// Function prototypes
void showMenu();
void performOperation(int choice);

int main() { //the main program goes here
    int choice; //declaring user choice as integer
    do { //contineos loop when true
        showMenu(); // calling the function to aski user for his choice
        cout << "Enter your choice: "; //asking user to type in his/her choice
        cin >> choice; //collecting the input from the user
        performOperation(choice);// calling the function to perform user's choice calculation
    } while (choice != 0); // Exit the program when choice is 0

    return 0; //the program ended successfully
}

// Function to display the menu
void showMenu() { // the function for user to see the available services
    cout << "\nCalculator Menu:\n"; //title of the menu
    cout << "1. Addition\n"; //choice 1 addition
    cout << "2. Subtraction\n"; //choice 2 subtraction
    cout << "3. Multiplication\n";//choice 3 multiplication
    cout << "4. Division\n";//choice 4 division
    cout << "5. Modulus\n";//choice 5 modulo
    cout << "6. Power\n";//choice 6 power
    cout << "7. Square Root\n";//choice 7 sqrt
    cout << "0. Exit\n";//choice 0 to terminate
}

// Function to perform the selected operation
void performOperation(int choice) { //function to collect and analyse user input
    double num1, num2, result; //declaring user inputs and result as double data type

    switch (choice) { // start of the switch statement(a conditional statement)
        case 1: // Addition
            cout << "Enter two numbers: "; //asking user to type-in the 2 inputs
            cin >> num1 >> num2; //collecting the value from the user
            result = num1 + num2; // performing the calculations
            cout << "Result: " << result << endl; // printing the output
            break; // the end of addition choice
        case 2: // Subtraction
            cout << "Enter two numbers: "; //asking user to type-in the 2 inputs
            cin >> num1 >> num2;
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case 3: // Multiplication
            cout << "Enter two numbers: "; //asking user to type-in the 2 inputs
            cin >> num1 >> num2;
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case 4: // Division
            cout << "Enter two numbers: "; //asking user to type-in the 2 inputs
            cin >> num1 >> num2;
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        case 5: // Modulus
            int intNum1, intNum2;
            cout << "Enter two integers: "; //asking user to type-in the 2 inputs
            cin >> intNum1 >> intNum2;
            if (intNum2 != 0) {
                result = intNum1 % intNum2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        case 6: // Power
            cout << "Enter base and exponent: "; //asking user to type-in the 2 inputs, for base and exponents
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
            break;
        case 7: // Square Root
            cout << "Enter a number: "; //asking user to type-in the input
            cin >> num1;
            if (num1 >= 0) {
                result = sqrt(num1);
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Square root of a negative number is not allowed.\n";
            }
            break;
        case 0: // Exit
            cout << "Exiting the calculator. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }
}

