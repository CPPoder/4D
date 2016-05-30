#ifndef MYUSEFULMATH_HPP
#define MYUSEFULMATH_HPP

namespace myMath {

	float max(float num1, float num2);
	int max(int num1, int num2);
	unsigned int max(unsigned int num1, unsigned int num2);

	float min(float num1, float num2);
	int min(int num1, int num2);
	unsigned int min(unsigned int num1, unsigned int num2);

	float meanValue(float num1, float num2);

	int randIntervali(int small, int big);

	float randIntervalf(int small, int big);

	int abs(int value);
	float abs(float value);

	int sign(int value);
	float sign(float value);


}



#endif