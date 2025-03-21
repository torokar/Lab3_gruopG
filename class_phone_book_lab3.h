#pragma once
#include "Phone_lad3.h"

class Phone_back
{
private:
	std::vector<Abonent> phone_book;
	int col = 0;
	bool flag = true;

public:
	Phone_back()
	{
		std::cout << "������� ��������� �� ������ ��������?\n--> ";
		std::cin >> col;
		if (std::cin.fail())
		{
			while (flag)
			{
				std::cout << "������������ ����!���������� �����.\n--> ";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<long>::max(), '\n');
				std::cin >> col;
				if (!std::cin.fail()) { flag = false; break; }
			}
		}
		std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	}

	void push_back_abonent()
	{
		std::cout << "������� ������ � ���������� �����.\n";
		for (int i = 0; i < col; i++)
		{
			Abonent new_abonent;

			std::cout << "������� �.�.� " << i + 1 << " ��������:\n--> ";
			std::getline(std::cin, new_abonent.name);

			std::cout << "������� ����� " << i + 1 << " ��������:\n--> ";
			std::cin >> new_abonent.number;
			if (new_abonent.number < 0)
			{
				while (!(std::cin >> new_abonent.number))
				{
					std::cout << "������������ �����! ���������� ��� ���:\n--> ";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<long>::max(), '\n');
				}
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "������� ����� " << i + 1 << " ��������:\n--> ";
			std::getline(std::cin, new_abonent.address);

			phone_book.push_back(new_abonent);

		}
	}


	void searc_fio()
	{
		system("cls");
		std::cout << "\n������� ������� �������� ��� ������:\n--> ";
		std::string input_fio, input_fio_in_vec;
		std::getline(std::cin, input_fio);
		std::vector<std::string> fio_vec;

		int size_fio = input_fio.size();
		for (int i = 0; i < phone_book.size(); i++)
		{
			std::string su = phone_book[i].name;
			input_fio_in_vec = su.substr(0, size_fio);
			fio_vec.push_back(input_fio_in_vec);
		}

		for (int i = 0; i < fio_vec.size(); i++)
		{
			if (input_fio == fio_vec[i])
			{
				std::cout << "\n������� ��������: " << phone_book[i].name << "| ����� ��������: " << phone_book[i].number << std::endl;
			}
		}
		fio_vec.clear();
	}

	void serch_letter()
	{
		std::string let;
		std::string sub_let;
		std::cout << "\n������� ����� � ������� ���������� �������(����� ������ ���� ���������):\n--> ";
		std::cin >> let;
		int c = 0;
		std::cout << "\n��� ������� ������������ �� ����� " << let << ": " << std::endl << std::endl;
		for (int i = 0; i < phone_book.size(); i++)
		{
			std::string sub = phone_book[i].name;
			sub_let = sub.substr(0, 1);
			if (let == sub_let)
			{
				std::cout << "�������: " << phone_book[i].name << " ����� ��������: " << phone_book[i].number << std::endl;
				c++;
			}
		}
		if (c == 0)
		{
			std::cout << "***� ���������� ����� ������� ������������ �� ����� '" << let << "' �� ����������!***\n";
		}
	}


	void ATC()
	{
		int num = 0;
		int sub_num;
		std::vector<int>ATC_num;
		for (int i = 0; i < phone_book.size(); i++)
		{
			sub_num = phone_book[i].number / 1000000000;
			ATC_num.push_back(sub_num);
		}

		for (int i = 0; i < ATC_num.size(); i++)
		{
			bool already_processed = false;
			for (int k = 0; k < i; k++)
			{
				if (ATC_num[i] == ATC_num[k])
				{
					already_processed = true;
					break;
				}
			}

			if (already_processed)
			{
				continue;
			}

			int num = 0;

			for (int j = 0; j < ATC_num.size(); j++)
			{
				if (ATC_num[i] == ATC_num[j])
				{
					num++;
				}
			}

			std::cout << "���������� ��� � ������� '" << ATC_num[i] << "' = " << num << std::endl;
		}
	}


	void print_abonent()
	{
		//system("cls");
		std::string str(230, '=');
		std::cout << "\n������ ��������� � ���������� �����:\n";
		std::cout << str << std::endl;
		for (int i = 0; i < phone_book.size(); i++)
		{
			std::cout << "\n�.�.� " << i + 1 << " ��������: " << phone_book[i].name << std::endl;
			std::cout << "����� �������� " << i + 1 << " ��������: " << phone_book[i].number << std::endl;
			std::cout << "����� " << i + 1 << " ��������: " << phone_book[i].address << std::endl << std::endl;
			std::cout << str << std::endl;
		}
	}

};
