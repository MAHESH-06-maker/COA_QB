
#include <stdio.h>

#include <string.h>

#define BUFFER_SIZE 100

char memory[BUFFER_SIZE];
char deviceData[] = "DATAFROMDEVICE";

void programmedIO() {
    printf("\nProgrammed I/O Transfer Started...\n");
    for (int i = 0; deviceData[i] != '\0'; i++) {
        printf("Polling device...\n");
        memory[i] = deviceData[i];
        printf("Transferred: %c\n", memory[i]);
    }
    // memory[strlen(deviceData)] = '\0';
    printf("Data transferred using Programmed I/O: %s\n", memory);
}

void interruptIO() {
    printf("\nInterrupt-Driven I/O Transfer Started...\n");
    printf("Simulate interrupt (immediate for simplicity)\n");
    printf("Interrupt received. Transferring data...\n");
    strcpy(memory, deviceData);
    printf("Data Transferred using Interrupt I/O: %s\n", memory);
}

void dmaTransfer() {
    printf("\nDMA Transfer Started... CPU sets up DMA and continues working\n");
    printf("DMA Controller Transferring data...\n");
    strcpy(memory, deviceData);
    printf("DMA Transfer Complete. CPU Interrupted.\n");
    printf("Data transferred using DMA: %s\n", memory);
}

int main() {
    int choice;
   while (choice!=4){
    printf("\n--- Data Transfer Techniques ---\n");
        printf("1. Programmed I/O\n");
        printf("2. Interrupt-Driven I/O\n");
        printf("3. Direct Memory Access (DMA)\n");
        printf("4. Exit\n");
        printf("Choose a method (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                programmedIO();
                break;
            case 2:
                interruptIO();
                break;
            case 3:
                dmaTransfer();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
   }

    return 0;
}
