#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class Writer {
public:
	virtual void ScrieInFisierTxt(ofstream& file) = 0;
};

//------------------------------------------------------clasa-Carte+clasa Tip-------------------------------------------------------------------
class Tip
{
protected:
	string gen;
public:
	virtual string tip() = 0;

	Tip()
	{
		gen = "stiintific";
	}
	Tip(string gen)
	{
		this->gen = gen;
	}
	string getGen()
	{
		return gen;
	}
	void setGen(string gen)
	{
		this->gen = gen;
	}
	Tip(const Tip& t)
	{
		this->gen = t.gen;
	}
	Tip& operator=(const Tip& t)
	{
		this->gen = gen;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Tip& t)
	{
		out << "Gen:" << t.gen << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Tip& t)
	{
		cout << "Dati gen: ";
		in >> t.gen;
		return in;
	}
	friend ifstream& operator>>(ifstream& file, Tip& t)
	{
		file >> t.gen;
		return file;
	}



};

class Carte :public Tip
{
protected:
	int const id;
	static int contor;
	char* nume;
	string autor;
	int nr_pag;

public:
	//constructor 1 fara parametrii
	Carte() :Tip(), id(contor++)
	{
		nume = new char[strlen("Matematica") + 1];
		strcpy_s(nume, strlen("Matematica") + 1, "Matematica");
		autor = "Urdea Ion";
		nr_pag = 200;
	}
	//constructor 2 cu toti parametrii
	Carte(const char* nume, string autor, int nr_pag) :Tip(), id(contor++)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->autor = autor;
		this->nr_pag = nr_pag;

	}
	//constructor 3 cu o parte din parametrii
	Carte(string autor, int nr_pag) :Tip(), id(contor++)
	{
		this->nume = nume = new char[strlen("Nunta in cer") + 1];
		strcpy_s(nume, strlen("Nunta in cer") + 1, "Nunta in cer");
		this->autor = autor;
		this->nr_pag = nr_pag;
	}
	//constructor 4 cu o parte din parametrii
	Carte(string autor) :Tip(), id(contor++)
	{
		this->nume = nume = new char[strlen("Poezii") + 1];
		strcpy_s(nume, strlen("Poezii") + 1, "Poezii");
		this->autor = autor;
		this->nr_pag = 300;

	}
	//constructor 5 cu o parte din parametrii
	Carte(int nr_pag) :Tip("actiune"), id(contor++)
	{
		this->nume = nume = new char[strlen("Amintiri din copilarie") + 1];
		strcpy_s(nume, strlen("Amintiri din copilarie") + 1, "Amintiri din copilarie");
		this->autor = "Ion Creanga";
		this->nr_pag = nr_pag;

	}
	//geteri si seteri
	string getGen()
	{
		return this->gen;
	}
	void setGen(string gen)
	{
		this->gen = gen;
	}
	char* getNume()
	{
		return nume;
	}
	void setNume(const char* nume)
	{
		delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

	}
	string getAutor()
	{
		return autor;
	}
	void setAutor(string autor)
	{
		this->autor = autor;
	}
	int getNrPag()
	{
		return nr_pag;
	}
	void setNrPag(int nr_pag)
	{
		if (nr_pag >= 0)
			this->nr_pag = nr_pag;
		else this->nr_pag = 0;
	}
	//operator scriere<<
	friend ostream& operator<< (ostream& out, const Carte& carte)
	{
		out << endl << "Id: " << carte.id << endl;
		out << "Titlu: " << carte.nume << endl;
		out << "Autor: " << carte.autor << endl;
		out << "Numar pagini:" << carte.nr_pag << endl;
		out << (Tip&)carte;
		return out;

	}
	//operator citire>>
	friend istream& operator>>(istream& in, Carte& carte)
	{
		cout << "Dati titlu: ";
		char buff[50];
		in >> buff;
		if (carte.nume != NULL) delete[] carte.nume;
		carte.nume = new char[strlen(buff) + 1];
		strcpy_s(carte.nume, strlen(buff) + 1, buff);
		cout << "Dati autorul: ";
		in >> carte.autor;
		cout << "Dati nr pagini: ";
		in >> carte.nr_pag;
		in >> (Tip&)carte;
		return in;
	}
	//operator citire din fisier
	friend ifstream& operator>>(ifstream& file, Carte& carte)
	{
		if (carte.nume != NULL) delete[] carte.nume;
		char buff[50];
		file >> buff;
		file >> carte.autor >> carte.nr_pag;
		file >> (Tip&)carte;
		carte.nume = new char[strlen(buff) + 1];
		strcpy_s(carte.nume, strlen(buff) + 1, buff);
		return file;
	}
	//constructor de copiere
	Carte(const Carte& carte) :Tip(carte), id(carte.id)
	{

		this->nume = new char[strlen(carte.nume) + 1];
		strcpy_s(this->nume, strlen(carte.nume) + 1, carte.nume);
		this->autor = carte.autor;
		this->nr_pag = carte.nr_pag;


	}
	//operatorul=
	Carte& operator=(const Carte& carte)
	{
		if (this != &carte)
		{
			Tip::operator=(carte);
			if (this->nume != NULL) delete[] this->nume;
			this->nume = new char[strlen(carte.nume) + 1];
			strcpy_s(this->nume, strlen(carte.nume) + 1, carte.nume);
			this->autor = carte.autor;
			this->nr_pag = carte.nr_pag;
		}
		return *this;
	}
	//operatori:
	//1.
	bool operator>(const Carte& c)
	{
		return this->nr_pag > c.nr_pag;
	}
	//2.
	bool operator ==(const Carte& c)
	{
		return this->autor == c.autor;
	}
	//3.
	Carte operator++()
	{
		this->nr_pag += 100;
		return *this;
	}
	//4.
	Carte operator++(int)
	{
		Carte c = *this;
		this->nr_pag += 100;
		return c;
	}
	//5.
	Carte operator+(const Carte& c)
	{
		Carte aux = *this;
		aux.nr_pag = this->nr_pag + c.nr_pag;
		return aux;
	}
	//destructor
	string tip()
	{
		return "online";
	}
	~Carte()
	{
		if (this->nume != NULL)
			delete[]this->nume;
	}




};
int Carte::contor = 1111;
//-------------------------------------------------------clasa mostenire Manual(is a)-----------------------------------------------
class Manual :public Carte
{
protected:
	string materie;
	int clasa;
public:
	Manual() :Carte()
	{
		this->materie = "Matematica";
		this->clasa = 9;
	}
	Manual(string materie, int clasa) :Carte()
	{
		this->materie = materie;
		this->clasa = clasa;
	}
	Manual(string materie) :Carte()
	{
		this->materie = materie;
		this->clasa = 10;
	}
	Manual(int clasa) :Carte()
	{
		this->materie = "Matematica";
		this->clasa = clasa;
	}
	Manual(const Manual& m) :Carte(m)
	{
		this->materie = m.materie;
		this->clasa = m.clasa;
	}
	Manual& operator=(const Manual& m)
	{
		if (this != &m)
		{
			Carte::operator=(m);
			this->materie = m.materie;
			this->clasa = m.clasa;
		}
		return *this;
	}
	void setMaterie(string materie)
	{
		this->materie = materie;
	}
	void setClasa(int clasa)
	{
		this->clasa = clasa;
	}
	string getMaterue()
	{
		return materie;
	}
	int getClasa()
	{
		return clasa;
	}
	friend ostream& operator<<(ostream& out, Manual& m)
	{
		out << (Carte&)m;
		out << "Materia: " << m.materie;
		out << endl << "Clasa: " << m.clasa;
		return out;
	}
	friend istream& operator>>(istream& in, Manual& m)
	{
		in >> (Carte&)m;
		cout << "\nIntroduceti materia: ";
		in >> m.materie;
		cout << "Introduceti clasa: ";
		in >> m.clasa;
		return in;
	}
};

