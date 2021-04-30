class Solution
{
public:
    vector<vector<int>> win_cond = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    bool win(vector<char> board, char c)
    {
        int cnt = 0;
        for (auto x : win_cond)
        {
            cnt = 0;
            for (auto y : x)
            {
                if (board[y] == c)
                {
                    cnt += 1;
                }
            }
            if (cnt == 3)
            {
                return 1;
            }
        }

        return 0;
    }

    bool isValid(char b[9])
    {
        vector<char> board;
        for (int i = 0; i < 9; i++)
        {
            board.push_back(b[i]);
        }
        bool o_win = win(board, 'O');
        bool x_win = win(board, 'X');
        int x_cnt = 0, o_cnt = 0;
        for (auto x : board)
        {
            if (x == 'X')
            {
                x_cnt += 1;
            }
            else
            {
                o_cnt += 1;
            }
        }

        if (x_win and x_cnt != o_cnt + 1)
        {
            return 0;
        }
        if (o_win and x_cnt != o_cnt)
        {
            return 0;
        }
        if (o_win and x_win)
        {
            return 0;
        }
        if (o_cnt >= x_cnt)
        {
            return 0;
        }
        return 1;
    }
};
