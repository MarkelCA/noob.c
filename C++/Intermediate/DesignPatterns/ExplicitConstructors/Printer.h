//
// Created by markel on 5/4/22.
//

#include <utility>
#include "string"

#ifndef DESIGNPATTERNS_CLASS_H
#define DESIGNPATTERNS_CLASS_H



class Printer {
public:
    std::string message;
    explicit Printer(std::string message) : message(message) {}
};


#endif //DESIGNPATTERNS_CLASS_H
