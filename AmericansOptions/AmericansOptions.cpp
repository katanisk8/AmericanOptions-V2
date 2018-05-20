#include "stdafx.h"
#include <iostream>
#include "Calculator.h"

int main()
{
	bool defaultValues;
	double r;
	double sigma;
	double t;
	double K;
	double S;
	int k;
	int n;
	double T;

	std::cout << "Can i calculate using default values? 1 = Yes, 0 = No\r\n";
	std::cin >> defaultValues;
	
	if (defaultValues)
	{
		r = 0.05;
		sigma = 0.2;
		t = 1;
		K = 45;
		S = 45;
		k = 16;
		n = 4;
		T = 1;
	}
	else
	{
		std::cout << "Please enter risk free rate: ";
		std::cin >> r;
		std::cout << "Please enter volatility sigma: ";
		std::cin >> sigma;
		std::cout << "Please enter tau: ";
		std::cin >> t;
		std::cout << "Please enter strike price: ";
		std::cin >> K;
		std::cout << "Please enter stock price: ";
		std::cin >> S;
		std::cout << "Please enter number of iteration: ";
		std::cin >> k;
		std::cout << "Please enter number of nodes: ";
		std::cin >> n;
		std::cout << "Please enter time to maturity: ";
		std::cin >> T;
	}

	printf("\r\n");

	printf("Input data:\r\n");
	printf("Risk free rate = %f\r\n", r);
	printf("Volatility sigma = %f\r\n", sigma);
	printf("Tau = %f\r\n", t);
	printf("Strike price = %f\r\n", K);
	printf("Stock price = %f\r\n", S);
	printf("Number of iteration = %d\r\n", k);
	printf("Number of nodes = %d\r\n", n);
	printf("Time to maturity = %f\r\n", T);

	printf("\r\n");

	printf("Results:\r\n");
	Calculator calc;
	auto results = calc.Calculate(r, sigma, t, K, S, k, n, T);

	for (auto itr = results.begin(); itr != results.end(); ++itr)
	{
		printf("k=%d  Bt=%f  P=%f\r\n", (*itr).ResultNumber, (*itr).BtRoundedValue, (*itr).PutRoundedValue);
	}

	printf("\r\n");
	system("pause");

	return 0;
}
