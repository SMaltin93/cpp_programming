#include "ChessBoard.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <wchar.h>
#include <string>
#include <random>


using namespace std;
 // remove the piece from the board


void ChessBoard::movePiece(ChessMove chess_move) {
    
    if (m_state(chess_move.to_x, chess_move.to_y) != nullptr) {
        removePiece(chess_move.to_x, chess_move.to_y, m_state(chess_move.to_x, chess_move.to_y).get(), false);
    }

    ChessPiece *piece = chess_move.piece;
    piece->m_x = chess_move.to_x;
    piece->m_y = chess_move.to_y;
    m_state(chess_move.to_x, chess_move.to_y) = m_state(chess_move.from_x, chess_move.from_y); // move the piece to the new position
    m_state(chess_move.from_x, chess_move.from_y) = nullptr; 

    // check if pawn can be switched
    pair<vector<int>, bool> pawn = checkPawn(piece);
    if (pawn.second) {
        switchPawn(this, pawn.first[0], pawn.first[1], piece->isWhite());
    }
 
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


void ChessBoard::printBoard(ChessBoard * cb) {
    // print the board to the output stream , print utfRepresentation of each piece
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (cb->m_state(j,i) == nullptr) {
                cout << ". " ;
            } else {
                cout <<  presentPiecesAsUnicode(cb->m_state(j,i)->latin1Representation()) << " ";
            }
        }
        cout << endl;
    }
}

string ChessBoard::presentPiecesAsUnicode(char piece) {
    // return as red or black
    if (piece == 'K') return "♚";
    if (piece == 'k') return "♔";
    if (piece == 'Q') return "♛";
    if (piece == 'q') return "♕";
    if (piece == 'R') return "♜";
    if (piece == 'r') return "♖";
    if (piece == 'B') return "♝";
    if (piece == 'b') return "♗";
    if (piece == 'N') return "♞";
    if (piece == 'n') return "♘";
    if (piece == 'P') return "♟";
    if (piece == 'p') return "♙";

    return "";
  }

void ChessBoard::removePiece(int x, int y , ChessPiece * piece, bool pawn_prompted) {
   
    if (piece->isWhite()) {
        for (size_t i = 0; i < m_white_pieces.size(); i++) {
            if (m_white_pieces[i] == piece) {
                m_white_pieces.erase(m_white_pieces.begin() + i);
                // the black captured a white piece
                if (pawn_prompted) break;
                cout << "Black captured the white piece " << black_capture_white.append(" "+presentPiecesAsUnicode(piece->latin1Representation())+" ") << endl;
                break;
            }
        }
    } else {
        for (size_t i = 0; i < m_black_pieces.size(); i++) {
            if (m_black_pieces[i] == piece) {
                m_black_pieces.erase(m_black_pieces.begin() + i);
                // the white captured a black piece
                if (pawn_prompted) break;
                cout << "White captured the black piece " << white_capture_black.append(" "+presentPiecesAsUnicode(piece->latin1Representation())+" ") << endl;
                break;
            }
        }
    }

}

shared_ptr<ChessPiece> ChessBoard::operator()(int x, int y) const {
    return m_state(x,y);
}

