#include "player.h"
#include <iostream>

using namespace std;
// Constructor implementation
Player::Player(const string& name) : name(name), wins(0) {}

// Accessor for name
string Player::getName() const {
    return name;
}

// Mutator for name
void Player::setName(const string& newName) {
    name = newName;
}

// Function to handle incorrect guesses
void Player::wrongGuess(int guess, int answer) {
    if (guess > answer) {
       cout << "Your guess is too high." << endl;
    } else {
        cout << "Your guess is too low." << endl;
    }
}

// Function to update wins at the end of a round
void Player::endRound(bool won) {
    if (won) {
        wins++;
    }
}

// Overloaded comparison operator to compare wins
bool Player::operator>(const Player& other) const {
    return wins > other.wins;
}

// Friend function to overload insertion operator for output
ostream& operator<<(ostream& os, const Player& player) {
    os << player.name << "\nNumber of Wins: " << player.wins;
    return os;
}
