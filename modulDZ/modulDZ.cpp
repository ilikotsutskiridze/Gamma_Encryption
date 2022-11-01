/*
вар 22

4 байта
сдвиг на 7
*/


#include <iostream>
#include <clocale> //для setlocal>
#include <string>
#include <vector>










void shifr1(int kluch, int sdiv, std::string text)
{
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(kluch);

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


    std::vector<int> vmass0(dlin, unsigned char("="));//создаем буфферный массив
    std::vector<int> vmass1(dlin, unsigned char("="));

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
        vmass0[i] = shifr1;
        vmass0[i + 1] = shifr2;
        vmass0[i + 2] = shifr3;
        vmass0[i + 3] = shifr4;


    }

    for (int i = 0; i < dlin; ++i) //сдвиг вправо на 7
        vmass1[(i + sdiv) % dlin] = vmass0[i];

    // Если последний символ равен значению заглушки, удаляем его
    while (vmass0[dlin - 1] == int("="))
    {
        vmass0.erase(vmass0.begin() + dlin - 1);
        dlin--;
    }



    // Выводим в виде текста и в виде кода

    std::cout << "\n\nЗашифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin; i++)
        std::cout << unsigned char(vmass1[i]);

    std::cout << "\n\nЗашифрованный текст в виде десятичного кода:\n";

    for (int i = 0; i < dlin; i++)
        std::cout << vmass1[i] << " ";

    std::cout << "\n\n" << "Зашифровал;)\n";
    std::cout << "Отлично, что будет дальше?\n\n";
}


void shifr2(int kluch, int sdiv, std::string text)
{
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(kluch);

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


    std::vector<int> vmass0(dlin, unsigned char("="));//создаем буфферный массив
    std::vector<int> vmass1(dlin, unsigned char("="));

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
        vmass0[i] = shifr1;
        vmass0[i + 1] = shifr2;
        vmass0[i + 2] = shifr3;
        vmass0[i + 3] = shifr4;


    }

    for (int i = 0; i < dlin; ++i)
        vmass1[(dlin + i - sdiv) % dlin] = vmass0[i];

    // Если последний символ равен значению заглушки, удаляем его
    while (vmass0[dlin - 1] == int("="))
    {
        vmass0.erase(vmass0.begin() + dlin - 1);
        dlin--;
    }



    // Выводим в виде текста и в виде кода

    std::cout << "\n\nЗашифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin; i++)
        std::cout << unsigned char(vmass1[i]);


    std::cout << "\n";

    std::cout << "Зашифрованный текст в виде десятичного кода:\n";

    for (int i = 0; i < dlin; i++)
        std::cout << vmass1[i] << " ";

    std::cout << "\n\n" << "Зашифровал;)\n\n\n";
}




