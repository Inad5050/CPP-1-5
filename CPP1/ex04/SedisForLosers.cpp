#include "SedisForLosers.hpp"

int	SedisForLosers(std::string fileName1, std::string str1, std::string str2)
{
	std::ifstream	file1(fileName1.c_str()); //we open the file, ifstream receives a const char* in CPP98, we can get a const char* from a std::string with string.c_str
	if (!file1)
		return (std::cerr << "Cannot open " << fileName1 << std::endl, 1);

	std::string	line; //we get a string with the contento of file1
	std::string	file1_content;
	while (std::getline(file1, line))
		file1_content.append(line + '\n');

	int	str1_lenght = str1.length(); //we find every instance of str1, clear it and susbstitute it with str2
	int	i = 0;
	while (file1_content[i])
	{
		i = file1_content.find(str1, i);
		file1_content.erase(i, str1_lenght);
		file1_content.insert(i, str2);
	}

	std::string		fileName2 = fileName1.append("replace"); //we create a new file
	std::ofstream	file2(fileName2.c_str());
	if (!file2)
		return (std::cerr << "Cannot create " << fileName2 << std::endl, 1);

	file2 << file1_content; //we copy the modified string to file2

	file1.close();
	file2.close();
	return (0);
}
