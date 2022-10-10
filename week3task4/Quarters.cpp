#define _CRT_SECURE_NO_WARNINGS
#include "Quarters.h"

void Quarters::addToImportantUrgent(Task task)
{
	importantUrgent.push_back(task);
}

void Quarters::addToNotImportantUrgent(Task task)
{
	notImportantUrgent.push_back(task);
}

void Quarters::addToImportantNotUrgent(Task task)
{
	importantNotUrgent.push_back(task);
}

void Quarters::addToNotImportantNotUrgent(Task task)
{
	notImportantNotUrgent.push_back(task);
}

//function to give us a current date MM/DD/YYYY
std::string Quarters::currentDate()
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, 80, "%m/%d/%Y ", timeinfo);
	std::string str(buffer);
	str.erase(2, 1);

	return str;

	system("PAUSE");
}

// To store number of days in all months from January to Dec.
const int monthDays[12]
= { 31, 28, 31, 30, 31, 30,
   31, 31, 30, 31, 30, 31 };

// This function returns number of days between two given dates
int Quarters::getDifference(int d, int m, int dc, int mc)
{
	// initialize count using years and day
	// Add days for months in given date 
	long int n1 = d;
	for (int i = 0; i < m - 1; i++)
		n1 += monthDays[i];

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' --> current date
	long int n2 = dc;
	for (int i = 0; i < mc - 1; i++)
		n2 += monthDays[i];

	// return difference between two counts
	int difference = n1 - n2;
	return (difference);
}

bool Quarters::checkIfUrgent(int difference) {
	return difference < 3;
}


void Quarters::addNewTask()
{
	Task newTask;
	std::cout << "Enter the task:" << std::endl;
	std::string newTaskName;
	std::cin >> newTaskName;
	newTask.taskNameSetter(newTaskName);

	std::cout << "Enter the deadline [MM-DD]:" << std::endl;
	std::string newDate, newDay, newMonth;
	std::cin >> newDate;
	newTask.dateSetter(newDate);
	newMonth += newDate[0];
	newMonth += newDate[1];
	newDay += newDate[3];
	newDay += newDate[4];
	int NewMonth = std::stoi(newMonth);
	int NewDay = std::stoi(newDay);
	newTask.daySetter(NewDay);
	newTask.monthSetter(NewMonth);

	std::string date = currentDate();
	int currentDay = dateToDays(date);
	int currentMonth = dateToMonths(date);
	int difference = getDifference(NewDay, NewMonth, currentDay, currentMonth);
	newTask.differenceSetter(difference);
	bool ifUrgent = checkIfUrgent(difference);
	newTask.urgentSetter(ifUrgent);


	std::cout << "Importance (if important enter 1, if false enter 0):" << std::endl;
	bool newImportant;
	std::cin >> newImportant;
	newTask.urgentSetter(newImportant);
	newTask.doneSetter(0);

	if (newTask.urgentGetter() && newTask.importantGetter()) {
		addToImportantUrgent(newTask);
	}
	if (newTask.urgentGetter() && !newTask.importantGetter()) {
		addToNotImportantUrgent(newTask);
	}
	if (!newTask.urgentGetter() && newTask.importantGetter()) {
		addToImportantNotUrgent(newTask);
	}
	if (!newTask.urgentGetter() && !newTask.importantGetter()) {
		addToNotImportantNotUrgent(newTask);
	}
}



int Quarters::dateToDays(std::string date) {
	std::string temp;
	temp += date[0];
	temp += date[1];
	int days = std::stoi(temp);
	return days;
}

int Quarters::dateToMonths(std::string date) {
	std::string temp;
	temp += date[2];
	temp += date[3];
	int months = std::stoi(temp);
	return months;
}

void Quarters::showQuarterImportantUrgent()
{
	sortingByDeadlineImportantUrgent();
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "                  IMPORTANT & URGENT " << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	for (int i = 0; i < importantUrgent.size(); i++) {
		std::cout << i + 1 << ". ";
		std::cout << "[";
		if (importantUrgent[i].doneGetter()) {
			std::cout << "X";
		}
		else {
			std::cout << " ";
		}
		std::cout << "] ";
		std::cout << importantUrgent[i].dateGetter() << " ";
		std::cout << importantUrgent[i].taskNameGetter();
		std::cout << std::endl;
	}
}

void Quarters::showQuarterImportantNotUrgent() {
	sortingByDeadlineImportantNotUrgent();
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "                  IMPORTANT & NOT URGENT " << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	for (int i = 0; i < importantNotUrgent.size(); i++) {
		std::cout << i + 1 << ". ";
		std::cout << "[";
		if (importantNotUrgent[i].doneGetter()) {
			std::cout << "X";
		}
		else {
			std::cout << " ";
		}
		std::cout << "] ";
		std::cout << importantNotUrgent[i].dateGetter() << " ";
		std::cout << importantNotUrgent[i].taskNameGetter();
		std::cout << std::endl;
	}
}

