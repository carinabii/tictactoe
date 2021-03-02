#include <iostream>
using namespace std;

char* squares = new char[9]{'1', '5', '3', '4', '5', '6', '7', '8', '9'};
enum Result {Ongoing, Win, Tie};


int win1;
int win2;




void makeBoard(string p1, string p2){
  cout << "\n\nTIC TAC TOE" << endl;

  cout << p1 + " (X)  -  " + p2 + " (O)" << endl;
  cout << endl;

  cout << "     |     |     " << endl;
  cout << "  " << squares[0] << "  |  " << squares[1] << "  |  " << squares[2] << endl;

  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;

  cout << "  " << squares[3] << "  |  " << squares[4] << "  |  " <<  squares[5] << endl;

  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;

  cout << "  " << squares[6] << "  |  " << squares[7] << "  |  " <<  squares[8] << endl;

  cout << "     |     |     " << endl << endl;
  
}

void resetBoard(){
  squares[0] = '1';
  squares[1] = '2';
  squares[2] = '3';
  squares[3] = '4';
  squares[4] = '5';
  squares[5] = '6';
  squares[6] = '7';
  squares[7] = '8';
  squares[8] = '9';

  
}

Result checkResult(int count){
  for (int i = 0; i < 4; i++){
    if (squares[i] == squares[i+3] && squares[i] == squares[i+6]){
      return Result :: Win;
    }
  }

  for (int i = 0; i < 4; i += 3){
    if (squares[i] == squares[i+1] && squares[i] == squares[i+2]){
      return Result :: Win;
    }
  }

  if (squares[0] == squares[4] && squares[0] == squares[8]){
    return Result :: Win;
  }

  if (squares[2] == squares[4] && squares[2] == squares[6]){
    return Result :: Win;
  }

  if (count == 9){
    return Result :: Tie;
  }

  return Result :: Ongoing;

}

string  togglePlayer(string player, string p1, string p2){
  if (player == p1){
    return  p2;
  }

  return p1;
}


int play(string p1, string p2, int toggle){
  string player;
  if (toggle%2 == 0){
    player = p2;
  } else {
    player = p1;
  }
  
  int count = 0;
  int pos;
  char *gamePiece = new char;

  do{
    // makeBoard(p1, p2);
    player = togglePlayer(player, p1, p2);
    *gamePiece = (player == p1) ? 'X' : 'O';
    cout << player + ", please pick a square: ";
    cin >> pos;

    while (squares[pos-1] == 'X' || squares[pos-1] == 'O'){
      cout << "Invalid: Square Already Taken" << endl;
      cout << player + ", please pick a square: " << endl;
      cin >> pos;
      
    }

    squares[pos-1] = *gamePiece;
    
    makeBoard(p1, p2);
    count++;
  } while(checkResult(count) == Result::Ongoing);

  if (checkResult(count) == Result::Win){
    cout << player + " wins!!" << endl;
  } else {
    cout << "It's a tie!! :))" << endl;
  }

  if (player == p1){
    return 1;
  } else if (player == p2){
    return 2;
  } else {
    return 0;
  }
  
  delete gamePiece;
}
