#pragma once 
#include "Balloon.h"

class TerribleBalloon : 
	public Balloon  {

	public:
		TerribleBalloon(sizeofScreenBuffer myScreenBufferSize, location myLoc, int iHowLongBeforeFall, SPEED spd = NO_SPD, DIRECTION dir = DOWN);
		virtual ~TerribleBalloon(void);

		void setBalloonState(BALLOON_STATE state);
		virtual bool draw(std::vector<std::string> &myScreenVector);
		

	private:
		int iHowLongBeforeFall;
		bool wingsAreFlapping;
		BALLOON_STATE balloonState;
};