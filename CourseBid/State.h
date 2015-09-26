#ifndef STATE_H
#define STATE_H
#include <string>

using namespace std;

class State {
public:
	virtual void Handle() = 0;
	virtual string getState() = 0;
}; 
#endif;