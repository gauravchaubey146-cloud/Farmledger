#include <stdio.h>
#include <string.h>
 
#define MAX 20
 
char crop_name[MAX][20], crop_field[MAX][20], crop_status[MAX][20];
float crop_area[MAX], crop_cost[MAX];
int crop_count = 0;
 
char exp_name[MAX][20];
float exp_amount[MAX];
int exp_count = 0;
 
char har_crop[MAX][20];
float har_qty[MAX], har_rate[MAX], har_revenue[MAX];
int har_count = 0;
 
/* --- Crop --- */
void add_crop() {
    if (crop_count >= MAX) { printf("Limit reached!\n"); return; }
    printf("\nEnter Crop Name: "); scanf("%19s", crop_name[crop_count]);
    printf("Enter Field: "); scanf("%19s", crop_field[crop_count]);
    printf("Enter Area: "); scanf("%f", &crop_area[crop_count]);
    printf("Enter Cost: "); scanf("%f", &crop_cost[crop_count]);
    strcpy(crop_status[crop_count], "Growing");
    crop_count++;
    printf("Crop Added!\n");
}
 
void view_crops() {
    int i;
    if (crop_count == 0) { printf("No crops added yet!\n"); return; }
    printf("\nID  Name             Field            Area     Cost     Status\n");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < crop_count; i++) {
        printf("%-3d %-16s %-16s %-8.1f %-8.2f %s\n",
               i+1, crop_name[i], crop_field[i], crop_area[i], crop_cost[i], crop_status[i]);
    }
}
 
/* --- Expense --- */
void add_expense() {
    if (exp_count >= MAX) { printf("Limit reached!\n"); return; }
    printf("\nEnter Expense Name: "); scanf("%19s", exp_name[exp_count]);
    printf("Enter Amount: "); scanf("%f", &exp_amount[exp_count]);
    exp_count++;
    printf("Expense Added!\n");
}
 
void view_expenses() {
    int i;
    if (exp_count == 0) { printf("No expenses added yet!\n"); return; }
    printf("\nID  Name             Amount\n");
    printf("----------------------------\n");
    for (i = 0; i < exp_count; i++) {
        printf("%-3d %-16s %.2f\n", i+1, exp_name[i], exp_amount[i]);
    }
}
 
/* --- Harvest --- */
void add_harvest() {
    int id;
    if (har_count >= MAX) { printf("Limit reached!\n"); return; }
    if (crop_count == 0) { printf("No crops available!\n"); return; }
    view_crops();
    printf("Enter Crop ID: "); scanf("%d", &id);
    if (id < 1 || id > crop_count) { printf("Invalid ID!\n"); return; }
    if (strcmp(crop_status[id-1], "Harvested") == 0) {
        printf("Already harvested!\n"); return;
    }
    strcpy(har_crop[har_count], crop_name[id-1]);
    strcpy(crop_status[id-1], "Harvested");
    printf("Enter Quantity: "); scanf("%f", &har_qty[har_count]);
    printf("Enter Rate: "); scanf("%f", &har_rate[har_count]);
    har_revenue[har_count] = har_qty[har_count] * har_rate[har_count];
    har_count++;
    printf("Harvest Added! Revenue: %.2f\n", har_revenue[har_count-1]);
}
 
void view_harvests() {
    int i;
    if (har_count == 0) { printf("No harvests recorded!\n"); return; }
    printf("\nID  Crop             Quantity  Rate     Revenue\n");
    printf("------------------------------------------------\n");
    for (i = 0; i < har_count; i++) {
        printf("%-3d %-16s %-9.1f %-8.2f %.2f\n",
               i+1, har_crop[i], har_qty[i], har_rate[i], har_revenue[i]);
    }
}
 
/* --- Report --- */
void show_report() {
    int i;
    float revenue = 0, cost = 0, expense = 0, profit;
    if (crop_count == 0 && exp_count == 0 && har_count == 0) {
        printf("No data available!\n"); return;
    }
    for (i = 0; i < har_count; i++) revenue += har_revenue[i];
    for (i = 0; i < crop_count; i++) cost += crop_cost[i];
    for (i = 0; i < exp_count; i++) expense += exp_amount[i];
    profit = revenue - (cost + expense);
    printf("\n========== FARM REPORT ==========\n");
    printf("Total Crops    : %d\n", crop_count);
    printf("Total Harvests : %d\n", har_count);
    printf("Total Expenses : %d\n", exp_count);
    printf("---------------------------------\n");
    printf("Total Revenue  : %.2f\n", revenue);
    printf("Crop Cost      : %.2f\n", cost);
    printf("Other Expenses : %.2f\n", expense);
    printf("Total Cost     : %.2f\n", cost + expense);
    printf("---------------------------------\n");
    if (profit >= 0)
        printf("NET PROFIT     : %.2f\n", profit);
    else
        printf("NET LOSS       : %.2f\n", -profit);
    printf("=================================\n");
}
 
/* --- Main --- */
int main() {
    int choice;
    do {
        printf("\n===== FARM MANAGEMENT SYSTEM =====\n");
        printf("1. Add Crop\n2. View Crops\n3. Add Expense\n");
        printf("4. View Expenses\n5. Add Harvest\n6. View Harvests\n");
        printf("7. Show Report\n0. Exit\n");
        printf("==================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_crop();     break;
            case 2: view_crops();   break;
            case 3: add_expense();  break;
            case 4: view_expenses(); break;
            case 5: add_harvest();  break;
            case 6: view_harvests(); break;
            case 7: show_report();  break;
            case 0: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (choice != 0);
    return 0;
}
