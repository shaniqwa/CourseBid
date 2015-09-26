//Shani Almog 302522669 && Viktoria Yakobashvili 309957363//
#include <iostream>
#include <algorithm>
#include "CalculateCourseBid.h"
#include "student.h"
#include "StorageFactory.h"
#include "IStorage.h"

using namespace lemon;
using namespace std;

void main(){
	//create DB factory
	StorageFactory* DBfactory = new StorageFactory();
	//Factory instantiating an object of type file_db
	IStorage* db = DBfactory->DataStorage(FILE_STORAGE, "data.txt");
	//init
	vector<Student> S = db->getStudentList();
	vector<Course> C = db->getCourseList();
	CalculateCourseBid* R;

	for (;;){
		cout << "\nMenu:\n 1) Registration Terminal\n 2) Calculate CourseBid\n 3) Veiw CourseBid resutls\n";
		int x;
		cin >> x;
		switch (x){
		case 1: {
			int flag = 1; Student temp;
			while (flag){
				cout << "Please enter your ID\n";
				int id;
				cin >> id;
				cin.clear();
				cin.ignore(100, '\n');  //100 --> asks cin to discard 100 characters from the input stream. avoiding loop when user input is not integers
				for (vector<Student>::size_type i = 0; i != S.size(); i++) {
					if (S[i].getId() == id){
						temp = S[i];
						flag = 0;
						break;
					}
				}
				if (flag == 1){
					cout << "no such ID \n";
				}
			}
			if (temp.getStatus() == "ACTIVE"){
				int i = 1;
				for (i = 1; i < 4; i++){
					cout << "Please enter your password\n";
					string pass;
					cin >> pass;
					if (temp.getPass() != pass){
						cout << "Wrong pass word. this was attempt num " << i << " out of 3 before your account goes to LOCK state\n";
					}
					else{
						break;
					}
				}
				if (i == 4){
					cout << "You have been LOCKED!\n";
					temp.Handle(); //switch state to LOCK
					//temp.display();
					db->updateStudent(temp);
					system("PAUSE");
				}
				else{
					ofstream outFile;
					outFile.open("bid.txt", ios_base::app);

					//Check for Error
					if (outFile.fail()){
						cerr << "Error Opening File";
						exit(1);
					}
					outFile << endl << temp.getId() << " ";
					cout << "Hello " << temp.getName() << "!\nYou have " << temp.getPoints() << " points.\nAvailable courses:\n";
					vector<string> availableCourses;
					vector<string> vec = temp.getCompleteCourses();
					//check what courses the student didn't complete
					for (vector<Course>::size_type i = 0; i != C.size(); i++) {
						if (find(vec.begin(), vec.end(), C[i].getName()) == vec.end()){
							//if course has no pre courses, it's available anyway
							if (C[i].getPreCourses().empty() == 1){
								availableCourses.push_back(C[i].getName());
								cout << C[i].getName() << endl;
							}
							vector<string> pre = C[i].getPreCourses();
							//check if student finished all pre-courses of this course 
							for (vector<string>::size_type j = 0; j != pre.size(); j++) {
								if (find(vec.begin(), vec.end(), pre[j]) != vec.end()){
									availableCourses.push_back(C[i].getName());
									cout << C[i].getName() << endl;
								}
							}
						}
					}
					flag = 1;
					//get students bid and save to bid.txt file
					for (vector<Course>::size_type i = 0; i != C.size(); i++) {
						if (find(availableCourses.begin(), availableCourses.end(), C[i].getName()) != availableCourses.end()){
							while (flag){
								int bid;
								cout << "you have " << temp.getPoints() << " points left.\nwhat is your bid on course " << C[i].getName() << "?\n";
								cin >> bid;
								if (bid > temp.getPoints()){
									cout << "this is more points then you have..\n";
									cin.clear();
									cin.ignore(100, '\n');
								}
								else{
									outFile << bid << " ";
									temp.setPoints(temp.getPoints() - bid);
									break;
								}
							}
						}
						else{
							outFile << 0 << " ";
						}
					}
					//outFile << endl;
					cout << "your bid is in the system. Thank you!\n";
					db->updateStudent(temp);
				}
			}
			else{
				cout << "Sorry, your account is locked. please go to the secritary to unlock it.\n";
			}
		}//close case 3
			
		//calculate CourseBid
		case 2: R = new CalculateCourseBid("bid.txt"); break;
		
		
		case 3: {
		//veiw result
		}

		}//close switch
	}	
}