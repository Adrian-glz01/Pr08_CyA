/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 8: Grammar simulation
 */

#include "../includes/Cfg.h"

const std::string KError_message{
    "Fatal error! The execution of this programm is not correct.\n\
  Try './{exe_file_name}  --help' to get more information.\n"};

const std::string Khelp_message{
    "The execution of this program must be done with 3 parameters.\n\
  Correct use example: ./{exe_file_name} [input.cfg] [input.drv] [output_file]\n\n"};

/**
 *
 *  @brief Send a error message if the arguments on the execution are not
 *  corrects.
 *  @param int argc
 *  @param char* argv[]
 *
 */
void Usage(int argc,char* argv[]) {
  if (argc == 1) {
    std::cout << KError_message << std::endl;
    exit(EXIT_SUCCESS);
  }else if (strcmp(argv[1], "--help") == 0) {
    std::cout << Khelp_message << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Print the chain in the output file.
 * 
 * @param std::string mychain 
 * @param std::string out 
 */
void print_chain(std::string mychain, std::string out) {
  std::ofstream os;
  os.open(out, std::ofstream::app);
  os << " => " << mychain;
}

/**
 * @brief Check if the chain obtended belong to the alphabet
 * 
 * @param std::vector<std::string> parsed_chain_vec 
 * @param Alphabet alphabet 
 */
void chain_belong_alphabet(std::vector<std::string> parsed_chain_vec, Alphabet alphabet) {
  std::string chain_to_check = parsed_chain_vec.back();
  std::vector<std::string> alphabet_aux;
  for (auto element: alphabet.get_alph()) {
    alphabet_aux.emplace_back(element.get_symbols());
  }
  for (auto element : chain_to_check) {
    std::string symbol;
    symbol.push_back(element);
    std::vector<std::string>::iterator belong = std::find(alphabet_aux.begin(), alphabet_aux.end(), symbol);

    if (belong == alphabet_aux.end()) { 
      std::cout << "The chain does not belong to the grammar alphabet\n";
      std::cout << "Program aborted!\n";
      exit(EXIT_SUCCESS);
    }
  }
}
/**
 * @brief Chek if all the non terminal elements introduced on input.drv belong to the non terminal set.
 * 
 * @param std::vector<std::pair<Chain,_int>> derivations 
 * @param std::set<Symbols> non_terminal_set 
 */
void derivations_belong_nonterminalset(std::vector<std::pair<Chain, int>> derivations, std::set<Symbols> non_terminal_set) {
  std::vector<std::string> non_terminal_vec;
  for (auto element : non_terminal_set) {
    non_terminal_vec.emplace_back(element.get_symbols());
  }
  for (auto nt_element: derivations) {
    std::vector<std::string>::iterator belong = std::find(non_terminal_vec.begin(), non_terminal_vec.end(), nt_element.first.get_chain());
    if (belong == non_terminal_vec.end()) { 
      std::cout << "The non terminal element introduced does not belong to the non terminal alphabet.\n";
      std::cout << "Program aborted!\n";
      exit(EXIT_SUCCESS);
    }
  }
}