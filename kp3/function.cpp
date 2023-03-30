#include"header.h"

Triangle get_Triangle(int index) {
    float x, y;
    cout << "Enter first point of triangle " << index + 1 << ": ";
    cin >> x >> y;
    Point p1(x, y);
    cout << "Enter second point of triangle " << index + 1 << ": ";
    cin >> x >> y;
    Point p2(x, y);
    cout << "Enter third point of triangle " << index + 1 << ": ";
    cin >> x >> y;
    Point p3(x, y);
    cout << "\n";
    return Triangle(p1, p2, p3);
}

int find_max_area(Triangle* triangles, int n) {
    int maxIndex = 0;
    float maxSq = triangles[0].square();

    for (int i = 1; i < n; i++) {
        float sq = triangles[i].square();
        if (sq > maxSq) {
            maxSq = sq;
            maxIndex = i;
        }
    }

    return maxIndex;
}

void print_results(Triangle* triangles, int n, int maxIndex) {
    for (int i = 0; i < n; i++) {
        float sq = triangles[i].square();
        cout << "Area of triangle " << i + 1 << ": " << sq << endl;
    }

    cout << "\nTriangle " << maxIndex + 1 << " has the largest area: " << triangles[maxIndex].square() << endl;
}