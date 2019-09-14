#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>

#ifndef HILOVIDA_CPP
#define HILOVIDA_CPP
using namespace std;
class HiloVida{
   private:
      bool vive;
      int espera;
      string texto;
      int vida;
   public:
          HiloVida(){
          	
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
             _beginthread(&HiloVida::runner, 
                          0, 
                          static_cast<void*>(this)
                          );             
          }
          //__cdecl
          static void runner(void* o){
                 static_cast<HiloVida*>(o)->runnerEstatico();
          }
          void runnerEstatico(){
               while(vive){
                   MessageBox(0,texto.c_str(), "advertencia", MB_OK);  
					vida+=1;				                         
                   Sleep(espera);
                   if(!vive){
                     _endthread();
                   }
               }
          } 
          int getVida(){
          	return vida;
		  }
		  void getDatos(int vida){
		  	this->vida=vida;
		  }                   
          void stop(){
             vive=false; 
          }             
      
};
#endif
