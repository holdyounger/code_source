// regex.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;

std::string readFile(string filePath)
{
	ifstream fin;
	fin.open(filePath, ios::in);
	if (!fin.is_open())
	{
		cout << "无法找到这个文件！" << endl;
		return "";
	}

	string strRead;
	string temp;
	while (getline(fin, temp))
	{
		fin >> temp;
		strRead += temp;
		temp.clear();
	}
	cout << "[read]:\n" << strRead << endl;

	fin.close();
	return strRead;
}

// 日志脱敏
std::string serviceDesensitize(std::string strJson)
{
	std::smatch base_match;
	string reg("\\\"username\\\"\:(.)?\\\"\[a-zA-Z0-9]\*\\\"");
	string reg_sub_name("\\\"sub_name\\\"\:(.)?\\\"\[a-zA-Z0-9]\*\\\"");
	std::regex pattern(reg);
	std::regex pattern_sub_name(reg_sub_name);

	std::regex_match(strJson, base_match, pattern);
	if (base_match.size() == 2) {
		std::string base = base_match[1].str();
		std::cout << "sub-match[0]: " << base_match[0].str() << std::endl;
		std::cout << "sub-match[1]: " << base << std::endl;
	}

	cout << "[正则内容]：" << reg << endl;
	cout << "[匹配的个数]：" << std::regex_search(strJson, pattern) << endl;
	string strV1 = regex_replace(strJson, pattern_sub_name, "\"sub_name\": \"*******\"");
	return regex_replace(strV1, pattern, "\"username\": \"*******\"");
}
// 日志脱敏
std::string serviceDesensitize1(std::string strJson)
{
	std::string reg_username("\\\"username\\\"\:(.)?\\\"\[a-zA-Z0-9]\*\\\"");
	std::string reg_name("\\\"name\\\"\:(.)?\\\"\[a-zA-Z0-9]\*\\\"");
	std::string reg_sub_name("\\\"sub_name\\\"\:(.)?\\\"\[a-zA-Z0-9]\*\\\"");

	std::regex pattern_username(reg_username);
	std::regex pattern_name(reg_name);
	std::regex pattern_sub_name(reg_sub_name);

	std::string strV1 = regex_replace(strJson, pattern_username, "\"username\": \"*******\"");
	std::string strV2 = regex_replace(strV1, pattern_name, "\"name\": \"*******\"");
	return regex_replace(strV2, pattern_sub_name, "\"sub_name\": \"*******\"");
}
int main() {
	string cnt = readFile("regexTest.txt");
	cout << "[正则]：\n" << serviceDesensitize1(cnt);


	return 0;
	std::string fnames[] = { "foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt" };
	// 在 C++ 中 \ 会被作为字符串内的转义符，为使 \. 作为正则表达式传递进去生效，需要对 \ 进行二次转义，从而有 \\.
	std::regex txt_regex("[a-z]+\\.txt");
	for (const auto& fname : fnames)
		std::cout << fname << ": " << std::regex_match(fname, txt_regex) << std::endl;

	string str = "\"USER_PWD\", \"username\": \"shimingming\"}]";
	regex pattern("\"username\": \".*\"");
	cout << regex_replace(str, pattern, "\"username\": \"\"") << endl;	//输出：_2018，将Hello替换为""
	cout << regex_replace(str, pattern, "\"username\": \"*******\"") << endl;	//输出：Hi_2018，将Hello替换为Hi

	//	chat to string
	char num[] = "123456";
	string strnum(num);
	cout << strnum << endl;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
