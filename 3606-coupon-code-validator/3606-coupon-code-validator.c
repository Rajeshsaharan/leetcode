struct coupon{
    char *code;
    char *category;
};

int category_index(char *cat) {
    if(strcmp(cat, "electronics") == 0) return 0;
    if(strcmp(cat, "grocery") == 0)     return 1;
    if(strcmp(cat, "pharmacy") == 0)    return 2;
    if(strcmp(cat, "restaurant") == 0)  return 3;
    return 4;
}

int cmp_coupon(const void *a, const void *b) {
     struct coupon *c1 = *(struct coupon **)a;
    struct coupon *c2 = *(struct coupon **)b;

    int i1 = category_index(c1->category);
    int i2 = category_index(c2->category);
    if(i1 != i2)
        return i1 - i2;
    return strcmp(c1->code, c2->code);
}





int is_coupon_valid(char * str){
    if(strlen(str) == 0) return 0;
    int i = 0;
    while(str[i] != '\0'){
       if (!isalnum(str[i]) && str[i] != '_') return 0;
        i++;
    }
    return 1;
}

int is_contains(char ** categories, int size,  char  * str){
    int i = 0;
    while(i < size){
      if(strcmp(categories[i], str) == 0){
        return 1;
      }
      i++;
    }
    return 0;
}


char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
    char * categories[4] = {"electronics", "grocery", "pharmacy", "restaurant"};
    struct coupon ** result = malloc(sizeof(struct coupon *) * 100); // max capacity
    int i = 0;
    int k = 0;
    while(i < codeSize){
        if(is_contains(categories, 4,  businessLine[i]) && is_coupon_valid(code[i]) && isActive[i]){
            result[k] = malloc(sizeof(struct coupon));
            result[k]->code = malloc(sizeof(char) * (strlen(code[i]) +1));
            result[k]->category = malloc(sizeof(char) * (strlen( businessLine[i]) +1));
            memcpy(result[k]->code, code[i], (strlen(code[i]) +1));
            memcpy(result[k]->category, businessLine[i], (strlen( businessLine[i]) +1));
            k++;
        }
        i++;
    }
    *returnSize = k;

    qsort(result, k, sizeof(struct copun *), cmp_coupon);
    i = 0;
    char ** result2 = malloc(sizeof(char*) * 100);
    while(i < k){
        result2[i] = malloc(sizeof(char) * (strlen(result[i]->code) +1));
        memcpy(result2[i], result[i]->code, (strlen(result[i]->code) +1));
        i++;
    }
    return result2;
}