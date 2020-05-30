//#include "class.hpp"
//#include "func.hpp"

//#include "func.hpp"
#include "factory.hpp"
#include "factory0.hpp"
#include "factory1.hpp"
#include "class0.hpp"
#include "class1.hpp"


vector<CVector*> ReadFile()
{
	//cout<<"hello, you are in readfile"<<endl;
	//int flag = 0;
	CVector0Factory Hori;
	CVector1Factory Vert;
	
	map<string, Factory*> factories_ = { 
	{"Hori",&Hori},
	{"Vert",&Vert} 
	};
	
	ifstream in("in.txt");
	if (!in)
	{
		cout << "file error" << endl;
		//flag = 1;
	}
	
	vector<CVector*> arr;
	arr.reserve(256);
	/*if (flag == 0)
	{*/
		//cout<<"hello, you are in if"<<endl;
		double m;
		string I;
		int len;
		string str;
		while (!in.eof())
		{
			//cout<<"hello, you are in while"<<endl;
			//vector<double> num{};
			vector<double> num;
			in >> I;
			in >> str;
			in >> len;
			for (int i = 0; i < len; i++)
			{
				//cout<<"hello, you are in for"<<endl;
				in >> m;
				num.push_back(m);
			}
			//cout<<"step_4"<<endl;
			
			auto resFactory = factories_[I];
			auto newVector = resFactory->Create();
			newVector->v = num;
			newVector->len = len;
			newVector->FileName = str;
			arr.push_back(newVector);
			//num.clear();
		}
	//}
	factories_.clear();
	return arr;
}




CVector0 operator+(CVector& first, CVector& second)
{
	time_t time1, time2;
	time(&time1);
	CVector0 result;
	result.v = first.v;
	result.v.reserve(first.len);
	if (first.len != second.len)
	{	
		cout<<"векторы разной длины"<<endl;
	}
	
	else
	{
#pragma omp parallel for
		for (int i = 0; i < first.len; i++)
		{
			result.v[i] = first.v[i] + second.v[i];
		}
		
		result.len = first.len;
		result.FileName = first.FileName;
	}
	time(&time2);
	cout<<"work time of operator+ is "<<(double) (time2-time1)<<" ms"<<endl;
	return result;
}

CVector0 operator-(CVector& first, CVector& second)
{
	time_t time1, time2;
	time(&time1);
	CVector0 result;
	result.v = first.v;
	result.v.reserve(first.len);
	
	if (first.len != second.len)
	{
		cout<<"векторы разной длины"<<endl;
	}
	
	else
	{
#pragma omp parallel for
		for (int i = 0; i < first.len; i++)
		{
			result.v[i] = first.v[i] - second.v[i];
		}
		
		result.len = first.len;
		result.FileName = first.FileName;
	}
	time(&time2);
	cout<<"work time of operator- is "<<(double) (time2-time1)<<" ms"<<endl;
	return result;
}


void autotest1() 
{
	cout<<"Test 1: сложение1"<<endl;
    string FileName = "test.txt";
    vector<double> a1 = {1.1, -2.2, 3.3};
    vector<double> b1 = {1.1, 2.2, 3.3};
    
    CVector0 a(a1, 3, FileName);
    CVector0 b(b1, 3, FileName);
    CVector0 c = a + b;
	
	//cout<<a1.v[1]<<endl;
	c.Show();
	
    if ((c.v[0]==2.2) && (c.v[1]==0) && (c.v[2]==6.6) 
		&& (c.FileName == "test.txt") && (c.len == 3)) 
		{
			cout << "Test 1: OK!" << endl << "" << endl;
			//c.Show();
		}
		else 
		{
			cout << "Test 1: FAILED!" << endl << "" << endl;
			//c.Show();
		}
}



