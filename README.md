# Rational-Number
This is just learning c++ classes.
Can you spot the mistake here?

//////////////////////////////////////////////////////////////
 Adding 2 rational numbers can work like this
 ````
RationalNumber RationalNumber::operator+(const RationalNumber &r) const {
	RationalNumber A;
	int a1 = this->a;
	int b1 = this->b;
	int a2 = r.a;
	int b2 = r.b;
             // a1/b1 + a2/b2    = > a1*b2 + a2*b1 / b1*b2;
	A.a = a1*b2 + a2*b1;
	A.b = b1*b2;
	return A;
}
RationalNumber RationalNumber::operator+(const int& integer) const {
	RationalNumber A;
	A.a = integer;
	A.b = 1;
	return *this + A;
}
RationalNumber RationalNumber::operator+(const double& decimal) const {
	RationalNumber A(decimal);
	return *this + A;
}
RationalNumber RationalNumber::operator+(const float& decimal) const {
	RationalNumber A(static_cast<double>(decimal));
	return *this + A;
}
````
//////////////////////////////////////////////////////////////////////
But, I am not getting the desired output from this function. The following is the debug window.
````
::::::::::::  Arithmetic Operators  :::::::::::::::
-----------------------------------------------------
(1/2)	+	(1/2)	=	(1/1)
(1/2)	+	3	=	(7/2)
3	+	(1/2)	=	(7/2)
(1/2)	+	0	=	(1/2)
3	+	(1/2)	=	(1/2)
(1/2)	+	4	=	(9/2)
3	+	(1/2)	=	(9/2)
-----------------------------------------------------
````
////////////////////////////////////////////////////////////////////

Below is the function I made to get this output.
````
void math_plus() {	
        RationalNumber a1 (1,2);
	RationalNumber sum = (a1 + a1);
	cout << a1 << "\t+\t" << a1 << "\t=\t" << sum << endl;

	int random = rand() % 10;
	sum = (a1 + random);
	cout << a1 << "\t+\t" << random << "\t=\t" <<  sum << endl;
	cout << random << "\t+\t" << a1 << "\t=\t" <<  sum << endl;

	double random2 = (rand() % 101) / 10;
	sum = (a1 + random2);
	cout << a1 << "\t+\t"<< random2 << "\t=\t" << sum << endl;
	cout << random << "\t+\t" << a1 << "\t=\t" <<  sum << endl;

	float random3 = (rand() % 101) / 10;
	sum = (a1 + random3);
	cout << a1 << "\t+\t" << random3 << "\t=\t" << sum << endl;
	cout << random << "\t+\t" << a1 << "\t=\t" <<  sum << endl;
}
````
////////////////////////////////////////////////////////////////////
