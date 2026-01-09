struct ele {
    char chr;
    int freq;
};

int comp(const void *a, const void *b) {
    struct ele *e1 = (struct ele *)a;
    struct ele *e2 = (struct ele *)b;
    return e2->freq - e1->freq;   // descending
}

char* frequencySort(char* s) {
    int arr[128] = {0};

    int i = 0;
    while (s[i] != '\0') {
        arr[s[i]]++;
        i++;
    }

    struct ele element_arr[128];
    int k = 0;

    for (i = 0; i < 128; i++) {
        if (arr[i] > 0) {
            element_arr[k].chr = i;
            element_arr[k].freq = arr[i];
            k++;
        }
    }

    qsort(element_arr, k, sizeof(struct ele), comp);

    int len = strlen(s);
    char *result = malloc(len + 1);

    int idx = 0;
    for (i = 0; i < k; i++) {
        int f = element_arr[i].freq;
        while (f--) {
            result[idx++] = element_arr[i].chr;
        }
    }

    result[idx] = '\0';
    return result;
}
