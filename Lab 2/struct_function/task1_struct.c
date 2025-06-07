#include <stdio.h>

typedef struct {
    int quantity;
    float unit_price;
} items;


void item_details(items *itm, const char *itm_name) {
    printf("Quantity Of %s: ", itm_name);
    scanf("%d", &itm->quantity);
    printf("Unit Price: ");
    scanf("%f", &itm->unit_price);
}


float totalbill_calculate(items paratha, items vegetable, items mineral_water) {
    float total_bill = (paratha.quantity * paratha.unit_price) +
                       (vegetable.quantity * vegetable.unit_price) +
                       (mineral_water.quantity * mineral_water.unit_price);
    return total_bill;
}

int main() {
    items paratha, vegetable, mineral_water;
    int people;

    
    item_details(&paratha, "Paratha");

    
    item_details(&vegetable, "Vegetables");

    
    item_details(&mineral_water, "Mineral Water");

    
    printf("Number of People: ");
    scanf("%d", &people);

    
    float total_bill = totalbill_calculate(paratha, vegetable, mineral_water);

    
    float per_person_cost = total_bill / people;

    
    printf("Individual people will pay: %f tk\n", per_person_cost);

    return 0;
}
