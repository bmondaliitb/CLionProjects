#include <iostream>   // Required for console input/output (std::cout, std::endl)
#include <optional>   // Required for std::optional
#include <string>     // Required for std::string
#include <map>        // Required for std::map (to store student IDs and grades)

// Simulate a database of student grades
std::map<int, int> student_grades = {
    {101, 95},
    {102, 88},
    {103, 72},
    {104, 91}
};

/**
 * @brief Looks up a student's grade by their ID.
 *
 * This function demonstrates returning an std::optional<int>.
 * If the student ID is found, it returns an optional containing their grade.
 * If the student ID is not found, it returns an empty (disengaged) optional.
 *
 * @param student_id The ID of the student to look up.
 * @return An std::optional<int> potentially containing the student's grade.
 */
std::optional<int> get_student_grade(int student_id) {
    // Attempt to find the student_id in our map
    auto it = student_grades.find(student_id);

    // Check if the iterator is at the end, meaning the ID was not found
    if (it != student_grades.end()) {
        // Student found: return an optional engaged with their grade
        return it->second;
    } else {
        // Student not found: return an empty optional
        return std::nullopt; // std::nullopt explicitly indicates no value
        // Alternatively, you could just 'return {};' for an empty optional
    }
}

int main() {
    std::cout << "--- Demonstrating std::optional ---" << std::endl << std::endl;

    // --- Scenario 1: Student exists ---
    int student_id_1 = 102;
    std::cout << "Attempting to find grade for student ID: " << student_id_1 << std::endl;
    std::optional<int> grade1 = get_student_grade(student_id_1);

    // Method A: Check using has_value() and then access with * (dereference)
    if (grade1.has_value()) {
        std::cout << "  Method A: Found grade: " << *grade1 << std::endl;
    } else {
        std::cout << "  Method A: Grade not found." << std::endl;
    }

    // Method B: Check using implicit boolean conversion and then access with .value()
    // Using .value() after checking ensures safety, though * is also common.
    if (grade1) { // Implicit conversion to bool checks if it has a value
        std::cout << "  Method B: Found grade: " << grade1.value() << std::endl;
    } else {
        std::cout << "  Method B: Grade not found." << std::endl;
    }

    // Method C: Using value_or() for a safe default value
    // This is often the most concise and safest way to get a value or a default.
    int final_grade_1 = grade1.value_or(-1); // Use -1 as a default if grade is not found
    std::cout << "  Method C: Final grade (or -1 if not found): " << final_grade_1 << std::endl;

    std::cout << std::endl; // Newline for separation

    // --- Scenario 2: Student does not exist ---
    int student_id_2 = 999;
    std::cout << "Attempting to find grade for student ID: " << student_id_2 << std::endl;
    std::optional<int> grade2 = get_student_grade(student_id_2);

    // Method A: Check using has_value()
    if (grade2.has_value()) {
        std::cout << "  Method A: Found grade: " << *grade2 << std::endl;
    } else {
        std::cout << "  Method A: Grade not found." << std::endl;
    }

    // Method B: Check using implicit boolean conversion
    if (grade2) {
        std::cout << "  Method B: Found grade: " << grade2.value() << std::endl;
    } else {
        std::cout << "  Method B: Grade not found." << std::endl;
    }

    // Method C: Using value_or()
    int final_grade_2 = grade2.value_or(0); // Use 0 as a default if grade is not found
    std::cout << "  Method C: Final grade (or 0 if not found): " << final_grade_2 << std::endl;

    std::cout << std::endl; // Newline for separation

    // --- Scenario 3: Demonstrating unsafe access (will likely crash if uncommented) ---
    // If you uncomment the line below and run the program, it will terminate
    // because you are trying to access the value of an empty optional using .value().
    // try {
    //     std::cout << "Unsafe access attempt: " << grade2.value() << std::endl;
    // } catch (const std::bad_optional_access& e) {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    // }

    std::cout << "--- End of std::optional demonstration ---" << std::endl;

    return 0; // Indicate successful execution
}