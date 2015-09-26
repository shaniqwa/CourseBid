#pragma once
#include "student.h"
#include "course.h"

class IStorage {
public:
	virtual vector<Student> getStudentList() = 0;
	virtual vector<Course> getCourseList() = 0;
	virtual void updateStudent(Student s) = 0;
	virtual void updateCourse(Course s) = 0;
};

