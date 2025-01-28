#include <iostream> // Includes the input-output stream library for using cout and cin.
#include <string> // Includes the string library for using the string class.
#include <vector> // Includes the vector library for using the vector class.

using namespace std; // Allows us to use standard library names without the std:: prefix.

class Lecture { // Defines a class named Lecture.
public: // Access specifier indicating that the following members are public.
    string time; // Declares a public string variable to store the lecture time.
    string venue; // Declares a public string variable to store the lecture venue.
    string lecturer; // Declares a public string variable to store the lecturer's name.

    Lecture(string t, string v, string l) : time(t), venue(v), lecturer(l) {} // Constructor to initialize the Lecture object with time, venue, and lecturer.
};

class SchoolManagementSystem { // Defines a class named SchoolManagementSystem.
private: // Access specifier indicating that the following members are private.
    vector<Lecture> lectures; // Declares a private vector to store Lecture objects.

public: // Access specifier indicating that the following members are public.
    void addLecture(string time, string venue, string lecturer) { // Function to add a lecture to the system.
        lectures.push_back(Lecture(time, venue, lecturer)); // Adds a new Lecture object to the lectures vector.
    }

    void viewLectures() { // Function to view all lectures in the system.
        for (int i = 0; i < lectures.size(); i++) { // Loops through each Lecture object in the lectures vector.
            cout << "Lecture " << i + 1 << ": " << endl; // Prints the lecture number.
            cout << "Time: " << lectures[i].time << endl; // Prints the lecture time.
            cout << "Venue: " << lectures[i].venue << endl; // Prints the lecture venue.
            cout << "Lecturer: " << lectures[i].lecturer << endl; // Prints the lecturer's name.
            cout << "-------------------------" << endl; // Prints a separator line.
        }
    }
};

int main() { // Main function where the program execution begins.
    SchoolManagementSystem sms; // Creates an object of the SchoolManagementSystem class.
    int choice; // Declares an integer variable to store the user's choice.
    string time, venue, lecturer; // Declares string variables to store lecture details.

    while (true) { // Infinite loop to keep the program running until the user chooses to exit.
        cout << "1. Add Lecture" << endl; // Prints the option to add a lecture.
        cout << "2. View Lectures" << endl; // Prints the option to view lectures.
        cout << "3. Exit" << endl; // Prints the option to exit the program.
        cout << "Enter your choice: "; // Prompts the user to enter their choice.
        cin >> choice; // Reads the user's choice.

        switch (choice) { // Switch statement to handle different choices.
        case 1: // Case for adding a lecture.
            cout << "Enter lecture time: "; // Prompts the user to enter the lecture time.
            cin.ignore(); // Ignores the newline character left in the input buffer.
            getline(cin, time); // Reads the lecture time.
            cout << "Enter lecture venue: "; // Prompts the user to enter the lecture venue.
            getline(cin, venue); // Reads the lecture venue.
            cout << "Enter lecturer name: "; // Prompts the user to enter the lecturer's name.
            getline(cin, lecturer); // Reads the lecturer's name.
            sms.addLecture(time, venue, lecturer); // Adds the lecture to the system.
            break; // Breaks out of the switch statement.
        case 2: // Case for viewing lectures.
            sms.viewLectures(); // Calls the function to view lectures.
            break; // Breaks out of the switch statement.
        case 3: // Case for exiting the program.
            return 0; // Exits the program.
        default: // Default case for invalid choices.
            cout << "Invalid choice. Please try again." << endl; // Prints an error message.
        }
    }
}

