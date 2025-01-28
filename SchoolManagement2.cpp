#include <iostream> // Include the input-output stream library
#include <vector> // Include the vector library for dynamic arrays
#include <string> // Include the string library for string operations
#include <fstream> // Include the file stream library for file operations

using namespace std; // Use the standard namespace

// Structure to store course information
struct Course {
    string courseName; // Variable to store the course name
    string lecturerName; // Variable to store the lecturer name
    string lectureVenue; // Variable to store the lecture venue
    string lectureTime; // Variable to store the lecture time
    string lectureDate; // Variable to store the lecture date
};

// Function prototypes
void showLecturerMenu(); // Function to display the lecturer menu
void showStudentMenu(); // Function to display the student menu
void addCourse(vector<Course>& courses); // Function to add a course
void editCourse(vector<Course>& courses); // Function to edit a course
void viewCourses(const vector<Course>& courses); // Function to view courses
void saveCoursesToFile(const vector<Course>& courses); // Function to save courses to a file
void loadCoursesFromFile(vector<Course>& courses); // Function to load courses from a file

int main() {
    vector<Course> courses; // Vector to store courses
    loadCoursesFromFile(courses); // Load courses from file at the start
    int userType; // Variable to store the user type

    do {
        cout << "Select user type:\n"; // Prompt user to select user type
        cout << "1. Lecturer\n"; // Option for lecturer
        cout << "2. Student\n"; // Option for student
        cout << "0. Exit\n"; // Option to exit
        cout << "Enter your choice: "; // Prompt user to enter choice
        cin >> userType; // Get user input

        switch (userType) {
            case 1:
                showLecturerMenu(); // Display lecturer menu
                break;
            case 2:
                showStudentMenu(); // Display student menu
                break;
            case 0:
                cout << "Exiting the system. Goodbye!\n"; // Exit message
                break;
            default:
                cout << "Invalid choice. Please try again.\n"; // Invalid choice message
                break;
        }

        if (userType == 1) {
            int lecturerChoice; // Variable to store lecturer's choice
            do {
                cout << "Enter your choice: "; // Prompt lecturer to enter choice
                cin >> lecturerChoice; // Get lecturer's input
                switch (lecturerChoice) {
                    case 1:
                        addCourse(courses); // Add course
                        saveCoursesToFile(courses); // Save courses to file after adding
                        break;
                    case 2:
                        editCourse(courses); // Edit course
                        saveCoursesToFile(courses); // Save courses to file after editing
                        break;
                    case 0:
                        cout << "Returning to main menu.\n"; // Return to main menu message
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n"; // Invalid choice message
                        break;
                }
            } while (lecturerChoice != 0); // Loop until lecturer chooses to return to main menu
        } else if (userType == 2) {
            viewCourses(courses); // View courses for students
        }

    } while (userType != 0); // Loop until user chooses to exit

    return 0; // Return 0 to indicate successful execution
}

// Function to display the lecturer menu
void showLecturerMenu() {
    cout << "\nLecturer Menu:\n"; // Display lecturer menu header
    cout << "1. Add Course\n"; // Option to add course
    cout << "2. Edit Course\n"; // Option to edit course
    cout << "0. Return to Main Menu\n"; // Option to return to main menu
}

// Function to display the student menu
void showStudentMenu() {
    cout << "\nStudent Menu:\n"; // Display student menu header
    cout << "Viewing courses...\n"; // Message indicating viewing courses
}

// Function to add a course
void addCourse(vector<Course>& courses) {
    Course newCourse; // Create a new course object
    cout << "Enter course name: "; // Prompt for course name
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, newCourse.courseName); // Get course name
    cout << "Enter lecturer name: "; // Prompt for lecturer name
    getline(cin, newCourse.lecturerName); // Get lecturer name
    cout << "Enter lecture venue: "; // Prompt for lecture venue
    getline(cin, newCourse.lectureVenue); // Get lecture venue
    cout << "Enter lecture time: "; // Prompt for lecture time
    getline(cin, newCourse.lectureTime); // Get lecture time
    cout << "Enter lecture date: "; // Prompt for lecture date
    getline(cin, newCourse.lectureDate); // Get lecture date
    courses.push_back(newCourse); // Add new course to the vector
    cout << "Course added successfully!\n"; // Success message
}

// Function to edit a course
void editCourse(vector<Course>& courses) {
    string courseName; // Variable to store course name to edit
    cout << "Enter course name to edit: "; // Prompt for course name
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, courseName); // Get course name
    for (auto& course : courses) { // Iterate through courses
        if (course.courseName == courseName) { // Check if course name matches
            cout << "Enter new lecturer name: "; // Prompt for new lecturer name
            getline(cin, course.lecturerName); // Get new lecturer name
            cout << "Enter new lecture venue: "; // Prompt for new lecture venue
            getline(cin, course.lectureVenue); // Get new lecture venue
            cout << "Enter new lecture time: "; // Prompt for new lecture time
            getline(cin, course.lectureTime); // Get new lecture time
            cout << "Enter new lecture date: "; // Prompt for new lecture date
            getline(cin, course.lectureDate); // Get new lecture date
            cout << "Course edited successfully!\n"; // Success message
            return; // Exit function
        }
    }
    cout << "Course not found.\n"; // Course not found message
}

// Function to view courses (for students)
void viewCourses(const vector<Course>& courses) {
    if (courses.empty()) { // Check if there are no courses
        cout << "No courses available.\n"; // No courses message
        return; // Exit function
    }
    for (const auto& course : courses) { // Iterate through courses
        cout << "Course Name: " << course.courseName << endl; // Display course name
        cout << "Lecturer Name: " << course.lecturerName << endl; // Display lecturer name
        cout << "Lecture Venue: " << course.lectureVenue << endl; // Display lecture venue
        cout << "Lecture Time: " << course.lectureTime << endl; // Display lecture time
        cout << "Lecture Date: " << course.lectureDate << endl; // Display lecture date
        cout << "-------------------------\n"; // Separator
    }
}

// Function to save courses to a file
void saveCoursesToFile(const vector<Course>& courses) {
    ofstream outFile("courses.txt"); // Open file for writing
    for (const auto& course : courses) { // Iterate through courses
        outFile << course.courseName << endl; // Write course name to file
        outFile << course.lecturerName << endl; // Write lecturer name to file
        outFile << course.lectureVenue << endl; // Write lecture venue to file
        outFile << course.lectureTime << endl; // Write lecture time to file
        outFile << course.lectureDate << endl; // Write lecture date to file
    }
    outFile.close(); // Close the file
}

// Function to load courses from a file
void loadCoursesFromFile(vector<Course>& courses) {
    ifstream inFile("courses.txt"); // Open file for reading
    if (!inFile) { // Check if file does not exist
        cout << "No saved courses found.\n"; // No saved courses message
        return; // Exit function
    }
    Course course; // Create a course object to store data
    while (getline(inFile, course.courseName)) { // Read course name from file
        getline(inFile, course.lecturerName); // Read lecturer name from file
        getline(inFile, course.lectureVenue); // Read lecture venue from file
        getline(inFile, course.lectureTime); // Read lecture time from file
        getline(inFile, course.lectureDate); // Read lecture date from file
        courses.push_back(course); // Add course to the vector
    }
    inFile.close(); // Close the file
}

