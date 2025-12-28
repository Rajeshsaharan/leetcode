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

int orangesRotting(int** grid, int gridSize, int* gridColSize) {

    ///importan global variable must intilized in the function scope to behvae normaly 
    front = 0, rear = 0;
    int i = 0;
    int fresh = 0;
    while (i < gridSize) {
        int j = 0;
        while (j < gridColSize[i]) {
            if (grid[i][j] == 2) enqueue(i, j);
            if( grid[i][j] == 1) fresh++;
            j++;
        }
        i++;
    }
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int count = 0;
    while (!isEmpty() && fresh > 0) {
        printf("this loop is running");
        int size = rear - front;
        bool rotten_this_side = false;
        int z = 0;
        while (z < size) {
            int i, j;
            dequeue(&i, &j);
            int k = 0;
            while (k < 4) {
                int new_i = i + directions[k][0];
                int new_j = j + directions[k][1];

                if (new_i >= 0 && new_i < gridSize && new_j >= 0 &&
                    new_j < gridColSize[new_i] && grid[new_i][new_j] == 1) {
                    grid[new_i][new_j] = 2;
                    fresh--;
                    enqueue(new_i, new_j);
                    rotten_this_side = true;
                }
                k++;
            }
            z++;
        }
        if (rotten_this_side)
            count++;
    }

    return fresh == 0 ? count : -1;
}