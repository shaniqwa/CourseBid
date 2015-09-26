#ifndef ACTIVE_H
#define ACTIVE_H
#include <iostream>
#include <stdio.h>
#include <string>
#include "State.h"
#include "student.h"

class Active : public State {
	private:
		Student* _context;
	public:
		Active(Student* context);
		void Handle();
		string getState();
};
#endif;
