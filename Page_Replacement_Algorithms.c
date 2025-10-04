#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 20

void fifoPageReplacement(int pages[], int num_pages, int num_frames) {
    int frame[num_frames];
    int page_faults = 0, index = 0, i, j, k, flag;

    for (i = 0; i < num_frames; i++) {
        frame[i] = -1;
    }

    printf("\nFIFO Page Replacement Algorithm\n");

    for (i = 0; i < num_pages; i++) {
        flag = 0;

        for (j = 0; j < num_frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            frame[index] = pages[i];
            index = (index + 1) % num_frames;
            page_faults++;

            printf("Page Fault: ");
            for (k = 0; k < num_frames; k++) {
                if (frame[k] != -1) {
                    printf("%d ", frame[k]);
                }
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
}

void lruPageReplacement(int pages[], int num_pages, int num_frames) {
    int frame[num_frames];
    int last_used[num_frames];
    int page_faults = 0, index, i, j, k, flag, lru_index;

    for (i = 0; i < num_frames; i++) {
        frame[i] = -1;
        last_used[i] = 0;
    }

    printf("\nLRU Page Replacement Algorithm\n");

    for (i = 0; i < num_pages; i++) {
        flag = 0;

        for (j = 0; j < num_frames; j++) {
            if (frame[j] == pages[i]) {
                flag = 1;
                last_used[j] = i; 
                break;
            }
        }

        if (flag == 0) {

            lru_index = 0;
            for (j = 1; j < num_frames; j++) {
                if (last_used[j] < last_used[lru_index]) {
                    lru_index = j;
                }
            }

            frame[lru_index] = pages[i];
            last_used[lru_index] = i;
            page_faults++;

            printf("Page Fault: ");
            for (k = 0; k < num_frames; k++) {
                if (frame[k] != -1) {
                    printf("%d ", frame[k]);
                }
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    int pages[MAX_PAGES];
    int num_pages, num_frames;
    int i, choice;

    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    printf("Enter the page reference string:\n");
    for (i = 0; i < num_pages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("\nChoose Page Replacement Algorithm:\n");
    printf("1. FIFO\n");
    printf("2. LRU\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fifoPageReplacement(pages, num_pages, num_frames);
            break;
        case 2:
            lruPageReplacement(pages, num_pages, num_frames);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}


'''
Output:

***********************************OUTPUT1***********************************


braham@braham:~/Desktop/program$ gcc page.c -o page
braham@braham:~/Desktop/program$ ./page

Enter the number of pages: 10
Enter the number of frames: 4
Enter the page reference string:
7 0 1 2 0 3 0 4 2 3

Choose Page Replacement Algorithm:
1. FIFO
2. LRU
Enter your choice (1 or 2): 1

FIFO Page Replacement Algorithm
Page Fault: 7 
Page Fault: 7 0 
Page Fault: 7 0 1 
Page Fault: 7 0 1 2 
Page Fault: 3 0 1 2 
Page Fault: 3 4 1 2 
Total Page Faults: 6


***********************************OUTPUT2***********************************


braham@braham:~/Desktop/program$ gcc page.c -o page
braham@braham:~/Desktop/program$ ./page
Enter the number of pages: 10
Enter the number of frames: 3
Enter the page reference string:
7 0 1 2 0 3 0 4 2 3

Choose Page Replacement Algorithm:
1. FIFO
2. LRU
Enter your choice (1 or 2): 2

LRU Page Replacement Algorithm
Page Fault: 7 
Page Fault: 0 
Page Fault: 0 1 
Page Fault: 0 1 2 
Page Fault: 0 3 2 
Page Fault: 0 3 4 
Page Fault: 0 2 4 
Page Fault: 3 2 4 
Total Page Faults: 8
'''