# 📊 42_PushSwap 📊
A project about sorting stacks with the minimun number of moves.

***

**✅Objective✅**


In this project we will create a program that sort numbers given by arguments in ascendent way in the minimun number of movements possible with the help of an auxiliar stack.

To make sure this is successfully done, we will need to implement functions that allow us to move the numbers of the stack (A stack is like a linked list of objects):

- `sa swap a` : Swap the two first elements of the stack A. It does nothing if the stack is empty.
- `sb swap b` : Swap the two first elements of the stack B. It does nothing if the stack is empty.
- `ss swap a & b` : Swap both stacks at the same time.
- `pa push a` : Push the first element from the stack B into stack A.
- `pb push b` : Push the first element from the stack A into stack B.
- `ra rotate a` : Moves up all the elements of the stack A. The first will be the last and the second will be the first.
- `rb rotate b` : Moves up all the elements of the stack B. The first will be the last and the second will be the first.
- `rr ra & rb` : Rotate the elements of A and B at the same time.
- `rra reverse rotate a` : Moves down all the elements of the stack A. The first will be the second and the last will be the first.
- `rrb reverse rotate b` : Moves down all the elements of the stack B. The first will be the second and the last will be the first.
- `rrr rra & rrb` : Reverse rotate the elements of A and B at the same time.

**📝Functions📝**
There we have a summary of the most valuable functions I implemented:
- `int	init_stack(t_stack **stack, int size, char **argv);` : This function will initiate the stack A with all the numbers given by argument, taking care about that the input is indeed a number (integer value) and doesn't already exists. 
- `void	ft_order(t_stack **a, t_stack **b, int argc);` : This function will call the correct function depending of the size of the stack (3 or less, 5 or less and higher).
- `void	reduce_stack(t_stack **a, t_stack **b, int size)` : This function will divide the stack in little groups to sort them quickly with less movements.
