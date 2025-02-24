#include <iostream>
#include <random>

int main()
{
	std::string actualPassword;
	// the actual password will act as our backend stored password
	const int passwordSize = 4;
	int password_generator[4];

	// the password will be unknown to us, because we want to brute force our way to it
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 9);
	for (size_t i = 0; i < passwordSize; i++)
	{
		password_generator[i] = dist(gen);
		actualPassword += std::to_string(password_generator[i]); 
	}

	// For sanity test
	// actualPassword = "1234";

	// for test reasons only
	std::cout << "Password is: " << actualPassword << std::endl;

	std::cout << "Welcome to Random Bank!" << std::endl;
	std::cout << "Please identify yourself: ";
	
	std::string user = "";
	while (!std::cin.eof() && user == "")
	{
		std::getline(std::cin, user);
	}
	std::cout << "Hello " << user << " please provide your password: ";
	std::string password;
	password = "";
	while (!std::cin.eof())
	{
		std::getline(std::cin, password);
		if (password.empty() || password != actualPassword)
			std::cout << "Wrong password: ";
		else
		{
			std::cout << "Correct password" << std::endl;
			break ;
		}
	}
	return (EXIT_SUCCESS);
}