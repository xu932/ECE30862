# HW11

Write a matrix multiply A = B x C that first uses 1, then 2 and then 4 threads. Let N be the number of rows and columns in A, and let N be divisible by 2. You have been provided a sequential implementation in `MM.java` and `Main.java` that needs to be changed to be multithreaded. You need to change/add very few lines, and there are comments providing hints.<br>
<br>
In particular, in `MM.java`, the difference between the code I’ve given you and the code needed for the multithreaded implementation is 5 lines that are changed. In `Main.java`, 2 lines need to be changed, 1 line needs to be deleted, and about 10 lines added. Your code may change a different number of lines and add a different number of lines, but this will give you a ballpark estimate of how much work you need to do.
