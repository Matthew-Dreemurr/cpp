# include <iostream>
# include <ctime>
# include <iomanip>
# include "Account.hpp"

# define WLEFTW2F0 std::right << std::setw(2) << std::setfill('0')

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;
// int //TODO WIP

Account::Account( int initial_deposit ) :
_amount(initial_deposit),
_nbDeposits(0),
_nbWithdrawals(0)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;

	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account( void )
{

}

/**
 * GET
*/

int	Account::getNbAccounts( void )
{

	return (0);
}

int	Account::getTotalAmount( void )
{

	return (0);
}

int	Account::getNbDeposits( void )
{

	return (0);
}

int	Account::getNbWithdrawals( void )
{

	return (0);
}

/**
 * MAKE
*/

void	Account::makeDeposit( int deposit )
{
(void) deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
(void) withdrawal;
	return (0);
}

int	Account::checkAmount( void ) const
{

	return (0);
}

/**
 * DISPLAY
*/

void	Account::_displayTimestamp( void )
{
	const std::time_t epoch_time = std::time(NULL);
	const std::tm *time = std::gmtime(&epoch_time);

	std::cout << "[";
	std::cout << WLEFTW2F0 << (time->tm_year + 1900);
	std::cout << WLEFTW2F0 << (time->tm_mon + 1);
	std::cout << WLEFTW2F0 << time->tm_mday;
	std::cout << "_";
	std::cout << WLEFTW2F0 << time->tm_hour;
	std::cout << WLEFTW2F0 << time->tm_min;
	std::cout << WLEFTW2F0 << time->tm_sec;
	std::cout << "]";

}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ":";
	std::cout << "total:" << _totalAmount << ":";
	std::cout << "deposits:" << _totalNbDeposits << ":";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ":";
	std::cout << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}
