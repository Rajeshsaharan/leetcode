
bool isAnagram(char* a, char* b) {
    if (strlen(a) != strlen(b)) return false;

    int freq[26] = {0};
    for (int i = 0; a[i]; i++) {
        freq[a[i]-'a']++;
        freq[b[i]-'a']--;
    }

    for (int i = 0; i < 26; i++)
        if (freq[i] != 0)
            return false;

    return true;
}

char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    int write_on_words = 1; 
    for (int i = 1; i < wordsSize; i++) {
        if (!isAnagram(words[i], words[write_on_words - 1])) {
            words[write_on_words++] = words[i];
        }
    }

    *returnSize = write_on_words;
    return words;
}
