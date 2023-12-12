#include <stdlib.h>
#include <stdio.h>
#define SIZE 50

// Structure to represent a memory block
struct node {
    int data;        // 0 for unallocated, 1 for allocated
    int nextBlock;   // Index of the next block in the allocated file
};

// Array to simulate the memory
struct node memBlock[SIZE];

// Variable to keep track of the previous allocated block
int prevBlock = -1;

// Function to display the current status of memory
void displayMemoryStatus() {
    printf("\nMemory Status:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", memBlock[i].data);
    }
    printf("\n");
}

// Function to check if a block is already allocated
int isBlockAllocated(int blockIndex) {
    return memBlock[blockIndex].data == 1;
}

// Function implementing indexed file allocation
void indexed() {
    int size, allocated = 0;

    // Input: Length of the file to be allocated
    printf("\nEnter the length of the file: ");
    scanf("%d", &size);

    // Loop through memory to find contiguous unallocated blocks
    for (int st = 0; st < SIZE && allocated < size; st++) {
        if (memBlock[st].data == 0 && !isBlockAllocated(st)) {
            // If it's the first block, set it as the previous block
            if (prevBlock == -1) {
                prevBlock = st;
            }

            // Allocate the block and update the next block in the file
            memBlock[st].data = 1;
            memBlock[prevBlock].nextBlock = st;
            prevBlock = st;
            allocated++;
            printf("\n%d ---- Allocated", st);
        }
    }

    // Display an error if there's not enough contiguous memory for allocation
    if (allocated < size) {
        printf("\nError: Not enough contiguous memory for allocation.\n");
    }
}

// Main function
int main() {
    int choice;

    // Menu-driven program to interact with the user
    do {
        printf("\n1. Indexed File Allocation\n2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                indexed();
                displayMemoryStatus();
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);

    return 0;
}
