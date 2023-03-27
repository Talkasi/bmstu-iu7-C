#include <stdio.h>
#include <math.h>
/*
Посчитать и вывести на экран в экспоненциальной форме сумму членов числовой последовательности:
\sum _ {i = 3} ^ {j : |a_j| < eps} a_i, 
a_i = (-1)**(2i - 1) * x**(i - 2) / (2 * (i + 2)! - (i + 1)!)
Вывести на экран до пятого знака после запятой с обязательной распечаткой знака значение функции f(x)=cos(arcsin(x)) в той же точке. Значения x и eps принимаются с клавиатуры.
*/
double my_sum(double x, double eps);

int main(void) {
	double x, eps;
	
	printf("Enter x: ");
	if (scanf("%lf", &x) != 1) {
		printf("Input x error\n");
		return 1;
	}
	
	printf("Enter eps: ");
	if (scanf("%lf", &eps) != 1) {
		printf("Input eps error\n");
		return 1;
	}
	
	double sum = my_sum(x, eps);
	
	printf("Sum: %.5e\n", sum);
	printf("F(x): %+.5e\n", cos(asin(x)));
	
	return 0;
}


double my_sum(double x, double eps) {
	int i = 3;
	double a_j = 1;
	
	while ((a_j > 0.0 ? a_j : -a_j) < eps) {
		a_j *= x * (2 * i + 3.0) / (i + 2.0) / (2 * i + 4.0);
		++i;
	}
	
	return a_j;
}
