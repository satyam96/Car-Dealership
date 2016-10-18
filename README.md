# Car-Dealership
Suppose a used car dealer, Joe, has asked you to build a website for his car dealership.

He wants this website to allow users to be able to search for a set of cars on his lot that

are in their price range. That is, viewed abstractly, he would like you to build a system that

can maintain an ordered collection, D, of key-value pairs, such that, in addition to the

standard insert and removal methods,

the implementation for D can support the following operation:

findAllInRange(k1 , k2 ): Return all the elements in D with key k such that k1 ≤ k ≤ k2 .

In this case, of course, the keys are car prices. Write a program to implement this method.

The implemented algorithm must have a time complexity of O(log n + s), where n is the

number of cars in D and s is the number of cars returned by an instance of this range

query.