//-------------------------------------------------------clasa Interactiune---------------------------------------------------------
class Interactiune :public Carte
{
protected:
	int click_s;
	int click_d;
	float timp;
	Carte carte_accesata;
public:
	//Constructor 1: fara parametrii
	Interactiune() :Carte()
	{
		this->click_s = 3;
		this->click_d = 4;
		this->timp = 50;

	}
	//Constructor 2 cu toti parametrii
	Interactiune(int click_s, int click_d, float timp) :Carte()
	{
		this->click_s = click_s;
		this->click_d = click_d;
		this->timp = timp;
	}
	//Constructor 3 cu o parte din parametrii
	Interactiune(int click_s, int click_d) :Carte()
	{
		this->click_s = click_s;
		this->click_d = click_d;
		this->timp = 60;
	}
	//constructor 4 cu o parte din parametrii
	Interactiune(float timp, string autor) :Carte(autor)
	{
		this->click_d = 9;
		this->click_s = 1;
		this->timp = timp;

	}
	//constructor 5 cu o parte din parametrii
	Interactiune(int click_s)
	{
		this->click_s = click_s;
		this->click_d = 0;
		this->timp = 76;
	}
	//geteri si seteri

	int getClick_s()
	{
		return click_s;
	}
	void setClick_s(int click_s)
	{
		if (click_s >= 0)
			this->click_s = click_s;
		else cout << "Numarul nu poate fi decat pozitiv";
	}
	int getClick_d()
	{
		return click_d;
	}
	void setClick_d(int click_d)
	{
		if (click_d >= 0)
			this->click_d = click_d;
		else cout << "Numarul nu poate fi decat pozitiv";
	}
	float getTimp()
	{
		return timp;
	}
	void setTimp(float timp)
	{
		if (timp >= 0)
			this->timp = timp;
		else cout << "Numarul nu poate fi decat pozitiv";
	}
	//operator scriere<<
	friend ostream& operator<<(ostream& out, const Interactiune& i)
	{
		out << (Carte&)i;
		out << "Click-uri stanga: " << i.click_s;
		out << "\nClick-uri dreapta: " << i.click_d;
		out << "\nTimp: " << i.timp << " secunde";
		return out;
	}
	//operator citire>>
	friend istream& operator>> (istream& input, Interactiune& i)
	{
		input >> (Carte&)i;
		cout << "Cate click-uri stanga a efectuat? "; input >> i.click_s;
		cout << "Cate click-uri dreapta a efectuat? "; input >> i.click_d;
		cout << "Cat de mult a durat sa se autentifice? "; input >> i.timp;
		return input;
	}
	//operator citire din fisier
	friend ifstream& operator>>(ifstream& file, Interactiune& i)
	{
		file >> (Carte&)i;
		file >> i.click_s;
		file >> i.click_d;
		file >> i.timp;
		return file;
	}
	//constructor de copiere
	Interactiune(const Interactiune& i) :Carte(i)
	{
		this->click_d = i.click_d;
		this->click_s = i.click_s;
		this->timp = i.timp;

	}
	//operator=
	Interactiune& operator=(const Interactiune& i)
	{
		if (this != &i)
		{
			Carte::operator=(i);
			this->click_d = i.click_d;
			this->click_s = i.click_s;
			this->timp = i.timp;

		}
		return *this;
	}

