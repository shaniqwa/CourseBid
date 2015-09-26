#include "CalculateCourseBid.h"

CalculateCourseBid::CalculateCourseBid(string file_name){

	Lp lp;
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
	

	//vet init
	vector<Lp::Col> v(m*n);
	for (int i = 0; i < m*n; ++i){
		v[i] = lp.addCol();
		lp.colLowerBound(v[i], 0);
		lp.colUpperBound(v[i], 1);
	}

	for (int j = 0; j < n; ++j){
		int Lj;
		inFile >> Lj;
		//build expr
		Lp::Expr e1;
		for (int i = 0; i < m; ++i){
			e1 += v[i*n+j];
		}
		Lp::Constr c;
		c = e1 <= Lj;
		lp.addRow(c);
	}

	Lp::Expr expr;
	for (int i = 0; i < m*n; ++i){
		int Cij;
		inFile >> Cij;
		//build obj expr
		expr += Cij*v[i];
	}

	lp.max();
	lp.obj(expr);
	lp.solve();

	//print result
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			cout << lp.primal(v[i*n+j]) <<"   ";
		}
		cout << endl;
	}
}