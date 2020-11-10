#include<iostream>
#include<string>
#define out(X) (cout << #X << " = " << X << endl)

using namespace std;


void lesson_06() {
	char ch = 'a';
	cout << "ch = " << ch << endl;
	cout << "(int) ch = " << (int) ch << endl;

	ch++;
	cout << "after increment\n";
	cout << "ch = " << ch << endl;
	cout << "(int) ch = " << (int) ch << endl;

	char str[12] = "chars array";
	char str2[] = {'c', 'h', 'a', 'r', '\0'};

	const char* str3 = "chars dyn array";
	cout << "str3 = " << str3 << endl;
	str3 = "new text";
	cout << "str3 = " << str3 << endl;
	cout << "strlen(str3) = " << strlen(str3) << endl;

	string str4 = "text example";
	out(str4);

	string str5("pointer text example");

	// size(), length()
	for (int i = 0; i < str4.size(); i++)
	{
		cout << "str4_i"<< i << " = "
			<< str4.at(i) << endl;
		//str4[i];
	}

	//str4.empty()
	//str4.clear()
	// str4.resize()

	string str6 = "asdf1234";
	out(str6);
	int count = 0;
	for (int i = 0; i < str6.length(); i++)
	{
		if (str6.at(i) >= '0' && 
			str6.at(i) <= '9')
			count++;
	}

	cout << "digits count is " << count << endl;

	out(str6.front());
	out(str6.back());
	out(str6.back());
	out(str6.substr(4, 2));
	//modifying
	str6.append("new text");
	out(str6);
	
	str6.insert(4, "ASDF");
	out(str6);

	str6.replace(0, 4, "REPLACED");
	out(str6);

	out(str6.find("EP"));
	out((int)str6.find("EPPP"));

	str6.erase(3, 6);
	out(str6);

	


}