	//operatori:
	//1.
	bool operator<(const Interactiune& i)
	{
		return this->timp < i.timp;
	}
	//2.
	Interactiune operator--()
	{
		if (this->click_d > 0)this->click_d--;
		if (this->click_s > 0)this->click_s--;
		return *this;
	}
	//3.
	Interactiune operator--(int)
	{
		Interactiune cop = *this;
		if (this->click_d > 0)this->click_d--;
		if (this->click_s > 0)this->click_s--;
		return cop;
	}
	//4.
	Interactiune operator+=(int j)
	{
		this->timp += j;
		return *this;
	}
	//5.
	Interactiune operator-=(int j)
	{
		this->timp -= j;
		return *this;
	}


};
//---------------------------------------------------------clasa User---------------------------------------------
class User
{
protected:
	int id_unic;
	string nume_user;
	string parola;
	int nr_int;
	Interactiune* interactiuni;
public:
	//Constructor 1 fara parametrii
	User()
	{
		this->id_unic = 0;
		this->nume_user = "USER";
		this->parola = "PAROLA";
		this->nr_int = 0;
		this->interactiuni = NULL;
	}
	//Constructor 2 cu toti parametrii
	User(int id_unic, string nume_user, string parola, int nr_int, Interactiune* interactiuni)
	{
		this->id_unic = id_unic;
		this->nume_user = nume_user;
		this->parola = parola;
		this->nr_int = nr_int;
		this->interactiuni = new Interactiune[nr_int];
		for (int i = 0;i < nr_int;i++)
		{
			this->interactiuni[i] = interactiuni[i];
		}

	}
	//Constructor 3 cu o parte din parametrii
	User(int id_unic)
	{
		this->id_unic = id_unic;
		this->nume_user = "USER";
		this->parola = "PAROLA";
		this->nr_int = 0;
		this->interactiuni = NULL;
	}
	//Constructor 4 cu o parte din parametrii
	User(int id_unic, string nume_user)
	{
		this->id_unic = id_unic;
		this->nume_user = nume_user;
		this->parola = "PAROLA";
		this->nr_int = 0;
		this->interactiuni = NULL;
	}
	//Constructor 5 cu o parte din parametrii
	User(int id_unic, string nume_user, string parola)
	{
		this->id_unic = id_unic;
		this->nume_user = nume_user;
		this->parola = parola;
		this->nr_int = 0;
		this->interactiuni = NULL;

	}
	//Constructor de copiere:
	User(const User& user)
	{
		this->id_unic = user.id_unic;
		this->nume_user = user.nume_user;
		this->parola = user.parola;
		this->nr_int = user.nr_int;
		delete[]this->interactiuni;
		if (user.nr_int == 0)
			this->interactiuni = NULL;
		else
		{
			this->interactiuni = new Interactiune[user.nr_int];
			for (int i = 0;i < user.nr_int;i++)
				this->interactiuni[i] = user.interactiuni[i];
		}


	}
	//Operatorul=
	User& operator=(const User& u)
	{
		if (this != &u)
		{
			this->id_unic = u.id_unic;
			this->nume_user = u.nume_user;
			this->parola = u.parola;
			this->nr_int = u.nr_int;
			if (u.nr_int == 0)
				this->interactiuni = NULL;
			else
			{
				this->interactiuni = new Interactiune[u.nr_int];
				for (int i = 0;i < u.nr_int;i++)
					this->interactiuni[i] = u.interactiuni[i];
			}

		}
		return *this;
	}
	//seteri si geteri
	int getIdUnic()
	{
		return id_unic;
	}
	void setIdUnic(int id_unic)
	{
		this->id_unic = id_unic;
	}
	string getNumeUser()
	{
		return nume_user;
	}
	void setNumeUser(string nume_user)
	{
		this->nume_user = nume_user;
	}
	string getParola()
	{
		return parola;
	}
	void setParola(string parola)
	{
		this->parola = parola;
	}
	int getNrInt()
	{
		return nr_int;
	}
	Interactiune* getInteractiuni()
	{
		if (nr_int != 0)return interactiuni;
		else return NULL;
	}
	void setInteractiuni(int nr_int, Interactiune* interactiuni)
	{
		if (this->interactiuni != NULL)
			delete[] this->interactiuni;
		this->nr_int = nr_int;
		this->interactiuni = new Interactiune[nr_int];
		for (int i = 0;i < nr_int;i++)
		{
			this->interactiuni[i] = interactiuni[i];
		}
	}

