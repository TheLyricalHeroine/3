class CVector1 : public CVector {
	public:
	
	CVector1();
	CVector1(vector<double> v1, int len1, string FileName1);
	CVector1(int len2);
	CVector1(const CVector& other);
	
	using CVector::operator=;
	
	
	void output();
	
};
