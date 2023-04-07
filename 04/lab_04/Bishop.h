//
// DD1388 - Lab 4: Losing Chess
//

#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"

class Bishop : virtual public ChessPiece {
protected:
    int validMove(int to_x, int to_y) override;
    char32_t utfRepresentation() override;
    char latin1Representation() override;

public:
    Bishop(int x, int y, bool is_white, ChessBoard *board);
    ~Bishop();
};


#endif //BISHOP_H
