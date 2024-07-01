#include <stdio.h>
#include <stdlib.h>
//give a set of numbers and a length R
//intervals with length 2*R and  the middle is in among those numbers
//the answer is the least number of intervals which could cover all the numbers

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N, R;
    scanf("%d %d", &N, &R);

    int villages[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &villages[i]);
    }    
    qsort(villages, N, sizeof(int), cmp);
    int stations = 0;
    int i = 0;
    while (i < N) {        
        int left_most_uncovered = villages[i];
        while (i < N && villages[i] <= left_most_uncovered + R) {
            i++;
        }        
        int station_position = villages[i - 1];        
        while (i < N && villages[i] <= station_position + R) {
            i++;
        }

        stations++;
    }

    printf("%d\n", stations);

    return 0;
}
