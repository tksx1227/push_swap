# push_swap

A program that sorts integers using two stacks and some operations on them.

## Description

This program sorts a given numeric string by applying multiple operations to two stacks.

There are 11 operations shown below.

`sa (swap a)` : Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

`sb (swap b)` : Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

`ss` : `sa` and `sb` at the same time.

`pa (push a)` : Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

`pb (push b)` : Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

`ra (rotate a)` : Shift up all elements of stack a by 1. The first element becomes the last one.

`rb (rotate b)` : Shift up all elements of stack b by 1. The first element becomes the last one.

`rr` : `ra` and `rb` at the same time.

`rra` (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.

`rrb (reverse rotate b)` : Shift down all elements of stack b by 1. The last element becomes the first one.

`rrr` : rra and rrb at the same time.

## Usage

As shown below, the program can be executed by giving multiple numbers as arguments.

The program outputs line by line the operations required to sort a given number.

```shell
$ make
$ ./bin/push_swap <numbers>
```

To check if the output operation is correct, you can check it by using the attached checker.

Enter the following command to generate a checker.

Then, pass the same number passed to push_swap as a checker argument and enter the output result of push_swap line by line.

After entering the operation, press Ctl+D to finish the entry, and it will be displayed whether the sort is completed.

```shell
$ make bonus
$ ./bin/checker <numbers>
> <operations>
```

## Example

An actual execution example is shown below.

```shell
$ ./bin/push_swap 3 4 2 1
ra
ra
ra
pb
rra
pa
```

Test the above results.

```shell
$ ./bin/checker 3 4 2 1
> ra
> ra
> ra
> pb
> rra
> pa
OK
```
