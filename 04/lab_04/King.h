//
// DD1388 - Lab 4: Losing Chess
//

#ifndef KING_H
#define KING_H

#include "ChessPiece.h"
#include <bits/stdc++.h>

class King : public ChessPiece {
    // Override virtual methods from ChessPiece here

friend ChessPiece;

protected:
    int validMove(int to_x, int to_y) override;
    char32_t utfRepresentation() override;
    char latin1Representation() override;


public:
    King(int x, int y, bool is_white, ChessBoard *board);
    ~King();
};


#endif //KING_H
