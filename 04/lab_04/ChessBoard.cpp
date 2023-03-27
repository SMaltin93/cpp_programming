//
// DD1388 - Lab 4: Losing Chess
//


#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

#include "ChessPiece.h"
#include "ChessBoard.h"

#include <bits/stdc++.h>
#include <iostream>




using namespace std;


// setBoard sets the board to a given state
void ChessBoard::setBoard(Matrix<shared_ptr<ChessPiece>> board) {
    this->m_state = board;
}

// getPiece returns the piece at a given position
ChessPiece * ChessBoard::getPiece(int x, int y) {
    return m_state(x, y).get();
}


// getWhitePieces returns the vector of white pieces
vector<ChessPiece *> ChessBoard::getWhitePieces() {
    return m_white_pieces;
}

// getBlackPieces returns the vector of black pieces
vector<ChessPiece *> ChessBoard::getBlackPieces() {
    return m_black_pieces;
}

void ChessBoard::printBoard() {
    cout << "  a b c d e f g h" << endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            if (m_state(j, i) == nullptr) {
                cout << ". ";
            } else {
                cout << m_state(j, i)->latin1Representation() << " ";
            }
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h" << endl;
}



void ChessBoard::movePiece(ChessMove chess_move) {
    shared_ptr<ChessPiece> piece = m_state(chess_move.from_x, chess_move.from_y); 
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


// operator>> reads a chess board from a stream
ChessBoard & operator>>(istream & is, ChessBoard & cb) {
  // read the board state from the stream¨
  //     ChessPiece(int x, int y, bool is_white, ChessBoard * board, Type type);
  Matrix<shared_ptr<ChessPiece>> board(8);
}
// operator<< prints a chess board to a stream
ChessBoard & operator<<(ostream & os, ChessBoard & cb) {

    cb.printBoard();
    return cb;
    
  
}


