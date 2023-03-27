//
// DD1388 - Lab 4: Losing Chess
//

#include "Pawn.h"
#include "ChessBoard.h"
#include <bits/stdc++.h>


// Implement method definitions here

Pawn::Pawn(int x, int y, bool is_white, ChessBoard* board, Type type) : ChessPiece(x, y, is_white, board, type) {}

// destructor
Pawn::~Pawn() {}

// validMove
int Pawn::validMove(int to_x, int to_y) {
   
   // which pecie is it that is in the target square
    ChessPiece* target = m_board->getPiece(to_x, to_y);
    // if the target square is empty
}