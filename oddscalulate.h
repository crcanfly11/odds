#ifndef __odds__oddscalulate__
#define __odds__oddscalulate__

<<<<<<< HEAD
#include <iostream>

=======
>>>>>>> origin/master
#include <boost/bind.hpp>

#include <iostream>
#include <vector>
#include <map>
<<<<<<< HEAD
#include <algorithm>

using namespace std;

enum team_odd_type { max_odds_type = 3 };

=======
#include <set>
#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

enum unit_price { lottery = 2, max_total_cost = 500 };
enum team_odd_type { max_odds_type = 3 };
enum play_type { win_draw_lost = 3 };
enum result_type { host_win = 0x01, shake_hand = 0x10, away_win = 0x100,  };
//0x1000 = 4096, 0x0100 = 256, 0x0010 = 16, 0x0001 = 1;
//0x11000 = 4096 why?  64bit?
enum result_type_9 { HWHW = 1,  HWSH = 2,   HWAW = 4,
                     SHHW = 8,  SHSH = 16,  SHAW = 32,
                     AWHW = 64, AWSH = 128, AWAW = 256 };
enum play_mode { none_modem, portion_mode, whole_mode, manual_mode };
>>>>>>> origin/master
//-----------------------------------------------------------------------

class fixtures_base_odds
{
	enum team_odd_enum { home_team_win = 0, shake_hands = 1, away_team_win = 2 };
<<<<<<< HEAD
    
	double team_odds_[3];
    
=======
	    
	double team_odds_[win_draw_lost];
	    
>>>>>>> origin/master
	char home_team_[30];
	char away_team_[30];
public:
	fixtures_base_odds(double win_odds, double shake_hands_odds, double lose_odds, const char* home_team_name, const char* away_team_name);
<<<<<<< HEAD
    
=======
	
>>>>>>> origin/master
	double operator[] (int index);

	double get_win_odds() const { return team_odds_[home_team_win]; }
	double get_shake_hands_odds() const { return team_odds_[shake_hands]; }
	double get_lose_odds() const { return team_odds_[away_team_win]; }
<<<<<<< HEAD

=======
	
>>>>>>> origin/master
	const char* get_home_team_name() { return home_team_; }
	const char* get_away_team_name() { return away_team_; }
};

//-----------------------------------------------------------------------

class forecas_result
{
	double odds_;
<<<<<<< HEAD
	unsigned short multiple_;	 //bei shu
	double yield_;			     //Unit of Measure %
	char result_msg_[10];
    
public:
	forecas_result(double odds, const char* result_msg);
    
	void set_result_multiple(unsigned short multiple) { multiple_ = multiple; }
	unsigned short get_result_multiple() const { return multiple_; }
	double get_result_odds() const { return odds_; }
	double get_result_yield() const { return yield_; }
	const char* get_result_msg() const { return result_msg_; }
=======
	double probability_;        //Unit of Measure %
	char result_msg_[10];

	unsigned short multiple_;	 //bei shu
	double income_;
	double yield_;			     //Unit of Measure %
	double total_cost_;
	double net_income_;
    short flag_;
    double unit_profit_;
  
public:
	forecas_result(double odds, double probability, const char* result_msg);
	forecas_result(const forecas_result& result);
	    
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
	double get_total_cost() const { return total_cost_; }
    double get_unit_profit() const { return unit_profit_; }
	const char* get_result_msg() const { return result_msg_; }
	short get_flag() const { return flag_; }
>>>>>>> origin/master
};

//-----------------------------------------------------------------------

<<<<<<< HEAD
class position
{
	char earnings_range[100];   //range of yield
	double cost;
};

//-----------------------------------------------------------------------

=======
typedef vector<fixtures_base_odds> base_odds_vector;
typedef map<unsigned int, forecas_result> forecas_result_map;
typedef pair<unsigned int, forecas_result> forecas_result_pair;

//-----------------------------------------------------------------------

class position;
class regulator;
class optimization_result;

>>>>>>> origin/master
class organizer
{
	double htwin_, sh_, atwin_;
	char htname_[20], atname_[20], tmp_[100], result_[5];
<<<<<<< HEAD
    
	typedef vector<fixtures_base_odds> base_odds_vector;
	base_odds_vector base_odds_;
    
	typedef map<unsigned int, forecas_result> forecas_result_map;
	forecas_result_map forecas_results_;
    
	typedef pair<unsigned int, forecas_result> forecas_result_pair;

public:
    organizer();
    
private:
    void init();
    void forecas_calculate(base_odds_vector::iterator begin, base_odds_vector::iterator end);
    void set_forecas_result_map(fixtures_base_odds first, fixtures_base_odds second);
	void result_msg(int first, int second);
	const char* get_result_flag(int index);

	void print(forecas_result_pair rpair);
=======
    short flag_;
	unsigned short index_;

	base_odds_vector base_odds_;
	forecas_result_map forecas_base_results_;
	forecas_result_map forecas_results_;

	position* position_;
	regulator* regulator_;
	optimization_result* optimization_result_;
public:
    organizer();
	~organizer();
    
	forecas_result_map* get_result_map() { return &forecas_results_; }
	position* get_position() { return position_; }
    regulator* get_regulator() { return regulator_; }

	void init();

	void clear();

	void print();
	void print(forecas_result_pair rpair);

private:
    void forecas_calculate(base_odds_vector::iterator begin, base_odds_vector::iterator end);
    void set_forecas_result_map(fixtures_base_odds first, fixtures_base_odds second);
	void result_msg(int first, int second);
	const char* msg_type(int index);
	int flag_type(int index);
	int check_odds();
    void execution(short mode);
};

//-----------------------------------------------------------------------

class position
{
	char earnings_range_[100];   //range of yield
	double cost_;
	int real_size_;
	double winning_probability_;

	organizer* organizer_;

public:
	position(organizer* org);
	
	void refresh();
	void clear();
	int add_someone_position(unsigned int index);

	void set_real_size(int rsize) { real_size_ = rsize; }
	void set_winning_probability(double probability) { winning_probability_ = probability; }

	double get_cost() { return cost_; }
	const char* get_earnings_range() { return earnings_range_; }
	int get_real_size() const { return real_size_; }
	double get_winning_probability() const { return winning_probability_; }

private:
	void total_cost(forecas_result_pair rpair);
	void set_result_cost(forecas_result_pair rpair);
};

//-----------------------------------------------------------------------

typedef map<double, forecas_result_map> optimization_result_map;
typedef pair<double, forecas_result_map> optimization_result_pair;

//-----------------------------------------------------------------------

class optimization_result 
{
	double max_min_yield_;
	unsigned int min_idx;

	optimization_result_map optimization_results_;	
	map<double, unsigned int> min_index_map_;

	organizer* organizer_;

public:
	optimization_result(organizer* org);
	
	void optimization();
	void clear();
    
    optimization_result_map* get_optimization_result_map() { return &optimization_results_; }
    
private:
	unsigned int get_result_min_idx();
	void print();
	void print_result();
};

//-----------------------------------------------------------------------

class regulator
{
	double adjusted_income_;
	double adjusted_yield_;

    bool is_overtop_;
	//play_mode mode_;
	short mode_;
    
	organizer* organizer_;

public:
	regulator(organizer* org);

    void clear();
    
	void set_play_mode(int mode);
    
    bool isovertop() const { return is_overtop_; }
    
private:
	void init_position();
	void init_results(forecas_result& rpair);
	void hedge_positions();
	void add_position();
>>>>>>> origin/master
};

//-----------------------------------------------------------------------

#endif /* defined(__odds__oddscalulate__) */
