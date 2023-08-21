#include "Queue.h"
#include <iostream>

int Queue::first(){
    if(this -> q2.empty()){
        while(!this -> q1.empty()){
            int value = this -> q1.top();
            this -> q2.push(value);
            this -> q1.pop();
        }
    }

    return this -> q2.top();
}

void Queue::push(const int& value){
    this -> q1.push(value);
}

void Queue::pop(){
    if(this -> q2.empty()){
        while(!this -> q1.empty()){
            this -> q2.push(this -> q1.top());
            this -> q1.pop();
        }
    }
    this -> q2.pop();
}
