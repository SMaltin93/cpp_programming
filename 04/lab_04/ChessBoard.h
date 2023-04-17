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

string white_capture_black = "";
string black_capture_white = "";

private:
    // Alternative 1 (the matrix owns the chess pieces):
    Matrix<shared_ptr<ChessPiece>> m_state; // Matrix from lab 2
    vector<ChessPiece *> m_white_pieces;
    vector<ChessPiece *> m_black_pieces;

public:
   // ChessBoard();
    void movePiece(ChessMove chess_move);
    vector<ChessMove> capturingMoves(bool is_white);
    vector<ChessMove> nonCapturingMoves(bool is_white);
    shared_ptr<ChessPiece> operator()(int, int) const;

  void removePiece(int, int , ChessPiece *, bool);
  void printBoard(ChessBoard  *cb);
  string presentPiecesAsUnicode(char piece);
  void ai1_moves(ChessBoard *, bool, vector<int>*, string*);
  void ai2_moves(ChessBoard *, bool, vector<int>*, string*); 
  void moveBack(int, int, int, int, ChessPiece *); 
  int generateRandomNumber(int const, int const);  

  pair<vector<int>, bool> checkPawn(ChessPiece *);
  void switchPawn(ChessBoard *, int, int, bool);

                

};


ChessBoard & operator>>(istream & is, ChessBoard & cb);
ChessBoard & operator<<(ostream & os, ChessBoard & cb);


#endif //CHESSBOARD_H