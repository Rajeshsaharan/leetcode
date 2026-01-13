int dp[205][205];

int helper(int **triangle, int triangleSize, int *triangleColSize, int i, int j) {
    if (i == triangleSize - 1)
        return triangle[i][j];

    if (dp[i][j] != INT_MAX)
        return dp[i][j];

    int value1 = triangle[i][j] +
                 helper(triangle, triangleSize, triangleColSize, i + 1, j);

    int value2 = triangle[i][j] +
                 helper(triangle, triangleSize, triangleColSize, i + 1, j + 1);

    dp[i][j] = value1 < value2 ? value1 : value2;
    return dp[i][j];
}

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    for (int i = 0; i < triangleSize; i++)
        for (int j = 0; j < triangleColSize[i]; j++)
            dp[i][j] = INT_MAX;

    return helper(triangle, triangleSize, triangleColSize, 0, 0);
}
