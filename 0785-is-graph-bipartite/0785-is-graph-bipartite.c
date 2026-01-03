struct node{
    int data;
    struct node *next;
};

struct graph{
    int num_of_nodes;
    struct node **list_of_nodes;
};

struct node *create_node(int data){
    struct node *node = malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct graph *create_graph(int order){
    struct graph *graph = malloc(sizeof(struct graph));
    graph->num_of_nodes = order;
    graph->list_of_nodes = calloc(order, sizeof(struct node *));
    return graph;
}

void add_edge_directed(struct graph *graph, int src, int dest){
    struct node *node = create_node(dest);
    node->next = graph->list_of_nodes[src];
    graph->list_of_nodes[src] = node;
}

void add_edge_undirected(struct graph *graph, int src, int dest){
    struct node *node = create_node(dest);
    node->next = graph->list_of_nodes[src];
    graph->list_of_nodes[src] = node;

    node = create_node(src);
    node->next = graph->list_of_nodes[dest];
    graph->list_of_nodes[dest] = node;
}

bool dfs(int **graph, int *graphColSize, int idx, int color, int *colors){
    colors[idx] = color;
    for(int i = 0; i < graphColSize[idx]; i++){
        int neighbor = graph[idx][i];
        if(colors[neighbor] == -1){
            if(!dfs(graph, graphColSize, neighbor, 1 - color, colors))
                return false;
        } else if(colors[neighbor] == color){
            return false;
        }
    }
    return true;
}

bool isBipartite(int **graph, int graphSize, int *graphColSize){
    int colors[101];
    for(int i = 0; i < graphSize; i++)
        colors[i] = -1;

    for(int i = 0; i < graphSize; i++){
        if(colors[i] == -1){
            if(!dfs(graph, graphColSize, i, 1, colors))
                return false;
        }
    }
    return true;
}