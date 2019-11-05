// Multi-Paredigm Programming, GMIT 2019
// Lecturer: Dominic Carr
// Author:Mary McDonagh
// Build a simulation of a shop in c
// Entities: Shop, Customers, Products, Stock
// Steps: 1. Model the entities, 2. print product info, 3. print customer info, 4. add item to the customer shopping list, 5. read in stock from a file

// Importing external libraries
#include <stdio.h> // for reading files(?)
#include <string.h>
#include <stdlib.h> // required for atof() method (?)

// Product entity:
struct Product {
    char* name;
    double price;
};

// Stock entity:
// i.e. the products available in the shop
struct ProductStock {
    struct Product product;
    int quantity;
};

// Shop entity:
struct Shop {
    double cash;
    ProductStock stock[20];
};

// Customer entity:
struct Customer {
    char* name;
    double budget;
    struct ProductStock shoppintList[10];
};

// Method to print out the product and customer information

// Product information:
void printProduct(struct Product p)
{
    printf("---------------------\n");
    printf("PRODUCT NAME: %s \nPRODUCT PRICE: \n %.2f\n", p.name, p.price);
    printf("---------------------\n");
}


void printCustomer(struct Customer c)
{
    printf("---------------------\n");
    printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: \n %.2f\n", c.name, c.budget   );
    printf("---------------------\n");
}   

//int main(void)
//{
  // struct Customer Mary = {"Mary", 200.0};
  // printf("Customer name is %s\n", Mary.name);

  // struct Product coke = { "Can Coke", 1.50 };
  // printProduct(coke);
    
  // struct ProductStock cokeStock= { coke, 20 };
  // printf("The shop has %d of the product %s\n", cokeStock.quantity, cokeStock.product.name);
   
  // return 0;
//}

// Reading each line of data from a file and converting it into a variable (product stock). Then add to struct that represents the shop.
void createAndStockShop() 
{
  struct Shop shop = {400}; // This struct represents what products are in stock in the shop. 400 is the shop cash.

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  // read the file.
  fp = fopen("stock.csv", "r"); // "r" suggests it is to be read only.
  if (fp == NULL) // if file doesn't exist then exit the program.
  exit(EXIT_FAILURE);

  // Below we read each line to assign certain data to correct variables.
  while ((read = getline(&line, &len, fp)) != -1) // Reads line one by one to the end of file. "&line" will remember the line value. len looks at the length.
  {
    printf(": %s \n", line); // This is for cheking if the program reads the file
    
    // Method "strtok" is utilised to break down a string into a delimiter (eg ",").
    char *name = strtok(line, ","); // Obtain data (product name) from the line and assign it to variable "name".
    char *pri = strtok(NULL, ",");  // Obtain product price.
    char *qua = strtok(NULL, ",");  // Obtain product quantity available.

    // To convert string into an integer.
    int quantity = atoi(qua);
    double price = atof(pri);
    struct Product product = {name, price};
    struct ProductStock stockItem = {product, quantity};
    shop.stock[shop.index++] = stockItem; // The above data taken from file will be added to shop stock of struct "Shop".
  }

  fclose(fp);

  return shop;
}

// Method to create a print out. It takes "struct Shop" as a parameter.
void printShop(struct Shop sh)
{
  printf("=====\n");
  printf("Shop has %.2f in cash\n", sh.cash);
  printf("=====\n");
  for (int i = 0; i < sh.index; i++)
  {
    printProduct(sh.stock[i].product);
    printf("The shop has %d of the above\n", sh.stock[i].quantity);
    printf("-----\n");
  }
  printf("=====\n");
}

  struct Shop shop = createAndStockShop(); // This method will read data from a file.
  printShop(shop);
  return 0;
}
