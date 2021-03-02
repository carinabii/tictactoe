#include <iostream>
using namespace std;

// initiates the game; 
// as long as game is still ongoing, prompts the next user for next input
// places user's input onto the board
// determines if there is a win
int play(string p1, string p2, int toggle);

// prints out and makes a board with the current input squares
void makeBoard(string p1, string p2);

// resets the board to have initial input squares of: 
// 1 2 3
// 4 5 6
// 7 8 9
void resetBoard();

// checks the state of the game: can either be ongoing, a tie or a win
// checks by checking for similarity of current inputs of nearby squares
void checkResult(int count);

// returns the player thats up next
string togglePlayer(string player, string p1, string p2);