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

## 🚦The algorithm

### 📑The rules

The allowed operations are:

* push (**pa**, **pb**): pushes the top element from one stack to the top of the other.
* swap (**sa**, **sb**, **ss**): swaps the two top elements.
* rotate (**ra**, **rb**, **rr**): puts the first element to the bottom.
* reverse rotate (**rra**, **rrb**, **rrr**): puts the last element to the top.

### 📊Chunk algorithm

Although everyone uses the turkish algorithm to reach the maximum puntuation, a (modified) chunk algorithm can also reach the goal.

My implementation goes the following way:

Imagine we want to rotate the list: **89 0 54 120 99 25 42 100 1 65 73 102**.

### 1- Order the list by rank:

The idea is to put a "label" to each number, so that we get a list which ordering instructions are the same:

```math
\begin{align}
\text{\textbf{Number}} && \text{\textbf{Rank}} \\
89 & \longrightarrow & 8 \\
0 & \longrightarrow & 1 \\
54 & \longrightarrow & 5 \\
120 & \longrightarrow & 12 \\
99 & \longrightarrow & 9 \\
25 & \longrightarrow & 3 \\
42 & \longrightarrow & 4 \\
100 & \longrightarrow & 10 \\
1 & \longrightarrow & 2 \\
65 & \longrightarrow & 6 \\
73 & \longrightarrow & 7 \\
102 & \longrightarrow & 11 \\
\end{align}
```

So, the new list we have to order is: **8 1 5 12 9 3 4 10 2 6 7 11**.

It can now be represented as a stack:

```math
\begin{align}
&\text{\textbf{Stack a}} & \text{\textbf{Stack b}} \\
8&⬜⬜⬜⬜⬜⬜⬜⬜ &\\
1&⬜ & \\
5&⬜⬜⬜⬜⬜ & \\
12&⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ & \\
9&⬜⬜⬜⬜⬜⬜⬜⬜⬜ & \\
3&⬜⬜⬜ & \\
4&⬜⬜⬜⬜ & \\
10&⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ & \\
2&⬜⬜ & \\
6&⬜⬜⬜⬜⬜⬜ & \\
7&⬜⬜⬜⬜⬜⬜⬜ & \\
11&⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ & \\
\end{align}
```

Why do we want it this way? You'll see.

### 2- Chunk them

We will put a 2nd "label", the _cathegory_ (in the code), which goes by the name `cat` in the list structure used (``lib/list.h``). To do so, we choose the number of chunks by hand. The optimal size has been found by a "trial-error" method. In this case, our code would use $8$ chunks, but we will use $6$ to illustrate better the idea. 

We have to divide our rank list in 4 parts, following the rule $\text{cat} = (\text{rank} + 1) / (\text{maxrank} / 6)$

Now, the problem is breaking in different parts, the stack can now be visualized with their catheories by colors ($🟥\color{red}{(1)},🟧\color{orange}{(2)},🟨\color{yellow}{(3)},🟩\color{green}{(4)},🟦\color{blue}{(5)},🟪\color{purple}{(6)}$):

```math
\begin{align}
&\text{\textbf{Stack a}} & \text{\textbf{Stack b}} \\
8&🟩🟩🟩🟩🟩🟩🟩🟩 &\\
1&🟥 & \\
5&🟨🟨🟨🟨🟨 & \\
12&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & \\
9&🟦🟦🟦🟦🟦🟦🟦🟦🟦 & \\
3&🟧🟧🟧 & \\
4&🟧🟧🟧🟧 & \\
10&🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦 & \\
2&🟥🟥 & \\
6&🟨🟨🟨🟨🟨🟨 & \\
7&🟩🟩🟩🟩🟩🟩🟩 & \\
11&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & \\
\end{align}
```
### 3- Sort the chunks

Now, we have to sort the chunks by "brute force" and put them into **Stack b** (in the inverse order we want the numbers). We first need to stack the small numbers.

The rule to sort will be the following:

* Look for the 2 smallest types of chunks ($🟥\color{red}{(1)}$ and $🟧\color{orange}{(2)}$) and calculate which one is the closest to the top.
  * In this case, the closests are number $1(🟥)$ and $3(🟧)$
* Rotate (**ra**) until the closest one reaches the top, and push b (**pb**).
* Rotate again (**ra**) until the second one raches the top and push b (**pb**).
* If the second cathegory pushed is smaller than the first, swap b (**rb**) (not in this case).

These instructions (**ra** **pb** **ra** **ra** **ra** **pb**) result in the following stacks:

```math
\begin{align}
&\text{\textbf{Stack a}} & & \text{\textbf{Stack b}} \\
4&🟧🟧🟧🟧 & 3&🟧🟧🟧\\
10&🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦 & 1&🟥\\
2&🟥🟥 & \\
6&🟨🟨🟨🟨🟨🟨 & \\
7&🟩🟩🟩🟩🟩🟩🟩 & \\
11&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & \\
8&🟩🟩🟩🟩🟩🟩🟩🟩 &\\
5&🟨🟨🟨🟨🟨 & \\
12&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & \\
9&🟦🟦🟦🟦🟦🟦🟦🟦🟦 & \\
\end{align}
```

* Repeat the same. This time we will have to swap b **rb**, since the order of the stacks has been placed wrongly.

