//
// DD1388 - Lab 4: Losing Chess
//

#include "King.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include "ChessPiece.h"

#include <bits/stdc++.h>

using namespace std;



King::King(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board) {}

King::~King() {}

// the king formula is either Δx * Δy is one or Δx + Δy is one
// Let Δx be abs(x1-x2) and Δy be abs(y1-y2)
// Then either Δx * Δy is one or Δx + Δy is one


/**
 * Returns 0 if target square is unreachable.
 * Returns 1 if target square is reachable and empty.
 * Returns 2 if move captures a piece.
 */
int King::validMove(int to_x, int to_y) {
    int delta_x = abs(m_x - to_x);
    int delta_y = abs(m_y - to_y);
    ChessPiece getPiece = m_board->operator()(to_x, to_y); 
    if (delta_x * delta_y == 1 || delta_x + delta_y == 1) {

        if (getPiece.isWhite() == m_is_white) {
            return 0;
        }
        else if (getPiece.isWhite() != m_is_white) {
            return 2;
        }
        else {
            return 1;
        }
 
    } else {
        return 0;
    }
}

char32_t King::utfRepresentation() {
    if (m_is_white) {
        // U+2654 is the unicode for the white king
        return U'\u2654';
    }
    // U+265A is the unicode for the black king
    return U'\u265A';  
}

char King::latin1Representation() {
    if (m_is_white) {
        return 'K';
    }
    return 'k';
}

