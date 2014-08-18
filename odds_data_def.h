//
//  odds_data_def.h
//  odds
//
//  Created by 金成日 on 14-8-18.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#ifndef __odds__odds_data_def__
#define __odds__odds_data_def__

#include <boost/bind.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <iostream>

//-----------------------------------------------------------------------

using namespace std;

enum unit_price { lottery = 2, max_total_cost = 500 };
enum team_odd_type { max_odds_type = 3 };
enum play_type { win_draw_lost = 3 };
enum result_type { HWHW = 0x0001, HWSH = 0x0002, HWAW = 0x0004, SHHW = 0x0008,
                   SHSH = 0x0010, SHAW = 0x0020, AWHW = 0x0040, AWSH = 0x0080,
                   AWAW = 0x0100 };
enum play_mode { none_modem, portion_mode, whole_mode, manual_mode };

//-----------------------------------------------------------------------

class base_odds
{
  	enum team_odd_enum { home_team_win = 0, shake_hands = 1, away_team_win = 2 };
    
	double team_odds_[win_draw_lost];
    
	char home_team_[30];
	char away_team_[30];
public:
	base_odds(double win_odds, double shake_hands_odds, double lose_odds, const char* home_team_name, const char* away_team_name);
	
	double operator[] (int index);
	
	const char* get_home_team_name() { return home_team_; }
	const char* get_away_team_name() { return away_team_; }
};

//-----------------------------------------------------------------------

#endif /* defined(__odds__odds_data_def__) */
