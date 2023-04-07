//
// DD1388 - Lab 4: Losing Chess
//

#include "Pawn.h"

// Implement method definitions here

#include "ChessBoard.h"
#include "ChessMove.h"
#include "ChessPiece.h"

#include <bits/stdc++.h>

using namespace std;

Pawn::Pawn(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board) {}




int Pawn::validMove(int to_x, int to_y) {
    int delta_x = abs(m_x - to_x);
    int delta_y = abs(m_y - to_y);
    int start = 1;
    int lastRow = 6;
    ChessPiece getPiece = m_board->operator()(to_x, to_y);

    // if the pawn at the start position



   
}