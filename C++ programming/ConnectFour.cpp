#include <iostream>
#include <string>
#include <vector> 

using namespace std;

//declare prototype for board display
void displayBoard(vector<vector<char>> board);
//declare prototype for board update, pass the board and disks in collumn by reference to update them
void updateBoard(vector<vector<char>> *board, vector<int> *disksInColl, int &playerChoice, bool currentPlayer);
//declare prototype for choice validation, pass the player choice by reference to change the players choice if it isn't valid
void validateChoice(int &playerChoice);
//declare prototype to reset the game
void reset(bool &currentPlayer, vector<int> *disksInColl, int &totalPieces, vector<vector<char>> *board);
//declare prototype to check if there has been a win
bool checkWin(int x, vector<int> disksInColl, vector<vector<char>> board);

//main method
int main()
{
  bool currentPlayer = false; //false for player one (X), true for player two(O)
  int playerChoice = 0;       //input variable to place to put disk
  vector<int> disksInColl = {0,0,0,0,0,0,0}; //initialize the current number of disks in each collumn
  bool keepPlaying = true;                   //variable to play another game
  int totalPieces = 0;                       //total number of pieces on the board, game ends if no winner is decided by the time it gets to 42
  vector<vector<char>> board {{' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, 
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, 
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},
  {' ', ' ', ' ', ' ', ' ', ' '}}; //initialize the playboard 6X7
  
  cout << "Welcome to connect 4!" << endl;                                 //greet the player
  while(keepPlaying)                                                       //variable to start another game
  {                                                                        //
      while(true)                                                          //loop while there is an active game going
      {                                                                    //
        displayBoard(board);                                               //display the board
        string player = !currentPlayer ? "Player 1 (X) "  : "Player 2 (O)";//is the current player player one or two? 
        cout <<  player << " choose a spot to place your piece: ";         //Tell the player to choose a space
        cin >> playerChoice;                                               //take in the players choice
                                                                           //
        validateChoice(playerChoice);                                      //see if the choice is valid, have them pick again if not
      
        updateBoard(&board, &disksInColl,playerChoice, currentPlayer);     //update the board, passing the disks in collumn and board by reference to update them
        totalPieces++;                                                     //update the total number of pieces on the board after it has been updated appropriately
        if(checkWin(playerChoice-1, disksInColl, board))                   //determine if a win has occured (searching up, down, left, right, and diagonally if possible without out of boundsing)
        {                                                                  //
            displayBoard(board);                                           //redisplay the board if a win has occured
            cout << player << " has won the game!" << endl;                //display the winner of the game
            break;                                                         //break out of the active game loop
        }                                                                  //
                                                                           //
        currentPlayer = !currentPlayer ? true : false;                     //change the current playerChoice
        if(totalPieces == 42)                                              //are all slots filled and no winner?
        {                                                                  //
            displayBoard(board);                                           //redisplay the board
            cout << "Game is a draw" << endl;                              //alert the players a draw has occured
            break;                                                         //break out of the active game loop
        }                                                                  //
    }                                                                      //
    cout << "would you like to play again? (y/n)";                         //ask the player if they would like to play again Y/y for yes, anything else registers as no
    char choice;                                                           //declare a variable for the player choice
    cin >> choice;                                                         //take in the players decision
    keepPlaying = (choice == 'Y' || choice == 'y') ? true : false;         //if Y or y was choosen, start another game
    if(keepPlaying)                                                        //if yes
        reset(currentPlayer, &disksInColl, totalPieces, &board);           //reset the gameboard, player, total pieces, and the disks in each collumn
  }                                                                        //
  return 0;                                                                //game terminated, terminate program
}

