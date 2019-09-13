#include<time.h>

#ifndef HILOBATALLA_CPP
#define HILOBATALLA_CPP
#include<windows.h>
#include<process.h>
#include<iostream>
#include"Jugador.cpp"
using namespace std;
class HiloBatalla{
   private:
      bool vive;
      int espera;
      string texto;
      
      //Jugador*jugador1;
      //Jugador*jugador2;
   public:
   		  	
          HiloBatalla(){
          	//jugador1=new Jugador();
          	//jugador2=new Jugador();
          	
          }
          /*
          void setJugador1(Jugador*jugador1){
          	this->jugador1=jugador1;
		  }
		  void setJugador2(Jugador*jugador2){
		  	this->jugador2=jugador2;
		  }
		  Jugador* getJugador1(){
		  	return jugador1;
		  }
		  Jugador* getJugador2(){
		  	return jugador2;
		  }
		  */
          void setVive(bool v){
             vive=v;
          }
          bool getVive(){
          	return vive;
		  }
          void setTexto(string t){
               texto=t;
          }
          void setEspera(int e){
               espera=e;
          }          
          void run(){
             _beginthread(&HiloBatalla::runner, 
                          0, 
                          static_cast<void*>(this)
                          );             
          }
          //__cdecl
          static void runner(void* o){
                 static_cast<HiloBatalla*>(o)->runnerEstatico();
          }
          void runnerEstatico(){
          	
				   
				while(vive){
						
				   MessageBox(0,texto.c_str(), "MNSJ!", MB_OK);//la batalla comenzara
                   Sleep(espera);
                   if(!vive){
                     _endthread();
                   }
               }
            
		   }
          void stop(){
             vive=false; 
          }             
      
};
#endif
