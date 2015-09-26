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
	//create factory
	StorageFactory* DBfactory = new StorageFactory();
	//Factory instantiating an object of type file_db
	IStorage* db = DBfactory->DataStorage(FILE_STORAGE, "data.txt");
	//init
	vector<Student> S = db->getStudentList();
	vector<Course> C = db->getCourseList();
	//
	CalculateCourseBid* R;



	for (;;){
		cout << "\nchoose a file:\n 1) input2_1.txt\n 2) input2_2.txt\n 3) Registration Terminal\n 4) Calculate CourseBid\n 5) Veiw CourseBid resutls\n";
		int x;
		cin >> x;
		switch (x){
		case 1: R = new CalculateCourseBid("input2_1.txt"); break;
		case 2: R = new CalculateCourseBid("input2_2.txt"); break;
		//Registration Terminal
		case 3: {
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
							cout<<temp.getPass();
							cout << "name: " <<temp.getName() <<endl;
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
						cout << "Hello " << temp.getName() << "!\nYou have " << temp.getPoints() << " points.\nAvailable courses:\n";
						vector<string> vec = temp.getCompleteCourses();
						for (vector<Course>::size_type i = 0; i != C.size(); i++) {
							if (find(vec.begin(), vec.end(), C[i].getName()) == vec.end()){
								vector<string> pre = C[i].getPreCourses();
								cout << C[i].getName() << endl;
								//add logic - check if student finished all pre-courses of a course 

							}
						}
						db->updateStudent(temp);
					}
				}else{
					cout << "Sorry, your account is locked. please go to the secritary to unlock it.\n";
				}
			}//close case 3
		}//close switch
	}	
}