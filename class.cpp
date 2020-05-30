#include "class.hpp"

CVector::CVector() = default;
CVector::~CVector() = default;

CVector::CVector(int len2)
{
	
	for (int i=0; i < len2; i++)
	{
		this -> v[i]=0;
	}
	
	this -> len=len2;
	FileName = ""; 
}

CVector::CVector(vector<double> v1, int len1, string FileName1)
{
	
	for (int i = 0; i < len1; i++)
	{
		v.push_back(v1[i]);
	}
	
	this -> len = len1;

	FileName = FileName1;
	//FileName.insert(0,FileName1);
}

CVector::CVector(const CVector& other)
{
	
	for (int i = 0; i < other.len; i++)
	{
		this -> v.push_back(other.v[i]);
	}
	
	this -> len = other.len;
	
	FileName = other.FileName;
}

double CVector::operator* (const CVector& other) //можно прописать здесь
{
	
	//time_t time1, time2;
   // time(&time1);
	double result = 0;
	if (len != other.len)
	{
		cout<<"векторы разной длины"<<endl;
	}
	else
	{
		auto start = chrono::system_clock::now();
#pragma omp parallel for
		for (int i = 0; i < len; i++)
		{
			result += v[i]*(double(other.v[i]));
		}
	}
	//time(&time2);
	
	auto end = chrono::system_clock::now();
	int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
        cout << "work time of operator* is : " << (double) (end - start)<<" ms" << endl;
	return result;
}

CVector& CVector::operator= (const CVector& other)
{
	this -> len=other.len;
	FileName = other.FileName;
	
	for (int i = 0; i < len; i++)
	{
		this -> v.push_back(other.v[i]);
	}
	
	return *this;
}

void CVector::Show()
{
	cout<<"(";
	for (int i = 0; i < len; i++)
	{
		cout<<v[i];
		if (i!=len-1) {cout<<",";}
	}
	cout<<")"<<endl;
}
		

//CVector& operator+ (const CVector& other);
//CVector& operator- (const CVector& other);
