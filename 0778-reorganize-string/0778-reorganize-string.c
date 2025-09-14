#define MAX 100

struct it {
    char c;
    int count;
};

struct maxheap{
    struct it ** arr;
    int size;
};

//parent of any index i
int parent(int i) {
	return (i - 1) / 2;
}

//left child of any index i
int left_child(int i) {
	return 2 * i + 1;
}
//right child of any index i

int right_child(int i) {
	return 2 * i + 2;
}

struct maxheap * init_heap() {
	struct maxheap * mheap = (struct maxheap *)malloc(sizeof(struct maxheap));
	mheap->size = 0;
	struct it ** arr = malloc(MAX * sizeof(struct it *));
    int i = 0;
    while(i < MAX){ arr[i] = NULL; i++;};
	mheap->arr = arr;
	return mheap;
}

//heapfiy up /bubble up <- from given index to until index >= 0
void heapify_up(struct it ** arr, int index) {
    while (index > 0) {
    int parent_index = parent(index);
    if (arr[index]->count > arr[parent_index]->count) {
        struct it* temp = arr[parent_index];
        arr[parent_index] = arr[index];
        arr[index] = temp;
        index = parent_index; // move up
    } else {
        break;
    }
}

}

void heapify_down(struct it  ** arr , int size, int index) {
	while (true) {
		int largest = index;
		int left_child_index = left_child(index);
		int right_child_index = right_child(index);
		if (left_child_index < size && (arr[left_child_index])->count > (arr[largest])->count ) {
			largest = left_child_index;
		}

		if (right_child_index < size && (arr[right_child_index])->count > (arr[largest])->count) {
			largest = right_child_index;
		}
		//after comparing both got largest value
		if (largest != index) {
			struct it * temp = arr[largest];
			arr[largest] = arr[index];
			arr[index] = temp;
			index = largest;
		} else {
			break;
		}
	}


}


void insert(struct maxheap * mheap, char c , int count) {
	if (mheap == NULL) {
		printf("%s\n", "mheap must be initlization & can't be NULL");
	}
    struct it * item = malloc(sizeof(struct it));
    item->c = c;
    item->count = count;
	mheap->arr[mheap->size] = item;
	heapify_up(mheap->arr, mheap->size); 
	mheap->size++; 
}


void print_heap(struct maxheap * heap){
    struct it ** items = heap->arr;
    int i =0;
    printf("{ ");
    while(i < heap->size){
        printf("{ char : %c , count : %d}", items[i]->c, items[i]->count);
        i++;
    }
    printf(" }\n");

}

struct it *delete_max_heap(struct maxheap *mheap) {
    if (mheap->size <= 0) {
        return NULL;
    }
    mheap->size--;
    struct it *item = mheap->arr[0];
    mheap->arr[0] = mheap->arr[mheap->size];
    mheap->arr[mheap->size] = NULL;

    heapify_down(mheap->arr, mheap->size, 0);

    return item;
}

char* reorganizeString(char* s) {
    int size_string = strlen(s);
    int arr[26] = {0};
    struct maxheap * maxheap= init_heap();
    char * result = malloc(sizeof(char) * (size_string + 1));
    result[size_string] = '\0'; 
    int i =0;
    while(s[i] != '\0'){
        arr[s[i] - 'a']++;
        i++;
    };

    for (i = 0; i < 26; i++) {
        if (arr[i] > (size_string + 1) / 2) {
            return "";
        }
    }

    for(i = 0; i < 26; i++){
        if(arr[i] > 0){
            insert(maxheap, i + 'a', arr[i]);
        }
    }

    int result_index = 0;
    while (maxheap->size > 1){
        struct it * item1 = delete_max_heap(maxheap);
        struct it * item2 = delete_max_heap(maxheap);

        result[result_index++] = item1->c;
        result[result_index++] = item2->c;

        item1->count--;
        item2->count--;

        if(item1->count > 0){
            insert(maxheap, item1->c, item1->count);
        }
        if(item2->count > 0){
            insert(maxheap, item2->c, item2->count);
        }

        free(item1);
        free(item2);
    }

    if (maxheap->size > 0) {
        struct it * last_item = delete_max_heap(maxheap);
        result[result_index++] = last_item->c;
        free(last_item);
    }

    return result;
}

