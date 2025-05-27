#include <iostream>

class ScoreEntry {
private:
    int points;

public:
    ScoreEntry() : points(0) {}
    ScoreEntry(int p) : points(p) {}

    int getPoints() const { return points; }
    void setPoints(int p) { points = p; }

    void showInfo() const {
        std::cout << "Entry Score: " << points << std::endl;
    }
};

class ElementNode {
public:
    ScoreEntry itemData;
    ElementNode* nextElement;

    ElementNode(ScoreEntry entry) : itemData(entry), nextElement(nullptr) {}
};

class ScoreList {
private:
    ElementNode* listHead;

public:
    ScoreList() : listHead(nullptr) {}

    void prepend(ScoreEntry newEntry) {
        ElementNode* newNode = new ElementNode(newEntry);
        newNode->nextElement = listHead;
        listHead = newNode;
    }

    void displayAll() {
        ElementNode* current = listHead;
        while (current != nullptr) {
            current->itemData.showInfo();
            current = current->nextElement;
        }
    }
};

int main() {
    ScoreList myScoreRecords;

    ScoreEntry scoreA(90);
    ScoreEntry scoreB(75);
    ScoreEntry scoreC(60);

    myScoreRecords.prepend(scoreA);
    myScoreRecords.prepend(scoreB);
    myScoreRecords.prepend(scoreC);

    myScoreRecords.displayAll();

    return 0;
}