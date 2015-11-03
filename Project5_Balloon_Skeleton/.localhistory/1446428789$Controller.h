#pragma once
#include <vector>
#include "constants.h"
#include "person.h"
#include "balloon.h"
#include "scorekeeper.h"
#include "instructions.h"

class Controller
{
public:
	Controller(int width, int height, SPEED speed=MEDIUM);
	~Controller(void);

	//render the scene
	void draw();
	void createBalloon();

	//how fast is the game?
	inline void setSpeed(SPEED speed){mSpeed = speed;};

	//current state intro or run
	inline void setControllerState(CONTROLLER_STATE state){mControllerState = state;};

	COLLISION hasCollidedWithCosmo(Balloon pBalloon);
	inline void changeCosmoDirection(DIRECTION dir){cosmo.setDirection(dir);};
private:
	//reset it all
	void initialize();

	//fills screen buffer with blanks
	void clearScreen();

	//draw scores if needed
	void renderScoresToScreenbuffer();
	
	SPEED mSpeed;		//game speed
	int iTimeBetweenBalloonCreation;
	sizeofScreenBuffer myScreenBufferSize;	//width and height of consolewindow

	//holds entire consolewindow screen, 
	//usually 80 chars wide by 24 lines long
	std::vector<std::string> myScreenVector;

	//all of our balloons
	std::vector<Balloon> myBalloons;

	//cosmo the person
	Person cosmo;

	//for writing instructions
	Instructions myInstructions;

	//max distance between center of squares for a collision to have occured
	//its corner of one object bounding box touching corner of another
	double mCollisionDistance;

	ScoreKeeper scorekeeper;
	CONTROLLER_STATE mControllerState;
};

