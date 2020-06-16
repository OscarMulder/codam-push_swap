# codam-push_swap

Push_swap is a sorting algorithm project. The program sorts an array of integers, using only 2 stacks and a combination of the 11 operations specified in the subject.
The goal is to use as little operations as possible. My program uses an adaptation of Insertion Sort and Quicksort. It runs both and only displays output
for the algorithm that uses the least amount of operations.

The project also requires writing a checker program, which will recieve the same array of integers, and checks if the operations provided by push_swap will actually sort the array.

To run:
```
make
./push_swap 3 5 4 2 1 | ./checker 3 5 4 2 1
```
