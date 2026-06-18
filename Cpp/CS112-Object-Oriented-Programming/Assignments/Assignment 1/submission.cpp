// Muhammad Hassan 2025537 assignment#1

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Return length of a C-style char array
int str_length(char* str) {
    int count = 0;
    for (; str[count] != '\0'; ++count) {
        // loop until null terminator
    }
    return count;
}

// Find first normal (non-circular) occurrence of substring in paragraph
int find_substring_index(char* text, char* target) {
    int lenText = str_length(text);
    int lenTarget = str_length(target);

    if (lenTarget == 0) return 0;
    if (lenTarget > lenText) return -1;

    for (int idx = 0; idx <= lenText - lenTarget; ++idx) {
        int matchCount = 0;
        while (matchCount < lenTarget && text[idx + matchCount] == target[matchCount]) {
            matchCount++;
        }
        if (matchCount == lenTarget) {
            return idx;
        }
    }
    return -1;
}

// Task 1.1: remove first occurrence of input from Para
char* removeSentence(char* mainStr, char* toRemove) {
    int matchPos = find_substring_index(mainStr, toRemove);

    if (matchPos == -1) return mainStr;

    int totalLen = str_length(mainStr);
    int removeLen = str_length(toRemove);
    
    if (removeLen == 0) return mainStr;

    char* modifiedStr = new char[totalLen - removeLen + 1];

    int srcIdx = 0;
    int destIdx = 0;
    
    while (mainStr[srcIdx] != '\0') {
        if (srcIdx == matchPos) {
            srcIdx += removeLen; 
        } else {
            modifiedStr[destIdx++] = mainStr[srcIdx++];
        }
    }
    modifiedStr[destIdx] = '\0';
    return modifiedStr;
}

// Task 1.2: circular substring search
bool FindSubString(char* source, char* pattern, int & start, int & end) {
    int srcLen = str_length(source);
    int patLen = str_length(pattern);

    if (patLen == 0) {
        start = 0;
        end = -1;
        return true;
    }

    if (srcLen == 0 || patLen > srcLen) {
        start = -1;
        end = -1;
        return false;
    }

    for (int beginIdx = 0; beginIdx < srcLen; ++beginIdx) {
        int offset = 0;
        for (; offset < patLen; ++offset) {
            int circularPos = (beginIdx + offset) % srcLen;
            if (source[circularPos] != pattern[offset]) {
                break;
            }
        }

        if (offset == patLen) {
            start = beginIdx;
            end = (beginIdx + patLen - 1) % srcLen;
            return true;
        }
    }

    start = -1;
    end = -1;
    return false;
}

//helper (task2_1)
int calculateDivisorsSum(int num, int div = 1) {
    if (div == num) return 0;

    if (num % div == 0) {
        return div + calculateDivisorsSum(num, div + 1);
    }

    return calculateDivisorsSum(num, div + 1);
}

//task2_1
bool isperfectNumber(int val) {
    if (val <= 1) return false;
    return (calculateDivisorsSum(val, 1) == val);
}

//task2_2
int findVowels(char* text) {
    if (*text == '\0') return 0;

    int isVowel = 0;
    char ch = *text;
    
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || 
        ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || 
        ch == 'u' || ch == 'U') {
        isVowel = 1;
    }

    return isVowel + findVowels(text + 1);
}

//task2_3
int pascal(int r, int c) {
    if (c > r || r < 0 || c < 0) {
        return -1;
    }

    if (c == 0 || c == r) {
        return 1;
    }

    return pascal(r - 1, c - 1) + pascal(r - 1, c);
}

//helper (task2_4)
void printSpace(int count) {
    if (count <= 0) return;
    cout << " ";
    printSpace(count - 1);
}

//task2_4
void PrintPattern1(int curr, int limit) {
    if (curr > (limit - curr)) return;

    printSpace(limit - 2 * curr);
    cout << "*" << endl;

    PrintPattern1(curr + 1, limit);

    if (limit - 2 * curr != 0) {
        printSpace(limit - 2 * curr);
        cout << "*" << endl;
    }
}

//helper1(task2_5)
void printAsterisks(int maxStars, int drawnStars) {
    if (maxStars == drawnStars) {
        return;
    }
    printAsterisks(maxStars - 1, drawnStars);
    cout << " *";
}

//helper2(task2_5)
void printSpaces(int spacesLeft) {
    if (spacesLeft == 0) {
        return;
    }
    printSpaces(spacesLeft - 1);
    cout << "  "; 
}

