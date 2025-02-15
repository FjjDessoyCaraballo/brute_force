/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include <iostream>
#include <random>

int main()
{
	// the actual password will act as our backend stored password
	std::string actualPassword;
	const int passwordSize = 4;
	// the password will be unknown to us, because we want to brute force our way to it
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(0, 9);
	for (size_t i = 0; i < passwordSize; i++)
	{
		password[i] = dist(gen);
		actualPassword += 
	}



	std::cout << "Welcome to Random Bank!" << std::endl;
	std::cout << "Please identify yourself: ";
	std::string user = "";
	while (!std::cin.eof() && user == "")
	{
		std::getline(std::cin, user);
	}
	std::cout << std::endl;
	std::cout << "Hello " << user << " please provide your password: ";
	std::string password = "";
	while (!std::cin.eof() && password == "")
	{
		std::getline(std::cin, password);
		if (password.empty() || password != actualPassword)
			std::cout << "Wrong password" << std::endl;
		else
		{
			std::cout << "Correct password" << std::endl;
			break ;
		}
	}
	return (EXIT_SUCCESS);
}