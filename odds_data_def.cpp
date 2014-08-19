//
//  odds_data_def.cpp
//  odds
//
//  Created by 金成日 on 14-8-18.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#include "odds_data_def.h"

//-----------------------------------------------------------------------

base_odds::base_odds(double win_odds, double shake_hands_odds, double lose_odds, const char* home_team_name, const char* away_team_name)
{
	team_odds_[home_team_win] = win_odds;
	team_odds_[shake_hands] = shake_hands_odds;
	team_odds_[away_team_win] = lose_odds;
    
	strncpy(home_team_, home_team_name, sizeof(home_team_));
	strncpy(away_team_, away_team_name, sizeof(away_team_));
};

double base_odds::operator[] (int index)
{
	if(index < max_odds_type)
		return team_odds_[index];
	else
		return -1;
};

//-----------------------------------------------------------------------
