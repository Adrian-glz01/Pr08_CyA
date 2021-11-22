/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 8: Grammar simulation
 */
#include "../includes/Cfg.h"

/**
 * @brief Construct a new Cfg:: Cfg object
 * 
 * @param Alphabet alphabet 
 * @param std::set<Symbols> non_terminal_set 
 * @param Symbol initial_symbol 
 * @param std::multimap<std::string,_std::pair<int,_std::string>> productions_rules_set 
 */
Cfg::Cfg( Alphabet alphabet, std::set<Symbols> non_terminal_set, Symbols initial_symbol ,std::multimap<Chain, std::pair<int, Chain>> productions_rules_set) {
  alphabet_ = alphabet;
  non_terminal_set_ = non_terminal_set;
  initial_symbol_ = initial_symbol;
  productions_rules_set_ = productions_rules_set;
}

/**
 * @brief Algorithm to build a chang by the productions of the grammar
 * 
 * @param std::vector<std::pair<Chain,_int>> derivations 
 * @param std::string output_file 
 */
void Cfg::BuildChainByGrammar(std::vector<std::pair<Chain, int>> derivations, std::string output_file) {
  std::vector<std::string> parsed_chains;
  derivations_belong_nonterminalset(derivations, non_terminal_set_);
  std::ofstream os;
  os.open(output_file.c_str(), std::ofstream::trunc);
  os << initial_symbol_.get_symbols();
  os.close();
  std::string Chain = initial_symbol_.get_symbols();
  for (auto deriv = 0; deriv < derivations.size(); deriv++) {
    for (auto productions = productions_rules_set_.begin(); productions != productions_rules_set_.end(); productions++) {
      if (derivations[deriv].first.get_chain() == productions->first.get_chain()) {
        if (derivations[deriv].second == productions->second.first) {
          Chain.replace(Chain.find(derivations[deriv].first.get_chain()), derivations[deriv].first.get_chain().length(), productions->second.second.get_chain());
          print_chain(Chain, output_file);
          parsed_chains.emplace_back(Chain);
        }
      }
    }
  }
  chain_belong_alphabet(parsed_chains,alphabet_);
}