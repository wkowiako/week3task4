#include "Task.h"

std::string Task::taskNameGetter()
{
    return taskName;
}

bool Task::urgentGetter()
{
    return urgent;
}

bool Task::importantGetter()
{
    return important;
}

bool Task::doneGetter()
{
    return done;
}

std::string Task::dateGetter()
{
    return date;
}

int Task::dayGetter()
{
    return day;
}

int Task::monthGetter()
{
    return month;
}

void Task::taskNameSetter(std::string TaskName)
{
    taskName = TaskName;
}

void Task::urgentSetter(bool Urgent)
{
    urgent = Urgent;
}

void Task::importantSetter(bool Important)
{
    important = Important;
}

void Task::doneSetter(bool Done)
{
    done = Done;
}

void Task::dateSetter(std::string Date)
{
    date = Date;
}

void Task::daySetter(int Day)
{
    day = Day;
}

void Task::monthSetter(int Month)
{
    month = Month;
}

int Task::differenceGetter()
{
    return difference;
}

void Task::differenceSetter(int Difference) {
    difference = Difference;
}


