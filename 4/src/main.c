#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// https://www.eolymp.com/en/problems/4
// https://planetcalc.ru/8098/
// https://www.eolymp.com/ru/problems/4/submissions
double calc_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    double d = calc_distance(x1, y1, x2, y2);
    if (d == 0 && r1 == r2) {
        printf("%d\n", -1);
        return 0;
    }

    if (d > r1 + r2 || fabs(r1 - r2) > d)
    {
        printf("%d\n", 0);
        return 0;
    }

    if (r1 + r2 == d || r1 * 2 == r2 || r2 * 2 == r1)
    {
        printf("%d\n", 1);
        return 0;
    }

    printf("%d\n", 2);
    return 0;
}