void Quarters::showQuarterNotImportantUrgent() {
	sortingByDeadlineNotImportantUrgent();
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "                  NOT IMPORTANT & URGENT " << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	for (int i = 0; i < notImportantUrgent.size(); i++) {
		std::cout << i + 1 << ". ";
		std::cout << "[";
		if (notImportantUrgent[i].doneGetter()) {
			std::cout << "X";
		}
		else {
			std::cout << " ";
		}
		std::cout << "] ";
		std::cout << notImportantUrgent[i].dateGetter() << " ";
		std::cout << notImportantUrgent[i].taskNameGetter();
		std::cout << std::endl;
	}
}

void Quarters::showQuarterNotImportantNotUrgent() {
	sortingByDeadlineNotImportantNotUrgent();
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << "                  NOT IMPORTANT & NOT URGENT " << std::endl;
	std::cout << "-------------------------------------------------------------" << std::endl;
	for (int i = 0; i < notImportantNotUrgent.size(); i++) {
		std::cout << i + 1 << ". ";
		std::cout << "[";
		if (notImportantNotUrgent[i].doneGetter()) {
			std::cout << "X";
		}
		else {
			std::cout << " ";
		}
		std::cout << "] ";
		std::cout << notImportantUrgent[i].dateGetter() << " ";
		std::cout << notImportantUrgent[i].taskNameGetter();
		std::cout << std::endl;
	}
}

void Quarters::showQuarters() {
	showQuarterImportantUrgent();
	std::cout << std::endl;
	showQuarterImportantNotUrgent();
	std::cout << std::endl;
	showQuarterNotImportantUrgent();
	std::cout << std::endl;
	showQuarterNotImportantNotUrgent();
}

void Quarters::removeAllDoneItems() {
	for (int i = 0; i < importantUrgent.size(); i++) {
		if (importantUrgent[i].doneGetter()) {
			std::vector<Task>::iterator it;
			it = importantUrgent.begin() + i;
			importantNotUrgent.erase(it);
		}
	}

	for (int i = 0; i < importantNotUrgent.size(); i++) {
		if (importantNotUrgent[i].doneGetter()) {
			std::vector<Task>::iterator it;
			it = importantNotUrgent.begin() + i;
			importantNotUrgent.erase(it);
		}
	}

	for (int i = 0; i < notImportantUrgent.size(); i++) {
		if (notImportantUrgent[i].doneGetter()) {
			std::vector<Task>::iterator it;
			it = notImportantUrgent.begin() + i;
			notImportantUrgent.erase(it);
		}
	}

	for (int i = 0; i < notImportantNotUrgent.size(); i++) {
		if (notImportantNotUrgent[i].doneGetter()) {
			std::vector<Task>::iterator it;
			it = notImportantNotUrgent.begin() + i;
			notImportantNotUrgent.erase(it);
		}
	}

}


