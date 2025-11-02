void print_matrix(int m, int n, int (*mat)[n]) {
    int i = 0;
    while (i < m) {
        int j = 0;
        while (j < n) {
            printf("%d ", mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int countUnguarded(int m, int n, int** guards, int guardsSize,
                   int* guardsColSize, int** walls, int wallsSize,
                   int* wallsColSize) {
    int mat[m][n]; // vla
    int i = 0;
    while (i < m) {
        int j = 0;
        while (j < n) {
            mat[i][j] = 0;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < wallsSize)
        mat[walls[i][0]][walls[i++][1]] = -1;
    i = 0;
    while (i < guardsSize) mat[guards[i][0]][guards[i++][1]] = 1;
    i = 0;
    while (i < m) {
        int j =0, w = -1, g = -1;
        while(j < n){
            if(mat[i][j] == 1){
                g = j;
            }
            if(mat[i][j] == -1 ){
                printf("for row %d\n", i);
                int z = w != -1 ? w : 0;
                while(z < j && g != -1){
                    mat[i][z] = mat[i][z] == 1 || mat[i][z] == -1 ? mat[i][z] : 2;
                    z++;
                }
                w = j;
                g = -1;
            }
            j++;
        }
        printf("w is %d and g is %d\n", w, g);
        if(g != -1 && w == -1){
            int z =0;
            while(z < n){
                mat[i][z] = mat[i][z] == 1 || mat[i][z] == -1 ? mat[i][z] : 2;
                z++;
            }
            i++;
            continue;
        }
        if(g != -1 && g > w){
            printf("this should called");
            int z = w;
            while(z < n){
                mat[i][z] = mat[i][z] == 1 || mat[i][z] == -1 ? mat[i][z] :2;
                z++;
            }
        }
        i++;
    }
    i =0;
    while(i < n){
        int j = 0, g = -1, w = -1;
        while(j < m){
            if(mat[j][i] == 1){
                g =j;
            }
            if(mat[j][i] == -1){
                    int z = w != -1 ? w : 0;
                    while(z < j && g != -1){
                    mat[z][i] = mat[z][i] == 1 || mat[z][i] == -1 ? mat[z][i] : 2;
                    z++;
                }
                w = j;
                g = -1;
            }
            j++;
        }
        printf("w is %d and g is %d\n", w, g);
        if(g != -1 && w == -1){
            int z =0;
            while(z < m){
                mat[z][i] = mat[z][i] == 1 || mat[z][i] == -1 ? mat[z][i] : 2;
                z++;
            }
            i++;
            continue;
        }
        if(g != -1 && g > w){
            printf("this should called");
            int z = w;
            while(z < m){
                mat[z][i] = mat[z][i] == 1 || mat[z][i] == -1 ? mat[z][i] :2;
                z++;
            }
        }
        i++;
    }
    i = 0;
    int total = 0;
    while(i < m){
        int j = 0;
        while(j < n){
            if(mat[i][j] == 0) total++;
            j++;
        }
        i++;
    }
    return total;
}