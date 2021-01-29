//El siguiente programa va a encontrar la raiz
//de una ecuacion trascendental usando Newton Raphson

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
//Variables globales, quiza la tolerancia
double TOL=0.0001;
//Funcion a la que le queremos encontrar una raiz
double Funcion(double x){
  double fx_n= 3*exp(x)-7*x;
  return fx_n;
}
//Funcion que calcula el valor de la derivada
double Derivada(double x){
  double fdx_n= 3*exp(x)-7;
  return fdx_n;
}
//Newton Raphson
double Newton_Raphson(double (*funcion)(double), double (*derivada)(double), double punto){
  //barrera para que no siga de forma infinita
      int contador=0;
        while (true){
          punto= punto- funcion(punto)/derivada(punto);
          contador+=1;
          if (abs(funcion(punto))<TOL or contador==10000){
            break;
          }
        }
        cout<<"Despues de "<<contador<<" iteraciones "<<endl;
        return punto;
}
int main(){
  double (*punteroFuncion)(double);
  double (*punteroDerivada)(double);
  punteroFuncion= Funcion;
  punteroDerivada= Derivada;
  cout<< "El resultado es: "<<Newton_Raphson(punteroFuncion, punteroDerivada,0);

  return 0;
}
