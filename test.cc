
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

void print_chain(std::string mychain) {
  std::cout << " => " << mychain;
}

int main() {
  std::vector<char> alfabeto = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '(', ')', '+', '-'};
  std::vector<char> non_terminal_alph = {'E', 'N', 'D'};

  std::multimap<std::string, std::pair<int, std::string>> prod_multimap;

  std::string prod1E = "( E )";
  std::string prod2E = "E + E";
  std::string prod3E = "E - E";
  std::string prod4E = "N";
  std::string prod1N = "ND";
  std::string prod2N = "D";
  std::string prod0D = "0";
  std::string prod1D = "1";
  std::string prod2D = "2";
  std::string prod3D = "3";
  std::string prod4D = "4";
  std::string prod5D = "5";
  std::string prod6D = "6";
  std::string prod7D = "7";
  std::string prod8D = "8";
  std::string prod9D = "9";

  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("E", std::pair<int, std::string>(1, prod1E)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("E", std::pair<int, std::string>(2, prod2E)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("E", std::pair<int, std::string>(3, prod3E)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("E", std::pair<int, std::string>(4, prod4E)));

  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("N", std::pair<int, std::string>(1, prod1N)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("N", std::pair<int, std::string>(2, prod2N)));

  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(1, prod0D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(2, prod1D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(3, prod2D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(4, prod3D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(5, prod4D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(6, prod5D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(7, prod6D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(8, prod7D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(9, prod8D)));
  prod_multimap.insert(std::pair<std::string, std::pair<int, std::string>>("D", std::pair<int, std::string>(10, prod9D)));

  // Derivaciones
  std::vector<std::pair<std::string, int>> drv;
  drv.emplace_back(std::pair<std::string, int>("E", 1));
  drv.emplace_back(std::pair<std::string, int>("E", 2));
  drv.emplace_back(std::pair<std::string, int>("E", 4));
  drv.emplace_back(std::pair<std::string, int>("N", 2));
  drv.emplace_back(std::pair<std::string, int>("D", 5));
  drv.emplace_back(std::pair<std::string, int>("E", 1));
  drv.emplace_back(std::pair<std::string, int>("E", 3));
  drv.emplace_back(std::pair<std::string, int>("E", 4));
  drv.emplace_back(std::pair<std::string, int>("N", 1));
  drv.emplace_back(std::pair<std::string, int>("N", 2));
  drv.emplace_back(std::pair<std::string, int>("D", 2));
  drv.emplace_back(std::pair<std::string, int>("D", 1));
  drv.emplace_back(std::pair<std::string, int>("E", 4));
  drv.emplace_back(std::pair<std::string, int>("N", 2));
  drv.emplace_back(std::pair<std::string, int>("D", 8));
  
  std::string mychain = "E";
  
  std::cout<< "E ";
  for(auto deriv = 0; deriv < drv.size(); deriv++) {
    for(auto product = prod_multimap.begin(); product != prod_multimap.end(); product++) {  
      if(drv[deriv].first == product->first) {
        if(drv[deriv].second == product->second.first) {
          mychain.replace(mychain.find(drv[deriv].first), drv[deriv].first.length(), product->second.second);
          print_chain(mychain);
          //std::cout << product->second.second << " => ";
        }
      }
    }
  }
  std::cout << "\n";
}

/*
0(10)∗  =>  01010

S(1) → 0A    //std::multimap<char, std::pair < int , std::vector<std::string>>
A(1) → 10A   //std::multimap<char, int> 
A(2) → ε

S: 1
A: 1
A: 1
A: 2

    S1     A1       A1        A2
S-> 0A -> 010A -> 01010A -> 01010
*/