# multi-paradigm-prog-shop

The task is to add some additional functionality to the shop as follows:
1. The shop CSV should be modified to also hold the initial cash value for the shop.
- Read in customer orders from a CSV file.
– That file should include all the products they wish to buy and in what quantity.
– It should also include their name and their budget.
2. The shop must be able to process the orders of the customer.
– Update the cash in the shop based on money received.
∗ It is important that the state of the shop be consistent.
∗ You should create customer test files which cannot be completed by the shop e.g. customer want 400 loaves
of bread but the shop only has 20, or the customer wants 2 cans of coke but can only afford 1.
– Know whether or not the shop can fill an order.
∗ Thrown an appropriate error.
3. Operate in a live mode, where the user can enter a product by name, specify a quantity, and pay for it.
The above described functionality should be completed in C. The second part of the assessment involves replicating the
functionality of the shop in Java. This must be done in an appropriately Object Oriented manner. You must complete a
short report, 1-3 pages, which compares the solutions acheived using the procedural approach (in C) and the object oriented
approach (in Java). The live mode, and the input files, should have exact same behaviour in both implementations.



# References
Reading files in c: https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
STRtok function: https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
