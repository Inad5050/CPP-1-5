#include <iostream>
#include <limits>
#include <stdlib.h>

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
	int		index;
	int		contact_count;

	public:

	PhoneBook() : index (0), contact_count (0)
	{
		std::cout << "Type ADD to create a new contact" << std::endl;
		std::cout << "Type SEARCH to display a specific contact" << std::endl;
		std::cout << "Type EXIT to finish the program, contacts will be lost" << std::endl;
	}

	int	add_contact()
	{	
		std::string	first_name, last_name, nickname, phone_number, darkest_secret;

		if (!add_contact_aux("first name", first_name))
			return (std::cout << "Contact info can't be empty" << std::endl, 1);
		if (!add_contact_aux("last name", last_name))
			return (std::cout << "Contact info can't be empty" << std::endl, 1);
		if (!add_contact_aux("nickname", nickname))
			return (std::cout << "Contact info can't be empty" << std::endl, 1);
		if (!add_contact_aux("phone number", phone_number))
			return (std::cout << "Contact info can't be empty" << std::endl, 1);
		if (!add_contact_aux("darkest secret", darkest_secret))
			return (std::cout << "Contact info can't be empty" << std::endl, 1);
		contact_list[index].set_contact(first_name, last_name, nickname, phone_number, darkest_secret);
		index = (index + 1) % MAX_CONTACTS;
		if (contact_count < MAX_CONTACTS)
			contact_count++;
		return (std::cout << "Contact added" << std::endl, 0);
	}

//std::cin >> selected_index attempts to read a value from the input stream before checking if the end of the file (EOF) has been reached. Even if we call first for the eof evaluation
//std::numeric_limits: This indicates that we are using the numeric_limits template from the standard library.
//<std::streamsize>: This specifies that we are specializing the template for the type std::streamsize.
//::max(): This calls the member function max() of the specialization std::numeric_limits<std::streamsize>, which returns the maximum value that std::streamsize can hold.
	
	int	search_contact() const
	{
		int	selected_index = -1;

		if (!contact_count)
			return (std::cout << "PhoneBook is empty" << std::endl, 1);
		for (int i = 0; i < MAX_CONTACTS; i++)
			contact_list[i].preview(i);
		std::cout << "Enter index for additional information" << std::endl;
		while (1)
		{
			if (!(std::cin >> selected_index))
			{
				if (std::cin.eof())
					return (1);
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Incorrect index" << std::endl;
			}
			else if (!(0 <= selected_index && selected_index < MAX_CONTACTS))
				std::cout << "Incorrect index" << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		contact_list[selected_index].view_contact(selected_index);
		return (0);
	}

	private:

	int	add_contact_aux(std::string name, std::string& str)
	{
		std::cout << "Enter " << name << std::endl;
		std::getline(std::cin, str);
		return (str.length());
	}
};

int	main()
{
	PhoneBook	PB;
	std::string	input;
	while(1)
	{
		if (std::cin.eof())
			return(std::cout << "EOF: Input stream closed" << std::endl, 0);
		std::cout << "Enter command (ADD, SEARCH or EXIT): " << std::endl;
		if (!std::getline(std::cin, input))
			break;
		else if (input == "ADD")
			(PB.add_contact());
		else if (input == "SEARCH")
		{
			if (PB.search_contact())
				continue;
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Incorrect command" << std::endl;
	}
	return (0);
}
