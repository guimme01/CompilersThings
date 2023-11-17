#include <string>
#include <list>
#include "Production.hpp"

class Grammar{
    private:
        std::string startSymbol;
        std::list<std::string> terminals;
        std::list<std::string> nonTerminals;
        std::list<Production> productions;

    public:
        Grammar(const std::string&, const std::list<std::string>&, const std::list<std::string>&, const std::list<Production>&);
        std::string getStartSymbol() const;
        std::list<std::string> getTerminals() const;
        std::list<std::string> getNonTerminals() const;
        std::list<Production> getProductions() const;
        void printGrammar() const;
        void setProductions(std::list<Production>);
};