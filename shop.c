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

int main(void)
{
   struct Customer Mary = {"Mary", 100.0};
   printf("Customer name is %s\n", Mary.name);

   struct Product coke = { "Can Coke", 1.10 };
   printf("The %s costs %.2f\n", coke.name, coke.price);
    
   struct ProductStock cokeStock= { coke, 20 };
   printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);
   
   return 0;
}
