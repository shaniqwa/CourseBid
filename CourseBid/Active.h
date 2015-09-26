#ifndef ACTIVE_H
#define ACTIVE_H
#include <string>
#include "State.h"
#include "student.h"


class Active : public State {
private:
	Student* _context;
public:
	Active(Student* context);
	void Handle();
	void printMyState();
	string getState();
};
#endif;
