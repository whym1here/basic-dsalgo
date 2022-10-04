# Questions

## Question 01 : 
<!-- ``` -->
There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump two blocks to the right (from i he can jump to i + 1 or i + 2).

Calculate the number of different path to reach the last cell from the first cell.

0 <= n 
<!-- ``` -->

## Question 02 :
<!-- ``` -->
You are given a array of bools(i.e only filled with 1s or 0s) of length n. No two ones(1) can be next to each other(110 is illegal and 010 is legal). 

Calculate the number of such array possible. 

0 <= n 
<!-- ``` -->

## Question 03 : 
<!-- ``` -->
There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump three blocks to the right (from i he can jump to i + 1 or i + 2 or i + 3). 

Calculate the number of different path to reach the last cell from the first cell.

0 <= n 
<!-- ``` -->

## Question 04 : 
<!-- ``` -->
There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump k blocks to the right (from i he can jump to i + 1, i + 2, ... i + k). 

Calculate the number of different path to reach the last cell from the first cell.

0 <= n 
<!-- ``` -->

## Question 05 : 
<!-- ``` -->
There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump 2 blocks to the right (from i he can jump to i + 1 and i + 2). 
Jumping on each cell cost some money which is provided.

Find the minimum money spent to reach the the last cell from the first cell.

0 <= n 

Eg : 

c  : [ 0,  3,  5,  6,  7,  1,  5,  4,  3,  0]  
dp : [ 0,  3,  5,  9, 12, 10, 15, 14, 17, 14]
<!-- ``` -->

## Question 05 : 
<!-- ``` -->
There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump k blocks to the right (from i he can jump to i + 1, i + 2, ... i + k).  
Jumping on each cell cost some money which is provided.

Find the minimum money spent to reach the the last cell from the first cell.

0 <= n 
<!-- ``` -->

## Question 07 : 
<!-- ``` -->
There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump k blocks to the right (from i he can jump to i + 1, i + 2, ... i + k).  
Jumping on each cell cost some money which is provided.

Find the path followed to achieved minimum money spent to reach the the last cell from the first cell.

0 <= n 
<!-- ``` -->

## Question 08 :

r = row and c = column

|r/c|0|1|2|3|
|-|-|-|-|-|
|**0**|```#```|3|2|3|
|**1**|1|6|5|7|
|**2**|2|3|1|2|
|**3**|8|2|1|6|
|**4**|3|2|1|```$```|

```#``` starting point and ```$``` ending point

Each cell has some food (larger the better). Our Turtle needs to find the max sum on the path(for the food value).

Legal moves :
- (i, j) -> (i + 1, j) 
- (i, j) -> (i, j + 1)

## Question 09 :

There is a small GrassHopper living on the left most cell(0) of a array and he wants to reach the right most cell(n) of this array. He can only jump any number of blocks to the right. 

For each jump it cannot be shorter than the pervious jump.

Calculate the number of different path to reach the last cell from the first cell.

0 <= n 
