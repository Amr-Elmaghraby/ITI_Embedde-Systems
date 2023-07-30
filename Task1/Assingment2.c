// Include stdio lib to use scanf, printf
#include <stdio.h>

void main(void) {
    int num_1, num_2, num_3;

    // Input three numbers from the user
    printf("Please enter number1: ");
    scanf("%d", &num_1);

    printf("Please enter number2: ");
    scanf("%d", &num_2);

    printf("Please enter number3: ");
    scanf("%d", &num_3);

    // Print in reversed order
    printf("Reversed order: %d, %d, %d\n", num_3, num_2, num_1);

}