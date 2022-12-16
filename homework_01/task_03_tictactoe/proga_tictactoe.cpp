#include <iostream>
#include <limits>


using namespace std;

using State = char[3][3];

void printGame(State& state) {
    cout << "\n   -----------";
    for (auto i = 0; i < 3; ++i) {
        cout << "\n  | ";
        for (auto j = 0; j < 3; ++j) {
            cout << state[i][j] << " | ";
        }
        cout << "\n   -----------\n";
    }
    cout << endl;
}

bool positionIsValid(State& state, int x, int y) {
    
    return 0 <= x && x < 3 && 0 <= y && y < 3 && state[x][y] == ' ';
}

void recordPosition(State& state, char player) {
    int x, y;
    auto valid = false;
    do {
        cout << "Player '" << player << "', please type position (X Y): ";
        cin >> x >> y;
        valid = cin.good() && positionIsValid(state, x, y);
        if (valid) {
            state[x][y] = player;
        } else {
            // skip current line
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (!valid);
}

bool rowIsFilled(State& state, int row) {
    auto first = state[row][0];
    if (first == ' ') {

        return false;
    }

    return first == state[row][1] && first == state[row][2];
}

bool columnIsFilled(State& state, int column) {
    auto first = state[0][column];
    if (first == ' ') {

        return false;
    }

    return first == state[1][column] && first == state[2][column];
}

bool anyDiagonalIsFilled(State& state) {
    auto middle = state[1][1];
    if (middle == ' ') {

        return false;
    }

    return (middle == state[0][0] && middle == state[2][2])
        || (middle == state[2][0] && middle == state[0][2]);
}

bool gameOver(State& state) {
    for (int i = 0; i < 3; ++i) {
        if (rowIsFilled(state, i) || columnIsFilled(state, i)) {

            return true;
        }
    }

    return anyDiagonalIsFilled(state);
}

bool nextStep(State& state, char player) {
    recordPosition(state, player);
    printGame(state);
    auto done = gameOver(state);
    if (done) {
        cout << "Congratulation! Player '" << player << "' wins\n";
    }

    return done;
}

int main(){
    char state[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    printGame(state);

    auto player = 'o';
    while (!nextStep(state, player)) {
        player = (player == 'o') ? 'x' : 'o';
    }
    
    return 0;
}