void dfs(int ** rooms, int roomsSize, int * roomsColSize,int i , int * already_open){
    already_open[i] = true;
    int j = 0;
    while(j < roomsColSize[i]){
        if(already_open[rooms[i][j]] != 1){
            dfs(rooms, roomsSize, roomsColSize, rooms[i][j], already_open);
        }
        j++;
    }

}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    int * already_open = (int *)calloc(roomsSize, sizeof (int));
    dfs(rooms, roomsSize, roomsColSize, 0, already_open);
    int i = 0;
    bool all_open = true;
    while(i < roomsSize) all_open  &= already_open[i++];
    return all_open;
}