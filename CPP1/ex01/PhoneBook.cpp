#include <iostream>

#define	MAX_CONTACTS 8

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

	void	preview(int	index) const
	{
		std::cout	<< "         " << index << "|"
				 	<< set_size(first_name) << truncate(first_name) << "|"
					<< set_size(last_name) << index << "|"
					<< set_size(nickname) << index << "|" << std::endl;
	}

	void	view_contact(int index)
	{
		std::cout << "First Name: " << first_name << std::endl;
		std::cout << "Last Name: " << last_name << std::endl;
		std::cout << "Nickname: " << nickname << std::endl;
		std::cout << "Phone Number: " << phone_number << std::endl;
		std::cout << "Darkest Secret: " << darkest_secret << std::endl;
	}

	private:

	std::string	set_size(std::string str1) const //si el tamaño del string es menor a 10 crea un strings con los espacios que faltan hasta el tamaño. Debe ser constante porque la llamamos dentro de una funcion constante
	{
		std::string str2; //por defecto el constructor lo inicializa a ""
		int	dif = 10 - str1.length();
		return (dif > 0) ? (str2.append(dif, ' ')) : str2;
	}

	std::string truncate(std::string str) const
	{
		return (str.length() > 10) ? (str.substr(0, 9) + ".") : str;
	}
};

class	PhoneBook
{
	private:
	Contact	contact_list[MAX_CONTACTS];
	int		current_contacts;
	int		new_contact_index;



};