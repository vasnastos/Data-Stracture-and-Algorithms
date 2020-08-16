#include "election.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>
#include <vector>
int sum(int s,election &elec);
void open_file(std::vector <election> &elc);
size_t calculate_total(std::vector <election> &el);
std::map <std::string,double> precents(std::vector <election> &el);