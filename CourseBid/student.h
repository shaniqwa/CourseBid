#ifndef STUDENT_H
#define STUDENT_H
#include <vector>
#include <string>
#include "course.h"
#include "State.h"

using namespace std;

class Student{
private:
	int id;
	string name;
	vector<string> complete_courses;
	int points;
	string pass;
	State* _status;

public:
	Student();
	Student(int id, string name, vector<string> courses, int points, string pass, int state);
	//Getters
	int getId();
	string getName();
	vector<string> getCompleteCourses();
	int getPoints();
	string getPass();
	string getStatus();
	//Setters
	void setId(int id);
	void setName(string name);
	void setCompleteCourses(vector<string> courses);
	void setPoints(int points);
	void setStatus(State* status);
	//other functions
	void display();
	void Handle();
	void operator=(const Student &S);
};

#endif;