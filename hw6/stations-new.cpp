#include <stdio.h>
#include <stdlib.h>

// Function to compare two points for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the minimum number of intervals to cover points using dynamic programming
int min_intervals_to_cover(int points[], int num_points, int interval_length) {
    // Sort the points
    qsort(points, num_points, sizeof(int), compare);

    // Dynamic programming array to store the minimum intervals needed to cover points up to index i
    int dp[num_points];
    dp[0] = 1; // Base case: First interval covers the first point

    // Iterate through the points
    for (int i = 1; i < num_points; i++) {
        // Find the rightmost point covered by the current interval
        int rightmost_covered_point = points[i] - interval_length;

        // Find the largest index j such that points[j] <= rightmost_covered_point
        int j = i - 1;
        while (j >= 0 && points[j] > rightmost_covered_point)
            j--;

        // Minimum intervals needed to cover points up to index i is 1 + dp[j]
        dp[i] = 1 + dp[j];
    }

    // The final answer is stored in dp[num_points - 1]
    return dp[num_points - 1];
}

int main() {
    int N, R;
    scanf("%d %d", &N, &R);
    int points[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &points[i]);
    }
    
    int num_points = sizeof(points) / sizeof(points[0]);
    int interval_length = 2*R;

    int result = min_intervals_to_cover(points, num_points, interval_length);
    printf("%d\n", result);

    return 0;
}
