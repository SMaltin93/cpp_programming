# TODO

* To run the program, navigate to the /lab_04 directory and execute the command " make game ai1='1' ai2='2' " to run the program with two AI players. Note that setting ai1 to 1 and ai2 to 2 will assign the white color to AI_1 and the black color to AI_2. You can run the command "make test_in" to run through the provided tests.


___________________________________________________________________________________________

AI 1 - random thinker 

If there are no capturing moves, this AI will perform a non capturing at random.
If there are several capturing moves, the AI will perform one of them at random.
If there is a pawn promotion, a random piece will be selected.

______________________________________________________________________

AI 2 - thinks one step ahead. but defaults to random

-If there are no capturing moves
Check if any non-capturing move will force a capturing move for the opponent.
If not, play a random move.

-If there are several capturing moves
Check if any capturing move will force a capturing move for the opponent
If not, play a random capturing move.

-If there is a pawn promotion
If possible, pick a piece that can not capture on its next move.
If not possible, promote to a random piece.