#define SIZE 100

struct ht_entry {
    int key;
    int data;
    struct ht_entry* next;
};
struct ht {
    struct ht_entry** store;
};

// simple hash function
int hash(int key) {
    int h = key % SIZE;
    return (h < 0) ? h + SIZE : h;
}


struct ht* init_ht() {
    struct ht* ht = (struct ht*)malloc(sizeof(struct ht));
    ht->store = (struct ht_entry**)malloc(SIZE * sizeof(struct ht_entry*));
     for (int i = 0; i < SIZE; i++) {
        ht->store[i] = NULL;
     }
    return ht;
}


void insert_ht(struct ht* ht, int key, int data) {
     int index = hash(key);
    struct ht_entry *head = ht->store[index],
                    *ht_entry = malloc(sizeof(struct ht_entry));
    ht_entry->key = key;
    ht_entry->data = data; 
    ht_entry->next = NULL;
    if (head == NULL) {
        ht->store[index] = ht_entry;
    } else {
        while (head->next) head = head->next;
        head->next = ht_entry;
    }

}

//if key exist than get key otherwise return -1;
int get_data(struct ht * ht , int key){
    int index = hash(key);
    printf("index -> %d\n", index);
    struct ht_entry * head = ht->store[index];
    if(!head) return -1; // no key found
    while(head){
        if(key == head->key){
            return head->data;
        }
        head = head->next;
    }
    return -1; //no value is found
}

void update_data(struct ht * ht , int key, int data){
     int index = hash(key);
    struct ht_entry * head = ht->store[index];
    if(!head) return; // no key found
    while(head){
        if(key == head->key) head->data = data;
        head = head->next;
    }
    return; //no value is found
}

int majorityElement(int* nums, int numsSize) {
    int i = 0;
    struct ht * ht = init_ht();
    while (i < numsSize) {
        if(get_data(ht, nums[i]) == -1){
            insert_ht(ht, nums[i], 1);
        }else{
            int data = get_data(ht, nums[i]);
            update_data(ht,nums[i], ++data);
        }
        i++;
    }

    int j = INT_MIN;
    i =0;
    int k;
    printf("%d\n", get_data(ht, 2));
    while(i < numsSize){
        if(get_data(ht,nums[i]) > j){
            j = get_data(ht,nums[i]);
            k = nums[i];
        }
        i++;
    }
    return k;
}