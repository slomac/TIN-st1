
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <unistd.h>
#ifdef _WIN32
    #include <conio.h>
#else
    #include <unistd.h>
    #include <termios.h>
    #include <sys/ioctl.h>
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// ===================================================================
//  Funkcje pomocnicze
// ===================================================================
#ifdef _WIN32
bool kbhit_pp() { return _kbhit() != 0; }
char getch_pp() { return (char)_getch(); }
#else
bool kbhit_pp()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

char getch_pp(void)
{
    char buf = 0;
    struct termios old = {};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}
#endif

// ---- funkcje.cpp ----
void liczby(int a, int b)
{
    int suma = a + b;
    int roznica;
    if (a > b) roznica = a - b;
    else roznica = b - a;
    int iloczyn = a * b;
    // dzielenie tylko gdy dzielnik jest rozny od zera
    bool bZero = (b == 0), aZero = (a == 0);
    int iloczyna = bZero ? 0 : a / b;
    int iloczynb = aZero ? 0 : b / a;
    int potegaa = pow(a, b);
    int potegab = pow(b, a);
    int pierwiasteka = sqrt(a);
    int pierwiastekb = sqrt(b);
    float eksponenta = exp(a);
    float eksponentb = exp(b);

    cout << "Suma: " << suma << endl;
    cout << "Roznica: " << roznica << endl;
    cout << "Iloczyn: " << iloczyn << endl;
    if (bZero) cout << "Iloraz a/b: dzielenie przez zero" << endl;
    else cout << "Iloraz a/b: " << iloczyna << endl;
    if (aZero) cout << "Iloraz b/a: dzielenie przez zero" << endl;
    else cout << "Iloraz b/a: " << iloczynb << endl;
    cout << "Potega a^b: " << potegaa << endl;
    cout << "Potega b^a: " << potegab << endl;
    cout << "Pierwiastek a: " << pierwiasteka << endl;
    cout << "Pierwiastek b: " << pierwiastekb << endl;
    cout << "Eksponent a: " << eksponenta << endl;
    cout << "Eksponent b: " << eksponentb << endl;
}

void kreskaminus(int n)
{
    for (int i = 0; i < n; i++) cout << "-";
}

// ---- cezar.cpp ----
inline int sprawdz(char znak)
{
    // jesli jest mala litera
    if (znak >= 'a' && znak <= 'z') return 0;
    // jesli jest duza litera
    if (znak >= 'A' && znak <= 'Z') return 1;
    // inny znak niz litera
    return 2;
}

void szyfruj(string &tab)
{
    int klucz = 13;

    int pom;
    char a, z;

    for (size_t i = 0; i < tab.size(); i++)
    {
        pom = sprawdz(tab[i]);
        // ustalenie wielkosci litery
        if (pom < 2)
        {
            if (pom == 0)
                a = 'a', z = 'z';
            else
                a = 'A', z = 'Z';

            if (klucz >= 0)
            {
                if (tab[i] + klucz <= z)
                    tab[i] += klucz;
                else
                    tab[i] = tab[i] + klucz - 26;
            }
            else
            {
                if (tab[i] + klucz >= a)
                    tab[i] += klucz;
                else
                    tab[i] = tab[i] + klucz + 26;
            }
        }
    }
}

unsigned long long silniaIteracyjnie(unsigned int n)
{
    unsigned long long wynik = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        wynik *= i;
    }
    return wynik;
}

unsigned long long silnia_rek(unsigned long long n)
{
    if (n <= 1) {
        return 1;
    }
    return n * silnia_rek(n - 1);
}
void Posortuj_1(int a, int b)
{
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    // Zmiany widoczne sa tylko tutaj i gina po zakonczeniu funkcji.
}

