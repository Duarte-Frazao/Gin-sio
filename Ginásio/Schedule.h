#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "Date.h"
#include <set>
#include <iostream>
#include <vector>
#include <new>
#include <string>


typedef enum {CROSSFIT,BODYBUILDING} task_id;


class Task{
public:
	Date start;
	Date end;
	std::string desc;

	Task(Date start, Date end, std::string desc): start(start), end(end), desc(desc){}

	friend std::ostream & operator<<(std::ostream &out , const Task &task);
	bool operator==(const Task &task);

	struct TaskPtrCmp{
		bool operator()(const Task *task1, const Task *task2) const {
			return  !(task2->start < task1->end);
		}
	};


	struct TaskPtrCmpDesc{
		bool operator()(const Task *task1, const Task *task2) const {
			if(task1->desc <= task2->desc) return true;
			else if(task1->desc == task2->desc) return TaskPtrCmp()(task1, task2);

			else return false;
		}
	};
};


class Schedule {

	std::set<Task *,Task::TaskPtrCmp> schedule;

	/**
	 * @brief Remove in the schedule everything between dateStart and dateFinish
	 * @param dateStart Time interval start date
	 * @param dateStart Time interval finish date
	 *
	 * @return
	 */
	void removeInInterval(const Date &dateStart, const Date &dateFinish);

public:
	Schedule();
	virtual ~Schedule();

	/**
	 * @brief Add a task to the schedule
	 * @param dateStart Time interval start date
	 * @param dateStart Time interval finish date
	 * @param description Task description
	 *
	 * @return Returns true if the time interval was added successfully and returns false otherwise
	 */
	bool addTask(const Date &dateStart, const Date &dateFinish, std::string description);

	/**
	 * @brief Change a task of the schedule
	 * @param dateStart Time interval start date
	 * @param dateStart Time interval finish date
	 * @param description Task description
	 *
	 * @return Returns true if the time interval was added successfully and returns false otherwise
	 */
	bool changeTask(const Date &dateStart, const Date &dateFinish, std::string description);

	/**
	 * @brief Delete a task of the schedule
	 * @param dateStart Time interval start date
	 * @param dateStart Time interval finish date
	 * @param description Task description
	 *
	 * @return Returns true if the time interval was added successfully and returns false otherwise
	 */
	bool deleteTask(const Date &dateStart, const Date &dateFinish);

	/**
	 * @brief Display Schedule Menu and call respective functions
	 */
	void editScheduleMenu();

	/**
	 * @brief Add Task - interface
	 * */
	void addTask();

	/**
	 * @brief Change Task - interface
	 */
	void changeTask();

	/**
	 * @brief Delete Task - interface
	 */
	void deleteTask();

	/**
	 * @brief List Tasks Menu
	 */
	void listTaskMenu() const;

	/**
	 * @brief List Tasks by Description
	 * @return Returns true if found any
	 */
	bool listTaskbyDesc() const;
	/**
	 * @brief List Tasks by Time
	 * @return Returns true if found any
	 */
	bool listTaskbyTime() const;

	/**
	 * @brief Prints in a user-friendly way the schedule
	 * @param out Output stream
	 * @param schedule Schedule object
	 */
	friend std::ostream & operator<<(std::ostream &out , const Schedule &schedule);

	/**
<<<<<<< HEAD
	 * @brief Return Set of Task Ptr
	 * @return Schedule
	 */
	std::set<Task *, Task::TaskPtrCmp> getScheduleSet() const;
=======
	* @brief Gets schedule set
	* @return Returns schedule set
	*/
	std::set<std::pair<Date,Date>*,APtrComp> getScheduleSet();

private:
	std::set<std::pair<Date,Date>*,APtrComp> schedule;
>>>>>>> SandroBranch-AEDA-part-2
};

#endif /* SCHEDULE_H_ */
