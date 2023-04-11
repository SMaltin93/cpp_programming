#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <wchar.h>


using namespace std;

// ChessBoard::ChessBoard() {
//     this->m_state = Matrix<shared_ptr<ChessPiece>>(8);
// } 

void ChessBoard::movePiece(ChessMove chess_move) {
    

}

vector<ChessMove> ChessBoard::capturingMoves(bool is_white) {
    vector<ChessMove> moves;
    vector<ChessPiece *> pieces = is_white ? m_white_pieces : m_black_pieces;
    for (ChessPiece * piece : pieces) {
        vector<ChessMove> piece_moves = piece->capturingMoves();
        for (ChessMove move : piece_moves) {
            moves.push_back(move);
        }
    }
    return moves;
}

vector<ChessMove> ChessBoard::nonCapturingMoves(bool is_white) {
    vector<ChessMove> moves;
    vector<ChessPiece *> pieces = is_white ? m_white_pieces : m_black_pieces;
    for (ChessPiece * piece : pieces) {
        vector<ChessMove> piece_moves = piece->nonCapturingMoves();
        for (ChessMove move : piece_moves) {
            moves.push_back(move);
        }
    }
    return moves;
}

ChessBoard & operator>>(istream & is, ChessBoard & cb) {
    
    Matrix<shared_ptr<ChessPiece>> m(8, 8);
    
    for (int y = 0; y < 8; y++) {

        for (int x = 0; x < 8; x++) {
            char c; 
            is >> c;
            switch (c) {
            case 'K':
            m(x,y) = make_shared<King>(x, y, true, &cb);
            break;
            case 'k':
            m(x,y) = make_shared<King>(x, y, false, &cb);
            break;
            case 'Q':
            m(x,y) = make_shared<Queen>(x, y, true, &cb);
            break;
            case 'q':
            m(x,y) = make_shared<Queen>(x, y, false, &cb);
            break;
            case 'R':
            m(x,y) = make_shared<Rook>(x, y, true, &cb);
            break;
            case 'r':
            m(x,y) = make_shared<Rook>(x, y, false, &cb);
            break;
            case 'B':
            m(x,y) = make_shared<Bishop>(x, y, true, &cb);
            break;
            case 'b':
            m(x,y) = make_shared<Bishop>(x, y, false, &cb);
            break;
            case 'N':
            m(x,y) = make_shared<Knight>(x, y, true, &cb);
            break;
            case 'n':
            m(x,y) = make_shared<Knight>(x, y, false, &cb);
            break;
            case 'P':
            m(x,y) = make_shared<Pawn>(x, y, true, &cb);
            break;
            case 'p':
            m(x,y) = make_shared<Pawn>(x, y, false, &cb);
            break;
            case '.':
            m(x,y) = nullptr;
            break;
            }
            if (m(x,y) != nullptr) {
                 if (m(x,y)->isWhite()) {
                    cb.m_white_pieces.push_back(m(x,y).get());
                } else {
                    cb.m_black_pieces.push_back(m(x,y).get());
                }
            }
        }
    }
    cb.m_state = m;
    // add peices to white and black pieces
    return cb; 
}



ChessBoard & operator<<(ostream & os, ChessBoard & cb) {
    // print the board to the output stream , print utfRepresentation of each piece

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cb.m_state(i,j) == nullptr) {
                os << ".";
            } else {
                os << cb.m_state(i,j)->latin1Representation();
            }
        }
        os << endl;
    }
    return cb;
}


void ChessBoard::addPiece(int x, int y, shared_ptr<ChessPiece> piece) {
    
    if (piece->isWhite()) {
        m_white_pieces.push_back(piece.get());
    } else {
        m_black_pieces.push_back(piece.get());
    }
        
}

void ChessBoard::removePiece(int x, int y) {
    m_state(x,y) = nullptr;
    // remove (x,y) from white or black pieces
    vector<ChessPiece *> vector_to_remove_from;
    if (m_state(x,y)->isWhite()) {
        vector_to_remove_from = m_white_pieces;
    } else {
        vector_to_remove_from = m_black_pieces;
    } 

    for (auto it = vector_to_remove_from.begin(); it != vector_to_remove_from.end(); it++) {
        if ( (*it) == m_state(x,y).get() ) {
            vector_to_remove_from.erase(it);
            break;
        }
    }
}

shared_ptr<ChessPiece> ChessBoard::operator()(int x, int y) const {
    return m_state(x,y);
}
