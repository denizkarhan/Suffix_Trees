# Suffix_Trees

## What is suffix tree used for?
Suffix tree is a compressed trie of all the suffixes of a given string. Suffix trees help in solving a lot of string related problems like pattern matching, finding distinct substrings in a given string, finding longest palindrome etc.


![banana](https://user-images.githubusercontent.com/81527587/165845040-4c41ce00-b0c9-480b-a7b2-15d062adbff2.png)
-Suffix tree for S = banana$ ($ denotes endof-string). Edge labels on a path from the root to a leaf correspond to a suffix in S. Leaf labels show the offset of each suffix in S 

## Step
A suffix tree T is a natural improvement over trie used in pattern matching problem, the one defined over a set of substrings of a string s. The idea is very simple here. Such a trie can have a long paths without branches. If we only can reduce these long paths into one jump, we will reduce the size of the trie significantly, so this is a great first step in improving the complexity of operations on such a tree. This reduced trie defined over a subset of suffixes of a string s is called a suffix tree of s

For better understanding, let's consider the suffix tree T for a string s = abakan. A word abakan has 6 suffixes {abakan , bakan, akan, kan, an, n} and its suffix tree looks like this:

![fa2b26c](https://user-images.githubusercontent.com/81527587/165845504-15d3b000-1372-4a92-9ccd-79aa771f97a4.jpg)

-There is a famous algorithm by Ukkonen for building suffix tree for s in linear time in terms of the length of s. However, because it may look quite complicated at first sight, many people are discouraged to learn how it works. Fortunately, there is a great, I mean an excellent, description of Ukkonen's algorithm given on StackOverflow. Please refer to it for better understanding what a suffix tree is and how to build it in linear time.

Suffix trees can solve many complicated problems, because it contain so many information about the string itself. Fo example, in order to know how many times a pattern P occurs in s, it is sufficient to find P in T and return the size of a subtree corresponding to its node. Another well known application is finding the number of distinct substrings of s, and it can be solved easily with suffix tree, while the problem looks very complicated at first sight.

The post I linked from StackOverflow is so great, that you simple must read it. After that, you will be able to identify problems solvable with suffix trees easily.

If you want to know more about when to use a suffix tree, you should read this paper about the applications of suffix trees.

Suffix Array
Suffix array is a very nice array based structure. Basically, it is a lexicographically sorted array of suffixes of a string s. For example, let's consider a string s = abakan. A word abakan has 6 suffixes {abakan , bakan, akan, kan, an, n} and its suffix tree looks like this:

![029389f](https://user-images.githubusercontent.com/81527587/165845557-8a5cec24-77ac-43be-88ef-6877d8807408.jpg)

Of course, in order to reduce space, we do not store the exact suffixes. It is sufficient to store their indices.

Suffix arrays, especially combined with LCP table (which stands for Longest Common Prefix of neighboring suffixes table), are very very useful for solving many problems. I recommend reading this nice programming oriented paper about suffix arrays, their applications and related problems by Stanford University.

Suffix arrays can be build easily in O(n * log2n) time, where n is the length of s, using the algorithm proposed in the paper from the previous paragraph. This time can be improved to O(n * log n) using linear time sorting algorithm.

However, there is so extraordinary, cool and simple linear time algorithm for building suffix arrays by Kärkkäinen and Sanders, that reading it is a pure pleasure and you cannot miss it.

Correspondence between suffix tree and suffix array
It is also worth to mention, that a suffix array can be constructed directly from a suffix tree in linear time using DFS traversal. Suffix tree can be also constructed from the suffix array and LCP table as described here.


