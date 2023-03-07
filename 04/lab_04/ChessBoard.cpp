//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include "ChessPiece.h"

#include <bits/stdc++.h>
#include <iostream>




using namespace std;


// setBoard sets the board to a given state
void ChessBoard::setBoard(Matrix<shared_ptr<ChessPiece>> board) {
    m_state = board;
}

void ChessBoard::movePiece(ChessMove chess_move) {
    shared_ptr<ChessPiece> piece = m_state(chess_move.from_x, chess_move.from_y); // my_state is a Matrix<shared_ptr<ChessPiece>> and has tow arguments row and column
    // changing the position x, y of the piece
    piece->m_x = chess_move.to_x;   
    piece->m_y = chess_move.to_y;
    // moving the piece to the new position
    m_state(chess_move.to_x, chess_move.to_y) = piece;
    // removing the piece from the old position
    m_state(chess_move.from_x, chess_move.from_y) = nullptr;
}

vector<ChessMove> ChessBoard::capturingMoves(bool is_white) {

    vector<ChessMove> capturing_moves;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (m_state(i, j) != nullptr) {
                if (m_state(i, j)->isWhite() == is_white) {
                    vector<ChessMove> piece_moves = m_state(i, j)->capturingMoves();
                    for (int k = 0; k < piece_moves.size(); k++) {
                        capturing_moves.push_back(piece_moves[k]);
                    }
                }
            }
        }
    }


}
// nonCapturingMoves returns a vector with ChessMoves that moves to an empty space.
vector<ChessMove> ChessBoard::nonCapturingMoves(bool is_white) { 

    vector<ChessMove> non_capturing_moves;
    // Looping through the board and checking if the piece is white or black
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (m_state(i, j) != nullptr) {
                if (m_state(i, j)->isWhite() == is_white) {
                    vector<ChessMove> piece_moves = m_state(i, j)->nonCapturingMoves();
                    for (int k = 0; k < piece_moves.size(); k++) {
                        non_capturing_moves.push_back(piece_moves[k]);
                    }
                }
            }
        }
    }
    return non_capturing_moves;    
}

// getPiece returns the piece at a given position
ChessPiece * ChessBoard::getPiece(int x, int y) {
    return m_state(x, y).get();
}




// here its a simple porgram
// using std::vector; using std::stringstream; using std::cout; using std::endl;
// //...
//     ChessBoard chess;
//     stringstream s;
//     s << ".....Q.." << endl;
//     s << "...q...." << endl;
//     s << "......Q." << endl;
//     s << "q......." << endl;
//     s << ".......Q" << endl;
//     s << ".q......" << endl;
//     s << "....Q..." << endl;
//     s << "..q.....";
//     s >> chess;
//     vector<ChessMove> v = chess.capturingMoves(true);

//     if (v.size() != 0) {
//         cout << "capturingMoves FAILED, expected 0 moves but got " << v.size() << " moves" << endl;
//     } else {
//         cout << "capturingMoves PASSED, expected 0 moves and got " << v.size() << " moves" << endl;
//     }

// operator>> reads a chess board from a stream
ChessBoard & operator>>(istream & is, ChessBoard & cb) {

    //set the board to the given state
    Matrix<shared_ptr<ChessPiece>> board(8, 8);
    char c;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            is >> c;
            if (c == '.') {
                board(i, j) = nullptr;
            } else if (c == 'K') {
                board(i, j) = make_shared<King>(i, j, true);
            } else if (c == 'k') {
                board(i, j) = make_shared<King>(i, j, false);
            } else if (c == 'Q') {
                board(i, j) = make_shared<Queen>(i, j, true);
            } else if (c == 'q') {
                board(i, j) = make_shared<Queen>(i, j, false);
            } else if (c == 'R') {
                board(i, j) = make_shared<Rook>(i, j, true);
            } else if (c == 'r') {
                board(i, j) = make_shared<Rook>(i, j, false);
            } else if (c == 'B') {
                board(i, j) = make_shared<Bishop>(i, j, true);
            } else if (c == 'b') {
                board(i, j) = make_shared<Bishop>(i, j, false);
            } else if (c == 'N') {
                board(i, j) = make_shared<Knight>(i, j, true);
            } else if (c == 'n') {
                board(i, j) = make_shared<Knight>(i, j, false);
            } else if (c == 'P') {
                board(i, j) = make_shared<Pawn>(i, j, true);
            } else if (c == 'p') {
                board(i, j) = make_shared<Pawn>(i, j, false);
            }
        }
    }
    cb.setBoard(board);
}

// operator<< prints a chess board to a stream
ChessBoard & operator<<(ostream & os, ChessBoard & cb) {
   for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cb.getPiece(i, j) == nullptr) {
                os << '.';
            } else {
                os << cb.getPiece(i, j) -> toString();
            }
        }
        os << endl;
    }
    return os;
}


