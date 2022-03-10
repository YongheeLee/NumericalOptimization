#pragma once
#include <vector>

class LineSearchStep
{
private:
	static double func(double x_k)
	{
		double f = 0.01 * x_k * x_k * x_k * x_k - 0.03 * x_k * x_k * x_k - 0.45 * x_k * x_k + 0.3 * x_k - 1.0;
		return f;
	}

	static double derivFunc(double x_k)
	{
		double derivF = 0.04 * x_k * x_k * x_k - 0.09 * x_k * x_k - 0.9 * x_k + 0.3;
		return derivF;
	}

	static double findStepViaWolfeCondition(double x_k, double derivF)
	{
		double c1 = 0.1;
		double c2 = 0.5;

		double p_k = -derivF;
		double slop = -c2 * derivF * derivF;

		double step = 0.0;
		double x = 0.1;
		while (true)
		{
			//f(x_k+\alpha_kp_k)
			double f_x_ap = func(x_k + step * p_k);
			//f(x_k)+c_1\alpha_k\nabla f_k^Tp_k
			double f_x = func(x_k) + c1 * step * derivF * p_k;
			//\nabla f(x_k+\alpha_kp_k)^Tp_k
			double derF_p_k = derivFunc(x_k + step * p_k) * p_k;
			//$c_2\nabla f_k^Tp_k$
			double c2_derF_p_k = c2 * derivF * p_k;

			//Strong Condition
			derF_p_k = abs(derF_p_k);
			c2_derF_p_k = abs(c2_derF_p_k);


			if (f_x_ap > f_x || derF_p_k > c2_derF_p_k)
			{
				step += 0.01;
				continue;
			}
			else
				break;
		}

		return step;
	}

	static double nextX_k(double x_k)
	{
		double derivF = derivFunc(x_k);
		double p_k = -derivF;
		double stepLen = 0.01;// findStepViaWolfeCondition(x_k, derivF);

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