#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 10  

typedef struct Block {
    int blockNumber;
    int nextBlock;  
} Block;

Block disk[MAX_BLOCKS];

void initializeDisk() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        disk[i].blockNumber = i;
        disk[i].nextBlock = -1;  
    }
}

void allocateBlocks(int startBlock, int numBlocks) {
    if (numBlocks <= 0) {
        printf("Invalid number of blocks.\n");
        return;
    }
    
    int current = startBlock;
    for (int i = 0; i < numBlocks; i++) {
        if (current >= MAX_BLOCKS || disk[current].nextBlock != -1) {
            printf("Not enough contiguous blocks available.\n");
            return;
        }
        
        if (i < numBlocks - 1) {
            int next = current + 1;
            if (next < MAX_BLOCKS && disk[next].nextBlock == -1) {
                disk[current].nextBlock = next;
                current = next;
            } else {
                printf("Not enough contiguous blocks available.\n");
                return;
            }
        } else {
            disk[current].nextBlock = -1; 
        }
    }
    printf("Blocks allocated successfully.\n");
}

void displayAllocation() {
    printf("Block Allocation:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        printf("Block %d: Next Block = %d\n", disk[i].blockNumber, disk[i].nextBlock);
    }
}

int main() {
    int startBlock, numBlocks;

    initializeDisk();
    
    printf("Enter starting block number for allocation: ");
    scanf("%d", &startBlock);
    printf("Enter number of blocks to allocate: ");
    scanf("%d", &numBlocks);
    
    if (startBlock >= MAX_BLOCKS || startBlock < 0) {
        printf("Invalid starting block number.\n");
        return 1;
    }

    allocateBlocks(startBlock, numBlocks);
    displayAllocation();

    return 0;
}

'''
braham@braham:~/Desktop/program$ gcc file.c -o file
braham@braham:~/Desktop/program$ ./file

Enter starting block number for allocation: 2
Enter number of blocks to allocate: 4

Blocks allocated successfully.

Block Allocation:
Block 0: Next Block = -1
Block 1: Next Block = -1
Block 2: Next Block = 3
Block 3: Next Block = 4
Block 4: Next Block = 5
Block 5: Next Block = -1
Block 6: Next Block = -1
Block 7: Next Block = -1
Block 8: Next Block = -1
Block 9: Next Block = -1
'''