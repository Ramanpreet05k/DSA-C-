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

### 4. Check Armstrong Number

-sum of each digit raised to the power of number of digits equals the number itself

#### **OPTIMISED APPROACH**

- Initialize Armstrong Sum = 0
- Calculate Remainder and Then Divide By 10
- Add Remainder with pow of count of digits to Armstrong Sum
- If Armstrong Sum == number, Then it is an Armstrong Number

### 5. Print All Divisors

#### **UNOPTIMISED APPROACH**

- run loop from 1 till n and find n%i
- if it equals to 0 print i
- time complexity : O(n) 

#### **OPTIMISED APPROACH**

- Run A For Loop From 1 to <= sqrt(n)
- if n % i == 0, { then i is a divisor, if(n/i != i){ // Not 6 x 6 =36 i.e it's counter part is different then n/i is also a divisor }


- ![alt text](<../Images/alldivisors.png>)


### 6. Prime Number Check

- no that has exactly two factors : 1 and no itself

#### **UNOPTIMISED APPROACH**

- take a cnt=0, run loop from 2 to < than that number
- increment cnt if number%i==0
- after loop if cnt=0 , than a prime number else not
- Time Complexity : O(n)


#### **OPTIMISED APPROACH**

- take cnt=0 , and run loop from 2 to < than sqrt(number)
- if n%i == 0 , than increase cnt
- after loop completion , if cnt=0 than prime number else not


### 7. GCD or HCF

#### **UNOPTIMISED APPROACH**

- Loop from 1 to min(num1,num2)
- Divide Each Number With min(num1,num2)
- Return the Final Answer

#### **BETTER APPROACH**

- Loop from min(num1,num2) to 1
- Divide Each Number With min(num1,num2) if Found Then Break
- Return the Final Answer

#### **OPTIMISED APPROACH [Euclidean Algorithm]**

- Subtract & Update Lesser Number From Greater Number
- Keep Repeating This Step Till Any One Number is 0
- After any no. is 0 return the other number.



## Basic Recursion

- when a function calls itself until a specific condition is mey


### 3. Print 1 To N

#### **APPROACH 1**

- Run Recursion From n and also store current value as 1 solve(1,n)
- each step solve(current + 1, n)
- Base Condition current > n


#### **APPROACH 2 [BACKTRACKING]**

- Run recursion from n
- After solve(n-1) write the print statement (Backtracking)

- ![alt text](<../Images/backtracking.png>)



### 4. Sum of N Numbers

#### **APPROACH 1 [Recursion]**

- Run Recursion from n and also store current sum as 0 solve(sum, n)
- Base condition : if(n>=0)
- while backtracking return sum+n


#### **APPROACH 2**
- backtracking tiLL base condition n==0
- if n==0 return 0 
- else return n + f(n-1)
- altast it will be returning sum



### 6. Reverse An Array

#### **APPROACH 1 [2 pointer]**

- Run A for Loop
- Using 2 Pointer Technique to swap(arr[i], arr[n-i-1])

#### **APPROACH 2 [Recursion]**

- Recursion Function Pass array and iterator=0
- Base Condition iterator >= arr.size()/2
- swap(arr[iterator], arr[size-iterator-1])


