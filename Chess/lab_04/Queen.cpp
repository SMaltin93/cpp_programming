#include "Queen.h"
#include "ChessBoard.h"



Queen::Queen(int x, int y, bool is_white, ChessBoard *board) : ChessPiece(x, y, is_white, board), Bishop(x, y, is_white, board), Rook(x, y, is_white, board) {}


Queen::~Queen() {}

int Queen::validMove(int to_x, int to_y) {
    return max(Bishop::validMove(to_x, to_y), Rook::validMove(to_x, to_y));
}



char32_t Queen::utfRepresentation() {
    if (m_is_white) {
        return U'\u2655';
        // print U'\u2655' to see the unicode character
    } else {
        return U'\u265B';
    }
}

char Queen::latin1Representation() {
    if (m_is_white) {
        return 'Q';
    } else {
        return 'q';
    }
}