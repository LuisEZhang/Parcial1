#include <iostream>
#include <string>
#include <stdlib.h>
#include<time.h>
#include <vector>

using namespace std;

template <class ticket>
void mostrar(ticket info);
template <class tickets>
void almacenar(tickets info);

//User=12345 y Pass=54321
vector<string> dia_semana;
vector<string> mes;
string User="12345", Pass="54321", username, password, email, mess, nom, apell, carrera, id, npass1, npass2, cat;
int intentos, lin=1, o, c, sec=0, minutos=0, hr=0, entradas=1;
long info;
bool ingreso, activa, inactiva;
char matricula;

template <class tickets>
void almacenar(tickets info){
    cout << "Nombre: "<<nom<<endl; 
    cout << "Apellido: "<<apell<<endl; 
    cout << "Identificacion "<<id<<endl;
    cout << "Correo electronico: "<<email<<endl;
    cout << "Carrera que estudia: "<<carrera<<endl;
    cout << "Mensaje: "<<mess<<endl;
}

int main(){

    //Numero de ticket
    srand (time(0));
    const unsigned int cantTicket = 100;
    int numCant[cantTicket];
    for (int i = 0; i < cantTicket; i++){
        numCant[i] = rand();
    
    //Estado de Matricula
    if (matricula == inactiva){
        inactiva = false;
    }
    if (matricula == activa){
        activa = true;
    }

    //estado de matricula
    matricula=activa;

    //Hora y fecha
    time_t now = time(0);
    tm * time = localtime(&now);	
	
	//Dia de semana
	dia_semana.push_back("Domingo");
	dia_semana.push_back("Lunes");
	dia_semana.push_back("Martes");
	dia_semana.push_back("Miercoles");
	dia_semana.push_back("Jueves");
	dia_semana.push_back("Viernes");
	dia_semana.push_back("Sabado");
	
    //Mes
	mes.push_back("Enero");
	mes.push_back("Febero");
	mes.push_back("Marzo");
	mes.push_back("Abril");
	mes.push_back("Mayo");
	mes.push_back("Junio");
	mes.push_back("Julio");
	mes.push_back("Agosto");
    mes.push_back("Septiembre");
	mes.push_back("Octubre");
	mes.push_back("Noviembre");
	mes.push_back("Diciembre");
			
	
	int year = 1900 + time->tm_year;		
	cout<<"\t\t\t\t\t\t\t\t\t "<< dia_semana[time->tm_wday] << ", ";
	cout<<time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
	cout<<"\t\t\t\t\t\t\t\t\t "<< time->tm_hour << " : " << time->tm_min << " : " <<time->tm_sec << endl;
	
    //Sistema para Iniciar seccion
    login:
    do{
        cout << "\t\t\tIngreso de Estudiante"<<endl;
        cout << "\nUsername: ";cin>>username;
        cout << "\nPassword: ";cin>>password;
        cin.ignore();   
        if (username == User && password == Pass){
            ingreso = true;

        }else{
            cout << "Username o Password incorrecto favor de corregirlo y volver a intentarlo."<<endl;
            cout << "Presionar ENTER para volver a interntar."<<endl;
            intentos++;
            cin.get();
            system("cls");
            if (intentos < 5){
                goto login;
                cin.get();
                system("cls");
            }
        }
    } while (ingreso == false && intentos < 5);

    if (intentos >= 5){
        matricula=inactiva;
        goto f;
    }   

    //Intentos Logrado/fallidos
    if (ingreso == false && matricula == activa){
        cout << "\nMuchos intentos fallidos favor de esperar 1 minuto para volver a intentarlo."<<endl;
        goto login;
    
    }else if(ingreso == true && matricula == activa && intentos < 5){

        //Primer ingreso
        if (entradas==1){
            change:
            system("cls");
            cout << "Por ser primer ingreso usted debera de cambiar la contrasena."<<endl;
            cout << "\nFavor de ingresar nueva contrasena: "<< "\n\nPassword1: "<<endl; cin>>npass1;
            cout << "\nFavor de volver a ingresar nueva contrasena: "<< "\n\nPassword2: "<<endl; cin>>npass2;cin.ignore();
            system("cls");

            if (npass1 == npass2){
                Pass=npass1;
                entradas=2;
            }else{
                cout << "Ambas contraseña deben ser iguales."<<endl;
                goto change;
            }
            int year = 1900 + time->tm_year;	
	        cout<<"\t\t\t\t\t\t\t\t\t "<< dia_semana[time->tm_wday] << ", ";
	        cout<<time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
	        cout<<"\t\t\t\t\t\t\t\t\t "<< time->tm_hour << " : " << time->tm_min << " : " <<time->tm_sec << endl;
            cout << "Contrasena Cambiada."<<endl;
            cout << "Precionar ENTER para continuar"<<endl;
            cin.get();
            goto login;
        }
        menu:
        system("cls");
        cout << "\t\t\tBienvenido a la Plataforma de Estudiante."<<endl;
        cout << "Opciones: \n1: Subir un ticket \n2: Ver tickets \n3: Salir"<<endl;cin>>o;

    }else if (ingreso == true && matricula == inactiva && intentos >=5){
        f:
        system("cls");
        cout << "Usuario no valido."<<endl;
        cout << "Favor de enviar un ticket al adm para activar la cuenta"<<endl;
        cout << "\n1: para enviar ticket al adm. \n3: para salir."<<endl; cin>>o;


    }else if(ingreso == true && matricula == inactiva){
        cout << "Usuario no valido."<<endl;
        cout << "Precionar ENTER para continuar"<<endl;
        cin.get();
        goto login;
    }
    
    //Menu
    switch (o){
    case 1:
        system("cls");
        cout << "\nBienvenido al systema de ticket de la Universidad."<<endl;
        cout << "\nFavor de llenar los requisitos para su ticket."<<endl;
        cout << "\nNombre: "; cin>>nom; cout << "\nApellido: "; cin>>apell; 
        cout << "\nIdentificacion "; cin>>id;
        cout << "\nCorreo electronico: "; cin>>email;
        cout << "\nCarrera que estudia: "; cin>>carrera;
        cout << "\nCategoria de ticket: "; cin>>cat;cin.ignore();
        cout << "\nMensaje: "<<endl; getline(cin,mess);
        cout << "\n\nNumero de ticket: "<<"#"<<numCant[i]<<endl;
        goto seguir;
        system("cls");
        break;

    case 2:
        ticket:
        system("cls");
        cout << "Ver tickets."<<endl;
        cout << "Numero de ticket: "<<"#"<<numCant[i]<<endl;
        almacenar(info);
        cout << "Precionar ENTER para continuar"<<endl;
        cin.ignore();
        cin.get();
        goto menu;
        break;

    case 3:
        goto s; 
        break;
    }

    seguir:
    cout << "Desea ver los ticket? \nSi->1 \nNo->2"<<endl;
    cin >> c;
    system("cls");

    if (c==1){
        goto ticket;
    } else if (c==2){
        goto s;
    }
    }
    s:
    time_t now = time(0);
    tm * time = localtime(&now);
    int year = 1900 + time->tm_year;	
	cout<<"\t\t\t\t\t\t\t\t\t "<< dia_semana[time->tm_wday] << ", ";
	cout<<time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
	cout<<"\t\t\t\t\t\t\t\t\t "<< time->tm_hour << " : " << time->tm_min << " : " <<time->tm_sec << endl;
    cout << "Que tenga un buen dia."<<endl;

    return 0;
}