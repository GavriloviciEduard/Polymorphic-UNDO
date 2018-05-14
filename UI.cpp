#include "UI.h"
#include <conio.h>
#include <windows.h>
#include<limits>




void UI::print_menu_admin()
{
	std::cout << '\n' << "**********************************************************" << '\n';
	std::cout << "A- Add Movie." << '\n';
	std::cout << "B- Remove Movie." << '\n';
	std::cout << "C- Update Movie." << '\n';
	std::cout << "D- Print Movies." << '\n';
	std::cout << "E- Filter Movies(by duration)." << '\n';
	std::cout << "F- Undo." << '\n';
	std::cout << "X- Exit." << '\n';
	std::cout << "**********************************************************" << '\n';
}

void UI::print_menu()
{
	std::cout << '\n' << "**********************************************************" << '\n';
	std::cout << "A - Manage movie repository." << '\n';
	std::cout << "B - Manage watch list." << '\n';
	std::cout << "X - Exit." << '\n';
	std::cout << "**********************************************************" << '\n';
}

void UI::print_menu_user()
{
	std::cout << '\n' << "**********************************************************" << '\n';
	std::cout << "A - See the movies in the database having a given genre." << '\n';
	std::cout << "B - Delete a movie from the watch list " << '\n';
	std::cout << "C - Print the watch list. " << '\n';
	std::cout << "D - Save watch list. " << '\n';
	std::cout << "E - Open watch list. " << '\n';
	std::cout << "X - Exit." << '\n';
	std::cout << "**********************************************************" << '\n';
}

std::string UI::read_string()
{
	std::string str;

	do
	{
		std::getline(std::cin, str);

	} while (str.empty());
	

	return str;
}

int UI::read_nr()
{
	int nr;

	
	std::cin >> nr;

	
	while (std::cin.fail())
	{
		std::cout << "That was no integer! Please enter an integer: ";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin >> nr;
	}

	std::cin.ignore(1000, '\n');

	return nr;
}



void UI::add_ui()
{
	
	std::cout << "Give the title of the movie(non-empty):";
	std::string t;
	t = read_string();
	



	std::cout << '\n' << "Give the genre of the movie(non-empty):";
	std::string g;
	g = read_string();

	std::cout << '\n' << "Give the year of release for the movie(must be >0):";
	int y;
	y = read_nr();

	std::cout << '\n' << "Give the number of likes for the movie(must be >0):";
	int l;
	l = read_nr();

	std::cout << '\n' << "Give a link for the trailer of the movie(non-empty):";
	std::string lnk;
	lnk = read_string();


	std::cout << '\n' << "Give the duration the movie(must be >0):";
	int dr;
	dr = read_nr();




	try 
	{
		this->contr.add_controller(t, g, y, l, lnk, dr);
		this->contr.writeF_repo();
	}
			

	catch (MovieException& e)
	{
		for (auto s : e.get_errors())
			std::cout << s;
	}


	catch (RepositoryException& e)
	{
		std::cout << e.what() << '\n';
	}


	system("pause");
}

void UI::remove_ui()
{
	std::cout << "Give the title of the movie(non-empty):";
	std::string t;
	t = read_string();

	std::cout << '\n' << "Give the year of release for the movie(must be >0):";
	int y;
	y = read_nr();

	try
	{
		this->contr.remove_controller(t, y);
		this->contr.writeF_repo();
	}


	catch (MovieException& e)
	{
		for (auto s : e.get_errors())
			std::cout << s;
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what() << '\n';
	}

	system("pause");
}

void UI::update_ui()
{
	std::cout << "Give the title of the movie(non-empty):";
	std::string t;
	t = read_string();

	std::cout << '\n' << "Give the year of release for the movie(must be >0):";
	int y;
	y = read_nr();

	std::cout << '\n' << "Give the new title of the movie(non-empty):";
	std::string t_new;
	t_new = read_string();

	std::cout << '\n' << "Give the new genre of the movie(non-empty):";
	std::string g_new;
	g_new = read_string();

	std::cout << '\n' << "Give the new year of release for the movie(must be >0):";
	int y_new;
	y_new = read_nr();

	std::cout << '\n' << "Give the new number of likes for the movie(must be >0):";
	int l_new;
	l_new = read_nr();

	std::cout << '\n' << "Give a new link for the trailer of the movie(non-empty):";
	std::string lnk_new;
	lnk_new = read_string();

	std::cout << '\n' << "Give a new duration the movie(must be >0):";
	int dr;
	dr = read_nr();

	try
	{
		this->contr.update_controller(t, y, t_new, g_new, y_new, l_new, lnk_new, dr);
		this->contr.writeF_repo();
	}


	catch (MovieException& e)
	{
		for (auto s : e.get_errors())
			std::cout << s;
	}
	catch (RepositoryException& e)
	{
		std::cout << e.what() << '\n';
	}
	system("pause");
}

void UI::print_movies()
{
	std::vector<Movie> V = this->contr.get_repo();
	int i = 0;

	for (Movie M:V)
	{
		std::cout << ++i <<".";
		std::cout<<M.to_string();
		std::cout << '\n' << '\n';
	}

	if(!this->contr.get_sizeRE())
		std::cout << '\n' << "Nothing to print." << '\n';
		

	system("pause");
}

