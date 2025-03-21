#include "Phone_lad3.h"
#include "class_phone_book_lab3.h"
#include <Windows.h>

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Phone_back abonent;
	abonent.push_back_abonent();
	abonent.searc_fio();
	abonent.serch_letter();
	abonent.print_abonent();
	abonent.ATC();

	return 0;
}
