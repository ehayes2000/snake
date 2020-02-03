//
// Created by eqhay on 4/30/2019.
//

#include "grid.h"
#include "Snake.h"
#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;

//member function for outputting the grid on the screen, no longer useful but was used to experiment with different visual styles and to bug test
void Grid::displayGrid(RenderWindow& window){
    for (int i = 0; i < window.getSize().x; i+= _GRID_SIZE){
        Vertex verticalLine[] =
                {
                Vertex(Vector2f(i, 0)),
                Vertex(Vector2f(i, window.getSize().x))
                };
        Vertex horizontalLine[] =
                {
                Vertex(Vector2f(0, i)),
                Vertex(Vector2f(window.getSize().y, i))
                };

        window.draw(verticalLine,2, Lines);
        window.draw(horizontalLine,2, Lines);
    }
}

//member function for displaying the snake in our grid
void Grid::displaySnake(vector<position> snakePos, RenderWindow& window){
    RectangleShape bodyPiece;
    for (int i = 0; i < snakePos.size(); i ++ ){
        bodyPiece.setSize(Vector2f(_GRID_SIZE ,_GRID_SIZE));
        bodyPiece.setFillColor(Color::Black);
        bodyPiece.setPosition(Vector2f(snakePos.at(i).x * _GRID_SIZE, snakePos.at(i).y * _GRID_SIZE));
        window.draw(bodyPiece);
    }
}

//member function for displaying pieces of food
void Grid::displayFood(position food, RenderWindow &window) {
    RectangleShape foodShape;
    foodShape.setSize(Vector2f(_GRID_SIZE,_GRID_SIZE ));
    foodShape.setFillColor(Color::Red);
    foodShape.setPosition(food.x * _GRID_SIZE, food.y * _GRID_SIZE);
    window.draw(foodShape);
}

//getter function to access _GRID_SIZE, no longer used but left in program for future modification
const int Grid::getGridSize(){
    return _GRID_SIZE;
}
