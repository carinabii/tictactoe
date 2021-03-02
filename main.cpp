#include "tictactoe.h"
#include <iostream>
using namespace std;



int main(){
  string player1;
  string player2;
  int win1 = 0;
  int win2 = 0;
  int toggleWhenOdd = 0;
  string again;

  cout << "Enter Player 1's Name: ";
  cin >> player1;

  cout << "Enter Player 2's Name: ";
  cin >> player2;

  do{
    resetBoard();
    makeBoard(player1, player2);
    int winner = play(player1, player2, toggleWhenOdd);
    if (winner == 1){
      win1++;
    }
    if (winner == 2){
      win2++;
    }

    cout << "\nWin Record:" << endl;
    cout << "   " + player1 + ": " << win1 << endl;
    cout << "   " + player2 + ": " << win2 << endl;
    
    cout << endl << "Play again? (y/n): ";
    cin >> again; 

    if (toggleWhenOdd%2 == 0){
      toggleWhenOdd++;
     } else {
      toggleWhenOdd--;
  }
    
  }while(again == "y");

}