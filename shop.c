// Build a simulation of a shop in c
// Entities: Shop, Customers, Products, Stock
// Steps: 1. Model the entities, 2. print product info, 3. print customer info, 4. add item to the customer shopping list, 5. read in stock from a file

#include <stdio.h>
#include <string.h>

struct Product {
    char* name;
    double price;
};

struct ProductStock {
    struct Product product;
    int quantity;
};

struct Shop {
    double cash;
    ProductStock stock[20];
};

struct Customer {
    char* name;
    double budget;
    struct ProductStock shoppintList[10];
};

void printProduct(struct Product p)
{
    printf("---------------------\n");
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: \n %.2f\n", p.name, p.price);
    printf("---------------------\n");
}


void printCustomer(struct )

int main(void)
{
   struct Customer Mary = {"Mary", 100.0};
   printf("Customer name is %s\n", Mary.name);

   struct Product coke = { "Can Coke", 1.10 };
   printProduct(coke);
    
   struct ProductStock cokeStock= { coke, 20 };
   printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);
   
   return 0;
}
