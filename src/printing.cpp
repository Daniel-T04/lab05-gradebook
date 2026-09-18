// src/printing.cpp
#include "printing.h"

#include <iomanip>
#include <iostream>
#include <string>

#include "grading.h"
#include "utilities.h"

void print_header(const int num_students, const int num_assignments) {
    std::cout << pad_name("STUDENT", num_students);

    for (auto i{0}; i < num_assignments; i++) {
        std::cout << std::setw(5) << "A" << i;
    }

    std::cout << std::setw(8) << "AVG" << std::setw(6) << "GRADE" << '\n';

    for (auto i{0}; i < 60; i++) {
        std::cout << '-';
    }

    std::cout << '\n';
}

void print_student_row(const Student& student) {

    std::cout << std::left << std::setw(12) << student.name;
    for (int j = 0; j < assignment_count; ++j) {
        std::cout << std::right << std::setw(8) << std::fixed << std::setprecision(1) << student.scores[j];
    }
    std::cout << std::right << std::setw(10) << std::fixed << std::setprecision(2) << student_average(student);
    if (is_at_risk(student)) {
        std::cout << "  [AT RISK]";
    }
    std::cout << "\n";

}

void print_histogram(const Student* roster, int roster_count) {
    const char grades[] = {'A', 'B', 'C', 'D', 'F'};
    for (char g : grades) {
        int count = count_grade(roster, roster_count, g);
        std::cout << g << ": " << std::string(count, '*') << "\n";
        }
    
    }

void print_assignment_summary(const Student* roster, int roster_count) {
    
    for (int j = 0; j < assignment_count; ++j){
        double avg = assignment_average(roster, roster_count, j);
        std::cout << "Assignent  " << (j + 1) << " Average: "
        << std::fixed << std::setprecision(2) << avg << "\n";
       }
     }


void print_roster(const Student* roster, int roster_count) {
    std::cout << "\nROSTER\n";
    // names is a pointer to the first element; it carries no size of its
    // own, so name_count is how far we are permitted to walk
    for ( int i = 0; i < roster_count; ++i) {
        print_student_row(roster[i]);
    }
 }                                                         
