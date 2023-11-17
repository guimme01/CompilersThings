#include <string>

#ifndef PRODUCTION_HPP
#define PRODUCTION_HPP

class Production{
    private:
        std::string head; //Left Side
        std::string body; //Right Side

    public:
        Production(const std::string&, const std::string&);
        std::string getHead() const;
        std::string getBody() const;
        void setHead(std::string);
        void setBody(std::string);
};

#endif