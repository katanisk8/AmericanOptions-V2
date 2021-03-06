#include "stdafx.h"
#include "BtCalculator.h"
#include "BtIntegralFunction.h"
#include "IntegralPoints.h"

double BtCalculator::CalculateBtK_1(double sigma, double K, double dist, double d1, double r, double tau, double d2)
{
	double a = (1 / sigma * Math::Sqrt(2 * Math::PI * tau));

	return (K * (1 / (dist + a * Math::Exp(-0.5 * Math::Pow(d1, 2))))) *
		(a * Math::Exp(-((r * tau) + (0.5 * Math::Pow(d2, 2))))) +
		(((2 * sigma * r) / ((2 * r) + (Math::Pow(sigma, 2))) * (2 * dist) - 1));
}

double BtCalculator::CalculateBt(double sigma, double K, double dist, double d1, double r, double t, double d2, int n, double T)
{
	double a = (1 / sigma * Math::Sqrt(2 * Math::PI * t));
	double integralFunction = BtIntegralFunction().Calculate(n, T, r, sigma, t, d2);

	return (1 / (dist + a * Math::Exp(-0.5 * Math::Pow(d1, 2)))) *
		(a * K * Math::Exp(-((r * t) + (0.5 * Math::Pow(d2, 2))))) +
		(r * K * integralFunction);
}

double BtCalculator::CalculateBtK1(double r, double sigma, double t, double K, double S, int n, double T)
{
	double integralPointD1 = IntegralPoints().CalculateIntegralPointD1(K, K, r, sigma, t);
	double integralPointD2 = IntegralPoints().CalculateIntegralPointD2(integralPointD1, sigma, t);
	double distribution = Math::Cdf(integralPointD1);

	return CalculateBtK_1(sigma, K, distribution, integralPointD1, r, t, integralPointD2);
}

double BtCalculator::CalculateBtK(double r, double sigma, double t, double K, double S, int n, double T, double BtK_1)
{
	double integralPointD1 = IntegralPoints().CalculateIntegralPointD1(BtK_1, K, r, sigma, t);
	double integralPointD2 = IntegralPoints().CalculateIntegralPointD2(integralPointD1, sigma, t);
	double distribution = Math::Cdf(integralPointD1);

	return CalculateBt(sigma, K, distribution, integralPointD1, r, t, integralPointD2, n, T);
}
