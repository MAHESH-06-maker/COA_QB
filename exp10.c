#include <stdio.h>

int main() {
    // List of instructions
    char *instructions[] = {
        "ADD R1,R2,R3",
        "SUB R4,R5,R6",
        "MUL R7,R8,R9",
        "LOAD R1,100(R2)",
        "STORE R3,200(R4)"
    };

    // Pipeline stages
    char *stages[] = {"Fetch", "Decode", "Execute", "Memory", "Write-back"};

    int numInstructions = 5; // total instructions
    int numStages = 5;       // total pipeline stages

    // Each clock cycle
    for (int cycle = 1; cycle <= numInstructions + numStages - 1; cycle++) {
        printf("\nClock Cycle %d:\n", cycle);

        // For each instruction
        for (int i = 0; i < numInstructions; i++) {
            int stageIndex = cycle - i - 1; // find which stage instruction is in

            if (stageIndex >= 0 && stageIndex < numStages) {
                printf("Instruction %s in stage: %s\n",
                       instructions[i], stages[stageIndex]);
            }
        }
    }

    return 0;
}