These steps lead to the instructions (**pb** **ra** **pb** **rb**) lead to:
```math
\begin{align}
&\text{\textbf{Stack a}} & & \text{\textbf{Stack b}} \\
6&🟨🟨🟨🟨🟨🟨 & 4&🟧🟧🟧🟧 \\
7&🟩🟩🟩🟩🟩🟩🟩 & 3&🟧🟧🟧\\
11&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & 1&🟥\\
8&🟩🟩🟩🟩🟩🟩🟩🟩 & 2&🟥🟥\\
5&🟨🟨🟨🟨🟨 & \\
12&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & \\
9&🟦🟦🟦🟦🟦🟦🟦🟦🟦 & \\
10&🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦 & \\
\end{align}
```

Repeat all these steps until the chunks are sorted. The instructions are (**pb** **rb** **pb** **ra** **pb** **pb** **rb** **pb** **pb** **rb** **pb** **rb** **pb**)

The current stacks should look like this:

```math
\begin{align}
&\text{\textbf{Stack a}} & & \text{\textbf{Stack b}} \\
& & 11&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 \\
& & 12&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 \\
& & 8&🟩🟩🟩🟩🟩🟩🟩🟩 \\
& & 7&🟩🟩🟩🟩🟩🟩🟩 \\
& & 4&🟧🟧🟧🟧 \\
& & 3&🟧🟧🟧 \\
& & 1&🟥 \\
& & 2&🟥🟥 \\
& & 6&🟨🟨🟨🟨🟨🟨 \\
& & 5&🟨🟨🟨🟨🟨 \\
& & 9&🟦🟦🟦🟦🟦🟦🟦🟦🟦  \\
& & 10&🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦 \\
\end{align}
```

### 4- Sort by rank

Finally, we have to return the numbers from **Stack b** to **Stack a**, using exactly the same method as before. For small numbers, searching for the $2$ largest ones is not that effective. When havving, for example $500$ numbers and $12$ chunks, it turns out to be really optimal.

* Look for the $2$ largest numbers (in this case, $11(🟪)$ and $12(🟪)$).
* Rotate until the closest one is at the top (nothing to do in this case) and push it to **a** (**pa**).
* Look for the other one, rotate to have it at the top (nothing to do in this case) and push it to **a** (**pa**)
* If the numbers were pushed in the incorrect order, swap **a** (**sa**).

These instructions are (**pa** **pa** **sa**) and lead to:
```math
\begin{align}
&\text{\textbf{Stack a}} & & \text{\textbf{Stack b}} \\
11&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪  & 8&🟩🟩🟩🟩🟩🟩🟩🟩 \\
12&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 & 7&🟩🟩🟩🟩🟩🟩🟩 \\
& & 4&🟧🟧🟧🟧 \\
& & 3&🟧🟧🟧 \\
& & 1&🟥 \\
& & 2&🟥🟥 \\
& & 6&🟨🟨🟨🟨🟨🟨 \\
& & 5&🟨🟨🟨🟨🟨 \\
& & 9&🟦🟦🟦🟦🟦🟦🟦🟦🟦  \\
& & 10&🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦 \\
\end{align}
```

* Repeat until the **Stack a** is sorted. The instructions are (**rrb** **pa** **rrb** **pa** **pa** **pa** **rrb** **pa** **rrb** **pa** **sa** **pa** **pa** **pa** **pa** **sa**) and lead to:

```math
\begin{align}
&\text{\textbf{Stack a}} & & \text{\textbf{Stack b}} \\
1&🟥 \\
2&🟥🟥 \\
3&🟧🟧🟧 \\
4&🟧🟧🟧🟧 \\
5&🟨🟨🟨🟨🟨 \\
6&🟨🟨🟨🟨🟨🟨 \\
7&🟩🟩🟩🟩🟩🟩🟩 \\
8&🟩🟩🟩🟩🟩🟩🟩🟩 \\
9&🟦🟦🟦🟦🟦🟦🟦🟦🟦  \\
10&🟦🟦🟦🟦🟦🟦🟦🟦🟦🟦 \\
11&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 \\
12&🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪🟪 \\
\end{align}
```

### 5- (Extra step) Clean the string

To reduce even more the instructions, look for combinations of (**ra** **rb** $\equiv$ **rr**), (**rra** **rrb** $\equiv$ **rrr**), (**sa** **sb** $\equiv$ **ss**) to compact the string.

This may not be helpful, but when sorting $500$ elements, it can reduce up to $300$ instructions; which may lead you achieve the highest score.

### ✔️Check it

Now, we can check if the outputed string is a solution of our problem. Execute the following command:

```bash
./checker 89 0 54 120 99 25 42 100 1 65 73 102
```

And paste the solution in the standard input:

```bash
ra
pb
ra
ra
ra
pb
pb
ra
pb
rb
pb
rb
pb
ra
pb
pb
rb
pb
pb
rb
pb
rb
pb
pa
pa
sa
rrb
pa
rrb
pa
pa
pa
rrb
pa
rrb
pa
sa
pa
pa
pa
pa
sa
```

The output is...
```output
OK
```
🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳🥳

## 📊[`push_swap_visualizer`](https://github.com/alexpg7/push_swap_visualizer)

With MiniLibX, I also have made a program to visualize the execution of your `push_swap` program, called [`push_swap_visualizer`](https://github.com/alexpg7/push_swap_visualizer). Using it, we can visualize the algorithm I implemented:

![til](https://github.com/alexpg7/Images/blob/main/ps_visualizer/Visualizer.gif)
