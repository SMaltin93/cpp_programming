//
// DD1388 - Lab 4: Losing Chess
//

#ifndef PAWN_H
#define PAWN_H

#include "ChessPiece.h"

class Pawn : public ChessPiece {
    // Override virtual methods from ChessPiece here
      protected:
        int validMove(int to_x, int to_y) override;
        char32_t utfRepresentation() override;
        char latin1Representation() override;

    public:
        Pawn(int x, int y, bool is_white, ChessBoard *board, Type type);
        virtual ~Pawn();
};


#endif //PAWN_H