//helper3(task2_5)
void printRow(int maxSize, int lineNum) {
    if (lineNum == 0) {
        return;
    }
    printRow(maxSize, lineNum - 1);
    
    if (lineNum <= maxSize) {
        printAsterisks(maxSize, lineNum - 1);
        printSpaces((lineNum - 1) * 2);
        printAsterisks(maxSize, lineNum - 1);
        cout << endl;
    } else {
        int mirroredLine = (2 * maxSize) - lineNum;
        printAsterisks(maxSize, mirroredLine);
        printSpaces(mirroredLine * 2);
        printAsterisks(maxSize, mirroredLine);
        cout << endl;
    }
}

//task2_5
void printHollowDiamond(int size) {
    printRow(size, size * 2);
}

//helper functions (task2_6)
void printspace(int spc) {
    if (spc <= 0) return;
    cout << "  "; 
    printspace(spc - 1);
}

void printHash() {
    cout << "# ";
}

void printDash(int dots) {
    if (dots <= 0) return;
    cout << ". ";
    printDash(dots - 1);
}

void printStar(int st) {
    if (st <= 0) return;
    cout << "* * ";
    printStar(st - 1);
}

//task2_6
void PrintPattern2(int begin, int stop) {
    if (stop <= (begin - stop)) return;

    printspace(stop - (begin - stop));
    printHash();
    printDash(stop - (begin - stop));
    printStar(begin - stop);
    cout << "| ";
    printStar(begin - stop);
    printDash(stop - (begin - stop));
    printHash();
    cout << endl;

    PrintPattern2(begin + 1, stop);

    if (begin - 2 * stop != -1) {
        printspace(stop - (begin - stop));
        printHash();
        printDash(stop - (begin - stop));
        printStar(begin - stop);
        cout << "| ";
        printStar(begin - stop);
        printDash(stop - (begin - stop));
        printHash();
        cout << endl;
    }
}

//task3

/* -------------------- Data structures -------------------- */
struct Snake {
    int head, tail;
};

struct Ladder {
    int bottom, top;
};

/* -------------------- Small helper functions -------------------- */
void waitForEnter() {
    cout << "Press ENTER to roll...";
    cin.get();
}

bool usedInPairs(int arr1[], int arr2[], int size, int val) {
    for (int idx = 0; idx < size; ++idx) {
        if (arr1[idx] == val || arr2[idx] == val) return true;
    }
    return false;
}

bool usedEverywhere(
    int snkH[], int snkT[], int snkSize,
    int ladB[], int ladT[], int ladSize,
    int pos
) {
    return usedInPairs(snkH, snkT, snkSize, pos) ||
           usedInPairs(ladB, ladT, ladSize, pos);
}

/* -------------------- Board mapping (zig-zag numbering) -------------------- */
int cellFromRowColBottomBased(int rowId, int colId, int totalCols) {
    if (rowId % 2 == 0) {
        return rowId * totalCols + colId + 1;
    }
    return rowId * totalCols + (totalCols - colId);
}

/* -------------------- Generate snakes and ladders -------------------- */
void generateSnakes(int numSnakes, int maxCells, int snkH[], int snkT[], int ladB[], int ladT[], int ladSize) {
    int created = 0;
    while (created < numSnakes) {
        int headPos = rand() % (maxCells - 2) + 2;
        int tailPos = rand() % (headPos - 1) + 1;

        if (headPos <= tailPos || headPos == maxCells) continue;
        if (usedEverywhere(snkH, snkT, created, ladB, ladT, ladSize, headPos)) continue;
        if (usedEverywhere(snkH, snkT, created, ladB, ladT, ladSize, tailPos)) continue;

        snkH[created] = headPos;
        snkT[created] = tailPos;
        created++;
    }
}

void generateLadders(int numLadders, int maxCells, int snkH[], int snkT[], int snkSize, int ladB[], int ladT[]) {
    int created = 0;
    while (created < numLadders) {
        int bottomPos = rand() % (maxCells - 2) + 1;
        int topPos = rand() % (maxCells - bottomPos - 1) + bottomPos + 1;

        if (topPos <= bottomPos) continue;
        if (usedEverywhere(snkH, snkT, snkSize, ladB, ladT, created, bottomPos)) continue;
        if (usedEverywhere(snkH, snkT, snkSize, ladB, ladT, created, topPos)) continue;

        ladB[created] = bottomPos;
        ladT[created] = topPos;
        created++;
    }
}

/* -------------------- Snake/Ladder lookup -------------------- */
int snakeAt(int currPos, int snkH[], int snkT[], int snkSize) {
    for (int idx = 0; idx < snkSize; ++idx) {
        if (snkH[idx] == currPos) return snkT[idx];
    }
    return -1;
}

