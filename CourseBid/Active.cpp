#pragma hdrstop   
#include "Active.h"
#include "Lock.h"

Active::Active(Student* context) : _context(context) {};

void Active::Handle(){
	_context->setStatus( new Lock(_context) );
}
string Active::getState(){
	string state = "ACTIVE";
	return state;
}
#pragma package(smart_init)