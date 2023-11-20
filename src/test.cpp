#include "Production.hpp"
#include "Grammar.hpp"
#include <iostream>
#include <string>
#include <list>

std::string getFirstRightSymbol(Production p){
    std::string s = "";
    for(int i = 0; p.getBody()[i] != '\0'; i++){
        if(p.getBody()[i] == ' '){
            return s;
        }
        s.push_back(p.getBody()[i]);
    }
    return s;
}

bool isRecursive(const Grammar& g){
    std::list<Production> prods = g.getProductions();
    std::string x;
    for(const auto& p : prods){
        x = getFirstRightSymbol(p);
        if(p.getHead() == x)
            return true;
    }
    return false;
}

std::list<Production> removeLeftRecursion(Grammar& g){
    std::list<Production> newProduction;
    std::list<Production> noLeftRecProductions;
    Production produzioneTemp("", "");
    std::string tmp;
    std::string alpha, beta;
    for (auto& p : g.getProductions()){
        tmp = getFirstRightSymbol(p);
        if(tmp == p.getHead()){
            for(auto& tmpP : g.getProductions()){
                if(tmpP.getHead() == tmp){
                    if(getFirstRightSymbol(tmpP) == tmp){
                        alpha = tmpP.getBody().substr(tmp.size());
                        produzioneTemp.setHead(tmp+"'");
                        produzioneTemp.setBody(alpha+" "+tmp+"'");
                    }else{
                        beta = tmpP.getBody();
                        produzioneTemp.setHead(tmpP.getHead());
                        produzioneTemp.setBody(beta+" "+tmpP.getHead()+"'");
                    }
                    newProduction.push_back(produzioneTemp);
                }
            }
        }else{
            noLeftRecProductions.push_front(p);
        }
    }
    bool add = true;
    std::list<Production> tmpList = newProduction;
    for(auto& p : noLeftRecProductions){
        for(auto& p2 : tmpList){
            if(p.getHead() == p2.getHead())
                add = false;
        }
        if(add){
            newProduction.push_front(p);
            add = false;
        }
    }
    return newProduction;
}

int main(){
    Production p("S", "E + E");
    Production p2("E", "E * id");
    Production p3("E", "%");

    std::list<std::string> terminals;
    std::list<std::string> nonterminals;
    std::list<Production> productions;

    terminals.push_front("id");
    terminals.push_front("+");

    nonterminals.push_front("S");
    nonterminals.push_front("E");

    productions.push_front(p);
    productions.push_front(p2);
    productions.push_front(p3);

    Grammar g("S", terminals, nonterminals, productions);

    g.printGrammar();

    if(isRecursive(g)){
        std::cout << "\n e' ricorsiva ora tolgo ricorsione...\n";
        g.setProductions(removeLeftRecursion(g));
        g.printGrammar();
    }

    return 0;
}