// 2. Przekazanie przez wskaznik/adres
void Posortuj_2(int *a, int *b)
{
    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

// 3. Przekazanie przez referencje/alias
void Posortuj_3(int &a, int &b)
{
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

void autor()
{
    // wypisuje imie, nazwisko oraz numer albumu
    cout << "Maciej Slominski, numer albumu 296250";
}

int dodaj(int a, int b)
{
    return a + b; // zwraca sume dwoch liczb calkowitych
}

double polekola(int r)
{
    return M_PI * r * r; // PI * r * r to wzor na pole kola
}

void sortujRosnaco(int &a, int &b)
{
    if (a > b) {
        int temp;
        temp = a; // zapisuje wieksza liczbe a w zmiennej tymczasowej
        a = b;    // mniejsza liczba b zostaje wpisana do zmiennej a
        b = temp; // poprzednia wartosc a zostaje przypisana do b
    }
    cout << "Wieksza liczba: " << b << " Mniejsza liczba: " << a << endl;
}

int potega(int a, int b)
{
    int temp = a; // wpisuje a do zmiennej tymczasowej, aby nie zmienial sie wykladnik
    for (int i = 1; i < b; i++) {
        a = a * temp;
    }
    return a;
}

long long fibonacci(int n)
{
    if (n <= 0) return 0;
    if (n == 1) return 1;
    long long a = 0;
    long long b = 1;
    long long c = 0;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c; // liczenie liczby fibonacciego
    }
    return b;
}

bool pierwsza(int a)
{
    int licznik = 0;
    if (a < 2) return false;
    for (int i = 2; i * i <= a; i++) { // sprawdzam tylko liczby do pierwiastka z a
        if (a % i == 0) licznik++;
    }
    if (licznik > 0) return false; // jesli liczba dzielnikow wynosi 0, liczba jest pierwsza
    return true;
}

double Euler(int x)
{
    double e = 1.0;
    double wyraz = 1.0;

    for (int i = 1; i <= x; ++i) {
        wyraz /= i;
        e += wyraz;
    }

    return e;
}

int nwd(int a, int b)
{
    while (b != 0) {
        int pom = b;
        b = a % b;
        a = pom;
    }
    return a;
}

// treningowe1.cpp - suma i srednia liczb z zakresu [a, b]
void treningowe1()
{
    float a, b;
    cout << "Podaj liczbe a: ";
    cin >> a;
    cout << "Podaj liczbe b: ";
    cin >> b;
    float suma = 0;
    float min;
    float max;
    if (a < b) { min = a; max = b; }
    else { min = b; max = a; }
    for (int i = min; i <= max; i++) { suma = suma + i; }
    float srednia = suma / (max - min + 1);

    cout << "suma liczb od " << min << " do " << max << " wynosi: " << suma << endl;
    cout << "srednia liczb od " << min << " do " << max << " wynosi: " << srednia << endl;
}

// treningowe2.cpp - suma i srednia 10 liczb
void treningowe2()
{
    cout<<"Podaj 10 liczb calkowitych: "<<endl;
    int tab[10];
    for (int i = 0; i < 10; i++) {
        
        cin >> tab[i];
    }
    float suma = 0;
    for (int i = 0; i < 10; i++) {
        suma = suma + tab[i];
    }
    float srednia = suma / 10;
    cout << "suma liczb wynosi: " << suma << endl;
    cout << "srednia liczb wynosi: " << srednia << endl;
}

// treningowe3.cpp - 10 losowych liczb z zakresu 0-100
void treningowe3()
{
    int randomowa = 0;
    for (int i = 0; i < 10; i++) {
        randomowa = rand() % 101;
        cout << "Wylosowana liczba to " << randomowa << endl;
    }
}

// treningowe4.cpp - rzuty dwiema kostkami
void treningowe4()
{
    int kosc1 = 0;
    int kosc2 = 0;
    for (int i = 0; i < 10; i++) {
        cout << "rzut numer: " << i + 1 << endl;
        kosc1 = rand() % 6 + 1;
        kosc2 = rand() % 6 + 1;
        cout << "Wylosowana liczba na pierwszej kosci to " << kosc1 << endl;
        cout << "Wylosowana liczba na drugiej kosci to " << kosc2 << endl;
    }
}

// treningowe5.cpp - tabliczka mnozenia 10x10
void treningowe5()
{
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
    }
}

// treningowe6.cpp - silnia z n (petla)
void treningowe6()
{
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;
    int wynik = 1;
    for (int i = 1; i <= n; i++) {
        wynik = wynik * i;
    }
    cout << "silnia z liczby " << n << " wynosi: " << wynik << endl;
}

