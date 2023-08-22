# AlmostEquivalentStrings

To search for inexact strings, you need to define a cost function. Possible actions: replace, insert, delete.
The algorithm calculates editing costs using dynamic programming.
The algorithm updates the contents of the parent index field of each cell in order to restore the editing sequence in the future.
![1](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/5526a82e-4552-496c-bea9-088aed023078)

The algorithm has a general structure, but some functions can be redefined to use the algorithm not only for string comparison, but for solving a wider class of problems.

For example, by modifying the initialization of rows and the choice of the goal cell, the cost of starting the match does not depend on the location in the text,
which allows us to use the algorithm to search substring.
![2](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/47c78f3d-abee-4374-ba20-eb327c858005)

And by redefining the cost of the comparison operation and making it unattractive (we make it higher than the total cost of insertion and deletion),
the algorithm can be used to find the longest common subsequence.
![3](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/1e38b118-de68-414d-9c2e-c6c8bb8d9cb9)

We also solve the problem of finding the maximum monotone subsequence. After analyzing, you can notice that this problem is a special case of the problem of "the longest common subsequence",
if the target string is built from the characters of the source string, but in a sorted order. For sorting, we use the heap sort algorithm.
![4](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/3b4de691-c411-47a3-9950-593e446865ed)

We create the objects of the resulting class hierarchy using the "factory method" pattern,
which allows us to determine on the fly during program execution which particular child class to use for the desired task.
