/*Il programma ha lo scopo di calcolare il prezzo consigliato col quale pagare un calciatore
 all' asta del fantacalcio leggendo alcuni dati sull'interessato (fantamedia e partite giocate anno precedente) da un file
specifico del reparto dello stesso,il quale vienerichiesto all'utente, che immettera anche il nome della squadra in cui milita
il calciatore nell'anno corrente e il numero di partecipanti alla lega.
 All' interno del programma sono presenti poi delle istruzioni di controllo,per assicurarsi che il calciatore scelto giochi in
 Serie A  e che i dati richiesti siano presenti nei file.*/

#include <fstream>
#include <iostream>
using namespace std;


double PrezzoMax (int PG, double FM, double  coeff, float coeffpart)
 {
 double pfin=(PG*FM*coeff*coeffpart);
 return pfin;
}
 /*Il programma utilizza una funzione che ,
dati PG(partite giocate) ,FM(fantamedia),coeff(un coefficiente legato alla squadra)
e ceffpart(coefficiente legato al numero partecipanti),calcola il prezzo consigliato col quale pagare il calciatore.*/


 struct giocatore /*dichiaro la struct giocatore,composta da nome,partite giocate e fantamedia*/
{
    string nome;
    int PG;
    double FM;


};
   struct ksquadra
   {                   /*dichiaro la struct ksquadra che associa, ad ogni squadra il nome
                        della stessa e il coefficiente di importanza*/
  string squadra;
    double k1;
   };

int main()
{
cout << "Ciao! Questo programma ti permette di calcolare il prezzo ideale da pagare all'asta"<<endl;
cout << "per i migliori attaccanti della passata stagione. Cominciamo!"<<endl;

char c;
ifstream fil("coefficienti_partecipanti.txt"); /*permetto all'utente,tramite la lettura di un file, di conoscere
 qual e il coefficiente per il numero partecipanti della propria lega e di inserirlo*/
while (fil.get(c))
{
cout<<c;
}

fil.close ();
cout<< " "<<endl;
cout << "Leggi i valori del coefficiente relativo al numero di partecipanti che ti interessa" <<endl;
cout << "dal file soprastante e inseriscilo di seguito:"<<endl;
double coeffpart;
double k2,k1;
cin >> coeffpart;
if (coeffpart!=1 && coeffpart!=0.6 && coeffpart!=0.8 && coeffpart!=1.1 && coeffpart!=1.2 && coeffpart !=1.3) {
    /* controllo che  l'inserimento del coefficiente sia corretto*/
                 cout << "Coefficiente non valido!"<<endl;
                 cout << "Riavvia il programma e riprova"<<endl;
                 return 0;
}
cout << "Ora inserisci il ruolo a cui sei interessato:"<<endl;
    cout << "P=portieri, D=difensori,C=centrocampisti,A=attaccanti:" << endl;
    char reparto; /*chiedo all' utente di inserire il ruolo a cui e interessato,
                in modo da caricare il file con i dati dei cacliatori di quel ruolo */
    cin >> reparto;
    giocatore arraygioc[10];

switch (reparto)
    {
     case 'P':
k2=0.2;
        {
        fstream fin;
         fin.open ("Portieri.txt");
        for(int i=0;i<10;i++)
         {
        fin>>arraygioc[i].nome;
        fin>>arraygioc[i].PG;
        fin>>arraygioc[i].FM;


}
fin.close();



        }
        break;

        case 'D':
 k2=0.3;
        {
        fstream fin;
         fin.open ("Difensori.txt");
        for(int i=0;i<10;i++)
         {
        fin>>arraygioc[i].nome;
        fin>>arraygioc[i].PG;
        fin>>arraygioc[i].FM;


}
fin.close();

       }

     break;

     case 'C':
       k2=0.5;  {
     fstream fin;
     fin.open ("Centrocampisti.txt");
     for(int i=0;i<10;i++) {
     fin>>arraygioc[i].nome;
     fin>>arraygioc[i].PG;
     fin>>arraygioc[i].FM;



     }
     fin.close();

     }




     break;

     case 'A':
       k2=0.8;  {
     fstream fin;
     fin.open ("Attaccanti.txt");
     for(int i=0;i<10;i++) {
     fin>>arraygioc[i].nome;
     fin>>arraygioc[i].PG;
     fin>>arraygioc[i].FM;


     }
     fin.close();

 }
     break;
    default:    /*nel caso il reparto inserito non sia uno dei quattro previsti il programma segnala errore*/
    do{

    cout << "ATTENZIONE, REPARTO INSERITO NON VALIDO!!" << endl;
    cout << "Riprova." << endl;
    cin  >> reparto;
 }

 while(reparto!='P' && reparto!='C' && reparto!='D' && reparto!='A');

    }

string scelta;
cout<<"Adesso scegli il giocatore, abbi cura di scrivere il cognome in stampatello maiuscolo: ";
cin >> scelta;  /*all' interno del file relativo al reparto chiedo di scegliere il calciatore e carico i suoi dati*/
int cont=0;
for(int i=0;i<10;i++)
{
if(scelta != arraygioc[i].nome)
{ cont++;
}
}
if (cont==10){cout<<"Il calciatore selezionato non e presente nella lista, Riavvia il programma!"<<endl;
 return 0;} /*controllo che il calciatore sia presente nella lista*/
int prezzo;
double coeff;
string sceltasquadra;
cout<<"in che squadra gioca il calciatore ?"<<endl;
cin>>sceltasquadra;
ksquadra scelta1[20];
      fstream fin;   /*il programma legge il file delle squadre e carica il coefficiente della squadra inserita dall' utente*/
     fin.open ("Squadre.txt");
     for(int i=0;i<10;i++) {
     fin>>scelta1[i].squadra;
     fin>>scelta1[i].k1;}
      fin.close();

int cont2=0;
for(int i=0;i<20;i++)
{
if(sceltasquadra == scelta1[i].squadra)
{ coeff=scelta1[i].k1*k2;
}
else {cont2++;}
}
if(cont2==20){cout<<"La squadra selezionata non e presente in Serie A"<<endl;
return 0;} /*controllo che la squadra scelta sia una delle 20 della Serie A*/


for(int i=0;i<10;i++)
{
if(scelta == arraygioc[i].nome)
{ prezzo=PrezzoMax(arraygioc[i].PG, arraygioc[i].FM,coeff,coeffpart);
cout<< "Il prezzo consigliato e' " << prezzo <<endl; }
}
}
/*una volta caricati tutti i dati necessari richiamo la funzione prezzo,la quale,
 in ultimo,calcolera il prezzo consigliato che verra stampato a aschermo*/

