#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include "Anvil.h"
#include "Controller.h"
#include "balloon.h"
#include "TerribleBalloon.h"
#include "ScoreKeeper.h"

Controller::Controller(int width, int height, SPEED speed) :myScreenBufferSize(width, height), mSpeed(speed), iTimeBetweenBalloonCreation(QUANTUM_WAIT_TIME + 2 * speed), i_time_between_anvil_creation(ANVIL_WAIT_TIME + 2 * speed), cosmo(myScreenBufferSize, location(myScreenBufferSize.x / 2, myScreenBufferSize.y - PERSON_HEIGHT), speed), myInstructions(myScreenBufferSize, location(myScreenBufferSize.x / 2, myScreenBufferSize.y - PERSON_HEIGHT), speed), mControllerState(SHOW_INTRO)
{	
	initialize();

	//max distance between center of squares for a collision to have occured
	//its corner of one object bounding box touching corner of another
	double distPersonSquare	 = sqrt(PERSON_WIDTH/2*PERSON_WIDTH/2 + PERSON_HEIGHT/2*PERSON_HEIGHT/2);
	double distBalloonSquare = sqrt(BALLOON_WIDTH/2*BALLOON_WIDTH/2 + BALLOON_HEIGHT/2*BALLOON_HEIGHT/2);
	mCollisionDistance		 = distPersonSquare + distBalloonSquare - REQUIRED_OVERLAP;

	/* initialize random seed: */
	srand ((unsigned int)time(NULL));

	//lets set up the screen buffer with blanks
	std::string myString;
	myString.resize(width-SPACE_FOR_CRLF,' ');
	for (int i = 0; i < height; i ++) {
		myScreenVector.push_back(myString);
	}
}							 


void Controller::clearScreen(){
	std::string myString;
	myString.resize(myScreenBufferSize.x-SPACE_FOR_CRLF,' ');
	for (int i = 0; i < myScreenBufferSize.y; i ++) {
		myScreenVector[i]=myString;
	}
}

void Controller::initialize(){
	//reset scores
	scorekeeper.resetScores();

	//TODO clear polymorphic vector that tracks balloons terrible balloons and anvils
	myScreenVector.clear();

	//reset cosmo to middle of screen, standing still
	cosmo.setLocation(location(myScreenBufferSize.x/2, myScreenBufferSize.y-PERSON_HEIGHT));
	cosmo.setDirection(NO_DIR);
	terrible = false;
}

void Controller::set_terrible()
{
	terrible = !terrible;
}

void Controller::draw(){
	clearScreen();

	switch(mControllerState){
	case RESET:
		initialize();
		mControllerState=RUN;
		break;

	case SHOW_INTRO:
		myInstructions.draw(myScreenVector);
		break;

	case EXIT:
		std::exit(0);
		break;

	case RUN:
		//create a balloon if appropriate
		if (!terrible)
		{
			createBalloon();
		}
		else
		{
			create_terrible_balloons();
		}
		create_anvils();

		//render cosmo to screenbuffer
		cosmo.draw(myScreenVector);		


		//render balloons to screenbuffer
		std::vector<std::unique_ptr<Moveable>>::iterator myIter = my_movable_objects.begin();
		
		while ( myIter != my_movable_objects.end()){
			//collisions
			COLLISION col = hasCollidedWithCosmo(*(*myIter));
			if (col == COSMO_POPPED || col == BALLOON_CLOBBERED_COSMO || col == NO || col == CLOBBERED)
				(*(*myIter)).setCollidedState(col);		

			if ((*myIter) -> draw(myScreenVector))
				myIter = my_movable_objects.erase(myIter);
			else
				++myIter;
		}
		//show score if keeping
		renderScoresToScreenbuffer();
		break;

	
	}

	//output the screen buffer
	for (int i = 0; i < myScreenBufferSize.y; i ++) {
		std::cout << myScreenVector[i]<<std::endl;
	}
}

void Controller::renderScoresToScreenbuffer(){
	scorekeeper.getDisplayString(myScreenVector[0]);
}

