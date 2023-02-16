# include <iostream>
# include <ctime>
# include <iomanip>
# include "Account.hpp"

# define WLEFTW2F0 std::right << std::setw(2) << std::setfill('0')

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

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
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

/**
 * GET
*/

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

/**
 * MAKE
*/

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:"       << _accountIndex  << ";";
	std::cout << "p_amount:"    << _amount        << ";";
	_amount += deposit;
	std::cout << "deposit:"     << deposit        << ";";
	std::cout << "amount:"      << _amount        << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;


}

/**
 * @return true if the drawal is allow, false if is refuse.
*/
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();

	std::cout << "index:"          << _accountIndex << ";";
	std::cout << "p_amount:"       << _amount       << ";";
	std::cout << "withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal                         << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:"         << _amount       << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals<< std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{

	return (_amount);
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
	std::cout << "] ";

}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
