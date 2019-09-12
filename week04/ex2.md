## Exercise 2

> Part 1.

Three times loop running in the background:

![ex2_1](https://github.com/Divinil001/os-homeworks/blob/master/week04/images/ex2_1.png)

- Before the first `pstree` command `a.out` forks and creates its copy. Parent on the left, child on the right side. \
![ex2_1_1](https://github.com/Divinil001/os-homeworks/blob/master/week04/images/ex2_1_1.png)

- Between the first and the second `pstree` command both of the process created earlier forks themself.\
![ex2_1_2](https://github.com/Divinil001/os-homeworks/blob/master/week04/images/ex2_1_2.png)

- And on the third loop iteration all four process creates its copies. \
![ex2_1_3](https://github.com/Divinil001/os-homeworks/blob/master/week04/images/ex2_1_3.png)

In the end we have **8** processes.

> Part 2.

If we change the loop so it iterates 5 times, output will be the next:

![ex2_2](https://github.com/Divinil001/os-homeworks/blob/master/week04/images/ex2_2.png) \
![ex2_3](https://github.com/Divinil001/os-homeworks/blob/master/week04/images/ex2_3.png)

Basically, there will be no difference with the previous example. \
The only difference is that processes will copy themself two times more. \
So in the end we will have **32** processes.
