// iliko tsutskiridze [Option 22 (4 byte ___ Shift by 7)]

#include <iostream>
#include <clocale> //для setlocal>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;


void shifr1(int key, int sdiv, string text)
{
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(key);

    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int shifr1, shifr2, shifr3, shifr4;//зашифрованные 4 символа
    int len; // Длина текста

    len = text.length();

    // Если текст не делиться нацело на блоки, прибавляем к тексту стоп-символ "="

    while (len % 4 != 0)
    {
        text += '=';
        len++;
    };

    vector<int> inmass0(len, unsigned char("="));//создаем буфферный массив
    vector<int> inmass1(len, unsigned char("="));

    for (int i = 0; i < len; i = i + 4)
    {
        //создадим для первых 4 элементов гаммы
        gam = rand();
        sim1 = gam / 256;
        sim2 = gam % 256;
        gam = rand();
        sim3 = gam / 256;
        sim4 = gam % 256;

        //выполним операцию xor для первых 4 элементов
        shifr1 = unsigned char(sim1 ^ (text[i]));
        shifr2 = unsigned char(sim2 ^ (text[i + 1]));
        shifr3 = unsigned char(sim3 ^ (text[i + 2]));
        shifr4 = unsigned char(sim4 ^ (text[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        inmass0[i] = shifr1;
        inmass0[i + 1] = shifr2;
        inmass0[i + 2] = shifr3;
        inmass0[i + 3] = shifr4;
    }

    for (int i = 0; i < len; ++i) //сдвиг вправо на 7
        inmass1[(i + sdiv) % len] = inmass0[i];

    // Если последний символ равен значению заглушки, удаляем его
    while (inmass0[len - 1] == int("="))
    {
        inmass0.erase(inmass0.begin() + len - 1);
        len--;
    }

    // Выводим в виде текста и в виде кода

    cout << "\n\nЗашифрованный текст в символьном виде:\n";

    for (int i = 0; i < len; i++)
        cout << unsigned char(inmass1[i]);

    cout << "\n\nЗашифрованный текст в виде десятичного кода:\n";

    for (int i = 0; i < len; i++)
        cout << inmass1[i] << " ";

    cout << "\n\n" << "Зашифровал;)\nОтлично, что будет дальше?\n\n";
}

void shifr2(int key, int sdiv, string text)
{
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(key);

    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int shifr1, shifr2, shifr3, shifr4;//зашифрованные 4 символа
    int dlin; // Длина текста

    dlin = text.length();

    // Если текст не делиться нацело на блоки, прибавляем к тексту стоп-символ "="

    while (dlin % 4 != 0)
    {
        text += '=';
        dlin++;
    };

    vector<int> inmass0(dlin, unsigned char("="));//создаем буфферный массив
    vector<int> inmass1(dlin, unsigned char("="));

    for (int i = 0; i < dlin; i = i + 4)
    {
        //создадим для первых 4 элементов гаммы
        gam = rand();
        sim1 = gam / 256;
        sim2 = gam % 256;
        gam = rand();
        sim3 = gam / 256;
        sim4 = gam % 256;

        //выполним операцию xor для первых 4 элементов
        shifr1 = unsigned char(sim1 ^ (text[i]));
        shifr2 = unsigned char(sim2 ^ (text[i + 1]));
        shifr3 = unsigned char(sim3 ^ (text[i + 2]));
        shifr4 = unsigned char(sim4 ^ (text[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        inmass0[i] = shifr1;
        inmass0[i + 1] = shifr2;
        inmass0[i + 2] = shifr3;
        inmass0[i + 3] = shifr4;
    }

    for (int i = 0; i < dlin; ++i)
        inmass1[(dlin + i - sdiv) % dlin] = inmass0[i];

    // Если последний символ равен значению заглушки, удаляем его
    while (inmass0[dlin - 1] == int("="))
    {
        inmass0.erase(inmass0.begin() + dlin - 1);
        dlin--;
    }

    // Выводим в виде текста и в виде кода

    cout << "\n\nЗашифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin; i++)
        cout << unsigned char(inmass1[i]);

    cout << "\nЗашифрованный текст в виде десятичного кода:\n";

    for (int i = 0; i < dlin; i++)
        cout << inmass1[i] << " ";

    cout << "\n\nЗашифровал;)\n\n\n";
}

void rasshifr1(int key, int sdiv, string cod)
{
    cod = cod + " ";
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(key);
    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int rshifr1, rshifr2, rshifr3, rshifr4;//зашифрованные 4 символа
    int dlin, dlin1; // Длина текста
    
    int a = 0;//создадим буферную переменную a
    dlin = cod.length();//узнаем строки

    vector<int> inmass0;//создаем буфферный массив

    for (int i = 0; i < dlin; i++) //пока не закончится строка
    {
        if (cod[i] == ' ') //если нашли пробел...
        {
            inmass0.push_back(a);//то запишем число а в вектор
            a = 0;
        }
        else 
        {
            a = a * 10 + (unsigned char(cod[i]) - 48);
        }
    }

    dlin1 = inmass0.size();

    vector<int> inmass1(dlin1, 0);

    //сдвигаем влево
    for (int i = 0; i < dlin1; ++i)
    {
        if(dlin1>sdiv)
            inmass1[((dlin1 + i - sdiv) % dlin1)] = inmass0[i];
        if (dlin1 < sdiv)
            inmass1[(dlin1 + i - (sdiv - dlin+1)) % dlin1] = inmass0[i];
    }

    vector<int> inmass3(dlin1, 0);

    for (int i = 0; i < dlin1; i = i + 4)
    {
        //создадим для первых 4 элементов гаммы
        gam = rand();
        sim1 = gam / 256;
        sim2 = gam % 256;
        gam = rand();
        sim3 = gam / 256;
        sim4 = gam % 256;

        //выполним операцию xor для первых 4 элементов
        rshifr1 = unsigned char(sim1 ^ (inmass1[i]));
        rshifr2 = unsigned char(sim2 ^ (inmass1[i + 1]));
        rshifr3 = unsigned char(sim3 ^ (inmass1[i + 2]));
        rshifr4 = unsigned char(sim4 ^ (inmass1[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        inmass3[i] = rshifr1;
        inmass3[i + 1] = rshifr2;
        inmass3[i + 2] = rshifr3;
        inmass3[i + 3] = rshifr4;
    }

    // Если последний символ равен значению заглушки, удаляем его
    while (inmass3[dlin1 - 1] == 61)
    {
        inmass3.erase(inmass3.begin() + dlin1 - 1);
        dlin1--;
    }

    cout << "\n\nРасшифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin1; i++)
        cout << unsigned char(inmass3[i]);

    cout << "\n\nРасшифровал;)\nОтлично, что будет дальше?\n\n";
}

void rasshifr2(int key, int sdiv, string cod)
{
    cod = cod + " ";
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(key);
    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int rshifr1, rshifr2, rshifr3, rshifr4;//зашифрованные 4 символа
    int dlin, dlin1; // Длина текста

    int a = 0;//создадим буферную переменную a
    dlin = cod.length();//узнаем строки

    vector<int> inmass0;//создаем буфферный массив

    for (int i = 0; i < dlin; i++) //пока не закончится строка
    {
        if (cod[i] == ' ') //если нашли пробел...
        {
            inmass0.push_back(a);//то запишем число а в вектор
            a = 0;
        }
        else
        {
            a = a * 10 + (unsigned char(cod[i]) - 48);
        }
    }

    dlin1 = inmass0.size();

    vector<int> inmass1(dlin1, 0);

    //сдвигаем влево
    for (int i = 0; i < dlin1; ++i) 
        inmass1[(i + sdiv) % dlin1] = inmass0[i];

    vector<int> inmass3(dlin1, 0);

    for (int i = 0; i < dlin1; i = i + 4)
    {
        //создадим для первых 4 элементов гаммы
        gam = rand();
        sim1 = gam / 256;
        sim2 = gam % 256;
        gam = rand();
        sim3 = gam / 256;
        sim4 = gam % 256;

        //выполним операцию xor для первых 4 элементов
        rshifr1 = unsigned char(sim1 ^ (inmass1[i]));
        rshifr2 = unsigned char(sim2 ^ (inmass1[i + 1]));
        rshifr3 = unsigned char(sim3 ^ (inmass1[i + 2]));
        rshifr4 = unsigned char(sim4 ^ (inmass1[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        inmass3[i] = rshifr1;
        inmass3[i + 1] = rshifr2;
        inmass3[i + 2] = rshifr3;
        inmass3[i + 3] = rshifr4;
    }

    // Если последний символ равен значению заглушки, удаляем его
    while (inmass3[dlin1 - 1] == 61)
    {
        inmass3.erase(inmass3.begin() + dlin1 - 1);
        dlin1--;
    }

    cout << "\n\nРасшифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin1; i++)
        cout << unsigned char(inmass3[i]);

    cout << "\n\nРасшифровал;)\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int a;
    bool exit;
    exit = true;

    while (exit)
    {
        cout << "Выберете режим работы:\n";
        cout << "Ведите 0, если хотите, чтобы программа работала в режиме шифровки\n";
        cout << "Введите 1, если хотите, чтобы программа работала в режиме расшифровки\n";
        cout << "Если хотите, чтобы программа завершила свою работу введите 2\n";

        cin >> a;

        if (a == 0)
        {
           cout << "\nВведите направление сдвига: vlevo или vpravo\n";
            int kluch, prover;
            string text, a;
            cin >> a;
            a = "vpravo";
             cout << "\nВведите ключ для шифровки:\n";
            cin >> kluch;
            cout << "\nВведите текст, который нужно зашифровать:\n";

            cin.ignore();
            std::getline(cin, text);

            if (a == "vpravo")
                shifr1(kluch, 7, text);
            if (a == "vlevo")
                shifr2(kluch, 7, text);
        }

        if (a == 1)
        {
            int kluch1, prover1;
            string a1;

           cout << "\nВведите направление сдвига, который вы ввели во время шифровки: vlevo или vpravo\n";
           cin >> a1;
            a1 = "vpravo";
            cout << "Введите ключ для расшифровки:(он должен равняться ключу, использованному для зашифровки этой сторки)\n";
            cin >> kluch1;

            cin.ignore();
            cout << "Введите код:\n";
            string cod;
            std::getline(cin, cod);

            if (a1 == "vpravo")
                rasshifr1(kluch1, 7, cod);
            if (a1 == "vlevo")
                rasshifr2(kluch1, 7, cod);
        }
        if (a == 2)
        {
            cout << "Работа программы завершена\n";
            exit = false;
        }

        if ((a != 1) && (a != 0) && (a != 2))
            cout << "Команда не распознана. Следуйте указаниям по выбору режима работы:\n";
    }
}


