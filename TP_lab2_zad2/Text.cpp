#include "Text.h"

string& Text::operator[](int index) {
    if (index >= 0 && index < size)
        return text[index];
}

void Text::push_back(string s) {
    string* tmp = text;
    size++;
    text = new string[size];
    for (int i = 0; i < size - 1; i++)
        text[i] = tmp[i];
    text[size - 1] = s;
}

void Text::pop_back() {
    string* tmp = new string[size - 1];
    for (int i = 0; i < size-1; i++)
        tmp[i] = text[i];
    size--;
    text = tmp;
}

void Text::clear() {
    delete[] text;
    text = nullptr;
    size = 0;
}
