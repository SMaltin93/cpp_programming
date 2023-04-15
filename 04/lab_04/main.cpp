//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "King.h"
#include <iostream>
#include <random>
using namespace std;


int main() {

ChessBoard chess;
    stringstream s;
    s << "rnbqkbnr" << endl;
    s << "pppppppp" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "PPPPPPPP" << endl;
    s << "RNBQKBNR" << endl;
    s >> chess;
    vector<ChessMove> v = chess.capturingMoves(true);
    // print the board
    chess.printBoard(&chess);
    //////////////////////////////////////////////////////

    bool ai1 = true; // is white
    bool ai2 = false; // is black
    // {white_moves, black_moves, white_captured, black_captured}
    vector<int> game_scoure = {0,0,0,0};
    // colors
    string red = "\33[31m";
    string reset = "\33[0m";
    string green = "\33[32m";

    // type of piece that has been captured
    string white_piec_moves = "";
    string black_piec_moves = "";

    // start the game
    cout << "<<<<<<<<<<<<<<<<<<<<<<< Game started >>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
  

    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            chess.ai1_moves(&chess, ai1, &game_scoure, &white_piec_moves);
            cout << red << "The AI_1 has moved " << ++game_scoure[0] << " times and total captured " << game_scoure[2] << ", The" << white_piec_moves << " has moved" << reset << endl;
        } else {
            chess.ai2_moves(&chess, ai2, &game_scoure, &black_piec_moves);
            cout << green << "The AI_2 has moved " << ++game_scoure[1] << " times and total captured " << game_scoure[3] << ", The" << black_piec_moves << " has moved" << reset << endl;
        }
        chess.printBoard(&chess);
        cout << endl;
    }
}

