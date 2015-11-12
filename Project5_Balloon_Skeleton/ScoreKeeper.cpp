#include "ScoreKeeper.h"

const char COSMO_SCORE_PREFIX[]		= "COSMO =";
const int  LEN_COSMO_SCORE_PREFIX	= 7;
const char BALLOON_SCORE_PREFIX[]	= "BALLOONS ="; 
const int  LEN_BALLOON_SCORE_PREFIX	= 10;
const int  SPACES_FOR_SCORE			= 6;

ScoreKeeper::ScoreKeeper(void)
{
	resetScores();
}

ScoreKeeper::~ScoreKeeper(void)
{
}

bool ScoreKeeper::getDisplayString(std::string &scoreString){
	//enough room  

	if ((scoreString.length() - LEN_COSMO_SCORE_PREFIX - LEN_BALLOON_SCORE_PREFIX - SPACES_FOR_SCORE - SPACES_FOR_SCORE)<0)

		return false;


	char buff[SPACES_FOR_SCORE];

	int len = sprintf(buff, "%d", scoreCosmo);

	scoreString.replace(0, LEN_COSMO_SCORE_PREFIX, COSMO_SCORE_PREFIX);

	scoreString.replace(LEN_COSMO_SCORE_PREFIX + 1, len, buff);


	len = sprintf(buff, "%d", scoreBalloon);

	int whereBalloonScoreStarts = scoreString.length() - LEN_BALLOON_SCORE_PREFIX - SPACES_FOR_SCORE;

	scoreString.replace(whereBalloonScoreStarts, LEN_BALLOON_SCORE_PREFIX, BALLOON_SCORE_PREFIX);

	scoreString.replace(whereBalloonScoreStarts + LEN_BALLOON_SCORE_PREFIX + 1, len, buff);

	return true;
}
