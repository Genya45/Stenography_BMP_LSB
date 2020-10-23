
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int endHeader = 53;

//Функція отримання бітового рядку
void getBit(char ch, int(&bits)[8]) {
	for (int i = 7; i >= 0; i--) {
		if (ch & (1 << i))bits[7-i] = 1;
		else bits[7-i] = 0;
		//cout << bits[7-i] << ' ';
	}
	//cout << endl;
}

string readFileBMP() {
	//Зчитування файлу
	string line;
	string filename;
	cout << "\nInput file name for write date - ";
	cin >> filename;
	cout << endl;
	ifstream in(filename);
	if (in.is_open())
	{
		while (!in.eof())
		{
			char a;
			in >> a;
			line += a;
			cout << a << ' ' << (int)a << endl;
		}
	}
	else {

		cout << "\nFile not found\n";
		system("pause");
		return "";
	}
	in.close();
	return line;

}

int main()
{

	string codeText = "Trots";
	string encodeText = ".....";
	string line;

	string filename;
	int bits[8];

	char mode;
	cout << "choose mode 1 - encrypt, 0 - decrypt    ";
	cin >> mode;
	if (mode != '1' && mode != '0') {

		cout << "\nerror\n";
		system("pause");
		return -1;
	}

	if (mode == '1') {


		line = readFileBMP();
		cout << "Input crypto text\nmax = " << (line.size() - endHeader) / 8 << "\n";
		cin >> codeText;
		if (((line.size() - endHeader) / 8) < codeText.size()) {
			cout << "\nInput text > max \n";
			system("pause");
			return -1;
		}
		//Шифрування
		for (int j = 0, bb = 0; j < codeText.size(); j++) {
			getBit(codeText[j], bits);
			for (int i = 0; i < 8; i++, bb++) {
				if (bits[i] == 1) {
					line[bb + 1 + endHeader] |= (1 << 0);
				}
				else line[bb + 1 + endHeader] &= ~(1 << 0);
			}
		}

		//Запис зашифрованого повідомлення
		cout << "\nInput file name for read date - ";
		cin >> filename;
		cout << endl;
		ofstream out;
		out.open(filename);
		out << line;
		out.close();

	}

	else {
		//Зчитування файлу


		line = readFileBMP();


		//Дешифровка

		cout << "Input count text\nmax = " << (line.size() - endHeader) / 8 << "\n";
		int countText;
		cin >> countText;
		if (((line.size() - endHeader) / 8) < countText) {
			cout << "\nInput text > max \n";
			system("pause");
			return -1;
		}

		cout << "\nDecode text - ";
		for (int j = 0, bb = 0; j < countText; j++) {
			char ch;
			for (int i = 0; i < 8; i++, bb++) {
				if (line[bb + 1 + endHeader] & (1 << 0)) {
					ch |= (1 << 7 - i);
				}
				else {
					ch &= ~(1 << 7 - i);
				}
			}
			cout << ch;
		}
		cout << endl;
	}
	   
	system("pause");
	return 0;
}




























/*


#include <iostream>

#include <fstream>
#include <string>
using namespace std;


const int endHeader = 53;


void getBit(char ch, int(&bits)[8]) {

	for (int i = 7; i >= 0; i--) {
		if (ch & (1 << i))bits[7-i] = 1;
		else bits[7-i] = 0;
		cout << bits[7-i] << ' ';
	}


}

int main()
{
	string line;
	ifstream in("labimgtest.bmp");
	int i = 0;
	if (in.is_open())
	{
		while (!in.eof())
		{
			char a;
			i++;
			in >> a;
			line += a;
			//cout << "i = " << i << ' ' << a << ' ' << (int)a << endl;

		}
	}

	cout << i << endl;
	in.close();     // закрываем файл



cout << endl << ' ' << 'b' << ' ' << (int)'b' << endl;

char alpha = 'b';
int bits[8];
getBit(alpha, bits);
cout << endl;




for (int i = 0; i < 8; i++) {
	if (bits[i] == 1) {
		line[i + 1 + endHeader] |= (1 << 0);
	}
	else line[i + 1 + endHeader] &= ~(1 << 0);
	cout << "i = " << i + 1 + endHeader << ' ' << line[i + 1 + endHeader] << ' ' << (int)line[i + 1 + endHeader] << endl;
}

ofstream out;
out.open("labimg1.bmp");
out << line;
out.close();




system("pause");
return 0;
}


*/



/*


#include <iostream>

#include <fstream>
#include <string>
using namespace std;


const int endHeader = 53;


void getBit(char ch, int(&bits)[8]) {

	for (int i = 7; i >= 0; i--) {
		if (ch & (1 << i))bits[7 - i] = 1;
		else bits[7 - i] = 0;
		cout << bits[7 - i] << ' ';
	}


}

int main()
{

	string codeText = "Trots";
	string line;



	ifstream in("labimgtest.bmp");
	if (in.is_open())
	{
		while (!in.eof())
		{
			char a;
			in >> a;
			line += a;
		}
	}

	in.close();     // закрываем файл


	cout << endl << ' ' << 'b' << ' ' << (int)'b' << endl;

	char alpha = 'b';
	int bits[8];
	getBit(alpha, bits);
	cout << endl;




	for (int i = 0; i < 8; i++) {
		if (bits[i] == 1) {
			line[i + 1 + endHeader] |= (1 << 0);
		}
		else line[i + 1 + endHeader] &= ~(1 << 0);
		cout << "i = " << i + 1 + endHeader << ' ' << line[i + 1 + endHeader] << ' ' << (int)line[i + 1 + endHeader] << endl;
	}

	ofstream out;
	out.open("labimg2.bmp");
	out << line;
	out.close();

	cout << endl;


	line = "";
	ifstream in2("labimg2.bmp");
	if (in2.is_open())
	{
		while (!in2.eof())
		{
			char a;
			in2 >> a;
			line += a;
		}
	}

	in2.close();     // закрываем файл


	char ch;
	for (int i = 0; i < 8; i++) {
		if (line[i + 1 + endHeader] & (1 << 0)) {
			bits[i] = 1;
			ch |= (1 << 7 - i);
		}
		else {
			bits[i] = 0;
			ch &= ~(1 << 7 - i);
		}
		cout << " " << bits[i];
	}
	cout << endl << ch << endl;





	system("pause");
	return 0;
}
*/