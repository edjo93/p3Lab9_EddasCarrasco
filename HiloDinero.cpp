#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>

#ifndef HILODINERO_CPP
#define HILODINERO_CPP
using namespace std;
class HiloDinero{
   private:
      bool vive;
      int espera;
      int dinero;
      string texto;
   public:
          HiloDinero(){
          	
          }
          void setVive(bool v){
             vive=v;
          }
          void setTexto(string t){
               texto=t;
          }
          void setEspera(int e){
               espera=e;
          }          
          void run(){
             _beginthread(&HiloDinero::runner, 
                          0, 
                          static_cast<void*>(this)
                          );             
          }
          //__cdecl
          static void runner(void* o){
                 static_cast<HiloDinero*>(o)->runnerEstatico();
          }
          void runnerEstatico(){
          	
               while(vive){
                   MessageBox(0,texto.c_str(), "advertencia", MB_OK);                        
                   //el dinero aumenta cada 7 seg
                   dinero+=1;
                   Sleep(espera);
                   if(!vive){
                     _endthread();
                   }
               }
          }
		  void getDatos(int dinero){//obtiene el dinero del jugador
		  	this->dinero=dinero;	
		  }  
		  int getDinero(){
		  	return dinero;
		  }                  
          void stop(){
             vive=false; 
          }             
      
};
#endif
