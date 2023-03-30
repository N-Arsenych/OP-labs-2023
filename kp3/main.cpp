#include"header.h"

int main() {
	
    int n;
    cout << "Enter the number of triangles: ";
    cin >> n;
    cout << "\n";
    
    Triangle* triangles = new Triangle[n];

    for (int i = 0; i < n; i++) {
        triangles[i] = get_Triangle(i);
    }
  
    int maxIndex = find_max_area(triangles, n);

    print_results(triangles, n, maxIndex);

    delete[] triangles;

	return 0;
}