void Quarters::gameLoop()
{
	//Menu:
		//Add new task
		//Modify a task -> wchodzisz do ćwiartek - oznacz jako done, remove
		//showkłoters
		//quit

	while (true) {
		std::cout << "-------------------------------MENU-------------------------" << std::endl;
		std::cout << "1. Add new task" << std::endl;
		std::cout << "2. Mark a task as done" << std::endl;
		std::cout << "3. Mark a task as udnone" << std::endl;
		std::cout << "4. Remove a task" << std::endl;
		std::cout << "5. Remove all done items" << std::endl;
		std::cout << "6. Quit application" << std::endl;
		showQuarters();
		int input;
		std::cin >> input;
		//Adding new task 
		if (input == 1) {
			system("CLS");
			addNewTask();
		}
		//Mark as done
		else if (input == 2) {
			system("CLS");
			std::cout << "Choose a quarter:" << std::endl << "1: ";
			showQuarterImportantUrgent();
			std::cout << "2:" << std::endl;
			showQuarterImportantNotUrgent();
			std::cout << "3: " << std::endl;
			showQuarterNotImportantUrgent();
			std::cout << "4: " << std::endl;
			showQuarterNotImportantNotUrgent();
			int choice;
			std::cin >> choice;
			system("CLS");
			std::cout << "Enter the number of the task: ";
			int taskNumber;
			std::cin >> taskNumber;
			if (choice == 1) {
				system("CLS");
				showQuarterImportantUrgent();
				importantUrgent[taskNumber - 1].doneSetter(true);
			}
			if (choice == 2) {
				system("CLS");
				showQuarterImportantNotUrgent();
				importantNotUrgent[taskNumber - 1].doneSetter(true);
			}
			if (choice == 3) {
				system("CLS");
				showQuarterNotImportantUrgent();
				notImportantUrgent[taskNumber - 1].doneSetter(true);
			}
			if (choice == 4) {
				system("CLS");
				showQuarterNotImportantNotUrgent();
				notImportantNotUrgent[taskNumber - 1].doneSetter(true);
			}
		}
		//Marking task as undone
		else if (input == 3) {
			system("CLS");
			std::cout << "Choose a quarter:" << std::endl << "1: ";
			showQuarterImportantUrgent();
			std::cout << "2:" << std::endl;
			showQuarterImportantNotUrgent();
			std::cout << "3: " << std::endl;
			showQuarterNotImportantUrgent();
			std::cout << "4: " << std::endl;
			showQuarterNotImportantNotUrgent();
			int choice;
			std::cin >> choice;
			system("CLS");
			std::cout << "Enter the number of the task: ";
			int taskNumber;
			std::cin >> taskNumber;
			if (choice == 1) {
				system("CLS");
				showQuarterImportantUrgent();
				importantUrgent[taskNumber - 1].doneSetter(false);
			}
			if (choice == 2) {
				system("CLS");
				showQuarterImportantNotUrgent();
				importantNotUrgent[taskNumber - 1].doneSetter(false);
			}
			if (choice == 3) {
				system("CLS");
				showQuarterNotImportantUrgent();
				notImportantUrgent[taskNumber - 1].doneSetter(false);
			}
			if (choice == 4) {
				system("CLS");
				showQuarterNotImportantNotUrgent();
				notImportantNotUrgent[taskNumber - 1].doneSetter(false);
			}


		}
		//Remove
		else if (input == 4) {
			system("CLS");
			std::cout << "Choose a quarter:" << std::endl << "1: ";
			showQuarterImportantUrgent();
			std::cout << "2:" << std::endl;
			showQuarterImportantNotUrgent();
			std::cout << "3: " << std::endl;
			showQuarterNotImportantUrgent();
			std::cout << "4: " << std::endl;
			showQuarterNotImportantNotUrgent();
			int choice;
			std::cin >> choice;
			system("CLS");
			std::cout << "Enter the number of the task to remove: ";
			int taskNumber;
			std::cin >> taskNumber;
			if (choice == 1) {
				system("CLS");
				showQuarterImportantUrgent();
				std::vector<Task>::iterator it;
				it = importantUrgent.begin() + taskNumber - 1;
				importantUrgent.erase(it);
			}
			if (choice == 2) {
				system("CLS");
				showQuarterImportantNotUrgent();
				std::vector<Task>::iterator it;
				it = importantUrgent.begin() + taskNumber - 1;
				importantNotUrgent.erase(it);
			}
			if (choice == 3) {
				system("CLS");
				showQuarterNotImportantUrgent();
				std::vector<Task>::iterator it;
				it = notImportantUrgent.begin() + taskNumber - 1;
				notImportantUrgent.erase(it);

			}
			if (choice == 4) {
				system("CLS");
				showQuarterNotImportantNotUrgent();
				std::vector<Task>::iterator it;
				it = notImportantNotUrgent.begin() + taskNumber - 1;
				notImportantNotUrgent.erase(it);
			}
		}
		//Removing all done items
		else if (input == 5) {
			removeAllDoneItems();
		}
		//Quit
		else if (input == 6) {
			system("CLS");
			std::cout << "See you again!";
			Sleep(3000);
			exit(1);
		}
		else
			std::cout << "Wrong input" << std::endl;
	}
}

void Quarters::sortingByDeadlineImportantUrgent() {

	int i, j;
	for (i = 0; i < importantUrgent.size(); i++) {

		// Last i elements are already
		// in place
		for (j = 0; j < importantUrgent.size() - i - 1; j++) {
			if (importantUrgent[j].differenceGetter() > importantUrgent[j + 1].differenceGetter()) {
				std::swap(importantUrgent[j], importantUrgent[j + 1]);
			}
		}
	}
}

void Quarters::sortingByDeadlineImportantNotUrgent() {

	int i, j;
	for (i = 0; i < importantNotUrgent.size(); i++) {

		// Last i elements are already
		// in place
		for (j = 0; j < importantNotUrgent.size() - i - 1; j++) {
			if (importantNotUrgent[j].differenceGetter() > importantNotUrgent[j + 1].differenceGetter()) {
				std::swap(importantNotUrgent[j], importantNotUrgent[j + 1]);
			}
		}
	}
}

void Quarters::sortingByDeadlineNotImportantUrgent() {

	int i, j;
	for (i = 0; i < notImportantUrgent.size(); i++) {

		// Last i elements are already
		// in place
		for (j = 0; j < notImportantUrgent.size() - i - 1; j++) {
			if (notImportantUrgent[j].differenceGetter() > notImportantUrgent[j + 1].differenceGetter()) {
				std::swap(notImportantUrgent[j], notImportantUrgent[j + 1]);
			}
		}
	}
}

void Quarters::sortingByDeadlineNotImportantNotUrgent() {

	int i, j;
	for (i = 0; i < notImportantNotUrgent.size(); i++) {

		// Last i elements are already
		// in place
		for (j = 0; j < notImportantNotUrgent.size() - i - 1; j++) {
			if (notImportantNotUrgent[j].differenceGetter() > notImportantNotUrgent[j + 1].differenceGetter()) {
				std::swap(notImportantNotUrgent[j], notImportantNotUrgent[j + 1]);
			}
		}
	}
}

