#include <stdio.h>

int main() {
    int memory[100], i, start, length, j, n;

    for (i = 0; i < 100; i++)
        memory[i] = 0;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter starting block and length of file %d: ", i + 1);
        scanf("%d %d", &start, &length);

        int flag = 0;
        for (j = start; j < start + length; j++) {
            if (memory[j] != 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            for (j = start; j < start + length; j++)
                memory[j] = i + 1;
            printf("File %d allocated successfully.\n", i + 1);
        } else {
            printf("File %d cannot be allocated.\n", i + 1);
        }
    }

    printf("\nMemory Allocation:\n");
    for (i = 0; i < 100; i++) {
        printf("%d ", memory[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }

    return 0;
}
