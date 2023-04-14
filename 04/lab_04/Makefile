all:
	g++ -Wall -o chess tests.cpp ChessBoard.cpp ChessPiece.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp
	

debug:
	g++ -Wall -g -o chess main.cpp ChessBoard.cpp ChessPiece.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp

main: 
	g++ -Wall -o chess main.cpp ChessBoard.cpp ChessPiece.cpp King.cpp Queen.cpp Bishop.cpp Knight.cpp Rook.cpp Pawn.cpp

ai: main
	./chess

testin: all
	./chess < tests.in 

git:
	git add .
	git commit -m "$(input)"
	git push