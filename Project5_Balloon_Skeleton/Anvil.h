#pragma once
#include "moveable.h"

class Anvil : public Moveable {
	public:
		Anvil(sizeofScreenBuffer myScreenBufferSize, location myLoc, SPEED spd = NO_SPD, DIRECTION dir = DOWN);
		virtual ~Anvil(void);

		//returns true if its time to delete
		virtual bool draw(std::vector<std::string> &myScreenVector);
	private:
		int iHowLongBeforeFall;
};