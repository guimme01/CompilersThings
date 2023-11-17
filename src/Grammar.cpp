#include "Grammar.hpp"
#include "Production.hpp"
#include <iostream>
#include <list>
#include <string>

Grammar::Grammar(const std::string& startSymbol, const std::list<std::string>& terminals, const std::list<std::string>& nonTerminals, 
    const std::list<Production>& productions): startSymbol(startSymbol), terminals(terminals), nonTerminals(nonTerminals), productions(productions)
{}

std::string Grammar::getStartSymbol() const{
    return startSymbol;
}
std::list<std::string> Grammar::getTerminals() const{
    return terminals;
}
std::list<std::string> Grammar::getNonTerminals() const{
    return nonTerminals;
}
std::list<Production> Grammar::getProductions() const{
    return productions;
}
void Grammar::setProductions(std::list<Production> newProductions){
    this->productions = newProductions;
}
void Grammar::printGrammar() const {
    std::cout << "Simbolo iniziale: " << this->startSymbol << "\n";

    std::cout << "Terminali: { ";
    for (const auto& terminal : this->terminals) {
        std::cout << terminal << " ";
    }
    std::cout << "}\n";

    std::cout << "Non terminali : { ";
    for (const auto& nonTerminal : this->nonTerminals) {
        std::cout << nonTerminal << " " ;
    }
    std::cout << "}\n";

    std::cout << "Produzioni : \n { ";
    for (const auto& produzione : this->productions) {
        std::cout << "\n\t" << produzione.getHead() << " -> " << produzione.getBody();
    }
    std::cout << "\n }";
}

