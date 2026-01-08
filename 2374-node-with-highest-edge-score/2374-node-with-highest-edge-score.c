int edgeScore(int* edges, int edgesSize) {
    long long* result = calloc(edgesSize, sizeof(long long));
    memset(result, 0, sizeof(result));
    int i = 0;
    while (i < edgesSize) {
        result[edges[i]] += i;
        i++;
    }
    i = 0;
    long long max = result[0];
    int index = 0;

    i = 1;
    while (i < edgesSize) {
        if (result[i] > max) {
            max = result[i];
            index = i;
        }
        i++;
    }
    return index;
}