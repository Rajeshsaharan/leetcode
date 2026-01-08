int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    //chance for looking first and second
    int first_choice = edges[0][0], first = 0;
    int second_choice = edges[0][1], second = 0;
    int i = 0;
    while(i < edgesSize){
        int j = 0;
        while(j < edgesColSize[i]){
            if(edges[i][j] == first_choice) first++;
            if(edges[i][j] == second_choice) second++;
            j++;
        }
        i++;
    }
    return first == edgesSize? first_choice : second_choice;
}