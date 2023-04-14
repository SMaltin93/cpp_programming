//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "King.h"
#include <iostream>
#include <random>


using namespace std;
void random_thinker(ChessBoard *, bool);

// Implement additional functions or classes of your choice

int main() {

ChessBoard chess;
    stringstream s;
    s << "rnbqkbnr" << endl;
    s << "pppppppp" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "........" << endl;
    s << "PPPPPPPP" << endl;
    s << "RNBQKBNR" << endl;
    s >> chess;
    vector<ChessMove> v = chess.capturingMoves(true);
    // print the board
    cout << chess;

    // start the game
    bool is_white = true;

    for (int i = 0; ; i++) {
        if (is_white) {
            random_thinker(&chess, is_white);
        } else {
            random_thinker(&chess, is_white);
        }
        cout << chess;
        is_white = !is_white;
    }
    
}

// At the end of the board, the rPawn transforms into any of Queen, Bishop, Knight or Rook.


// chose piec randomly
void random_thinker (ChessBoard *chess, bool is_white) {

// alla capture moves
vector<ChessMove> capture = chess->capturingMoves(is_white);
// alla non capture moves
vector<ChessMove> non_capture = chess->nonCapturingMoves(is_white);

    if (capture.size() > 0) {
        // random move
        int random = rand() % capture.size();
        chess->movePiece(capture[random]);
    } else if (non_capture.size() > 0) {
    // random move
        int random = rand() % non_capture.size();
        chess->movePiece(non_capture[random]);
    } else {
        cout << "No moves left" << endl;
    }
}
