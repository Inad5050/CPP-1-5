#include "Contact.hpp"

class	Contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	public:
	void	set_contact(std::string f_name, std::string last_n, std::string nick, std::string phone, std::string secret)
	{
		first_name = f_name;
		last_name = last_n;
		nickname = nick;
		phone_number = phone;
		darkest_secret = secret;
	}

	int		preview(int	index) const
	{
		if (index > MAX_CONTACTS)
			return (std::cout << "Incorrect index" << std::endl, 1);
		std::cout	<< "         " << index << "|"
				 	<< set_size(first_name) << truncate(first_name) << "|"
					<< set_size(last_name) << truncate(last_name) << "|"
					<< set_size(nickname) << truncate(nickname) << "|" << std::endl;
		return (0);
	}

	int		view_contact(int index) const
	{
		if (index > MAX_CONTACTS)
			return (std::cout << "Incorrect index" << std::endl, 1);
		std::cout << "First Name: " << first_name << std::endl;
		std::cout << "Last Name: " << last_name << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone Number: " << phone_number << std::endl;
		std::cout << "Darkest Secret: " << darkest_secret << std::endl;
		return (0);
	}

	private:

	std::string	set_size(std::string str1) const
	{
		std::string str2;
		int	dif = 10 - str1.length();
		return (dif > 0) ? (str2.append(dif, ' ')) : str2;
	}

	std::string truncate(std::string str) const
	{
		return (str.length() > 10) ? (str.substr(0, 9) + ".") : str;
	}
};
