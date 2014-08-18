//
//  odds_position_manager.h
//  odds
//
//  Created by 金成日 on 14-8-18.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#ifndef __odds__odds_position_manager__
#define __odds__odds_position_manager__

#include "odds_data_def.h"

//-----------------------------------------------------------------------

class odds_result
{
	double odds_;
	double probability_;
	char result_msg_[10];
	char team_msg_[64];
    
	unsigned short multiple_;
	double income_;
	double net_income_;
	double yield_;
    double unit_profit_;
    short flag_;
    
public:
	odds_result(double odds, double probability, const char* result_msg);
	odds_result(const odds_result& result);
    
	void set_result_multiple(unsigned short multiple);
	void set_total_cost(double tcost);
	void set_flag(short type) { flag_ |= type; }
	void clear_dynamic_data();
    
	unsigned short get_result_multiple() const { return multiple_; }
	double get_result_odds() const { return odds_; }
	double get_result_probability() const { return probability_; }
	double get_result_yield() const { return yield_; }
	double get_result_income() const { return income_; }
	double get_net_income() const { return net_income_; }
    double get_unit_profit() const { return unit_profit_; }
	const char* get_result_msg() const { return result_msg_; }
	const char* get_team_msg() const { return team_msg_; }
	short get_flag() const { return flag_; }
};

//-----------------------------------------------------------------------

typedef vector<base_odds> base_odds_vector;
typedef map<unsigned int, odds_result> odds_result_map;
typedef pair<unsigned int, odds_result> odds_result_pair;

//-----------------------------------------------------------------------

class odds_position
{
	double total_cost_;
    double unit_profit_;
	int real_size_;
	double winning_probability_;
    
	odds_result_map odds_original_results_;
	odds_result_map odds_results_;
    
public:
	odds_position();
	~odds_position();
	
	odds_result_map* get_original_results_map() { return &odds_original_results_; }
   	odds_result_map* get_result_map() { return &odds_results_; }
    
	void refresh();
	void clear();
    void reset();
	int add_someone_position(unsigned int index);
    
	void set_real_size(int rsize) { real_size_ = rsize; }
	void set_winning_probability(double probability) { winning_probability_ = probability; }
    
	double get_total_cost() { return total_cost_; }
	int get_real_size() const { return real_size_; }
	double get_winning_probability() const { return winning_probability_; }
    
private:
	void total_cost(odds_result_pair rpair);
	void set_result_cost(odds_result_pair rpair);
};

//-----------------------------------------------------------------------

#endif /* defined(__odds__odds_position_manager__) */
