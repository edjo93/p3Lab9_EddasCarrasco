#include"Jugador.cpp"
#include<iostream>
using namespace std;
int main(){
	Jugador* jugador1=new Jugador();
	Jugador* jugador2=new Jugador();
	
	char opcion;
	char opcion2;
	do{
		cout<<"\n1-mostrar datos del jugador\n2-curar punto de vida\n3-salir\n?: ";
		cin>>opcion;
		switch(opcion){
			case'1':
				cout<<"\n--- jugador 1 ---"<<endl;
				jugador1->print();
				cout<<"\n--- jugador 2 ---"<<endl;
				jugador2->print();
				break;
			case'2':
				do{
					cout<<"\n1-curar jugador 1\n2- curar jugador 2\n3-regresar\n?: ";
					cin>>opcion2;
					switch(opcion2){
						case'1':
							
							break;
						case'2':
							break;
						case'3':
							break;
						default:
							cout<<"\nno se ingreso una opcion correcta\n";		
					}
				}while(opcion2!='3');
				break;
			case'3':
				
				break;
			default:
				cout<<"\nno se ingreso una opcion correcta\n";		
		}
	}while(opcion!='3');
		
	
	return 0;
}
