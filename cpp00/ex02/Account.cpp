/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:43:36 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/05 10:35:19 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account(int initial_deposit)
{
	initial_deposit ++;
	return;
}

Account::~Account(void)
{
	return;
}

int	Account::getNbAccounts(void)
{
	return(0);
}

int Account::getTotalAmount(void)
{
	return(0);
}

int Account::getNbDeposits(void)
{
	return(0);
}

int Account::getNbWithdrawals(void)
{
	return(0);
}

void Account::displayAccountsInfos(void)
{
	return;
}

void Account::makeDeposit(int deposit)
{
	deposit ++;
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	withdrawal --;
	return(false);
}

int Account::checkAmount(void) const
{
	return(0);
}

void Account::displayStatus(void) const
{
	return;
}

void Account::_displayTimestamp(void)
{
	return;
}

