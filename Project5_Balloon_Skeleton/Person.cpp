#include "Person.h"


Person::Person(sizeofScreenBuffer myScreenBufferSize,location myLoc, SPEED spd, DIRECTION dir ):Moveable(myScreenBufferSize,myLoc, spd, dir),bLegChangePosition(false)
{

}


Person::~Person(void)
{
}

//always return false since person never deleted
bool Person::draw(std::vector<std::string> &myScreenVector){			//pure virtual, abstract base class, MUST BE DEFINED BY DERIVED CLASSES	
//
bLegChangePosition = !bLegChangePosition;
switch(dir){
	case LEFT:

		if (myLoc.x - spd == 0){

		}
		else{
			myLoc.x = myLoc.x - spd;
		}
		if (bLegChangePosition){
			myScreenVector[myLoc.y].replace(myLoc.x,14,	"   \\\\\\\\|//// ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x,14,	"    |~ ////  ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x,14,	"    |O  //   ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x,14,	"   <    |    ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14, "    |_/ |    ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, 14, "--o |__/    ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, 14, "   \\__|      ");
			myScreenVector[myLoc.y + 7].replace(myLoc.x, 14, "      |      ");
			myScreenVector[myLoc.y + 8].replace(myLoc.x, 14, "     /|      ");
			myScreenVector[myLoc.y + 9].replace(myLoc.x, 14, "   \\/_|      ");
			break;
		}
		else
		{
			myScreenVector[myLoc.y].replace(myLoc.x, 14, "   \\\\\\\\|//// ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, 14, "    |~ ////  ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, 14, "    |O  //   ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, 14, "   <    |    ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14, "    |_/ |    ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, 14, "--o |__/    ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, 14, "   \\__|      ");
			myScreenVector[myLoc.y + 7].replace(myLoc.x, 14, "      |      ");
			myScreenVector[myLoc.y + 8].replace(myLoc.x, 14, "      |      ");
			myScreenVector[myLoc.y + 9].replace(myLoc.x, 14, "    \\||      ");
			break;
		}

	case RIGHT:
		if (myLoc.x + spd + PERSON_WIDTH == DEFAULT_WIDTH)
		{

		}
		else {
			myLoc.x = myLoc.x + spd;
		}

		if (bLegChangePosition){
			myScreenVector[myLoc.y].replace(myLoc.x, 14, " \\\\\\\\|////   ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, 14, "  \\\\\\\\ ~|    ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, 14, "   \\\\  O|    ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, 14, "    |    >   ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14, "    | \\_|    ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, 14, "     \\__| o--");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, 14, "      |__/   ");
			myScreenVector[myLoc.y + 7].replace(myLoc.x, 14, "      |      ");
			myScreenVector[myLoc.y + 8].replace(myLoc.x, 14, "      |\\     ");
			myScreenVector[myLoc.y + 9].replace(myLoc.x, 14, "      |_\\/    ");
			break;
		}
		else
		{
			myScreenVector[myLoc.y].replace(myLoc.x, 14, " \\\\\\\\|////   ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, 14, "  \\\\\\\\ ~|    ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, 14, "   \\\\  O|    ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, 14, "    |    >   ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14, "    | \\_|    ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, 14, "     \\__| o--");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, 14, "      |__/   ");
			myScreenVector[myLoc.y + 7].replace(myLoc.x, 14, "      |      ");
			myScreenVector[myLoc.y + 8].replace(myLoc.x, 14, "      |     ");
			myScreenVector[myLoc.y + 9].replace(myLoc.x, 14, "      ||/    ");
			break;
		}
	case UP:
			myScreenVector[myLoc.y].replace(myLoc.x, 14, " \\\\\\\\\\|///// ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, 14, "  \\\\|\\ /|//  ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, 14, "   \\|O O|/   ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, 14, "    | ^ |    ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14, " \\  | - |  / ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, 14, "  o |___| o  ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, 14, "   \\__|__/   ");
			myScreenVector[myLoc.y + 7].replace(myLoc.x, 14, "      |     ");
			myScreenVector[myLoc.y + 8].replace(myLoc.x, 14, "      |     ");
			myScreenVector[myLoc.y + 9].replace(myLoc.x, 14, "     _|_     ");
			break;

	case NO_DIR:
			myScreenVector[myLoc.y].replace(myLoc.x, 14, " \\\\\\\\\\|///// ");
			myScreenVector[myLoc.y + 1].replace(myLoc.x, 14, "  \\\\|~ ~|//  ");
			myScreenVector[myLoc.y + 2].replace(myLoc.x, 14, "   \\|O O|/   ");
			myScreenVector[myLoc.y + 3].replace(myLoc.x, 14, "    | ^ |    ");
			myScreenVector[myLoc.y + 4].replace(myLoc.x, 14, "    | v |    ");
			myScreenVector[myLoc.y + 5].replace(myLoc.x, 14, "    |___|    ");
			myScreenVector[myLoc.y + 6].replace(myLoc.x, 14, "    __|__    ");
			myScreenVector[myLoc.y + 7].replace(myLoc.x, 14, "    \\ | /    ");
			myScreenVector[myLoc.y + 8].replace(myLoc.x, 14, "     0|0     ");
			myScreenVector[myLoc.y + 9].replace(myLoc.x, 14, "     _|_     ");
			break;
}
//
//		"   \\\\\\\\|//// ");
//		"    |~ ////  ");
//		"    |O  //   ");
//		"   <    |    ");
//		"    |_/ |    ");
//		"--o |__/    ");
//		"   \\__|      ");
//		"      |      ");
//		
//		"     /|      ");
//		"   \\/_|      ");
//
//
//		"      |      ");
//		"    \\||      ");
//
//
//" \\\\\\\\|////   ");
//"  \\\\\\\\ ~|    ");
//"   \\\\  O|    ");
//"    |    >   ");
//"    | \\_|    ");
//"     \\__| o--");
//"      |__/   ");
//"      |      ");
//
//"      |\\     ");
//"      |_\\/    ");
//
//
//
//"      |     ");
//"      ||/    ");
//		}
//
//
//" \\\\\\\\\\|///// ");
//"  \\\\|\\ /|//  ");
//"   \\|O O|/   ");
//"    | ^ |    ");
//" \\  | - |  / ");
//"  o |___| o  ");
//"   \\__|__/   ");
//"      |     ");
//"      |     ");
//"     _|_     ");
//
//
//" \\\\\\\\\\|///// ");
//"  \\\\|~ ~|//  ");
//"   \\|O O|/   ");
//"    | ^ |    ");
//"    | v |    ");
//"    |___|    ");
//"    __|__    ");
//"    \\ | /    ");
//"     0|0     ");
//"     _|_     ");
//
//	}

return false;
}
