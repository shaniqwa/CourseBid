#include "course.h"
Course::Course(int id, string name, string des, vector<string> pre, int max){
	this->id = id;
	this->name = name;
	this->description = des;
	this->preCourses = pre;
	this->max_students = max;
}
//Getter
int Course::getId(){
	return this->id;
}
string Course::getName(){
	return this->name;
}
string Course::getDescription(){
	return this->description;
}
vector<string> Course::getPreCourses(){
	return this->preCourses;
}

int Course::getMaxStudents(){
	return this->max_students;
}
//Setters
void Course::setId(int id){
	this->id = id;
}
void Course::setName(string name){
	this->name = name;
}
void Course::setDescription(string des){
	this->description = des;
}
void Course::setPreCourses(vector<string> pre){
	this->preCourses = pre;
}

void Course::setMaxStudents(int max){
	this->max_students = max;
}
//other functions
void Course::display(){
	cout << "Course ID: " << this->getId() << endl;
	cout << "Name: " << this->getName() << endl;
	cout << "Description: " << this->getDescription() << endl;
	vector<string> list = this->getPreCourses();
	cout << "Pre Courses: ";
	for (vector<string>::size_type i = 0; i != list.size(); i++) {
		cout << list[i] << " " ;
	}
	cout << "\nMax Students in this course: " << this->getMaxStudents() << endl;
}