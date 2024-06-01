#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <conio.h> 
#include <vector>
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

//#include <SFML/Audio.hpp>

using namespace std;
int menuing();
int menu(){
	int x;
	cout<<"**********TRADUCTOR************"<<endl;
	cout<<"1.Interfaz de Espanol a Ingles"<<endl;
	cout<<"2.Interfaz de Espanol a Aleman"<<endl;
	cout<<"3.Interfaz de Espanol a Italiano"<<endl;
	cout<<"4.Interfaz de Espanol a Frances"<<endl;
	cout<<"5.PARA SALIR DEL PROGRAMA"<<endl;
	cout<<"Ingrese alguna de las Opciones disponibles"<<endl;
    /*cout<<"2.VerHoja"<<endl;*/
	cin>>x;
	return x;
}

void buscarPalabraA(ifstream &Lec) {
	string letras1[54]={"a","A","e","E","i","I","o","O","u","U","b","c","d","f","g","h","j","k","l","m","n","ñ","p","q","r","s","t","v","w","x","y","z","B","C","D","F","G","H","J","K","L","M","N","Ñ","P","Q","R","S","T","V","W","X","Y","Z"};
	string letras2[54]={"U1","U1","U2","U2","U3","U4","U4","U4","U5","U5","m1","m2","m3","m4","m5","m6","m7","m8","m9","m10","m11","m12","m13","m14","m15","m16","m17","m18","m19","m20","m21","m22","g1","g2","g3","g4","g5","g6","g7","g8","g9","g10","g11","g12","g13","g14","g15","g16","g17","g18","g19","g20","g21","g22"};
	system("cls");
	Lec.open("Aleman.txt", ios::in);
	string esp, ale, espaux, nueva, nueva2, nueva3;
	int no, pos;
	char cadena[50];
	bool encontrado = false;
	cout<<"***TRADUCTOR DE ESPANOL A ALEMAN***"<<endl;
	cout<<" "<<endl;
	cout<<"Digite la palabra que desee traducir: ";
	cin>>espaux;
	Lec>>esp;
	while(!Lec.eof() && !encontrado){
		Lec>>ale;
		if(esp == espaux){
			cout<<"ESPANOL      |     ALEMAN"<<endl;
			cout<<""<<esp<<"    |     "<<ale<<endl;
					
					std::string frase=esp;
					std::string frase2=ale;
					std::string command = "espeak \"" + frase + "\""+frase2;
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    
					encontrado = true;	 
			
					strcpy(cadena, espaux.c_str());
					no = strlen(cadena);
			    	cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva2 = cadena[cont];
					if (letras1[con]==nueva2){
					nueva = nueva+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra: "<<nueva<<endl;    
			
					strcpy(cadena, ale.c_str());
					no = strlen(cadena);
			    	cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva3 = cadena[cont];
					if (letras1[con]==nueva3){
					nueva2 = nueva2+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Aleman: "<<nueva2<<endl;                          
		}
		Lec>>esp;
	}
	Lec.close();
	if(!encontrado)
	cout<<"Palabra no encontrado"<<endl;
	system("pause");		
}

bool verificar(string Esp){
	ifstream leer("Aleman.txt", ios::in);
	string esp;
	string ale;
	leer>>esp;
	while(!leer.eof()){
		leer>>ale;
		if(esp==Esp){
			cout<<"La palabra ya existe en el diccionario anteriormente"<<endl;
			leer.close();
			return false;
		}
		leer>>esp;
	}
	cout<<"La palabra fue agregada correctamente"<<endl;
	leer.close();
	return true;
	
}
void agregarale(ofstream &esc){
	system("cls");
	string esp;
	string ale;
	esc.open("Aleman.txt", ios::out | ios::app);
	cout<<"Palabra en espanol"<<endl;
	cin>>esp;
	cout<<"Traduccion en Aleman"<<endl;
	cin>>ale;
	if(verificar(esp))
	esc<<esp<<" "<<ale<<endl;
	esc.close();
	system("pause");
}
void eliminarale(ifstream &lec){
	system("cls");
	string esp;
	string ale;
	string espaux;
	
	lec.open("Aleman.txt", ios::in);
	ofstream aux("auxiliar2.txt", ios::out);
	if(lec.is_open()){
		cout<<" Palabra: ";
		cin>>espaux;
		lec>>esp;
		while(!lec.eof()){
			lec>>ale;
			if(esp == espaux){
				cout<<"Palabra eliminada correctamente";
				Sleep(1500);
			}else{
				aux<<esp<<" "<<ale<<"\n";
			}
			lec>>esp;
		}
		lec.close();
		aux.close();
	}else
		cout<<"La palabra que desea eliminar no se encuentra en la base"<<endl;
		remove("Aleman.txt");
		rename("auxiliar2.txt", "Aleman.txt");
}

void buscarPalabraIn(ifstream &Lec) {
	string letras1[54]={"a","A","e","E","i","I","o","O","u","U","b","c","d","f","g","h","j","k","l","m","n","ñ","p","q","r","s","t","v","w","x","y","z","B","C","D","F","G","H","J","K","L","M","N","Ñ","P","Q","R","S","T","V","W","X","Y","Z"};
	string letras2[54]={"U1","U1","U2","U2","U3","U4","U4","U4","U5","U5","m1","m2","m3","m4","m5","m6","m7","m8","m9","m10","m11","m12","m13","m14","m15","m16","m17","m18","m19","m20","m21","m22","g1","g2","g3","g4","g5","g6","g7","g8","g9","g10","g11","g12","g13","g14","g15","g16","g17","g18","g19","g20","g21","g22"};
	system("cls");
	Lec.open("Espanol.txt", ios::in);
	string esp, ing, espaux, nueva, nueva2, nueva3;
	int no, pos;
	char cadena[50];
	bool encontrado = false;
	cout<<"***TRADUCTOR DE ESPANOL A INGLES***"<<endl;
	cout<<" "<<endl;
	cout<<"Digite la palabra que desee traducir: ";
	cin>>espaux;
	Lec>>esp;
	while(!Lec.eof() && !encontrado){
		Lec>>ing;
		if(esp == espaux){
			cout<<"ESPANOL      |     INGLES"<<endl;
			cout<<""<<esp<<"    |     "<<ing<<endl;
			
			
			
					std::string frase=esp;
					std::string frase2=ing;
					std::string command = "espeak \"" + frase + "\""+frase2;
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    
			encontrado = true;
					
					strcpy(cadena, espaux.c_str());
					no = strlen(cadena);
					cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva2 = cadena[cont];
					if (letras1[con]==nueva2){
					nueva = nueva+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Espanol: "<<nueva<<endl;
			
					strcpy(cadena, ing.c_str());
					no = strlen(cadena);
			    	cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva3 = cadena[cont];
					if (letras1[con]==nueva3){
					nueva2 = nueva2+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Ingles: "<<nueva2<<endl;
		}
		Lec>>esp;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"Palabra no encontrado"<<endl;
	system("pause");	
}
bool verificar2(string Esp){
	ifstream leer("Espanol.txt", ios::in);
	string esp;
	string ing;
	leer>>esp;
	while(!leer.eof()){
		leer>>ing;
		if(esp==Esp){
			cout<<"La palabra ya existe en el diccionario anteriormente"<<endl;
			leer.close();
			return false;
		}
		leer>>esp;
	}
	cout<<"La palabra fue agregada correctamente"<<endl;
	leer.close();
	return true;
	
}
void agregaring(ofstream &esc){
	system("cls");
	string esp;
	string ing;
	esc.open("Espanol.txt", ios::out | ios::app);
	cout<<"Palabra en Espanol"<<endl;
	cin>>esp;
	cout<<"Traduccion en Ingles"<<endl;
	cin>>ing;
	if(verificar2(esp))
	esc<<esp<<" "<<ing<<endl;
	esc.close();
	system("pause");
}
void eliminaring(ifstream &lec){
	system("cls");
	string esp;
	string ing;
	string espaux;
	
	lec.open("Espanol.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(lec.is_open()){
		cout<<" Palabra: ";
		cin>>espaux;
		lec>>esp;
		while(!lec.eof()){
			lec>>ing;
			if(esp == espaux){
				cout<<"Palabra eliminada correctamente";
				Sleep(1500);
			}else{
				aux<<esp<<" "<<ing<<"\n";
			}
			lec>>esp;
		}
		lec.close();
		aux.close();
	}else
		cout<<"La palabra que desea eliminar no se encuentra en la base"<<endl;
		remove("Espanol.txt");
		rename("auxiliar.txt", "Espanol.txt");
}
/*
void PalabraMB(ofstream &esc){
	system("cls");
	string esp;
	string ing;
	esc.open("Espanol20.txt", ios::out | ios::app);
	if(buscarPalabraIn(Lec))
	esc<<esp<<" "<<ing<<endl;
	esc.close();
	system("pause");
}*/
/*void Verhoja(ifstream &Lec){
	string esp, ing ;
	
	Lec.open("espanol20.txt", ios::in);
	Lec>>esp;
	while(!Lec.eof()){
		Lec>>ing;
		cout<<"Espanol------: "<<esp<<endl;
		cout<<"Ingles-------: "<<ing<<endl;
		Lec>>esp;
	}
	Lec.close();
	system("pause");
*/
void buscarPalabraI(ifstream &Lec) {
	string letras1[54]={"a","A","e","E","i","I","o","O","u","U","b","c","d","f","g","h","j","k","l","m","n","ñ","p","q","r","s","t","v","w","x","y","z","B","C","D","F","G","H","J","K","L","M","N","Ñ","P","Q","R","S","T","V","W","X","Y","Z"};
	string letras2[54]={"U1","U1","U2","U2","U3","U4","U4","U4","U5","U5","m1","m2","m3","m4","m5","m6","m7","m8","m9","m10","m11","m12","m13","m14","m15","m16","m17","m18","m19","m20","m21","m22","g1","g2","g3","g4","g5","g6","g7","g8","g9","g10","g11","g12","g13","g14","g15","g16","g17","g18","g19","g20","g21","g22"};
	system("cls");
	Lec.open("Italiano.txt", ios::in);
	string esp, ita, espaux, nueva, nueva2, nueva3;
	int no, pos;
	char cadena[50];
	bool encontrado = false;
	cout<<"***TRADUCTOR DE ESPANOL A ITALIANO***"<<endl;
	cout<<" "<<endl;
	cout<<"Digite la palabra que desee traducir: ";
	cin>>espaux;
	Lec>>esp;
	while(!Lec.eof() && !encontrado){
		Lec>>ita;
		if(esp == espaux){
			cout<<"ESPANOL      |     ITALIANO"<<endl;
			cout<<""<<esp<<"    |     "<<ita<<endl;
			
					std::string frase=esp;
					std::string frase2=ita;
					std::string command = "espeak \"" + frase + "\""+frase2;
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    
					encontrado = true;
					
					strcpy(cadena, espaux.c_str());
					no = strlen(cadena);
					cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva2 = cadena[cont];
					if (letras1[con]==nueva2){
					nueva = nueva+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Espanol: "<<nueva<<endl;
			
					strcpy(cadena, ita.c_str());
					no = strlen(cadena);
			    	cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva3 = cadena[cont];
					if (letras1[con]==nueva3){
					nueva2 = nueva2+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Italiano: "<<nueva2<<endl;
		}
		Lec>>esp;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"Palabra no encontrado"<<endl;
	system("pause");	
}
bool verificar3(string Esp){
	ifstream leer("Italiano.txt", ios::in);
	string esp;
	string ita;
	leer>>esp;
	while(!leer.eof()){
		leer>>ita;
		if(esp==Esp){
			cout<<"La palabra ya existe en el diccionario anteriormente"<<endl;
			leer.close();
			return false;
		}
		leer>>esp;
	}
	cout<<"La palabra fue agregada correctamente"<<endl;
	leer.close();
	return true;
	
}
void agregarita(ofstream &esc){
	system("cls");
	string esp;
	string ita;
	esc.open("Italiano.txt", ios::out | ios::app);
	cout<<"Palabra en espanol"<<endl;
	cin>>esp;
	cout<<"Traduccion en italiano"<<endl;
	cin>>ita;
	if(verificar3(esp))
	esc<<esp<<" "<<ita<<endl;
	esc.close();
	system("pause");
}
void eliminarita(ifstream &lec){
	system("cls");
	string esp;
	string ita;
	string espaux;
	
	lec.open("Italiano.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(lec.is_open()){
		cout<<" Palabra: ";
		cin>>espaux;
		lec>>esp;
		while(!lec.eof()){
			lec>>ita;
			if(esp == espaux){
				cout<<"Palabra eliminada correctamente";
				Sleep(1500);
			}else{
				aux<<esp<<" "<<ita<<"\n";
			}
			lec>>esp;
		}
		lec.close();
		aux.close();
	}else
		cout<<"La palabra que desea eliminar no se encuentra en la base"<<endl;
		remove("Italiano.txt");
		rename("auxiliar.txt", "Italiano.txt");
}


void buscarPalabraF(ifstream &Lec) {
	string letras1[54]={"a","A","e","E","i","I","o","O","u","U","b","c","d","f","g","h","j","k","l","m","n","ñ","p","q","r","s","t","v","w","x","y","z","B","C","D","F","G","H","J","K","L","M","N","Ñ","P","Q","R","S","T","V","W","X","Y","Z"};
	string letras2[54]={"U1","U1","U2","U2","U3","U4","U4","U4","U5","U5","m1","m2","m3","m4","m5","m6","m7","m8","m9","m10","m11","m12","m13","m14","m15","m16","m17","m18","m19","m20","m21","m22","g1","g2","g3","g4","g5","g6","g7","g8","g9","g10","g11","g12","g13","g14","g15","g16","g17","g18","g19","g20","g21","g22"};
	system("cls");
	Lec.open("Frances.txt", ios::in);
	string esp, fra, espaux, nueva, nueva2, nueva3;
	int no, pos;
	char cadena[50];
	bool encontrado = false;
	cout<<"***TRADUCTOR DE ESPANOL A FRANCES***"<<endl;
	cout<<" "<<endl;
	cout<<"Digite la palabra que desee traducir: ";
	cin>>espaux;
	Lec>>esp;
	while(!Lec.eof() && !encontrado){
		Lec>>fra;
		if(esp == espaux){
			cout<<"ESPANOL      |     FRANCES"<<endl;
			cout<<""<<esp<<"    |     "<<fra<<endl;
			
					std::string frase=esp;
					std::string frase2=fra;
					std::string command = "espeak \"" + frase + "\""+frase2;
                    const char* charCommand = command.c_str();
                    system(charCommand);
                    
					encontrado = true;
					
					strcpy(cadena, espaux.c_str());
					no = strlen(cadena);
					cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva2 = cadena[cont];
					if (letras1[con]==nueva2){
					nueva = nueva+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Espanol: "<<nueva<<endl;
			
					strcpy(cadena, fra.c_str());
					no = strlen(cadena);
			    	cout<<"Longitud de la palabra: "<<no<<endl;
					for (int cont=0;cont<no;cont++){	
					for(int con=0;con<54;con++){
					nueva3 = cadena[cont];
					if (letras1[con]==nueva3){
					nueva2 = nueva2+letras2[con];
				}
			  }
			}
			cout<<"Codigo de cada letra en Frances: "<<nueva2<<endl;
		}
		Lec>>esp;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"Palabra no encontrado"<<endl;
	system("pause");	
	
}
bool verificar4(string Esp){
	ifstream leer("Frances.txt", ios::in);
	string esp;
	string fra;
	leer>>esp;
	while(!leer.eof()){
		leer>>fra;
		if(esp==Esp){
			cout<<"La palabra ya existe en el diccionario anteriormente"<<endl;
			leer.close();
			return false;
		}
		leer>>esp;
	}
	cout<<"La palabra fue agregada correctamente"<<endl;
	leer.close();
	return true;
	
}
void agregarfra(ofstream &esc){
	system("cls");
	string esp;
	string fra;
	esc.open("Frances.txt", ios::out | ios::app);
	cout<<"Palabra en espanol"<<endl;
	cin>>esp;
	cout<<"Traduccion en frances"<<endl;
	cin>>fra;
	if(verificar(esp))
	esc<<esp<<" "<<fra<<endl;
	esc.close();
	system("pause");
}
void eliminarfra(ifstream &lec){
	system("cls");
	string esp;
	string fra;
	string espaux;
	
	lec.open("Frances.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(lec.is_open()){
		cout<<" Palabra: ";
		cin>>espaux;
		lec>>esp;
		while(!lec.eof()){
			lec>>fra;
			if(esp == espaux){
				cout<<"Palabra eliminada correctamente";
				Sleep(1500);
			}else{
				aux<<esp<<" "<<fra<<"\n";
			}
			lec>>esp;
		}
		lec.close();
		aux.close();
	}else
		cout<<"La palabra que desea eliminar no se encuentra en la base"<<endl;
		remove("Frances.txt");
		rename("auxiliar.txt", "Frances.txt");
}
/*
void Verhoja(ifstream &Lec){
	string esp, ing ;
	
	Lec.open("espanol.txt", ios::in);
	Lec>>esp;
	while(!Lec.eof()){
		Lec>>ing;
		cout<<"Espanol------: "<<esp<<endl;
		cout<<"Ingles-------: "<<ing<<endl;
		Lec>>esp;
	}
	Lec.close();
	system("pause");
}*/

int main(){
	ifstream Lec;
	ofstream esc;
	vector<string> usuarios;
    vector<string> claves;

    usuarios.push_back("Adan");
    usuarios.push_back("Jorge");
    usuarios.push_back("Brayan");
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
    	char caracter;
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO"<<endl;
        cout << "\t\t\t----------------"<<endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);
        cout << "\tPassword: ";
        caracter = getch();
        password = "";

        while (caracter != ENTER)
        {
            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }else{
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }
        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }if (!ingresa){
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }
        
	} while (ingresa == false && contador < INTENTOS);
    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. " << endl;
    }else{
        cout << "\n\n\tBienvenido al Traductor de Palabras" << endl;
    }
    cin.get();

	int op;
	int op2;
	do{
		system("cls");
		op = menu();
		switch(op){
			case 1: {
				system("cls");
				int ops;
				cout<<"********** TRADUCTOR EN INGLES ************"<<endl;
				cout<<"1.Traductor de espanol a Ingles"<<endl;
				cout<<"2.Ingresar palabra nueva al traductor"<<endl;
				cout<<"3.Ingrese palabra para eliminar"<<endl;
				cout<<"Ingrese alguna de las opciones Disponibles"<<endl;
				cout<<" "<<endl;
				cin>>ops;
					switch(ops){
						case 1:
							buscarPalabraIn(Lec);
						break;
						case 2:
							agregaring(esc);
						break;
						case 3:
							eliminaring(Lec);
						break;		
						default:
						cout<<"Dato mal ingresados"<<endl;	
					}
				}	
				break;	
			case 2:{
				system("cls");
				int ops;
				cout<<"**********TRADUCTOR EN ALEMAN************"<<endl;
				cout<<"1.Traductor de Espanol a Aleman"<<endl;
				cout<<"2.Ingresar palabra nueva al traducir"<<endl;
				cout<<"3.Ingrese palabra para eliminar"<<endl;
				cout<<"Ingrese alguna de las opciones Disponibles"<<endl;
				cout<<" "<<endl;
				cin>>ops;
					switch(ops){
						case 1:
							buscarPalabraA(Lec);
						break;
						case 2:
							agregarale(esc);
						break;
						case 3:
							eliminarale(Lec);
						break;	
						default:
						cout<<"Dato mal ingresados"<<endl;	
					}
				}
				
				break;
			case 3:{
				system("cls");
				int ops;
				cout<<"**********TRADUCTOR EN ITALIANO************"<<endl;
				cout<<"1.Traductor de Espanol a Italiano"<<endl;
				cout<<"2.Ingresar palabra nueva al traducir"<<endl;
				cout<<"3.Ingrese palabra para eliminar"<<endl;
				cout<<"Ingrese alguna de las opciones Disponibles"<<endl;
				cout<<" "<<endl;
				cin>>ops;
					switch(ops){
						case 1:
							buscarPalabraI(Lec);
						break;
						case 2:
							agregarita(esc);
						break;
						case 3:
							eliminarita(Lec);
						break;		
						default:
						cout<<"Dato mal ingresados"<<endl;	
					}
				}
			break;
			case 4:{
				system("cls");
				int ops;
				cout<<"**********TRADUCTOR EN FRANCES************"<<endl;
				cout<<"1.Traductor de Espanol a frances"<<endl;
				cout<<"2.Ingresar palabra nueva al traducir"<<endl;
				cout<<"3.Ingrese palabra para eliminar"<<endl;
				cout<<"Ingrese alguna de las opciones Disponibles"<<endl;
				cout<<" "<<endl;
				cin>>ops;
					switch(ops){
						case 1:
							buscarPalabraF(Lec);
						break;
						case 2:
							agregarfra(esc);
						break;
						case 3:
							eliminarfra(Lec);
						break;		
						default:
						cout<<"Dato mal ingresados"<<endl;	
					}
				}
			break;	
			}
	}while(op !=5);
	
	cout <<"ENTER PARA SALIR DEL PROGRAMA";
	return 0;
}
