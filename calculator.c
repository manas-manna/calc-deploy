#include <stdio.h>
#include <math.h>

// Function to calculate factorial
long long factorial(int n) {
    if (n < 0) return -1; // Invalid case
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    setbuf(stdout, NULL);  // ✅ Makes stdout unbuffered (Fixes Docker issue)
    
    int choice;
    double x, y;

    while (1) {
        printf("\nScientific Calculator...\n");
        printf("1. Square Root (√x)\n");
        printf("2. Factorial (x!)\n");
        printf("3. Natural Logarithm (ln(x))\n");
        printf("4. Power (xʸ)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Read choice input and validate
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1-5.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter number: ");
                if (scanf("%lf", &x) != 1 || x < 0) {
                    printf("Invalid input! Enter a non-negative number.\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                printf("Result: %.2lf\n", sqrt(x));
                break;

            case 2:
                printf("Enter a non-negative integer: ");
                int num;
                if (scanf("%d", &num) != 1 || num < 0) {
                    printf("Invalid input! Enter a non-negative integer.\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                printf("Result: %lld\n", factorial(num));
                break;

            case 3:
                printf("Enter number: ");
                if (scanf("%lf", &x) != 1 || x <= 0) {
                    printf("Invalid input! Enter a positive number.\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                printf("Result: %.2lf\n", log(x));
                break;
s
            case 4:
                printf("Enter base (x): ");
                if (scanf("%lf", &x) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                printf("Enter exponent (y): ");
                if (scanf("%lf", &y) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'); // Clear buffer
                    continue;
                }
                printf("Result: %.2lf\n", pow(x, y));
                break;

            case 5:
                printf("Exiting calculator.\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a number between 1-5.\n");
        }
    }
    return 0;
}

