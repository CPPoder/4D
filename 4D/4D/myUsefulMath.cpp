#include "stdafx.h"
#include "myUsefulMath.hpp"
#include <cstdlib>

namespace myMath {

	float max(float num1, float num2)
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
	int max(int num1, int num2)
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
	unsigned int max(unsigned int num1, unsigned int num2)
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

	float min(float num1, float num2)
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
	int min(int num1, int num2)
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
	unsigned int min(unsigned int num1, unsigned int num2)
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


	float meanValue(float num1, float num2)
	{
		return ((num1 + num2) / 2.f);
	}


	int randIntervali(int small, int big)
	{
		return (rand() % (big - small + 1) + small);
	}

	float randIntervalf(int small, int big)
	{
		return static_cast<float>(myMath::randIntervali(small, big));
	}

	int abs(int value)
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

	float abs(float value)
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

	int sign(int value)
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

	float sign(float value)
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
