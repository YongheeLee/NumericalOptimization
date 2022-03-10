#pragma once
#include <vector>

class LineSearchIntro
{
private:
	static double nextX_k(double x_k)
	{
		double derivF = 0.04 * x_k * x_k * x_k - 0.09 * x_k * x_k - 0.9 * x_k + 0.3;
		double p_k = -derivF;
		double stepLen = 0.01;

		return x_k + p_k * stepLen;
	}

public:
	static double getSolve(double init_x)
	{
		double prev = init_x;

		std::vector<double> acc;
		while (true)
		{
			double next = nextX_k(prev);

			if (abs(prev - next) < 0.001)
				break;

			acc.push_back(prev);
			prev = next;
		}


		return prev;
	}
};