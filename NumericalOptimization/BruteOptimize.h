#pragma once


class BruteOptimize
{
public: 
	static bool optimize(double &optX1, double &optX2)
	{
		double infinite = 1e+20;

		optX1 = infinite;
		optX2 = infinite;

		double minObject = infinite;
		for (int x1 = -100; x1 < 100; ++x1)
		{
			for (int x2 = -100; x2 < 100; ++x2)
			{
				double object = (x1 - 2.0) * (x1 - 2.0) + (x2 - 1.0) * (x2 - 1.0);

				if (x1 * x1 - x2 <= 0 && x1 + x2 <= 2.0)
				{
					if (object < minObject)
					{
						minObject = object;
						optX1 = x1;
						optX2 = x2;
					}
				}
			}
		}

		if (optX1 == infinite || optX2 == infinite)
			return false;

		return true;
	}
};

