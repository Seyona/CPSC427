#include "TerribleBalloon.h"

TerribleBalloon::TerribleBalloon(sizeofScreenBuffer myScreenBufferSize, location myLoc, int iHowLongBeforeFall, SPEED spd, DIRECTION dir):Balloon(myScreenBufferSize, myLoc, iHowLongBeforeFall, spd, dir) {
	this->iHowLongBeforeFall = iHowLongBeforeFall;
	this->balloonState = IS_BALLOON;
}

TerribleBalloon::~TerribleBalloon(void) {

}

void TerribleBalloon::setBalloonState(BALLOON_STATE state) {
	this->balloonState = state;
}

bool TerribleBalloon::draw(std::vector<std::string>& myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	

	bool bDeleteMe = false;

	if(this->balloonState == IS_BEE) {
		dir = static_cast<DIRECTION>(rand() % 5);
		wingsAreFlapping = !wingsAreFlapping;
		switch(dir) {
			case LEFT:
				if ( myLoc.x - spd < 0)
				{
					bDeleteMe = true;
					break;
				}
				else
				{
					myLoc.x = myLoc.x - spd;
					myScreenVector[myLoc.y].replace(myLoc.x, BEE_WIDTH, "  () ");

					if(this->wingsAreFlapping) {
						myScreenVector[myLoc.y].replace(myLoc.x, BEE_WIDTH, " ()) ");
					}
				
					myScreenVector[myLoc.y + 1].replace(myLoc.x, BEE_WIDTH, "%000-");
					myScreenVector[myLoc.y + 2].replace(myLoc.x, BEE_WIDTH, "     ");
					break;
				}

			case RIGHT:
				if (myLoc.x + spd + BEE_WIDTH > DEFAULT_WIDTH)
				{

				}
				else
				{
					myScreenVector[myLoc.y].replace(myLoc.x, BEE_WIDTH, " ()  ");

					if (this->wingsAreFlapping) {
						myScreenVector[myLoc.y].replace(myLoc.x, BEE_WIDTH, " (()");
					}

					myScreenVector[myLoc.y + 1].replace(myLoc.x, BEE_WIDTH, "-000%");
					myScreenVector[myLoc.y + 2].replace(myLoc.x, BEE_WIDTH, "     ");
					break;
				}
				

			case UP:
				if (myLoc.y - spd < 0)
				{

				}
				else
				{
					myLoc.y = myLoc.y - spd;
					myScreenVector[myLoc.y].replace(myLoc.x, BEE_WIDTH, " %   ");
					myScreenVector[myLoc.y + 1].replace(myLoc.x, BEE_WIDTH, "=0=  ");
					myScreenVector[myLoc.y + 2].replace(myLoc.x, BEE_WIDTH, " |  ");
					break;
				}
				

			case DOWN:
				if (myLoc.y + spd +5 > DEFAULT_HEIGHT)
				{

				}
				else
				{
					myLoc.y = myLoc.y + spd;
					myScreenVector[myLoc.y].replace(myLoc.x, BEE_WIDTH, " |   ");
					myScreenVector[myLoc.y + 1].replace(myLoc.x, BEE_WIDTH, "=0=  ");
					myScreenVector[myLoc.y + 2].replace(myLoc.x, BEE_WIDTH, " %   ");
					break;
				}
				

		}
	} else {

		switch (col) {
		case NO:
			if (iHowLongBeforeFall <= 0 && iTimeBetweenMovements == 0)
			{
				myLoc.y = myLoc.y + spd;
				iTimeBetweenMovements++;
			}
			else
			{

				iHowLongBeforeFall--;
				iTimeBetweenMovements = 0;
			}

			myScreenVector[myLoc.y].replace(myLoc.x, BALLOON_WIDTH, "  ___  ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, BALLOON_WIDTH, " //\\ \\ ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, BALLOON_WIDTH, "| \\/  |");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, BALLOON_WIDTH, " \\   / ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH, "  \\ /  ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, BALLOON_WIDTH, "   |   ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, BALLOON_WIDTH, "   |   ");

			if (myLoc.y + BALLOON_HEIGHT >= myScreenBufferSize.y) {
				bDeleteMe = true;
			}

			break;

		case CLOBBERED:

			myScreenVector[myLoc.y].replace(myLoc.x, BALLOON_WIDTH, "   *   ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, BALLOON_WIDTH, " *   * ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, BALLOON_WIDTH, "* * * *");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, BALLOON_WIDTH, "*BOOM *");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH, "* * * *");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, BALLOON_WIDTH, " *   * ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, BALLOON_WIDTH, "   *   ");

			// Turn into bee. This will only matter if balloon is Terrible Balloon
			this->balloonState = IS_BEE;
			bDeleteMe = false;

			break;


		case COSMO_POPPED:

			myScreenVector[myLoc.y].replace(myLoc.x, BALLOON_WIDTH, "       ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, BALLOON_WIDTH, "    |  ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, BALLOON_WIDTH, " - pop-");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH, "  /   \\");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, BALLOON_WIDTH, "    |  ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, BALLOON_WIDTH, "       ");

			// Turn into bee. This method is called from inherited class Terrible Balloon
			// therefore, action applies to all classes of type Balloon, but will only have
			// any visible output on TerribleBalloon objects
			this->balloonState = IS_BEE;
			bDeleteMe = false;

			break;

		}
	}

	return bDeleteMe;
}