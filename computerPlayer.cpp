#include "computerPlayer.h"
#include <iostream>

using namespace std;
// Constructor implementation
ComputerPlayer::ComputerPlayer(const string& name) : Player(name) {
    srand(time(NULL));
    resetRNG();
}

// Function to get computer player's guess
int ComputerPlayer::getGuess() {
    int guess = rand() % rngRange + rngStart;
    cout << getName() << " guesses " << guess << endl;
    return guess;
}

// Function to reset random number generator
void ComputerPlayer::resetRNG() {
    rngStart = 0;
    rngRange = 100;
}

// Function to adjust range based on high guess
void ComputerPlayer::adjustHigh(int guess) {
    rngRange = guess - rngStart; // Adjust range to be below the wrong high guess
}

// Function to adjust range based on low guess
void ComputerPlayer::adjustLow(int guess) {
    rngStart = guess + 1; // Adjust start to be above the wrong low guess
    rngRange -= (guess - rngStart + 1);
}
