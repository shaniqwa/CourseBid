#ifndef LOCK_H
#define LOCK_H
#include <iostream>
#include <stdio.h>
#include <string>
#include "State.h"
#include "student.h"

class Lock : public State{
	private:
		Student* _context;
	public:
		Lock(Student* context);
		void Handle();
		string getState();
};
#endif;