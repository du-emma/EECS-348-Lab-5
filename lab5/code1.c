/*
Name: Emma Du
KUID: 3134852
Lab Session: Friday at 1pm with Toye
Lab Assignment Number: 05
Program Description: Program reads 12 monthly sales and generates a sales report
Collaborators: None
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define NUM_MONTHS 12


/*
 * Global constants
 */
// Month names
const char *months[NUM_MONTHS] = {
    "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};


/*
 * Declaring functions
 */
void sortSalesArray(double originalSales[], double sortedSales[]);
void printMonthlySalesReport(double sales[]);
void printSalesSummary(double sales[], double sortedSales[]);
void printSixMonthMovingAverage(double sales[]);
void printSalesDescending(double sales[], double sortedSales[]);


/*
 *
 * Main function to take input file and generate multipel reports
 *
 */
int main() {

    /*
     * Decare variables
     */
    double sales[NUM_MONTHS];        // Array used to store sales data
    double sortedSales[NUM_MONTHS];  // Array used to store sorted sales data highest to lowest
    char   filename[100];            // Buffer to store file name


    /*
     * Prompt user for input file, read the  file, and populate sales array
     */

    // Asks user to enter file name
    printf("Enter your file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r"); // Opens user's file

    // Checks if file has been successfully opened
    if (file == NULL) {
        printf("Error, file not opened\n");
        return 1;
    }

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

    /*
     *  Sort sales array, populate the sortedSales array using original sales array
     */
    sortSalesArray(sales, sortedSales);


    /*
     * Generates reports
     */
    printf("\n\nMonthly Sales Report for 2024\n\n");
    printMonthlySalesReport(sales);

    printf("\nSales summary report: \n\n");
    printSalesSummary(sales, sortedSales);

    printf("\nSix-Month moving average report: \n\n");
    printSixMonthMovingAverage(sales);

    printf("\nSales report (highest to lowest): \n\n");
    printSalesDescending(sales, sortedSales);

    return 0;

}



/*
 * Function that prints the Monthly Sales Report
 */
void printMonthlySalesReport(double sales[]) {
    printf("%-10s %-10s\n", "Month", "Sales");
    for (int i=0; i<NUM_MONTHS; i++) {
        printf("%-10s $%-10.2f\n", months[i], sales[i]);
    }
}


/*
 * Function that prints sales Summary
 */
void printSalesSummary(double sales[], double sortedSales[]) {
    double totalSales = 0.0;
    int minIndexInOriginalSales = 0;
    int maxIndexInOriginalSales = 0;

    for (int i=0; i<NUM_MONTHS; i++) {
        totalSales += sales[i];
        if(sortedSales[11] == sales[i]) {
            minIndexInOriginalSales = i;
        }
        if(sortedSales[0] == sales[i]) {
            maxIndexInOriginalSales = i;
        }
    }

    printf("Minimum sales: $%-10.2f (%-s)\n", sortedSales[11] , months[minIndexInOriginalSales]);
    printf("Maximum sales: $%-10.2f (%-s)\n", sortedSales[0] ,  months[maxIndexInOriginalSales]);
    printf("Average sales: $%-10.2f\n", totalSales / NUM_MONTHS);
}

/*
 * Function that prints Six Month Moving Average
 */
void printSixMonthMovingAverage(double sales[]) {
    int startMonthIndex = 0;
    int endMonthIndex = startMonthIndex + 5;
    double movingSixMonthTotal = 0.00;

    // Loop until end month is out of range
    while (endMonthIndex < NUM_MONTHS) {
       for (int i=startMonthIndex; i <= endMonthIndex; i++) {
         movingSixMonthTotal += sales[i];
       }
       double movingAverage = movingSixMonthTotal / 6;

       // Concat the months names in range
       char monthRange[22];
       strcpy(monthRange,  months[startMonthIndex]);
       strcat(monthRange, "-");
       strcat(monthRange,  months[endMonthIndex]);

       // Print moving average for current range
       printf("%-20s $%-10.2f\n",  monthRange, movingAverage);

       // Move to next range, and set total back to zero
       startMonthIndex++;
       endMonthIndex++;
       movingSixMonthTotal = 0.00;
   }

}



/*
 * Function that prints Sales Report from highest to lowest
 */
void printSalesDescending(double sales[], double sortedSales[]) {
   int amountInSalesCnt = 0;
   int printedInSalesCnt = 0;
   double currentSortedSalesAmount = 0.0;
   double previousSortedSalesAmount = 0.0;

   printf("%-10s %-10s\n", "Month", "Sales");

   for (int i=0; i<NUM_MONTHS; i++) {

      if(i != 0 && sortedSales[i] == sortedSales[i-1]) {
         amountInSalesCnt++;
      }
      else {
         amountInSalesCnt = 1;
      }

      for(int j=0; i<NUM_MONTHS; j++) {

         if(sortedSales[i] == sales[j]) {
           printedInSalesCnt++;
         }
         if(amountInSalesCnt == printedInSalesCnt) {
            printf("%-10s $%-10.2f\n", months[j], sales[j]);
            printedInSalesCnt = 0;
            break;
         }
      }
   }

}


/*
 * Utility functions
 *
 */


/*
 * Coompare doubles
 */
static int compareDouble (const void * a, const void * b)
{
  if (*(double*)a < *(double*)b) return 1;
  else if (*(double*)a > *(double*)b) return -1;
  else return 0;
}


/*
 * Copy originalSales data to sortedSales, and sort sortedSales in dedending order
 */
void  sortSalesArray(double originalSales[], double sortedSales[]) {

    // Copy the original array to the new array
    for (int i = 0; i < NUM_MONTHS; i++) {
        sortedSales[i] = originalSales[i];
    }

    // Sort the new array using qsort
    qsort(sortedSales, NUM_MONTHS, sizeof(double), compareDouble);
}
