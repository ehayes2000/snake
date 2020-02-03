# snake
The classic arcade game snake coded in C++


![alt text](https://github.com/ehayes2000/snake/blob/master/snake-demo.gif)

**Overview**


This was made as a final project for 261 (programming concepts) in collaberation with another student. The project is composed of two classes, the grid clas and the snake class.

The grid class handles all window all window drawing and takes, a vector containing the location of every piece of the snake. The grid class is also responsible for determining when the snake can and cannot turn to remain within a pre-defined grid. The snake class is responsible for snake movement, position, growth, and collision with walls, iteslf, and food. 

**Snake Movement and Display**

The snake class stores a vector of x,y pairs, these pairs are passed to the grid class and are drawn within the grid as SFML
rectangle objects. With every move of the snake, a new rectangle is drawn and the in the direction the snake is moving and the last rectangle is erased. This method allows the coordinates of the snake to be indipendent of the window or grid size, making resizing the window or grid easy.

**Main Game Loop**

The game loop can be found in the main function and loops until an end condition is met. A fixed tick-rate was used to control the game speed. We found that a tick-rate of 90hz created a challenging yet playable game speed. With every iteration of the game loop the window is cleared, the position of the snake is displayed, the snake class is checked for game ending collision, and collision that would cause growth. If collision with walls or itself is detected the window is closed and "YOU LOSE" is printed to standard output. If collision with food is detected the growSnake() member function is called and another x,y position pair is added to the position vector. 

**Known Bugs and Fixes**

While using a fixed tick-rate works for controlling game speed, it is not ideal as the durration of each frame varies with processor speed. A better solution would be a dynamic tick-rate that measures the duration of each frame and goes to the next frame when a fixed time has passed. 


A vector was used to store x,y position pairs in this version. However, a set may be more fitting as it allows for quick comparison of position which simplifies and speeds up collision detection.


  
