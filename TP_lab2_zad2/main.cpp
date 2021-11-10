#include <iostream>
#include <string>
#include<fstream>
using namespace std;

bool checkingFileName(string name_file);
void reading_words_starting_with_vowels(ifstream&);

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-";
string vowels = "AEIOUYaeiouy";

int main()
{
    setlocale(LC_ALL, "rus");
    string name_file;
    cout << "Введите название файла: ";
    //getline(cin, name_file);
    getline(cin, name_file);
    if (checkingFileName(name_file) == true) {
        ifstream fin;
        fin.open(name_file);
        if (!fin)
            cout << "Файл " << name_file << " не открыт" << endl;
        else
        {
            cout << "Файл " << name_file << " открыт" << endl << endl;
            reading_words_starting_with_vowels(fin);
        }
        fin.close();
    }
    else
        cout << "Не верное имя файла или расширение." << endl;
}

void reading_words_starting_with_vowels(ifstream& fin) {
    string s, s1, s_tmp;
    while (getline(fin, s))
    {
        //cout << "s: " << s << endl;
        //cout << "s1: " << s1 << endl;
        while (s != "" && s.find(" ") != string::npos)
        {
            if (s_tmp != "")
            {
                s1 = s_tmp;
                s1 += s.substr(0, s.find_first_of(" "));
                s_tmp = "";
            }
            else
            s1 = s.substr(0, s.find_first_of(" "));
            bool flag = 0;
            if (s1.find_first_of(vowels) == 0 )
            {
                if (s1.find_first_not_of(alphabet) != string::npos)
                {
                    
                    int tmp = s1.find_first_not_of(alphabet) + 1;
                    for (int i = 0; i < alphabet.size(); i++)
                    {
                        if (s1[tmp] == alphabet[i])
                        {
                            cout << "Не верная запись: " << s1 << endl;
                            flag = 1;
                        }
                    }
                   
                }
                if (flag == 0)
                {
                    s1 = s1.substr(0, s1.find_first_not_of(alphabet));
                    cout << s1 << endl;
                }                
            }     
            if (s1.find_first_of(vowels) == 1 && (s1[0] == '"' || s1[0] == '('))
            {
                s1 = s1.substr(1);
                if (s1.find_first_not_of(alphabet) != string::npos)
                    s1 = s1.substr(0, s1.find_first_not_of(alphabet));
                cout << s1 << endl;

            }
            s = s.substr(s.find_first_of(" ") + 1);
            if (s.find_first_of(" ") == string::npos && s.size() >= 2)
            {
                if (s[s.size() - 1] == '-')
                {
                    s = s.substr(0, s.size() - 1);
                    s_tmp = s;
                }
            }
        }       
    }
}

bool checkingFileName(string name_file) {
    if (name_file.size() < 4) {
        cout << "Имя файла короткое." << endl;
        return false;
    }
    name_file = name_file.substr(name_file.find_last_of(".") + 1);
    if (name_file == "txt" || name_file == "doc")
        return true;
    else
    {
        cout << "Файл должен иметь формат .txt или .doc" << endl;;
        return false;
    }
}