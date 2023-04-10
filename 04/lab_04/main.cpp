//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "King.h"
#include <iostream>


using namespace std;

// Implement additional functions or classes of your choice

int main() {

ChessBoard chess;
    stringstream s;
    s << ".....Q.." << endl;
    s << "...q...." << endl;
    s << "......Q." << endl;
    s << "q......." << endl;
    s << ".......Q" << endl;
    s << ".q......" << endl;
    s << "....Q..." << endl;
    s << "..q.....";
    s >> chess;
    vector<ChessMove> v = chess.capturingMoves(true);

    // print the board
    cout << chess;
    
    

    if (v.size() != 0) {
        cout << "capturingMoves FAILED, expected 0 moves but got " << v.size() << " moves" << endl;
    } else {
        cout << "capturingMoves PASSED, expected 0 moves and got " << v.size() << " moves" << endl;
    }

    // test if the board is set correctl


}