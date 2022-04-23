//programa realizado por Edison Urquijo - Manejador de archivos
//realiza busqueda por metodo "busqueda binaria" en los registros del archivo
// pass 12345678

#include <stdio.h>
#include <conio2.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <mmsystem.h>
using namespace std;

struct registro{
                char nombre[50];
                char telefono [50];
                int nrr;
                int cod;
                int convertido;
                int n;
                };
                
                struct index{
                             int nrr;
                             int key;
                 };
                 
             int modoretornar;   
             struct registro nuevo, borrado;
             FILE *data;
             FILE *Index;
             FILE *aux;
             void insertar(FILE *data, FILE *Index);  
             struct index indexado;  
             void mainmenu();
             void retornecaptura();
             void ordenarcodigo();
             void usermenu();
             void modolistado();
             void cargando();
             int busquedaBinaria(const int[], int, int);
             void insertar(){                
                data=fopen("data.txt","at+");
                Index=fopen("index.txt","a+");
				char add; 
				int vercod;
				int nuevocodaux=0;
				int itstrue=0;
                  system ("cls");
                  cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
                  cout <<"================================================================================";
                  cout <<"|||                Agregar Nuevos Registros Al Archivo                       |||";
                  cout <<"================================================================================";     
                  cout<<endl;
                  cout <<"--------------------------------------------------------------------------------";
                  cout<<" AVISO: Necesitamos Validar La Disponibilidad De Codigo Para Continuar!"<<endl;
                  cout<<"  +> Por Favor Introdusca Un Codigo Para Verificar: "; 
                  cin>>vercod;
                  _flushall();
                  nuevocodaux=vercod;
                  cout <<"--------------------------------------------------------------------------------";
                  while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                        nuevo.nrr;
                        if (vercod==nuevo.cod){
                                              itstrue=1;
                                              }
                        }
                  if(itstrue==0){
                                 cout <<" CODIGO DISPONIBLE! Es Posible Adicionar Un Nuevo Registro ";
                                             cout<<endl;
                                             cout<<" Agregar Un Nuevo Empleado " <<endl;
                                             cout<<"    +>Ingrese El Nombre De La Persona : ";
                                             cin>>nuevo.nombre;
                                             _flushall();
                                             cout<<"    +>Ingrese El Codigo De La Persona: ";
                                             cout<<nuevocodaux;
                                             nuevo.cod=nuevocodaux;
                                             cout<<endl;
                                             cout<<"    +>Ingrese El Telefono De La Persona ";
                                             cin >>nuevo.telefono;
                                             _flushall();
                                             nuevo.nrr=nuevo.nrr+1;
                                             nuevo.n=nuevo.n+1;
                                             fwrite(&nuevo, sizeof(struct registro), 1, data);
                                             cout <<"--------------------------------------------------------------------------------";
                                             cout <<" Procesando Registro";
                                             Sleep(200);
                                             cout<<".";
                                             Sleep(200);
                                             cout<<".";
                                             Sleep(200);
                                             cout<<".";   
                                             Sleep(500); 
                                             cout<<endl;
                                             cout <<"--------------------------------------------------------------------------------";
                                             char soundfile[] = "C:/Users/edison/Desktop/prog.wav" ;
                                             PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );  
                                             cout <<"  (+) Para Agregar Otro Empleado Presione s \n";
                                             cout <<"  (+)Para Ver El Menu Presione *                            ->Seleccion: "; 
                                             cin>>add;  
                                             cout <<"--------------------------------------------------------------------------------"; 
                                             
                                             if (add=='s'){
                                                           retornecaptura();
                                                           }
                                           fclose(data);
                                           fclose(Index);
                                           ordenarcodigo();
                                           system ("cls");
                                    }
                      else {
                           cout <<"|||||||||||   Lo Senimos! Este Codigo Ya Ha Sido Registrado ||||||||||||||||||||";
                           cout <<"|||||||||||   Pulsa Intro Para Continuar                    ||||||||||||||||||||";
                           cout <<"--------------------------------------------------------------------------------\n"; 
                           getche();
                           }
                }
                
                void retornecaptura(){
                                   insertar();
                              }
                
   void listar(){ 
               char yes;
               cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
               cout <<"================================================================================";
               cout <<"|||                  Registros Almacenados En Archivo                        |||";
               cout <<"================================================================================";     
               cout <<"|  Index  |    Codigo    |         Nombre                |     Telefono        |";
               cout <<"================================================================================";              
               int y=7; 
              char retornar;
              data=fopen("data.txt", "at+");
                while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                gotoxy(6,y);
                cout<<nuevo.nrr;
                gotoxy(18,y);
                cout<<nuevo.cod;
                gotoxy(28,y);
                cout<<nuevo.nombre;
                gotoxy(60,y);
                cout<<nuevo.telefono;
                y++;
                
    }         
               cout <<endl;
               cout <<"================================================================================"; 
               fclose(data);
               cout <<"Se Ha Finalizado La Impresion De Registros De Archivo Pulse Intro Para Continar ";    
               cout <<"================================================================================"; 
               cout <<endl; 
               getche();
}   

   void ordenarcodigo() {
        system ("cls");
        int n;
        while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                         nuevo.n; 
                        }
        n=nuevo.n;
        index vec[n];
        int i=0;
        int key;
        int nrr;
        int auxkey;
        int auxnrr;
        
        data=fopen("data.txt","r");
        while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                         vec[i].key = nuevo.cod;
                         vec[i].nrr = nuevo.nrr;
                         i++;
                        }
        fclose(data);

        // Codigo Para Imprmir Oculto
        // for (int j=0;j<n;j++){
        //             cout<<"Codigo: "<<vec[j].key <<"   Numero De Registro:"  <<vec[j].nrr << endl;
        //             }
                     
        for (int k=0; k<=n; k++){
                      for (int s=0;s<n-1;s++) { 
                                if(vec[s].key > vec[s+1].key){ 
                                        auxkey=vec[s].key;
                                        auxnrr=vec[s].nrr;
                                        vec[s].key=vec[s+1].key;
                                        vec[s].nrr=vec[s+1].nrr;
                                        vec[s+1].key=auxkey;
                                        vec[s+1].nrr=auxnrr;
                               }
                      }
        }

        // for (int t=0;t<n; t++)
        //           cout<<vec[t].key <<"  "  <<vec[t].nrr<<endl;
                   
           Index=fopen("index.txt", "w+");
                   for(int i=0;i<n;i++){
                         indexado.key=vec[i].key;
                         indexado.nrr=vec[i].nrr;
      	           fwrite(&indexado, sizeof(struct index), 1, Index);
                  }
           fclose(Index); 
                 cout<<endl<<endl<<endl<<endl<<endl<<endl;
                 cout <<"                      Estamos Procesando Registros";
                 Sleep(300);
                 cout<<".";
                 Sleep(300);
                 cout<<".";
                 Sleep(300);
                 cout<<".";   
                 Sleep(700);
                 cout<<endl;    
          }
      
      void listarnombreordened(){
            int y=7;
            cout<<endl<<endl<<endl<<endl<<endl;
               cout <<"                  Procesando Archivo";
               Sleep(400);
               cout<<".";
               Sleep(400);
               cout<<".";
               Sleep(400);
               cout<<".";   
               Sleep(900);   
               system ("cls");
               cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
               cout <<"================================================================================";
               cout <<"|||          Listado De Registro Por Orden Alfabetico (A - Z)                |||";
               cout <<"================================================================================";     
               cout <<"|  Index  |    Codigo    |         Nombre                |     Telefono        |";
               cout <<"================================================================================";
               int n;
               data=fopen("data.txt","r");
               while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                             nuevo.n; 
                           }
               fclose(data);
               n=nuevo.n;
               registro vec[n];
               int i=0;
               int key;
               int nrr;
               char auxnom[50];
               char auxtel[50];
               int auxkey;
               int auxnrr;
               int auxconverted;
               int mayus;
               data=fopen("data.txt","r");
               while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                         mayus=nuevo.nombre[0];
                            if((mayus>=65)&&(mayus<=90)){
                                 nuevo.nombre[0]=tolower(nuevo.nombre[0]);
                             }
                         vec[i].convertido=nuevo.nombre[0];
                         strcpy(vec[i].nombre,nuevo.nombre);
                         strcpy(vec[i].telefono,nuevo.telefono);
                         vec[i].cod = nuevo.cod;
                         vec[i].nrr = nuevo.nrr;
                         i++;
                        }
               fclose(data);  
                        
                 for (int k=0; k<=n; k++){
                      for (int s=0;s<n-1;s++) { 
                                if(vec[s].convertido>vec[s+1].convertido){ 
                                        auxconverted=vec[s].convertido;      
                                        auxkey=vec[s].cod;
                                        auxnrr=vec[s].nrr;
                                        strcpy(auxnom,vec[s].nombre);
                                        strcpy(auxtel,vec[s].telefono);
                                        
                                        vec[s].convertido=vec[s+1].convertido;
                                        vec[s].cod=vec[s+1].cod;
                                        vec[s].nrr=vec[s+1].nrr;
                                        strcpy(vec[s].nombre,vec[s+1].nombre);
                                        strcpy(vec[s].telefono,vec[s+1].telefono);
                                        
                                        vec[s+1].convertido=auxconverted;
                                        vec[s+1].cod=auxkey;
                                        vec[s+1].nrr=auxnrr;
                                        strcpy(vec[s+1].nombre,auxnom);
                                        strcpy(vec[s+1].telefono,auxtel);
                               }
                      }
        }
         for (int t=0;t<n; t++){
              gotoxy(2,y);
              cout<<vec[t].convertido;
              gotoxy(6,y);
              cout<<vec[t].nrr;
              gotoxy(15,y);
              cout<<vec[t].cod; 
              gotoxy(28,y);
              cout<<vec[t].nombre;
              gotoxy(60,y);
              cout<<vec[t].telefono <<endl; 
               y++; 
               }      
               getche();
               
           }
      
      void listarcodigonombre(){
               int y=7;
               cout<<endl<<endl<<endl<<endl<<endl;
               cout <<"                  Procesando Archivo";
               Sleep(400);
               cout<<".";
               Sleep(400);
               cout<<".";
               Sleep(400);
               cout<<".";   
               Sleep(900);   
               system ("cls");
               cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
               cout <<"================================================================================";
               cout <<"|||          Listado De Registro Por Orden Asendente De Codigo               |||";
               cout <<"================================================================================";     
               cout <<"|  Index  |    Codigo    |         Nombre                |     Telefono        |";
               cout <<"================================================================================";
               int n;
               data=fopen("data.txt","r");
               while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                             nuevo.n; 
                           }
               fclose(data);
               n=nuevo.n;
               registro vec[n];
               int i=0;
               int key;
               int nrr;
               char auxnom[50];
               char auxtel[50];
               int auxkey;
               int auxnrr;
               
               data=fopen("data.txt","r");
               while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                         strcpy(vec[i].nombre,nuevo.nombre);
                         strcpy(vec[i].telefono,nuevo.telefono);
                         vec[i].cod = nuevo.cod;
                         vec[i].nrr = nuevo.nrr;
                         i++;
                        }
               fclose(data);  
                        
                 for (int k=0; k<=n; k++){
                      for (int s=0;s<n-1;s++) { 
                                if(vec[s].cod > vec[s+1].cod){ 
                                              
                                        auxkey=vec[s].cod;
                                        auxnrr=vec[s].nrr;
                                        strcpy(auxnom,vec[s].nombre);
                                        strcpy(auxtel,vec[s].telefono);
                                        
                                        vec[s].cod=vec[s+1].cod;
                                        vec[s].nrr=vec[s+1].nrr;
                                        strcpy(vec[s].nombre,vec[s+1].nombre);
                                        strcpy(vec[s].telefono,vec[s+1].telefono);
                                        
                                        vec[s+1].cod=auxkey;
                                        vec[s+1].nrr=auxnrr;
                                        strcpy(vec[s+1].nombre,auxnom);
                                        strcpy(vec[s+1].telefono,auxtel);
                               }
                      }
        }
         for (int t=0;t<n; t++){
              gotoxy(6,y);
              cout<<vec[t].nrr;
              gotoxy(15,y);
              cout<<vec[t].cod; 
              gotoxy(28,y);
              cout<<vec[t].nombre;
              gotoxy(60,y);
              cout<<vec[t].telefono <<endl; 
               y++; 
               }      
               
               Index=fopen("index.txt","r");
               while(fread(&indexado, sizeof(struct index),1,Index) !=0){
                         cout<< indexado.key <<" " ;
                         cout<< indexado.nrr<<" ";
                         
                         cout<<endl;
                        }
               fclose(Index);
               
               getche();
                        }
      
      int busquedaBinaria(const int dat[], int nn, int schcodigo) {
                                               int ini = nn-1; 
                                               int fin = 0;     
                                               int cen;
                                               while (fin <= ini) {
                                               cen = (ini + fin)/2;
                                               if (dat[cen] == schcodigo)
                                               return cen;
                                               else
                                               if (schcodigo < dat[cen])
                                               ini=cen-1;
                                               else
                                               fin=cen+1;
                                               }
                                               cout<< endl;
                                               return -1;
                                               }
                        
      void buscar(){
               system ("cls");
               int schcodigo;
               int nn;
               int h=0;
               cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
               cout <<"================================================================================";
               cout <<"|||          Sistema De Busqueda / Busqueda Por Codigo De Persona            |||";
               cout <<"================================================================================";
               data=fopen("data.txt","r+");
               while(fread(&nuevo, sizeof(struct registro),1,data) !=0){
                         nuevo.n;
                        }

               nn=nuevo.n;
               fclose(data);
               int dat[nn];
               //creacion de vector busqueda 
               Index=fopen("index.txt","r+");
                    while(fread(&indexado, sizeof(struct index),1,Index) !=0){
                             dat[h]=indexado.key;
                             h++;
                            }
                    fclose(Index);
               //Busqueda Binaria 
               cout <<"\n Introdusca Un Codigo: ";
               cin>>schcodigo;
               int valid=busquedaBinaria(dat,nn,schcodigo);
               if(valid==-1){
               cout<< "\n El Codigo No Ha Sido Registrado O Ha Sido Eliminado " << endl;
               }
               else{
                     char soundfilesa[] = "C:/Users/edison/Desktop/buske.wav" ;
                                             PlaySound((LPCSTR)soundfilesa, NULL, SND_FILENAME | SND_ASYNC );
                     cout<<"\n Se Ha Encontrado Un Registro Con El Codigo Ingresado " << endl;
                     data=fopen("data.txt","r");
                     while(fread(&nuevo,sizeof(nuevo),1,data)){
                                   if (nuevo.cod==schcodigo){
                     cout<<endl;
                                                                   cout<<"    +>Registro #: "<<nuevo.nrr<<endl;
                                                                   cout<<"    +>Nombre: "<<nuevo.nombre<<endl;
                                                                   cout<<"    +>Telefono: "<<nuevo.telefono<<endl;
                     cout<<endl;
                     cout<<endl;    
	                 fclose(data);}
                  } 
               }
		        getche(); 
           }  
                          
      void modificar(){
        char auxnombre[50], seguir;
        char auxtelefono[50];
        int modifycodigo;
        int semodifico=0;
        int encontrado=0;
        int ind=0, codx;
        long mover, inicio;
        int movido;
        cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
               cout <<"================================================================================";
               cout <<"|||            Modificacion De Registros Almacenados En Arcivo               |||";
               cout <<"================================================================================";
               cout <<" Recuerde Que Solo Es Posible Modificar Los Registros De Nombre Y Telefono "<<endl; 
               cout <<" +>Ingrese Un Codigo: ";
               cin>>modifycodigo;
               cout<<endl;
               data=fopen("data.txt","r");
                while (fread(&nuevo,sizeof(struct registro),1,data) !=0){
                       if (modifycodigo==nuevo.cod){
                            encontrado=1;
                            break;
                           }
               }
               fclose(data);
               
               if (encontrado==1){
                                  //Parte estetica de la funcion de modiicacion
                                    gotoxy(3,9);
                                    cout<<"ออออออออออออออออออออออออออออออออ";
                                    gotoxy(3,13);     
                                    cout<<"ออออออออออออออออออออออออออออออออ"; 
                                    gotoxy(3,10);     
                                    cout<<"บ";
                                    gotoxy(34,10); 
                                    cout<<"บ";
                                    gotoxy(3,11);     
                                    cout<<"บ";
                                    gotoxy(34,11); 
                                    cout<<"บ";
                                    gotoxy(3,12);     
                                    cout<<"บ";
                                    gotoxy(34,12); 
                                    cout<<"บ";
               
                                    //tabla de modificacion
               
                                    gotoxy(42,9);
                                    cout<<"ออออออออออออออออออออออออออออออออ";
                                    gotoxy(43,11);
                                    cout<<" Modificacion De Registro";
                                    gotoxy(42,13);     
                                    cout<<"ออออออออออออออออออออออออออออออออ";
                                    gotoxy(42,15);     
                                    cout<<"ออออออออออออออออออออออออออออออออ";
                                    gotoxy(42,17);     
                                    cout<<"ออออออออออออออออออออออออออออออออ";
                
                                    gotoxy(42,10);     
                                    cout<<"บ";
                                    gotoxy(42,10); 
                                    cout<<"บ";
                                    gotoxy(42,11);     
                                    cout<<"บ";
                                    gotoxy(73,11); 
                                    cout<<"บ";
                                    gotoxy(73,12);     
                                    cout<<"บ";
                                    gotoxy(73,12); 
                                    cout<<"บ";
                                    
                                    //finaliza estetica
               
                                   data=fopen("data.txt","r+");
      
                               while(fread(&nuevo,sizeof(nuevo),1,data)){
                                   if (modifycodigo==nuevo.cod){
                             gotoxy(4,10);
                                                                   cout<<" Se Ha Encontrado Registro! "<<endl;
                                                                   cout<<"    +>Nombre: "<<nuevo.nombre<<endl;
                                                                   cout<<"    +>Telefono: "<<nuevo.telefono<<endl;
                                                                   movido=nuevo.nrr;
                                                                   inicio=ftell(data);
                                                                   cout<<endl;
                            gotoxy(42,14);        
                            cout<<" +>Nombre: ";
                            gotoxy(42,16); 
                            cout<<" +>Telefono: ";
                            gotoxy(53,14);
                            cin>>nuevo.nombre;
                           _flushall();
                           gotoxy(55,16);
                           cin>>nuevo.telefono;
                           _flushall();
                           int movid=inicio-sizeof(nuevo);
                           fseek(data,movid,SEEK_SET);
                           cout<<endl<<endl<<endl<< " Esta Seguro De Que Desea Modificar? ";
                                    seguir=getche();
                                    if (seguir=='s' || seguir=='S'){
                                    semodifico=1;
                                    fwrite(&nuevo,sizeof(nuevo),1,data);
                                    cout<<endl<<endl<<" Registro Moficado Correctamente ";
                                    char soundfilex[] = "C:/Users/edison/Desktop/prog.wav" ;
                                             PlaySound((LPCSTR)soundfilex, NULL, SND_FILENAME | SND_ASYNC );
                                    cout<<endl<<endl;
                                     fclose(data);
                                    }     
                           }
               } 
                                                                 
               }
               
               if (semodifico==1){ 
               data=fopen("data.txt","r");
               while(fread(&nuevo,sizeof(nuevo),1,data)){
                                   if (modifycodigo==nuevo.cod){              
                                    gotoxy(4,10);
                                                                   cout<<" Se Han Hecho Los Cambios! "<<endl;
                                                                   cout<<"    +>Nombre: "<<nuevo.nombre<<"         "<<endl;
                                                                   cout<<"    +>Telefono: "<<nuevo.telefono<<"         "<<endl;
                                                                   cout<<endl; 
                                                                   gotoxy(4,23);
                                                                   }
                                                                   }
               }
               if (semodifico==0){
                                  cout<<endl<<endl<<" No Se Realizaron Cambios! "<<endl<<endl; 
                                  }
                                  
               if (encontrado==0){
                                  cout<<endl<<"         El Codigo No Ha Sido Registrado O No Esta Disponible ";
                                  cout<<endl;
                                  cout<<endl;
                                  }      
          getche(); 
          return;     
        }
      
   void eliminar(){
        int deletecodigo;
                            aux=fopen("auxiliar.txt","a");
                   fclose(aux);
        int g=0;
        int hxc=0;
        char asterisco;
               cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
               cout <<"================================================================================";
               cout <<"|||             Eliminacion De Registros Almacenados En Arcivo               |||";
               cout <<"================================================================================";
               char deleting='s', seg;
               cout <<" +) Ingrese Un Codigo Para Borrar: ";
               cin>>deletecodigo;
               cout<<endl;
               _flushall();
                data=fopen("data.txt","r+");
                           if (data == (FILE *)NULL){
                           cout<<"    No se pudo abrir el archivo!     ";
                           exit(1);
                            }			
                while (fread(&nuevo,sizeof(struct registro),1,data) != 0){
					if (nuevo.cod==deletecodigo){
                         g=1;
                        cout<<" +>Registro Numero: "<<nuevo.nrr<<endl;
                        cout<<" +>Codigo: "<<nuevo.cod<<endl;
                        cout<<" +>Nombre: "<<nuevo.nombre<<endl;
                        cout<<" +>Telefono: "<<nuevo.telefono<<endl;
                        cout<<endl;
						cout<<"Esta seguro que desea borrar ?: ";
						cin>>seg;       
                        }
                    }
                    
                     if (g==0){
                               cout<<" El Codigo No Se Ha Registrado O No esta Disponible ";
                               cout<<endl;
                               cout<<endl;
                              }
                    
                    if(seg=='s'||seg == 'S') {
                       data=fopen("data.txt","r");
                       aux=fopen("auxiliar.txt","w");
                                         while(!feof(data)){
                                               if (fread(&nuevo,sizeof(struct registro),1,data) != 0){
                                                                         if (nuevo.cod!=deletecodigo){
                                                                         nuevo.n=nuevo.n-1;
                                                                         borrado=nuevo;
                                                                         fwrite(&borrado,sizeof(borrado),1,aux);
                                                                         }
                                                                 }
                                                                
                                                     }
                      fclose(data);
                      fclose(aux);
                      
        aux=fopen("auxiliar.txt","r");
        data=fopen("data.txt","w"); 
                while(!feof(aux)){
                                               if (fread(&borrado,sizeof(borrado),1,aux) != 0){
                                                                         hxc=1;
                                                                         nuevo=borrado;
                                                                         fwrite(&nuevo,sizeof(borrado),1,data);
                                                                 }
                                                                
                                                     }       
        if (hxc==1){
                    char soundfilef[] = "C:/Users/edison/Desktop/prog.wav" ;
                                             PlaySound((LPCSTR)soundfilef, NULL, SND_FILENAME | SND_ASYNC );
                    cout <<"Se Ha Eliminado El Registro Correctamente! \n";
                    cout <<"Para Ver La Nueva Lista Ingrese * ";
                    cin>>asterisco;
                    }
                fclose(data);
               fclose(aux);
               cout<<endl; 
                }
                
        if (asterisco=='*'){
            system ("cls");
            listar();
            }
                   
        getche();
        ordenarcodigo();
        system ("cls");
  }  
        
                  
   void adminmenu(){
        system ("cls");
        char soundfilesq[] = "C:/Users/edison/Desktop/admin.wav" ;
                                             PlaySound((LPCSTR)soundfilesq, NULL, SND_FILENAME | SND_ASYNC );
        cargando();
        Beep(523,500); Beep(587,500); Beep(659,500); Beep(698,500); Beep(784,500);
        system ("cls");
        system("color 6f");
        int opcion = 0; 
       do{ 
                     do{ 
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
       cout <<"================================================================================";
       cout <<"||                    Modo De Ingreso Administrador                           ||";   
       cout <<"================================================================================";
       cout <<endl;
       cout<<"\n    +>Ingresar Un Nuevo Registro De Empleado..........................(1) " <<endl;
       cout<<"    +>Mostrar En Lista Los Registros Existentes.......................(2)"<<endl;
       cout<<"    +>Ver Lista De Registros (Ordenado Por Codigo / Nombre)...........(3)"<<endl;
       cout<<"    +>Consultar Registro De Empleado Existente........................(4)"<<endl;
       cout<<"    +>Modificar Registro De Empleado Existente........................(5)"<<endl;
       cout<<"    +>Eliminar Registro De Empleado Existente.........................(6)"<<endl;
       cout<<"    +>Retornar Al Menu Principal......................................(7)"<<endl;
       cout<<"    +>Finalizar El Programa...........................................(8)            Seleccion: ";
       cin>>opcion; 
         }
        while(opcion<1 || opcion>8); 
                    switch(opcion){ 
                            case 1: 
                            cout <<"\n--------------------------------------------------------------------------------";
                            system("color 4f");
                            insertar();
                            break; 
                            case 2:
                            cout <<"--------------------------------------------------------------------------------";
                            system ("cls");
                            system("color 4f");
                            listar();
                            break;
                            case 3:
                            system ("cls");
                            system("color 4f");
                            modolistado(); 
                            break;
                            case 4:
                            system ("cls");
                            system("color 4f");
                            buscar();
                            break;
                            case 5:
                            system ("cls");
                            system("color 6f");
                            modificar();
                            break;
                            case 6:
                            system ("cls");
                            system("color 4f");
                            eliminar(); 
                            break;
                            case 7:
                            system ("cls");
                            system("color 6f");
                            break;
                            case 8:
                            system("color 4f");
                            char soundfilesas[] = "C:/Users/edison/Desktop/gracias.wav" ;
                                             PlaySound((LPCSTR)soundfilesas, NULL, SND_FILENAME | SND_ASYNC );
                            cout <<"\n--------------------------------------------------------------------------------"; 
                            cout <<"\n                      Gracias Por Utilizar Nuestros Servicios!                ";
                            cout <<"\n                      Ing. Edison Urquijo              "; 
                            Sleep (5000);                           
                            exit (0);
                            break;  
                             } 
                    }
                    while(opcion!=8); 
        }
        
        
        void cuadro(const int x,const int y,const int x1,const int y1) {     
                    char si=201,ii=200,sd=187,id=188,v=186,h=205; 
                     int i,j;
                     gotoxy(x,y); cout<<si;
                     gotoxy(x1,y); cout<<sd;
                     for(i=x+1;i<x1;i++) {
                     gotoxy(i,y); cout<<h;}  
                     for(j=y+1;j<y1;j++) {
                     gotoxy(x,j); cout<<v;}
                     gotoxy(x,y1); cout<<ii;
                     gotoxy(x1,y1); cout<<id;
                     for(j=y+1;j<y1;j++) {
                     gotoxy(x1,j); cout<<v;}
                     for(i=x+1;i<x1;i++){
                     gotoxy(i,y1); cout<<h;}  
                      }
   void cargando(){
        system ("cls");
        system ("color 0f");
                      int i,l=0,t=100;
                       float j=0,k;
                       char c=219; 
                       k=1.754;   
                       cuadro(10,20,70,22);
                       if(modoretornar==1){
                       gotoxy(19,23);cout<<"SE ESTA CARGANDO EL SISTEMA DEL ADMINISTRADOR"; 
                       }
                        if(modoretornar==2){
                       gotoxy(19,23);cout<<"SE ESTA CARGANDO EL SISTEMA DEL USUARIO"; 
                       }
                       for(i=12;i<69;i+=1) {
                       textcolor(BLUE);                   
                       gotoxy(i,21); cout<<c;  
                       Sleep(t);  
                       textcolor(WHITE);                   
                       gotoxy(38,24); cout<<l<<"%";
                       j+=k;
                       l=j;
                       if(i>20 && i<35) t=200;
                       if(i>30 && i<57) t=50;
                       if(i>57) t=130;
                     }          
                       gotoxy(37,24); cout<<"100%";
                       Sleep(500);
        }
                
    void validar(){
    int asp=15, asx=15;
    system ("cls");
     system ("color 4f"); 
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
       cout <<"================================================================================";
       cout <<"||                    Modo De Ingreso Administrador                           ||";   
       cout <<"================================================================================";
       cout <<endl;
                        int password;
                        int errores=2;
                        gotoxy(7,6);
                        cout<<" +>AVISO: El Sistema Requiere Validar La Informacion Para Ingresar \n        A La Administacion De Datos \n";
                        gotoxy(6,8);
                        cout<<"อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ";
                         gotoxy(6,6);     
                        cout<<"บ";
                        gotoxy(76,6);     
                        cout<<"บ";
                         gotoxy(6,7);     
                        cout<<"บ";
                        gotoxy(76,7);     
                        cout<<"บ";
                        
                        gotoxy(6,11);
                        cout<<"ออออออออออออออออออออออออออออออออ";
                        gotoxy(6,12);
                        cout<<"  Login Del Administrador ";
                        gotoxy(6,16);
                        cout<<"  +)Ingrese La Contrase๑a: ";
                        gotoxy(6,14);
                        cout<<"ออออออออออออออออออออออออออออออออ";
                         gotoxy(6,12);     
                        cout<<"บ";
                        gotoxy(6,13);     
                        cout<<"บ";
                        gotoxy(37,12);     
                        cout<<"บ";
                        gotoxy(37,13);     
                        cout<<"บ";
     
                        while (asp<=23){   
                         gotoxy(6,asp);     
                        cout<<"บ";
                        asp++;
                        }
                        
                        while (asx<=23){   
                         gotoxy(37,asx);     
                        cout<<"บ";
                        asx++;
                        }
                        gotoxy(6,24);
                        cout<<"ออออออออออออออออออออออออออออออออ";
                        
                         
       gotoxy(10,19);
                                             cout<<"ออออออออออออออออออออออออ";
        gotoxy(10,18);                 
       cin>>password;
       
        gotoxy(45,12);
        cout<<"  Verificando Contrase๑a";
        Sleep(900);
        cout<<".";
        Sleep(900);
        cout<<".";
        Sleep(900);
        cout<<".";
        Sleep(1000);
        gotoxy(45,12);
        cout<<"  Verificacion Completada  ";
        
                        
     while (errores<=2 && password!=12345678){
       if(password!=12345678 && errores==2)
       {
                                gotoxy(46,16);
                             cout<<"ออออออออออออออออออออออออออออ";
           gotoxy(47,17);
           cout<<"Acceso Denegado! Contrase๑a";
           gotoxy(47,18);
            cout<<"Ingresada No Es Valida"; 
            gotoxy(47,19);
            cout<<"(Intentos Restantes 2)"<<endl;
            gotoxy(10,22);
            cout<<" INTENTE NUEVAMENTE ";
            
              gotoxy(46,20);
                             cout<<"ออออออออออออออออออออออออออออ";
                             
            
           gotoxy(10,18);
            cout<<"                       ";
           gotoxy(10,18);
           cin>>password;
             gotoxy(45,12);
        cout<<"  Verificando Contrase๑a";
        Sleep(900);
        cout<<".";
        Sleep(900);
        cout<<".";
        Sleep(900);
        cout<<".";
        Sleep(1000);
        gotoxy(45,12);
        cout<<"  Verificacion Completada  ";
                             
           }
       if(password!=12345678 && errores==1)
       {
          
            gotoxy(47,19);
            cout<<"(Intentos Restantes 1)"<<endl;
             gotoxy(10,18);
            cout<<"                         ";
           gotoxy(10,18);
           cin>>password;
            gotoxy(45,12);
        cout<<"  Verificando Contrase๑a";
        Sleep(900);
        cout<<".";
        Sleep(900);
        cout<<".";
        Sleep(900);
        cout<<".";
        Sleep(1000);
        gotoxy(45,12);
        cout<<"  Verificacion Completada  ";
           }
       if(password!=12345678 && errores==0)
       {
          char soundfilesas[] = "C:/Users/edison/Desktop/gracias.wav" ;
                                             PlaySound((LPCSTR)soundfilesas, NULL, SND_FILENAME | SND_ASYNC );
           gotoxy(47,19);
           cout<<"     HASTA LUEGO      ";
           Sleep(5000);
           exit (0);
           }
       
       errores--;
       }
     if (password==12345678){
     cout<<endl<<endl<<endl;
               gotoxy(10,22);
            cout<<":) CONTRASEัA VALIDA";
               gotoxy(16,27);
               cout<<":) La Contrase๑a Es Valida! Estamos Alistando Todo";
               Sleep(900);
               cout<<".";
               Sleep(900);
               cout<<".";
               Sleep(900);
               cout<<".";   
               Sleep(1000);   
               system ("cls");
     cout<<endl<<endl;
     adminmenu();
     }
     
     }
     void modolistado(){
              int opcion=0; 
              cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
              cout <<"================================================================================";
              cout <<"||             Organizacion De Registros Almacenados                          ||";   
              cout <<"================================================================================";
               do{ 
                     do{
                         cout<<endl;                 
                         cout <<"\n    +>Ordenar Por Nombre......................(1) " <<endl;
                         cout <<"    +>Ordenar Por Codigo......................(2) " <<endl;
                         cout <<"    +>Regresar Al Menu Anterior...............(3) " <<endl;
                         cout <<"                                    Seleccion: ";
                         cin>>opcion;
                         
                         }
               while(opcion<1 || opcion>3); 
                    switch(opcion){ 
                            case 1: 
                            system ("cls");  
                            listarnombreordened();
                            break;
                            case 2: 
                            system ("cls"); 
                            listarcodigonombre();
                            break;
                            case 3: 
                            system ("cls"); 
                            if(modoretornar==1){
                            adminmenu();
                            }
                            if (modoretornar==2){
                             usermenu();                    
                                                 }
                            break;
                 }     
              }
           while(opcion!=3);   
          }
     
     void usermenu(){
        char soundfilesx[] = "C:/Users/edison/Desktop/user.wav" ;
                                             PlaySound((LPCSTR)soundfilesx, NULL, SND_FILENAME | SND_ASYNC );
        cargando();
        system ("cls");
        system ("color 6f");  
        int opcion = 0; 
       do{ 
                     do{ 
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
       cout <<"================================================================================";
       cout <<"||                       Modo De Ingreso Usuario                              ||";   
       cout <<"================================================================================";
       cout<<endl;                 
       cout <<"\n    +>Ver Lista De Los Empleados Existentes (Orden De Entrada)............(1) " <<endl;
       cout <<"    +>Ver Lista De Registros (Ordenado Por Codigo / Nombre)...............(2)"<<endl;
       cout <<"    +>Sistema De Busqueda De Registos.....................................(3)"<<endl;
       cout <<"    +>Finalizar El Programa...............................................(4)"<<endl;            
       cout <<"                                                           Seleccion: ";
       cin>>opcion; 
         }
        while(opcion<1 || opcion>4); 
                    switch(opcion){ 
                            case 1: 
                            system ("cls");
                             system ("color 4f");   
                            listar();
                            break;
                            case 2: 
                            system ("cls"); 
                             system ("color 4f"); 
                            modolistado(); 
                            break; 
                            case 3:
                            system ("cls");
                             system ("color 4f"); 
                            buscar(); 
                            break;
                            case 4:
                            char soundfilesas[] = "C:/Users/edison/Desktop/gracias.wav" ;
                                             PlaySound((LPCSTR)soundfilesas, NULL, SND_FILENAME | SND_ASYNC );
                            cout <<"\n--------------------------------------------------------------------------------"; 
                            cout <<"\n                      Gracias Por Utilizar Nuestros Servicios!                ";
                            cout <<"\n                      Ing. Edison Urquijo              "; 
                            Sleep (5000);                           
                            exit (0);
                            break;  
                             } 
                    }
                    while(opcion!=4); 
        }
        
