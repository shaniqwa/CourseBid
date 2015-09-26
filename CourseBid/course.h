#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Course{
private:
	int id;
	string name;
	string description;
	vector<string> preCourses;
	int max_students;

public:
	Course();
	Course(int id, string name, string des, vector<string> pre, int max);
	//Getters
	int getId();
	string getName();
	string getDescription();
	vector<string> getPreCourses();
	int getMaxStudents();
	//Setters
	void setId(int id);
	void setName(string name);
	void setDescription(string des);
	void setPreCourses(vector<string> pre);
	void setMaxStudents(int max);
	//other functions
	void display();
};