#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int first;
    int second;
} Pair;

int compare(const void *a, const void *b) {
    Pair *pairA = (Pair *)a;
    Pair *pairB = (Pair *)b;
    return pairA->second - pairB->second;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    Pair missions[n];
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        missions[i].first = a;
        missions[i].second = b;
    }
    qsort(missions, n, sizeof(Pair), compare);
    int nums = 0, total = n;
    while (total > 0) {
        Pair temp[total];
        int tempIndex = 0;
        for (int i = 0; i < total; i++) {
            if (missions[i].first >= missions[0].second) {
                temp[tempIndex++] = missions[i];
            }
        }
        memcpy(missions, temp, tempIndex * sizeof(Pair));
        total = tempIndex;
        nums++;
    }
    printf("%d", nums);
    return 0;
}
