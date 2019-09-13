#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>

#ifndef HILOVIDAMAXIMA_CPP
#define HILOVIDAMAXIMA_CPP
using namespace std;
class HiloVidaMaxima{
   private:
      bool vive;
      int espera;
      string texto;
   public:
          HiloVidaMaxima(){
          	
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
             _beginthread(&HiloVidaMaxima::runner, 
                          0, 
                          static_cast<void*>(this)
                          );             
          }
          //__cdecl
          static void runner(void* o){
                 static_cast<HiloVidaMaxima*>(o)->runnerEstatico();
          }
          void runnerEstatico(){
               while(vive){
                   MessageBox(0,texto.c_str(), "advertencia", MB_OK);  
				                         
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
