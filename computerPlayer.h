#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "player.h"

using namespace std;
class ComputerPlayer : public Player {
private:
    int rngStart, rngRange;

public:
    // Constructor with default name "CPU"
    ComputerPlayer(const string& name = "CPU");

    // Function to get computer player's guess
    int getGuess() override;

    // Function to reset random number generator
    void resetRNG();

    // Functions to adjust range based on guess
    void adjustHigh(int guess);
    void adjustLow(int guess);
};

#endif
