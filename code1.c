#include <stdio.h>
#include <stdlib.h>
#define NUM_MONTHS 12


// Month names
const char *months[NUM_MONTHS] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};


// Declaring functions
void printMonthlySalesReport(double sales[]);
void printSalesSummary(double sales[]);
void printSixMonthMovingAverage(double sales[]);
void printSalesDescending(double sales[]);

int main() {
    double sales[NUM_MONTHS]; // Array used to store sales data
    char filename[100]; // Buffer to store file name

    // Asks user to enter file name
    printf("Enter your file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r"); // Opens user's file

    // Checks if file has been successfully opened
    if (file == NULL) {
        printf("Error, file not opened\n");
        return 1;
    }

    // Reads sales data from file
    for (int i=0; i < NUM_MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]); // Reads each sales figure from file
    }

    fclose(file); // Closes input file

    // Generates reports
    printf("Monthly Sales Report for 2024\n");
    printMonthlySalesReport(sales);

    printf("\nSales summary report: \n");
    printSalesSummary(sales);

    printf("\nSix-Month moving average report: \n");
    printSixMonthMovingAverage(sales);

    printf("\nSales report (highest to lowest): \n");
    printSalesDescending(sales);

    return 0;

}

// Function that prints the Monthly Sales Report
void printMonthlySalesReport(double sales[]) {
    printf("%-10s %10s\n", "Month", "Sales");
    for (int i=0; i<NUM_MONTHS; i++) {
        printf("%-10s %10.2f\n", months[i], sales[i]);
    }
}
