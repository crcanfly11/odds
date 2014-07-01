//
//  oddscalulate.h
//  odds
//
//  Created by 金成日 on 14-7-1.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#ifndef __odds__oddscalulate__
#define __odds__oddscalulate__

#include <iostream>

#include <boost/bind.hpp>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class fixtures_base_odds
{
	enum team_odd_enum { home_team_win = 0, shake_hands = 1, away_team_win = 2 };
    
	double team_odds_[3];
    
	char home_team_[30];
	char away_team_[30];
public:
	fixtures_base_odds(double win_odds, double shake_hands_odds, double lose_odds, const char* home_team_name, const char* away_team_name)
	{
		team_odds_[home_team_win] = win_odds;
		team_odds_[shake_hands] = shake_hands_odds;
		team_odds_[away_team_win] = lose_odds;
        
		std::strcpy(home_team_, home_team_name);
		std::strcpy(away_team_, away_team_name);
	};
    
	double get_win_odds() const { return team_odds_[home_team_win]; }
	double get_shake_hands_odds() const { return team_odds_[shake_hands]; }
	double get_lose_odds() const { return team_odds_[away_team_win]; }
};

class forecas_result
{
	float odds_;
	unsigned short multiple_;
	float yield_;			     //Unit of Measure %
	char result_msg_[50];
    
public:
	forecas_result(float odds, const char* result_msg) : odds_(odds)
	{
		std::strcpy(result_msg_, result_msg);
		yield_ = (odds - 1)*100;
	}
    
	void set_result_multiple(unsigned short multiple) { multiple_ = multiple; }
    
	unsigned short get_result_multiple() const { return multiple_; }
	float get_result_yield() const { return yield_; }
	const char* get_result_msg() const { return result_msg_; }
};

class organizer
{
	double htwin_, sh_, atwin_;
	char htname_[20], atname_[20], tmp_[100];
    
	typedef vector<fixtures_base_odds> base_odds_vector;
	base_odds_vector base_odds_;
    
	typedef map<unsigned short, forecas_result> forecas_result_map;
	forecas_result_map forecas_results_;
    
public:
    organizer() : htwin_(0), sh_(0), atwin_(0)
    {
        memset(htname_, 0, 20);
        memset(atname_, 0, 20);
        
        init();
    };
    
private:
    void init();
    void forecas_calculate(base_odds_vector::iterator begin, base_odds_vector::iterator end);
    void set_forecas_result_map(int frontodd, int value);
};

#endif /* defined(__odds__oddscalulate__) */
