#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

void SortedArray(int argc, char *argv[]) {
    int arr[argc-1];
    for(int i = 0; i < argc-1; i++) {
        arr[i] = atoi(argv[i+1]);
    }
    int n = argc-1;
    qsort(arr, n, sizeof(int), compare);
    printf("descending order: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    SortedArray(argc, argv);
    return 0;
}
