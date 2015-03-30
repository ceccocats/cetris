/* 
 * File:   Game.cpp
 * Author: cecco
 * 
 * Created on 24 marzo 2015, 17.57
 */

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include "SysGame.h"

SysGame::SysGame() {
}


SysGame::~SysGame() {
}

bool SysGame::load() {
    
    Tetris = new SysTetris();
    return true;
}



void SysGame::update(float dt) {
    
    if(Tetris->gameOver) {
        delete Tetris;
        Tetris = new SysTetris();
    }
    
    Tetris->update(dt);

}

void SysGame::render() {

    Tetris->draw();
}

void SysGame::keypressed(SDL_Event& ev) {
    
    if(ev.key.keysym.sym == SDLK_LEFT)
        Tetris->moveLeft(true);
    if(ev.key.keysym.sym == SDLK_RIGHT)
        Tetris->moveRight(true);
    if(ev.key.keysym.sym == SDLK_DOWN)
        Tetris->addFallSpeed(true);  
    if(ev.key.keysym.sym == SDLK_UP)
        Tetris->rotateBrick(); 
    if(ev.key.keysym.sym == SDLK_SPACE)
        Tetris->fallBrick(); 
}

void SysGame::keyrelased(SDL_Event& ev) {
    
    if(ev.key.keysym.sym == SDLK_LEFT)
        Tetris->moveLeft(false);
    if(ev.key.keysym.sym == SDLK_RIGHT)
        Tetris->moveRight(false);
    if(ev.key.keysym.sym == SDLK_DOWN)
        Tetris->addFallSpeed(false);
}