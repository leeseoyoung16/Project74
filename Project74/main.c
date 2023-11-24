#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
int move, compare;

//선택

void print_array(int arr[], int size) { //과정 출력
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int list[], int n) {
    int i, j, least, temp;
    move = 0;
    compare = 0;

    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least]) least = j;
            compare += 1;
        }
        SWAP(list[i], list[least], temp);
        print_array(list, n);
        move += 1;
    }
}

void selection_sort2(int list[], int n) {
    int i, j, least, temp;
    move = 0;
    compare = 0;

    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least]) least = j;
            compare += 1;
        }
        SWAP(list[i], list[least], temp);
        //print_array(list, n);
        move += 1;
    }
}

int main(void) {
    int i,j;
    int move_count = 0;
    int compare_count = 0;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("Selection Sort\n");
    selection_sort(list, n);

    move_count += move;
    compare_count += compare;


    for (j = 1; j <= 19; j++) {
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        selection_sort2(list, n);

        move_count += move;
        compare_count += compare;

    }
    printf("Average Move Count: %d\n", move_count / 20);
    printf("Average Compare Count: %d\n", compare_count / 20);


    
    return 0;
}