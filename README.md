*This project has been created as part of the 42 curriculum by ldepenne*

## Description

The aim of this project is to sort a set of values in ascending order.
To do this, we can only use a limited number of functions and two memory stacks.

This project uses linked lists to store integers and manipulate them.

## Rules
**At the beginning:**

Two stacks named a and b.
The stack a contains a random number of unique negative and/or positive integers.
The stack b is empty.

**Authorised functions :**

sa (swap a): Swap the first 2 elements at the top of stack a.
	*Do nothing if there is only one element or none.*

sb (swap b): Swap the first 2 elements at the top of stack b.
	*Do nothing if there is only one element or none.*

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
	*Do nothing if b is empty.*

pb (push b): Take the first element at the top of a and put it at the top of b.
	*Do nothing if a is empty.*

ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.

rrr : rra and rrb at the same time.

## Instructions

The programme takes as an argument a list of unique negative and/or positive integers

## Ressources

enum : https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/les-enumerations/

Turk algorithm :
https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://medium.com/@beatrizdile/about

## Bonus

### Description

The goal is to create a checker for our push_swap.

It verifies, using the instructions given to it, that stack a is sorted in ascending order.

It must also verify that it has the same number of arguments as were given at the start, and that stack b is empty.

### Instructions

The programme takes a list of unique negative and/or positive integers such as push_swap as a parameter and executes the commands (see rules) given to it in the standard input.
