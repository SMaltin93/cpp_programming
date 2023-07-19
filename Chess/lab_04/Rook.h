//
// DD1388 - Lab 4: Losing Chess
//

#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"

class Rook : virtual public ChessPiece {

protected:
    int validMove(int to_x, int to_y) override;
    char32_t utfRepresentation() override;
    char latin1Representation() override;

public:
    Rook(int x, int y, bool is_white, ChessBoard *board); 
    ~Rook();

};


#endif //ROOK_H
