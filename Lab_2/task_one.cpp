#include <iostream>
#include <string>

using namespace std;

// Represents an academic unit
class UnitInfo {
public:
    string unitCode;
    string unitTitle;

    UnitInfo() {}
    UnitInfo(string code, string title) : unitCode(code), unitTitle(title) {}
};

// Stores a student's score and assigns a letter grade
class AssessmentScore {
private:
    int pointsAchieved;
    char finalGrade;

public:
    AssessmentScore() : pointsAchieved(0), finalGrade('F') {}

    void setPoints(int p) {
        pointsAchieved = p;
        if (pointsAchieved >= 70) finalGrade = 'A';
        else if (pointsAchieved >= 60) finalGrade = 'B';
        else if (pointsAchieved >= 50) finalGrade = 'C';
        else if (pointsAchieved >= 40) finalGrade = 'D';
        else finalGrade = 'F';
    }

    int getPoints() const { return pointsAchieved; }
    char getFinalGrade() const { return finalGrade; }
};

// Defines a learner with personal and academic details
class CampusLearner {
private:
    string studentID;
    string studentName;
    int studentAge;
    UnitInfo enrolledUnit;
    AssessmentScore unitScore;

public:
    CampusLearner() {}
    CampusLearner(string id, string name, int age, UnitInfo unit)
        : studentID(id), studentName(name), studentAge(age), enrolledUnit(unit) {}

    void setUnitPoints(int p) { unitScore.setPoints(p); }
    int getUnitPoints() const { return unitScore.getPoints(); }
    void setStudentID(string id) { studentID = id; }
    string getStudentID() const { return studentID; }
    void setStudentName(string name) { studentName = name; }
    string getStudentName() const { return studentName; }
    void setStudentAge(int age) { studentAge = age; }
    int getStudentAge() const { return studentAge; }
    void setEnrolledUnit(UnitInfo unit) { enrolledUnit = unit; }
    UnitInfo getEnrolledUnit() const { return enrolledUnit; }
    void setUnitAssessment(AssessmentScore score) { unitScore = score; }
    AssessmentScore getUnitAssessment() const { return unitScore; }

    void displayLearnerDetails() const {
        cout << "ID: " << studentID << ", Name: " << studentName
             << ", Age: " << studentAge << ", Unit: " << enrolledUnit.unitTitle
             << ", Score: " << unitScore.getPoints()
             << ", Grade: " << unitScore.getFinalGrade() << endl;
    }
};

#define MAX_ENTRIES 45 // Slightly different maximum capacity

// Manages a collection of CampusLearner objects
class LearnerRecords {
private:
    int currentEntryCount;
    CampusLearner learnerEntries[MAX_ENTRIES];

public:
    LearnerRecords() : currentEntryCount(0) {}

    LearnerRecords(CampusLearner learner) : currentEntryCount(1) {
        learnerEntries[0] = learner;
    }

    LearnerRecords(const LearnerRecords& otherRecords) {
        currentEntryCount = otherRecords.currentEntryCount;
        for (int i = 0; i < currentEntryCount; i++) {
            learnerEntries[i] = otherRecords.learnerEntries[i];
        }
    }

    void addLearner(CampusLearner learner) {
        if (currentEntryCount < MAX_ENTRIES) {
            learnerEntries[currentEntryCount++] = learner;
        } else {
            cout << "Records are full!" << endl;
        }
    }

    void insertLearnerAt(CampusLearner learner, int position) {
        if (currentEntryCount < MAX_ENTRIES && position >= 0 && position <= currentEntryCount) {
            for (int i = currentEntryCount; i > position; i--) {
                learnerEntries[i] = learnerEntries[i - 1];
            }
            learnerEntries[position] = learner;
            currentEntryCount++;
        } else {
            cout << "Invalid position or records full!" << endl;
        }
    }

    void removeLearner(CampusLearner learnerToRemove) {
        for (int i = 0; i < currentEntryCount; i++) {
            if (learnerEntries[i].getStudentID() == learnerToRemove.getStudentID()) {
                for (int j = i; j < currentEntryCount - 1; j++) {
                    learnerEntries[j] = learnerEntries[j + 1];
                }
                currentEntryCount--;
                return;
            }
        }
    }

    void removeLearnerAt(int position) {
        if (position >= 0 && position < currentEntryCount) {
            for (int i = position; i < currentEntryCount - 1; i++) {
                learnerEntries[i] = learnerEntries[i + 1];
            }
            currentEntryCount--;
        }
    }

    int getEntryCount() const {
        return currentEntryCount;
    }

    void clearAllRecords() {
        currentEntryCount = 0;
    }

    CampusLearner& retrieveLearner(int index) {
        return learnerEntries[index];
    }

    void printAllLearners() {
        for (int i = 0; i < currentEntryCount; i++) {
            learnerEntries[i].displayLearnerDetails();
        }
    }
};

int main() {
    UnitInfo programmingUnit("COMP202", "Object-Oriented Programming");
    LearnerRecords studentDatabase;

    for (int i = 0; i < 16; i++) {
        string identifier = "STD" + to_string(202400 + i);
        CampusLearner currentStudent(identifier, "User" + to_string(i + 1), 19 + (i % 3), programmingUnit);
        currentStudent.setUnitPoints(50 + i * 2); // Varying scores
        studentDatabase.addLearner(currentStudent);
    }

    cout << "\n--- All Current Learners in Database ---" << endl;
    studentDatabase.printAllLearners();

    cout << "\nTotal Learners: " << studentDatabase.getEntryCount() << endl;

    // Add a new learner at a specific position
    CampusLearner freshEntry("STD202499", "New Face", 18, programmingUnit);
    freshEntry.setUnitPoints(92);
    studentDatabase.insertLearnerAt(freshEntry, 3);

    cout << "\n--- Database After Adding a New Learner ---" << endl;
    studentDatabase.printAllLearners();
    cout << "\nTotal Learners: " << studentDatabase.getEntryCount() << endl;

    // Remove a learner by object
    CampusLearner toDelete("STD202405", "User6", 21, programmingUnit);
    studentDatabase.removeLearner(toDelete);

    cout << "\n--- Database After Removing a Learner ---" << endl;
    studentDatabase.printAllLearners();
    cout << "\nTotal Learners: " << studentDatabase.getEntryCount() << endl;

    // Remove a learner at a specific index
    studentDatabase.removeLearnerAt(0);

    cout << "\n--- Database After Removing the First Entry ---" << endl;
    studentDatabase.printAllLearners();
    cout << "\nTotal Learners: " << studentDatabase.getEntryCount() << endl;

    return 0;
}