#include"Jugador.cpp"
#include<iostream>
#include"HiloBatalla.cpp"
#include"HiloDinero.cpp"
#include"HiloVida.cpp"
#include<CONIO.H>
using namespace std;
int main(){
	char exit;
	HiloVida*hiloVida=new HiloVida();
	HiloDinero* hiloDinero=new HiloDinero();
	hiloDinero->setVive(false);
	//--
	HiloBatalla*hiloBatalla=new HiloBatalla();
	hiloBatalla->setVive(true);
	hiloBatalla->setEspera(10000);
	hiloBatalla->setTexto("la batalla comenzara");
	hiloBatalla->run();
	Jugador* jugador1=new Jugador();
	Jugador* jugador2=new Jugador();
	char opcion=-1;
	char opcion2;
	while(true){
		if(hiloBatalla->getVive()){
			hiloDinero->setVive(false);
			hiloVida->setVive(false);
			int count_jug_1;
			int ganador;
			int count_jug_2;
			int jugador1int;
			int jugador2int;
		   	ganador=false;//no hay ganador de la ronda
			count_jug_1=0;
			count_jug_2=0;
			//mientras ninguno gane
			while(!ganador){
				//jugador 1 juega
				jugador1int=0;
				jugador2int=0;	
				//validacion
	
				while(jugador1int<1||jugador1int>3){
					cout<<"\nturno jugador 1\n1)piedra\n2)papel\n3)tijera\n?:";
					cin>>jugador1int;
					
				}
				//jugador2 juega
				//validacion
				while(jugador2int<1||jugador2int>3){
					cout<<"\nturno jugador 2\n1)piedra\n2)papel\n3)tijera\n?:";
					cin>>jugador2int;
					
				}
				//analizamos todos los casos
				if(jugador1int==1&&jugador2int==2){
					count_jug_2++;
				}	
	
				if(jugador1int==1&&jugador2int==3){
					count_jug_1++;
				}
				
				if(jugador1int==2&&jugador2int==1){
					count_jug_1++;
				}
				if(jugador1int==2&&jugador2int==3){
					count_jug_2++;
				}
				if(jugador1int==3&&jugador2int==1){
					count_jug_2++;
				}
				if(jugador1int==3&&jugador2int==2){
					count_jug_1++;
				}
				
				cout<<"\npuntos\njugador1: "<<count_jug_1<<"\njugador2: "<<count_jug_2<<endl;
				if(count_jug_1==2||count_jug_2==2){//cuando alguien gane el ciclo termina
					ganador=true;
				}
				
	
				
			}
		
			if(count_jug_1==2){
				cout<<"\nel ganador es el jugador 1"<<endl;
				//el jugador2 pierde un punto de vida
				jugador2->setVida(jugador2->getVida()-1);
			}else{
				cout<<"\nel ganador es el jugador 2"<<endl;	
				//el jugador1 pierde un punto de vida
				jugador1->setVida(jugador1->getVida()-1);
			}	
			
			hiloBatalla->stop();
		}else{
			bool entroa1=false;
			bool entroa2=false;
			hiloDinero->setVive(true);
			hiloDinero->setTexto("el dinero aumenta cada 7 seg en este menu");
			hiloDinero->setVive(true);
			hiloDinero->setEspera(7000);
			hiloDinero->run();
			if(jugador1->getVida()<=0){
				entroa1=true;
				hiloVida->setTexto("la vida aumenta para el jugador 1 en este menu");
				hiloVida->run();
				hiloVida->setEspera(6000);
				hiloVida->setVive(true);
			}
			if(jugador2->getVida()<=0){
				hiloVida->setTexto("la vida aumenta para el jugador 2 en este menu");
				hiloVida->run();
				hiloVida->setVive(true);
				hiloVida->setEspera(6000);
				entroa2=true;
			}
			
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
							cout<<"\n1-curar jugador 1\n2-curar jugador 2\n3-regresar\n?: ";
							cin>>opcion2;
							switch(opcion2){
								case'1':
									if(jugador1->getDinero()>0){
										jugador1->setDinero(jugador1->getDinero()-1);//el dinero baja
										jugador1->setVida(jugador1->getVida()+1);//se aumenta un punto de vida para el jugador 1
									}else{
										cout<<"\nno se puede curar por falta de dinero";
									}
									break;
								case'2':
									if(jugador2->getDinero()>0){
										jugador2->setDinero(jugador2->getDinero()-1);//el dinero baja
										jugador2->setVida(jugador2->getVida()+1);//se aumenta un punto de vida para el jugador 1
									}else{
										cout<<"\nno se puede curar por falta de dinero";
									}
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
				jugador1->setDinero(hiloDinero->getDinero());
				jugador2->setDinero(hiloDinero->getDinero());
				hiloDinero->stop();
				hiloBatalla->setVive(true);
				if(entroa1){
					jugador1->setVida(hiloVida->getVida());
				}
				if(entroa2){
					jugador2->setVida(hiloVida->getVida());
				}
				
		}
		cout<<"\n\n1 para salir por completo del programa/ otra tecla continuar ";
		cin>>exit;
		if(exit=='1'){
			break;
		}	
	}
		
	
	return 0;
}
