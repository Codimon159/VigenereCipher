/*
 * Timon Esser - me@timonster.com
 * Verschlüsselungsprogramm mit der Vigenere-Verschlüsselung
 * -> verwendet das vigenere quadrat zum verschlüsseln als array
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
    char crypted;
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
    
    //zeichen einlesen
    cout << "\nBitte geben Sie die zu verschluesselnden Zeichen ein (a-z ohne Sonderzeichen): ";
    cin >> input;
    
    //passwort einlesen
    cout << "Bitte geben Sie ein Passwort zum verschluesseln ein: (a-z ohne Sonderzeichen) ";
    cin >> passwd;
    
    //längen ermitteln
    inputl = input.length();
    passl = passwd.length();
    
    //durchlaufe den input
    for (int i =0; i<inputl; i++){   
        
        //schritt1: finde die indexe von z.v. zeichen und vom v zeichen
        foundx = abc.find(input[i]);
        foundy = abc.find(passwd[i % passl]);
        
        //speicher das verschlüsselte zeichen
        crypted = vQuadrat[foundy][foundx];
        
        //hänge das ergebnis an die ausgabe
        output = output.append(1, crypted);

    } 
    //ausgabe
    cout << "Die verschluesselte Nachricht lautet: "<< output << endl;;
    return 0;
}
