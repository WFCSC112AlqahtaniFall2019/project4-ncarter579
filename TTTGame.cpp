/* Class: TicTacToe
 * Author: Nathan Carter
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <random>
#include <ctime>
using namespace std;

int main() {
    TicTacToe game;
    int pCount;
    int row;
    int col;
    int goesFirst;

    srand(time(0));   //setting it so that the computer can generate random numbers every time

    game.initializeBoard();  //initializing the board

    cout << "One-player or Two-player (1 or 2): " << endl;
    cin >> pCount;   //asking how many players their are and storing a corresponding value into pCount
    game.printBoard();  //printing the untouched board out to the user

    if(pCount == 2){  //if you are playing a two player game
        for(int i = 0; i < 300; i ++){  //a for loop that will repeat virtually infinitely
            cout << "player " << game.getCurrentPlayerNumber() <<" enter your row (1-3)" << endl;
            cin >> row;  //asking and receiving the row pick from the user
            cout << "player " << game.getCurrentPlayerNumber() << " enter your column (1-3)" << endl;
            cin >> col;  //asking and receiving the column pick from the user
            if( game.placeMark(row - 1, col - 1) == true) {  //checking if the space is filled or no. if it is a valid space the player will be allowed to place their move
                game.placeMark(row - 1, col - 1);  //placing the mark in the valid location
                game.printBoard();     //print board after the mark is placed

                if (game.checkForWin() == true) {  //checking if a player won the game. If they win prints the output message and ends the program
                    cout << "Player " << game.getCurrentPlayerNumber() << " Wins!!!" << endl;
                    return 0;
                } else {  //if no winner, change the player turn
                    game.changePlayer();
                }
                if (game.isBoardFull() == true) {  //checking if there are any valid moves left. If not it ends the game
                    cout << "Game over! No One Wins!" << endl;
                    return 0;
                }
            }
            else{ // if the move isn't valid, the program prints this statement to the user
                cout << "not a valid entry, please enter a valid row and column combination" << endl;
            }
        }

    }
    else{    //if its a 1 player game, this code will run
        goesFirst = rand() % 2 + 0;   //randomly choosing who gets to go first
        if (goesFirst == 1){   // changes the player if the random generator lands on 1
            game.changePlayer();  //changes player
        }
        cout << "It's player " << game.getCurrentPlayerNumber() << "'s turn!" << endl;
        for(int i = 0; i < 500; i ++){   //loops this code until the end of the game
            if(game.getCurrentPlayerNumber() == 1){    //if the human is playing
                cout << "player " << game.getCurrentPlayerNumber() <<" enter your row (1-3)" << endl;
                cin >> row;   //getting row value
                cout << "player " << game.getCurrentPlayerNumber() << " enter your column (1-3)" << endl;
                cin >> col;     //getting column value
                if( game.placeMark(row - 1, col - 1) == true) {    //checking to see if a valid place is entered
                    game.placeMark(row - 1, col - 1);   //placing the mark
                    game.printBoard();   //printing board

                    if (game.checkForWin() == true) {   //checking to see if anyone has won. if so, prints statement and ends the program
                        cout << "Player " << game.getCurrentPlayerNumber() << " Wins!!!" << endl;
                        return 0;
                    } else {  // else it changes player turn
                        game.changePlayer();
                    }
                    if (game.isBoardFull() == true) {    //checking if their are any more possible moves. if not, ends the game
                        cout << "Game over! No One Wins!" << endl;
                        return 0;
                    }
                }
                else{  //if its not a valid space imput will print this out
                    cout << "not a valid entry, please enter a valid row and column combination" << endl;
                }
            }
            else if (game.getCurrentPlayerNumber() == 2){   //if the robot is playing
                row = rand() % 3 + 0;   //getting random values for row and column
                col = rand() % 3 + 0;
                if( game.placeMark(row, col) == true){   //if its a valid spot
                    game.placeMark(row, col);   //place the mark in that location
                    game.printBoard();   //print the board

                    if(game.checkForWin() == true){     //if someone has won, this will output and the game will end
                        cout << "Player " << game.getCurrentPlayerNumber() << " Wins!!!" << endl;
                        return 0;
                    }
                    else{  //else it will change player turn
                        game.changePlayer();
                    }
                    if(game.isBoardFull() == true){     //checking if their are any possible moves left. If not will end the game
                        cout << "Game over! No One Wins!" << endl;
                        return 0;
                    }
                }
            }
        }
    }



    return 0;
}