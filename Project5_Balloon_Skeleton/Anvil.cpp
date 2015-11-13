#include "Anvil.h"

Anvil::Anvil(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc,spd, dir)
{

}

Anvil::~Anvil(void)
{
}

bool Anvil::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	

	bool bDeleteMe = false;

	switch(col) {
 
		case NO:
			if (myLoc.y + ANVIL_HEIGHT +2 >= myScreenBufferSize.y) {
				bDeleteMe = true;
			}
			myLoc.y = myLoc.y + spd;

			myScreenVector[myLoc.y].replace(myLoc.x, ANVIL_WIDTH,	  " ___ ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, ANVIL_WIDTH, "/   \\");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, ANVIL_WIDTH, "|O O|");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, ANVIL_WIDTH, "|   |");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, ANVIL_WIDTH, "\\___/");
			break;
		
		case COSMO_POPPED:
			myScreenVector[myLoc.y].replace(myLoc.x, ANVIL_WIDTH, " ___ ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, ANVIL_WIDTH, "/   \\");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, ANVIL_WIDTH, "|X X|");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, ANVIL_WIDTH, "|   |");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, ANVIL_WIDTH, "\\___/");
			bDeleteMe = true;
			break;

		case CLOBBERED:
			myScreenVector[myLoc.y].replace(myLoc.x, ANVIL_WIDTH,		" ___ ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, ANVIL_WIDTH,	"/   \\");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, ANVIL_WIDTH,	"|X X|");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, ANVIL_WIDTH,	"|   |");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, ANVIL_WIDTH,	"\\___/");
			bDeleteMe = true;
			break;
	}


	return bDeleteMe; 
}