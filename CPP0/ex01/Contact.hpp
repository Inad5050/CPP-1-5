#pragma once

#include <iostream>
#include <limits> //std::numeric_limits<t>
#include <string> //std::string
#include <stdlib.h> //exit
/* #include "PhoneBook.hpp" */ //two headers can't include each other

#define MAX_CONTACTS 8

class Contact 
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		/* int			add_contact_aux(const std::string& name, std::string& str); */
		std::string	set_size(std::string str1) const;
		std::string truncate(std::string str) const;

	public:
		Contact();
		~Contact();
		void	set_contact(std::string f_name, std::string last_n, std::string nick, std::string phone, std::string secret);
		int		preview(int	index) const;
		int		view_contact(int index) const;
};
