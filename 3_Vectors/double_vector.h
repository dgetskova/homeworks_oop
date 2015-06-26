class DoubleVector
{
private:
	double* array;
	int size;

	void DoubleVector::allocate(int new_size);
	void DoubleVector::free(DoubleVector&);

	void DoubleVector::toSize(const DoubleVector& other);
	DoubleVector operator-() const;

public:
	void print()const;
	bool is_in_bound(unsigned int index)const;

	DoubleVector();
	~DoubleVector();
	DoubleVector(const DoubleVector& other);
	DoubleVector& operator=(const DoubleVector& other);
	DoubleVector(int size_value, double* value);

	double operator[](int index);

	DoubleVector  operator + (const DoubleVector& other)const;
	DoubleVector& operator +=(const DoubleVector& other);

	DoubleVector operator -(const DoubleVector& other)const;
	DoubleVector& operator -=(const DoubleVector& other);
	
	DoubleVector  operator *(int number)const;
	DoubleVector& operator*=(int number);
	
	DoubleVector operator /(int number)const;
	DoubleVector& operator/=(int number);

	double operator %(const DoubleVector&);
};