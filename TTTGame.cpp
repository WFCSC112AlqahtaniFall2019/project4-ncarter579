/* Class: TicTacToe
 * Author: [FINISH ME]
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

    srand(time(0));

    game.initializeBoard();

    cout << "One-player or Two-player (1 or 2): " << endl;
    cin >> pCount;
    game.printBoard();

    if(pCount == 2){
        for(int i = 0; i < 100; i ++){
            cout << "player " << game.getCurrentPlayerNumber() <<" enter your row (1-3)" << endl;
            cin >> row;
            cout << "player " << game.getCurrentPlayerNumber() << " enter your column (1-3)" << endl;
            cin >> col;
            if( game.placeMark(row - 1, col - 1) == true) {
                game.placeMark(row - 1, col - 1);
                game.printBoard();

                if (game.checkForWin() == true) {
                    cout << "Player " << game.getCurrentPlayerNumber() << " Wins!!!" << endl;
                    return 0;
                } else {
                    game.changePlayer();
                }
                if (game.isBoardFull() == true) {
                    cout << "Game over! No One Wins!" << endl;
                    return 0;
                }
            }
            else{
                cout << "not a valid entry, please enter a valid row and column combination" << endl;
            }
        }

    }
    else{
        goesFirst = rand() % 2 + 0;
        if (goesFirst == 1){
            game.changePlayer();
        }
        cout << "It's player " << game.getCurrentPlayerNumber() << "'s turn!" << endl;
        for(int i = 0; i < 500; i ++){
            if(game.getCurrentPlayerNumber() == 1){    //if the human is playing
                cout << "player " << game.getCurrentPlayerNumber() <<" enter your row (1-3)" << endl;
                cin >> row;
                cout << "player " << game.getCurrentPlayerNumber() << " enter your column (1-3)" << endl;
                cin >> col;
                if( game.placeMark(row - 1, col - 1) == true) {
                    game.placeMark(row - 1, col - 1);
                    game.printBoard();

                    if (game.checkForWin() == true) {
                        cout << "Player " << game.getCurrentPlayerNumber() << " Wins!!!" << endl;
                        return 0;
                    } else {
                        game.changePlayer();
                    }
                    if (game.isBoardFull() == true) {
                        cout << "Game over! No One Wins!" << endl;
                        return 0;
                    }
                }
                else{
                    cout << "not a valid entry, please enter a valid row and column combination" << endl;
                }
            }
            else if (game.getCurrentPlayerNumber() == 2){   //if the robot is playing
                row = rand() % 3 + 0;
                col = rand() % 3 + 0;
                if( game.placeMark(row, col) == true){
                    game.placeMark(row, col);
                    game.printBoard();

                    if(game.checkForWin() == true){
                        cout << "Player " << game.getCurrentPlayerNumber() << " Wins!!!" << endl;
                        return 0;
                    }
                    else{
                        game.changePlayer();
                    }
                    if(game.isBoardFull() == true){
                        cout << "Game over! No One Wins!" << endl;
                        return 0;
                    }
                }
                else{
                    cout << "not a valid entry, please enter a valid row and column combination" << endl;
                }
            }
        }
    }



    return 0;
}