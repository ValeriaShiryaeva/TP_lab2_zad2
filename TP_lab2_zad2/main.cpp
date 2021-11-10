#include <iostream>
#include <string>
#include<fstream>
#include <vector>
using namespace std;

bool checkingFileName(string name_file);
void reading_words_starting_with_vowels(ifstream&);
void changing_text(string);
void print_menu_changing_text();
int input_number();
void menu();
void print_menu();
void input_from_file();
void output_to_file();

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-'";
string vowels = "AEIOUYaeiouy";

vector <string> text;

int main()
{
    setlocale(LC_ALL, "rus");
    menu();
}

void menu() {
    while (1) {
        print_menu();
        int punkt_menu = input_number();
        if (punkt_menu <= 9 && punkt_menu >= 0) {
            switch (punkt_menu)
            {
            case 1:
                input_from_file();
                break;
            case 2:
                output_to_file();
                break;
            case 3:
                exit(0);
            }
        }
        else
            cout << "������ �� ������ ����� ����. " << endl;
    }
}

void print_menu() {
    cout << "�������� ��������" << endl;
    cout << "1. ������� ����� �� ����� � ������� �����, ������������ � �������" << endl;
    cout << "2. ������� ��������� (����������) ����� � ����" << endl;
    cout << "3. ����� �� ���������" << endl;
}

void input_from_file()
{
    string name_file;
    cout << "������� �������� �����: ";
    getline(cin, name_file);
    getline(cin, name_file);
    if (checkingFileName(name_file) == true) {
        ifstream fin;
        fin.open(name_file);
        if (!fin)
            cout << "���� " << name_file << " �� ������" << endl;
        else
        {
            cout << "���� " << name_file << " ������" << endl << endl;
            reading_words_starting_with_vowels(fin);
        }
        fin.close();
    }
    else
        cout << "�� ������ ��� ����� ��� ����������." << endl;

}

void reading_words_starting_with_vowels(ifstream& fin) {
    string s, s1, s_tmp;
    text.clear();
    while (getline(fin, s))
    {
        if (s == "") 
            text.push_back("\n");
        while (s != "" && s.find(" ") != string::npos)
        {
            if (s_tmp != "")
            {
                s1 = s_tmp;
                text.pop_back();
                text.push_back(s1 += s.substr(0, s.find_first_of(" ") + 1));
                s1 = s_tmp;
                s1 += s.substr(0, s.find_first_of(" "));
                s_tmp = "";
            }
            else
            {
                s1 = s.substr(0, s.find_first_of(" "));
                text.push_back(s.substr(0, s.find_first_of(" ") + 1));
            }            
            bool flag = 0;
            if (s1.find_first_of(vowels) == 0)
            {
                if (s1.find_first_not_of(alphabet) != string::npos)
                {
                    int tmp = s1.find_first_not_of(alphabet) + 1;
                    for (int i = 0; i < alphabet.size(); i++)
                    {
                        if (s1[tmp] == alphabet[i])
                        {
                            cout << "�� ������ ������: " << s1 << endl;
                            changing_text(s1);
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
            if (s.find_first_of(" ") == string::npos)
                text.push_back(s);
        }       
    }
    cout << endl;
}

void output_to_file() {
    string name_file;
    cout << "������� �������� �����: ";
    getline(cin, name_file);
    getline(cin, name_file);
    if (checkingFileName(name_file) == true) {
        ofstream fout;
        fout.open(name_file);
        if (!fout)
            cout << "���� " << name_file << " �� ������" << endl;
        else
        {
            int size_str = 0;
            for (int i = 0; i < text.size(); i++)
            {
                if (size_str + text[i].size() > 95 || text[i] == "\n")
                {
                    fout << endl;
                    size_str = 0;
                }
                fout << text[i];
                size_str += text[i].size();
            }
            fout << endl;
            cout << "������ �������� � ����" << endl;
        }
        fout.close();
    }
    else
        cout << "�� ������ ��� ����� ��� ����������." << endl;
}

bool checkingFileName(string name_file) {
    if (name_file.size() < 4) {
        cout << "��� ����� ��������." << endl;
        return false;
    }
    name_file = name_file.substr(name_file.find_last_of(".") + 1);
    if (name_file == "txt" || name_file == "doc" || name_file == "dat")
        return true;
    else
    {
        cout << "���� ������ ����� ������ .txt ��� .doc" << endl;;
        return false;
    }
}

void changing_text(string s1) {
    while (1) {
        print_menu_changing_text();
        int punkt_menu = input_number();
        if (punkt_menu == 1 || punkt_menu == 2)
        {
            if (punkt_menu == 1) {
                string s;
                cout << "������ �����: " << s1 << endl;
                cout << "������� ���������� �����: ";
                getline(cin, s);
                getline(cin, s);
                s += " ";
                text.pop_back();
                text.push_back(s);
                break;
            }
            if (punkt_menu == 2)
                break;
        }
        else
            cout << "�� ����� ������ �����. ";
    }
}

void print_menu_changing_text() {
    cout << "������ �������� �� ����� ���������� �����" << endl;
    cout << "1. ��������" << endl;
    cout << "2. �������� �������" << endl;
}

int input_number() {
    string number_s;
    while (1)
    {
        cout << "�������: " << endl;
        cin >> number_s;
        if (number_s.find_first_not_of("0123456789", 0) == string::npos)
        {
            int number = stoi(number_s);
            return number;
        }
        else
            cout << "������� �� ������ ��������. ��������� ����." << endl;
    }
}