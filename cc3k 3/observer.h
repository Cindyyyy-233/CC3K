#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Cell;

class Observer
{
public:
    // Pass the Subject that called the notify method.
    virtual std::string notify(Cell &whoNotified) = 0;
    virtual ~Observer() = default;
};

#endif
