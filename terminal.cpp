#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>

void make_directory (std::string* , int size);
void change_directory (std::string* , int size );
void cur_directory (std::string* , int size );
void tree_function (std::string* ,  int size );
void touch_function (std::string* , int size );
void delete_function (std::string* , int size);


int main()
{
  bool start = true;
  while (start) {
  std::string token[3] = {"empty" , "empty", "empty"};
  std::string command;
  std::getline(std::cin,command);
  std::istringstream iss(command);
  int ix = 0;

  while (!iss.eof())
    {
        std::string subs;
        iss >> subs;
        token[ix++] = subs;
    } 
    
    if ( token[0] == "mkdir") {
    	make_directory(token, ix );
    	continue;
	}
	
	if ( token[0] == "chdir") {
    	change_directory(token, ix );
    	continue;
	}
	
	if ( token[0] == "dir") {
    	cur_directory(token, ix );
    	continue;
	}
	
	if ( token[0] == "rmdir") {
    	delete_function(token, ix );
    	continue;
	}
	
	if ( token[0] == "tree") {
    	make_directory(token, ix );
    	continue;
	}
	
	if ( token[0] == "touch") {
    	touch_function(token, ix );
    	continue;
	}
    
  } 
    return 0;
}


void make_directory (std::string* token, int size)
{
	if (size > 2) {
		std::cout << "Unknown command!\n";
		return;
	}
    char * cstr = new char [50];
    std::strcpy (cstr, token[0].c_str());
    std::strcat (cstr, " ");
    std::strcat (cstr, token[1].c_str());
    system(cstr);
}

void change_directory (std::string* token, int size)
{
	if (size > 2) {
		std::cout << "Unknown command!\n";
		return;
	}
    char * cstr = new char [50];
    std::strcpy (cstr, token[0].c_str());
    std::strcat (cstr, " ");
    std::strcat (cstr, token[1].c_str());
    system(cstr);
}

void delete_function (std::string* token, int size)
{
	if (size > 2) {
		std::cout << "Unknown command!\n";
		return;
	}
    char * cstr = new char [50];
    std::strcpy (cstr, token[0].c_str());
    std::strcat (cstr, " ");
    std::strcat (cstr, token[1].c_str());
    system(cstr);
}

void touch_function (std::string* token, int size)
{
	if (size > 2) {
		std::cout << "Unknown command!\n";
		return;
	}
	
	char * cstr = new char [50];
	std::strcpy (cstr, token[0].c_str());
    std::ofstream myfile (cstr);
    if (myfile.is_open())
    {
    std::cout << "File is open!\n";
    }
  else std::cout << "Unable to open file\n";
}


void cur_directory (std::string* token, int size)
{
	if (size > 1) {
		std::cout << "Unknown command!\n";
		return;
	}
    char * cstr = new char [50];
    std::strcpy (cstr, token[0].c_str());
    system(cstr);
}

void tree_function (std::string* token, int size)
{
	if (size > 1) {
		std::cout << "Unknown command!\n";
		return;
	}
    char * cstr = new char [50];
    std::strcpy (cstr, token[0].c_str());
    system(cstr);
}
