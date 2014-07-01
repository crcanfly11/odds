//
//  oddscalulate.cpp
//  odds
//
//  Created by 金成日 on 14-7-1.
//  Copyright (c) 2014年 金成日. All rights reserved.
//

#include "oddscalulate.h"

void organizer::init()
{
    while(1) {
        cout<<"add new fixtures odds?(Y:yes/others:no)"<<endl;
        cin.getline(tmp_,100);
        cin.clear();
        
        if(!strcmp(tmp_,"Y")||!strcmp(tmp_,"y")) {
            cout<<"input home team win odds:"<< endl;
            cin.getline(tmp_,100);
            htwin_ = atof(tmp_);
            cin.clear();
            
            cout<<"input shake hands odds:"<< endl;
            cin.getline(tmp_,100);
            sh_ = atof(tmp_);
            cin.clear();
            
            cout<<"input away team win odds:"<< endl;
            cin.getline(tmp_,100);
            atwin_ = atof(tmp_);
            cin.clear();
            
            cout<<"input away team win odds:"<< endl;
            cin>>htname_;
            cin.clear();
            
            cout<<"input away team win odds:"<< endl;
            cin>>atname_;
            cin.clear();
            
            fixtures_base_odds* pbo = new fixtures_base_odds(htwin_, sh_, atwin_, htname_, atname_);
            base_odds_.push_back(*pbo);
        }else {
            break;
        }
    }
    
    forecas_calculate(base_odds_.begin(),base_odds_.end());
};

void organizer::forecas_calculate(base_odds_vector::iterator begin, base_odds_vector::iterator end)
{
    if(begin + 1 == end) return;
    
    for_each(begin, end, boost::bind(&organizer::set_forecas_result_map, this, *begin, _1));
    
    return forecas_calculate(++begin, end);
};

void organizer::set_forecas_result_map(int frontodd, int value)
{
    //add this method
};