#include<iostream>
#include<fstream>
#include<string>
#include<malloc.h>
using namespace std;


string* dict;
int length;

string* history;
int history_length;

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
		cout << strs[i] << (i < size - 1 ? ", " : "");
	}
	cout << "]\n";
}

int compare(const string& left, const string& right) {
	int len = min(left.length(), right.length());

	for (int i = 0; i < len; i++)
	{
		int c1 = ((unsigned char)left.at(i)) * 2;
		int c2 = ((unsigned char)right.at(i)) * 2;

		if (left.at(i) == 'ё') c1 = ((unsigned char)'е') * 2 + 1;
		if (right.at(i) == 'ё') c2 = ((unsigned char)'е') * 2 + 1;

		if (c1 != c2) {
			return c1 - c2;
		}
	}
	return left.length() - right.length();
}


// O(n*log(n))
bool binary_search(const string& findMe, string* sorted, int length) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;
		if (compare(sorted[middle], findMe) < 0) {
			left = middle + 1;
		}
		else if (compare(sorted[middle], findMe) > 0) {
			right = middle - 1;
		}
		else {
			return true;
		}
	}
	return false;
}

bool in_array(const string& findMe, string* strs, const int size) {
	for (int k = 0; k < size; k++)
	{
		if (findMe == strs[k]) {
			return true;
		}
	}
	return false;
}

// n^k, n - размер алфавита, k - число элементов
// 0000, 0001, 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
// слон => алон, блон, влон
// 33^4 = 1185921 * 1784 = 2115683064
string* getWords(const string& in, const string& out, int &result_length) {
	string* result = new string[result_length];
	string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	for (int i = 0; i < in.size(); i++)
	{
		string current = in;
		if (current[i] != out[i]) {
			for (int j = 0; j < abc.size(); j++)
			{
				current[i] = abc[j];
				//O(1) O(n*log(n))
				if (current != in &&
					!in_array(current, history, history_length) &&
					binary_search(current, dict, length)) {
					add(result, current, result_length);
					add(history, current, history_length);
				}

				//current = current.replace(i, 1, abc.substr(j, 1));
				//for (int k = 0; k < length; k++)
				//{
				//	if (current == dict[k] &&
				//		current != in) {
				//		//cout << current << endl;
				//		add(result, current, result_length);
				//		break;
				//	}
				//}
			}
		}
	}
	return result;
}

bool found = false;

void game(const string& in, const string& out, string* result, int result_length) {
	if (in == out) {
		found = true;
		cout << out << endl;
		cout << "Цепочка найдена!\n";
		add(result, in, result_length);
		print(result, result_length);
		cout << "Размер цепочки = " << result_length << endl;
		return;
	}

	int words_length = 0;
	cout << in << ": ";
	string * words = getWords(in, out, words_length);
	if (words_length > 0) {
		add(result, in, result_length);
	}
	print(words, words_length);
	for (int i = 0; i < words_length; i++)
	{
		if (!found)
		game(words[i], out, result, result_length);
	}

}

void game(const string& in, const string& out) {
	string* result = new string[0];
	int result_length = 0;
	game(in, out, result, result_length);
}

void main2() {
	setlocale(LC_ALL, "russian");
	readDictionary("dict_len4_ansi.txt");
	string in = "стук", out = "слон";
	game(in, out);

}

// стук - сток - стон - слон