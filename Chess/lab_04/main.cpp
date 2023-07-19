//
// DD1388 - Lab 4: Losing Chess
//
#include "ChessBoard.h"
#include "ChessPiece.h" 
#include "King.h" 
#include <iostream>
#include <random>

using namespace std;


void ai_moves (ChessBoard *chess, bool ai_color, vector<int> *game_scoure, string *piece, int id);
int main(int argc, char** argv) {

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " make game ai1='1' ai2='2' if you want to set the AI 1 vs AI 2 " << std::endl;
    }
    int ai_1 = atoi(argv[1]);
    int ai_2 = atoi(argv[2]);

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
    // save chess.ai1_moves(&chess, ai2, &game_scoure, &black_piec_moves); in a vector
    // save chess.ai2_moves(&chess, ai2, &game_scoure, &black_piec_moves); in a vector    
    
    for (int i = 0; i < 50; i++) {
        if (i % 2 == 0 ) {
            ai_moves (&chess, ai1, &game_scoure, &white_piec_moves, ai_1);
            cout << red << "The AI_ has moved " << ++game_scoure[0] << " times and total captured " << game_scoure[2] << ", The" << white_piec_moves << " has moved" << reset << endl;
        } else {
             ai_moves (&chess, ai2, &game_scoure, &black_piec_moves, ai_2);
            cout << green << "The AI_2 has moved " << ++game_scoure[1] << " times and total captured " << game_scoure[3] << ", The" << black_piec_moves << " has moved" << reset << endl;
        }
        chess.printBoard(&chess);
        cout << endl;
    }
}

void ai_moves (ChessBoard *chess, bool ai_color, vector<int> *game_scoure, string *piece, int id) {
    if (id == 1) chess->ai1_moves(chess, ai_color, game_scoure, piece);
    else chess->ai2_moves(chess, ai_color, game_scoure, piece);
}


