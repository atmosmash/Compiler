#include <iostream>
#include <fstream>
using namespace std;
int isNumber(string str)
{
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
int isAlphaNum(char c)
{
	int flag = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
	{
		flag = 1;
	}
	return flag;
}
string readFile(string filename)
{
	string line;
	ifstream t;
	t.open("21BCE3188.txt");
	string buffer = "";
	while (t)
	{
		std::getline(t, line);
		buffer += line;
	}
	t.close();
	return buffer;
}
string removeComment(string program)
{
	string final1 = "";
	for (int i = 0; i < program.length(); i++)
	{
		if (program[i] == '/' && program[i + 1] == '*')
		{
			i += 2;
			while (program[i] != '*')
			{
				if (program[i + 1] == '*' && program[i + 2] == '/')
				{
					program[i] = ' ';
					i += 3;
					break;
				}
				i++;
			}
		}
		final1 += program[i];
	}
	return final1;
}
int main()
{
	string keywords[] = { "int", "if", "then", "print", "else", "endif" };
	string delimiters = "{},;()[]";
	string operators = "=+-*/";
	string program = readFile("21BCE3188.txt");
	string lexeme;
	program = removeComment(program);
	cout << "Registration number: 21BCE3188\n";
	cout << "\tlexeme\t\ttype\t\t\n";
	for (int i = 0; i < program.length(); i++)
	{
		for (int j = 0; j < operators.length(); j++)
		{
			if (program[i] == operators[j])
			{
				cout << "\t" << program[i] << "\t\tOperator\t\n";
				break;
			}
		}
		for (int j = 0; j < delimiters.length(); j++)
		{
			if (program[i] == delimiters[j])
			{
				cout << "\t" << program[i] << "\t\tDelimiter\t\n";
				break;
			}
		}
		if (isAlphaNum(program[i]))
		{
			while (isAlphaNum(program[i]))
				lexeme += program[i++];
			i--;
			int flag = 0;
			for (int j = 0; j < 6; j++)
			{
				if (lexeme == keywords[j])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				cout << "\t" << lexeme << "\t\tKEYWORD\t\t\n";
				lexeme = "";
				flag = 0;
			}
			else
			{
				if (isNumber(lexeme))
					cout << "\t" << lexeme << "\t\tCONSTANT\t\n";

				else
				{
					if (lexeme.length() >= 100)
						cout << "WARNING! identifier " << lexeme << "is to long!\nIdeal length<100\n";
					cout << "\t" << lexeme << "\t\tIDENTIFIER\t\n";
				}

				lexeme = "";
			}
		}
	}
}