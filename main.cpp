#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "humanPlayer.h"
#include "computerPlayer.h"

using namespace std;

void play(Player& player1, Player& player2);
bool checkForWin(Player& player, int answer);
void displayStats(const Player& player1, const Player& player2);

int main() {
    string h1_name, h2_name; // Declare strings to store human player names

    cout << "How many human players? (0, 1, or 2): ";
    int numPlayers;
    cin >> numPlayers;

    srand(static_cast<unsigned int>(time(0)));  // random seed

    // Create player instances
    HumanPlayer h1, h2;
    ComputerPlayer c1("CPU 1"), c2("CPU 2");
    Player *p1, *p2;

    // Assign pointers based on the number of human players
    switch(numPlayers) {
        case 0:
            p1 = &c1;
            p2 = &c2;
            break;
        case 1:
            cout << "Enter name for Player 1: ";
            cin >> ws; // consume leading whitespace
            getline(cin, h1_name);
            h1.setName(h1_name); // Set custom name for Player 1
            p1 = &h1;
            p2 = &c2;
            break;
        case 2:
            cout << "Enter name for Player 1: ";
            cin >> ws; // consume leading whitespace
            getline(cin, h1_name);
            cout << "Enter name for Player 2: ";
            cin >> ws; // consume leading whitespace
            getline(cin, h2_name);
            h1.setName(h1_name); // Set custom name for Player 1
            h2.setName(h2_name); // Set custom name for Player 2
            p1 = &h1;
            p2 = &h2;
            break;
        default:
            cout << "Invalid number of players. Please restart the game with a valid input." << endl;
            return 1; // Exit with error
    }

    char playAgain;
    do {
        play(*p1, *p2);
        cout << "Would you like to play again? (Y/N): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    displayStats(*p1, *p2);  // Display the game stats before the program ends

    return 0;
}

void play(Player& player1, Player& player2) {
    int answer = rand() % 100;  // Generate a random number between 0 and 99
    bool win = false;

    while (!win) {
        win = checkForWin(player1, answer);
        if (win) {
            player1.endRound(true);
            player2.endRound(false);
            return;
        }
        win = checkForWin(player2, answer);
        if (win) {
            player1.endRound(false);
            player2.endRound(true);
        }
    }
}

bool checkForWin(Player& player, int answer) {
    cout << player.getName() << "'s turn to guess." << endl;
    int guess = player.getGuess();
    cout << "You guessed " << guess << ". ";
    if (answer == guess) {
        cout << "You're right! You win!" << endl;
        return true;
    } else {
        player.wrongGuess(guess, answer);
        return false;
    }
}

void displayStats(const Player& player1, const Player& player2) {
    cout << "Final Results:" << endl;
    cout << player1 << endl;  // Using overloaded << operator to print player details
    cout << player2 << endl;

    if (player1 > player2) {
        cout << "Congratulations, " << player1.getName() << "!" << endl;
    } else if (player2 > player1) {
        cout << "Congratulations, " << player2.getName() << "!" << endl;
    } else {
        cout << "We have a tie!" << endl;
    }
}
