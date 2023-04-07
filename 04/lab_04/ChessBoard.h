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
   
friend ChessBoard & operator>>(istream & is, ChessBoard & cb);
friend ChessBoard & operator<<(ostream & os, ChessBoard & cb);


private:
    // Alternative 1 (the matrix owns the chess pieces):
    Matrix<shared_ptr<ChessPiece>> m_state; // Matrix from lab 2
    vector<ChessPiece *> m_white_pieces;
    vector<ChessPiece *> m_black_pieces;

    // Alternative 2 (the vectors own the chess pieces):
    // Matrix<ChessPiece *> m_state; // Matrix from lab 2
    // vector<shared_ptr<ChessPiece>> m_white_pieces;
    // vector<shared_ptr<ChessPiece>> m_black_pieces;

public:
    ChessBoard();
    void movePiece(ChessMove chess_move);
    vector<ChessMove> capturingMoves(bool is_white);
    vector<ChessMove> nonCapturingMoves(bool is_white);

    void addPiece(int x, int y, shared_ptr<ChessPiece> piece);
    void removePiece(int , int);
    shared_ptr<ChessPiece> operator()(int, int) const;
};

ChessBoard & operator>>(istream & is, ChessBoard & cb);
ChessBoard & operator<<(ostream & os, ChessBoard & cb);


#endif //CHESSBOARD_H