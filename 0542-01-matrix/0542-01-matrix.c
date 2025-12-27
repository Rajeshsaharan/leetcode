#define MAX 1000000

int queue[MAX][2];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}

void dequeue(int *x, int *y) {
    *x = queue[front][0];
    *y = queue[front][1];
    front++;
}

int isEmpty() {
    return front == rear;
}

int** updateMatrix(int** mat, int matSize, int* matColSize,
                   int* returnSize, int** returnColumnSizes) {

    int **result = malloc(sizeof(int*) * matSize);
    *returnColumnSizes = malloc(sizeof(int) * matSize);
    *returnSize = matSize;

    for(int i = 0; i < matSize; i++) {
        result[i] = malloc(sizeof(int) * matColSize[i]);
        (*returnColumnSizes)[i] = matColSize[i];
        for(int j = 0; j < matColSize[i]; j++) {
            if(mat[i][j] == 0) {
                result[i][j] = 0;
                enqueue(i, j);
            } else {
                result[i][j] = -1;
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!isEmpty()) {
        int x, y;
        dequeue(&x, &y);

        for(int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx >= 0 && nx < matSize &&
               ny >= 0 && ny < matColSize[nx] &&
               result[nx][ny] == -1) {

                result[nx][ny] = result[x][y] + 1;
                enqueue(nx, ny);
            }
        }
    }

    return result;
}
