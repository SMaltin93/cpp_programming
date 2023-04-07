//
// DD1388 - Lab 4: Losing Chess
//

#include "Pawn.h"
#include "ChessBoard.h"
#include <bits/stdc++.h>

// Implement method definitions here

#include "ChessBoard.h"
#include "ChessMove.h"
#include "ChessPiece.h"

#include <bits/stdc++.h>

using namespace std;

Pawn::Pawn(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board) {}

Pawn::~Pawn() {}



int Pawn::validMove(int to_x, int to_y) {

    // An implementation for capturingmove is to check y+1, x+1 and x-1 and for the other color; y-1, x+1 and x-1.
    // The non-capturing move needs to check if there is a blocking piece at y+1/y-1.
    int delta_x = abs(m_x - to_x);
    int delta_y = m_y - to_y; // delta_y is negative if the pawn moves up
    int start = 1;
    int lastRow = 6;
    shared_ptr<ChessPiece> getPiece = m_board->operator()(to_x, to_y);

    if (delta_x == 0) {

        if (getPiece != nullptr) {
            return 0;
        }
        // a pawn cant move backwards
        if ((m_is_white && m_y > to_y) || (!m_is_white && m_y < to_y)) {
            return 0;
        }
        // a pawn can move 2 steps if it is in its starting position
        if ( (m_is_white && m_y == lastRow && delta_y == 2 ) || (!m_is_white && m_y == start && delta_y == -2) ) {
           // check if there is a piece in the way
           if ( (*m_board)(to_x, to_y - 1) == nullptr) {
               return 1;
           }
        }
        // a pawn can move 1 step
        if ( (m_is_white && delta_y == 1) || (!m_is_white && delta_y == -1) ) {
            return 1;
        }

    } else if (delta_x == 1 && delta_y == 1) {
      
      if (getPiece != nullptr) {
        if (getPiece->isWhite() != m_is_white) {
          return 2;
        }
      }
    }
    return 0;
}

char32_t Pawn::utfRepresentation() {
    if (m_is_white) {
        // U+2659 is the unicode for the white pawn
        return U'\u2659';
    }
    // U+265F is the unicode for the black pawn
    return U'\u265F';
}

char Pawn::latin1Representation() {
    if (m_is_white) {
        return 'P';
    }
    return 'p';
}