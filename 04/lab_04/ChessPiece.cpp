//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessPiece.h"
#include "ChessBoard.h"

int ChessPiece::validMove(int to_x, int to_y) {

}

char32_t ChessPiece::utfRepresentation() {
    // Implementation goes h
}

char ChessPiece::latin1Representation() {
    // Implementation goes here
}

ChessPiece::ChessPiece(int x, int y, bool is_white, ChessBoard *board)
/*:  Initialize members here */ {
    this->m_x = x;
    this->m_y = y;
    this->m_is_white = is_white;
    this->m_board = board;
}

bool ChessPiece::capturingMove(int to_x, int to_y) { // capture move means that the move is valid and the target square is occupied by a piece of the opposite color
    if (validMove(to_x, to_y) == 2) { 
        return true;
    }
    return false;
}

bool ChessPiece::nonCapturingMove(int to_x, int to_y) {
    if (validMove(to_x, to_y) == 1) {
        return true;
    }
    return false;
}

vector<ChessMove> ChessPiece::capturingMoves() {
    vector<ChessMove> capturing_moves;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (capturingMove(i, j)) {
                ChessMove move = {m_x, m_y, i, j, this};
                capturing_moves.push_back(move);
            }
        }
    }
    return capturing_moves;
}

vector<ChessMove> ChessPiece::nonCapturingMoves() {
    vector<ChessMove> non_capturing_moves;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (nonCapturingMove(i, j)) {
                ChessMove move = {m_x, m_y, i, j, this};
                non_capturing_moves.push_back(move);
            }
        }
    }
    return non_capturing_moves;
}
