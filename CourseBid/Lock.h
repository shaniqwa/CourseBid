#ifndef LOCK_H
#define LOCK_H
#include <string>
#include "State.h"
#include "student.h"


class Lock : public State
{
private:
	Student* _context;

public:
	Lock(Student* context);
	void Handle();
	void printMyState();
	string getState();
};

#endif;