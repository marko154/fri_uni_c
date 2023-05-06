#include <stdio.h>
#include <stdlib.h>

int get_height(int node, int (*nodes)[2], int n) {
    if (node < 0 || node >= n) {
        return 0;
    }
    int left_offset = nodes[node][0];
    int right_offset = nodes[node][1];

    int l_height = 0, r_height = 0;
    if (left_offset != 0) {
        int left = node + nodes[node][0];
        l_height = get_height(left, nodes, n);
    }
    if (right_offset != 0) {
        int right = node + nodes[node][1];
        r_height = get_height(right, nodes, n);
    }
    return 1 + (l_height > r_height ? l_height : r_height);
}

int main() {
    int n;
    scanf("%d", &n);
    int c;

    int(*nodes)[2] = (int(*)[2])malloc(n * 2 * sizeof(int));
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[i][0] = a;
        nodes[i][1] = b;
    }

    printf("%d\n", get_height(0, nodes, n) - 1);
    return 0;
}