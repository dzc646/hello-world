#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main()
{
	char  c, x;
	int inword = 0,ture=1;  //inword用于辅助判断一个单词的结束，true：统计结束后结束循环
	string filename;    //需要打开的文件名
	int line = 0;   //行数
	int word = 0;  //单词数
	int character = 0;   //字符数
	int sentence = 0;  //句子数
	
	while (ture)
	{
		
		cout << "请输入需要统计的类型：w-单词 c-字符 s-句子 l-行数  (均为小写)\n" << endl;
		cin >> x;
		if (x != 'w' & x != 'c' & x != 's' & x!='l')  //限制输入条件
			{
				cout << "输入出错！！！\n请从新输入...\n" << endl;
				continue;
			}
		cout << "请输入需要统计文本的名称，例：test.txt\n" << endl;
		cin >> filename;  //输入文件名
		
		cout << "开始读取文件..." << endl;
		ifstream ifile;
		ifile.open(filename, ios::in);
		if (!ifile)
			{
				cerr << "Open File Fail.\n请重新输入..." << endl;
				continue;
			}
		cout << "读取成功！\n" << endl;

		switch (x)
		{	case 'l': //统计行数
				while (ifile.get(c))
				{
					if (c == '\n')
						line++;
				} 
				cout << "line is:" << line << endl;
				break;
			case 'w':  //统计单词数
				while (ifile.get(c))
				{
					if (!isspace(c) && !inword)     //isspace (c)检查参数c是否为非字母的字符，如：('')、('\t')、('\r')、('\n')、('\v')、('\f')
					{
						inword = 1;
						word++;
					}
					if (isspace(c) && inword)
						inword = 0;				
				}
				cout << "word is:" << word << endl;
				break;
			case 'c':  //统计字符数
				while (ifile.get(c))
				{
					//if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
						character++;
				}
				cout << "character is:" << character << endl;
				break;
			case 's':  //统计句数
				while (ifile.get(c))
				{
					if ( c == '.'|| c== '?' )
						sentence++;
				}
				cout << "sentence is:" << sentence << endl;
				break;

		}

		ifile.close();  //关闭文件
		ture = 0;  //结束循环
		
	}
	system("pause");
}

