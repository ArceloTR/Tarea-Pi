// OpenMP header
#include <omp.h>
#include <cmath>
#include <iomanip>
#include <iostream>
 
int main()
{
    int n;
    std::cout<<"Ingrese la precision del calculo: ";
    std::cin>>n;
    double h = 1.0 / (double) n;
    double sum = 0.0;
 
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x*x));
    }    
 
    double pi = sum * h;
    std::cout << std::fixed << std::setprecision(50);
    std::cout << "El valor aproximado de PI es: " << pi << std::endl;
    return 0;
}