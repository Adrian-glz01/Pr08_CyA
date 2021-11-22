/**
 * @author: Adrián González Expósito
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º Ingeniería Informática
 * Práctica 8: Grammar simulation
 */


void Usage(int, char* argv[]);
void print_chain(std::string, std::string);
void chain_belong_alphabet(std::vector<std::string>, Alphabet);
void derivations_belong_nonterminalset(std::vector<std::pair<Chain, int>>, std::set<Symbols>);
