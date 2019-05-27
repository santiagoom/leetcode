## Divide and Conquer 

### Introduction

Divide and Conquer is an algorithmic paradigm. A typical Divide and Conquer algorithm solves a problem using following three steps.

**1.** *Divide:* Break the given problem into subproblems of same type.
**2.** *Conquer:* Recursively solve these subproblems
**3.** *Combine:* Appropriately combine the answers

### **Divide and Conquer (D & C) vs Dynamic Programming (DP)**

Both paradigms (D & C and DP) divide the given problem into subproblems and solve subproblems. How to choose one of them for a given problem? Divide and Conquer should be used when same **subproblems are not evaluated many times.** Otherwise Dynamic Programming or Memoization should be used. For example, Binary Search is a Divide and Conquer algorithm, we never evaluate the same subproblems again. On the other hand, for calculating nth Fibonacci number, Dynamic Programming should be preferred (See this for details). 



## Dynamic Programming

Dynamic Programming is an algorithmic paradigm that solves a given complex problem by breaking it into subproblems and stores the results of subproblems to avoid computing the same results again.Following are the two main properties of a problem that suggests that the given problem can be solved using Dynamic programming.

**1) Overlapping Subproblems**

**2) Optimal Substructure**



### Overlapping Subproblems Property

Like Divide and Conquer, Dynamic Programming combines solutions to sub-problems. Dynamic Programming is mainly used when solutions of same subproblems are needed again and again. In dynamic programming, computed solutions to subproblems are stored in a table so that these don’t have to be recomputed. So Dynamic Programming is not useful when there are no common (overlapping) subproblems because there is no point storing the solutions if they are not needed again. For example, Binary Search doesn’t have common subproblems. If we take an example of following recursive program for Fibonacci Numbers, there are many subproblems which are solved again and again.

```c++
/* simple recursive program for Fibonacci numbers */
int fib(int n)
{
   if ( n <= 1 )
      return n;
   return fib(n-1) + fib(n-2);
}
```



Recursion tree for execution of *fib(5)*

```
                         fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)
```

We can see that the function fib(3) is being called 2 times. If we would have stored the value of fib(3), then instead of computing it again, we could have reused the old stored value. There are following two different ways to store the values so that these values can be reused:
a) Memoization (Top Down)
b) Tabulation (Bottom Up)

#### **Memoization (Top Down)** 

The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions. We initialize a lookup array with all initial values as NIL. Whenever we need the solution to a subproblem, we first look into the lookup table. If the precomputed value is there then we return that value, otherwise, we calculate the value and put the result in the lookup table so that it can be reused later.

Following is the memoized version for nth Fibonacci Number.

**Java Code**

```java
/* Java program for Memoized version */
public class Fibonacci
{
  final int MAX = 100;
  final int NIL = -1;
 
  int lookup[] = new int[MAX];
 
  /* Function to initialize NIL values in lookup table */
  void _initialize()
  {
    for (int i = 0; i < MAX; i++)
        lookup[i] = NIL;
  }
 
  /* function for nth Fibonacci number */
  int fib(int n)
  {
    if (lookup[n] == NIL)
    {
      if (n <= 1)
          lookup[n] = n;
      else
          lookup[n] = fib(n-1) + fib(n-2);
    }
    return lookup[n];
  }
 
  public static void main(String[] args)
  {
    Fibonacci f = new Fibonacci();
    int n = 40;
    f._initialize();
    System.out.println("Fibonacci number is" + " " + f.fib(n));
  }
 
}
// This Code is Contributed by Saket Kumar
```

**Python Code**

```python
# Python program for Memoized version of nth Fibonacci number
 
# Function to calculate nth Fibonacci number
def fib(n, lookup):
 
    # Base case
    if n == 0 or n == 1 :
        lookup[n] = n
 
    # If the value is not calculated previously then calculate it
    if lookup[n] is None:
        lookup[n] = fib(n-1 , lookup)  + fib(n-2 , lookup) 
 
    # return the value corresponding to that value of n
    return lookup[n]
# end of function
 
# Driver program to test the above function
def main():
    n = 34
    # Declaration of lookup table
    # Handles till n = 100 
    lookup = [None]*(101)
    print "Fibonacci Number is ", fib(n, lookup)
 
if __name__=="__main__":
    main()
 
# This code is contributed by Nikhil Kumar Singh(nickzuck_007)
```



