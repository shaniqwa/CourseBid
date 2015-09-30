#include "stdafx.h"
#include "CppUnitTest.h"
#include "IStorage.h"
#include "file_storage.h"
#include "StorageFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StorageFactoryTest
{		
	TEST_CLASS(StorageFactoryTest)
	{
	public:
		
		TEST_METHOD(DataStorage)
		{
			struct StorageMock : public IStorage {
				virtual vector<Student>& getStudentList() {
					vector<Student> s;
					return s;
				}
				virtual vector<Course>& getCourseList(){
					vector<Course> c;
					return c;
				}
				virtual void updateStudent(Student s) throw(exception){

				}
				virtual void updateCourse(Course s){

				}
			}storageMock;


			class StorageFactory {
			public:
				void useObject(IStorage & object) {
					object.getStudentList();
				}
			};

			StorageFactory toTest;

			toTest.useObject(storageMock);
		}

	};
}