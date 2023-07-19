//
// DD1388 - Lab 4: Losing Chess
//

#include "Rook.h"

Rook::Rook(int x, int y, bool is_white, ChessBoard *board) :  ChessPiece(x, y, is_white, board) {}

Rook::~Rook() {}

using namespace std;

int Rook::validMove(int to_x, int to_y) {
    int delta_x = abs(m_x - to_x);
    int delta_y = abs(m_y - to_y);
    shared_ptr<ChessPiece> getPiece = m_board->operator()(to_x, to_y);
    // if (delta_x == 0 && delta_y == 0) {
    if ( (delta_x == 0 && delta_y == 0) || (delta_x != 0 && delta_y != 0) ) {
        return 0;
    } 
    // rook canot capture its own piece
    if ( (getPiece != nullptr) && (getPiece->isWhite() == m_is_white) ) {
        return 0;
    }

    if ( delta_x == 0 ) {

        if (m_y < to_y) {

            for (int i = m_y + 1; i < to_y; i++) {
                if ((*m_board)(m_x, i) != nullptr) {
                    return 0;
                }
            }

        } else if (m_y > to_y) {

            for (int i = m_y - 1; i > to_y; i--) {
                if ((*m_board)(m_x, i) != nullptr) {
                    return 0;
                }
            }
        } 
    } else if (delta_y == 0) {

        if (m_x < to_x) {

            for (int i = m_x + 1; i < to_x; i++) {
                if ((*m_board)(i, m_y) != nullptr) {
                    return 0;
                }
            }
        } else if (m_x > to_x) {

            for (int i = m_x - 1; i > to_x; i--) {
                if ((*m_board)(i, m_y) != nullptr) {
                    return 0;
                }
            }
        } 
    }

    if ( (getPiece != nullptr )&& (getPiece->isWhite() != m_is_white) ) {
        return 2;
    }
    // the rook can move to an empty square
    if (getPiece == nullptr) {
        return 1;
    }

    return 0;
}


char32_t Rook::utfRepresentation() {
    if (m_is_white) {
        return U'\u2656';
    } else {
        return U'\u265C';
    }
}

char Rook::latin1Representation() {
    if (m_is_white) {
        return 'R';
    } else {
        return 'r';
    }
}