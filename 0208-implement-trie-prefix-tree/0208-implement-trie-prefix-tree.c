#define SIZE 26

typedef struct Trie {
    struct Trie *children[SIZE];
    bool is_end_of_word;
} Trie;

Trie* trieCreate(void){
    Trie * trie = malloc(sizeof(Trie));
    trie->is_end_of_word = false;
    int i = 0;
    while(i < SIZE){
        trie->children[i] = NULL;
        i++;
    }
    return trie;
}

void trieInsert(Trie* obj, char* word) {
    Trie * current = obj;
    //int len = strlen(word);
    int i = 0;
    while(word[i] != '\0'){
        int index = word[i] - 97;
        if(current->children[index] == NULL) current->children[index] = trieCreate();
        current = current->children[index];
        i++;
    }
    current->is_end_of_word = true;
}

bool trieSearch(Trie* obj, char* word) {
    Trie * current = obj;
    //int len = strlen(word);
    int i = 0;
    while(word[i] != '\0'){
        int index = word[i]-97;
        if(current->children[index] == NULL) return false;
        current = current->children[index];
        i++;
    }
    return current !=NULL && current->is_end_of_word;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    Trie * current = obj;
   // int len = strlen(prefix);
    int i = 0;
    while(prefix[i] != '\0'){
        int index = prefix[i]-97;
        if(current->children[index] == NULL) return false;
        current = current->children[index];
        i++;
    }
    return current != NULL;
}

void trieFree(Trie* obj) {
    int i = 0;
    while(i < SIZE){
        free(obj->children[i]);
        i++;
    }
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/