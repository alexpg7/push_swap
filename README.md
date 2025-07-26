# 🧮push_swap ![Static Badge](https://img.shields.io/badge/Barcelona-black?style=for-the-badge&logo=42&logoColor=%23FFFFFF)
![Static Badge](https://img.shields.io/badge/c-grey?style=flat&logo=c)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

A stack sorting algorithm. With the rules, rotate, swap and push between two stacks. The first 42 project of Milestone 2

## :hammer: Compilation
Firstly, copy the repository into you computer directory:

```bash
git clone https://github.com/alexpg7/push_swap.git push swap
```

Once copied, just execute the `make` command:

```bash
make
```

The `make`command should output all the object files (`*.o`) and the ``push_swap`` file.

You can also compile the `checker` program:

```bash
make bonus
```

Which outputs the `checker` file.

## :book: How to use it

Execute the program giving the numbers you want to sort as arguments.

```bash
./push_swap 6 5 4 3 2 1
```
the output should look as a list of instructions of movements to perform in order to sort the stack **a** leaving the stack **b** empty.

```output
rra
pb
rra
pb
rra
pb
rra
pb
sa
pa
pa
pa
pa
```

### :information_source: Bonus

Execute the `checker`program with some numbers:

```bash
./checker 3 2 1
```

Put the instructions to sort and press `Ctrl+D`:

```bash
sa
rra
```

The program tells you if you managed to sort the list:

```output
OK
```

### ➕Mix both programs

You can check if push swap is outputting correct instructions by pipeing the result:

```bash
./push_swap 78 65 4 2 42 79 81 | ./checker 78 65 4 2 42 79 81
```
```output
OK
```

## 🚦The algorthm
