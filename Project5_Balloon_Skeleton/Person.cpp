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
		if (bLegChangePosition){
			myScreenVector[14].replace(1,14,	"   \\\\\\\\|//// ");
			myScreenVector[15].replace(1,14,	"    |~ ////  ");
			myScreenVector[16].replace(1,14,	"    |O  //   ");
			myScreenVector[17].replace(1,14,	"   <    |    ");
			myScreenVector[18].replace(1,14,	"    |_/ |    ");
			myScreenVector[19].replace(1,14,	"--o |__/    ");
			myScreenVector[20].replace(1,14,	"   \\__|      ");
			myScreenVector[21].replace(1,14,	"      |      ");
			myScreenVector[22].replace(1,14,	"     /|      ");
			myScreenVector[23].replace(1,14,    "   \\/_|      ");
			break;
		}
		else
		{
			myScreenVector[14].replace(1, 14,	"   \\\\\\\\|//// ");
			myScreenVector[15].replace(1, 14,	"    |~ ////  ");
			myScreenVector[16].replace(1, 14,	"    |O  //   ");
			myScreenVector[17].replace(1, 14,	"   <    |    ");
			myScreenVector[18].replace(1, 14,	"    |_/ |    ");
			myScreenVector[19].replace(1, 14,	"--o |__/    ");
			myScreenVector[20].replace(1, 14,	"   \\__|      ");
			myScreenVector[21].replace(1, 14,	"      |      ");
			myScreenVector[22].replace(1, 14,	"      |      ");
			myScreenVector[23].replace(1, 14,	"    \\||      ");
			break;
		}

	case RIGHT:
		if (bLegChangePosition){
			myScreenVector[14].replace(1, 14,	" \\\\\\\\|////   ");
			myScreenVector[15].replace(1, 14,	"  \\\\\\\\ ~|    ");
			myScreenVector[16].replace(1, 14,	"   \\\\  O|    ");
			myScreenVector[17].replace(1, 14,	"    |    >   ");
			myScreenVector[18].replace(1, 14,	"    | \\_|    ");
			myScreenVector[19].replace(1, 14,	"     \\__| o--");
			myScreenVector[20].replace(1, 14,	"      |__/   ");
			myScreenVector[21].replace(1, 14,	"      |      ");
			myScreenVector[22].replace(1, 14,	"      |\\     ");
			myScreenVector[23].replace(1, 14,	"      |_\\/    ");
			break;
		}
		else
		{
			myScreenVector[14].replace(1, 14,	" \\\\\\\\|////   ");
			myScreenVector[15].replace(1, 14,	"  \\\\\\\\ ~|    ");
			myScreenVector[16].replace(1, 14,	"   \\\\  O|    ");
			myScreenVector[17].replace(1, 14,	"    |    >   ");
			myScreenVector[18].replace(1, 14,	"    | \\_|    ");
			myScreenVector[19].replace(1, 14,	"     \\__| o--");
			myScreenVector[20].replace(1, 14,	"      |__/   ");
			myScreenVector[21].replace(1, 14,	"      |      ");
			myScreenVector[22].replace(1, 14,	"      |     ");
			myScreenVector[23].replace(1, 14,	"      ||/    ");
			break;
		}
	case UP:
			myScreenVector[14].replace(1,14,	" \\\\\\\\\\|///// ");
			myScreenVector[15].replace(1,14,	"  \\\\|\\ /|//  ");
			myScreenVector[16].replace(1,14,	"   \\|O O|/   ");
			myScreenVector[17].replace(1,14,	"    | ^ |    ");
			myScreenVector[18].replace(1,14,	" \\  | - |  / ");
			myScreenVector[19].replace(1,14,	"  o |___| o  ");
			myScreenVector[20].replace(1,14,	"   \\__|__/   ");
			myScreenVector[21].replace(1,14,	"      |     ");
			myScreenVector[22].replace(1,14,	"      |     ");
			myScreenVector[23].replace(1,14,	"     _|_     ");
			break;

	case NO_DIR:
			myScreenVector[14].replace(1, 14,	" \\\\\\\\\\|///// ");
			myScreenVector[15].replace(1, 14,	"  \\\\|~ ~|//  ");
			myScreenVector[16].replace(1, 14,	"   \\|O O|/   ");
			myScreenVector[17].replace(1, 14,	"    | ^ |    ");
			myScreenVector[18].replace(1, 14,	"    | v |    ");
			myScreenVector[19].replace(1, 14,	"    |___|    ");
			myScreenVector[20].replace(1, 14,	"    __|__    ");
			myScreenVector[21].replace(1, 14,	"    \\ | /    ");
			myScreenVector[22].replace(1, 14,	"     0|0     ");
			myScreenVector[23].replace(1, 14,	"     _|_     ");
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
