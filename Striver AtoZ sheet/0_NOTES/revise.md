# DSA REVISION NOTES

# Step 1 : Basics

## Patterns

## Learn STL

## Basic Maths

### 1. Count Digits

#### **UPOPTIMISED APPROACH**

- Create a counter , + each Number by 10 and Increase counter


### 2. Reverse Number

#### **OPTIMISED APPROACH**

- Take Remainder
- check if final ans > INT_MIN/10 || < INT_MAX/10
- Multiply final ans by 10 and add remainder

### 3. Check Palindrome Number

#### **OPTIMISED APPROACH**

- if negative return false
- else find the reverse of number
- if reverse num and original number same, return true

### 3. Check Armstrong Number

-sum of each digit raised to the power of number of digits equals the number itself

#### **OPTIMISED APPROACH**

- Initialize Armstrong Sum = 0
- Calculate Remainder and Then Divide By 10
- Add Remainder with pow of count of digits to Armstrong Sum
- If Armstrong Sum == number, Then it is an Armstrong Number

### 4. Print All Divisors

#### **UNOPTIMISED APPROACH**

- run loop from 1 till n and find n%i
- if it equals to 0 print i

#### **OPTIMISED APPROACH**

- ![alt text](<Images/alldivisors>)





