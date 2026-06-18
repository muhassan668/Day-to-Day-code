#include <iostream>

using namespace std;

void startSnakeGame();
void snakeBoardCreation(int**& board, int M, int N);
void displayBoard(int M, int N, int p1, int p2, int* snakes, int* ladders);
int playdice();
int checkSnakeHead(int pos, int* snakes);
int checkLeaderFoot(int pos, int* ladders);

int getPos(int r, int c, int M, int N);
unsigned int customRand();
void customSrand(unsigned int seed);

unsigned long long next_rand = 1;

int main() {
    startSnakeGame();
    return 0;
}
 
void customSrand(unsigned int seed) {
    next_rand = seed;
}

unsigned int customRand() {
    next_rand = next_rand * 1103515245 + 12345;
    return (unsigned int)((next_rand / 65536) % 32768);
}

void clearScreen() {
    for(int i=0; i<50; i++) cout << "\n";
}

void printFormatted(int num) {
    if (num < 10) cout << num << "   ";
    else if (num < 100) cout << num << "  ";
    else cout << num << " ";
}

void startSnakeGame() {
    int M, N;
    cout << "Enter rows (M): ";
    cin >> M;
    cout << "Enter columns (N): ";
    cin >> N;

    int seedInput;
    cout << "Enter any number to shuffle the board: ";
    cin >> seedInput;
    customSrand(seedInput);

    int** board = 0;
    snakeBoardCreation(board, M, N);

    int maxVal = M * N;
    
    int* snakes = new int[maxVal + 1];
    int* ladders = new int[maxVal + 1];

    for (int i = 0; i <= maxVal; i++) {
        snakes[i] = 0;
        ladders[i] = 0;
    }

    int count = 0;
    while (count < N - 1) {
        int head = (customRand() % (maxVal - 1)) + 2; 
        int tail = (customRand() % (head - 1)) + 1;   

        if (snakes[head] == 0 && ladders[head] == 0 && head != tail) {
            snakes[head] = tail;
            count++;
        }
    }

    count = 0;
    while (count < N - 1) {
        int top = (customRand() % (maxVal - 1)) + 2;
        int bottom = (customRand() % (top - 1)) + 1;

        if (ladders[bottom] == 0 && snakes[bottom] == 0 && top != bottom) {
            ladders[bottom] = top;
            count++;
        }
    }

    int p1 = 1, p2 = 1; 
    bool p1Started = false; 
    bool p2Started = false;
    int turn = 1;
    char temp;

    while (p1 < maxVal && p2 < maxVal) {
        clearScreen();
        cout << "--- SNAKE AND LADDER GAME ---\n";
        displayBoard(M, N, p1, p2, snakes, ladders);
        
        cout << "\nPlayer " << turn << "'s turn.\nPress Enter to roll dice...";
        cin.get(temp); 

        int dice = playdice();
        cout << "Player " << turn << " rolled a " << dice << endl;

        if (turn == 1) {
            if (!p1Started) {
                if (dice == 6) {
                    p1Started = true;
                    cout << "Player 1 enters the game!" << endl;
                } else {
                    cout << "Need a 6 to start." << endl;
                }
            } else {
                if (p1 + dice <= maxVal) {
                    p1 += dice;
                    int newPos = checkSnakeHead(p1, snakes);
                    if (newPos != p1) p1 = newPos;
                    else {
                        newPos = checkLeaderFoot(p1, ladders);
                        if (newPos != p1) p1 = newPos;
                    }
                }
            }
            if (p1 == maxVal) {
                cout << "\n*** Player 1 Wins! ***" << endl;
                break;
            }
            turn = 2; 
        } 
        else {
            if (!p2Started) {
                if (dice == 6) {
                    p2Started = true;
                    cout << "Player 2 enters the game!" << endl;
                } else {
                    cout << "Need a 6 to start." << endl;
                }
            } else {
                if (p2 + dice <= maxVal) {
                    p2 += dice;
                    int newPos = checkSnakeHead(p2, snakes);
                    if (newPos != p2) p2 = newPos;
                    else {
                        newPos = checkLeaderFoot(p2, ladders);
                        if (newPos != p2) p2 = newPos;
                    }
                }
            }
            if (p2 == maxVal) {
                cout << "\n*** Player 2 Wins! ***" << endl;
                break;
            }
            turn = 1; 
        }
        
        cout << "Press Enter to continue...";
        cin.get(temp);
    }

    for (int i = 0; i < M; i++) {
        delete[] board[i];
    }
    delete[] board;
    delete[] snakes;
    delete[] ladders;
}

void snakeBoardCreation(int**& board, int M, int N) {
    board = new int*[M];
    for (int i = 0; i < M; i++) {
        board[i] = new int[N];
    }
}

int getPos(int r, int c, int M, int N) {
    int rowFromBottom = M - 1 - r;
    
    int pos;
    if (rowFromBottom % 2 == 0) {
        pos = rowFromBottom * N + c + 1;
    } else {
        pos = rowFromBottom * N + (N - 1 - c) + 1;
    }
    return pos;
}

void displayBoard(int M, int N, int p1, int p2, int* snakes, int* ladders) {
    for (int k = 0; k < N; k++) cout << "------";
    cout << "-" << endl;

    for (int i = 0; i < M; i++) {
        cout << "|";
        for (int j = 0; j < N; j++) {
            int pos = getPos(i, j, M, N);
            
            bool isP1 = (pos == p1);
            bool isP2 = (pos == p2);

            if (isP1 && isP2) {
                cout << " P1P2";
            } else if (isP1) {
                cout << "  P1 ";
            } else if (isP2) {
                cout << "  P2 ";
            } else {
                if (snakes[pos] != 0) {
                    cout << " S";
                    printFormatted(snakes[pos]); 
                }
                else if (ladders[pos] != 0) {
                    cout << " L";
                    printFormatted(ladders[pos]); 
                } 
                else {
                    cout << " ";
                    printFormatted(pos);
                }
            }
            cout << "|";
        }
        cout << endl;
        for (int k = 0; k < N; k++) cout << "------";
        cout << "-" << endl;
    }
}

int playdice() {
    return (customRand() % 6) + 1;
}

int checkSnakeHead(int pos, int* snakes) {
    if (snakes[pos] != 0) {
        cout << " -> oops, snake got you!!! Down to " << snakes[pos] << endl;
        return snakes[pos];
    }
    return pos;
}

int checkLeaderFoot(int pos, int* ladders) {
    if (ladders[pos] != 0) {
        cout << " -> you got lucky. Up to " << ladders[pos] << endl;
        return ladders[pos];
    }
    return pos;
}
