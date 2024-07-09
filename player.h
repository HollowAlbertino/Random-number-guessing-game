#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player {
protected:
    string name; 
    int wins; 

public:
    // Constructor with default name "Player"
    Player(const string& name = "Player");

    virtual ~Player() {}

    // Accessors and mutators for name
    string getName() const;
    void setName(const string& name);
    
    // Pure virtual function to get player's guess
    virtual int getGuess() = 0;

    // Function to handle incorrect guesses
    void wrongGuess(int guess, int answer);

    // Function to update wins at the end of a round
    void endRound(bool won);

    // Overloaded comparison operator to compare wins
    bool operator>(const Player& other) const;

    // Friend function to overload insertion operator for output
    friend ostream& operator<<(ostream& os, const Player& player);
};

#endif
