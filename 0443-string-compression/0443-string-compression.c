int compress(char* chars, int charsSize) {
    int i = 0, j = 0, k = 0;
    while (i < charsSize) {
        if (chars[i] != chars[j]) {
            int z = i - j;
            chars[k++] = chars[j];
            if (z <= 9 && z > 1) {
                chars[k++] = z + 48;
            }
            if (z > 9) {
                char str[20];
                sprintf(str, "%d", z);
                for (int i = 0; str[i] != '\0'; i++) {
                    chars[k++] = str[i];
                }
            }
            j = i;
        } else {
            i++;
        }
    }
    // edge case handling
    int z = charsSize - j;
    chars[k++] = chars[j];
    if (z <= 9 && z > 1) {
        chars[k++] = z + 48;
    }
    if (z > 9) {
        char str[20];
        sprintf(str, "%d", z);
        for (int i = 0; str[i] != '\0'; i++) {
            chars[k++] = str[i];
        }
    }

    return k;
}