#ifndef JUGADOR_CPP
#define JUGADOR_CPP
	#include<iostream>
	using namespace std;
	class Jugador{
		private:
			int dinero;
			int vida;
			int vidaMaxima;
			int nivel;
		public:
			Jugador(){//inicializa el jugador en un estado consistente
				dinero=0;
				vida=1;
				vidaMaxima=3;
				nivel=1;
				
			}
			//setters y getters
			int getDinero() {
		        return dinero;
		    }
		
		    void setDinero(int dinero) {
		        this->dinero = dinero;
		    }
		
		    int getVida() {
		        return vida;
		    }
		
		    void setVida(int vida) {
		        this->vida = vida;
		    }
		
		    int getVidaMaxima() {
		        return vidaMaxima;
		    }
		
		    void setVidaMaxima(int vidaMaxima) {
		        this->vidaMaxima = vidaMaxima;
		    }
		
		    int getNivel() {
		        return nivel;
		    }
		
		    void setNivel(int nivel) {
		        this->nivel = nivel;
		    }	
		    void print(){
		    	cout<<"\ndinero: "<<dinero<<endl;
		    	cout<<"vida: "<<vida<<endl;
		    	cout<<"vida maxima: "<<vidaMaxima<<endl;
		    	cout<<"nivel: "<<nivel<<endl;
		    	
			}
		    
		    //destructor
		    ~Jugador(){
		    	
			}
	};
	
#endif
