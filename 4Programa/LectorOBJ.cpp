#include <LectorOBJ.hpp>

Lector :: Lector()
{
   
}

string Lector:: leeArchivo(string path)
{
    char desision;
    string resStr;
    bool salida = false;
    bool stillAny = false;
    bool deGolpeYporrazo = true;

	 ifstream file(path);
     while(salida == false)
     {
         if(deGolpeYporrazo == false )
         {
                //desision = getchar();                         
         }

        //cout<<"apretado"<<desision<<endl; 

        if(desision == 'd' || desision == 'D')
        {
            deGolpeYporrazo = true;
        }
        if(desision == 'S' || desision == 's' || deGolpeYporrazo == true)
         {
            if(getline(file,resStr))
            {
                stillAny = true;
            }               
            else
            {
                salida = true;
            }
                cout<<resStr<<endl;            
         }
        else
        {
            if(desision == 'e' || desision == 'E')
            {
                 salida = true;
            }
        }  
        //fflush(stdin);
     }//ciclo principal.
     cout<<"lectura terminada"<<endl;
}//metodo de lectura.