void autotest2() 
{
    
	cout<<"Test 2: вычитание1"<<endl;
	string FileName = "test.txt";
    vector<double> a1 = {1.1, -2.2, 3.3,0};
    vector<double> b1 = {1.1, 2.2, 3.2};
	
	//cout<< "hi, you are unlucky_2" << endl;
    
    CVector0 a(a1, 3, FileName);
    CVector0 b(b1, 3, FileName);
    CVector1 c;
	
	c = a - b;
	
	//cout<<a.v[1]<<endl;
	c.Show();
	int flag = 0;
	for (int i = 0; i < c.len; i++) 
		if (c.v[i] == 0, -4.4, 0.1) flag++;
	
	if (flag==3)
    //if ((c.v[0] == 0) && (c.v[1] == -4.4) && (c.v[2] == 0.1) 
		//&& (c.FileName == "test.txt") && (c.len == 3)) 
		{
			cout << "Test 2: OK!" << endl << "" << endl;
		}
	else 
		{
			cout << "Test 2: FAILED!" << endl << "" << endl;
		}
}

void autotest3() 
{
    cout<<"Test 3: сложение2"<<endl;
	string FileName = "test.txt";
    vector<double> a1 = {1.1, -2.2, 3.3};
    vector<double> b1 = {1.1, 2.2, 3.2};
    
    CVector1 a(a1, 3, FileName);
    CVector1 b(b1, 3, FileName);
    CVector0 c = a + b;
	
	//cout<<a1.v[1]<<endl;
	c.Show();
	
    if ((c.v[0] == 2.2) && (c.v[1] == 0) && (c.v[2] == 6.5) 
		&& (c.FileName == "test.txt") && (c.len == 3)) 
		{
			cout << "Test 3: OK!" << endl << "" << endl;
		}
		else 
		{
			cout << "Test 3: FAILED!" << endl << "" << endl;
		}
}


void autotest4() 
{
    cout<<"Test 4: скалярное умножение"<<endl;
	string FileName = "test.txt";
    vector<double> a1 = {1.1, -2.2, 3.3};
    vector<double> b1 = {1.5, 2.5, 3.5};
    
	//cout<< "hi, you are unlucky_4" << endl;
	
    CVector1 a(a1, 3, FileName);
    CVector0 b(b1, 3, FileName);
    double c = a * b;
	
	cout<<"c="<<c<<endl;
	
    if ((c>=7.7)||(c<=7.7))
	{
		cout<< "Test 4: OK!" << endl << "" << endl;
	}
	else
	{
		cout<< "Test 4: FAILED!"<<endl << "" << endl;
	}
}

void autotest5() 
{
    
	cout<<"Test 5: вычитание2"<<endl;
	string FileName = "test.txt";
    vector<double> a1 = {1.1, -2.2, 3.3};
    vector<double> b1 = {1.1, 2.2, 3.2};
	
	//cout<< "hi, you are unlucky_2" << endl;
    
    CVector1 a(a1, 3, FileName);
    CVector1 b(b1, 3, FileName);
    CVector0 c;
	
	c = a - b;
	
	//cout<<a.v[1]<<endl;
	c.Show();
	int flag = 0;
	for (int i = 0; i < c.len; i++) 
		if (c.v[i] == 0, -4.4, 0.1) flag++;
	
	if (flag==3)
    //if ((c.v[0] == 0) && (c.v[1] == -4.4) && (c.v[2] == 0.1) 
		//&& (c.FileName == "test.txt") && (c.len == 3)) 
		{
			cout << "Test 5: OK!" << endl << "" << endl;
		}
	else 
		{
			cout << "Test 5: FAILED!" << endl << "" << endl;
		}
}

void OpenMPTest()
{
	cout<<"OpenMPTest"<<endl;
	
	string FileName = "test.txt";
	vector<double> a1;
	vector<double> b1;
	for (int i = 0; i < 20000000; i++)
	{
		a1.push_back(1.1);
		b1.push_back(1.1);
	}
	
	CVector0 a(a1, 20000000, FileName);
	CVector1 b(b1, 20000000, FileName);
	CVector0 c;
	
	c = a + b;
	
}
		