//method to display our game board
void displayBoard(vector<vector<char>> board)
{
  cout << endl << " 1  2  3  4  5  6  7" << endl;                                                                                                                                                                         //display collumn numbers
  cout << "[" << board[0][5] << "]" << "[" << board[1][5] << "]" << "[" << board[2][5] << "]" << "[" << board[3][5] << "]" << "[" << board[4][5] << "]" << "[" << board[5][5] << "]" << "[" << board[6][5] << "]" << endl;//display first row
  cout << "[" << board[0][4] << "]" << "[" << board[1][4] << "]" << "[" << board[2][4] << "]" << "[" << board[3][4] << "]" << "[" << board[4][4] << "]" << "[" << board[5][4] << "]" << "[" << board[6][4] << "]" << endl;//display second row
  cout << "[" << board[0][3] << "]" << "[" << board[1][3] << "]" << "[" << board[2][3] << "]" << "[" << board[3][3] << "]" << "[" << board[4][3] << "]" << "[" << board[5][3] << "]" << "[" << board[6][3] << "]" << endl;//display third row
  cout << "[" << board[0][2] << "]" << "[" << board[1][2] << "]" << "[" << board[2][2] << "]" << "[" << board[3][2] << "]" << "[" << board[4][2] << "]" << "[" << board[5][2] << "]" << "[" << board[6][2] << "]" << endl;//display fourth row
  cout << "[" << board[0][1] << "]" << "[" << board[1][1] << "]" << "[" << board[2][1] << "]" << "[" << board[3][1] << "]" << "[" << board[4][1] << "]" << "[" << board[5][1] << "]" << "[" << board[6][1] << "]" << endl;//display fifth row
  cout << "[" << board[0][0] << "]" << "[" << board[1][0] << "]" << "[" << board[2][0] << "]" << "[" << board[3][0] << "]" << "[" << board[4][0] << "]" << "[" << board[5][0] << "]" << "[" << board[6][0] << "]" << endl;//display sixth row
}

//take the players input and place on board
void updateBoard(vector<vector<char>> *board, vector<int> *disksInColl, int &playerChoice, bool currentPlayer)
{
    while(true)                                                                                               //loop to validate the player has choosen a collumn that is not full
    {                                                                                                         //
        if((*disksInColl)[playerChoice-1] < 6)                                                                //if the collumn isn't full
        {                                                                                                     //
            (*board)[playerChoice-1][(*disksInColl)[playerChoice-1]] = currentPlayer ? 'O' : 'X';             //place the players piece at the choosen location
            (*disksInColl)[playerChoice-1] += 1;                                                              //update the number of discs in that collumn
            break;                                                                                            //break out of the validation loop
        }                                                                                                     //
        else                                                                                                  //if the collumn is full
        {                                                                                                     //
            cout << "that collumn is full, pick again";                                                       //tell the player it's full
            cin >> playerChoice;                                                                              //take in the players choice again
            validateChoice(playerChoice);                                                                     //validate the input  
        }                                                                                                     //
    }                                                                                                         //
}                                                                                                             //

//validate that the player has chosen a number between 1 and 7, ask them to select again if not
void validateChoice(int &playerChoice)                                                                        //
{                                                                                                             //
  while(true)                                                                                                 //loop to validate input
  {                                                                                                           //
      if(1 <= playerChoice && playerChoice <=7)                                                               //if the player chose between 1 and 7
        break;                                                                                                //we're good
      else                                                                                                    //anything else
      {                                                                                                       //
        while (cin.fail())                                                                                    //safe check in case player input a char
        {                                                                                                     //
            cin.clear();                                                                                      // clear input buffer to restore cin to a usable state                     
            cin.ignore(INT_MAX, '\n');                                                                        // ignore last input
            cout << "invalid selection, choose between 1 and 7";                                              //tell player to choose between 1 and 7                   
            cin >> playerChoice;                                                                              //take back in player choice
        }
      }
  }
}

