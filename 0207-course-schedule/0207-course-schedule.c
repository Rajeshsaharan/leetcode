bool dfs(int** mat, int n, int idx, int* visited, int* current_path) {
    visited[idx] = true;
    current_path[idx] = true;
    int k = 0;
    while (k < n) {
        if (mat[idx][k] == 1) {
            if (current_path[k])
                return true; // back edge → cycle
            if (!visited[k]) {
                if (dfs(mat, n, k, visited, current_path))
                    return true;
            }
        }
        k++;
        
    }
    current_path[idx] = false;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize) {
    // building adjency list
    int** matrix = malloc(sizeof(*matrix) * numCourses);
    int i = 0;
    while (i < numCourses) {
        matrix[i] = calloc(numCourses, sizeof(int));
        i++;
    }
    i = 0;
    while (i < prerequisitesSize) {
        int course = prerequisites[i][0];
        int pre = prerequisites[i][1];
        matrix[pre][course] = 1;
        i++;
    }

    int visited[2001] = {false};
    int current_path[2001] = {false};

    i = 0;
    while (i < numCourses) {
        if (!visited[i]) {
            if (dfs(matrix, numCourses, i, visited, current_path))
                return false;
        }
        i++;
    }
    return true;
}