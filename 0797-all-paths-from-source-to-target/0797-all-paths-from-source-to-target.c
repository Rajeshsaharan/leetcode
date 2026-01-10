int ** result;

//result is one of -
//  -empty (null)
//  - cons listofNode ListOfNodeNode;

void dfs(int ** graph, int graphSize, int * graphColSize, int * returnSize, int ** returnColumnSizes, int node_index, int index, int * path){
    if(node_index == graphSize -1){
        path[index] = node_index;
        result[*returnSize] = malloc(sizeof(int) * (index +1));
        memcpy(result[*returnSize], path,  sizeof(int) * (index + 1));
        (*returnColumnSizes)[*returnSize] = index+1;
        (*returnSize)++;
        return;
    }

    path[index] = node_index;
    int k = 0;
    while(k < graphColSize[node_index]){
        dfs(graph, graphSize, graphColSize, returnSize, returnColumnSizes, graph[node_index][k], index + 1, path);
        k++;
    }
}



int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    result = malloc(sizeof(int *) * 100000);
    int * path  = malloc(sizeof(int) * graphSize);
    *returnSize  =0;
    *returnColumnSizes = malloc(sizeof(int) * 100000); // maximum can be size of graphSize;
    dfs(graph, graphSize, graphColSize, returnSize, returnColumnSizes, 0, 0, path);
    return result;
}