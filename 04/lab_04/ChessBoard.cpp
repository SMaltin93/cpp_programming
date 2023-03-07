//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"




using namespace std;

void ChessBoard::movePiece(ChessMove chess_move) {
    shared_ptr<ChessPiece> piece = m_state(chess_move.from_x, chess_move.from_y); // my_state is a Matrix<shared_ptr<ChessPiece>> and has tow arguments row and column
    // changing the position x, y of the piece
    piece->m_x = chess_move.to_x;   
    piece->m_y = chess_move.to_y;
    // moving the piece to the new position
    m_state(chess_move.to_x, chess_move.to_y) = piece;
    // removing the piece from the old position
    m_state(chess_move.from_x, chess_move.from_y) = nullptr;
}

vector<ChessMove> ChessBoard::capturingMoves(bool is_white) {

    vector<ChessMove> capturing_moves; // vector of ChessMove
    vector<ChessPiece *> pieces; // vector of pointers to ChessPiece
    if (is_white) { // if the player is white
        pieces = m_white_pieces; // pieces is a vector of pointers to ChessPiece
    } else { // if the player is black 
        pieces = m_black_pieces; // pieces is a vector of pointers to ChessPiece
    }
    for (ChessPiece * piece : pieces) { // for each piece in pieces
        vector<ChessMove> piece_moves = piece->capturingMoves(); // piece_moves is a vector of ChessMove
        for (ChessMove move : piece_moves) { // for each move in piece_moves 
            capturing_moves.push_back(move); // add the move to capturing_moves
        } 
    }
    return capturing_moves; // return the vector of ChessMove

}

vector<ChessMove> ChessBoard::nonCapturingMoves(bool is_white) {
            
        vector<ChessMove> non_capturing_moves; // vector of ChessMove
        vector<ChessPiece *> pieces; // vector of pointers to ChessPiece
        if (is_white) { // if the player is white
            pieces = m_white_pieces; // pieces is a vector of pointers to ChessPiece
        } else { // if the player is black 
            pieces = m_black_pieces; // pieces is a vector of pointers to ChessPiece
        }
        for (ChessPiece * piece : pieces) { // for each piece in pieces
            vector<ChessMove> piece_moves = piece->nonCapturingMoves(); // piece_moves is a vector of ChessMove
            for (ChessMove move : piece_moves) { // for each move in piece_moves 
                non_capturing_moves.push_back(move); // add the move to non_capturing_moves
            } 
        }
        return non_capturing_moves; // return the vector of ChessMove
    
}
