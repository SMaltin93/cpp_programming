//
// DD1388 - Lab 4: Losing Chess
//

#include "Knight.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include "ChessPiece.h"

#include <bits/stdc++.h>

using namespace std;


Knight::Knight(int x, int y, bool is_white, ChessBoard *board, Type type) : ChessPiece(x, y, is_white, board, peiceType) {}

// A possible implementation to check valid moves for knights is to check if Δx² + Δy² is 5.

int Knight::validMove(int to_x, int to_y) {
    int x = abs(m_x - to_x);
    int y = abs(m_y - to_y);
    // Returns 0 if target square is unreachable.
    if (x * x + y * y != 5) {
        return 0;
    }
    // Returns 1 if target square is reachable and empty
    if (m_board->getPiece(to_x, to_y) == nullptr) {
        return 1;
    }
    // Returns 2 if move captures a piece.
    if (m_board->getPiece(to_x, to_y)->isWhite() != m_is_white) {
        return 2;
    }
    return 0;
}

char32_t Knight::utfRepresentation() {
    if (m_is_white) {
        // U+2658 is the unicode for the white knight
        return U'\u2658';
    }
    // U+265E is the unicode for the black knight
    return U'\u265E';  
}

char Knight::latin1Representation() {
    if (m_is_white) {
        return 'N';
    }
    return 'n';
}

