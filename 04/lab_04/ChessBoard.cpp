#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

using namespace std;

ChessBoard::ChessBoard() {
    this->m_state = Matrix<shared_ptr<ChessPiece>>(8);
} 

void ChessBoard::movePiece(ChessMove chess_move) {
    
    shared_ptr<ChessPiece> piece = m_state(chess_move.from_x, chess_move.from_y);
    m_state(chess_move.to_x, chess_move.to_y) = piece;
    m_state(chess_move.from_x, chess_move.from_y) = nullptr;

}

vector<ChessMove> ChessBoard::capturingMoves(bool is_white) {
    vector<ChessMove> moves;
    vector<ChessPiece *> pieces;
    if(is_white) {
        pieces = m_white_pieces;
    } else {
        pieces = m_black_pieces;
    }
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
    vector<ChessPiece *> pieces;
    if(is_white) {
        pieces = m_white_pieces;
    } else {
        pieces = m_black_pieces;
    }
    for (ChessPiece * piece : pieces) {
        vector<ChessMove> piece_moves = piece->nonCapturingMoves();
        for (ChessMove move : piece_moves) {
            moves.push_back(move);
        }
    }
    return moves;
}

ChessBoard & operator>>(istream & is, ChessBoard & cb) {
    Matrix<shared_ptr<ChessPiece>> m_state(8);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c; 
            is >> c;
            switch (c) {
            case 'K':
            m_state(i,j) = make_shared<King>(i, j, true, &cb);
            break;
            case 'k':
            m_state(i,j) = make_shared<King>(i, j, false, &cb);
            break;
            case 'Q':
            m_state(i,j) = make_shared<Queen>(i, j, true, &cb);
            cout << m_state(i,j)->utfRepresentation() << endl;
            break;
            case 'q':
            m_state(i,j) = make_shared<Queen>(i, j, false, &cb);
            break;
            case 'R':
            m_state(i,j) = make_shared<Rook>(i, j, true, &cb);
            break;
            case 'r':
            m_state(i,j) = make_shared<Rook>(i, j, false, &cb);
            break;
            case 'B':
            m_state(i,j) = make_shared<Bishop>(i, j, true, &cb);
            break;
            case 'b':
            m_state(i,j) = make_shared<Bishop>(i, j, false, &cb);
            break;
            case 'N':
            m_state(i,j) = make_shared<Knight>(i, j, true, &cb);
            break;
            case 'n':
            m_state(i,j) = make_shared<Knight>(i, j, false, &cb);
            break;
            case 'P':
            m_state(i,j) = make_shared<Pawn>(i, j, true, &cb);
            break;
            case 'p':
            m_state(i,j) = make_shared<Pawn>(i, j, false, &cb);
            break;
            case '.':
            m_state(i,j) = nullptr;
            break;
            }
            // add piece to white or black pieces
            if (m_state(i,j) != nullptr) {
                cb.addPiece(i,j, m_state(i,j));
            }
        }

    }

    return cb; 
}



ChessBoard & operator<<(ostream & os, ChessBoard & cb) {
    // print the board to the output stream , print utfRepresentation of each piece

  
    os << cb.m_state;
         
       
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
