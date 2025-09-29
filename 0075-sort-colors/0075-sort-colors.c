void heapify_down(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify_down(arr, n, largest);
    } else {
        return;
    }
}

void heap_sort(int* arr, int size) {
    int i = size / 2 - 1;
    while (i >= 0) {
        heapify_down(arr, size, i);
        i--;
    }
    i = size - 1;
    while (i > 0) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify_down(arr, i, 0);
        i--;
    }
}


void sortColors(int* nums, int numsSize) {
    heap_sort(nums, numsSize);
}