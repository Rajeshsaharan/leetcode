
int is_larger(int* arr, int size, int a) {
    if (arr == NULL || size == 0) {
        return -1;
    }

    int low = 0;
    int high = size - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > a) {
            result = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}


int numMatchingSubseq(char* s, char** words, int wordsSize) {
    int freq[26];
    int track[26] = {0};
    int* arr[26] = {NULL};
    int count = 0;
    int i = 0;
    while (s[i] != '\0') {
        freq[s[i] - 97]++;
        i++;
    }

    i = 0;
    while (s[i] != '\0') {
        int idx = s[i] - 'a';
        int size = freq[idx];
        int pos = track[idx];
        int* st = arr[idx];
        if (st == NULL) {
            int* new_st = malloc(sizeof(int) * size);
            new_st[pos] = i;
            arr[idx] = new_st;
            track[idx]++;
        } else {
            st[pos] = i;
            track[idx]++;
        }
        i++;
    }

    // for (int c = 0; c < 26; c++) {
    //     if (arr[c] != NULL) {
    //         printf("%c -> ", 'a' + c);
    //         printIntArray(arr[c], freq[c]);
    //     }
    // }

    i = 0;
    while (i < wordsSize) {
      //  printf("string %s => \n", words[i]);
        int j = 0;
        int prev = -1;
        while (words[i][j] != '\0') {
            int idx = words[i][j] - 97;
            int size = freq[idx];
            int* st = arr[idx];
            if(st == NULL){
                break;
            }
            int is_large = is_larger(st, size, prev);
          //  printf("%c -> ", words[i][j]);
           // printIntArray(st, size);
           // printf("prev %d and is_large %d\n", prev, is_large);
            if (is_large > -1) {
                prev = is_large;
            } else {
                break;
            }
            j++;
        }
        int s = strlen(words[i]);
      //  printf("j is %d ans strlen %d\n\n\n", j,s);
        if(j == s){
            count++;
        }
        i++;
    }

    return count;
}