/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 8: Grammar simulation
 */

#include "../includes/Cfg.h"


int main(int argc,char* argv[]) {
  Usage(argc,argv);
  std::string input_grammar = argv[1];
  std::string input_derivation = argv[2];
  std::string output_file = argv[3];

  //derivations
  std::ifstream deriv_inputfile;
  std::string derive_line;
  deriv_inputfile.open(input_derivation);

  std::vector<std::pair<Chain, int>> derivations_vec;

  while (std::getline(deriv_inputfile,derive_line)) {
    Chain nonterminal_derivation_element(std::string(1, derive_line[0]));
    int element_derivation = std::stoi(std::string(1, derive_line[4]));
    derivations_vec.emplace_back(std::pair<Chain, int>(nonterminal_derivation_element, element_derivation));
  }

  //Grammar elements

  std::ifstream grammar_inputfile;
  std::string grammar_line;
  grammar_inputfile.open(input_grammar);

  //Alphabet
  std::set<Symbols> alphabet_set;
  getline(grammar_inputfile,grammar_line);
  std::string symbols_aux = grammar_line;
  for (int iterator = 0; iterator < symbols_aux.size(); iterator++) {
    Symbols alph_symbols;
    if (iterator % 2 == 0) {
      alph_symbols = std::string(1, symbols_aux[iterator]);
      alphabet_set.insert(alph_symbols);
    }
  }
  Alphabet alphabet(alphabet_set); //first parameter of cfg object

  //non terminal sets and initial synbol
  std::set<Symbols> non_terminal_set; // Second parameter of cfg object
  getline(grammar_inputfile,grammar_line);
  std::string non_terminal_set_aux = grammar_line;

  Symbols initial_symbol;

  for (int iterator_nte = 0; iterator_nte < non_terminal_set_aux.size(); iterator_nte++) {
    Symbols initial_symbol_aux(std::string(1,non_terminal_set_aux[0])); 
    initial_symbol = initial_symbol_aux; // Third parameter of Cfg object

    if (iterator_nte % 2 == 0) {
      Symbols non_terminal_symbols(std::string(1, non_terminal_set_aux[iterator_nte]));
      non_terminal_set.insert(non_terminal_symbols);
    }
  }

  //Productions
  std::multimap<Chain, std::pair<int, Chain>> productions_rules_set; //Fourth parameter of cfg object

  int aux = 0;
  std::string string_aux = std::string(1, non_terminal_set_aux[0]);

  while (getline(grammar_inputfile,grammar_line)) {
    Chain nt_element(std::string(1, grammar_line[0]));

    std::string pharsed_line_str = grammar_line;
    pharsed_line_str.erase(0,5);
    Chain production_string(pharsed_line_str);

    if (std::string(1, grammar_line[0]) == string_aux) {
      aux++;
      productions_rules_set.insert(std::pair<Chain, std::pair<int, Chain>>(nt_element, std::pair<int, Chain>(aux, production_string)));
    } else {
      string_aux = std::string(1, grammar_line[0]);
      aux = 1;
      productions_rules_set.insert(std::pair<Chain, std::pair<int, Chain>>(nt_element, std::pair<int, Chain>(aux, production_string)));
    }
  }
  Cfg grammar(alphabet, non_terminal_set, initial_symbol, productions_rules_set);
  grammar.BuildChainByGrammar(derivations_vec, output_file);
  /*for (auto element: productions_rules_set) {
    std::cout << element.first << ":" << element.second.first << " -> " << element.second.second << "\n";
  }*/
}