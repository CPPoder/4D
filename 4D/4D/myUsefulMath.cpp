#include "stdafx.h"
#include "myUsefulMath.hpp"
#include <cstdlib>

namespace myMath {

	float myMath::max(float num1, float num2)
	{
		if (num1 > num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
	int myMath::max(int num1, int num2)
	{
		if (num1 > num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}
	unsigned int myMath::max(unsigned int num1, unsigned int num2)
	{
		if (num1 > num2)
		{
			return num1;
		}
		else
		{
			return num2;
		}
	}

	float myMath::min(float num1, float num2)
	{
		if (num1 > num2)
		{
			return num2;
		}
		else
		{
			return num1;
		}
	}
	int myMath::min(int num1, int num2)
	{
		if (num1 > num2)
		{
			return num2;
		}
		else
		{
			return num1;
		}
	}
	unsigned int myMath::min(unsigned int num1, unsigned int num2)
	{
		if (num1 > num2)
		{
			return num2;
		}
		else
		{
			return num1;
		}
	}


	float myMath::meanValue(float num1, float num2)
	{
		return ((num1 + num2) / 2.f);
	}

	
	int myMath::randIntervali(int small, int big)
	{
		return (rand() % (big - small + 1) + small);
	}

	float myMath::randIntervalf(int small, int big)
	{
		return static_cast<float>(myMath::randIntervali(small, big));
	}

	int myMath::abs(int value)
	{
		if (value < 0)
		{
			return (-value);
		}
		else
		{
			return value;
		}
	}

	float myMath::abs(float value)
	{
		if (value < 0)
		{
			return (-value);
		}
		else
		{
			return value;
		}
	}

	int myMath::sign(int value)
	{
		if (value < 0)
		{
			return (-1);
		}
		else
		{
			return 1;
		}
	}

	float myMath::sign(float value)
	{
		if (value < 0)
		{
			return (-1.f);
		}
		else
		{
			return 1.f;
		}
	}

}