// treningowe7.cpp - pierwsze 10 wyrazow ciagu Fibonacciego
void treningowe7()
{
    long long t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 1; i <= 10; ++i) {
        if (i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if (i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << ", ";
    }
    cout << endl;
}

// treningowe8.cpp - przyblizenie liczby pi (algorytm Gaussa-Legendre'a)
void treningowe8()
{
    int iterations = 5; // Kazda iteracja podwaja liczbe poprawnych cyfr

    double a = 1.0;
    double b = 1.0 / std::sqrt(2.0);
    double t = 1.0 / 4.0;
    double p = 1.0;

    for (int i = 0; i < iterations; ++i) {
        double a_next = (a + b) / 2.0;
        double b_next = std::sqrt(a * b);
        double t_next = t - p * std::pow(a - a_next, 2);
        double p_next = 2.0 * p;

        a = a_next;
        b = b_next;
        t = t_next;
        p = p_next;
    }

    double pi_approx = std::pow(a + b, 2) / (4.0 * t);

    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Przyblizenie liczby pi: " << pi_approx << '\n';
    std::cout << std::defaultfloat << std::setprecision(6);
}

// zajecia3_1.cpp - dzialania na dwoch liczbach (korzysta z liczby())
void zajecia3_1()
{
    int a, b;
    cout << "Podaj dwie liczby calkowite: ";
    cin >> a >> b;
    liczby(a, b);
}

// zajecia3_2.cpp - kategoria wzrostu
void zajecia3_2()
{
    float wzrost;
    cout << "Podaj swoj wzrost w centymetrach: ";
    cin >> wzrost;
    if (wzrost < 150) cout << "Jestes niski" << endl;
    else if (wzrost >= 150 && wzrost < 180) cout << "Jestes sredniego wzrostu" << endl;
    else cout << "Jestes wysoki" << endl;
}

// zajecia3_3.cpp - rozpoznawanie wcisnietego klawisza
void zajecia3_3()
{
    cout << " Wcisnij dowolony klawisz: ";

    unsigned char znak;
    znak = getch_pp();
    cout << endl;
    if (znak <= 122 and znak >= 97) { cout << "mala litera" << endl; return; }
    else if (znak <= 90 and znak >= 65) { cout << "duza litera" << endl; return; }
    else if (znak <= 57 and znak >= 48) { cout << "cyfra" << endl; return; }
    if (kbhit_pp()) {
        char znak2 = getch_pp();
        if (znak2 == '[') {
            char znak3 = getch_pp();
            if (znak3 == 'D') cout << "strzalka w lewo" << endl;
            else if (znak3 == 'C') cout << "strzalka w prawo" << endl;
            else if (znak3 == '1') {
                char znak4 = getch_pp();
                char znak5 = getch_pp();
                if (znak4 == '1' && znak5 == '~') cout << "przycisk F1" << endl;
            }
        }
        else if (znak2 == 'O') {
            char znak3 = getch_pp();
            if (znak3 == 'P') cout << "przycisk F1" << endl;
        }
    } else {
        cout << "przycisk ESC" << endl;
    }
}

// zajecia3_4.cpp - proste menu (Hello World / dodawanie / powtarzanie zdania)
void zajecia3_4()
{
    int znak;
    int a, b;
    string wyraz;
    do {
        cout << "Witaj!" << endl << "Wybierz jedna z opcji, aby kontynuowac:" << endl <<
            "1. Aby napisac Hello World, Wcisnij 1" << endl
            << "2. Aby dodac do siebie 2 liczby ktore wybierzesz, wcisnij 2" << endl <<
            "3. Aby wyswietlic 4 razy zdanie, ktore mi podasz, wcisnij 3" << endl <<
            "4. Aby zakonczyc, wcisnij 4" << endl;
        if (!(cin >> znak)) break;
        if (znak == 1) cout << "Hello, World!" << endl;
        else if (znak == 2) {
            cout << "Podaj dwie liczby: ";
            cin >> a >> b;
            cout << "suma tych liczb to: " << a + b << endl;
        }
        else if (znak == 3) {
            cout << "Podaj zdanie, ktore mam powtorzyc:" << endl;
            cin >> wyraz;
            cout << endl;

            cout << wyraz << endl;
        }

    } while (znak != 4);
    cout << "Do Zobaczenia!" << endl;
}

// zajecia3_petle1.cpp - linia o zadanej dlugosci
void zajecia3_petle1()
{
    int a;
    cout << "podaj dlugosc linii: ";
    cin >> a;
    kreskaminus(a);
    cout << endl;
}

// zajecia3_petle2.cpp - liczenie znakow do wpisania 'k' / 'K'
void zajecia3_petle2()
{
    char k;
    int licznikduzych = 0;
    int licznik = 0;
    do {
        cin >> k;
        licznik++;
        if (k <= 90 and k >= 65) licznikduzych++;
    } while (k != 'K' and k != 'k');
    cout << "liczba znakow przed 'k': " << licznik - 1 << endl;
    cout << "liczba duzych znakow przed 'K': " << licznikduzych << endl;
}

// zajecia3_petle3.cpp - suma, srednia, max i min wpisanych liczb
void zajecia3_petle3()
{
    int licznik = 0;
    int suma = 0;
    int max = -1298346132;
    int min = 127203947;
    string pytanie;
    int liczba;
    do {
        cout << "podaj liczbe: ";
        cin >> liczba;
        cout << endl;
        suma = suma + liczba;
        if (liczba > max) max = liczba;
        if (min > liczba) min = liczba;
        licznik++;

        cout << "Czy koniec wprowadzania? T/N: ";
        cin >> pytanie;
    } while (pytanie != "T");

    float srednia = (float)suma / licznik;
    cout << "suma podanych liczb: " << suma << endl;
    cout << "srednia podanych liczb: " << srednia << endl;
    cout << "maksymalna z podanych liczb: " << max << endl;
    cout << "minimalna z podanych liczb: " << min << endl;
}

// zajecia3_petle4.cpp - suma szeregu 1 + 1/2 + ... + 1/n
void zajecia3_petle4()
{
    int n;
    cout << "Podaj liczbe n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Liczba n musi byc wieksza od zera!" << endl;
        return;
    }

    double suma = 0.0;

    for (int i = 1; i <= n; ++i) {
        suma += 1.0 / i; // 1.0 wymusza dzielenie zmiennoprzecinkowe
    }

    cout << "Suma szeregu dla n = " << n << " wynosi: " << suma << endl;
}