#### **Tabulation (Bottom Up)**

The tabulated program for a given problem builds a table in bottom up fashion and returns the last entry from table. For example, for the same Fibonacci number, we first calculate fib(0) then fib(1) then fib(2) then fib(3) and so on. So literally, we are building the solutions of subproblems bottom-up.

Following is the tabulated version for nth Fibonacci Number.

**Java Code**

```java
/* Java program for Tabulated version */
public class Fibonacci
{
  int fib(int n)
  {
    int f[] = new int[n+1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
          f[i] = f[i-1] + f[i-2];
    return f[n];
  }
 
  public static void main(String[] args)
  {
    Fibonacci f = new Fibonacci();
    int n = 9;
    System.out.println("Fibonacci number is" + " " + f.fib(n));
  }
 
}
// This Code is Contributed by Saket Kumar
```

**Python Code**

```python
# Python program Tabulated (bottom up) version
def fib(n):
 
    # array declaration
    f = [0]*(n+1)
 
    # base case assignment
    f[1] = 1
 
    # calculating the fibonacci and storing the values
    for i in xrange(2 , n+1):
        f[i] = f[i-1] + f[i-2]
    return f[n]
 
# Driver program to test the above function
def main():
    n = 9
    print "Fibonacci number is " , fib(n)
 
if __name__=="__main__":
    main()
 
# This code is contributed by Nikhil Kumar Singh (nickzuck_007)
```



#### Summary

Both Tabulated and Memoized store the solutions of subproblems. In Memoized version, table is filled on demand while in Tabulated version, starting from the first entry, all entries are filled one by one. **Unlike the Tabulated version, all entries of the lookup table are not necessarily filled in Memoized version.** For example, Memoized solution of the LCS problem doesn’t necessarily fill all entries.

To see the optimization achieved by Memoized and Tabulated solutions over the basic Recursive solution, see the time taken by following runs for calculating 40th Fibonacci number:

**Time taken by Recursion method is much more than the two Dynamic Programming techniques mentioned above – Memoization and Tabulation!**

We will be covering Optimal Substructure Property and some more example problems in future posts on Dynamic Programming.

Try following questions as an exercise of this post.
1) Write a Memoized solution for LCS problem. Note that the Tabular solution is given in the CLRS book.
2) How would you choose between Memoization and Tabulation?



### Optimal Substructure Property

A given problems has Optimal Substructure Property if optimal solution of the given problem can be obtained by using optimal solutions of its subproblems. 



For example, the Shortest Path problem has following optimal substructure property:
If a node x lies in the shortest path from a **source node u** to **destination node v** then the shortest path from u to v is combination of shortest path from u to x and shortest path from x to v. The standard All Pair Shortest Path algorithms like Floyd–Warshall and Bellman–Ford are typical examples of Dynamic Programming.

On the other hand, the Longest Path problem doesn’t have the Optimal Substructure property. Here by Longest Path we mean longest simple path (path without cycle) between two nodes. Consider the following unweighted graph given in the CLRS book. There are two longest paths from q to t: q→r→t and q→s→t. Unlike shortest paths, these longest paths do not have the optimal substructure property. For example, the longest path q→r→t is not a combination of longest path from q to r and longest path from r to t, because the longest path from q to r is q→s→t→r and the longest path from r to t is r→q→s→t.

![](C:\Users\Administrator\Desktop\Algorithems\20_leetcodes\Algorithms\LongestPath.gif)

### Tabulation vs Memoizatation

There are following two different ways to store the values so that the values of a problem can be reused. Here, will discuss two patterns of solving DP problem:

1. 1. **Tabulation:** Bottom Up
   2. **Memoization:** Top Down

Before getting to the definitions of the above two terms consider the below statements:

- **Version 1**: I will study the theory of Dynamic Programming from GeeksforGeeks, then I will practice some problems on classic DP and hence I will master Dynamic Programming.
- **Version 2**: To Master Dynamic Programming, I would have to practice Dynamic problems and to practice problems – Firstly, I would have to study some theory of Dynamic Programming from GeeksforGeeks

Both the above versions say the same thing, just the difference lies in the way of conveying the message and that’s exactly what Bottom Up and Top Down DP do. Version 1 can be related to as Bottom Up DP and Version-2 can be related as Top Down Dp.

**Tabulation Method – Bottom Up Dynamic Programming** 

As the name itself suggests starting from the bottom and cumulating answers to the top. Let’s discuss in terms of state transition.



Let’s describe a state for our DP problem to be dp[x] with dp[0] as base state and dp[n] as our destination state. So,  we need to find the value of destination state i.e dp[n].
If we start our transition from our base state i.e dp[0] and follow our state transition relation to reach our destination state dp[n], we call it Bottom Up approach as it is quite clear that we started our transition from the bottom base state and reached the top most desired state.

**Now, Why do we call it tabulation method?**

To know this let’s first write some code to calculate the factorial of a number using bottom up approach. Once, again as our general procedure to solve a DP we first define a state. In this case, we define a state as dp[x], where dp[x] is to find the factorial of x.

Now, it is quite obvious that dp[x+1] = dp[x] * (x+1)

```c
// Tabulated version to find factorial x.
int dp[MAXN];

// base case
int dp[0] = 1;
for (int i = 1; i< =n; i++)
{
    dp[i] = dp[i-1] * i;
}
```

The above code clearly follows the bottom-up approach as it starts its transition from the bottom-most base case dp[0] and reaches its destination state dp[n]. Here, we may notice that the dp table is being populated sequentially and we are directly accessing the calculated states from the table itself and hence, we call it tabulation method.

**Memoization Method – Top Down Dynamic Programming** 

Once, again let’s describe it in terms of state transition. If we need to find the value for some state say dp[n] and instead of starting from the base state that i.e dp[0] we ask our answer from the states that can reach the destination state dp[n] following the state transition relation, then it is the top-down fashion of DP.

Here, we start our journey from the top most destination state and compute its answer by taking in count the values of states that can reach the destination state, till we reach the bottom most base state.

Once again, let’s write the code for the factorial problem in the top-down fashion

```c
// Memoized version to find factorial x.
// To speed up we store the values
// of calculated states

// initialized to -1
int dp[MAXN]

// return fact x!
int solve(int x)
{
    if (x==0)
        return 1;
    if (dp[x]!=-1)
        return dp[x];
    return (dp[x] = x * solve(x-1));
}
```

As we can see we are storing the most recent cache up to a limit so that if next time we got a call from the same state we simply return it from the memory. So, this is why we call it memoization as we are storing the most recent state values.

**In this case the memory layout is linear that’s why it may seem that the memory is being filled in a sequential manner like the tabulation method,** but you may consider any other top down DP having 2D memory layout like Min Cost Path, here the memory is not filled in a sequential manner.

![](C:\Users\Administrator\Desktop\Algorithems\20_leetcodes\Algorithms\Tabulation-vs-Memoization-1.png)

### How to solve a Dynamic Programming Problem?

**D**ynamic **P**rogramming (DP) is a technique that solves some particular type of problems in Polynomial Time. Dynamic Programming solutions are faster than exponential brute method and can be easily proved for their correctness. Before we study how to think Dynamically for a problem, we need to learn:

1. Overlapping Subproblems
2. Optimal Substructure Property

```
Steps to solve a DP
1) Identify if it is a DP problem
2) Decide a state expression with least parameters
3) Formulate state relationship    
4) Do tabulation (or add memoization)
```

**Step 1 : How to classify a problem as a Dynamic Programming Problem?**

