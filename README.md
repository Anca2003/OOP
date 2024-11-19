Realizati o aplicatie de tip consola in C++, care sa permita gestiunea profilelor utilizatorilor unei aplicatii.

Fiecare utilizator este identificat printr-un id unic.

Profilul utilizatorului este deteminat pe baza anumitor caracteristici masurate pentru fiecare utilizator. Datele masurate pentru fiecare utilizator sunt citite din fisierul text: sesiuni.txt. Datele in fisier sunt organizate dupa o structura standard decisa de fiecare student in parte.

Se presupune ca datele despre fiecare utilizator sunt masurate si exista in acel fisier.

 

Aplicatia trebuie să realizeze un profil al utilizatorului pe baza datelor din fisier reprezentand interactiunile precedente cu aplicatia pe baza mai multor indicatori realizati de catre student. Dupa stabilirea profilului utilizatorului, la viitoarele logari ale acestuia se verifica daca profilul corespunde modului de interactiune din curenta logare. In cazul in care corespunde inseamna ca utilizatorul este cel de drept si are permisiunea de a interactiona cu aplicatia. In cazul in care profilul nu corespunde sau corespunde intr-un procent redus se considera ca utilizatorul logat in aplicatie nu este cel de drept si trebuie sa fie delogat din aplicatie.

Stabilirea profilului se realizeaza in functie de anumiti indicatori alesi din urmatoarele categorii:

-numarul de click-uri stanga efectuate in aplicatie;

-numarul de click-uri dreapta efectuate in aplicatie;

-locul/zona in care tine cursorul atunci cand nu foloseste mouse-ul;

-modul de rulare (scrollare) a unei pagini (mouse, PageDown, cu mouse-ul folosind controlul VerticalScroll al paginii, sau din sageti);

-viteza de rulare (scrollare);

-viteza de tastare;

-timpul in care tine o tasta apasata la tehnoredactare (in milisecunde);

-modul de stergere al unor cuvinte anterioare (Delete, BackSpace, selectare si folosire meniu contextual pentru stergere sau decupare);

-modul in care scrie caracterele capitalizate (cu CapsLock sau cu Shift);

-ce taste de control (Shift, Alt, Control) foloseste, pe cele din stanga sau pe cele din dreapta tastaturii;

-modul de navigare in aplicatie (foloseste butonul de back al aplicatiei, foloseste butonul de back al browserului, foloseste tasta BackSpace pentru intoarcere la pagina precedenta);

-modul de copiere sau de decupare (foloseste scurtaturile Ctrl+C, Ctrl+X sau foloseste meniul contextual);

 

Se pot adauga si alte caracteristici identificate de voi.

 

Cerinte proiect:

Definirea a minim 3 clase care au legatura cu cerinta proiectului.

Definirea a cel putin o clasa care mosteneste o alta clasa realizata in proiect (exemplificarea conceptului de relatie "is a").

Definirea unei clase abstracta, cu cel putin o functie virtuala. Sa fie exemplificata utilitatea functiilor virtuale.

Definirea a minim un atribut de tip sir de caractere alocat dinamic, si a minim un atribut de tip vector alocat dinamic.

Existența unui atribut static si a unui atribut constant.

Geteri si seterii pentru toate atributele claselor.

Constructuri si operator= pentru toate clasele.

Supraincarcarea operatorilor << si >> pentru fiecare clasa.

Supraincaracarea a cel putin 5 operatori pentru fiecare clasa dintre:  +,-,*,/,+=,-=,*=,++ (post si pre), --(post si pre), [], () (functie), !. (Recomandare: incercati ca cei 15 operatori sa fie diferiti)

Definierea unei clase template care sa poata folosi atat elemente de tip int, float cat si elemente de tipul unei clase create

 

Aplicatia citeste datele din fisierul sesiuni.txt cu privire la sesiunile realizate in cadrul unei aplicatii si pe baza id-ului unic al utilizatorilor construieste un profil generic al fiecarui utilizator, pe baza tuturor sesiunilor realizate de catre utilizatorul respectiv.

Profilele realizate sunt salvate intr-un fisier text. Calea fisierului este citita de la tastatura.

 

Aplicatia permite citirea de la tastatura a datelor unei sesiuni si pe baza profilelor generale realizate, stabileste ce utilizator a realizat aceasta sesiune.
