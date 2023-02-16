# include <iostream>
# include "Account.hpp"

int Account::_nbAccounts = 0;
// int //TODO WIP

Account::Account( int initial_deposit ) :
_amount(initial_deposit)
{
	if (!_nbAccounts)
		_nbAccounts = 1;
	_accountIndex = _nbAccounts - 1;

	std::cout << "index:" << _accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;

	this->_nbAccounts++;
}

void Account::displayAccountsInfos( void )
{
	
}

Account::~Account( void )
{

}