	//afisare <<
	friend ostream& operator<<(ostream& out, const User& u)
	{
		out << "\nId unic: " << u.id_unic << endl;
		out << "Nume user: " << u.nume_user << endl;
		out << "Parola: ";
		out.width(2 + u.parola.length());
		out.fill('*');
		out << "; " << "    (" << u.parola << ")\n";
		if (u.nr_int != 0)
		{
			out << "Nr interactiuni: " << u.nr_int;
			for (int i = 0;i < u.nr_int;i++)
			{
				out << "\nInteractiunea " << i + 1 << " : ";
				out << u.interactiuni[i];
			}
		}
		else out << "Nu au fost interactiuni";
		out << endl;
		return out;
	}

	//Cei 5 operatori:
	//1.
	Interactiune operator[](int pozitie)
	{
		if (pozitie >= 0 && pozitie < this->nr_int)
			return this->interactiuni[pozitie];
		else
			throw new exception("Nu s a putut, pozitia nu este corecta");
	}

	//2.
	bool operator>=(const User& u)
	{
		return this->parola.length() > u.parola.length();
	}

	//3.
	void operator()(string prelungire)
	{
		this->nume_user = this->nume_user + prelungire;
	}

	//4.
	bool operator!=(const User& u)
	{
		return this->nr_int != u.nr_int;
	}
	//5.
	bool operator<=(const User& u)
	{
		return this->nume_user.length() > u.nume_user.length();
	}



	//citire >>
	friend istream& operator>>(istream& in, User& u)
	{
		cout << "Dati id unic personal: ";
		in >> u.id_unic;
		cout << "Dati nume user: ";
		in >> u.nume_user;
		cout << "Dati parola: ";
		in >> u.parola;
		cout << "Dati numarul de interactiuni:";
		in >> u.nr_int;
		if (u.interactiuni != NULL) delete[] u.interactiuni;
		u.interactiuni = new Interactiune[u.nr_int];
		for (int i = 0;i < u.nr_int;i++)
		{
			cout << "Dati interactiunea " << i + 1 << " :\n";
			in >> u.interactiuni[i];
		}
		return in;

	}

