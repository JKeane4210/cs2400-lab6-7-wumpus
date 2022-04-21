#include "cell.h"
#include "hazard.h"
#include "board.h"

Cell::Cell(Board * b, int x, int y) : x{x}, y{y} {
	this->board = b;
	this->x = x;
	this->y = y;
	this->hasPlayer = false;
	this->hasHazard = false;
	this->hasArrow = false;
	this->token = '.';
}

void Cell::insertPlayer(Player * p){
	this->hasPlayer = true;
	this->player = p;
	this->token = 'P';
	this->board->playerX = this->x;
	this->board->playerY = this->y;
}

void Cell::insertHazard(Hazard * h){
	this->hasHazard = true;
	this->hazard = h;
	this->token = h->display();
}

void Cell::leavePlayer(){
	this->hasPlayer = false;
	this->player = nullptr;
	this->token = '.';
}

void Cell::leaveHazard(){
	this->hasHazard = false;
	this->hazard = nullptr;
	this->token = '.';
}

void Cell::insertArrow(){
	this->hasArrow = true;
	this->token = '-';
}

void Cell::grabArrow(){
	this->hasArrow = false;
	this->token = '.';
}

bool Cell::isOccupied(){
	return this->hasArrow || this->hasHazard;
}

char Cell::getToken(){
	return this->token;
}

Hazard * Cell::getHazard() {
	return this->hazard;
}

bool Cell::hasHazard() {
	return this->hasHazard;
}
