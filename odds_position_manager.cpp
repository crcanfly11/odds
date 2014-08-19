//
//  odds_position_manager.cpp
//  odds
//
//  Created by 金成日 on 14-8-18.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#include "odds_position_manager.h"

//-----------------------------------------------------------------------

odds_result::odds_result(double odds, double probability, const char* result_msg) :
    odds_(odds), multiple_(0), income_(0), yield_(0), net_income_(0), flag_(0x00), probability_(probability), unit_profit_(0)
{
	strncpy(result_msg_, result_msg, sizeof(result_msg_));
   	strncpy(team_msg_, 0, sizeof(team_msg_));
};

odds_result::odds_result(const odds_result& result)
{
	odds_ = result.odds_;
	multiple_ = result.multiple_;
	income_ = result.income_;
	yield_ = result.yield_;
	net_income_ = result.net_income_;
	flag_ = result.flag_;
	probability_ = result.probability_;
    unit_profit_ = result.unit_profit_;
    
	strncpy(result_msg_, result.result_msg_, sizeof(result_msg_));
};

void odds_result::set_result_multiple(unsigned short multiple)
{
	multiple_ = multiple;
    
	if(multiple_) income_ = lottery*multiple_*odds_;
};

void odds_result::set_total_cost(double tcost)
{
	if(tcost == 0 || multiple_ == 0) return;
    
	net_income_ = income_ - tcost;
	yield_ = (net_income_/tcost)*100;
    unit_profit_ = yield_/tcost;
};

void odds_result::clear_dynamic_data()
{
	multiple_ = 0;
	net_income_ = 0;
	yield_ = 0;
	income_ = 0;
    unit_profit_ = 0;
};

//-----------------------------------------------------------------------

odds_position::odds_position() : total_cost_(0), unit_profit_(0), real_size_(0), winning_probability_(0)
{
};

void odds_position::clear()
{
	total_cost_ = 0;
    unit_profit_ = 0;
	real_size_ = 0;
	winning_probability_ = 0;
};

void odds_position::reset()
{
    if(!odds_results_.empty())
        odds_results_.clear();
    
    odds_results_ = odds_original_results_;
};

void odds_position::refresh()
{
	total_cost_ = 0;
    
	for(odds_result_map::iterator iter_total_cost = odds_results_.begin();
		iter_total_cost != odds_results_.end();++iter_total_cost) {
		if(iter_total_cost->second.get_result_multiple() == 0)
			continue;
        
		total_cost_ += iter_total_cost->second.get_result_multiple() * lottery;
	}
    
//	for_each(odds_results_.begin(), odds_results_.end(),
//             boost::bind(&odds_position::total_cost, this,
//                         boost::bind<odds_result>(&odds_result_map::value_type::second,_1)));
    
	for(odds_result_map::iterator iter_set_result_cost = odds_results_.begin();
		iter_set_result_cost != odds_results_.end();++iter_set_result_cost) {
		iter_set_result_cost->second.set_total_cost(total_cost_);
	}
};

void odds_position::total_cost(odds_result_pair rpair)
{
	if(rpair.second.get_result_multiple() == 0) return;
    
	total_cost_ += rpair.second.get_result_multiple() * lottery;
};

void odds_position::set_result_cost(odds_result_pair rpair)
{
	rpair.second.set_total_cost(total_cost_);
};

int odds_position::add_someone_position(unsigned int index)
{
    odds_result_map::iterator iter = odds_results_.find(index);
    if(iter == odds_results_.end())
        return 0;
    
    iter->second.set_result_multiple(iter->second.get_result_multiple()+1);
    
    refresh();
    
    return 1;
};

//-----------------------------------------------------------------------