	//citire din fisier
	friend ifstream& operator>>(ifstream& file, User& u)
	{
		file >> u.id_unic;
		file >> u.nume_user;
		file >> u.parola;
		file >> u.nr_int;
		if (u.interactiuni != NULL) delete[] u.interactiuni;
		u.interactiuni = new Interactiune[u.nr_int];
		for (int i = 0;i < u.nr_int;i++)
		{
			file >> u.interactiuni[i];
		}
		return file;

	}
	//destructor
	~User()
	{
		if (this->interactiuni != NULL)
		{
			delete[] this->interactiuni;
		}
	}
};
//"----------------------------------------------------clasa Profil Utilizator---------------------------------------"
class ProfilUser :public Writer
{
private:
	int id_unic;
	int nr_click_s_mediu;
	int nr_click_d_mediu;
	float timp_minim;
	int nr_pag_maxim;
public:
	//Constructor 1 fara parametrii
	ProfilUser()
	{
		id_unic = 0;
		nr_click_s_mediu = 0;
		nr_click_d_mediu = 0;
		timp_minim = 0;
		nr_pag_maxim = 0;
	}
	//Constructor 2 cu parametrii
	ProfilUser(int id_unic, int nr_click_s_mediu, int nr_click_d_mediu, float timp_minim, int nr_pag_maxim)
	{
		this->id_unic = id_unic;
		this->nr_click_s_mediu = nr_click_s_mediu;
		this->nr_click_d_mediu = nr_click_d_mediu;
		this->timp_minim = timp_minim;
		this->nr_pag_maxim = nr_pag_maxim;
	}
	friend ostream& operator<<(ostream& out, const ProfilUser& p)
	{
		out << p.id_unic << endl << p.nr_click_s_mediu << endl << p.nr_click_d_mediu << endl << p.timp_minim << endl << p.nr_pag_maxim << endl;
		return out;
	}
	//Scriere in fisier text
	void ScrieInFisierTxt(ofstream& file)
	{
		file << id_unic;
		file << endl << nr_click_s_mediu;
		file << endl << nr_click_d_mediu;
		file << endl << timp_minim;
		file << endl << nr_pag_maxim << endl;
	}
	//seteri
	void setIdUnic(int id_unic)
	{
		this->id_unic = id_unic;

	}
	int getIdUnic()
	{
		return id_unic;
	}
	void setNrClickSMediu(int nr_click_s_mediu)
	{
		this->nr_click_s_mediu = nr_click_s_mediu;
	}
	int getNrClickSMediu()
	{
		return nr_click_s_mediu;
	}
	void setNrClickDMediu(int nr_click_d_mediu)
	{
		this->nr_click_d_mediu = nr_click_d_mediu;
	}
	int getNrClickDMediu()
	{
		return nr_click_d_mediu;
	}
	void setTimpMinim(float timp_minim)
	{
		this->timp_minim = timp_minim;
	}
	float getTimpMinim()
	{
		return timp_minim;
	}
	void setNrPagMax(int nr_pag_maxim)
	{
		this->nr_pag_maxim = nr_pag_maxim;
	}
	int getNrPagMax()
	{
		return nr_pag_maxim;
	}


};

//-------------------------------------------------------------------Clasa Template-----------------------------------------------
template<typename TIP1, class TIP2>
class Informatii
{
private:
	TIP1 atribut1;
	int nr_ob;
	TIP2* obiecte;
public:
	Informatii()
	{

		atribut1 = 0;
		nr_ob = 0;
		obiecte = NULL;
	}
	Informatii(TIP1 atribut1, int nr_ob, TIP2* obiecte)
	{
		this->atribut1 = atribut1;
		this->nr_ob = nr_ob;
		if (obiecte != NULL)
		{
			this->obiecte = new TIP2[nr_ob];
			for (int i = 0;i < nr_ob;i++)
				this->obiecte[i] = obiecte[i];
		}
		else this->obiecte = NULL;
	}
	TIP2* getObiecte()
	{
		return this->obiecte;
	}
	TIP1 getAtribut()
	{
		return this->atribut1;
	}
	int getNrOb()
	{
		return this->nr_ob;
	}
	~Informatii()
	{
		if (this->obiecte != NULL)
			delete[] this->obiecte;
	}

};

