#include <stdlib.h>

void dfs(int **image, int imageSize, int *imageColSize, int i, int j, int startColor, int newColor)
{
    if (i < 0 || j < 0 || i >= imageSize || j >= imageColSize[i])
        return;

    if (image[i][j] != startColor)
        return;

    image[i][j] = newColor;

    dfs(image, imageSize, imageColSize, i + 1, j, startColor, newColor);
    dfs(image, imageSize, imageColSize, i - 1, j, startColor, newColor);
    dfs(image, imageSize, imageColSize, i, j + 1, startColor, newColor);
    dfs(image, imageSize, imageColSize, i, j - 1, startColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize,
                int sr, int sc, int color,
                int* returnSize, int** returnColumnSizes)
{
    int startColor = image[sr][sc];

    if (startColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = malloc(sizeof(int) * imageSize);
        for (int i = 0; i < imageSize; i++)
            (*returnColumnSizes)[i] = imageColSize[i];
        return image;
    }

    dfs(image, imageSize, imageColSize, sr, sc, startColor, color);

    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++)
        (*returnColumnSizes)[i] = imageColSize[i];

    return image;
}