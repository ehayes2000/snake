#define SFML_STATIC
#include <windows.h>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <random>
#include "grid.h"
#include "Snake.h"

using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

//position struct type function to randomize the x and y coordinates of an apple
position generateFood(){
    srand(time(NULL));
    position food;
    food.x = (rand() % 20);
    food.y = (rand() % 20);
    return food;
}

int main() {
    const int WINDOW_SIZE = 920;
    const int TICK_RATE = 90;
    Snake player;
    Grid board;
    RenderWindow window(VideoMode(WINDOW_SIZE,WINDOW_SIZE),"Snake");
    //initialize food at same place at start of every game; position is then randomized later
    position food;
    food.x = 15;
    food.y = 10;

    while (window.isOpen()){
        //slows game down to a playable speed
        Sleep(TICK_RATE);
        window.clear(Color::White);

        board.displayGrid(window);
        board.displaySnake(player.getPosition(), window);
        board.displayFood(food, window);

        player.moveSnake();

        window.display();
        //collision detection is after window.display() to avoid visual bug of snake dying before collision
        if (player.detectCollision()) {
            cout << "YOU LOSE" << endl;
            window.close();
        }
        //food collision detection
        if (player.detectFoodCollision(food)){
            player.growSnake();
            food = generateFood();
        }

        Event event;
        while(window.pollEvent(event)){
            if( event.type == Event::Closed ) { // if event type is a closed event
                window.close();                 // then close our window
            }
            //checking for user input in the form of arrow key presses
            if (event.type == Event::KeyPressed){
                player.setDirection(event.key.code);
            }
        }

    }
    return EXIT_SUCCESS;                        // report our program exited successfully
}