void UI::remove_ui_wlst()
{
	std::cout << "Give the title of the movie(non-empty):";
	std::string t;
	t = read_string();

	std::cout << '\n' << "Give the year of release for the movie(must be >0):";
	int y;
	y = read_nr();

	if (this->contr.remove_controller_wlst(t, y))
	{
		std::string opt;

		std::cout << '\n' << "The movie was removed from the watch list." << '\n';
		std::cout << '\n' << "Did you liked the movie('Y'-YES, 'N'-NO):";

		opt = read_string();

		if (opt == "Y" || opt == "y")
		{
			this->contr.increment_likes_cn(t, y);
			this->contr.writeF_repo();
		}


	}


	
	else
		std::cout << '\n' << "Nothing to remove from the watch list. " << '\n';


	system("pause");
}

void UI::print_watchlist()
{
	std::vector<Movie> V = this->contr.get_WL();
	int i = 0;

	for (Movie M : V)
	{
		std::cout << ++i << ".";
		std::cout<<M.to_string();
		std::cout << '\n' << '\n';
	}

	if (!this->contr.get_sizeWL())
		std::cout << '\n' << "Nothing to print." << '\n';


	system("pause");
}

void UI::save_watchlist()
{

	this->contr.writeF_wl();
	system("pause");
}

void UI::open_watchlist()
{
	this->contr.openF();
	system("pause");
}

void UI::peruse_database()
{
	std::cout << '\n' << "Give the genre of the movie(non-empty):";
	std::string g;
	std::getline(std::cin, g);

	std::vector<Movie> list = this->contr.filter_genre(g);

	if (list.size())
	{
		int i = 0;
		std::string opt;

		while (true)
		{
			system("cls");
			std::cout<<list[i].to_string();
			std::cout << '\n' << '\n';
			list[i].play();

			std::cout << '\n' << "Add to watch list('Y'-YES, 'N'-NO):";
			opt = read_string();

			if (opt == "Y" || opt=="y")
			{
				if (this->contr.add_controller_wlst(list[i]))
				{
					std::cout << '\n' << "The movie was added to the watch list." << '\n';
		
				}
				else
					std::cout << '\n' << "The movie was not added because it already exists in the watch list." << '\n';

			}


			std::cout << '\n' << "Do you want to see the next movie('Y'-YES, 'N'-NO):";
			opt = read_string();

			if (opt == "N" || opt == "n")
				break;

			i++;

			if (i == list.size())
				i = 0;
		}
	}

	else
		std::cout << '\n' << "No movies with the selected genre. " << '\n';


	system("pause");

}

std::string UI::read_pass()
{
	

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

	std::string s;
	std::getline(std::cin, s);

	SetConsoleMode(hStdin, mode);

	return s;
}

void UI::filter_duration_ui()
{
	std::cout << '\n' << "Give a duration(>0):";
	int dr;
	dr = read_nr();

	std::vector<Movie> V = this->contr.filter_duration_cn(dr);
	int i = 0;

	for (Movie M : V)
	{
		std::cout << ++i << ".";
		std::cout<<M.to_string();
		std::cout << '\n' << '\n';
	}

	system("pause");
}

void UI::undo()
{
	try
	{
		this->contr.undo_controller();
	}

	catch (RepositoryException& e)
	{
		std::cout<<e.what();
	}
}

void UI::start()
{
	while (true)
	{
		system("cls");
		print_menu();
		std::cout << "\n" << "Enter an option:";
		char opt = toupper(_getch());

		if (opt == 'A')
		{
			std::string pass;
			std::cout<<'\n' << "Enter the password for admin mode:";
		
			pass = read_pass();

			if (pass == "19562851956285E")
			{

				while (true)
				{
					system("cls");
					print_menu_admin();
					std::cout << "\n" << "Enter an option:";
					char opt = toupper(_getch());
	

					if (opt == 'X')
						break;

					switch (opt)
					{
					case 'A':
						system("cls");
						add_ui();
						break;

					case 'B':
						system("cls");
						remove_ui();
						break;

					case 'C':
						system("cls");
						update_ui();
						break;

					case 'D':
						system("cls");
						print_movies();
						break;

					case 'E':
						system("cls");
						filter_duration_ui();
						break;

					case 'F':
						system("cls");
						undo();
						break;

					default:
						std::cout << "The option does not exist. Try again." << '\n';
						system("pause");
						break;
					}


					std::cin.ignore();

				}

			}

			else
			{
				std::cout <<'\n'<< "The password was wrong!"<<'\n';
				system("pause");
			}


		}

		else if (opt == 'B')
		{
			while (true)
			{
				system("cls");
				print_menu_user();
				std::cout << "\n" << "Enter an option:";
				char opt = toupper(_getch());


				if (opt == 'X')
					break;

				switch (opt)
				{


				case 'A':
					system("cls");
					peruse_database();
					break;

				case 'B':
					system("cls");
					remove_ui_wlst();
					break;

				case 'C':
					system("cls");
					print_watchlist();
					break;

				case 'D':
					system("cls");
					save_watchlist();
					break;

				case 'E':
					system("cls");
					open_watchlist();
					break;




					default:
						std::cout << "The option does not exist. Try again." << '\n';
						system("pause");
						break;
				}

				std::cin.ignore();
			}

		}

		else if (opt == 'X')
			break;
		

		else
		{
			std::cout << "The option does not exist. Try again." << '\n';
			system("pause");
		}
	}
}