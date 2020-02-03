//
// Created by eqhay on 4/30/2019.
//

#ifndef SFML_TEMPLATE_SNAKE_H
#define SFML_TEMPLATE_SNAKE_H
#include <vector>
#include "position.h"
#include "grid.h"
using namespace std;

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;

class Snake{
private:
    vector <position> _bodyPieces;                  //vector for storing the snake pieces
    char _direction = 'r';                          //direction stored as char u = up d = down etc..., initialized to 'r' so that snake starts moving right upon creation
    char _prevDirection = 'r';                      //previous direction used similar to direction variable, allows program to prevent snake from going backwards into itself
public:
    Snake();                                        //default constructor
    vector <position> getPosition();                //getter function for the position of the snake
    void moveSnake();                               //member function for updating the position of the snake
    void setDirection(int keyCode);                 //member function for changing the direction of the snake
    void growSnake();                               //member function for increasing the size of the snake when it collides with a food object

    bool detectCollision();                         //member function for detecting collision with walls or itself
    bool detectFoodCollision(position foodPos);     //member function for detecting if the snake eats the food
};
#endif //eSFML_TEMPLATE_SNAKE_H
