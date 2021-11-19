/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 8: Grammar simulation
 */

#include "alphabet.h"
#include "symbols.h"
#include "chain.h"
#include "utilities.h"

class Cfg {
 public:
  Cfg(Alphabet, std::set<Symbols>, Symbols,std::multimap<Chain, std::pair<int, Chain>>);
  void BuildChainByGrammar(std::vector<std::pair<Chain, int>>, std::string);
 private:
  Alphabet alphabet_;
  std::set<Symbols> non_terminal_set_;
  Symbols initial_symbol_;
  std::multimap<Chain, std::pair<int, Chain>> productions_rules_set_;
};