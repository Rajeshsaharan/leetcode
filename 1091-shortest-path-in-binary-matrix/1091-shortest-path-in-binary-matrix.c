#define MAX 1000000

int queue[MAX][2];
int front = 0, rear = 0;

void enqueue(int x, int y) {
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
}

void dequeue(int* x, int* y) {
    *x = queue[front][0];
    *y = queue[front][1];
    front++;
}

int isEmpty() { return front == rear; }

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize) {
    front = 0 , rear = 0;
    if (grid[0][0] == 1 ||
    grid[gridSize - 1][gridColSize[gridSize - 1] - 1] == 1)
    return -1;

    int directions[8][2] = {
        {1, 0},   {0, 1},  {-1, 0}, {0, -1}, {1, 1},
        {-1, -1}, {1, -1}, {-1, 1}}; // because we want to move only to n-1 n-1
                                     // corner
    enqueue(0, 0); // staring point;
    grid[0][0] = 1; //and first one is visted
    int count = 1;
    while (!isEmpty()) {
        int size = rear - front;
        int z = 0;
        while (z < size) {
            int i, j;
            dequeue(&i, &j);
            if (i == gridSize - 1 && j == gridColSize[gridSize - 1] - 1)
                return count;

            int k = 0;
            while (k < 8) {
                int new_i = i + directions[k][0];
                int new_j = j + directions[k][1];
                if (new_i >= 0 && new_j >= 0 && new_i < gridSize &&
                    new_j < gridColSize[new_i] && grid[new_i][new_j] == 0) {
                    enqueue(new_i, new_j);
                    grid[new_i][new_j] = 1;
                }
                k++;
            }
            
            z++;
        }
        count++;
    }
    return -1;
}