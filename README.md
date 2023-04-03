# radix-bucket_sort
radix sort

Sorting algorithm using linked lists and arrays. Takes 4 CLA: random seed, the number of values to generate, a lower bound, and an upper bound. After generating numbers, it calculates the number of digits in the largest number in the list, then performs a radix sort algorithm that iteratively sorts the values based on the digits. In each iteration, the program uses ten buckets to distribute the values based on their current digit, and then concatenates the buckets back into the original list. After the final iteration, the linked list is sorted in ascending order.

The program prints the linked list after each iteration, so that the user can see the sorting process. The output shows the sequence number of the current iteration, the contents of each bucket, and the sorted list after concatenation.
