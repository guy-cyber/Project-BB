#include "ballot.h"

int Ballot::getID()
{
	return id;
}
Address Ballot::getAdress()
{
	return address;
}
Voter** Ballot::getVoters()
{
	return voters;
}
float Ballot::getVoters_percent()
{
	return voters_precent;
}


bool Ballot::setID(int temp)
{
	if (temp > 0)
	{
		id = temp;
		return true;
	}
	else return false;
}
bool Ballot::setAddress(Address temp) 
{
	if ((strlen(temp.getCity) > 1) && (temp.getHouse_Number > 0) &&
		(strlen(temp.getStreet) > 0)) {
		address = temp;
		return true;
	}
	else return false;
}
bool Ballot::increaseList(Voter** temp)
{
	phy *= 2;
	voters = new Voter * [phy];
	voters = temp;
	if (!voters)
		return false;
	return true;
}
//check if the citizen is already inside the voters array
bool Ballot::isInVoters(Voter temp)
{
	for (int i = 0; i < log; i++)
	{
		if (CivCmp(voters[i]->getCivilian, temp.getCivilian))
			return true;
		else return false;
	}
}
//compare the citizens id
bool Ballot:: CivCmp(Citizen a,Citizen b)
{
	if (strcmp(a.getID, b.getID) == 0)
		return true;
	else return false;
}
bool Ballot::addVoter(Voter temp)
{
	if (log >= phy)
	{
		if (!(increaseList(voters)))
			return false;
	}
	if (!isInVoters(temp))
	{
		voters[log] = new Voter;
		*(voters[log]) = temp;
		log++;
		return true;
	}
	else return false;
}
bool Ballot::openVotersListList()
{
	log = 0;
	phy = 2;
	voters = new Voter * [phy];
	if (!voters)
		return false;
	return true;
}
