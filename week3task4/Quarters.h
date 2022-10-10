#pragma once
#include <vector>
#include "Task.h"
#include <string>
#include <stdio.h>
#include <ctime>
#include <windows.h>
class Quarters
{
	std::vector<Task> importantUrgent;
	std::vector<Task> notImportantUrgent;
	std::vector<Task> importantNotUrgent;
	std::vector<Task> notImportantNotUrgent;
public:
	void addToImportantUrgent(Task task);
	void addToNotImportantUrgent(Task task);
	void addToImportantNotUrgent(Task task);
	void addToNotImportantNotUrgent(Task task);
	void showQuarterImportantUrgent();
	void showQuarterImportantNotUrgent();
	void showQuarterNotImportantUrgent();
	void showQuarterNotImportantNotUrgent();
	void showQuarters();
	std::string currentDate();
	void addNewTask();
	int getDifference(int, int, int, int);
	int dateToDays(std::string);
	int dateToMonths(std::string);
	bool checkIfUrgent(int);
	void removeAllDoneItems();
	void gameLoop();
	void sortingByDeadlineImportantUrgent();
	void sortingByDeadlineImportantNotUrgent();
	void sortingByDeadlineNotImportantUrgent();
	void sortingByDeadlineNotImportantNotUrgent();
};

