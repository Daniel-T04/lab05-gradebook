// src/grading.cpp
#include "grading.h"

#include <algorithm>

#include "utilities.h"

double student_average(const Student& student) {
    double sum = 0.0;
    // Total the assignment scores for this student
    for (int i = 0; i < assignment_count; ++i) {
        sum += student.scores[i];
    }

    return sum / assignment_count;
}

double assignment_average(const Student* roster, int roster_count, 
int assignment_index) {
    double sum = 0.0;

    // Total this assignment's score down every student row
    for (int i = 0; i < roster_count; ++i) {
        sum += roster[i].scores[assignment_index];
    }

    return sum / roster_count;
}

double class_average(const Student* roster, int roster_count)  {
    double sum = 0.0;

   for (int  i = 0; i < roster_count; ++i) {
            sum += student_average(roster[i]);
        }

    return sum / roster_count;
}

void find_extremes(const Student& student, double& lowest, 
double& highest) {
    // Start from a real score so the result is correct for any range of
    // values, including all-negative ones
    lowest = student.scores[0];
    highest = student.scores[0];
    for (int i = 1; i < assignment_count; ++i) {
        if (student.scores[i] < lowest) lowest = student.scores[i];
        if (student.scores[i] > highest) highest = student.scores[i];
    }
}

int count_grade(const Student* roster, int roster_count, char target) {
    int count = 0;

    for (int i = 0; i < roster_count; ++i) {
        double avg = student_average(roster[i]);
        char grade = 'F';
        if (avg >= 90) grade = 'A';
        else if (avg >= 80) grade = 'B';
        else if (avg >= 70) grade = 'C';
        else if (avg >= 60) grade = 'D';

        if (grade == target) count++;
    }
    return count;
}

bool has_perfect_score(const Student& student) {
    
    for (int i = 0; i < assignment_count; ++i) {
        if (student.scores[i] >= 100.0) {
            return true;
        }
    }
    return false;

 }
bool is_at_risk(const Student& student) {
    
    if (student_average(student) < 70.0) {
        return true;
    }

    for (int i = 0; i < assignment_count; ++i) {
        if (student.scores[i] < 50.0) {
            return true;
        }
    }

    return false;
} 