int ladderAt(int currPos, int ladB[], int ladT[], int ladSize) {
    for (int idx = 0; idx < ladSize; ++idx) {
        if (ladB[idx] == currPos) return ladT[idx];
    }
    return -1;
}

/* -------------------- Display board -------------------- */
void displayBoard(int rows, int cols, int posPlayer1, int posPlayer2) {
    cout << "\n================ BOARD ================\n";

    for (int r = rows - 1; r >= 0; r--) {
        for (int c = 0; c < cols; c++) {
            int cellId = cellFromRowColBottomBased(r, c, cols);

            if (cellId == posPlayer1 && cellId == posPlayer2) {
                cout << "[" << cellId << ":P1,P2]\t";
            } else if (cellId == posPlayer1) {
                cout << "[" << cellId << ":P1]\t";
            } else if (cellId == posPlayer2) {
                cout << "[" << cellId << ":P2]\t";
            } else {
                cout << "[" << cellId << "]\t";
            }
        }
        cout << "\n";
    }
    cout << "=======================================\n";
}

/* -------------------- Apply one player turn -------------------- */
void applyTurn(
    int pId, int rollVal, int totalCells,
    int &currentPos, bool &hasStarted,
    int snkH[], int snkT[], int snkSize,
    int ladB[], int ladT[], int ladSize
) {
    cout << "Player " << pId << " rolled: " << rollVal << "\n";

    if (!hasStarted) {
        if (rollVal == 6) {
            hasStarted = true;
            currentPos = 1;
            cout << "Player " << pId << " entered board at cell 1.\n";
        } else {
            cout << "Player " << pId << " needs 6 to start.\n";
        }
        return;
    }

    int proposedPos = currentPos + rollVal;

    if (proposedPos <= totalCells) {
        currentPos = proposedPos;
    } else {
        cout << "Player " << pId << " move skipped (beyond " << totalCells << ").\n";
        return;
    }

    int snakeDest = snakeAt(currentPos, snkH, snkT, snkSize);
    if (snakeDest != -1) {
        cout << "Player " << pId << ": Oops! Snake (" << currentPos << " -> " << snakeDest << ")\n";
        currentPos = snakeDest;
        return;
    }

    int ladderDest = ladderAt(currentPos, ladB, ladT, ladSize);
    if (ladderDest != -1) {
        cout << "Player " << pId << ": Lucky! Ladder (" << currentPos << " -> " << ladderDest << ")\n";
        currentPos = ladderDest;
    }
}

/* -------------------- Main game controller -------------------- */
void startSnakeGame() {
    int rCount, cCount;
    cout << "Enter board rows (M) and columns (N): ";
    cin >> rCount >> cCount;
    cin.ignore();

    if (rCount < 2 || cCount < 2) {
        cout << "Invalid board size.\n";
        return;
    }

    int maxCells = rCount * cCount;
    int entityCount = cCount - 1;

    int *snkHeads = new int[entityCount];
    int *snkTails = new int[entityCount];
    int *ladBottoms = new int[entityCount];
    int *ladTops = new int[entityCount];

    srand((unsigned)time(0)); 

    generateSnakes(entityCount, maxCells, snkHeads, snkTails, ladBottoms, ladTops, 0);
    generateLadders(entityCount, maxCells, snkHeads, snkTails, entityCount, ladBottoms, ladTops);

    int posP1 = 0, posP2 = 0;
    bool startedP1 = false, startedP2 = false;
    int activePlayer = 1;

    cout << "\n=== 2-Player Snake & Ladder Started ===\n";
    cout << "Rule: each player needs 6 to start.\n";

    while (true) {
        displayBoard(rCount, cCount, posP1, posP2);

        waitForEnter();
        int roll = rand() % 6 + 1;

        if (activePlayer == 1) {
            applyTurn(1, roll, maxCells, posP1, startedP1, snkHeads, snkTails, entityCount, ladBottoms, ladTops, entityCount);
            activePlayer = 2;
        } else {
            applyTurn(2, roll, maxCells, posP2, startedP2, snkHeads, snkTails, entityCount, ladBottoms, ladTops, entityCount);
            activePlayer = 1;
        }

        cout << "Position: P1=" << posP1 << " , P2=" << posP2 << "\n";

        if (posP1 == maxCells) {
            cout << "\nPlayer 1 wins!\n";
            break;
        }
        if (posP2 == maxCells) {
            cout << "\nPlayer 2 wins!\n";
            break;
        }
    }

    delete[] snkHeads;
    delete[] snkTails;
    delete[] ladBottoms;
    delete[] ladTops;
}