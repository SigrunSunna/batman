#include <iostream>
#include <fstream>

using namespace std;

class DataClass
{
private:
    int i;
    double d;
    char str[50];
    char c;

    bool verbose;

public:

    DataClass()
    {
        i = 0 ;
        d =0.0;
        str[0] = '\0';
        c = '-';
        verbose = true;
    }

    void setVerbose(bool v)
    {
        verbose = v;
    }

    friend istream& operator >>(istream& in, DataClass& data)
    {
        if (data.verbose){
        cout << "Enter an integer: ";
        }
        in >> data.i;
        if (data.verbose){
        cout << "Enter a real number: ";
        }
        in >> data.d;
        if (data.verbose){
        cout << "Enter a string: ";
        }
        in >> data.str;
        if (data.verbose){
        cout << "Enter a character: ";
        }
        in >> data.c;
        return in;
    }

    friend ostream& operator <<(ostream& out, const DataClass& data)
    {
        if (data.verbose) {
        out << "Integer: " ;
        }
        out << data.i << endl;
        if (data.verbose) {
        out << "Real number: ";
        }
        out << data.d << endl;
        if (data.verbose) {
        out << "String: " ;
        }
        out << data.str << endl;
        if (data.verbose) {
        out << "Character: " ;
        }
        out<< data.c << endl;

        return out;

    }


};


int main()
{
    DataClass data1, data2;


   cin >> data1;


   ofstream fout;
    fout.open("binary_file_Dataclass.dat", ios::binary);

    fout.write((char*)(&data1), sizeof(DataClass));

    fout.close();


    ifstream fin;
    fin.open("binary_file_Dataclass.dat", ios::binary);
    if (fin.is_open())
    {
        fin.read((char*)(&data2), sizeof(DataClass));
    }

    else{

        cout << "could not open file" << endl;
    }
    fin.close();

    cout << data2;

   // while()


    return 0;
}
