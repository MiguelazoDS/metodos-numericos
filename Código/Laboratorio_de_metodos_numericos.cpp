#include<iostream>
#include<cmath>

using namespace std;

double funcion(double);
void biseccion (double, double, double, int);

    double diam;
    const double diammax = 40;
    double vol;
    double volmax;
    const double pi = 3.1415926;
    double a, b, c;
    double tol;
    double radio;
    int itermax;
    int iter;
    double interin;
    int opcion;
    
int main()
{   
    cout <<"Este programa determinara la altura de liquido dentro de un recipiente esferico" << endl;
    cout << "\nIngrese un diametro para el recipiente en metros " << endl;
    cout << "\n";
    cin  >>  diam;
    
if (diam < 0 || diam > diammax)
    
    do
    { 
       cout << "\nValor negativo o muy grande ingrese un valor positivo y menor o igual que " << diammax << endl;
       cin >> diam; 
    }
         
    while (diam < 0 || diam > diammax);
    
    radio = diam/2;
    
    cout << "\nEl diametro de la esfera es " << diam << " metro/s" << endl;
    
    volmax = (4*pi/3)* pow(diam,3)/8;
    
    cout << "\nEl volumen maximo permitido es " << volmax << " metros cubicos" << endl;
    cout << "\nIngrese un valor de volumen en metros cubicos " << endl;
    cout << "\n";
    
    cin >> vol;

if (vol < 0 || vol > volmax)   
    
    do
    { 
        cout << "\nValor negativo incorrecto o demasiado grande "  << endl; 
        cout << "\ningrese un volumen positivo menor que " << volmax << endl;
        cout << "\n";
        
        cin >> vol;
    }
  
    while(vol < 0 || vol > volmax);

    cout << "\nEl volumen ingresado es " << vol << " metros cubicos" << endl; 
    cout << "\nLa altura (h) correspondiente a ese volumen es la raiz positiva y menor que " << diam << endl;
    cout << "\nde la ecuacion: " << endl; 
    cout << "\nf(h)=h^3-3rh^2+3*" << vol << "/pi" <<  endl;
    cout << "\nSiendo (r) el radio de la esfera " << endl;
    cout << "\n";
    
    system ("pause");
    
    cout << "\nIngrese valores para el intervalo que encierra la raiz " << endl;
    cout << "\nEl limite inferior debe ser mayor o igual a 0 " << endl;
    cout << "\ny el limite superior debe ser menor o igual que " << diam << endl;
    
do
{
    cout << "\nRecuerde que los valores deben encerrar la raiz " << endl;
    cout << "\n";
    cin >> a;
    cout << "\n";
    cin >> b;
    
if(a<0 || b<0 || a>diam || b>diam || a==b)

{
   do
   {

     cout << "\nLos valores ingresados son incorrectos, no ingrese valores negativos, " << endl;
     cout << "\niguales entre si y/o mayores a " << diam << endl;
     cout << "\nIngrese nuevamente los valores " << endl;
     cout << "\n";
     cin >> a;
     cout << "\n";
     cin >> b;
   }

    while (a<0 || b<0 || a>diam || b>diam || a==b);
}

if(a<b)

    cout << "\nEl intervalo ingresado es [" << a << "," << b << "]" << endl;

    else
    {
      c=b;
      b=a;
      a=c;

      cout << "\nEl intervalo ingresado es [" << a << "," << b << "]" << endl;
      
      }
}

while(funcion(a)*funcion(b)>0.0);

cout << "\nIngrese un valor de tolerancia (tol) " << endl;
cin >> tol;  
    
if (tol<0)
    
    do
    {
       cout << "\nIngrese un numero positivo " << endl;
       cout << "\n";
       cin >> tol; 
    }
    
    while(tol<0);
    
    cout << "\nLa tolerancia es " << tol << endl;
    
    interin = b-a;

    itermax =  int((log(interin/tol)/log(2))+1);

    cout << "\nLa cantidad de iteraciones necesarias son " << itermax << endl;
    cout << "\nPresione (1) si desea restringir el numero de iteraciones " << endl;
    cout << "\n";
    cin >> opcion;
    
if  (opcion==1)  
{
cout << "\nIngrese un nuevo valor de iteraciones " << endl;
cout << "\n";

do 
{ 
  cout << "\nEl valor ingresado debe ser mayor a cero y menor o igual que " << itermax << endl;
  cout << "\n";   
  cin >> iter;
  }
  
while(iter <= 0 || iter > itermax);

itermax=iter;
    
cout << "\nEl programa finalizara al llegar a las " << itermax << " iteraciones" << endl;   
}

else

cout << "\nEl programa finalizara al llegar a las " << itermax << " iteraciones" << endl; 
cout << "\n";

system("pause");


biseccion(a, b, tol, itermax);

cout << "\n";    

system("pause");

return 0;

}


void biseccion(double a, double b, double tol, int itermax)
{
int i;

double x1, x2, x3;
double f1, f2, f3;

double ancho_it;

cout << "\nel intervalo inicial es "<< interin << endl;

x1 = a;
x3 = b;
f1 = funcion(x1);
f3 = funcion(x3);


for(i=0; i < itermax; i++)
{
  x2 = (x1 + x3)/2.0;
  f2=funcion(x2);       
         
  if(f1 * f2 < 0.0)
  {
   ancho_it =(x2-x1)/2.00;     
   f3 = f2;
   x3 = x2;
   
  }
  
  else
  {
   ancho_it =(x3-x2)/2.00;
   f1 = f2;
   x1 = x2;
  }
  
  if(abs(ancho_it) < tol)
  {
   cout << "\nSe encontro una raiz en X= " << x2 << endl;           
   cout << "\nSe realizaron "<< i << " iteraciones " << endl;
   cout << "\nLa funcion valuada en " << x2 << " es igual a " << f2 << endl;
 
   return;
   }
}

cout << "\nNo se encontro ninguna raiz en " << itermax << " iteraciones" << endl;
cout << "\nque cumplan con el criterio de convergencia" << endl; 

return;    
     
}
       
double funcion(double x)

{ 
   double f;
   
   f = pow(x,3)-3*radio*pow(x,2)+3*vol/pi;
  
return f;
}
