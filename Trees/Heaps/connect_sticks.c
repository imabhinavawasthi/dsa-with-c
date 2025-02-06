// Max-Heap data structure in C
#include <stdio.h>

int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int size, int i) {
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    // if left child is larger
    if(left<size && arr[left]<arr[smallest]) {
        smallest = left;
    }

    // if right child is larger
    if(right<size && arr[right]<arr[smallest]) {
        smallest = right;
    }

    if(smallest!=i) {
        swap(&arr[i],&arr[smallest]);
        heapify(arr,size,smallest);
    }
}

int getMin(int array[],int size) {
    if(size==0){
        return -1;
    }
    return array[0];
}

void insert(int array[], int newNum) {
    array[size] = newNum;
    size += 1;

    int current = size - 1;
    while (current != 0) {
        int parent = (current - 1) / 2;
        if (array[current] < array[parent]) {
            swap(&array[current], &array[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

void deleteRoot(int array[]) {
    int i = 0;

    swap(&array[i], &array[size - 1]);
    // Reduce the size of the heap since the last element is now removed
    size -= 1;

    // Heapify from the current index to adjust the rest of the heap
    if (i < size) {
        heapify(array, size, i);
    }
}

int main() {
    int sticks[] = {5,3,1,2,4};
    int heap[10];

    for(int i=0;i<5;i++){
        insert(heap,sticks[i]);
    }

    int cost = 0;

    while(size>1) {
        int x = getMin(heap,size);
        deleteRoot(heap);
        int y = getMin(heap,size);
        deleteRoot(heap);

        cost += (x+y);
        insert(heap,(x+y));
    }

    printf("%d",cost);
    
    return 0;
}