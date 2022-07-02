#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

class Library {//класс библиотека со структурой автора,название,шифра,года и позиции
    char author[50];
    char title[100];
    char shifr[10];
    int year;
    int position;
public:
    Library(const char* a, const char* b, const char* c, int i, int n) {//конструктор 
        strcpy_s(author, a);//функция переписывает из переменного а в author
        strcpy_s(title, b);
        strcpy_s(shifr, c);
        year = i;
        position = n;
    }
    char* get_aut() {//функция записывает автора
        return author;
    }
    char* get_tit()
    {
        return title;
    }
    char* get_pub() {
        return shifr;
    }
    int get_year() {
        return year;
    }
    int get_pos() {
        return position;
    }
};

void SeePublish(const char* str,const char* ptr, Library* Lib) {//процедура поиска местоположения книги оп автору и названию
    cout << " Автор: " << str<<"; Название: "<<ptr << ": ";
    for (int i = 0; i < 3; i++) {//цикл вывода

        if ((strcmp((Lib[i].get_aut()), str) == 0) && (strcmp((Lib[i].get_tit()), ptr) == 0)) {//когда у нас одинаковые данные выводит позицию в библиотеке
            cout<<Lib[i].get_pos() <<endl;
        }
    }
}

void SeeAutor(const char* str, Library* Lib) {//процедура книг одного автора
    cout << "Список книг автора" << str << ": ";
    for (int i = 0; i < 3; i++) {
        if (strcmp((Lib[i].get_aut()), str) == 0) {
            cout << Lib[i].get_tit() << endl;
        }
    }
}

void SeeYear(int h, Library* Lib) {//процедура нахождения кол-ва книг 
    cout << "Список книг указанного года издания: " << h << ": ";
    int k = 0;
    for (int i = 0; i < 3; i++) {

        if (Lib[i].get_year() == h)
            k++;
    }
    cout << "Найдено книг " << h << " года издания: " << k << endl;
}


int main()
{
    setlocale(LC_ALL, "");
    Library Lib[] = { {"AlexandrPushkin", "Ruslan_and_Ludmila", "N3380", 1820, 1}, {"AlexandrPushkin", "Dubrovsky", "N1376", 1833, 2}, {"IsaacAzimov", "Foundation", "Z1708", 1951, 3} };//не смог сделать бинарный файл вывода
    char choice, str[40],ptr[40];
    int h;
            cout << "Выберите пункт меню:" << endl << " 1. Список книг по автору" << endl << " 2. местоположение книги" << endl << " 3. Список книг указанного года издания" << endl;
            cin >> choice;//выбор в switch case
        cout << endl;
        switch (choice) {//вывод через switch case
        case '1':
            cout << "Введите имя автора: ";
            cin >> str;
            SeeAutor(str, Lib);//процедура вывода
            break;
         case '2':
                 cout << "Автор: ";
                 cin >> str;
                 cout << "Название: ";
                 cin >> ptr;
                 SeePublish(str,ptr, Lib);//процедура вывода
                 break;
        case '3':
            cout << "Введите указанный год: ";
            cin >> h;
            SeeYear(h, Lib);//процедура вывода
            break;
    }
}
