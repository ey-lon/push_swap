# push_swap
A program in C called *push_swap* which calculates and displays on the standard output the smallest amount of instructions, that sorts the integers received as arguments.

## Bonus
A program named *checker* that takes as an argument a stack formatted as a list of integers, execute instructions read from the standard input and checks, if after executing those instructions, the stack is actually sorted.

## How to use
| command | info |
| ------- | ---- |
| `make` | to compile *push_swap* |
| `make bonus` | to compile *checker* |

### push_swap
```shell
./push_swap <arg1> <arg2> <...> <argn>
```
or

```shell
ARGS="..."; ./push_swap $ARGS
```
### checker
```shell
./checker <arg1> <arg2> <...> <argn>
```
or

```shell
ARGS="..."; ./checker $ARGS
```
### Instructions
| Instruction | aka | Description |
| ----------- | --- | ----------- |
| sa | swap a | Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb | swap b | Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | | sa and sb at the same time. |
| pa | push a | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb | push b | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| ra | rotate a | Shift up all elements of stack a by 1. The first element becomes the last one. |
| rb | rotate b | Shift up all elements of stack b by 1. The first element becomes the last one. |
| rr | | ra and rb at the same time. |
| rra | reverse rotate a | Shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb | reverse rotate b | Shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr | | rra and rrb at the same time. |
