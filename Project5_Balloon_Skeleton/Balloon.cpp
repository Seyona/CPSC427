#include "Balloon.h"
#include <iostream>
Balloon::Balloon(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc,spd, dir)
{
	this->iHowLongBeforeFall = iHowLongBeforeFall;
}

Balloon::~Balloon(void)
{
}

//returns true if its time to delete this balloon
bool Balloon::draw(std::vector<std::string>& myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	

	bool bDeleteMe = false;
	
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

	case BALLOON_CLOBBERED_COSMO:

		myScreenVector[myLoc.y].replace(myLoc.x, BALLOON_WIDTH, "   *   ");
		myScreenVector[myLoc.y + 1].replace(myLoc.x, BALLOON_WIDTH, " *   * ");
		myScreenVector[myLoc.y + 2].replace(myLoc.x, BALLOON_WIDTH, "* * * *");
		myScreenVector[myLoc.y + 3].replace(myLoc.x, BALLOON_WIDTH, "*BOOM *");
		myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH, "* * * *");
		myScreenVector[myLoc.y + 5].replace(myLoc.x, BALLOON_WIDTH, " *   * ");
		myScreenVector[myLoc.y + 6].replace(myLoc.x, BALLOON_WIDTH, "   *   ");

		bDeleteMe = true;

		break;
	case COSMO_POPPED:

		myScreenVector[myLoc.y].replace(myLoc.x, BALLOON_WIDTH, "       ");
		myScreenVector[myLoc.y + 1].replace(myLoc.x, BALLOON_WIDTH, "    |  ");
		myScreenVector[myLoc.y + 3].replace(myLoc.x, BALLOON_WIDTH, " - pop-");
		myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH, "  /   \\");
		myScreenVector[myLoc.y + 5].replace(myLoc.x, BALLOON_WIDTH, "    |  ");
		myScreenVector[myLoc.y + 6].replace(myLoc.x, BALLOON_WIDTH, "       ");

		bDeleteMe = true;

		break;

		/*case COSMO_POPPED:
		"       ");
		"    |  ");
		"  \\   /");
		" - pop-");
		"  /   \\");
		"    |  ");
		"       ");
		bDeleteMe = true;
		break;


		"   *   ");
		" *   * ");
		"* * * *");
		"*BOOM *");
		"* * * *");
		" *   * ");
		"   *   ");




		"  ___  ");
		" //\\ \\ ");
		"| \\/  |");
		" \\   / ");
		"  \\ /  ");
		"   |   ");
		"   |   ");

		}*/
	}

	return bDeleteMe;
}
