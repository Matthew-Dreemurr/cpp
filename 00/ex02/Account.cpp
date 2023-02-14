# include <iostream>
# include "Account.hpp"

Account::Account( int initial_deposit )
{
	(void) initial_deposit;
	std::cout << "test" << initial_deposit << std::endl;
}



Account::~Account( void )
{

}
