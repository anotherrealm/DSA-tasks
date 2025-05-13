#include <stdio.h>
#include <string.h>

// Course information
typedef struct {
    char code[10];  // Like "CS101"
    char name[50];  // Like "Programming"
} Course;

// Grade information
typedef struct {
    int mark;       // 0-100
    char grade;     // A-E
    int is_locked;  // 0 = can change, 1 = fixed
} Grade;

// Full student record
typedef struct {
    char id[20];    // Registration number
    char name[50];
    int age;
    Course course;
    Grade grades;
} Student;

// Calculate grade from marks
void calculate_grade(Student *s) {
    if(s->grades.is_locked) {
        printf("Grades already finalized!\n");
        return;
    }
    
    if(s->grades.mark >= 70) s->grades.grade = 'A';
    else if(s->grades.mark >= 60) s->grades.grade = 'B';
    else if(s->grades.mark >= 50) s->grades.grade = 'C';
    else if(s->grades.mark >= 40) s->grades.grade = 'D';
    else s->grades.grade = 'E';
    
    s->grades.is_locked = 1; // Lock after calculation
}

// Print student details
void print_student(Student s) {
    printf("\nStudent ID: %s\n", s.id);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Course: %s (%s)\n", s.course.name, s.course.code);
    printf("Mark: %d\n", s.grades.mark);
    printf("Grade: %c\n", s.grades.grade);
}

int main() {
    // Here I created a sample course
    Course cs101 = {"CS101", "Introduction to Programming"};
    
    // New student
    Student student1;
    strcpy(student1.id, "2023/0001");
    strcpy(student1.name, "John Mwangi");
    student1.age = 20;
    student1.course = cs101;
    student1.grades.mark = 65;  // Set initial mark
    student1.grades.is_locked = 0; // Grades can be changed
    
    // Calculate and print
    calculate_grade(&student1);
    print_student(student1);
    
    return 0;
}