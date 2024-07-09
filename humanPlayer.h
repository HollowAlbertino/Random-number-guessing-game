#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

using namespace std;

class HumanPlayer : public Player {
public:
    // Constructor with default name "Player"
    HumanPlayer(const string& name = "Player");

    // Function to get human player's guess
    int getGuess() override;
};

#endif
