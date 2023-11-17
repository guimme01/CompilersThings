#include "Production.hpp"
#include <string>

Production::Production(const std::string& head, const std::string& body): head(head), body(body)
{
}

std::string Production::getHead() const{
    return head;
}

std::string Production::getBody() const {
    return body;
}

void Production::setHead(std::string newHead) {
    this->head = newHead;
}

void Production::setBody(std::string newBody) {
    this->body = newBody;
}