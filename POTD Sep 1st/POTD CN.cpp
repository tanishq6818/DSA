void setMatrixOnes(vector<vector<int>> &MAT, int n, int m)
{
    set<int> rows_with_ones;
    set<int> cols_with_ones;

    // Step 1: Find rows and columns with 1s
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (MAT[i][j] == 1)
            {
                rows_with_ones.insert(i);
                cols_with_ones.insert(j);
            }
        }
    }

    // Step 2: Set elements to 1 in identified rows and columns
    for (int i : rows_with_ones)
    {
        for (int j = 0; j < m; ++j)
        {
            MAT[i][j] = 1;
        }
    }

    for (int j : cols_with_ones)
    {
        for (int i = 0; i < n; ++i)
        {
            MAT[i][j] = 1;
        }
    }
}