int main()
{
	cout << "------------------------------testare-clasa-Carte(+ clasa abstracta)---------------------------------------------";
	//constructori:
	cout << "\nTest constructori clasa Carte:\n";
	//1.
	cout << "\nConstructor 1:\n";
	Carte c1;
	cout << c1;

	//2.
	cout << "\nConstructor 2:\n";
	char* c;
	c = new char[strlen("Mara") + 1];
	strcpy_s(c, strlen("Mara") + 1, "Mara");
	Carte c2(c, "Ioan Slavici", 158);
	cout << c2;

	//3.
	cout << "\nConstructor 3:\n";
	Carte c3("Mircea Eliade", 128);
	cout << c3;

	//4.
	cout << "\nConstructor 4:\n";
	Carte c4("Mihai Eminescu");
	cout << c4;

	//5.
	cout << "\nConstructor 5:\n";
	Carte c5(210);
	cout << c5;

	//seteri si geteri
	cout << "\nTest seteri si geteri:\n";
	cout << endl << c1.getGen() << ' ' << c1.getNume() << ' ' << c1.getAutor() << ' ' << c1.getNrPag() << endl;
	c1.setGen("actiune");
	c1.setNume(c);
	c1.setAutor("Ioan Slavici");
	c1.setNrPag(158);
	cout << c1.getGen() << ' ' << c1.getNume() << ' ' << c1.getAutor() << ' ' << c1.getNrPag() << endl;

	//operatori scriere/citire
	/*
	cout<<"\nTest citire si scriere:\n"
	Carte c6;
	cin >> c6;
	cout << c6;*/

	//constructor de copiere
	cout << "\nTest constructor de copiere:\n";
	Carte c7 = c2;
	cout << c7;

	//operator=
	cout << "\nTest operator =\n";
	c7 = c3;
	cout << c7;

	//operatori testare:
	cout << "\nTest cei 5 operatori:\n";

	//1.
	cout << "\n1.Operatorul > compara numarul de pagini a doua clase:\n";
	if (c1 > c3) cout << "\nPrima carte are mai multe pagini\n";
	else cout << "\nA treia carte are mai multe pagini\n";

	//2.
	cout << "\n2.Operatorul == arata daca cele doua carti au acelasi autor:\n";
	if (c1 == c2) cout << "\nCartea 1 are acelasi autor precum cartea 2\n";
	else cout << "\nCele doua carti nu au acelasi autor\n";

	//3.
	cout << "\n3.Operatorul ++ preincrementat mareste numarul paginilor cu 100\n";
	++c1;
	cout << c1;

	//4.
	cout << "\n4.Operatorul ++ postincrementat mareste numarul paginilor cu 100\n";
	cout << c2++;
	cout << c2;

	//5.
	cout << "\n5.Operatorul + \n";
	c2 = c1 + c2;
	cout << c2;

	//test functie virtuala si clasa abstracta:
	cout << "\nTest functie virtuala si casa abstracta:\n";
	cout << endl << c1.tip() << endl;

	/* verificare citire din fisier (nu se mai poate utiliza dupa introducerea de informatii in sesiuni.txt)
	Carte c8;
	ifstream file("sesiuni.txt", ios::in);
	file >> c8;
	cout << c8;*/
	cout << "--------------------------------------Clasa mostenire Manual(is a)-------------------";
	Manual m1;
	cout << m1<<endl;
	Manual m2;
	/*cin >> m2;
	cout << endl << m2;*/
	cout << "--------------------------------------clasa-Interactiune----------------------------------\n";
	//Testam constructorii
	cout << "\nTestam constructorii:\n";

	//1.
	cout << "\n\nConstructorul 1:";
	Interactiune i1;
	cout << i1;

	//2.
	cout << "\n\nConstructorul 2:";
	Interactiune i2(2, 2, 30);
	cout << endl << i2;

	//3.
	cout << "\n\nConstructorul 3:";
	Interactiune i3(2, 2);
	cout << endl << i3;

	//4.
	cout << "\n\nConstructorul 4:";
	Interactiune i4(40.5, "Ion Luca Caragiale");
	cout << endl << i4;

	//5.
	cout << "\n\nConstructorul 5:";
	Interactiune i5(4);
	cout << endl << i5;

	//Test geteri si seteri
	cout << "\nTest geteri si seteri:\n";
	cout << endl << i1.getClick_s() << ' ' << i1.getClick_d() << ' ' << i1.getTimp() << ' ' << i1.getAutor() << endl;
	i1.setClick_s(1);
	i1.setClick_d(1);
	i1.setTimp(12.5);
	cout << endl << i1.getClick_s() << ' ' << i1.getClick_d() << ' ' << i1.getTimp() << ' ' << i1.getAutor() << endl;

	//test citire si scriere
	/*
	cout<<"\nTest citire si scriere:\n";
	Interactiune i6;
	cin >> i6;
	cout << endl << i6;*/

	//Test constructor de copiere
	cout << "\nTest constructor de copiere:\n";
	Interactiune i7 = i5;
	cout << i7 << endl;

	//Test operator=
	cout << "\nTest operator =:\n";
	i7 = i4;
	cout << i7 << endl;

	//Test citire din fisier (aceste comenzi nu se vor mai putea executa din pricina faptului ca fisierul text se va schimba pana la sfarsitul ptorgramului)
	/*Interactiune i9;
	ifstream file("sesiuni.txt", ios::in);
	file >> i9;
	cout << i9;*/

	//Test operatori:
	cout << "\nTestam cei 5 operatori:\n";

	//1.
	cout << "\n1.Operatorul < ne arata care dintre cele doua interactiuni a durat mai putin:\n";
	if (i7 < i3)
		cout << " \nTimpul la interactiunea 7 a fost mai scrurt decat la interactiunea 3";
	else cout << " \nTimpul la interactiunea 3 a fost mai scrurt decat la interactiunea 7";

	//2.
	cout << "\n2.Operatorul -- preincrementat modifica clasa scazand numarul de click-uri, daca este posibil:\n";
	--i7;
	cout << endl << i7;

	//3.
	cout << "\n3.Operatorul -- postincrementat modifica clasa scazand numarul de click-uri, daca este posibil:\n";
	cout << endl << i7--;
	cout << endl << i7;

	//4.
	cout << "\n4.Operatorul += modifica timpul utilizat pe aplicatie:\n";
	i7 += 10;
	cout << endl << i7;

	//5.
	cout << "\n5.Operatorul -= modifica timpul utilizat pe aplicatie:\n";
	i7 -= 20;
	cout << endl << i7;

	cout << "\n\n-----------------------------Clasa User---------------------------\n";

	//Constructor 1:
	cout << "\nTestam constructorii:\n\n Constructorul 1:\n";
	User u1;
	cout << u1;

	//Constructor 2:
	cout << "\nConstructorul 2:\n";
	Interactiune vector[] = { i1,i2 };
	User u2(1, "Ion", "STUD", 2, vector);
	cout << u2;

	//Constructor 3:
	cout << "\nConstructorul 3:\n";
	User u3(2);
	cout << u3;

	//Constructor 4:
	cout << "\nConstructorul 4:\n";
	User u4(3, "Marin");
	cout << u4;

	//Constructor 5:
	cout << "\nConstructorul 5\n";
	User u5(4, "Ioana", "STUD");
	cout << u5;

	//Constructor de copiere:
	cout << "\nTestam Constructorul de copiere:\n";
	User u6 = u5;
	cout << u6;

	//Operatorul =
	cout << "\nTestam operatorul =:\n";
	u6 = u2;
	cout << u6;

	//test geteri si seteri
	cout << "\nTestam pentru geteri si seteri: \n";
	cout << endl << u6.getIdUnic();
	cout << endl << u6.getNumeUser();
	cout << endl << u6.getParola();
	cout << endl << u6.getNrInt();
	Interactiune* inte = new Interactiune[u6.getNrInt()];
	inte = u6.getInteractiuni();
	for (int i = 0;i < u6.getNrInt();i++)
		cout << inte[i] << endl << endl;

	//test 5 operatori:
	cout << "Testam cei 5 operatori:\n";
	//1.Operatorul index:
	cout << "\n1.Operatorul index:\n";
	try
	{
		cout << u2[3];
	}
	catch (exception* ex)
	{
		cout << ex->what() << endl;
	}
	//2.Operatorul >=
	cout << "\n2.Operatorul >=:\n";
	if (u2 >= u6) cout << "\nUtilizatorul 2 are o parola mai mare sau egala cu operatorul 6\n";
	else cout << "\nUtilizatorul 2 nu are o parola mai mare decat operatorul 6\n";
	//3.Operatorul() functie
	cout << "\n3.Operatorul() functie adauga prelungire userului\n";
	u2("2");
	cout << endl << u2 << endl;
	//4.Operatorul != testeaza daca utilizatorii au un numar diferit de interactiuni;
	cout << "\n4..Operatorul != testeaza daca utilizatorii au un numar diferit de interactiuni\n";
	if (u2 != u6) cout << "\nCei doi useri au un numar diferit de interactiuni \n";
	else cout << "\nCei doi useri au un numar identic de interactiuni\n";
	//5.Operatorul <=
	cout << "\n5.Operatorul <=: \n";
	if (u2 <= u6) cout << "\nUtilizatorul 2 are un username mai mic sau egal cu userul 6\n\n\n\n";
	else cout << "\nUtilizatorul 2 are o parola mai mare decat userul 6\n\n\n\n";
	//operatori scriere si afisare
	/*
	cout<<"\nTest operatori de scriere si afisare:\n";
	User u7;
	cin >> u7;
	cout << u7;*/



//citire din fisier
	cout << "------------------------------------Citire useri din fisier----------------------------------\n";
	cout << "\nUserii din fisier sunt:\n";
	User* useri;
	useri = new User[10];
	ifstream file("sesiuni.txt", ios::in);
	for (int i = 0;i < 10;i++)
	{
		file >> useri[i];
	}
	file.close();
	for (int i = 0;i < 10;i++)
	{
		cout << endl << useri[i];
	}
	//-------------------------crearea profilului utilizatorilor si scrierea sa in fisier text------------------
	ofstream f("profil.txt", ios::app);
	ProfilUser* p;
	p = new ProfilUser[10];
	for (int i = 0;i < 10;i++)
	{
		int id = useri[i].getIdUnic();
		int click_s_mediu = 0;
		int click_d_mediu = 0;
		float timp_minim = 1000;
		int nr_pag_maxim = 0;
		Interactiune* interactiuni;
		interactiuni = new Interactiune[useri[i].getNrInt()];
		interactiuni = useri[i].getInteractiuni();
		 for (int j = 0;j < useri[i].getNrInt();j++)
		{
			 click_s_mediu += interactiuni[j].getClick_s();
			 click_d_mediu += interactiuni[j].getClick_d();
			 if (interactiuni[j].getTimp() < timp_minim)
				 timp_minim = interactiuni[j].getTimp();
			 if (interactiuni[j].getNrPag() > nr_pag_maxim)
				 nr_pag_maxim = interactiuni[j].getNrPag();

		}
		 click_d_mediu /= useri[i].getNrInt();
		 click_s_mediu /= useri[i].getNrInt();
		 p[i].setIdUnic(id);
		 p[i].setNrClickSMediu(click_s_mediu);
		 p[i].setNrClickDMediu(click_d_mediu);
		 p[i].setTimpMinim(timp_minim);
		 p[i].setNrPagMax(nr_pag_maxim);
		 f << p[i];
		 delete[] interactiuni;

	}
	f.close();

	//---------------------------------------citirea unei sesiuni si determinarea userului------------------------------------------
	/*cout << "\nS-a creat profilul fiecarui uitilizator\n Sa se citeasca o sesiune pentru a determina ce utilizator a efectuat o:\n";
	Interactiune sesiune;
	cin >> sesiune;
	int ok = 1;
	for (int i = 0;i <= 10&&ok==1;i++)
	{
		if (sesiune.getClick_s() == p[i].getNrClickSMediu())
			if (sesiune.getClick_d() == p[i].getNrClickDMediu())
				if (sesiune.getTimp() >= p[i].getTimpMinim())
					if (sesiune.getNrPag() <= p[i].getNrPagMax())
					{
						cout << "S-a recunoscut utilizatorul cu id-ul unic: " << p[i].getIdUnic() << endl;
						ok = 0;
					}


	}
	if (ok == 1) cout << "Nu s a putut recunoaste userul.";*/
	

	cout << "\n\n\n\n--------------------------------------------------Clasa Template Informatii------------------------------\n\n\n\n";
	Informatii<int, Interactiune> info(11, u6.getNrInt(),inte);
	cout << info.getAtribut();
	cout << endl << info.getNrOb();
	Interactiune* interact = new Interactiune[u6.getNrInt()];
	interact = info.getObiecte();
	for (int i = 0;i < u6.getNrInt();i++)
		cout << interact[i] << endl;





	delete[]p;
	delete[] c;
	delete[]inte;
	delete[] useri;

	return 0;
}