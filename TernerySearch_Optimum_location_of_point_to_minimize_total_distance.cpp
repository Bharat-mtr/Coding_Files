#include <bits/stdc++.h>
using namespace std;

#define sq(x) ((x) * (x))
#define eps 1e-6

struct point
{
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y)
    {
    }
};

struct line
{
    int a, b, c;
    line(int a, int b, int c) : a(a), b(b), c(c)
    {
    }
};

double distance(double x, double y, point p)
{
    return sqrt(sq(x - p.x) + sq(y - p.y));
}

double computeTotalDist(point points[], int n, line l, double X)
{
    double Y = -1 * (l.c + l.a * X) / l.b;

    double d = 0;
    for (int i = 0; i < n; i++)
    {
        d += distance(X, Y, points[i]);
    }
    return d;
};
double computeOptimumDist(point points[], int n, line l)
{
    double high = 1e6; //??
    double low = -1e6; //??

    while ((high - low) > eps)
    {
        // cout << "cod while" << endl;
        double mid1 = low + (high - low) / 3;
        double mid2 = high - (high - low) / 3;

        double d1 = computeTotalDist(points, n, l, mid1);
        double d2 = computeTotalDist(points, n, l, mid2);

        if (d1 < d2)
            high = mid2;
        else
            low = mid1;
    }

    return computeTotalDist(points, n, l, (low + high) / 2); // ??
};

int main()
{
    int n;
    cin >> n;
    int x, y;
    point points[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        points[i] = point(x, y);
        // cout << "main loop" << endl;
    }
    int a, b, c;
    cin >> a >> b >> c;
    line l(a, b, c);

    cout << computeOptimumDist(points, n, l);
}