void reset(bool &currentPlayer, vector<int> *disksInColl, int &totalPieces, vector<vector<char>> *board)//method to reset the gameboard, disks in collumn, number of disks, and current player
{                                                                                                       //
  currentPlayer = false;                                                                                //false for player one (X), true for player two(O)
  *disksInColl = {0,0,0,0,0,0,0};                                                                       //initialize the current number of disks in each collumn
  totalPieces = 0;                                                                                      //total number of pieces on the board, game ends if no winner is decided by the time it gets to 42
  *board = {{' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},                             //
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},                                       //
  {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '},                                       //
  {' ', ' ', ' ', ' ', ' ', ' '}};                                                                      //reinitialize the playboard
}                                                                                                       //

//function to determine if there has been a win, checks left, right, up, down, and diagonally
bool checkWin(int x, vector<int> disksInColl, vector<vector<char>> board)                                                                                                                             //
{                                                                                                                                                                                                     //
    int y = disksInColl[x]-1;                                                                                                                                                                         //get our y coordinate
    if(x < 4)                                                                                                                                                                                         //if we have not crossed the middle boundary, perform checks to the right
    {                                                                                                                                                                                                 //
        if(board.at(x).at(y) == board.at(x+1).at(y)  && board.at(x+1).at(y) == board.at(x+2).at(y)  && board.at(x+2).at(y) == board.at(x+3).at(y))                                                    //are there 3 matching to the right? 
            return true;                                                                                                                                                                              //return true
        if(x > 0 && board.at(x-1).at(y) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x+1).at(y)  && board.at(x+1).at(y) == board.at(x+2).at(y))                                             //is there 1 on the left and 2 on the right? 
            return true;                                                                                                                                                                              //return true
        if(x > 1 && board.at(x-2).at(y) == board.at(x-1).at(y)  && board.at(x-1).at(y) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x+1).at(y))                                             //is there 2 on the left and 1 on the right? 
            return true;                                                                                                                                                                              //return true
    }                                                                                                                                                                                                 //
    if(x >= 3)                                                                                                                                                                                        //if we have cross the middle boundary, perform checks to the left
    {                                                                                                                                                                                                 //
        if(board.at(x).at(y) == board.at(x-1).at(y)  && board.at(x-1).at(y) == board.at(x-2).at(y)  && board.at(x-2).at(y) == board.at(x-3).at(y))                                                    //are there 3 matching to the left? 
            return true;                                                                                                                                                                              //return true
        if(x < 6 && board.at(x+1).at(y) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x-1).at(y)  && board.at(x-1).at(y) == board.at(x-2).at(y))                                             //is there 1 on the right and 2 on the left? 
            return true;                                                                                                                                                                              //return true
        if(x < 5 && board.at(x+2).at(y) == board.at(x+1).at(y)  && board.at(x+1).at(y) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x-1).at(y))                                             //is there 2 on the right and 1 on the left? 
            return true;                                                                                                                                                                              //return true
    }                                                                                                                                                                                                 //
    if(y >= 3)                                                                                                                                                                                        //if we have cross the middle boundary, perform downward checks
    {                                                                                                                                                                                                 //
        if(board.at(x).at(y) == board.at(x).at(y-1)  && board.at(x).at(y-1) == board.at(x).at(y-2)  && board.at(x).at(y-2) == board.at(x).at(y-3))                                                    //you can only stack vertically, perform one check down
            return true;                                                                                                                                                                              //return true
    }                                                                                                                                                                                                 //
    if(y < 3)                                                                                                                                                                                         //if we are below the middle boundary, check diagonally upward
    {                                                                                                                                                                                                 //
        if(x <= 3)                                                                                                                                                                                    //if we are on or to the left of the middle boundary, check right
        {                                                                                                                                                                                             //
            if(board.at(x).at(y) == board.at(x+1).at(y+1)  && board.at(x+1).at(y+1) == board.at(x+2).at(y+2)  && board.at(x+2).at(y+2) == board.at(x+3).at(y+3))                                      //are there 3 diagonally up and right? 
                return true;                                                                                                                                                                          //return true
            if(x > 0 && y > 0 && board.at(x-1).at(y-1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x+1).at(y+1)  && board.at(x+1).at(y+1) == board.at(x+2).at(y+2))                        //is there one behind and two in front? 
                return true;                                                                                                                                                                          //return true
            if(x > 1 && y > 2 && board.at(x-2).at(y-2) == board.at(x-1).at(y-1)  && board.at(x-1).at(y-1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x+1).at(y+1))                        //is there two behind and one in front? 
                return true;                                                                                                                                                                          //return true
        }                                                                                                                                                                                             //
        if(x >= 3)                                                                                                                                                                                    //if we are on or to the right of the middle boundary, check left    
        {                                                                                                                                                                                             //
            if(board.at(x).at(y) == board.at(x-1).at(y+1)  && board.at(x-1).at(y+1) == board.at(x-2).at(y+2)  && board.at(x-2).at(y+2) == board.at(x-3).at(y+3))                                      //are there three to the left and up?
                return true;                                                                                                                                                                          //return true
            if(x < 6 && y > 0 && board.at(x+1).at(y-1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x-1).at(y+1)  && board.at(x-1).at(y+1) == board.at(x-2).at(y+2))                        //is there one behind and two in front? 
                return true;                                                                                                                                                                          //return true
            if(x < 5 && y > 1 && board.at(x+2).at(y-2) == board.at(x+1).at(y-1)  && board.at(x+1).at(y-1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x-1).at(y+1))                        //is there two behind and one in front? 
                return true;                                                                                                                                                                          //return true
        }                                                                                                                                                                                             //
    }                                                                                                                                                                                                 //
    if(y > 2)                                                                                                                                                                                         //if we are above the middle boundary, check diagonally downward
    {                                                                                                                                                                                                 //
        if(x <= 3)                                                                                                                                                                                    //if we are on or to the left of the middle boundary, check right
        {                                                                                                                                                                                             //
            if(board.at(x).at(y) == board.at(x+1).at(y-1)  && board.at(x+1).at(y-1) == board.at(x+2).at(y-2)  && board.at(x+2).at(y-2) == board.at(x+3).at(y-3))                                      //are there three down to the right?
                return true;                                                                                                                                                                          //return true
            if(x > 0 && y < 5 && board.at(x-1).at(y+1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x+1).at(y-1)  && board.at(x+1).at(y-1) == board.at(x+2).at(y-2))                        //is there one behind and two in front?
                return true;                                                                                                                                                                          //return true
            if(x > 1 && y < 4 && board.at(x-2).at(y+2) == board.at(x-1).at(y+1)  && board.at(x-1).at(y+1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x+1).at(y-1))                        //is there two behind and one in front? 
                return true;                                                                                                                                                                          //return true
        }                                                                                                                                                                                             //
        if(x >= 3)                                                                                                                                                                                    //if we are on or to the right of the middle boundary, check left
        {                                                                                                                                                                                             //
            if(board.at(x).at(y) == board.at(x-1).at(y-1)  && board.at(x-1).at(y-1) == board.at(x-2).at(y-2)  && board.at(x-2).at(y-2) == board.at(x-3).at(y-3))                                      //are there three down to the left? 
                return true;                                                                                                                                                                          //return true
            if(x < 6 && y < 5 && board.at(x+1).at(y+1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x-1).at(y-1)  && board.at(x-1).at(y-1) == board.at(x-2).at(y-2))                        //is there one behind and two in front
                return true;                                                                                                                                                                          //return true
            if(x < 5 && y < 4 && board.at(x+2).at(y+2) == board.at(x+1).at(y+1)  && board.at(x+1).at(y+1) == board.at(x).at(y)  && board.at(x).at(y) == board.at(x-1).at(y-1))                        //is there two behind and one in front
                return true;                                                                                                                                                                          //return true
        }                                                                                                                                                                                             //
    }                                                                                                                                                                                                 //
    return false;                                                                                                                                                                                     //there is no winner return false
}                                                                                                                                                                                                     //
