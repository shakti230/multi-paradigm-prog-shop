#!/usr/bin/env python
# coding: utf-8

# ## Mary McDonagh
# ## Programming for Data Analysis
# ## Assignment 2 - Multi Paradign programming

# Task: For each of the following write a functional, recursive, function in Python to accomplish the task.

# #### Question 1: Sum of an array 
# Given an array of numbers return it’s sum (all the numbers added together)

# In[6]:


# Return the sum for an array of numbers 

def sum(arr):
# if the length of the array is equal to 1
    if len(arr) == 1:
        return arr[0]
# add the value at 0 to the sum of the rest of the elements in the array
    else:
        return arr[0] + sum(arr[1:])

# Define a list of numbers to test with
arr = [1,2,3,4,5,6]
# Print the sum of the array
print(sum(arr))


# #### Question 2: Product of an array 
# 
# Given an array of numbers return it’s product (all the numbers multiplied together).

# In[7]:


# Define a list of numbers to test with
arr = [1,2,3,4,5,6]

def product(arr):
    # define the base case
    if len(arr) == 1:
# if the lenght of the array is 1 return the only value in the array
        return arr[0]
# if not then the function will add the value at index 0 to the product of the remainder of the list
    else:
        return arr[0] * product(arr[1:])   


# print out the product of the array
print(product(arr)) 


# #### Qestion 3: Remove all odd numbers 
# Given an array of numbers return an array with all the odd numbers removed.

# In[13]:


def remove_odd(arr):  
# if the list is empty then return an empty list  
    if not arr:
        return []
# if the element at position is even, return an array with this element in it and then check the remove the odds from the rest of the array 
    if arr[0] % 2 == 0:
        return [arr[0]] + remove_odd(arr[1:])
# if it is not even then check the next element in the array    
    return remove_odd(arr[1:])


# Define a list of numbers to test with
a = [1,2,3,4,5,6,7,8]
# Print the evens from the array
print(remove_odd(arr)) 


# #### Question 4: Remove all even numbers 
# Given an array of numbers return an array with all the even numbers removed. 

# In[22]:


def remove_even(arr):  
# if the list is empty then this will act as a base case and return an empty list 
    if not arr:
        return []
# If element is at a position of odd then return an array with this element and check to remove any even within the array 
    if arr[0] % 2 == 1:
# if it does then return the odd number and continue recursion
        return [arr[0]] + remove_even(arr[1:])
    # if its not odd - check the next element in the array    
    return remove_even(arr[1:])


 # Define a list of values to test with
arr = [1,2,3,4,5,6,7,8,9,10]
# the odds from the list
print(remove_even(arr)) 


# #### Question 5:Replace a given character with ’*’ 
# 
# 
# Given a string, and a character to replace, return a string where each occurance of the character is replaced with ’*’.

# In[28]:


# define the old and new character
old = 'e'
new = '*'

# take in a sentence, an old character and a new character
def replace_char(sentence, old, new):
# check if the sentence is empty
    if sentence == '':
        return ''
# if the sentence contains old, return the new character and continue recursion    
    if sentence[0] == old:
        return new + replace_char(sentence[1:], old, new)
    return sentence[0] + replace_char(sentence[1:], old, new)

# sentence
sentence = "The sky is very blue"

# print and test the function
print(replace_char("The sky is very blue", 'e', '*'))


# #### Question 6: Find index in array for item. 
# Given an array, and an element to search for return the index of the element in the array or -1 if the element is not present in the array.

# In[34]:


# array of values
arr = [1,2,3,4,5,6,7]

# counter
index=0

# number to find
number = 4

# take in an array, number to find and a counter i
def find_index(arr, number, index):
# if the array index is equal to the 4
    if arr[0] == number:
# return the index
        return index
    else:
# counting the index
        index = index +1
        return find_index(arr[1:], number, index)

# calling the function
ans = find_index(arr,number, index)
# print answer
print (ans)


# #### Question 7: Sum of Digits 
# Given a whole number such as 23, return the sum of the digits in the number i.e. 2 + 3 = 5. For this would be useful to convert the number to a string then break it apart into digits.

# In[38]:


# Take in a number using recursion
def sum_digits(number):
# if it is equal to 0, return
    if number == 0:
        return number
    else:
# modulus of the number is added together
        return number%10 + sum_digits(number//10)

# Break number 36 apart into digits
number = 36

ans =sum_digits(number)
# print the result
print (ans)


# #### Question 8: Print an array 
# Given an array of integers prints all the elements one per line. This is a little bit different as there is no need for a ’return’ statement just to print and
# recurse.

# In[47]:


def print_arr(array):
# if lenght of array is not 0 then print the first value and call the function on the remainder of array
  if len(array) != 0:
    print(array[0])
    print_arr(array[1:])

# Define list of numbers to test with
a = [1,2,3,4,5,6,7]
# Print the values in the array
print_arr(a)  


# #### Question 9: Find the minimum element in an array of integers. 
# You can carry some extra information through method arguments such as minimum value.

# In[50]:


def find_min(arr):
    if len(arr) == 1:
       return arr[0]
    else:
# return the minimum value
       return min(arr[0], find_min(arr[1:]))


# define the array of values
arr = [2,3,4,5,6,7]

# call the funtion
ans =find_min(arr)
# print
print (ans)


# #### Question 10: Verify the parentheses 
# Given a string, return true if it is a nesting of zero or more pairs of parenthesis, like “(())” or “((()))”.

# In[55]:


def check(string, counter=0):
  if not string:
    return "True" if counter == 0 else "False"
# if the counter is less than 1 then it not balanced
  elif counter < 0:
    return "False"
# if the char is (
  elif string[0] == "(":
# continue and add to 1 to counter
    return check(string[1:], counter+1)
# then check if the char is )
  elif string[0] == ")":
# continue and subtract 1 from counter
    return check(string[1:], counter-1)
  else:
    return check(string[1:], counter)

# string to check
string ="(())"

# test and call the function
print(check(string))


# #### References:
# - Removing odd numbers: https://www.includehelp.com/python/print-list-after-removing-even-numbers.aspx
# - Removing odd numbers: https://www.geeksforgeeks.org/python-program-to-print-odd-numbers-in-a-list/
# - Find index in an array: https://www.quora.com/How-do-I-get-index-of-an-item-from-a-list-in-Python
# - Find index in an array: https://thispointer.com/python-how-to-find-all-indexes-of-an-item-in-a-list/
# - Sum of digits: https://www.geeksforgeeks.org/sum-digit-number-using-recursion/
# - Min element in array of integers: https://www.geeksforgeeks.org/recursive-programs-to-find-minimum-and-maximum-elements-of-array/
# - Verify parentheses: https://stackoverflow.com/questions/38833819/python-program-to-check-matching-of-simple-parentheses
# - Verify parentheses: https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-python/
# 
