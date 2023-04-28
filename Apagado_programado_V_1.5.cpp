#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int opcion,mins,UserHour=3600,UserMin=60,UserHoursel,UserMinsel,UserTimemix;
void menu();
void ConfirmShutdown(int confirm){

	switch(confirm){
				case 1:
					system("scriptedSH.bat");
					menu();
					break;
				case 2:
					
					cout<<"El archivo quedo guardado con el tiempo que me ha indicado."<<endl;
					system("pause");
					system("cls");
					menu();
					break;
				default:
					cout<<"Opcion incorrecta."<<endl;
					ConfirmShutdown(confirm);
					break;
				}
				
}
void modificarDobleEleccion(int time,int user_time_selection,int user_time_selection2){
	int confirm=0;
	ofstream fileEscr;
	fileEscr.open("scriptedSH.bat",ios::out);
		if(fileEscr.is_open()==true){
			if(user_time_selection<=0){
						if(user_time_selection==0){
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en 0 horas, no hare nada. Hubiese sido mejor seleccionar solo minutos..."<<endl;
							exit(1);
						}
						else{
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en tiempo negativo, no hare nada."<<endl;
							exit(1);
						}
					}
						else{
							if(user_time_selection==1){
								cout<<"El computador se apagara en "<<user_time_selection<<" hora";
						}
						else{
							cout<<"El computador se apagara en "<<user_time_selection<<" horas";
							}
						}
					if(user_time_selection2<=0){
						if(user_time_selection2==0){
							fflush(stdin);
							//cout<<", desea continuar? 1:SI 2:NO."<<endl;
							//cin>>confirm;
						}
						else{
							fflush(stdin);
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en minutos negativos, solo considerare las horas que me indico, desea continuar? 1:SI 2:NO"<<endl;
							cin>>confirm;
						}
					}
						else{
							if(user_time_selection2==1){
								//fflush(stdin);
								cout<<" y "<<user_time_selection2<<" minuto."<<endl;
								//cin>>confirm;
						}
						else{
							//fflush(stdin);			//, desea continuar? 1:SI 2:NO
							cout<<" y "<<user_time_selection2<<" minutos."<<endl;
							//cin>>confirm;
							}
						}
			fileEscr<<"shutdown -s -t "<<time<<endl;
			fileEscr.close();
			cout<<"el valor en segundos es: "<<time<<", en minutos: "<<time/60<<" y en horas: "<<(time/60)/60<<"."<<endl;
			//system("pause");
			fflush(stdin);
			cout<<"\n AL ELEGIR ESTO SE PROGRAMARA EL APAGADO DE SU PC, PROCEDA CON CUIDADO.\n 		Desea apagar el sistema con el tiempo especificado? \n		digite 1 para SI, 2 para NO "<<endl;
			cin>>confirm;
			ConfirmShutdown(confirm);
		}
		else{
			cout<<"ERROR! El archivo no pudo abrirse."<<endl;
			exit(1);
			}
	return;
}
void modificar(int time,int user_time_selection,int opcion_menu){
	int confirm=0;
	ofstream fileEscr;
	fileEscr.open("scriptedSH.bat",ios::out);
		if(fileEscr.is_open()==true){
			switch(opcion_menu){
				case 1:{
					if(user_time_selection<=0){
						if(user_time_selection==0){
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en 0 horas, no hare nada."<<endl;
							exit(1);
						}
						else{
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en tiempo negativo, no hare nada."<<endl;
							exit(1);
						}
					}
					else{
						if(user_time_selection==1){
							cout<<"El computador se apagara en "<<user_time_selection<<" hora."<<endl;
							}
						else{
							cout<<"El computador se apagara en "<<user_time_selection<<" horas."<<endl;
							}
						fileEscr<<"shutdown -s -t "<<time<<endl;
						}
					break;
				}
				case 2:{
					if(user_time_selection<=0){
						if(user_time_selection==0){
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en 0 minutos, no hare nada."<<endl;
							exit(1);
						}
						else{
							cout<<"Su opcion no tiene sentido, me ha indicado que apague su pc en tiempo negativo, no hare nada."<<endl;
							exit(1);
						}
					}
						else{
							if(user_time_selection==1){
								cout<<"El computador se apagara en "<<user_time_selection<<" minuto."<<endl;
						}
						else{																//, desea continuar? 1:SI 2:NO
							cout<<"El computador se apagara en "<<user_time_selection<<" minutos."<<endl;
							}
							fileEscr<<"shutdown -s -t "<<time<<endl;
						}
					break;
				}
				case 4:{
					fileEscr<<"shutdown -a"<<endl;
					system("scriptedSH.bat");
					menu();
					break;
				}
			}
			//fileEscr<<"shutdown -s -t "<<time<<endl;
			fileEscr.close();
			cout<<"el valor en segundos es: "<<time<<", en minutos: "<<time/60<<" y en horas: "<<(time/60)/60<<"."<<endl;
			system("pause");
			fflush(stdin);
			cout<<"\n AL ELEGIR ESTO SE PROGRAMARA EL APAGADO DE SU PC, PROCEDA CON CUIDADO.\n 		Desea apagar el sistema con el tiempo especificado? \n		digite 1 para SI, 2 para NO "<<endl;
			cin>>confirm;
			ConfirmShutdown(confirm);
		}
		else{
			cout<<"ERROR! El archivo no pudo abrirse."<<endl;
			exit(1);
			}
	return;
}
void menu(){
	system("cls");
	cout<<"|   indicame en cuanto tiempo quieres apagar el pc.   |"<<endl;
	cout<<"|            1 para ingresar horas                    |"<<endl;
	cout<<"|            2 para ingresar minutos                  |"<<endl;
	cout<<"|            3 si desea hora y minutos                |"<<endl;
	cout<<"|            4 ABORTAR APAGADO PROGRAMADO             |"<<endl;
	cout<<"|_____________________________________________________|"<<endl;
	cin>>opcion;
	switch(opcion){
		case 1:{
			fflush(stdin);
			cout<<"En cuantas horas mas desea apagar el computador?"<<endl;
			cin>>UserHoursel;
			UserHour=UserHour*UserHoursel;
			modificar(UserHour,UserHoursel,opcion);
			break;
		}
		case 2:{
			fflush(stdin);
			cout<<"En cuantos minutos mas desea apagar el computador?"<<endl;
			cin>>UserMinsel;
			UserMin=UserMin*UserMinsel;
			modificar(UserMin,UserMinsel,opcion);
			break;
		}
		case 3:{
			fflush(stdin);
			cout<<"En cuantas horas mas desea apagar el computador?"<<endl;
			cin>>UserHoursel;
			UserHour=UserHour*UserHoursel;
			fflush(stdin);
			cout<<"En cuantos minutos mas desea apagar el computador?"<<endl;
			cin>>UserMinsel;
			UserMin=UserMin*UserMinsel;
			UserTimemix=UserHour+UserMin;
			modificarDobleEleccion(UserTimemix,UserHoursel,UserMinsel);
			break;
		}
		case 4:{
			modificar(0,0,opcion);
			break;
		}
	}
	menu();
		}
int main() {
	cout<<"|~~~~~~~~~~~~~~~~~~~Bienvenido!~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
	menu();
	return 0;
}
