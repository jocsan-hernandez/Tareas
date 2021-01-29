//Un programa que haga diversas operaciones de fracciones
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
//Estructura de fraccion
 struct fraccion{
     int numerador;
     int denominador;
 };

 //Para simplificar podemos calcular el maximo comun divisor del numerador y denominador y luego dividir ambos entre el
 int mcd(fraccion *f){
     //Por defecto va a ser uno
     int maxcomdiv= 1;
     int a= max(f->numerador, f->denominador);
     for (int i=2; i<= a; i++){
         if(((f->numerador%i)==0)&& (f->denominador%i)==0){
             maxcomdiv=i;
         }
     }
     return maxcomdiv;
 }
 //Finalmente para simplificar dividimos
 void simplificaFraccion(fraccion *f){
    int mx;
    mx= mcd(f);
    f->denominador= f->denominador/mx;
    f->numerador=f->numerador/mx;
 }
//Funcion para crear las fracciones
 void crearFraccion(fraccion *f, int numerador, int denominador){
     f->numerador= numerador;
     f->denominador= denominador;
 }
//Una funcion que imprima fracciones
 void imprimirFraccion(fraccion *f){
     simplificaFraccion(f);
     cout<< f->numerador<< "/"<<f->denominador<<endl;
 }
//Una funcion para la suma de fracciones
 fraccion sumaFraccion(fraccion *f1, fraccion *f2){
     fraccion suma;
     suma.numerador= f1->numerador*f2->denominador+f1->denominador*f2->numerador;
     suma.denominador= f1->denominador*f2->denominador;
     simplificaFraccion(&suma);
     return suma;
 }
 //Una funcion para la multiplicacion de fracciones
 fraccion productoFraccion(fraccion *f1, fraccion*f2){
     fraccion producto;
     producto.numerador= f1->numerador*f2->numerador;
     producto.denominador= f1->denominador*f2->denominador;
     simplificaFraccion(&producto);
     return producto;
 }

 //Una funcion que reste fracciones
 fraccion restaFraccion(fraccion *sumando, fraccion *restando){
     //Vamos a suponer que es f1-f2
     fraccion resta,f2;
     crearFraccion(&f2, - restando->numerador, restando->denominador);
     resta=sumaFraccion(sumando, &f2);
     simplificaFraccion(&resta);
     return resta;
 }


int main()
{
    fraccion f1,f2,f3;
    crearFraccion(&f1,15,6);
    crearFraccion(&f2,4,3);
    f3= sumaFraccion(&f2,&f1);
    imprimirFraccion(&f3);
    return 0;
}

