int grader(board)
{
    int j_, i_, j��, m;
    for (i = 0, i < 15, i += 1)
    {
        for (j = 0, j < 15, j += 1)
        {
            if (board[i][j] == 90)
            {
                for (n = -3, n <= 4, n += 1)
                {
                    j_ = j + n;
    		    i_ = i + n;
    		    j�� = j - n;
    		    m = 4 - abs(n);
    		    if (j_ >= 0 and j_ <= 14 and board[i ][j_] != 99 and board[i ][j_] != 66)
    		    {
                        board[i ][ j_] += m;
    		    }
    		    if (i_ >= 0 and i_ <= 14 and board[i_][j_] != 99 and board[i_][j_] != 66)
    		    {
    			board[i_][ j_] += m;
    		    }
    		    if (i_ >= 0 and i_ <= 14 and board[i_][j ] != 99 and board[i_][j ] != 66)
    		    {
    			board[i_][ j ] += m;
    		    }
    		    if (j�� >= 0 and j�� <= 14 and board[i_][j��] != 99 and board[i_][j��] != 66)
    		    {
    			board[i_][ j��] += m;
    		    }
    		}
    	    }
    	    else if (board[i][j] == 66)
    	    {
                for (n = -3, n <= 4, n += 1)
    		{
                    j_ = j + n;
                    i_ = i + n;
                    j�� = j - n;
                    m = 4 - abs(n);
    		    if (j_ >= 0 and j_ <= 14 and board[i ][j_] != 99 and board[i ][j_] != 66)
    		    {
                        board[i ][ j_] -= m;
    		    }
    		    if (i_ >= 0 and i_ <= 14 and board[i_][j_] != 99 and board[i_][j_] != 66)
    		    {
                        board[i_][ j_] -= m;
    		    }
                    if (i_ >= 0 and i_ <= 14 and board[i_][j ] != 99 and board[i_][j ] != 66)
    		    {
    			board[i_][ j ] -= m;
                    }
                    if (j�� >= 0 and j�� <= 14 and board[i_][j��] != 99 and board[i_][j��] != 66)
    		    {
                        board[i_][ j��] -= m;
    		    }
    		}
    	    }
    	}
    }
}