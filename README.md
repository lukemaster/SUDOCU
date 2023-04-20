# SUDOCU
Sudoku solver developed in C language

This story begins, more or less, in 2002, when my brother received a gift on his birthday: a game for solving sudokus.

That game was very simple:

    - 1 board able to be written and erased by marker
    - 2 markers: blue and black
    - 60 cards with the problem unsolved on one side
    - A cardboard wich contains each solution for each card
    * And a paper admiting mistakes in some solutions: 30, 46, 60... (I don't remember all)

Some years later, I started my degree of technical engineer in computer science, systems, and one day, when I was in the first year
I found the box of the game in the storage room. I remember I opened the box and the first thing I saw was the paper with the warning about
mistakes; I asked myself: are these the only mistakes... or maybe are there more undiscovered mistakes?

I was very bored, because it was Christmas holidays (that's why I was looking for something that I don't remember in the storage room), and
I didn't have any plan... So... Why can not doing a program to review all those sudokus contained in the game? (Why did not I use a website solver based on, I don't know)

And that day started this program. Since 2008 until 2023, I've walked a very long trail, looking for always a new sudoku for testing the program.

And yes! there was many times that the program fails, but at first, all sudokus in the game's box were checked, and the paper was right, hehe; then I discovered multisolution sudokus, and a kind of sudoku that needs a tree data structure to be solved, being able to get all its possible solutions.

The main algotithm is based on the probability to find a new number to be inserted in the problem.

So, if you have this sudoku


			 0 1 0	 7 9 0	 3 0 0	

			 4 0 0	 0 6 0	 0 1 0	

			 0 0 9	 3 8 0	 0 0 5	


			 0 5 0	 6 0 3	 0 0 0	

			 0 0 0	 0 7 0	 6 3 2	

			 0 6 8	 0 0 9	 5 0 4	


			 2 3 0	 9 0 0	 4 0 0	

			 0 0 6	 8 0 2	 0 0 7	

			 9 0 1	 0 0 0	 0 6 0	


Array of frequency would be:

| Number   |   Frequency   |
|:--------:|:-------------:|
|    1     |        3      |
|    2     |        3      |
|    3     |        5      |
|    4     |        2      |
|    5     |        3      |
|    6     |        6      |
|    7     |        3      |
|    8     |        3      |
|    9     |        5      |

Sorting this array by times repeated:

| Number   |   Frequency   |
|:--------:|:-------------:|
|    6     |        6      |
|    3     |        5      |
|    9     |        5      |
|    1     |        3      |
|    2     |        3      |
|    5     |        3      |
|    7     |        3      |
|    8     |        3      |
|    4     |        2      |


So, by probability, the next number that could be introduced in only one site could be number 6...

Cycling, updating frequency array, and/or forcing 'cleverly' or by permutations, numbers, rows, and combinations, this program tries to show all possible solutions of a sudoku.

I wish you enjoy it!


Rafa Luque