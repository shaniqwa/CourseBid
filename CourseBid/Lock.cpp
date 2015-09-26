#pragma hdrstop   
#include "Lock.h"
#include "Active.h"

Lock::Lock(Student* context) : _context(context) {};
void Lock::Handle(){
	_context->setStatus(new Active(_context));
}

string Lock::getState(){
	string state = "LOCK";
	return state;
}
#pragma package(smart_init)