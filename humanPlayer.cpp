#include "humanPlayer.h"
#include <climits>
#include <iostream>

using namespace std;
// Constructor implementation
HumanPlayer::HumanPlayer(const string& name) : Player(name) {}

// Function to get human player's guess
int HumanPlayer::getGuess() {
    int guess;
    cout << getName() << "'s turn to guess: ";
    while (true) {
        cin >> guess;
        if (cin.fail() || guess < 0 || guess > 99) {
            cin.clear(); // Clear error flag
            cin.ignore(INT_MAX, '\n'); // Ignore characters until the end of line
            cout << "Invalid guess. Please enter a number between 0 and 99: ";
        } else {
            break;
        }
    }
    return guess;
}
