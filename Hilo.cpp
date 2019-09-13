#include<time.h>
#include<windows.h>
#include<process.h>
#include<iostream>

#ifndef HILO_CPP
#define HILO_CPP
using namespace std;
class Hilo{
   private:
      bool vive;
      int espera;
      string texto;
   public:
          Hilo(){
          	
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
             _beginthread(&Hilo::runner, 
                          0, 
                          static_cast<void*>(this)
                          );             
          }
          //__cdecl
          static void runner(void* o){
                 static_cast<Hilo*>(o)->runnerEstatico();
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
