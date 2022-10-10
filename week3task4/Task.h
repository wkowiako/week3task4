#pragma once

#include <iostream>

class Task
{
	std::string taskName;
	bool urgent;
	bool important;
	bool done;
	std::string date;
	int day;
	int month;
	int difference;

public:
	std::string taskNameGetter();
	bool urgentGetter();
	bool importantGetter();
	bool doneGetter();
	std::string dateGetter();
	int dayGetter();
	int monthGetter();
	void taskNameSetter(std::string TaskName);
	void urgentSetter(bool Urgent);
	void importantSetter(bool Important);
	void doneSetter(bool Done);
	void dateSetter(std::string Date);
	void daySetter(int Day);
	void monthSetter(int Month);
	int differenceGetter();
	void differenceSetter(int);
};

