#include<iostream>
#include<fstream>
#include<string>
#include<malloc.h>
using namespace std;


string* dict;
int length;

void readDictionary(const char* filename) {
	ifstream file(filename);
	if (file.is_open()) {
		char* line = new char();
		length = 0;
		while (file.getline(line, 10)) {
			length++;
		}
		cout << length << endl;
		file.clear();
		file.seekg(0);
		dict = new string[length];
		for (int i = 0; file.getline(line, 10); i++)
		{
			dict[i] = line;
		}
		file.close();
	}
}

void add(string*& strs, string add, int &size) {
	//int size = _msize(strs) / sizeof(string);
	string* result = new string[size + 1];
	int i = 0;
	for (; i < size; i++)
	{
		result[i] = strs[i];
	}
	result[i] = add;
	strs = result;
	size++;
}

void print(string* strs, int &size) {
	cout << "[";
	for (size_t i = 0; i < size; i++)
	{
		cout << strs[i] << (i < size - 1 ? ", " : "]\n");
	}
}

string* getWords(string in, int &result_length) {
	string* result = new string[result_length];
	string abc = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	for (int i = 0; i < in.size(); i++)
	{
		string current = in;
		for (int j = 0; j < abc.size(); j++)
		{
			current = current.replace(i, 1, abc.substr(j, 1));
			for (int k = 0; k < length; k++)
			{
				if (current == dict[k] &&
					current != in) {
					//cout << current << endl;
					add(result, current, result_length);
					break;
				}
			}
		}
	}
	return result;
}

void main2() {
	setlocale(LC_ALL, "russian");
	readDictionary("dict_len4_ansi.txt");
	string in = "ñòóê", out = "ñëîí";
	int result_length = 0;
	print(getWords(in, result_length), result_length);
	

}