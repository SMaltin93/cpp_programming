//
// DD1388 - Lab 4: Losing Chess
//

#include "Knight.h"
#include "ChessBoard.h"
#include "ChessMove.h"
#include "ChessPiece.h"

#include <bits/stdc++.h>

using namespace std;


Knight::Knight(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board) {}


Knight::~Knight() {}

// A possible implementation to check valid moves for knights is to check if Δx² + Δy² is 5.

int Knight::validMove(int to_x, int to_y) {
    int delta_x = abs(m_x - to_x);
    int delta_y = abs(m_y - to_y);
    shared_ptr<ChessPiece> getPiece = m_board->operator()(to_x, to_y);
    if (delta_x  * delta_x  + delta_y * delta_y == 5) {
        if (getPiece->isWhite() == m_is_white) {
            return 0;
        }
        else if (getPiece->isWhite() != m_is_white) {
            return 2;
        }
        else {
            return 1;
        }
    } else {
        return 0;
    }    

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