// zajecia3_petle5.cpp - choinka z gwiazdek
void zajecia3_petle5()
{
    int wysokosc;
    cout << "Podaj wysokosc choinki: ";
    cin >> wysokosc;

    if (wysokosc <= 0) {
        cout << "Wysokosc musi byc wieksza od zera!" << endl;
        return;
    }

    for (int i = 1; i <= wysokosc; ++i) {

        // 1. spacje wiodace (wysrodkowanie choinki)
        for (int j = 0; j < wysokosc - i; ++j) {
            cout << " ";
        }

        // 2. gwiazdki (1, 3, 5, 7...)
        for (int k = 0; k < (2 * i - 1); ++k) {
            cout << "*";
        }

        cout << endl;
    }
}

// zajecia4.cpp - przekazywanie parametrow: wartosc / wskaznik / referencja
void zajecia4()
{
    int x, y;
    cout << "podaj dwie liczby:";
    cin >> x >> y;

    // Test Posortuj_1 (przez wartosc)
    int x1 = x, y1 = y;
    cout << "Przed Posortuj_1: x = " << x1 << ", y = " << y1 << endl;
    Posortuj_1(x1, y1);
    cout << "Po Posortuj_1 (brak zmian): x = " << x1 << ", y = " << y1 << "\n\n";

    // Test Posortuj_2 (przez wskaznik)
    int x2 = x, y2 = y;
    cout << "Przed Posortuj_2: x = " << x2 << ", y = " << y2 << endl;
    Posortuj_2(&x2, &y2);
    cout << "Po Posortuj_2 (posortowane): x = " << x2 << ", y = " << y2 << "\n\n";

    // Test Posortuj_3 (przez referencje)
    int x3 = x, y3 = y;
    cout << "Przed Posortuj_3: x = " << x3 << ", y = " << y3 << endl;
    Posortuj_3(x3, y3);
    cout << "Po Posortuj_3 (posortowane): x = " << x3 << ", y = " << y3 << endl;
}

