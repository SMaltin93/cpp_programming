//
// DD1388 - Lab 4: Losing Chess
//

#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <string>
#include <vector>
#include "ChessMove.h"
#include "ChessBoard.h"

using namespace std;

class ChessPiece {
    friend void ChessBoard::movePiece(ChessMove p);
    friend ChessBoard & operator<<(ostream & os, ChessBoard & cb);
    // friend printBoard(ChessBoard & cb);
    friend void ChessBoard::printBoard(ChessBoard *cb);
    friend void ChessBoard::ai1_moves(ChessBoard *, bool, vector<int> *, string*);
    friend void ChessBoard::ai2_moves(ChessBoard *, bool, vector<int> *, string*);
    friend void ChessBoard::removePiece(int, int, ChessPiece *, bool);

    friend void ChessBoard::switchPawn(ChessBoard *, int, int, bool);
    friend void ChessBoard::switchAI2(ChessBoard *, int, int, bool, char);
   

    friend pair<vector<int>, bool> ChessBoard::checkPawn(ChessMove const *);

    

    friend void ChessBoard::moveBack(int, int, int, int, ChessPiece *);



protected:                               // protected will cause problems with multiple inheritance
    int m_x, m_y;
    bool m_is_white;
    ChessBoard* m_board;

    /**
     * Returns 0 if target square is unreachable.
     * Returns 1 if target square is reachable and empty.
     * Returns 2 if move captures a piece.
     */
    virtual int validMove(int to_x, int to_y);
    virtual char32_t utfRepresentation();
    virtual char latin1Representation(); 


public:
    // Constructor
    
    ChessPiece(int x, int y, bool is_white, ChessBoard *board);
    // Destructor
    virtual ~ChessPiece();
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

    bool isWhite() const; 
    
    /**
    * For testing multiple inheritance
    */
    int unnecessary_int;


};


#endif //CHESSPIECE_H
