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
    int index;
};

// Customer entity:
struct Customer {
    char* name;
    double budget;
    struct ProductStock shoppintList[10];
    int index;
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
	printf("CUSTOMER NAME: %s \nCUSTOMER BUDGET: %.2f\n", c.name, c.budget);
	printf("-------------\n");
	for(int i = 0; i < c.index; i++)
	{
		printProduct(c.shoppingList[i].product);
		printf("%s ORDERS %d OF ABOVE PRODUCT\n", c.name, c.shoppingList[i].quantity);
		double cost = c.shoppingList[i].quantity * c.shoppingList[i].product.price; 
		printf("The cost to %s will be €%.2f\n", c.name, cost);
	}
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
struct Shop createAndStockShop() 
{
    
      struct Shop shop = { 200 };
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  size_t read;

  // read the file.
  fp = fopen("stock.csv", "r"); // "r" suggests it is to be read only.
  if (fp == NULL) // if file doesn't exist then exit the program.
  exit(EXIT_FAILURE);

  getline(&line, &len, fp!;
  double cashInShop = atof(line); // converting variable read
  struct Shop shop = { cashInShop 
                     }; // This struct represents what products are in stock in the shop. 400 is the shop cash.

          
  // Below we read each line to assign certain data to correct variables.
  while ((read = getline(&line, &len, fp)) != -1) // Reads line one by one to the end of file. "&line" will remember the line value. len looks at the length.
  {
    printf(": %s \n", line); // This is for cheking if the program reads the file
    
    // Method "strtok" is utilised to break down a string into a delimiter (eg ",").
    char *n = strtok(line, ","); // Obtain data (product name) from the line and assign it to variable "name".
    char *p = strtok(NULL, ",");  // Obtain product price.
    char *q = strtok(NULL, ",");  // Obtain product quantity available.
    // printf("NAME OF PRODUCT %s PRICE %s QUANTITY %s \n", name, price, quantity);
    
    // Next convert price and quantity into appropriate data types
    // To convert string into an integer using atoi.
    int quantity = atoi(q);
    // To convert into a floating point number using atof
    double price = atof(p);
    char *name = malloc(sizeof(char) * 50); //memory allocation 
    strcpy(name, n);
      
    //printf("NAME OF PRODUCT %s PRICE %.2f QUANTITY %s \n", name, price, quantity);
   
    struct Product product = {name, price};
    struct ProductStock stockItem = {product, quantity};
    shop.stock[shop.index++] = stockItem; // The above data taken from file will be added to shop stock of struct "Shop".
  }

  fclose(fp);

  return shop;
}
	  
}

double find(struct Shop s, char* name)
{
	for (int i = 0; i < s.index; i++)
	{
		if (strcmp(name, s.stock[i].product.name) == 0){
			return s.stock[i].product.price;
		}
	}
	return -1;
}

int main(void) 
{
	struct Product productA = { "Coke Can", 0.0 };
	struct Product productB = { "Milk", 0.0 };
	struct Product productC = { "Bread", 0.0 };
	struct ProductStock StockA = { productA, 12 };
	struct ProductStock StockB = { productB, 5 };
	struct ProductStock StockC = { productC, 2 };
	
	struct ProductStock array[] = { StockA, StockB, StockC }; 
	
	struct Shop shop = createAndStockShop();
	
	double totalCostForCustomer = 0;
	for(int i=0; i < 3; i++){
		struct Product p = array[i].product;
		double price = find(shop, p.name);
		printf("The price of %s in the shop is %.2f\n", p.name, price);
		double totalCostOfItem = array[i].quantity * price;
		printf("You want %d of %s, that will cost you %.2f\n", array[i].quantity, p.name, totalCostOfItem);
		totalCostForCustomer += totalCostOfItem;
	}
	printf("The total cost for the customer will be %.2f\n", totalCostForCustomer);
	
    return 0;
}

// Method to create a print out. It takes "struct Shop" as a parameter.
void printShop(struct Shop s)
{
  printf("=====\n");
  printf("Shop has %.2f in cash\n", s.cash);
  printf("=====\n");
  // create a for loop
  for (int i = 0; i < shop.index; i++)
  {
    struct Product product = s.stock[i].product;
    printProduct(product);
      
    printProduct(s.stock[i].product); // call to print product
    printf("The shop has %d of the above\n", s.stock[i].quantity);
    printf("-----\n");
  }
  printf("=====\n");
}
  
          
double FindProductPrice(struct Shop s, char *n)
  {
   for (int i = 0; i < shop.index; i++)
   {
    struct Product product = s.stock[i].product;
    char *name = product.name;
    if (strcmp(name, n) == 0) //if they are equal 0
    {
        return product.price;
    }
   }
  return -1; //if not return -1
  }

  struct Shop shop = createAndStockShop(); // This method will read all of the data from the csv stock file.
  printShop(shop);
  double price = findProductPrice(shop, "Can Coke");        
  printf("%.2f", price);          
          
  return 0;
}
