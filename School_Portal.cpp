#include <iostream> // Includes the input-output stream library for using cout and cin.
#include <fstream> // Includes the file stream library for file operations.
#include <string> // Includes the string library for using the string class.
#include <regex> // Includes the regex library for regular expression operations.

using namespace std; // Allows us to use standard library names without the std:: prefix.

class Student { // Defines a class named Student.
public: // Access specifier indicating that the following members are public.
    string name; // Declares a public string variable to store the student's name.
    int age; // Declares a public integer variable to store the student's age.
    string email, course; // Declares a public string variable to store the student's email and course.
    float gpa; // Declares a public float variable to store the student's GPA.

    Student(string n, int a, string e, float g, string c) : name(n), age(a), email(e), gpa(g), course(c) {} // Constructor to initialize the Student object with name, age, email,GPA and course.
};

class SchoolPortal { // Defines a class named SchoolPortal.
public: // Access specifier indicating that the following members are public.
    void applyForAdmission() { // Function to apply for admission.
        string name, email, course; // Declares string variables to store the student's name, email and course.
        int age; // Declares an integer variable to store the student's age.
        float gpa; // Declares a float variable to store the student's GPA.

        cout << "Enter your name: "; // Prompts the user to enter their name.
        cin.ignore(); // Ignores the newline character left in the input buffer.
        getline(cin, name); // Reads the student's name.
        cout << "Enter your age: "; // Prompts the user to enter their age.
        cin >> age; // Reads the student's age.
        cout << "Enter your email: "; // Prompts the user to enter their email.
        cin.ignore(); // Ignores the newline character left in the input buffer.
        getline(cin, email); // Reads the student's email.
         cout << "Enter your Course: "; // Prompts the user to enter their course.
        cin.ignore(); // Ignores the newline character left in the input buffer.
        getline(cin, course); // Reads the student's course.
        

        if (!isValidEmail(email)) { // Checks if the email is invalid.
            cout << "Invalid email format. Please try again." << endl; // Prints an error message if the email is invalid.
            return; // Exits the function.
        }

        if (isDuplicateEmail(email)) { // Checks if the email is a duplicate.
            cout << "An application with this email already exists. Please use a different email." << endl; // Prints an error message if the email is a duplicate.
            return; // Exits the function.
        }

        cout << "Enter your GPA: "; // Prompts the user to enter their GPA.
        cin >> gpa; // Reads the student's GPA.

        Student student(name, age, email, gpa, course); // Creates a Student object with the entered details.
        saveStudentInfo(student); // Calls the function to save the student's information.

        if (isEligible(student)) { // Checks if the student is eligible for admission.
            cout << "Congratulations! You are eligible for admission to study "<< course << "." << endl; // Prints a success message if the student is eligible.
        } else { // If the student is not eligible.
            cout << "Sorry, you are not eligible for admission." << endl; // Prints a failure message if the student is not eligible.
        }
    }

    void saveStudentInfo(Student student) { // Function to save the student's information to a file.
        ofstream file("student_info.txt", ios::app); // Opens the file in append mode.
        if (file.is_open()) { // Checks if the file is open.
            file << "Name: " << student.name << endl; // Writes the student's name to the file.
            file << "Age: " << student.age << endl; // Writes the student's age to the file.
            file << "Email: " << student.email << endl; // Writes the student's email to the file.
            file << "Course: " << student.course << endl; // Writes the student's course to the file.
            file << "GPA: " << student.gpa << endl; // Writes the student's GPA to the file.
            file << "-------------------------" << endl; // Writes a separator line to the file.
            file.close(); // Closes the file.
        } else { // If the file is not open.
            cout << "Unable to open file." << endl; // Prints an error message.
        }
    }

    bool isEligible(Student student) { // Function to check if the student is eligible for admission.
        return student.gpa >= 3.0; // Eligibility criteria: GPA must be 3.0 or higher.
    }

    bool isValidEmail(string email) { // Function to validate the email format.
        const regex pattern("[\\w\\.-]+@[\\w\\.-]+\\.\\w+"); // Regular expression pattern for a valid email.
        return regex_match(email, pattern); // Returns true if the email matches the pattern, false otherwise.
    }

    bool isDuplicateEmail(string email) { // Function to check if the email is a duplicate.
        ifstream file("student_info.txt"); // Opens the file in read mode.
        if (file.is_open()) { // Checks if the file is open.
            string line;
            while (getline(file, line)) { // Reads each line from the file.
                if (line.find("Email: " + email) != string::npos) { // Checks if the email is found in the file.
                    file.close(); // Closes the file.
                    return true; // Returns true if the email is found.
                }
            }
            file.close(); // Closes the file.
        }
        return false; // Returns false if the email is not found.
    }

    void viewStudentInfo() { // Function to view the saved student information.
        ifstream file("student_info.txt"); // Opens the file in read mode.
        if (file.is_open()) { // Checks if the file is open.
            string line; // Declares a string variable to store each line read from the file.
            while (getline(file, line)) { // Reads each line from the file.
                cout << line << endl; // Prints the line to the console.
            }
            file.close(); // Closes the file.
        } else { // If the file is not open.
            cout << "Unable to open file." << endl; // Prints an error message.
        }
    }
};

int main() { // Main function where the program execution begins.
    SchoolPortal portal; // Creates an object of the SchoolPortal class.
    int choice; // Declares an integer variable to store the user's choice.

    while (true) { // Infinite loop to keep the program running until the user chooses to exit.
        cout << "1. Apply for Admission" << endl; // Prints the option to apply for admission.
        cout << "2. View Student Information" << endl; // Prints the option to view student information.
        cout << "3. Exit" << endl; // Prints the option to exit the program.
        cout << "Enter your choice: "; // Prompts the user to enter their choice.
        cin >> choice; // Reads the user's choice.

        switch (choice) { // Switch statement to handle different choices.
        case 1: // Case for applying for admission.
            portal.applyForAdmission(); // Calls the function to apply for admission.
            break; // Breaks out of the switch statement.
        case 2: // Case for viewing student information.
            portal.viewStudentInfo(); // Calls the function to view student information.
            break; // Breaks out of the switch statement.
        case 3: // Case for exiting the program.
            return 0; // Exits the program.
        default: // Default case for invalid choices.
            cout << "Invalid choice. Please try again." << endl; // Prints an error message.
        }
    }
}

