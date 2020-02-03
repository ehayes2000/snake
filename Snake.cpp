//
// Created by eqhay on 4/30/2019.
//

#include "Snake.h"
#include "position.h"
#include <iostream>

using namespace std;

//default constructor that initializes the snake position in the middle of the grid
Snake::Snake(){
    position tempPos;
    tempPos.x = 10;
    tempPos.y = 10;
    _bodyPieces.push_back(tempPos);
};

//getter function for the snake position vector
vector <position> Snake::getPosition(){
    return _bodyPieces;
}

//function handles the movement of the snake by increasing/decreasing its position in the x-y plane based on the direction it is going
//the if-else statements in each case prevent the user from creating a bug when they press the opposite key of the direction they are going
void Snake::moveSnake(){
    position tempPos;
            switch (_direction){
        case 'u':
            if (_prevDirection != 'd') {
                tempPos.x = _bodyPieces.back().x;
                tempPos.y = _bodyPieces.back().y + 1;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'u';
            }
            else {
                tempPos.x = _bodyPieces.back().x;
                tempPos.y = _bodyPieces.back().y - 1;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'd';
            }
            break;
        case 'd':
            if (_prevDirection != 'u') {
                tempPos.x = _bodyPieces.back().x;
                tempPos.y = _bodyPieces.back().y - 1;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'd';
            }
            else {
                    tempPos.x = _bodyPieces.back().x;
                    tempPos.y = _bodyPieces.back().y + 1;
                    _bodyPieces.erase(_bodyPieces.begin());
                    _bodyPieces.push_back(tempPos);
                    _prevDirection = 'u';
            };
            break;
        case 'l':
            if (_prevDirection != 'r') {
                tempPos.x = _bodyPieces.back().x - 1;
                tempPos.y = _bodyPieces.back().y;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'l';
            }
            else {
                tempPos.x = _bodyPieces.back().x + 1;
                tempPos.y = _bodyPieces.back().y;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'r';
            }
            break;
                case 'r':
            if (_prevDirection != 'l') {
                tempPos.x = _bodyPieces.back().x + 1;
                tempPos.y = _bodyPieces.back().y;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'r';
            }
            else {
                tempPos.x = _bodyPieces.back().x - 1;
                tempPos.y = _bodyPieces.back().y;
                _bodyPieces.erase(_bodyPieces.begin());
                _bodyPieces.push_back(tempPos);
                _prevDirection = 'l';
            }
            break;
    }
}

//member function that interprets key presses
void Snake::setDirection(int keyCode){
    switch (keyCode){
        case 74: // 22 = W
            _direction = 'u'; //go up
            break;
        case 71: //0 = A
            _direction = 'l'; //go left
            break;
        case 73: // 18 = S
            _direction = 'd'; //go down
            break;
        case 72: //3 = D2
            _direction = 'r';
            break;
    }
}

//member function for interpreting when the snake hits walls
bool Snake::detectCollision(){
    for (int i = 0; i < _bodyPieces.size() - 1; i++){
        if (_bodyPieces.back().x == _bodyPieces.at(i).x && _bodyPieces.back().y == _bodyPieces.at(i).y){
            return true;
        }
    }
    for (int i = 0; i < _bodyPieces.size(); i++) {
        if (_bodyPieces.at(i).x < -1 || _bodyPieces.at(i).x > 20) {
            return true;
        }
        if (_bodyPieces.at(i).y < -1 || _bodyPieces.at(i).y > 20) {
            return true;
        }
    }
    return false;
}

//member function for interpreting when the snake hits food
bool Snake::detectFoodCollision(position foodPos){
    if (_bodyPieces.back().x == foodPos.x && _bodyPieces.back().y == foodPos.y){
        return true;
    }
    return false;
}

//member function for growing the snake when it hits food
void Snake::growSnake(){
    _bodyPieces.insert(_bodyPieces.begin(), _bodyPieces.at(0));
}

