#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char input()
{
    char inp;
    cin >> inp;
    return inp;
}

char yornInput ()
{
    char inp = 'a';
    while (inp != 'y' && inp !=  'n')
    {
        cout << "Do you wish to continue (y/n)? ";
        cin >> inp;
    }

    return inp;
}


void read()
{
    string str;
    ifstream fin;
    int counter = 0;
    fin.open("randomTexti.txt");        //opna input file stream
    if(fin.is_open())
    {
        while(!fin.eof())               //keyrsla hættir ef við erum kominn á enda skráarinnar
        {
            counter++;                  //línuteljari
            getline(fin, str);
            cout << str << endl;
            if(counter == 10)
            {
                counter = 0;
                char inp = yornInput();
                if(inp == 'n')
                {
                    fin.close();
                    break;
                }
            }
        }
    }
}
void write()
{
    string str;
    ofstream fout;
    fout.open("randomTexti.txt", ios::app);
    if(fout.is_open())
    {
        do
        {
            getline(cin, str);
            if(str[0] == '\\') break;
            fout << str << endl;

        }
        while(str[0] != '\\');
    }
    fout.close();
}

int main()
{
    //velja hvort fallið maður vill nota
    cout << "Read or Write? read = r, write = w, quit = q: ";
    char in = input();
    while(in == 'r' || in == 'w')
    {
        if(in == 'r')
        {
            read();
        }
        if(in == 'w')
        {
            write();
        }
        cout << "Read or Write? read = r, write = w, quit = q: ";
        in = input();
    }
    return 0;
}
