#pragma once
#include <string>
#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <fstream>
#include <vector>
#include "IStorage.h"
//#include "student.h"
//#include "course.h"

using namespace std;

class FileStorage : public IStorage {
private:
	string file_name;
	vector<Course> Clist;
	vector<Student> Slist;
	static FileStorage *s_instance;
	
public:
	static FileStorage *instance();
	FileStorage(string file_name);
	~FileStorage();

	vector<Student> getStudentList();
	vector<Course> getCourseList();
	void updateStudent(Student s);
	void updateCourse(Course c);
};

