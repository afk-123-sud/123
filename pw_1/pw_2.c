#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

enum MenuOption {
    MENU_PRINT = 1,
    MENU_SUM,
    MENU_MIN_MAX,
    MENU_AVERAGE,
    MENU_COUNT_POSITIVE,
    MENU_EXIT
};

void printArray(const long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%ld ", arr[i]);
    }
    printf("\n");
}

long long sumArray(const long arr[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void findMinMax(const long arr[], int size, long *min, long *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

long double averageArray(const long arr[], int size) {
    long long sum = sumArray(arr, size);
    return (long double)sum / size;
}

int countPositive(const long arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) count++;
    }
    return count;
}

int main() {
    long numbers[MAX_SIZE];
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Wrong size\n");
        return 0;
    }

    printf("Enter numbers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%ld", &numbers[i]);
    }

    int choice;
    bool work = true;

    while (work) {
        printf("\n1.Print\n2.Sum\n3.Min Max\n4.Average\n5.Positive\n6.Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case MENU_PRINT:
                printArray(numbers, n);
                break;

            case MENU_SUM:
                printf("Sum: %lld\n", sumArray(numbers, n));
                break;

            case MENU_MIN_MAX: {
                long min, max;
                findMinMax(numbers, n, &min, &max);
                printf("Min: %ld\nMax: %ld\n", min, max);
                break;
            }

            case MENU_AVERAGE:
                printf("Average: %.2Lf\n", averageArray(numbers, n));
                break;

            case MENU_COUNT_POSITIVE:
                printf("Positive: %d\n", countPositive(numbers, n));
                break;

            case MENU_EXIT:
                work = false;
                printf("Bye\n");
                break;

            default:
                printf("Error\n");
        }
    }

    return 0;
}