- Typically, all the problems that require to maximize or minimize certain quantity or counting problems that say to count the arrangements under certain condition or certain probability problems can be solved by using Dynamic Programming.
- All dynamic programming problems satisfy the overlapping subproblems property and most of the classic dynamic problems also satisfy the optimal substructure property. Once, we observe these properties in a given problem, be sure that it can be solved using DP.

**Step 2 : Deciding the state**
DP problems are all about state and their transition. This is the most basic step which must be done very carefully because the state transition depends on the choice of state definition you make. So, let’s see what do we mean by the term “state”.

**State:** A state can be defined as the set of parameters that can uniquely identify a certain position or standing in the given problem. This set of parameters should be as small as possible to reduce state space.

For example: In our famous Knapsack problem, we define our state by two parameters **index** and **weight** i.e DP\[index][weight]. Here DP\[index][weight] tells us the maximum profit it can make by taking items from range 0 to index having the capacity of sack to be weight. Therefore, here the parameters **index** and **weight** together can uniquely identify a subproblem for the knapsack problem.

So, our first step will be deciding a state for the problem after identifying that the problem is a DP problem.

As we know DP is all about using calculated results to formulate the final result.
So, our next step will be to find a relation between previous states to reach the current state.

**Step 3 : Formulating a relation among the states**
This part is the hardest part of for solving a DP problem and requires a lot of intuition, observation and practice. 

Let’s understand it by considering a sample problem

```
Given 3 numbers {1, 3, 5}, we need to tell
the total number of ways we can form a number 'N' 
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is: 8
1+1+1+1+1+1
1+1+1+3
1+1+3+1
1+3+1+1
3+1+1+1
3+3
1+5
5+1
```

Let’s think dynamically about this problem. So, first of all, we decide a state for the given problem. We will take a parameter n to decide state as it can uniquely identify any subproblem. So, our state dp will look like state(n). Here, state(n) means the total number of arrangements to form n by using {1, 3, 5} as elements.

Now, we need to compute state(n).

**How to do it?** 
So here the intuition comes into action. As we can only use 1, 3 or 5 to form a given number. Let us assume that we know the result for n = 1,2,3,4,5,6 ; being termilogistic let us say we know the result for the state (n = 1), state (n = 2), state (n = 3) ……… state (n = 6)

Now, we wish to know the result of the state (n = 7). See, we can only add 1, 3 and 5. Now we can get a sum total of 7 by the following 3 ways:

**2) Adding 3 to all possible combinations of state (n = 4);**

Eg : [(1+1+1+1) + 3]
[(1+3) + 3]
[(3+1) + 3]

**3) Adding 5 to all possible combinations of state(n = 2)**
Eg : [ (1+1) + 5]

Now, think carefully and satisfy yourself that the above three cases are covering all possible ways to form a sum total of 7;

Therefore, we can say that result for
state(7) = state (6) + state (4) + state (2)
or
state(7) = state (7-1) + state (7-3) + state (7-5)

In general,
**state(n) = state(n-1) + state(n-3) + state(n-5)**

So, our code will look like:

```c
// Returns the number of arrangements to 
// form 'n' 
int solve(int n)
{ 
   // base case
   if (n < 0) 
      return 0;
   if (n == 0)  
      return 1;  
 
   return solve(n-1) + solve(n-3) + solve(n-5);
}    
```

The above code seems exponential as it is calculating the same state again and again. So, we just need to add a memoization.

**Step 4 : Adding memoization or tabulation for the state**

This is the easiest part of a dynamic programming solution. We just need to store the state answer so that next time that state is required, we can directly use it from our memory

Adding memoization to the above code

```c++
// initialize to -1
int dp[MAXN];
 
// this function returns the number of 
// arrangements to form 'n' 
int solve(int n)
{ 
  // base case
  if (n < 0)  
      return 0;
  if (n == 0)  
      return 1;
 
  // checking if already calculated
  if (dp[n]!=-1) 
      return dp[n];
 
  // storing the result and returning
  return dp[n] = solve(n-1) + solve(n-3) + solve(n-5);
}
```



Another way is to add tabulation and make solution iterative. 

Dynamic Programming comes with a lots of practice. One must try solving various classic DP problems that can be found here. 