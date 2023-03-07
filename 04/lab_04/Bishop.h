//
// DD1388 - Lab 4: Losing Chess
//

#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class Bishop : public ChessPiece {
    
public:
    Bishop(int x, int y, bool is_white, ChessBoard * board);
    int validMove(int to_x, int to_y);
    char32_t utfRepresentation();
    char latin1Representation();
    vector<ChessMove> capturingMoves();
    vector<ChessMove> nonCapturingMoves();
};


#endif //BISHOP_H