void rasshifr1(int kluch, int sdiv, std::string cod)
{
    ///

    cod = cod + " ";
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(kluch);
    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int rshifr1, rshifr2, rshifr3, rshifr4;//зашифрованные 4 символа
    int dlin, dlin1; // Длина текста
    
    

    int a = 0;//создадим буферную переменную a
    dlin = cod.length();//узнаем строки

    std::vector<int> vmass0;//создаем буфферный массив

    //687 467 23 23
    for (int i = 0; i < dlin; i++) //пока не закончится строка
    {
        if (cod[i] == ' ') //если нашли пробел...
        {
            vmass0.push_back(a);//то запишем число а в вектор
            a = 0;
        }
        else 
        {
            a = a * 10 + (unsigned char(cod[i]) - 48);
        }
    }


    dlin1 = vmass0.size();

    std::vector<int> vmass1(dlin1, 0);

    //сдвигаем влево
    for (int i = 0; i < dlin1; ++i)
    {
        if(dlin1>sdiv)
            vmass1[((dlin1 + i - sdiv) % dlin1)] = vmass0[i];
        if (dlin1 < sdiv)
            vmass1[(dlin1 + i - (sdiv - dlin+1)) % dlin1] = vmass0[i];
    }

    std::vector<int> vmass3(dlin1, 0);

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
        rshifr1 = unsigned char(sim1 ^ (vmass1[i]));
        rshifr2 = unsigned char(sim2 ^ (vmass1[i + 1]));
        rshifr3 = unsigned char(sim3 ^ (vmass1[i + 2]));
        rshifr4 = unsigned char(sim4 ^ (vmass1[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        vmass3[i] = rshifr1;
        vmass3[i + 1] = rshifr2;
        vmass3[i + 2] = rshifr3;
        vmass3[i + 3] = rshifr4;


    }

    // Если последний символ равен значению заглушки, удаляем его
    while (vmass3[dlin1 - 1] == 61)
    {
        vmass3.erase(vmass3.begin() + dlin1 - 1);
        dlin1--;
    }



    std::cout << "\n\nРасшифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin1; i++)
        std::cout << unsigned char(vmass3[i]);

    ///

    std::cout << "\n\nРасшифровал;)\n";
    std::cout << "Отлично, что будет дальше?\n\n";
}

void rasshifr2(int kluch, int sdiv, std::string cod)
{
    ///

    cod = cod + " ";
    // Устанавливаем начальное значение генератора псевдослучайных чисел, равное ключу
    srand(kluch);
    int gam; // Функция гамма для каждого блока
    int sim1, sim2, sim3, sim4; //первые четыре символа
    int rshifr1, rshifr2, rshifr3, rshifr4;//зашифрованные 4 символа
    int dlin, dlin1; // Длина текста



    int a = 0;//создадим буферную переменную a
    dlin = cod.length();//узнаем строки

    std::vector<int> vmass0;//создаем буфферный массив

    //654 657 89 98

    for (int i = 0; i < dlin; i++) //пока не закончится строка
    {
        if (cod[i] == ' ') //если нашли пробел...
        {
            vmass0.push_back(a);//то запишем число а в вектор
            a = 0;
        }
        else
        {
            a = a * 10 + (unsigned char(cod[i]) - 48);
        }
    }


    dlin1 = vmass0.size();

    std::vector<int> vmass1(dlin1, 0);

    //сдвигаем влево
    for (int i = 0; i < dlin1; ++i) 
        vmass1[(i + sdiv) % dlin1] = vmass0[i];


    std::vector<int> vmass3(dlin1, 0);

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
        rshifr1 = unsigned char(sim1 ^ (vmass1[i]));
        rshifr2 = unsigned char(sim2 ^ (vmass1[i + 1]));
        rshifr3 = unsigned char(sim3 ^ (vmass1[i + 2]));
        rshifr4 = unsigned char(sim4 ^ (vmass1[i + 3]));
        //запишем зашифрованные элементы в буферный массив
        vmass3[i] = rshifr1;
        vmass3[i + 1] = rshifr2;
        vmass3[i + 2] = rshifr3;
        vmass3[i + 3] = rshifr4;


    }

    // Если последний символ равен значению заглушки, удаляем его
    while (vmass3[dlin1 - 1] == 61)
    {
        vmass3.erase(vmass3.begin() + dlin1 - 1);
        dlin1--;
    }



    std::cout << "\n\nРасшифрованный текст в символьном виде:\n";

    for (int i = 0; i < dlin1; i++)
        std::cout << unsigned char(vmass3[i]);

    ///

    std::cout << "\n\nРасшифровал;)\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");


    int a;
    bool exit;
    exit = true;


    while (exit)
    {

        std::cout << "Выберете режим работы:\n";
        std::cout << "Ведите 0, если хотите, чтобы программа работала в режиме шифровки\n";
        std::cout << "Введите 1, если хотите, чтобы программа работала в режиме расшифровки\n";
        std::cout << "Если хотите, чтобы программа завершила свою работу введите 2\n";


        std::cin >> a;

        if (a == 0)
        {
           std::cout << "\nВведите направление сдвига: vlevo или vpravo\n";
            int kluch, prover;
            std::string text, a;
            std::cin >> a;
            a = "vpravo";
             std::cout << "\nВведите ключ для шифровки:\n";
            std::cin >> kluch;
            std::cout << "\nВведите текст, который нужно зашифровать:\n";

            std::cin.ignore();
            std::getline(std::cin, text);

            if (a == "vpravo")
                shifr1(kluch, 7, text);
            if (a == "vlevo")
                shifr2(kluch, 7, text);

        }

        if (a == 1)
        {
            int kluch1, prover1;
            std::string a1;


           std::cout << "\nВведите направление сдвига, который вы ввели во время шифровки: vlevo или vpravo\n";
           std::cin >> a1;
            a1 = "vpravo";
            std::cout << "Введите ключ для расшифровки:(он должен равняться ключу, использованному для зашифровки этой сторки)\n";
            std::cin >> kluch1;

            std::cin.ignore();
            std::cout << "Введите код:\n";
            std::string cod;
            std::getline(std::cin, cod);

            if (a1 == "vpravo")
                rasshifr1(kluch1, 7, cod);
            if (a1 == "vlevo")
                rasshifr2(kluch1, 7, cod);

        }
        if (a == 2)
        {
            std::cout << "Работа программы завершена\n";
            exit = false;
        }

        if ((a != 1) && (a != 0) && (a != 2))
            std::cout << "Команда не распознана. Следуйте указаниям по выбору режима работы:\n";

    }
}


