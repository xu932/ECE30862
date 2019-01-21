#ifndef SQUEAK_H_
#define SQUEAK_H_
#include <string>
#include "Quack.h"

class Squeak : public Quack {
public:
    Squeak();
    virtual ~Squeak();
    virtual void quack();
};
// PUT CODE HERE.  Use QuackQuack.h as an example.

#endif /* SQUEAK_H_ */
