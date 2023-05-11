#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int numbers[20];
int (*stacks)[20];
int *capacities;
bool *taken;
int target;
int n, k;

void print_stacks() {
    printf("{");
    for (int i = 0; i < k; i++) {
        printf("{%d", stacks[i][0]);
        for (int j = 1; j < capacities[i]; j++) {
            printf(", %d", stacks[i][j]);
        }
        printf("}");
        if (i < k - 1) printf(", ");
    }

    printf("}\n");
}

int index_of(int element) {
    for (int i = 0; i < n; i++) {
        if (numbers[i] == element) return i;
    }
    return -1;
}

void rec(int stackIdx, int stackSum, int startIdx) {
    if (stackIdx == k && stackSum == 0) {
        print_stacks();
        return;
    }
    if (stackIdx >= k) return;

    for (int i = startIdx; i < n; i++) {
        if (taken[i]) continue;
        taken[i] = true;
        stacks[stackIdx][capacities[stackIdx]] = numbers[i];
        capacities[stackIdx]++;
        int sumWith = stackSum + numbers[i];
        if (sumWith == target) {
            rec(stackIdx + 1, 0, index_of(stacks[stackIdx][0]));
        } else if (sumWith < target) {
            rec(stackIdx, sumWith, i + 1);
        }
        taken[i] = false;
        capacities[stackIdx]--;
    }
}

int main() {
    scanf("%d %d", &n, &k);

    stacks = calloc(k, sizeof(int[20]));
    capacities = calloc(k, sizeof(int));
    taken = calloc(n, sizeof(bool));
    int total = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", numbers + i);
        total += numbers[i];
    }
    target = total / k;
    rec(0, 0, 0);
    return 0;
}