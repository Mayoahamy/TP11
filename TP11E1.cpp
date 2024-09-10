#include <iostream>
#include <cstring>
#include <vector>
#include <windows.h>
#include <algorithm>
using namespace std;
class Alumno {
private:
     string nombre;
     int edad;
     double nota1;
     double nota2;
     double nota3;
     bool pass;
public:
     // Constructor
     Alumno(string nombre, int edad, double nota1, double nota2, double nota3, bool pass)
     : nombre(nombre), edad(edad), nota1(nota1), nota2(nota2), nota3(nota3), pass(pass) {}
     // Getters
     string getNombre() const { return nombre; }
     int getEdad() const { return edad; }
     double getNota1() const { return nota1; }
     double getNota2() const { return nota2; }
     double getNota3() const { return nota3; }
     bool getPass() const { return pass; }
     // Método para calcular el promedio
     double calcularPromedio() const { return (nota1 + nota2 + nota3)/ 3; }
     // Nota mas alta
     double topNota() const{
     	vector<double> notas = {nota1,nota2,nota3};
     	sort(notas.begin(),notas.end());
     	return notas[2];
	 }
	double menorNota() const{
     	vector<double> notas = {nota1,nota2,nota3};
     	sort(notas.begin(),notas.end());
     	return notas[0];
	 }
};
int main() {
 // Vector para almacenar los alumnos
 vector<Alumno> alumnos;
// Ingresar datos de los alumnos y agregarlos al vector
 string nombre,buscar,low,low2,buscar2;
 int edad,suma;
 double nota1, nota2, nota3, prom;
 int numAlumnos;
 cout << "Ingrese el numero de alumnos: ";
 cin >> numAlumnos;
 for (int i = 0; i < numAlumnos; i++) {
     cout << "Ingrese el nombre del alumno: ";
     cin >> nombre;
     cout << "Ingrese la edad del alumno: ";
     cin >> edad;
     cout << "Ingrese la nota 1 del alumno: ";
     cin >> nota1;
     cout << "Ingrese la nota 2 del alumno: ";
     cin >> nota2;
     cout << "Ingrese la nota 3 del alumno: ";
     cin >> nota3;
     if((nota1+nota2+nota3)/3>=7){
     	alumnos.push_back(Alumno(nombre, edad, nota1, nota2, nota3, true));
	 }
	 else{
	 	alumnos.push_back(Alumno(nombre, edad, nota1, nota2, nota3, false));
	 }
}
system("cls");
for(const auto& alumno : alumnos){
	suma+=alumno.getNota1();
	suma+=alumno.getNota2();
	suma+=alumno.getNota3();
}
prom=(float)suma/((alumnos.size()*3));
cout<<"El promedio general de los alumnos es: "<<prom<<endl;
// Ingresar nombre a buscar
cout<<"Ingresar nombre a buscar: ";
cin>>buscar;
//lowcap
for(int i=0;i<buscar.size();i++){
	buscar2.push_back(tolower(buscar[i]));
}
// Busca y muestra
for(const auto& alumno : alumnos){
	low=alumno.getNombre();
	low2.clear();
	//lowcap
	for(int i=0;i<low.size();i++){
		low2.push_back(tolower(low[i]));
	}
	if(buscar2==low2){
		system("cls");
		cout << "Nombre: " << alumno.getNombre() << endl;
	    cout << "Edad: " << alumno.getEdad() << endl;
	    cout << "Nota 1: " << alumno.getNota1() << endl;
	    cout << "Nota 2: " << alumno.getNota2() << endl;
	    cout << "Nota 3: " << alumno.getNota3() << endl;
	    cout << "Nota mas alta: " << alumno.topNota() << endl;
		cout << "Nota mas baja: " << alumno.menorNota() << endl;
	    cout << "Promedio: " << alumno.calcularPromedio() << endl;
	    if(alumno.getPass()==true){
	        cout << "Aprobado: Si" << endl;
		}else{
		 	cout << "Aprobado: No" << endl;
		}
	}
}return 0;
}