#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main()
{
       FILE *soubor;
       char c;
       int pocet=0;
       int x=6;
       int y=6;
       int znak;
       int maxDelka = 255;
       int cislice;
       long long soucin=1;
       int pole[1001];
       long long nejvetsi=0;
       int pozice=0;
       int i,j;
       char csv[x][y][maxDelka];
       char separator = ',';

    soubor = fopen("C:\\Users\\sovjak.AZ\\Documents\\ctenisouboru\\bin\\Debug\\mojecsv.txt","r");

    cout << "tisk jako znaky\n";
    do {
        c = fgetc(soubor);
        cout << c;
        Sleep(10);
        pocet++;
        //if (c == '\n') cout << "!!!";
    } while (c != EOF);
    //je jich 1000, 50*20

    rewind(soubor);
    cout << "\n\n";

    //ulozime do pole
    x=1;
    y=1;
    znak=0;
    do {
        c = fgetc(soubor);
        if (c == '\n') {
            y++;
            x=1;
            znak=0;
            cout << "nacten konec radku" << endl;
        }
        else if (c == separator) {
            csv[x][y][znak]=0;
            x++;
            znak = 0;
            cout << "nacten separator" << endl;
        }
        else {
        csv[x][y][znak]=c;
        cout << "x=" << x << " y=" << y << " znak=" << znak << " char=" << c <<endl;
        Sleep(100);

        znak++;
        }
    } while (c != EOF);

    cout << "x= " << x << ", y= " << y << ", z= " << znak <<endl;

    fclose(soubor);

//tisk poli
for (int j=1;j<=5;j++){
        cout << endl;
    for(int i=1;i<=5;i++){
        cout << " ";
        int z=0;
        while(csv[i][j][z] != 0){
            cout << csv[i][j][z];
            z++;
        }

    }
}
    return 0;
}