void mainmenu(){
     int opcion = 0; 
       do{ 
                     do{ 
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"; 
       cout <<"================================================================================";
       cout <<"|| Este Programa Le Permitira A Un Administrador Insertar Los Sueldos De N    ||"; 
       cout <<"|| Cantidad De Empleados Los Cuales Seran Registrados En Un Archivo Local Y   ||";
       cout <<"||                                                                            ||";
       cout <<"================================================================================";
       cout <<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
       cout <<"||||||||||||||||||||||||||||  MANEJO DE ARCHIVOS  ||||||||||||||||||||||||||||||";
       cout <<endl;
       cout<<" +)ADMINISTRADOR: Se requiere contrase๑a de autenticacion, Permeite A๑adir, \n   Modificar, Eliminar & Ver Registros Existentes "<<endl;
       cout<<" +)USUARIO: Permite Ver Los Registros Existentes y Hacer Consulta Especifica"<<endl<<endl; 
       cout<<"  Seleccione Modo De Ingreso: "<<endl;
       cout<<"    +>Ingresar Como Adminitrador De Datos..........(1) " <<endl;
       cout<<"    +>Ingresar Como Usuario .......................(2)"<<endl;
       cout<<"    +>Finalizar El Programa........................(3)          Seleccion: ";
        gotoxy(75,18);
                                             cout<<" อออออ";
        gotoxy(75,16);     
        cout<<" อออออ"; 
        gotoxy(76,17);     
        cout<<"บ   บ";
         
        gotoxy(78,17);                                
       cin>>opcion;  
         }
        while(opcion<1 || opcion>4); 
                    switch(opcion){ 
                            case 1: 
                            cout <<"\n--------------------------------------------------------------------------------";
                            modoretornar=1;
                            validar();
                            break; 
                            case 2:
                            cout <<"--------------------------------------------------------------------------------";
                            modoretornar=2;
                            usermenu();
                            break;
                            case 3:
                            char soundfilesas[] = "C:/Users/edison/Desktop/gracias.wav" ;
                                             PlaySound((LPCSTR)soundfilesas, NULL, SND_FILENAME | SND_ASYNC );
                            cout <<"\n--------------------------------------------------------------------------------"; 
                            cout <<"\n                      Gracias Por Utilizar Nuestros Servicios!                ";
                            cout <<"\n\n  +>Desarrollado Por: Ing.                 "; 
                            cout <<"\n                      Ing. Edison Urquijo              "; 
                            Sleep (5000);                           
                            exit (0);
                            break;  
                             } 
                    }
                    while(opcion!=4); 
                        
       getchar();      
     }

main(){
       char soundfiles[] = "C:/Users/edison/Desktop/progm.wav" ;
                                             PlaySound((LPCSTR)soundfiles, NULL, SND_FILENAME | SND_ASYNC );
       system("color 6f");
       mainmenu();
       getchar();  
       
        
       }
