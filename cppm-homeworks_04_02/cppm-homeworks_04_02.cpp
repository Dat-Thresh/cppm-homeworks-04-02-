// cppm-homeworks_04_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Adress {
private:
    std::string city;
    std::string street;
    int homeNumb;
    int apartment;

public:
    
    //cеттеры для считывания из файла
    void set_city(std::ifstream& reader) {
        reader >> city;
    }
    void set_street(std::ifstream& reader) {
        reader >> street;
    }
    void set_homeNumb(std::ifstream& reader) {
        reader >> homeNumb;
    }
    void set_apartment(std::ifstream& reader) {
        reader >> apartment;
    }
    //геттеры
    std::string get_city() { return city; }
    std::string get_street() { return street; }
    int get_homeNumb() { return homeNumb; }
    int get_apartment() { return apartment; }

    std::string back_whole_adress() {
        std::string buff;
        buff = city + ", " + street + ", " + std::to_string(homeNumb) + ", " + std::to_string(apartment) + "\n";
        return buff;
    }

};

void sort_adress_by_first_letter_of_city(Adress* arrayAd, int N); //сортирует массив адресов по первой букве города

int main()
{
    std::setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::ifstream reader("in.txt");
    if (!reader.is_open()) {
        std::cout << "Unable to open input file!\n";
        return 1;
    }
    int N; // для записи кол-ва адресов
    reader >> N;

    Adress* arrayAd = new(std::nothrow) Adress[N];
    if (arrayAd == NULL) {
        std::cout << "Not enough memory!\n";
        return 2;
    }
    for (int i = 0; i < N; i++) {
        arrayAd[i].set_city(reader);
        arrayAd[i].set_street(reader);
        arrayAd[i].set_homeNumb(reader);
        arrayAd[i].set_apartment(reader);
    }
    reader.close();
    
    sort_adress_by_first_letter_of_city(arrayAd, N);

    std::ofstream writer("out.txt");
    if (!writer.is_open()) {
        std::cout << "Unable to open output file!\n";
        return 3;
    }
    //в аут.тхт сначала записываем количество адресов, далее все отсортированные адреса
    writer << N << std::endl;
    for (int i = 0; i < N; i++) {
        writer << arrayAd[i].back_whole_adress();
    }
    writer.close();
    delete[] arrayAd;
}

void sort_adress_by_first_letter_of_city(Adress* arrayAd, int N) {
    
    std::string buffer_i,buffer_j; 
    //идем по массиву адресов, сравнивая города элементов по первым буквам
    for (int i = 0; i < N; i++) {

        //запоминаем позицию элемента 
        int min = i; 
        
        for (int j = i; j < N; j++) {
            //сравниваем названия городов лексикографически
            if (arrayAd[i].get_city() > arrayAd[j].get_city()) {
                min = j;
            }
            
        }
        //если было изменение min, меняем элемнты местами
        if (min != i) {
            Adress buffer = arrayAd[i];
            arrayAd[i] = arrayAd[min];
            arrayAd[min] = buffer;
        }
    }
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