int ChessBoard::generateRandomNumber(int const min, int const max) {
    // generate a random number between min and max
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void ChessBoard::ai1_moves(ChessBoard *chess, bool is_white, vector<int> *game_scoure, string *piece) {
// alla capture moves
vector<ChessMove> capture = chess->capturingMoves(is_white);
// alla non capture moves
vector<ChessMove> non_capture = chess->nonCapturingMoves(is_white);

    // check the paw

    if (capture.size() > 0) {
        // random move
        int random = generateRandomNumber(0, capture.size() - 1);
        chess->movePiece(capture[random]);
        // update the game score
        game_scoure->at(2)++;
        // update the piece
        *piece = " " + presentPiecesAsUnicode(capture[random].piece->latin1Representation()) + " ";
        
    } else if (non_capture.size() > 0) {
    // random move
        int random = generateRandomNumber(0, non_capture.size() - 1);
        chess->movePiece(non_capture[random]);
        *piece = " " + presentPiecesAsUnicode(non_capture[random].piece->latin1Representation()) + " ";

        // check if the pawn is in the last row
      
        // int pawn_y = is_white ? 0 : 7;
        // char c = (pawn_y == 0) ? 'P' : 'p';
        // for (int pawn_x = 0; pawn_x < 8; pawn_x++) {
        //     if (chess->m_state(pawn_x, pawn_y) != nullptr && chess->m_state(pawn_x, pawn_y)->latin1Representation() == c) {
        //         // the pawn is in the last row
        //         switchPawn(chess, pawn_x, pawn_y, is_white);
        //     }
        // }

        
    } else {
        cout << (is_white ? " white, " : " black, ") << " No moves left for the AI 1 player " << endl;
    }
}


void ChessBoard::ai2_moves(ChessBoard *chess, bool is_white, vector<int> *game_scoure, string *piece) {

    vector<ChessMove> capture = chess->capturingMoves(is_white);
    vector<ChessMove> non_capture = chess->nonCapturingMoves(is_white);
    bool can_capture = false;

    // will minimize the number of capturing moves for the opponent
    if (non_capture.size() > 0) {

        for (auto &move : non_capture) {
            // save the current position for moving back
            int from_x = move.from_x;
            int from_y = move.from_y;
            int to_x = move.to_x;
            int to_y = move.to_y;
            ChessPiece *p = move.piece;
            // make the move
            chess->movePiece(move);
            vector<ChessMove> opponent_capture = chess->capturingMoves(!is_white);
            if (opponent_capture.size() > 0) {
                // delete the move from the possible moves
                for (size_t i = 0; i < non_capture.size(); i++) {
                    if (non_capture[i].piece == move.piece) {
                        non_capture.erase(non_capture.begin() + i);
                    }
                }
                can_capture = true;
                chess->movePiece(ChessMove{to_x, to_y, from_x, from_y, p}); 
                break;
            }else chess->movePiece(ChessMove{to_x, to_y, from_x, from_y, p}); 
        }
        
        if (can_capture) {
            
            if (capture.size() > 0) {
                int random = generateRandomNumber(0, capture.size() - 1);
                chess->movePiece(capture[random]);
                // update the game score
                game_scoure->at(3)++;
                // update the piece
                *piece = " " + presentPiecesAsUnicode(capture[random].piece->latin1Representation()) + " ";
                can_capture = false;
            } else {
                int random = generateRandomNumber(0, non_capture.size() - 1);
                chess->movePiece(non_capture[random]);
                *piece = " " + presentPiecesAsUnicode(non_capture[random].piece->latin1Representation()) + " ";
                can_capture = false;
            }

        } else {
            int random = generateRandomNumber(0, non_capture.size() - 1);
            chess->movePiece(non_capture[random]);
            *piece = " " + presentPiecesAsUnicode(non_capture[random].piece->latin1Representation()) + " ";
        }

    } else if (capture.size() > 0) {

        for (auto &move : capture) {
            // save the current position for moving back
            int from_x = move.from_x;
            int from_y = move.from_y;
            int to_x = move.to_x;
            int to_y = move.to_y;
            ChessPiece *p = move.piece;
            // make the move
            chess->movePiece(move);
            vector<ChessMove> opponent_capture = chess->capturingMoves(!is_white);
            if (opponent_capture.size() > 0) {
                // delete the move from the possible moves
                for (size_t i = 0; i < capture.size(); i++) {
                    if (capture[i].piece == move.piece) {
                        capture.erase(capture.begin() + i);
                    }
                }
                chess->movePiece(ChessMove{to_x, to_y, from_x, from_y, p});
                can_capture = true;
                break;
            } else chess->movePiece(ChessMove{to_x, to_y, from_x, from_y, p});  

        }  if (can_capture) {
            // random move
            int random = generateRandomNumber(0, capture.size() - 1);
            chess->movePiece(capture[random]);
            // update the game score
            game_scoure->at(3)++;
            // update the piece
            *piece = " " + presentPiecesAsUnicode(capture[random].piece->latin1Representation()) + " ";
            can_capture = false;
        } else {
            int random = generateRandomNumber(0, non_capture.size() - 1);
            chess->movePiece(non_capture[random]);
            *piece = " " + presentPiecesAsUnicode(non_capture[random].piece->latin1Representation()) + " ";
        }
        
    } else {
        cout << "Color " << (is_white ? " white, " : " black, ") << " No moves left for the AI 2 player " << endl;
    }

}

/*
@function: check if the pawn is in the last row
@input: the piece that we want to check
@output: the position(x,y) and true if the pawn is in the last/first row and (0, 0) and false otherwise
*/ 
  pair<vector<int>, bool> ChessBoard::checkPawn(ChessPiece *piece) {
    // check if the pawn is in the last row
    int pawn_y =  piece->isWhite() ? 0 : 7;
    char c = (pawn_y == 0) ? 'P' : 'p';
    for (int pawn_x = 0; pawn_x < 8; pawn_x++) {
        if (m_state(pawn_x, pawn_y) != nullptr && m_state(pawn_x, pawn_y)->latin1Representation() == c) {
            // the pawn is in the last row
            return make_pair(vector<int>{pawn_x, pawn_y}, true);
        }
        }
    return make_pair(vector<int>{0, 0}, false);
  }

/*  
@function: switch the pawn to a random piece
@input: the position of the pawn and the color of the pawn

*/

void ChessBoard::switchPawn(ChessBoard *chess, int pawn_x, int pawn_y, bool is_white_p){
    // vector of the white pieces
    vector<char> white_pieces = {'Q', 'B', 'N', 'R', 'K'};
    // vector of the black pieces
    vector<char> black_pieces = {'q', 'b', 'n', 'r', 'k'};
    // chose random 
    int random = generateRandomNumber(0, 4);

    removePiece(pawn_x, pawn_y, chess->m_state(pawn_x, pawn_y).get(), true);

        // check if the pawn is in the last row
    if (is_white_p) {
        cout << "A white pawn has been promoted to a " << presentPiecesAsUnicode(white_pieces[random]) << endl;
        switch (white_pieces[random])
        {
        case 'Q':
            chess->m_state(pawn_x, pawn_y) = make_shared<Queen>(pawn_x, pawn_y, is_white_p, chess);
            m_white_pieces.push_back(chess->m_state(pawn_x, pawn_y).get());
            break;
        case 'B':
            chess->m_state(pawn_x , pawn_y) = make_shared<Bishop>(pawn_x, pawn_y, is_white_p, chess);
            m_white_pieces.push_back(chess->m_state(pawn_x, pawn_y).get());
            break;
        case 'N':
            chess->m_state(pawn_x , pawn_y) = make_shared<Knight>(pawn_x, pawn_y, is_white_p, chess);
            m_white_pieces.push_back(chess->m_state(pawn_x, pawn_y).get());
            break;
        case 'R':
            chess->m_state(pawn_x , pawn_y) = make_shared<Rook>(pawn_x, pawn_y, is_white_p, chess);
            m_white_pieces.push_back(chess->m_state(pawn_x, pawn_y).get());
            break;
        case 'K':
            chess->m_state(pawn_x , pawn_y) = make_shared<King>(pawn_x, pawn_y, is_white_p, chess);
            m_white_pieces.push_back(chess->m_state(pawn_x, pawn_y).get());
            break;
        default:
            break;
        }

    } else {
        cout << "A black pawn has been promoted to a " << presentPiecesAsUnicode(black_pieces[random]) << endl;
        switch (black_pieces[random])
        {
        case 'q':
            chess->m_state(pawn_x , pawn_y) = make_shared<Queen>(pawn_x, pawn_y, is_white_p, chess);
            m_black_pieces.push_back(chess->m_state(pawn_x , pawn_y).get());
            break;
        case 'b':
            chess->m_state(pawn_x , pawn_y) = make_shared<Bishop>(pawn_x, pawn_y, is_white_p, chess);
            m_black_pieces.push_back(chess->m_state(pawn_x , pawn_y).get());
            break;
        case 'n':
            chess->m_state(pawn_x , pawn_y) = make_shared<Knight>(pawn_x, pawn_y, is_white_p, chess);
            m_black_pieces.push_back(chess->m_state(pawn_x , pawn_y).get());
            break;
        case 'r':
            chess->m_state(pawn_x , pawn_y) = make_shared<Rook>(pawn_x, pawn_y, is_white_p, chess);
            m_black_pieces.push_back(chess->m_state(pawn_x , pawn_y).get());
            break;
        case 'k':
            chess->m_state(pawn_x , pawn_y) = make_shared<King>(pawn_x, pawn_y, is_white_p, chess);
            m_black_pieces.push_back(chess->m_state(pawn_x , pawn_y).get());
            break;
        }
    }
    
    
}
