//
// DD1388 - Lab 4: Losing Chess
//

#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <vector>
#include "ChessMove.h"
#include "ChessBoard.h"

using namespace std;

enum Type {King, Knight, Pawn, Queen, Rook, Bishop};


class ChessPiece {
    friend void ChessBoard::movePiece(ChessMove p);
    friend void ChessBoard::setBoard(Matrix<shared_ptr<ChessPiece>> board);
   

protected:                               // protected will cause problems with multiple inheritance so solve it by using composition instead
    int m_x, m_y;
    bool m_is_white;
    ChessBoard* m_board;
    Type peiceType; 


    /**
     * Returns 0 if target square is unreachable.
     * Returns 1 if target square is reachable and empty.
     * Returns 2 if move captures a piece.
     */
    virtual int validMove(int to_x, int to_y) = 0;
    virtual char32_t utfRepresentation() = 0;
    virtual char latin1Representation() = 0; 
    
    


public:
    // Constructor
    ChessPiece(int x, int y, bool is_white, ChessBoard * board, Type type);
    /**
     * Checks if this move is valid for this piece and captures
     * a piece of the opposite color.
     */
    bool capturingMove(int to_x, int to_y);
    /**
     * Checks if this move is valid but does not capture a piece.
     */
    bool nonCapturingMove(int to_x, int to_y);
    virtual vector<ChessMove> capturingMoves();
    virtual vector<ChessMove> nonCapturingMoves();

    // make that possible to access the protected members
    bool isWhite();
    // get type 
    Type getType();
    
   
    /**
    * For testing multiple inheritance
    */
    int unnecessary_int;


};


#endif //CHESSPIECE_H
