#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono> // Para medir tiempos de ejecución

using namespace std;

struct Point {
    double x, y;
};

// Función para calcular la distancia euclidiana entre dos puntos
double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Comparadores para ordenar por coordenadas x y y
bool compareX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool compareY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

// Fuerza bruta para encontrar la distancia mínima en un conjunto pequeño de puntos
double bruteForce(vector<Point> &points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

// Encontrar la distancia mínima en la banda
double stripClosest(vector<Point> &strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }
    return minDist;
}

// Algoritmo de divide y vencerás para encontrar la distancia mínima
double closestUtil(vector<Point> &points, int left, int right) {
    if (right - left + 1 <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = left + (right - left) / 2;
    double dl = closestUtil(points, left, mid);
    double dr = closestUtil(points, mid + 1, right);

    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if (abs(points[i].x - points[mid].x) < d) {
            strip.push_back(points[i]);
        }
    }

    return min(d, stripClosest(strip, d));
}

// Función principal para encontrar la distancia mínima
double closest(vector<Point> &points) {
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1);
}

// Generar puntos aleatorios
vector<Point> generatePoints(int n) {
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = {rand() % 10000, rand() % 10000};
    }
    return points;
}

// Main para ejecutar las pruebas
int main() {
    vector<int> testCases = {10, 100, 1000, 10000, 100000};
    for (int n : testCases) {
        vector<Point> points = generatePoints(n);

        auto start = chrono::high_resolution_clock::now();
        double minDist = closest(points);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;

        cout << "Para n = " << n << ", la distancia mínima es: " << minDist 
             << ", tiempo de ejecución: " << duration.count() << " segundos." << endl;
    }

    return 0;
}
