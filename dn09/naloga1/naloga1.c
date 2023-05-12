#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

int numbers[MAX_SIZE];
int stacks[MAX_SIZE][MAX_SIZE];
int stackSizes[MAX_SIZE];
bool taken[MAX_SIZE];
int target;
int n, k;

void print_stacks() {
    printf("{");
    for (int i = 0; i < k; i++) {
        printf("{%d", stacks[i][0]);
        for (int j = 1; j < stackSizes[i]; j++) {
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
        stacks[stackIdx][stackSizes[stackIdx]] = numbers[i];
        stackSizes[stackIdx]++;
        int sumWith = stackSum + numbers[i];
        if (sumWith == target) {
            rec(stackIdx + 1, 0, index_of(stacks[stackIdx][0]));
        } else if (sumWith < target) {
            rec(stackIdx, sumWith, i + 1);
        }
        taken[i] = false;
        stackSizes[stackIdx]--;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    int total = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", numbers + i);
        total += numbers[i];
    }
    target = total / k;
    rec(0, 0, 0);
    return 0;
}