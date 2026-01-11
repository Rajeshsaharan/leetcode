#define SIZE 1000000

struct node {
    int data;
    struct node *next;
};

struct graph {
    int num_of_nodes;
    struct node **list_of_nodes;
};

enum color { RED, BLUE };

static int queue[SIZE][2];
int front = 0, rear = 0;

bool is_empty() {
    return front == rear;
}

void enqueue(int node, enum color color) {
    if (rear < SIZE) {
        queue[rear][0] = node;
        queue[rear][1] = color;
        rear++;
    }
}

void dequeue(int *node, enum color *color) {
    *node = queue[front][0];
    *color = queue[front][1];
    front++;
}

struct node *create_node(int data) {
    struct node *n = malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    return n;
}

struct graph *create_graph(int order) {
    struct graph *g = malloc(sizeof(struct graph));
    g->num_of_nodes = order;
    g->list_of_nodes = malloc(sizeof(struct node *) * order);

    int i = 0;
    while (i < order) {
        g->list_of_nodes[i] = NULL;
        i++;
    }

    return g;
}

void add_edge_directed(struct graph *g, int src, int dest) {
    if (src < 0 || src >= g->num_of_nodes) return;
    if (dest < 0 || dest >= g->num_of_nodes) return;

    struct node *n = create_node(dest);
    n->next = g->list_of_nodes[src];
    g->list_of_nodes[src] = n;
}

int* shortestAlternatingPaths(
    int n,
    int **redEdges, int redEdgesSize, int *redEdgesColSize,
    int **blueEdges, int blueEdgesSize, int *blueEdgesColSize,
    int *returnSize
) {
    front = 0;
    rear = 0;

    struct graph *red_graph  = create_graph(n);
    struct graph *blue_graph = create_graph(n);

    int i = 0;
    while (i < redEdgesSize) {
        add_edge_directed(red_graph, redEdges[i][0], redEdges[i][1]);
        i++;
    }

    i = 0;
    while (i < blueEdgesSize) {
        add_edge_directed(blue_graph, blueEdges[i][0], blueEdges[i][1]);
        i++;
    }

    int *red  = malloc(sizeof(int) * n);
    int *blue = malloc(sizeof(int) * n);

    i = 0;
    while (i < n) {
        red[i] = -1;
        blue[i] = -1;
        i++;
    }

    enqueue(0, RED);
    enqueue(0, BLUE);
    red[0] = 0;
    blue[0] = 0;

    while (!is_empty()) {
        int node;
        enum color color;
        dequeue(&node, &color);

        if (color == RED) {
            struct node *p = blue_graph->list_of_nodes[node];
            while (p) {
                if (blue[p->data] == -1) {
                    blue[p->data] = red[node] + 1;
                    enqueue(p->data, BLUE);
                }
                p = p->next;
            }
        } else {
            struct node *p = red_graph->list_of_nodes[node];
            while (p) {
                if (red[p->data] == -1) {
                    red[p->data] = blue[node] + 1;
                    enqueue(p->data, RED);
                }
                p = p->next;
            }
        }
    }

    int *result = malloc(sizeof(int) * n);

    i = 0;
    while (i < n) {
        if (red[i] == -1 && blue[i] == -1)
            result[i] = -1;
        else if (red[i] == -1)
            result[i] = blue[i];
        else if (blue[i] == -1)
            result[i] = red[i];
        else
            result[i] = red[i] < blue[i] ? red[i] : blue[i];
        i++;
    }

    *returnSize = n;
    return result;
}
