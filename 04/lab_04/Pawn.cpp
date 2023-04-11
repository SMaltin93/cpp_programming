//
// DD1388 - Lab 4: Losing Chess
//

#include "Pawn.h"


using namespace std;

Pawn::Pawn(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board) {}

Pawn::~Pawn() {}



int Pawn::validMove(int to_x, int to_y) {
    int white_start = 6;
    int black_start = 1;
    int delta_x = abs(m_x - to_x);
    int delta_y = abs(m_y - to_y);
    shared_ptr<ChessPiece> piece = (*m_board)(to_x, to_y);

  
    // capturing 
    if (delta_x == 1 && delta_y == 1) {
        if (piece != nullptr  && piece->isWhite() != m_is_white) {
            if( (m_is_white && to_y < m_y) || (!m_is_white && to_y > m_y) ) {
                return 2;
            } 
        }
    }

    // non_capturing
    if (delta_x == 0 && piece == nullptr) {
        // handel the first move
        if (m_is_white && to_y < m_y) {

            if (m_y == white_start && delta_y == 2) {
                // dont allow jumping
                ChessPiece* p = (*m_board)(m_x, white_start-1).get();
                if (p == nullptr) {
                    return 1;
                } else {
                    return 0;
                }

            } else if (delta_y == 1) {
                return 1;
            }

        } else if (!m_is_white && to_y > m_y) {
            // dont allow jumping
            if (m_y == black_start && delta_y == 2) {
                ChessPiece* p = (*m_board)(m_x, black_start + 1).get();
                if (p == nullptr) {
                    return 1;
                } else {
                    return 0;
                }
            } else if (delta_y == 1) {
                return 1;
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