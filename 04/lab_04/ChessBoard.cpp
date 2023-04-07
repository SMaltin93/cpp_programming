#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"


void ChessBoard::movePiece(ChessMove chess_move) {
    // Implementation goes here
}

vector<ChessMove> ChessBoard::capturingMoves(bool is_white) {
    // Implementation goes here
}

vector<ChessMove> ChessBoard::nonCapturingMoves(bool is_white) {
    // Implementation goes here
}

ChessBoard & operator>>(istream & is, ChessBoard & cb) {
    // Implementation goes here
}

ChessBoard & operator<<(ostream & os, ChessBoard & cb) {
    // Implementation goes here
}


void ChessBoard::setPiece(int x, int y, ChessPiece * piece) {
    m_state(x,y) = make_shared<ChessPiece>(*piece);
}

void ChessBoard::removePiece(int x, int y) {
    m_state(x,y) = nullptr;
}

ChessPiece & ChessBoard::operator()(int x, int y) const {
    // board (i,j) returns the piece at position (i,j)
    return *m_state(x,y);
}