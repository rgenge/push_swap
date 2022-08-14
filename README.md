# push_swap
Push swap is sorting algorithm project.
But in this project we have just a few restrictions to make it much more advanced than a simple sorting algorithm. 
For this project I used the bucket sort algorithm to push everything from A to B.
The I used insertion sort to bring back the max number to the A stack(rotating the stack after checking the fastest rotation to use).
So now you have your stack A sorted!
I got around 800 movements with 100 numbers and around 7700 movements with 500 numbers.
If you have any doubt and want some help and tips just message me! 

The rules
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order.
sa (swap a): Swap the first 2 elements at the top of stack a.
sb (swap b): Swap the first 2 elements at the top of stack b.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
pb (push b): Take the first element at the top of a and put it at the top of b.
ra (rotate a): Shift up all elements of stack a by 1.
rb (rotate b): Shift up all elements of stack b by 1.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
rrr : rra and rrb at the same time.
