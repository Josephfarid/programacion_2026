#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Estudiante {
private:
	string nombre;
	string codigo;
	int edad;
	float promedio;
	bool activo;
	
public:
	Estudiante(string n, string c, int e, float p, bool a) {
		nombre = n;
		codigo = c;
		edad = e;
		promedio = p;
		activo = a;
	}
	void actualizarNombre(string nuevoNombre) {
		nombre = nuevoNombre;
	}
	
	void actualizarCodigo(string nuevoCodigo) {
		codigo = nuevoCodigo;
	}
	
	void actualizarEdad(int nuevaEdad) {
		edad = nuevaEdad;
	}
	
	void actualizarPromedio(float nuevoPromedio) {
		if (nuevoPromedio >= 0.0 && nuevoPromedio <= 10.0) {
			promedio = nuevoPromedio;
		} else {
			cout << "Promedio invalido (debe estar entre 0.0 y 10.0)\n";
		}
	}
	
	void actualizarActivo(bool nuevoEstado) {
		activo = nuevoEstado;
	}
	
	void mostrarNombre() {
		cout << "Nombre: " << nombre << endl;
	}
	
	void mostrarCodigo() {
		cout << "Codigo: " << codigo << endl;
	}
	
	void mostrarEdad() {
		cout << "Edad: " << edad << " años" << endl;
	}
	
	void mostrarPromedio() {
		cout << "Promedio: " << promedio << endl;
	}
	
	void mostrarActivo() {
		cout << "Estado: " << (activo ? "Activo" : "Inactivo") << endl;
	}
	
	void mostrarInformacionCompleta() {
		cout << "----------------------------\n";
		mostrarNombre();
		mostrarCodigo();
		mostrarEdad();
		mostrarPromedio();
		mostrarActivo();
		cout << "----------------------------\n";
	}
	
	string getCodigo() {
		return codigo;
	}
};

int main() {
	vector<Estudiante> estudiantes;
	int opcion;
	
	do {
		cout << "\nMENU DEL PROGRAMA\n";
		cout << "1. Agregar estudiante\n";
		cout << "2. Mostrar un estudiante en especifico\n";
		cout << "3. Mostrar todos los estudiantes\n";
		cout << "4. Salir\n";
		cout << "Opcion: ";
		cin >> opcion;
		cin.ignore();
		
		if (opcion == 1) {
			string nombre, codigo;
			int edad;
			float promedio;
			bool activo;
			
			cout << "Nombre completo: ";
			getline(cin, nombre);
			
			cout << "Codigo: ";
			getline(cin, codigo);
			
			cout << "Edad: ";
			cin >> edad;
			
			cout << "Promedio (0.0 - 10.0): ";
			cin >> promedio;
			
			cout << "Activo (1 = Si, 0 = No): ";
			cin >> activo;
			cin.ignore();
			
			Estudiante nuevo(nombre, codigo, edad, promedio, activo);
			estudiantes.push_back(nuevo);
			
			cout << "Estudiante agregado correctamente.\n";
			
		} else if (opcion == 2) {
			string codigoBuscar;
			cout << "Ingrese el codigo del estudiante: ";
			getline(cin, codigoBuscar);
			
			bool encontrado = false;
			for (auto &e : estudiantes) {
				if (e.getCodigo() == codigoBuscar) {
					e.mostrarInformacionCompleta();
					encontrado = true;
					break;
				}
			}
			
			if (!encontrado) {
				cout << "Estudiante no encontrado.\n";
			}
			
		} else if (opcion == 3) {
			if (estudiantes.empty()) {
				cout << "No hay estudiantes registrados.\n";
			} else {
				for (auto &e : estudiantes) {
					e.mostrarInformacionCompleta();
				}
			}
			
		} else if (opcion == 4) {
			cout << "Saliendo del programa...\n";
		} else {
			cout << "Opcion invalida.\n";
		}
		
	} while (opcion != 4);
	
	return 0;
}
