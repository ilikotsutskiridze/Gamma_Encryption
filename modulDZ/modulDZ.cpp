// iliko tsutskiridze [Option 22 (4 byte ___ Shift by 7)]

#include <iostream>
#include <clocale> //для setlocal>
#include <string>
#include <vector>
#include <ctime>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using std::endl;

//возвращает true если в строке знаковое целое
bool isNum(string& s)
{
    if ((s[0] == '-') || (isdigit(s[0])))
    {
        for (size_t i = 1; i < size(s); ++i)
            if (not(isdigit(s[0])))
                return 0;
    }
    else
        return 0;
}

void GenNewKey(string& key)
{
    cout << "Неверно введен ключ! Программа присвоит ключ автоматически!\n";
    srand(time(0));
    int newkey = rand();
    cout << "Ваш новый ключ: " << newkey << std::endl;
    key = std::to_string(newkey);
}


void EncryptHelper()
{

}


void Encryption(int key, int sdiv, string text, string route)
{
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(key);

    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int enc1, enc2, enc3, enc4;//зашифрованные 4 символа
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
        enc1 = unsigned char(sim1 ^ (text[i]));
        enc2 = unsigned char(sim2 ^ (text[i + 1]));
        enc3 = unsigned char(sim3 ^ (text[i + 2]));
        enc4 = unsigned char(sim4 ^ (text[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        inmass0[i] = enc1;
        inmass0[i + 1] = enc2;
        inmass0[i + 2] = enc3;
        inmass0[i + 3] = enc4;
    }

    if (route == "right")
        for (int i = 0; i < len; ++i) //сдвиг вправо на 7
            inmass1[(i + sdiv) % len] = inmass0[i];
    else if (route == "left")
        for (int i = 0; i < len; ++i) //сдвиг влево на 7
            inmass1[(len + i - sdiv) % len] = inmass0[i];


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

    cout << "\n\n" << "Зашифровал!\nОтлично, что будет дальше?\n\n";
}

void Decryption(int key, int sdiv, string cod, string route)
{
    cod = cod + " ";
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(key);
    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int dec1, dec2, dec3, dec4;//зашифрованные 4 символа
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

    if (route == "right")
        for (int i = 0; i < dlin1; ++i)
        {
            if(dlin1 > sdiv)
                inmass1[((dlin1 + i - sdiv) % dlin1)] = inmass0[i];
            if (dlin1 < sdiv)
                inmass1[(dlin1 + i - (sdiv - dlin+1)) % dlin1] = inmass0[i];
        }
    else if (route == "left")
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
        dec1 = unsigned char(sim1 ^ (inmass1[i]));
        dec2 = unsigned char(sim2 ^ (inmass1[i + 1]));
        dec3 = unsigned char(sim3 ^ (inmass1[i + 2]));
        dec4 = unsigned char(sim4 ^ (inmass1[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        inmass3[i] = dec1;
        inmass3[i + 1] = dec2;
        inmass3[i + 2] = dec3;
        inmass3[i + 3] = dec4;
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

    cout << "\n\nРасшифровал!\nОтлично, что будет дальше?\n\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int mode;
    bool exit;
    exit = true;

    while (exit)
    {
        cout << "Выберете режим работы:\n";
        cout << "Ведите 0, если хотите, чтобы программа работала в режиме шифровки\n";
        cout << "Введите 1, если хотите, чтобы программа работала в режиме расшифровки\n";
        cout << "Если хотите, чтобы программа завершила свою работу введите 2\n";

        cin >> mode;

        if (mode == 0)
        {
           cout << "\nВведите направление сдвига: left или right\n";
            string key = "";
            string text, route;
            cin >> route;
            cout << "\nВведите ключ для шифровки:\n";
            cin >> key;

            if (not(isNum(key)))
                GenNewKey(key);

            cout << "\nВведите текст, который нужно зашифровать:\n";
            cin.ignore();
            std::getline(cin, text);

            Encryption(stoi(key), 7, text, route);
        }

        if (mode == 1)
        {
            string key;
            string route;

           cout << "\nВведите направление сдвига, который вы ввели во время шифровки: left или right\n";
           cin >> route;
           cout << "Введите ключ для расшифровки: (он должен равняться ключу, использованному для зашифровки этой сторки)\n";
           cin >> key;

           if (not(isNum(key)))
               GenNewKey(key);

            cin.ignore();
            cout << "Введите код:\n";
            string code;
            std::getline(cin, code);

            Decryption(stoi(key), 7, code, route);
        }
        if (mode == 2)
        {
            cout << "Работа программы завершена\n\n\n";
            exit = false;
        }

        if ((mode != 0) && (mode != 1) && (mode != 2))
            cout << "Команда не распознана. Следуйте указаниям по выбору режима работы!\n\n\n";
    }
}


