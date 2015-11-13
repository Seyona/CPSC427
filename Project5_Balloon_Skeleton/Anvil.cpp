#include "Anvil.h"

Anvil::Anvil(sizeofScreenBuffer myScreenBufferSize,location myLoc,int iHowLongBeforeFall, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc,spd, dir)
{

}

Anvil::~Anvil(void)
{
}

bool Anvil::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
	bool bDeleteMe = false;

	switch(this -> col) {
 

		case NO:
			if (myLoc.y + BALLOON_HEIGHT + 2 >= myScreenBufferSize.y)
			{
				bDeleteMe = true;
				break;
			}
			myLoc.y = myLoc.y + spd;

			myScreenVector[myLoc.y].replace(myLoc.x,BALLOON_WIDTH,		"     ___    ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x,BALLOON_WIDTH,	"    /   \\   ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x,BALLOON_WIDTH,	"    |O O|   ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x,BALLOON_WIDTH,	"    |   |   ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH,"    \\___/   ");
			break;
		
		case ANVIL_CLOBBERED:
			myScreenVector[myLoc.y].replace(myLoc.x, BALLOON_WIDTH, "            ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, BALLOON_WIDTH, "            ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, BALLOON_WIDTH, "   GET GUD  ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, BALLOON_WIDTH, "            ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, BALLOON_WIDTH, "            ");
			bDeleteMe = true;
			break;
	}


	return bDeleteMe; 
}