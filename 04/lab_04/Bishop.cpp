//
// DD1388 - Lab 4: Losing Chess
//

#include "Bishop.h"

// Implement method definitions here

Bishop::Bishop(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board) {}

Bishop::~Bishop() {}

int Bishop::validMove(int to_x, int to_y) {

    int delta_x = abs(m_x - to_x);
    int delta_y = abs(m_y - to_y);
    shared_ptr<ChessPiece> getPiece = m_board->operator()(to_x, to_y);
    
    // return 0 cases ////////////////////////////////////////////////////
    // move only diagonally,
    if  (delta_x == 0 || delta_y == 0 || delta_x != delta_y) return 0;

     // not capturing own pieces,

    if (getPiece != NULL && getPiece->isWhite() == m_is_white) return 0;

    //  not jumping over pieces
    for (int i = 1; i < delta_x; i++) {
        if (m_x < to_x && m_y < to_y) {
            if ((*m_board)(m_x + i, m_y + i) != NULL) return 0;
        } else if (m_x < to_x && m_y > to_y) {
            if ((*m_board)(m_x + i, m_y - i) != NULL) return 0;
        } else if (m_x > to_x && m_y < to_y) {
            if ((*m_board)(m_x - i, m_y + i) != NULL) return 0;
        } else if (m_x > to_x && m_y > to_y) {
            if ((*m_board)(m_x - i, m_y - i) != NULL) return 0;
        }
    }

    // return 2 cases ////////////////////////////////////////////////////

    if (getPiece != NULL && getPiece->isWhite() != m_is_white) return 2;

    return 1;
    
}


char32_t Bishop::utfRepresentation() {
    if (m_is_white) {
        return U'\u2657';
    } else {
        return U'\u265D';
    }
}

char Bishop::latin1Representation() {
    if (m_is_white) {
        return 'B';
    } else {
        return 'b';
    }
}