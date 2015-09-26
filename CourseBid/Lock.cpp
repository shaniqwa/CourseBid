#pragma hdrstop   
#include "Lock.h"
#include "Active.h"

Lock::Lock(Student* context) : _context(context) {};
void Lock::Handle(){
	_context->setStatus(new Active(_context));
}

void Lock::printMyState(){
	printf("LOCK\n");
}
string Lock::getState(){
	string state = "Lock";
	return state;
}
#pragma package(smart_init)