
#ifndef QUEEN_H
#define QUEEN_H

#include "ChessPiece.h"
#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop, public Rook {

    protected:

        int validMove(int to_x, int to_y) override;
        char32_t utfRepresentation() override;
        char latin1Representation() override;

    public:
        Queen(int x, int y, bool is_white, ChessBoard *board);
        virtual ~Queen(); 
};


#endif //QUEEN_H
