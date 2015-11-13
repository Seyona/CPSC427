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

		if (myLoc.y - this -> spd <= 0) {
			bDeleteMe = true;
		}

		case NO:
			myScreenVector[myLoc.y].replace(myLoc.x,14,		"     ___    ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x,14,	"    /   \   ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x,14,	"    |O O|   ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x,14,	"    |   |   ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14,"    \___/   ");
			break;
		
		case BALLOON_CLOBBERED_COSMO:
			myScreenVector[myLoc.y].replace(myLoc.x,14,		"            ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x,14,	"            ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x,14,	"   GET GUD  ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x,14,	"            ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14,"            ");
			bDeleteMe = true;
			break;
	}


	return bDeleteMe; 
}