// zajecia5.cpp - zestaw funkcji (autor, dodaj, polekola, sortujRosnaco, potega,
//                fibonacci, pierwsza, Euler, nwd)
void zajecia5()
{
    autor();
    cout << endl;

    int a, b;
    cout << "Podaj dwie liczby calkowite: ";
    cin >> a >> b;
    cout << "Dodawanie: " << dodaj(a, b) << endl;

    cout << "Podaj promien kola, ktorego pole mam obliczyc: ";
    int r;
    cin >> r;
    cout << "Pole kola: " << polekola(r) << endl;

    cout << "Podaj dwie liczby, ktore mam posortowac: ";
    int c, d;
    cin >> c >> d;
    sortujRosnaco(c, d);

    cout << "podaj wykladnik oraz potege: " << endl;
    int e, f;
    cin >> e >> f;
    cout << potega(e, f) << endl;

    cout << "Podaj, ktory element ciagu fibbonaciego chcesz abym policzyl: " << endl;
    int g;
    cin >> g;
    cout << g << " Liczba fibonacciego to: " << fibonacci(g) << endl;

    cout << "Podaj liczbe, a ja sprawdze czy jest pierwsza: " << endl;
    int h;
    cin >> h;
    if (pierwsza(h) == 1) cout << "Pierwsza" << endl;
    else cout << "Nie jest pierwsza" << endl;

    cout << "Podaj dokladnosc obliczen liczby eulera: " << endl;
    int z;
    cin >> z;
    cout << "Liczba eulera z dokladnoscia " << z << " iteracji: " << setprecision(z) << Euler(z) << endl;
    cout << setprecision(6);

    cout << "Podaj dwie liczby, ktorych NWD chcesz obliczyc: " << endl;
    int i, j;
    cin >> i;
    cin >> j;
    cout << "NWD tych liczb to: " << nwd(i, j) << endl;
}


int main(){
    int wybor;
    do{
    cout<<"=========== MENU ==========="<<endl;
    cout<<"1.suma i srednia 10 liczb"<<endl;
    cout<<"2.10 losowych liczb"<<endl;
    cout<<"3.10-cio krotny rzut dwiema kosciami"<<endl;
    cout<<"4.tabliczka mnozenia"<<endl;
    cout<<"5.silnia z liczby n"<<endl;
    cout<<"6.ciag Fibonacciego"<<endl; 
    cout<<"7.przyblizenie liczby pi"<<endl;
    cout<<"8.dzialania na 2 liczbach"<<endl;
    cout<<"9.Czy jestes wysoki?"<<endl;
    cout<<"10.rozpoznawanie klawisza"<<endl;
    cout<<"11.menu z komendami z zajec 3 zadania 4  "<<endl;
    cout<<"12.linia z kresek"<<endl;
    cout<<"13.liczenie znakow do 'k'"<<endl;
    cout<<"14.suma, srednia, max, min"<<endl;
    cout<<"15.suma szeregu 1/i"<<endl;
    cout<<"16.choinka"<<endl;
    cout<<"17.parametry: wartosc/wskaznik/referencja"<<endl;
    cout<<"18.zestaw funkcji (NWD, Fibonacci, ...)"<<endl;
    cout<<"0. Wyjscie"<<endl;
    cout<<"Wybierz program: ";
    
    cin>>wybor;
    if(wybor==1) treningowe2();
    else if(wybor==2) treningowe3();
    else if(wybor==3) treningowe4();
    else if(wybor==4) treningowe5();
    else if(wybor==5) treningowe6();
    else if(wybor==6) treningowe7();
    else if(wybor==7) treningowe8();
    else if(wybor==8) zajecia3_1();
    else if(wybor==9) zajecia3_2();
    else if(wybor==10) zajecia3_3();
    else if(wybor==11) zajecia3_4();
    else if(wybor==12) zajecia3_petle1();
    else if(wybor==13) zajecia3_petle2();
    else if(wybor==14) zajecia3_petle3();
    else if(wybor==15) zajecia3_petle4();
    else if(wybor==16) zajecia3_petle5();
    else if(wybor==17) zajecia4();
    else if(wybor==18) zajecia5();
    else cout<<"Niepoprawny wybor."<<endl;
    sleep(1);
    cout<<endl;
    system("read -n 1 -s -p \"Nacisnij dowolny klawisz, aby kontynuowac...\"");
    cout<<endl;
    }while(wybor!=0);
    cout<<"Do zobaczenia!"<<endl;
    return 0;
}