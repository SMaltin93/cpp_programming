//
// DD1388 - Lab 4: Losing Chess
//

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <vector>
#include <istream>
#include <memory>
#include "ChessMove.h"
#include "Matrix.h"   // Use the "-I ../02" flag to let the compiler find Matrix.h

using namespace std;

class ChessPiece;

class ChessBoard {



private:
    // Alternative 1 (the matrix owns the   chess pieces):
    Matrix<shared_ptr<ChessPiece>> m_state; // Matrix from lab 2
    vector<ChessPiece *> m_white_pieces;  // Vector of pointers to white pieces
    vector<ChessPiece *> m_black_pieces;  // Vector of pointers to black pieces

public: 
    // set a board  to a given state
    void setBoard(Matrix<shared_ptr<ChessPiece>> board);
    // print the board
    void printBoard();
    // get the piece at a given position
    ChessPiece * getPiece(int x, int y);
      // set a piece
    shared_ptr <ChessPiece> newPiece(int x, int y, bool is_white, ChessBoard * board, Type type);
    // acces the vector of white pieces
    vector<ChessPiece *> getWhitePieces();
    // acces the vector of black pieces
    vector<ChessPiece *> getBlackPieces();
  

 
    void movePiece(ChessMove chess_move);
    vector<ChessMove> capturingMoves(bool is_white);
    vector<ChessMove> nonCapturingMoves(bool is_white);

};

ChessBoard & operator>>(istream & is, ChessBoard & cb);
ChessBoard & operator<<(ostream & os, ChessBoard & cb);

#endif //CHESSBOARD_H
