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
    int choice;
    double x, y;
    
    while (1) {
        printf("\nScientific Calculator\n");
        printf("1. Square Root (√x)\n");
        printf("2. Factorial (x!)\n");
        printf("3. Natural Logarithm (ln(x))\n");
        printf("4. Power (xʸ)\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x < 0)
                    printf("Invalid input! Square root of negative number is not defined.\n");
                else
                    printf("Result: %.2lf\n", sqrt(x));
                break;
            
            case 2:
                printf("Enter a non-negative integer: ");
                int num;
                scanf("%d", &num);
                if (num < 0)
                    printf("Invalid input! Factorial of negative number is not defined.\n");
                else
                    printf("Result: %lld\n", factorial(num));
                break;
            
            case 3:
                printf("Enter number: ");
                scanf("%lf", &x);
                if (x <= 0)
                    printf("Invalid input! Logarithm is not defined for zero or negative numbers.\n");
                else
                    printf("Result: %.2lf\n", log(x));
                break;
            
            case 4:
                printf("Enter base (x): ");
                scanf("%lf", &x);
                printf("Enter exponent (y): ");
                scanf("%lf", &y);
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
