//#include <iostream>
//#include <fstream>
//#include <string>
//#include<conio.h>
//#include<vector>
//using namespace std;
//
//long sizef(string filename)
//{
//    ifstream in;
//    in.open(filename, ios::ate);
//    if (!in)
//        return -1000;
//    else return in.tellg();
//}
//int main()
//{
//    while (true)
//    {   
//        ifstream in("file.txt", ios::ate );
//        long s1 = sizef();
//        long s2 = s1;
//        int fl = 0;
//        if (!in.is_open()) {
//              cerr << "Error: Could not open file " << endl;
//              break; // Выходим, если не удалось открыть файл
//        }
//
        //while (s2 == s1)
        //{
        //    
        //    s2 = s1;
        //    s1 = sizef();
        //    if (_kbhit()) { // Проверяем, была ли нажата клавиша
        //        if (_getch() == 27) { // 27 - ASCII код клавиши ESC
        //            std::cout << std::endl << "Exiting..." << std::endl;
        //            fl = 1;
        //            break; // Выход из цикла
        //        }
        //    }
        //}
//        if (fl)
//            break;
//        /*string s="";*/
//        for (; !in.eof(); ) {
//            string s = "";
//            getline(in, s);
//            cout << s << endl;
//            if (in.eof())
//                break;
//        }
//        /*getline(in, s); //если работать только с одной введенной строкой
//        if (s == "")
//        {
//            getline(in, s);
//        }
//        cout << s<<endl;
//        cout << s<<endl;*/
//        if (_kbhit()) { // Проверяем, была ли нажата клавиша
//            if (_getch() == 27) { // 27 - ASCII код клавиши ESC
//                std::cout << std::endl << "Exiting..." << std::endl;
//                break; // Выход из цикла
//            }
//        }
//        in.close();
//    }
//}

//БИНАРНИК
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <conio.h>
//#include <vector>
//
//using namespace std;
//
//long sizef(const string& filename) {
//    ifstream in(filename, ios::ate | ios::binary); // Открываем в бинарном режиме
//    if (!in.is_open())
//        return -1000;
//    else
//        return in.tellg();
//}
//
//int main() {
//    const string filename = "file.bin"; // Изменили расширение, чтобы было понятно, что это бинарный файл
//    const int bufferSize = 1024; // Размер буфера для чтения данных
//
//    while (true) {
//        ifstream in(filename, ios::binary); // Открываем в бинарном режиме
//        long s1 = sizef(filename);
//        long s2 = s1;
//        int fl = 0;
//
//        if (!in.is_open()) {
//            cerr << "Error: Could not open file " << filename << endl;
//            break; // Выходим, если не удалось открыть файл
//        }
//
//        while (s2 == s1) {
//            s2 = s1;
//            s1 = sizef(filename);
//            if (_kbhit()) {
//                if (_getch() == 27) {
//                    cout << endl << "Exiting..." << endl;
//                    fl = 1;
//                    break;
//                }
//            }
//        }
//        if (fl)
//            break;
//
//        char buffer[bufferSize];
//        while (in.read(buffer, bufferSize) || in.gcount() > 0) {
//            streamsize bytesRead = in.gcount(); // Получаем количество фактически прочитанных байт
//            // Теперь обрабатываем данные в буфере (buffer).
//            // Например, выводим их в шестнадцатеричном формате:
//            for (int i = 0; i < bytesRead; ++i) {
//                cout << /*hex<< (int)(unsigned char)*/buffer[i] << " ";
//            }
//            cout << endl;
//            if (_kbhit()) {
//                if (_getch() == 27) {
//                    cout << endl << "Exiting..." << endl;
//                    fl = 1;
//                    break;
//                }
//            }
//        }
//        if (fl)
//            break;
//
//        in.close();
//        cout << "File read complete (or interrupted)." << endl;
//    }
//
//    return 0;
//}


#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
#include <string>
#include <random>
#include <algorithm>

long long sizef(const string& filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::ate);

	if (!file.is_open()) {
		std::cerr << "Не удалось открыть файл: " << filename << std::endl;
		return -1; // Или другое значение, указывающее на ошибку
	}

	std::streamsize size = file.tellg();
	file.close();

	if (size == std::streamsize(-1)) { // Проверка на ошибку
		std::cerr << "Ошибка при получении размера файла (ifstream)" << std::endl;
		return -1;
	}

	return size;
}

string generateRandomId(int length) {
	const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, characters.size() - 1);

	string random_id;
	for (int i = 0; i < length; ++i) {
		random_id += characters[distribution(generator)];
	}
	return random_id;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream in;
	ifstream out;
	string id = generateRandomId(4);
	id += " ";
	do {
		//cout << "Введите кол-во оценок, которое хотите ввести:" << endl;
		in.open("file.bin", ios::binary);
		char mark;
		int n=4;
		/*string s = id;*/
		//cin >> n;
		int k = 0;
		cout << "Введите оценки(4 штуки)" << endl;
		char buff[4+5];
		for (int i = 0; i < 5; i++)
		{
			buff[i] = id.at(i);
		}
		int p = 5;
		while (k < n)
		{
			cin >> mark;
			buff[p] = mark;//чтобы программы не мешали друг другу
			k++;
			p++;
		}
		in.write(buff, sizeof(buff));
		in.close();
		
		long s1 = sizef("../../../comp_webs_serv/comp_webs_serv/files.bin");
        long s2 = s1;
		while (s2 == s1)
		{
			s2 = s1;
			s1 = sizef("../../../comp_webs_serv/comp_webs_serv/files.bin");
		}
		out.open("../../../comp_webs_serv/comp_webs_serv/files.bin", ios::binary);
		//out.seekg(-(12), ios::end);
		char buffer[13];
		out.read(buffer, sizeof(buffer));
		string res="";
		for (int i = 0; i < sizeof(buffer); i++)
		{
			res += buffer[i];
		}
		out.close();
		std::ofstream ofs;
		ofs.open("../../../comp_webs_serv/comp_webs_serv/files.bin", std::ofstream::out | std::ofstream::trunc);
		ofs.close();
		if (res.find("0000000")!= string::npos)
		{
			cout << "Стипендия равна:" << 0 << endl;
		}
		else cout <<"Стипендия равна:"<< res.substr(5) << endl;
		cout << "Для ввода оценок нажмите на любую клавишу, для выхода из программы нажмите esc" << endl;
	} while (_kbhit() || _getch() != 27);
	cout << "Exiting...";
	
}

