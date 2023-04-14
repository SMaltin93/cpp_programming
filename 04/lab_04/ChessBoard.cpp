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
    
    cout << m_black_pieces.size() << endl;
    cout << m_white_pieces.size() << endl;

    if (m_state(chess_move.to_x, chess_move.to_y) != nullptr) {
        removePiece(chess_move.to_x, chess_move.to_y, m_state(chess_move.to_x, chess_move.to_y).get());
    }

    ChessPiece *piece = chess_move.piece;
    piece->m_x = chess_move.to_x;
    piece->m_y = chess_move.to_y;

    m_state(chess_move.to_x, chess_move.to_y) = m_state(chess_move.from_x, chess_move.from_y); // move the piece to the new position

    m_state(chess_move.from_x, chess_move.from_y) = nullptr;


    
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
            if (cb.m_state(j,i) == nullptr) {
                os << ".";
            } else {
                os << cb.m_state(j,i)->latin1Representation();
            }
        }
        os << endl;
    }
    return cb;
}

void ChessBoard::removePiece(int x, int y , ChessPiece * piece) {
    // remove the piece from the board
    if (piece->isWhite()) {
        for (size_t i = 0; i < m_white_pieces.size(); i++) {
            if (m_white_pieces[i] == piece) {
                m_white_pieces.erase(m_white_pieces.begin() + i);
                break;
            }
        }
    } else {
        for (size_t i = 0; i < m_black_pieces.size(); i++) {
            if (m_black_pieces[i] == piece) {
                m_black_pieces.erase(m_black_pieces.begin() + i);
                break;
            }
        }
    }

    // remove from the board


}

shared_ptr<ChessPiece> ChessBoard::operator()(int x, int y) const {
    return m_state(x,y);
}
