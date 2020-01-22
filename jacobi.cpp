#include "jacobi.h"
#include "timer.h"
#include <iostream>


result Jacobi::calculate(std::vector<std::vector<double>> A)
{
    Timer t;

    int n = A.size();
    //std::vector<double> N(n);
    //std::vector<std::vector<double>> M(n, std::vector<double> (n));

   /////////

	std::vector<double> m(n);
	std::vector<double> nn(n);

		//float a[10][10], b[10], m[10], n[10];
		int p = 0, q = 0, i = 0, j = 0;
		//cout << "Enter size of 2D array : ";
		//cin >> p;
		//for (i = 0; i < p; i++) {
		//	for (j = 0; j < p; j++) {
		/*		cout << "a[" << i << ", " << j << " ]=";
				cin >> a[i][j];
			}
		}
		cout << "\nEnter values to the right side of equation\n";
		for (i = 0; i < p; i++) {
			cout << "b[" << i << ", " << j << " ]=";
			cin >> b[i];
		}
		cout << "Enter initial values of x\n";
		for (i = 0; i < p; i++) {
			cout << "x:[" << i << "]=";
			cin >> m[i];
		}
		cout << "\nEnter the no. of iteration : ";
		cin >> q;*/
		q = mIteration;
		while (q > 0) {
			for (i = 0; i < n; i++) {
				nn[i] = (A[i][n] / A[i][i]);
				for (j = 0; j < n; j++) {
					if (j == i)
						continue;
					nn[i] = nn[i] - ((A[i][j] / A[i][i]) * m[j]);

				}
				//std::cout << "x" << i + 1 << "=" << nn[i] << " ";
			}

			for (int i = 0; i < p; i++)
				m[i] = nn[i];

			//std::cout << "\n";
			q--;
		}

		double time = t.elapsed();



	////////

    result output;
    output.solution = m;
    output.time = time;

    return output;



}
