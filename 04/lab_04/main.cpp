//
// DD1388 - Lab 4: Losing Chess
//

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "King.h"

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
    chess.printBoard();
    return 0;

    // test if the board is set correctl

}