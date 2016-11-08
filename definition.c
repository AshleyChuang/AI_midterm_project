int board[15][15];
// board's current status which uses 99 to represent our stones, 66 for opponent's, 0 for vacant sites
// Need implementation!

int temp_board[15][15];
// temporary board, board's copy, in order to let grader() edit it

int cand_board[15][15];
// candidate board, a branch in Monte Carlo, for evaluator() to give it a score
