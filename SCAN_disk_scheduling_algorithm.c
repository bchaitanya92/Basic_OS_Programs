#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void scanAlgorithm(int requests[], int n, int head, int direction, int disk_size) {
    int seek_sequence[MAX_REQUESTS];
    int index = 0, i;

    sort(requests, n);

    if (direction == 1) {

        for (i = 0; i < n; i++) {
            if (requests[i] >= head) {
                seek_sequence[index++] = requests[i];
            }
        }

        for (i = n - 1; i >= 0; i--) {
            if (requests[i] < head) {
                seek_sequence[index++] = requests[i];
            }
        }
    }

    else {

        for (i = n - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                seek_sequence[index++] = requests[i];
            }
        }

        for (i = 0; i < n; i++) {
            if (requests[i] > head) {
                seek_sequence[index++] = requests[i];
            }
        }
    }

    printf("Seek Sequence: ");
    for (i = 0; i < index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
}

int main() {
    int requests[MAX_REQUESTS];
    int n, head, direction, disk_size;
    
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    if (n > MAX_REQUESTS) {
        printf("Number of requests exceeds the maximum limit of %d.\n", MAX_REQUESTS);
        return 1;
    }

    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the direction of head movement (1 for right, 0 for left): ");
    scanf("%d", &direction);

    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    scanAlgorithm(requests, n, head, direction, disk_size);

    return 0;
}


'''
********************************OUTPUT 1********************************


braham@braham:~/Desktop/program$ gcc disk.c -o disk
braham@braham:~/Desktop/program$ ./disk

Enter the number of disk requests: 8
Enter the disk requests:
98 183 37 122 14 124 65 67
Enter the initial head position: 50
Enter the direction of head movement (1 for right, 0 for left): 1
Enter the size of the disk: 200
Seek Sequence: 65 67 98 122 124 183 37 14


********************************OUTPUT 2********************************


braham@braham:~/Desktop/program$ gcc disk.c -o disk
braham@braham:~/Desktop/program$ ./disk

Enter the number of disk requests: 8
Enter the disk requests:
98 183 37 122 14 124 65 67
Enter the initial head position: 50
Enter the direction of head movement (1 for right, 0 for left): 0
Enter the size of the disk: 200
Seek Sequence: 37 14 65 67 98 122 124 183
'''