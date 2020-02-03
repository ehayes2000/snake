//
// Created by eqhay on 4/30/2019.
//

#ifndef SFML_TEMPLATE_GRID_H
#define SFML_TEMPLATE_GRID_H
#include "Snake.h"
#include "position.h"
#include <string>
using namespace std;

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;

class Grid{
private:
    const int _GRID_SIZE = 46;                  //constant variable that allows user to easily change the size of grid tiles

public:
    const int getGridSize();                    //getter function, not currently used
    void displayGrid(RenderWindow& window);     //member function for displaying the grid, currently not used
    void displaySnake(vector<position> snakePos, RenderWindow& window);     //member function for displaying the snake in our grid
    void displayFood(position food, RenderWindow& window);                  //member function for displaying food in our grid
};
#endif //SFML_TEMPLATE_GRID_H
