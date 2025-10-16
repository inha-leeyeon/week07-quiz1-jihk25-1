[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/VpL0ElM-)
# Week07 Quiz1:

## 1. Requirements:

In a two-dimensional plane, we want to define a Square class as a derived class using the Point class as a common base. When the name of the square, the coordinates of the bottom-left vertex (in the order of x-coordinate and y-coordinate), and the length of one side are input (one line per square), a Square object is created and added to a vector. The generated squares are sorted by area, x-coordinate, and y-coordinate in ascending order, and the results are output.

- Writing code using c++
- Use `Point` class and `Square` class to complete your code. 
- Changing the provided class is not allowed. You can `only use the provided class and the functions defined within it`.
- You need to store the `given class definitions` in the `Point.h` file and `Square.h` file. Store the `function definitions and the main function` in the `main.cpp` file.   
  `(Please submit the above two documents, and if you do not name the main file "main.cpp", the test will not pass and you will receive zero points)`
- Your submitted files should `include only one ".cpp" file named "main.cpp"`. Any ".cpp" files with other names will not be accepted by the test system.
- Please confirm the containment relationship between header file and main file.

<br/>
                  
### Point class:
- Complete and use the following class:
  ```C++
  class Point {
	public:
		Point(int px = 0, int py = 0);
		int getX() const;
		int getY() const;
		void setX(int);
		void setY(int);
	private:
		int x; // The x-axis coordinate of the point
		int y; // The y-axis coordinate of the point
	};
  ```
  
### Square class:
- Complete and use the following class:
  ```C++
  class Square : public Point {
	public:
		Square(const string, int, int, unsigned int = 0);
		unsigned int getSide() const;
		unsigned int getArea() const;
		string getName() const;
		void setSide(unsigned int);
		void setArea(unsigned int);
		void setName(string);
	private:
		unsigned int side; 
		unsigned int area{ 0 };
		string name;
	};
  ```
<br/>

- The area should be the square of the side length。
- Allow the use of vectors. When using, it is necessary to declare `#include <vector>` in advance.
- The reference point should be set as the coordinate point in the `lower left corner` of the square.
  
<br/>

### Input
- The first line should input a number (int type) indicating the number of stored squares.  
- Starting from the second line, enter the name of the square, x-axis coordinates, y-axis coordinates, and side length in sequence.  
  e.g.
	```
	S1 1 2 3
	S2 -2 -5 2
	S3 15 20 5
	S4 100 -10 10
	S5 40 -30 4
	```

<br/>

### Output  

- Set a blank line between input and output.
- The first set of data should output "Squares in increasing order of area", and then output the data`(name(reference x-coordinates, reference y-coordinates), side, area)` in `ascending order` according to the size of the square area.  
  e.g.
  ```
	Squares in increasing order of area
	S2(-2, -5) side=2, area=4
	S1(1, 2) side=3, area=9
	S5(40, -30) side=4, area=16
	S3(15, 20) side=5, area=25
	S4(100, -10) side=10, area=100
  ```
- Set a blank line between first and second set of data.
- The second set of data should output "Squares in increasing order of max x-coordinate", and then output the data`(name(max x-coordinates, reference y-coordinates), side, area)` in `ascending order` according to the max x-coordinate of the square.  
  e.g.
  ```
	Squares in increasing order of max x-coordinate
	S2(0, -5) side=2, area=4
	S1(4, 2) side=3, area=9
	S3(20, 20) side=5, area=25
	S5(44, -30) side=4, area=16
	S4(110, -10) side=10, area=100
  ```
- Set a blank line between second and third set of data.
- The third set of data should output "Squares in increasing order of max y-coordinate", and then output the data`(name(reference x-coordinates, max y-coordinates), side, area)` in `ascending order` according to the max y-coordinate of the square.  
  e.g.
  ```
	Squares in increasing order of max y-coordinate
	S5(40, -26) side=4, area=16
	S2(-2, -3) side=2, area=4
	S4(100, 0) side=10, area=100
	S1(1, 5) side=3, area=9
	S3(15, 25) side=5, area=25
  ```


<br/>


## 2. Scoring Criteria (5 points in total):

- Uploaded `Point.h`, `Square.h` and `main.cpp` three files with no compilation errors: 1 point
- The cpp file calls header file and declares the given functions: 2 point
- The result is correct: 2 point

<br/>

## 3. Examples
### Example1 (Red font for input, blue font for output):
![image](https://github.com/chyh001228/images/blob/main/w7q1.png)

**Input:**

```
5
S1 1 2 3
S2 -2 -5 2
S3 15 20 5
S4 100 -10 10
S5 40 -30 4
```

**Output:**

```

Squares in increasing order of area
S2(-2, -5) side=2, area=4
S1(1, 2) side=3, area=9
S5(40, -30) side=4, area=16
S3(15, 20) side=5, area=25
S4(100, -10) side=10, area=100

Squares in increasing order of max x-coordinate
S2(0, -5) side=2, area=4
S1(4, 2) side=3, area=9
S3(20, 20) side=5, area=25
S5(44, -30) side=4, area=16
S4(110, -10) side=10, area=100

Squares in increasing order of max y-coordinate
S5(40, -26) side=4, area=16
S2(-2, -3) side=2, area=4
S4(100, 0) side=10, area=100
S1(1, 5) side=3, area=9
S3(15, 25) side=5, area=25
```

**Actual results:**  
![image](https://github.com/chyh001228/images/blob/main/w7q1_c.png)

<br/>


(The deadline is 00:00a.m. on October 19, 2025. This assignment will not be graded, but it will be related to the mid-term exam questions. Hope students can review well and achieve good results.)

<img src="https://cdn.imweb.me/upload/S201906178853c3e170808/c5d876d707352.jpg" width=30% align=center />
