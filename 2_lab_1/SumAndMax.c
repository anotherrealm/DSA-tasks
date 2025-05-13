#include <stdio.h>

// Function to add up all numbers in array
int sum_array(int numbers[], int count) {
    int total = 0;
    for(int i = 0; i < count; i++) {
        total += numbers[i];
    }
    return total;
}

// Function to find biggest number in array
int find_max(int numbers[], int count) {
    if(count == 0) return -1; // Empty array case
    
    int max_num = numbers[0];
    for(int i = 1; i < count; i++) {
        if(numbers[i] > max_num) {
            max_num = numbers[i];
        }
    }
    return max_num;
}

int main() {
    int n;
    printf("How many numbers? ");
    scanf("%d", &n);
    
    int nums[n];
    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Sum: %d\n", sum_array(nums, n));
    printf("Largest number: %d\n", find_max(nums, n));
    
    return 0;
}