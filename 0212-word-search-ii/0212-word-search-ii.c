struct Trie {
    struct Trie * children[26];
    char * word; //  end leaf will store the complete word; 
};

//in ths case starts and starts with cant work so we store complet word on the leaf node 

struct Trie * create_trie(){
    struct Trie * trie = malloc(sizeof(*trie));
    int i = 0;
    while(i < 26){
        trie->children[i] = NULL;
        i++;
    }
    trie->word = NULL;
    return trie;
}
struct Trie *build_trie(struct Trie *root_trie, char **words, int word_size){
    for (int i = 0; i < word_size; i++) {
        struct Trie *node = root_trie;        // ⭐ har word root se shuru

        int j = 0;
        while (words[i][j] != '\0') {
            int index = words[i][j] - 'a';
            if (node->children[index] == NULL)
                node->children[index] = create_trie();
            node = node->children[index];
            j++;
        }

        node->word = malloc(strlen(words[i]) + 1);
        memcpy(node->word, words[i], strlen(words[i]) + 1);
    }
    return root_trie;
}


int directions[4][2];
char ** result;
void helper(char ** boards, int boardSize, int * boardColSize, int * returnSize, int i, int j, struct Trie * trie){
    if(i < 0 || j < 0 || i >= boardSize || j >= boardColSize[i] || boards[i][j] == '#') return;
    char temp = boards[i][j];
    int index = temp-97;
    struct Trie * new_trie = trie->children[index];

    if(new_trie == NULL) return;
    if(new_trie->word != NULL){
        result[*returnSize] = malloc(sizeof(char) * (strlen(new_trie->word) +1));
        memcpy(result[*returnSize], new_trie->word, (strlen(new_trie->word) + 1));
        (*returnSize)++;
        new_trie->word = NULL;
    }
    boards[i][j] = '#';
    int k = 0;
    while(k < 4){
        int new_i = i + directions[k][0];
        int new_j = j + directions[k][1];
        helper(boards, boardSize, boardColSize, returnSize, new_i, new_j, new_trie);
        k++;
    }
    boards[i][j] = temp;
}


char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    int temp[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    memcpy(directions, temp, sizeof temp);
    struct Trie * trie =  create_trie();
    trie = build_trie(trie, words, wordsSize); // building trie
    result = malloc(sizeof(*result) * wordsSize);// cant exceed the result size limit mre than wordsSize
    *returnSize = 0;
    int i = 0;
    while(i < boardSize){
        int j =0;
        while(j < boardColSize[i]){
            helper(board, boardSize, boardColSize, returnSize, i, j, trie);
            j++;
        }
        i++;
    } 
    return result;
    
}