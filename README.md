# AlmostEquivalentStrings

To search for inexact strings, you need to define a cost function. Possible actions: replace, insert, delete.
The algorithm calculates editing costs using dynamic programming.
The algorithm updates the contents of the parent index field of each cell in order to restore the editing sequence in the future.
![resScreen1](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/a7a63821-b841-4879-aa68-51f236f64174)

The algorithm has a general structure, but some functions can be redefined to use the algorithm not only for string comparison, but for solving a wider class of problems.

For example, by modifying the initialization of rows and the choice of the goal cell, the cost of starting the match does not depend on the location in the text,
which allows us to use the algorithm to search substring.
![resScreen2](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/78cef3df-157b-4458-a6ca-0b4bc9f184da)

And by redefining the cost of the comparison operation and making it unattractive (we make it higher than the total cost of insertion and deletion),
the algorithm can be used to find the longest common subsequence.
![resScreen3](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/371055e2-bce2-45c8-9e7a-f7d5903a0f71)

We also solve the problem of finding the maximum monotone subsequence. After analyzing, you can notice that this problem is a special case of the problem of "the longest common subsequence",
if the target string is built from the characters of the source string, but in a sorted order. For sorting, we use the heap sort algorithm.
![resScreen4](https://github.com/Tricui11/AlmostEquivalentStrings/assets/42153889/73f1f1f1-29ff-4578-844a-acd570ed460f)

We create the objects of the resulting class hierarchy using the "factory method" pattern,
which allows us to determine on the fly during program execution which particular child class to use for the desired task.
