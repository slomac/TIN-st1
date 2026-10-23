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
    cout<<" Wcisnij dowolony klawisz: ";

    unsigned char znak;
    znak = getch();
    cout<<endl;
    if(znak<=122 and znak>=97){cout<<"mala litera"<<endl; return 0;}
    else if(znak<=90 and znak>=65) {cout<<"duza litera"<<endl; return 0;}
    else if(znak<=57 and znak>=48) {cout<<"cyfra"<<endl; return 0; }
    if(kbhit()) {
        char znak2 = getch();
        if(znak2 == '[') {
            char znak3 = getch();
            if(znak3 == 'D') cout<<"strzalka w lewo"<<endl;
            else if(znak3 == 'C') cout<<"strzalka w prawo"<<endl;
            else if(znak3 == '1') {
                char znak4 = getch();
                char znak5 = getch();
                if(znak4 == '1' && znak5 == '~') cout<<"przycisk F1"<<endl;
            }
        }
        else if(znak2 == 'O') {
            char znak3 = getch();
            if(znak3 == 'P') cout<<"przycisk F1"<<endl;
        }
    } else {
        cout<<"przycisk ESC"<<endl;
    }
}
