//#include <iostream>
//#include <fstream>
//#include <string>
//#include<conio.h>
//using namespace std;
//
//long long sizef(const string& filename) {
//    std::ifstream file(filename, std::ios::binary | std::ios::ate);
//
//    if (!file.is_open()) {
//        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
//        return -1; // Или другое значение, указывающее на ошибку
//    }
//
//    std::streamsize size = file.tellg();
//    file.close();
//
//    if (size == std::streamsize(-1)) { // Проверка на ошибку
//        std::cerr << "Ошибка при получении размера файла (ifstream)" << std::endl;
//        return -1;
//    }
//
//    return size;
//}
//
//int main()
//{
//    ifstream in;
//    
//    while (true)
//    {
//        in.open("../../comp_webs/x64/Debug/file.bin");
//        long s1 = sizef("../../comp_webs/x64/Debug/file.txt");
//        long s2 = s1;
//        int fl = 0;
//        
//        if (!in.is_open()) {
//            cerr << "Error: Could not open file " << endl;
//            break; // Выходим, если не удалось открыть файл
//        }
//        while (s2 == s1)
//        {
//            s2 = s1;
//            s1 = sizef("../../comp_webs/x64/Debug/file.txt");
//        }
//        string s = "";
//        string id;
//        string res = "";
//        
//        while (!in.eof() && getline(in, s))
//        {
//            id = s.substr(0, 4);
//            res = id + " 3126.82";
//            for (int i = 5; i < s.size(); i++)
//            {
//                if (s.at(i) == '3')
//                {
//                    res = id + " 0";
//                    break;
//                }
//                if (s.at(i) == '4')
//                {
//                    res = id + " 2046.32";
//                }
//            }
//        }
//        ofstream out("files.txt", ios::app);
//        out << res << endl;
//        cout << "Success" << endl;
//        out.close();
//        in.close();
//    }
//}

#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
using namespace std;

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

int main()
{
    ifstream in;

    while (true)
    {
        in.open("../../comp_webs/x64/Debug/file.bin", ios::binary);
        long s1 = sizef("../../comp_webs/x64/Debug/file.bin");
        long s2 = s1;
        int fl = 0;

        if (!in.is_open()) {
            cerr << "Error: Could not open file " << endl;
            break; // Выходим, если не удалось открыть файл
        }
        while (s2 == s1)
        {
            s2 = s1;
            s1 = sizef("../../comp_webs/x64/Debug/file.bin");
        }
        string s = "";
        string id;
        string res = "";
        char buffer[9] = { '0','0','0','0','0','0','0','0','0' };
        in.read(buffer, sizeof(buffer));
        char rez[13]= { '0','0','0','0','0','0','0','0','0', '0', '0', '0', '0'};;
        for (int i = 0; i < 5; i++)
            id+= buffer[i];
        res = id + " 3126.82";
        for (int i = 5; i < sizeof(buffer); i++)
        {
            if ((buffer[i]) == '3')
            {
                res = id + " 0";
                break;
            }
            if (buffer[i] == '4')
            {
                res = id + " 2046.32";
            }
        }
        for (int i = 0; i < res.size(); i++)
        {
            rez[i] = res.at(i);
        }
        ofstream out("files.bin", ios::binary);
        out.write(rez, sizeof(rez));
        cout << "Success" << endl;
        out.close();
        in.close();
        std::ofstream ofs;
        ofs.open("../../comp_webs/x64/Debug/file.bin", std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
}

