#include <stdio.h>
#include <stdlib.h>

struct Numbers {
    int num1;
    int num2;
};

int main() {
    FILE *file;
    char filename[] = "numbers.txt";


    file = fopen(filename, "r");


    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }


    int numPairs;
    fscanf(file, "%d", &numPairs);


    struct Numbers *pairs = (struct Numbers *)malloc(numPairs * sizeof(struct Numbers));


    for (int i = 0; i < numPairs; i++) {
        fscanf(file, "%d %d", &pairs[i].num1, &pairs[i].num2);
    }


    fclose(file);


    for (int i = 0; i < numPairs; i++) {
        if (pairs[i].num1 == pairs[i].num2) {
            printf("equal\n");
        } else {
            printf("not equal\n");
        }
    }

    free(pairs);

    return 0;
}