Name: Kelly Huang
Student ID: 1123526
Date of submission: 2024/11/26

Question 1: Binary Tree - Find the Diameter of a Binary Tree
Problem Statement:
Write a program to calculate the diameter of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root.

Input:
5,6,7,-1,-1,3,4,-1,-1,2,3,-1,-1,1,2

Output:
5

Question 2: Heap Sort - Build a Priority Queue for Tasks
Problem Statement:
Write a program to manage a task priority queue using a max heap. Each task has a name and a priority level. Your program should allow:
1.Add a Task: Add a task with a given priority.
2.Get the Highest Priority Task: Remove and return the task with the highest priority.
3.Display the Remaining Tasks: Print the remaining tasks in descending order of priority.

Input:
10
ADD Task1 5
ADD Task2 10
ADD Task3 8
GET
ADD Task4 9
ADD Task5 15
GET
ADD Task6 12
ADD Task7 20
GET

Output:
Task2
Task5
Task7
Remaining tasks: [('Task6', 12), ('Task4', 9), ('Task3', 8), ('Task1', 5)]

Question 3: Merge K Sorted Arrays Using Min Priority Queue
You are given K sorted arrays of integers. Write a C++ program to merge these arrays into a single sorted array using a Min Priority Queue.
Your program should:
1.Insert the first element of each array into a Min Priority Queue along with the array index and element index.
2.Extract the smallest element from the queue, add it to the result array, and insert the next element from the same array into the queue.
3.Continue this process until all elements from all arrays are merged.

Input:
4
1 10 12
3 8 11
4 7 9
2 5 6

Output:
Merged Array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]

Question 4: Schedule Tasks with Deadlines Using Max Priority Queue
You are given N tasks, each with a profit and a deadline. Write a C++ program to schedule the tasks such that the maximum profit is achieved, using a Max Priority Queue.
Each task must be completed within its deadline (1-based index), and only one task can be scheduled at a time.

Input:
5
23 3
22 2
13 1
32 2
20 1

Output:
Maximum Profit: 77
Scheduled Tasks: [32, 23, 22]