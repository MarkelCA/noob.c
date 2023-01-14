//
// Created by markel on 5/7/22.
//


#ifndef DESIGNPATTERNS_PERSON_H
#define DESIGNPATTERNS_PERSON_H


#include "Talks.h"
#include "iostream"
class Person : public Talks {
public:
    void sayHi() override {
        std::cout << "Hi person" ;
    }


};


#endif //DESIGNPATTERNS_PERSON_H