void Controller::create_terrible_balloons()
{
	if (--iTimeBetweenBalloonCreation != 0)
		return;
	iTimeBetweenBalloonCreation = QUANTUM_WAIT_TIME + QUANTUM_WAIT_TIME*(FAST - mSpeed);		//if set to fast last term drops to 0 then balloons are created quickly
	
	int ilocx = rand() % (myScreenBufferSize.x - BALLOON_WIDTH);
	int ilocy = rand() % BALLOON_APPEAR_BAND_SIZE;	//anywhere withen first 5 lines
	location myLoc(ilocx, ilocy);

	//HOW LONG BEFORE IT FALLS
	int iHowLongBeforeFall = MIN_BALLOON_HOVER_TIME + ((FAST - mSpeed)*QUANTUM_WAIT_TIME);

	//SPEED OF FALL
	SPEED iBalloonSpeed = (SPEED)((rand() % mSpeed) + 1);

	my_movable_objects.push_back(std::unique_ptr<Moveable>(dynamic_cast<Moveable*>(new TerribleBalloon(myScreenBufferSize, myLoc, iHowLongBeforeFall, iBalloonSpeed))));

}
void Controller::create_anvils()
{
	if (--i_time_between_anvil_creation != 0)
		return;
	i_time_between_anvil_creation = ANVIL_WAIT_TIME + ANVIL_WAIT_TIME*(FAST - mSpeed);

	int i_loc_x = rand()%(myScreenBufferSize.x - BALLOON_WIDTH);
	int i_loc_y = rand()%BALLOON_APPEAR_BAND_SIZE;
	location my_loc(i_loc_x, i_loc_y);

	SPEED i_anvil_speed = (SPEED)((rand() % mSpeed) +1 );
	
	my_movable_objects.push_back(std::unique_ptr<Moveable>(new Anvil(myScreenBufferSize, my_loc, i_anvil_speed)));
	

}
void Controller::createBalloon(){
	//BALLOON CREATION RATE based on difficulty
	if (--iTimeBetweenBalloonCreation !=0)
		return;
	iTimeBetweenBalloonCreation = QUANTUM_WAIT_TIME + QUANTUM_WAIT_TIME*(FAST-mSpeed);		//if set to fast last term drops to 0 then balloons are created quickly

	//LOCATION  number between 0 and max balloon size for location
	int ilocx = rand()%(myScreenBufferSize.x -BALLOON_WIDTH);
	int ilocy = rand()%BALLOON_APPEAR_BAND_SIZE;	//anywhere withen first 5 lines
	location myLoc(ilocx, ilocy);

	//HOW LONG BEFORE IT FALLS
	int iHowLongBeforeFall = MIN_BALLOON_HOVER_TIME + ((FAST-mSpeed)*QUANTUM_WAIT_TIME);

	//SPEED OF FALL
	SPEED iBalloonSpeed = (SPEED)((rand()%mSpeed) +1);	//make sure this falls between SLOW=1 and FAST=4

 	//TODO add it to a single vector that tracks balloons terrible balloons and anvils
	
	my_movable_objects.push_back(std::unique_ptr<Moveable>(new Balloon (myScreenBufferSize, myLoc, iHowLongBeforeFall, iBalloonSpeed)));
}

COLLISION Controller::hasCollidedWithCosmo(Moveable &pBalloon){
	//get the x separation 
	int x = cosmo.getX() - pBalloon.getX();
	int y = cosmo.getY() - pBalloon.getY();
	double distance = sqrt(x*x + y*y);
	if (distance <= mCollisionDistance){
		//nows the time to see where cosmo was hit
		//-on head the balloon wins
		//-on side with needle(s) cosmo wins
		DIRECTION dir = cosmo.getDir();

		if (dir == UP || (x>0 && dir==LEFT) || (x<0 && dir==RIGHT)){
			scorekeeper.incScoreCosmo();
			return COSMO_POPPED;
		}

		//balloon hit cosmo on head or back or cosmo was standing with arms on hips 
		scorekeeper.incScoreBalloon();
		return CLOBBERED;
	}
	else
		return NO;
}

Controller::~Controller(void)
{
}
