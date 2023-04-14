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

    if (getPiece != nullptr && getPiece->isWhite() == m_is_white) return 0;

    //  not jumping over pieces
    for (int i = 1; i < delta_x; i++) { // i = 1 because we don't need to check the first square

        if (m_x < to_x && m_y < to_y) {

            if ((*m_board)(m_x + i, m_y + i) != nullptr) return 0; // case that x , y + 1 is not empty

        } else if (m_x < to_x && m_y > to_y) {

            if ((*m_board)(m_x + i, m_y - i) != nullptr) return 0; // case that x , y - 1 is not empty

        } else if (m_x > to_x && m_y < to_y) {

            if ((*m_board)(m_x - i, m_y + i) != nullptr) return 0; // case that x , y + 1 is not empty

        } else if (m_x > to_x && m_y > to_y) {
            
            if ((*m_board)(m_x - i, m_y - i) != nullptr) return 0;     // case that x , y - 1 is not empty
        }

    }

    // return 2 cases ////////////////////////////////////////////////////

    if (getPiece != nullptr && getPiece->isWhite() != m_is_white) return 2; // capture

    if (getPiece == nullptr) return 1; // move

    return 0;
    
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