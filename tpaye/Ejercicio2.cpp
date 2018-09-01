#include <iostream>
#include<vector>
#include<array>
#include <stdio.h>
#include <ctime>

using namespace std;

struct Pais {  // intente hacer un header pero no me compilaba bien
    int NumBolillero;
    string NombreEquipo;
    string Conferedacion;
};

struct Grupo{
    Pais Equipo1;
    Pais Equipo2;
    Pais Equipo3;
    Pais Equipo4;
};
bool esUefa(Grupo A){
    return ((A.Equipo1.Conferedacion == "UEFA" && A.Equipo2.Conferedacion =="UEFA") || (A.Equipo2.Conferedacion == "UEFA" && A.Equipo3.Conferedacion =="UEFA" ) || (A.Equipo1.Conferedacion == "UEFA" && A.Equipo3.Conferedacion =="UEFA"));
}
bool fueSorteado(Grupo (&Grupos)[8], int n, Pais pais){
    for (int i = 0; i<n; i++){

        if ((Grupos[i].Equipo1.NombreEquipo == pais.NombreEquipo)|| (Grupos[i].Equipo2.NombreEquipo == pais.NombreEquipo) || (Grupos[i].Equipo3.NombreEquipo == pais.NombreEquipo) || (Grupos[i].Equipo4.NombreEquipo == pais.NombreEquipo) ){
         return true;
        }
    }
    return false;
}

int main() {
    /* initialize random seed: aca o en el void??*/
//    std::time_t result = std::time(nullptr);
//    srand (std::localtime(&result)->tm_sec);
    srand(NULL);
    Pais Bolillero1[8] = {1, "Rusia", "UEFA", 1, "Alemania", "UEFA", 1, "Brasil", "Conmebol", 1, "Portugal", "UEFA", 1, "Argentina", "Conmebol", 1, "Belgica", "UEFA", 1, "Polonia", "UEFA", 1, "Francia", "UEFA"};
    Pais Bolillero2[8] = {2, " Espana", "UEFA", 2, "Peru", "Conmebol", 2, "Suiza", "UEFA", 2, "Inglaterra", "UEFA", 2, "Colombia", "Conmebol", 2, "Mexico", "Concacaf", 2, "Uruguay", "Conmebol", 2, "Croacia", "UEFA"};
    Pais Bolillero3[8] = {3, "Dinamarca", "UEFA", 3, "Islandia", "UEFA", 3, "Costa Rica", "Concacaf", 3, "Suecia", "UEFA", 3, "Tunez", "CAF", 3, "Egipto", "CAF", 3, "Senegal", "CAF", 3, "Iran", "AFC"};
    Pais Bolillero4[8] = {4, "Serbia", "CAF", 4, "Nigeria", "CAF", 4, "Australia", "AFC", 4, "Japon", "AFC", 4, "Marruecos", "CAF", 4, "Panama", "Concacaf", 4, "Corea del Sur", "OFC", 4, "Arabia Saudita", "AFC"};

    Grupo Grupos[8];

    for (int i = 0; i<8; i++) {
        if (i == 0) {
            Grupos[0].Equipo1 = Bolillero1[0];
        } else {
            Grupos[i].Equipo1 = Bolillero1[rand() % 8];

            while (fueSorteado(Grupos,i,Grupos[i].Equipo1)){
                    int a = rand() % 8;
                while (fueSorteado(Grupos,i,Bolillero1[a])) {
                    a = (a+1) % 8;
                }
                Grupos[i].Equipo1 = Bolillero1[a];
            }
        }

        Grupos[i].Equipo2 = Bolillero2[rand() % 8];
        while ((Grupos[i].Equipo1.Conferedacion == "Conmebol" && Grupos[i].Equipo2.Conferedacion == "Conmebol") || fueSorteado(Grupos,i,Grupos[i].Equipo2) || (Grupos[i].Equipo1.Conferedacion == Grupos[i].Equipo2.Conferedacion && Grupos[i].Equipo1.Conferedacion != "UEFA")) {

            int a = rand() % 8;
            Grupos[i].Equipo2 = Bolillero2[a];
        }

        //PASO 3
        Grupos[i].Equipo3 = Bolillero3[rand() % 8];
        int c = 0;
        while ((Grupos[i].Equipo1.Conferedacion == "UEFA" && Grupos[i].Equipo2.Conferedacion == "UEFA" &&
                Grupos[i].Equipo3.Conferedacion == "UEFA") ||
               (Grupos[i].Equipo1.Conferedacion == Grupos[i].Equipo3.Conferedacion &&
                Grupos[i].Equipo1.Conferedacion != "UEFA") ||
               (Grupos[i].Equipo2.Conferedacion == Grupos[i].Equipo3.Conferedacion &&
                Grupos[i].Equipo2.Conferedacion != "UEFA") || fueSorteado(Grupos,i,Grupos[i].Equipo3)) {
            // a,b,c uefa, roll
            // c = a, a! = uefa roll
            // c = b & b != uefa roll
            int a = rand() % 8;
            Grupos[i].Equipo3 = Bolillero3[a];
        }
        // PASO 4
        Grupos[i].Equipo4 = Bolillero4[rand() % 8];
        c = 0;
        while ((esUefa(Grupos[i]) && Grupos[i].Equipo4.Conferedacion == "UEFA") ||
               (Grupos[i].Equipo4.Conferedacion == Grupos[i].Equipo1.Conferedacion &&
                Grupos[i].Equipo1.Conferedacion != "UEFA") ||
               (Grupos[i].Equipo4.Conferedacion == Grupos[i].Equipo2.Conferedacion &&
                Grupos[i].Equipo2.Conferedacion != "UEFA") ||
               (Grupos[i].Equipo4.Conferedacion == Grupos[i].Equipo3.Conferedacion &&
                Grupos[i].Equipo3.Conferedacion != "UEFA") || fueSorteado(Grupos,i,Grupos[i].Equipo4)) {
            // esuefa y d es uefa, roll
            // d = a y a!=uefa
            // d = b y b!=uefa
            // d = c y c!=uefa
            int a = rand() % 8;
            Grupos[i].Equipo4 = Bolillero4[a];
        }
    }
    for (int i = 0; i < 8; i++){
    cout << Grupos[i].Equipo1.NombreEquipo << ", " << Grupos[i].Equipo2.NombreEquipo << ", " << Grupos[i].Equipo3.NombreEquipo << ", " << Grupos[i].Equipo4.NombreEquipo << endl;
    }
return 0;

}
