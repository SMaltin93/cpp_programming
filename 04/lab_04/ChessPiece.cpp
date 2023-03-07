//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessPiece.h"
#include "ChessBoard.h"
// Implenet value så we can se if we create create a new object 
int ChessPiece::validMove(int to_x, int to_y) {

    return 0;
}

char32_t ChessPiece::utfRepresentation() {

    return 0;

}

char ChessPiece::latin1Representation() {
    
    return 0;
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

// capturingMoves returns a vector with ChessMoves that captures a piece of the opposing color
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

// nonCapturingMoves returns a vector with ChessMoves that moves to an empty space.

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

bool ChessPiece::isWhite() {
    return m_is_white;
}
