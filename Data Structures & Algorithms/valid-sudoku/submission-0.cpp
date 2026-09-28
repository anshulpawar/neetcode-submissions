class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        // check rows
        for(int i=0; i<n; i++)
        {
            vector<bool> seen(n + 1, false);
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == '.')
                    continue;
                if(seen[board[i][j] - '0'])
                    return false;

                seen[board[i][j] - '0'] = true;
            }
        }

        // check columns
        for(int j=0; j<n; j++)
        {
            vector<bool> seen(n + 1, false);
            for(int i=0; i<n; i++)
            {
                if(board[i][j] == '.')
                    continue;
                if(seen[board[i][j] - '0'])
                    return false;

                seen[board[i][j] - '0'] = true;
            }
        }

        // check sub boxes
        for(int i=0; i<n; i+=3)
        {
            for(int j=0; j<n; j+=3)
            {
                vector<bool> seen(n + 1, false);
                for(int k=i; k<i+3; k++)
                {
                    for(int l=j; l<j+3; l++)
                    {
                        if(board[k][l] == '.')
                            continue;
                        if(seen[board[k][l] - '0'])
                            return false;

                        seen[board[k][l] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
};