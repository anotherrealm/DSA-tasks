#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char unitTag[20];
    char unitName[50];
} AcademicUnit;

typedef struct {
    int scoreVal;
    char assignedGrade;
} AssessmentResult;

typedef struct {
    char studentId[20];
    char fullName[50];
    int currentAge;
    AcademicUnit primaryUnit;
    AssessmentResult overallResult;
} CampoLearner; // 

typedef struct LearnerEntry {
    CampoLearner learnerData; 
    struct LearnerEntry* nextEntry;
} LearnerEntryNode;

LearnerEntryNode* startNode = NULL;

char compute_grade(int inputScore) {
    if (inputScore >= 70) return 'A';
    if (inputScore >= 60) return 'B';
    if (inputScore >= 50) return 'C';
    if (inputScore >= 40) return 'D';
    return 'F';
}

void add_learner_record(CampoLearner newLearner) { 
    LearnerEntryNode* newNode = (LearnerEntryNode*)malloc(sizeof(LearnerEntryNode));
    newNode->learnerData = newLearner;
    newNode->learnerData.overallResult.assignedGrade = compute_grade(newLearner.overallResult.scoreVal);
    newNode->nextEntry = startNode;
    startNode = newNode;
}

void show_all_records() {
    LearnerEntryNode* current = startNode;
    while (current != NULL) {
        printf("ID: %s, Name: %s, Score: %d, Grade: %c, Unit: %s\n",
               current->learnerData.studentId,
               current->learnerData.fullName,
               current->learnerData.overallResult.scoreVal,
               current->learnerData.overallResult.assignedGrade,
               current->learnerData.primaryUnit.unitName);
        current = current->nextEntry;
    }
}

int main() {
    AcademicUnit compUnit = {"COMP101", "Introduction to C"};
    AcademicUnit mathUnit = {"MATH201", "Linear Algebra"};
    AcademicUnit physUnit = {"PHYS105", "Classical Mechanics"};
    AcademicUnit chemUnit = {"CHEM101", "General Chemistry"};
    AcademicUnit artsUnit = {"ARTS100", "Art History"};

    CampoLearner learnerOne = {"ST001", "Jane Doe", 20, compUnit, {82, ' '}};
    CampoLearner learnerTwo = {"ST002", "John Smith", 21, mathUnit, {70, ' '}};
    CampoLearner learnerThree = {"ST003", "Emily White", 22, physUnit, {63, ' '}};
    CampoLearner learnerFour = {"ST004", "David Brown", 23, chemUnit, {51, ' '}};
    CampoLearner learnerFive = {"ST005", "Olivia Green", 24, artsUnit, {35, ' '}};

    add_learner_record(learnerOne);
    add_learner_record(learnerTwo);
    add_learner_record(learnerThree);
    add_learner_record(learnerFour);
    add_learner_record(learnerFive);

    show_all_records();

    return 0;
}
