void helper(int i, int ** isConnected, int isConnectedSize, int * isConnectedColSize, int * visited){
    visited[i] = 1;
    int k = 0;
    while(k < isConnectedColSize[i]){
        if(visited[k] == 0 && isConnected[i][k] == 1){
            helper(k, isConnected, isConnectedSize, isConnectedColSize, visited);
        }
        k++;
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int * visited = calloc(isConnectedSize, sizeof(int));
    int count = 0;
    //all intilized with zero here here are node;
    int i = 0;
    while(i < isConnectedSize){
        int j = 0;
        while(j < isConnectedColSize[i]){
            if(visited[i] == 0){
                helper(i, isConnected, isConnectedSize, isConnectedColSize,visited);
                count++;
            }
            j++;
        }
        i++;
    }
    return count;
}