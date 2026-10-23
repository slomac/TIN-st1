 #include <unistd.h>
    #include <termios.h>
    #include <cstdio>
    #include <iostream>
    #include <sys/ioctl.h>

    using namespace std;


    bool kbhit()
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

    char getch(void)
    {
        char buf = 0;
        struct termios old = {0};
        fflush(stdout);
        if(tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if(tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if(read(0, &buf, 1) < 0)
            perror("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if(tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        //printf("%c\n", buf);
        return buf;
    }
    int main(){
        int znak;
        int a, b;
        string wyraz;
        do{
        cout<<"Witaj!"<<endl<<"Wybierz jedna z opcji, aby kontynuowac:"<<endl<<
        "1. Aby napisac Hello World, Wcisnij 1"<<endl
        <<"2. Aby dodac do siebie 2 liczby ktore wybierzesz, wcisnij 2"<<endl<<
        "3. Aby wyswietlic 4 razy zdanie, ktore mi podasz, wcisnij 3"<<endl<<
        "4. Aby zakonczyc, wcisnij 4"<<endl;
         cin>>znak;
         if(znak == 1) cout<<"Hello, World!"<<endl;
         else if(znak == 2){
            cout<<"Podaj dwie liczby: ";
            cin>>a>>b;
            cout<<"suma tych liczb to: "<<a+b<<endl;
         }
         else if(znak ==3){
            cout<<"Podaj zdanie, ktore mam powtorzyc:"<<endl;
            cin>>wyraz;
            cout<<endl;
        
            cout<<wyraz<<endl;
         }

        }while(znak != 4);
        cout<<"Do Zobaczenia!";
        return 0;
    }