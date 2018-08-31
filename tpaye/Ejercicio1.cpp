#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
struct Pais {  // intente hacer un header pero no me compilaba bien
    int NumBolillero;
    string NombreEquipo;
    string Conferedacion;
};
int main() {
    FILE *aequipos = NULL;
    aequipos = fopen("equipos.bin", "wb");
    if (!aequipos) {
        cout << "No se pudo abrir el archivo de escritura" << endl;
        return 1;
    }
    Pais Rusia {1, "Rusia", "UEFA"};
    Pais Alemania {1, "Alemania", "UEFA" };
    Pais Brasil {1, "Brasil", "Conmebol" };
    Pais Portugal {1, "Portugal", "UEFA" };
    Pais Argentina {1, "Argentina", "Conmebol" };
    Pais Belgica {1, "Belgica", "UEFA" };
    Pais Polonia {1, "Polonia", "UEFA" };
    Pais Francia {1, "Francia", "UEFA" };
    Pais Espana {2, " España", "UEFA" };
    Pais Peru {2, "Peru", "Conmebol" };
    Pais Suiza {2, "Suiza", "UEFA" };
    Pais Inglaterra {2, "Inglaterra", "UEFA" };
    Pais Colombia {2, "Colombia", "Conmebol" };
    Pais Mexico {2, "Mexico", "Concacaf" };
    Pais Uruguay {2, "Uruguay", "Conmebol" };
    Pais Croacia {2, "Croacia", "UEFA" };
    Pais Dinamarca {3, "Dinamarca", "UEFA" };
    Pais Islandia {3, "Islandia", "UEFA" };
    Pais CostaRica {3, "Costa Rica", "Concacaf" };
    Pais Suecia {3, "Suecia", "UEFA" };
    Pais Tunez {3, "Tunez", "CAF" };
    Pais Egipto {3, "Egipto", "CAF" };
    Pais Senegal {3, "Senegal", "CAF" };
    Pais Iran {3, "Iran", "AFC" };
    Pais Serbia {4, "Serbia", "CAF" };
    Pais Nigeria {4, "Nigeria", "CAF" };
    Pais Australia {4, "Australia", "AFC" };
    Pais Japon {4, "Japon", "AFC" };
    Pais Marruecos {4, "Marruecos", "CAF"};
    Pais Panama {4, "Panama", "Concacaf"};
    Pais CoreaDelSur {4, "Corea del Sur", "OFC"};
    Pais ArabiaSaudita {4, "Arabia Saudita", "AFC" };
    fwrite(&Rusia,sizeof(Pais),1, aequipos);
    fwrite(&Alemania,sizeof(Pais),1, aequipos);
    fwrite(&Brasil,sizeof(Pais),1, aequipos);
    fwrite(&Portugal,sizeof(Pais),1, aequipos);
    fwrite(&Argentina,sizeof(Pais),1, aequipos);
    fwrite(&Belgica,sizeof(Pais),1, aequipos);
    fwrite(&Polonia,sizeof(Pais),1, aequipos);
    fwrite(&Francia,sizeof(Pais),1, aequipos);
    fwrite(&Espana,sizeof(Pais),1, aequipos);
    fwrite(&Peru,sizeof(Pais),1, aequipos);
    fwrite(&Suiza,sizeof(Pais),1, aequipos);
    fwrite(&Inglaterra,sizeof(Pais),1, aequipos);
    fwrite(&Colombia,sizeof(Pais),1, aequipos);
    fwrite(&Mexico,sizeof(Pais),1, aequipos);
    fwrite(&Uruguay,sizeof(Pais),1, aequipos);
    fwrite(&Croacia,sizeof(Pais),1, aequipos);
    fwrite(&Dinamarca,sizeof(Pais),1, aequipos);
    fwrite(&Islandia,sizeof(Pais),1, aequipos);
    fwrite(&CostaRica,sizeof(Pais),1, aequipos);
    fwrite(&Suecia,sizeof(Pais),1, aequipos);
    fwrite(&Tunez,sizeof(Pais),1, aequipos);
    fwrite(&Egipto,sizeof(Pais),1, aequipos);
    fwrite(&Senegal,sizeof(Pais),1, aequipos);
    fwrite(&Iran,sizeof(Pais),1, aequipos);
    fwrite(&Serbia,sizeof(Pais),1, aequipos);
    fwrite(&Nigeria,sizeof(Pais),1, aequipos);
    fwrite(&Australia,sizeof(Pais),1, aequipos);
    fwrite(&Japon,sizeof(Pais),1, aequipos);
    fwrite(&Marruecos,sizeof(Pais),1, aequipos);
    fwrite(&Panama,sizeof(Pais),1, aequipos);
    fwrite(&CoreaDelSur,sizeof(Pais),1, aequipos);
    fwrite(&ArabiaSaudita,sizeof(Pais),1, aequipos);
    cout << "Se genero el archivo binario con exito." << endl;
    int n = fclose(aequipos);
//    FILE *aequipos2 = fopen("equipos.bin","rb");
//    Pais pais = {0,"",""};
//    fread(&pais,sizeof(pais),1,aequipos2);
//    fclose(aequipos2);
//    cout << "El Nombre del equipo es: " << pais.NombreEquipo << endl; Pruebo leer uno, lo lee, pero me devuelve segmentation fault y no se por que.
return n;
}
