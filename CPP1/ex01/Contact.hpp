#pragma once

#include <iostream>
#include <limits> //std::numeric_limits<t>
#include <string> //std::string
#include <stdlib.h> //exit
#include "PhoneBook.hpp"

#define MAX_CONTACTS 8

class PhoneBook 
{
private:

	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

    int			add_contact_aux(const std::string& name, std::string& str);
	std::string	set_size(std::string str1) const;
	std::string truncate(std::string str) const;

public:

	void	set_contact(std::string f_name, std::string last_n, std::string nick, std::string phone, std::string secret);
	int		preview(int	index) const;
	int		view_contact(int index) const;

};
