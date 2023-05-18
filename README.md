# Algorithm complexity evaluation

Implement a basic database (an array of pointers to arbitrary structures with ID numbers). Implement functions for searching (by ID), adding (random), and deleting (by ID) elements in the database.

Also, implement two sorting algorithms for this database - bubble sort and quicksort. You can use the quicksort algorithm from a library or find it on the internet.

The search, deletion, and insertion algorithms should work differently if the database is sorted. For example, searching in an unsorted database should be done with a full search, while in a sorted database, it should be done with binary search.

Create a static variable to count all iterations using loops when working with the database.

Implement a database operation simulator that takes as input the initial number of records in the database, the number of simulated queries, and the ratio of different types of queries (addition, deletion, search).

Run the simulator for two sets of data, and for each set, compare the number of iterations obtained for different configurations - an unsorted database, a database sorted by bubble sort, and a database sorted by quicksort.
