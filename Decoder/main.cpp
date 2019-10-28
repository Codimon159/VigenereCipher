/*
 * Timon Esser - me@timonster.com
 * Entschlüsselungsprogramm für die Vigenere-Verschlüsselung
 * -> verwendet das vigenere quadrat zum entschlüsseln als array
 * -> einfache passwort eingabe möglich
 * 
 * todo: 
 * -prüfung ob passwort länger als der input ist
 * -prüfung auf sonderzeichen
 * 
 * */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int main(int argc, char **argv)
{
    //deklaration
    int indexX, indexY, strl, inputl, passl, indexABC;
    string input, passwd, output, abc, currC;
    size_t foundy, foundx;

    //erstelle ein string mit dem abc
    abc ="abcdefghijklmnopqrstuvwxyz";
    
    //längen ermitteln
    strl = abc.length();
    
    //array für das vigenere quadrat
    char vQuadrat[26][26];
    cout << "-----Das Vigenere Quadrat-----\n" << endl;
    cout << "   " << abc << endl;
    cout << "------------------------------" << endl;
    
    //while schleife die nach jedem durchlauf eine zeile weiter springt
    for (indexY = 0; indexY <=25; indexY++){
        
    // for schleife die durch jedes zeichen in der zeile loopt
    for (indexX = 0; indexX < strl; indexX++){
        
        if (indexX == 0){cout << abc[indexY] << " |";}
        
        //falls i > 26 fange von vorne im abc an
        indexABC = (indexX+indexY) % 26;
        
        vQuadrat[indexY][indexX] = abc[indexABC];
        
        //debug ausgabe des vigenere quadrats
        cout << vQuadrat[indexY][indexX];
        
    }
    cout << endl;
    }
    
    //verschlüsselte zeichen einlesen
    cout << "\nBitte geben Sie die zu entschluesselnden Zeichen ein (a-z ohne Sonderzeichen): ";
    cin >> input;
    
    //passwort einlesen, einfach reicht
    cout << "Bitte geben Sie das Passwort zum entschluesseln ein: (a-z ohne Sonderzeichen) ";
    cin >> passwd;
    
    //längen ermitteln
    inputl = input.length();
    passl = passwd.length();
    
    //durchlaufe den input
    for (int i =0; i<inputl; i++){   
        
        //% falls das passwort kürzer ist als der input
        foundx = abc.find(passwd[i%passl]);
        
        foundy = abc.find(input[i]);
        //cout << abc[foundy];
        
        //durchsuche die spalte nach dem zeichen und zähle mit
        for (int j=0; j < 26; j++) {
            if ( abc[foundy] == vQuadrat[j][foundx]){
                
                //ausgabe des entschlüsselten zeichens
                cout << abc[j] ;
                break;
            }
        }
    }
    cout << endl;
    return 0;
}