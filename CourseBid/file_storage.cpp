#include "file_storage.h"


FileStorage::FileStorage(string file_name){
	this->file_name = file_name;
	ifstream inFile;
	inFile.open(file_name);

	//Check for Error
	if (inFile.fail()){
		cerr << "Error Opening File";
		exit(1);
	}

	//m - num of students, n - num of courses
	int m, n;

	inFile >> m >> n;
	//read courses
	for (int i = 0; i < n; ++i){
		int id, max;
		string pass, name, des, pre;
		vector<string> Clist_temp;

		inFile >> id >> name >> des >> pre;
		while (pre != "$"){
			Clist_temp.push_back(pre);
			inFile >> pre;
		}
		inFile >> max;

		Course C(id, name, des, Clist_temp, max);

		Clist.push_back(C);
	
	}

	//for (vector<Course>::size_type i = 0; i != Clist.size(); i++) {
	//	Clist[i].display();
	//	cout << endl;
	//}


	//read students
	for (int i = 0; i < m; i++){	
	
		int id, points, state;
		string pass, name, complete;
		vector<string> Clist_temp;

		inFile >> id >> pass >> name >> complete;
		while (complete != "$"){
			Clist_temp.push_back(complete);
			inFile >> complete;
		}
		inFile >> points >> state;
		Student S(id, name, Clist_temp, points, pass, state);
		Slist.push_back(S);

	}

	for (vector<Student>::size_type i = 0; i != Slist.size(); i++) {
		Slist[i].display();
		cout << endl;
	}

	inFile.close();
}

FileStorage::~FileStorage(){
	cout << "\nFileStorage destructor\n";
}

vector<Student>& FileStorage::getStudentList(){
	return this->Slist;
}

vector<Course>& FileStorage::getCourseList(){
	return this->Clist;
}

void FileStorage::updateStudent(Student s){
	string search_string = to_string(s.getId());
	string replace_string = search_string +" " + s.getPass() + " " + s.getName() + " ";
	for (vector<string>::size_type i = 0; i != s.getCompleteCourses().size(); i++) {
		replace_string += s.getCompleteCourses()[i] + " ";
	}
	replace_string += " $ " + to_string(s.getPoints()) + " " ;

	string state = s.getStatus();
	if (state == "ACTIVE"){
		replace_string += " 1 ";
	}
	else{
		replace_string += " 0 ";
	}

	string inbuf;
	fstream input_file(this->file_name, ios::in);
	ofstream output_file("result.txt");
	//Check for Error
	if (input_file.fail()){
		cerr << "Error Opening Data File";
		exit(1);
	}
	while (!input_file.eof()){
		getline(input_file, inbuf);

		int spot = inbuf.find(search_string);
		if (spot >= 0){
			string tmpstring = inbuf.substr(0, spot);
			tmpstring += replace_string;
			tmpstring += inbuf.substr(spot + inbuf.length(), inbuf.length());
			inbuf = tmpstring;
		}

		output_file << inbuf << endl;
	}
	input_file.close();
	output_file.close();

	int result;
	char oldname[] = "result.txt";
	char newname[] = "data.txt";
	remove(newname);
	result = rename(oldname, newname);
	if (result == 0)
		puts("DB File successfully updated\n");
	else
		perror("Student update error: Error renaming file\n");
}




void FileStorage::updateCourse(Course c){
	string search_string = to_string(c.getId());
	string replace_string = search_string + " " + c.getName() + " " + c.getDescription() + " ";
	for (vector<string>::size_type i = 0; i != c.getPreCourses().size(); i++) {
		replace_string += c.getPreCourses()[i] + " ";
	}
	replace_string += " $ " + to_string(c.getMaxStudents()); 

	string inbuf;
	fstream input_file(this->file_name, ios::in);
	ofstream output_file("result.txt");
	//Check for Error
	if (input_file.fail()){
		cerr << "Error Opening Data File";
		exit(1);
	}
	while (!input_file.eof()){
		getline(input_file, inbuf);

		int spot = inbuf.find(search_string);
		if (spot >= 0){
			string tmpstring = inbuf.substr(0, spot);
			tmpstring += replace_string;
			tmpstring += inbuf.substr(spot + inbuf.length(), inbuf.length());
			inbuf = tmpstring;
		}

		output_file << inbuf << endl;
	}
	input_file.close();
	output_file.close();

	int result;
	char oldname[] = "result.txt";
	char newname[] = "data.txt";
	remove(newname);
	result = rename(oldname, newname);
	if (result == 0)
		puts("DB File successfully updated\n");
	else
		perror("Course update error: Error renaming file\n");
}