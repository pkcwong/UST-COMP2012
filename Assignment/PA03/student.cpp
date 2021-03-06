/*
 * student.cpp
 *
 */

#include "student.h"

/* TODO: Constructors
 * - history is a pointer to an int array, storing completed courses
 * - num is the length of this array
 * When cp_type = AVL_CP, store course_plan as an AVL tree; otherwise store course_plan as a BST
 */
Student::Student(const string& id, const int* history, int num, CP_TYPE cp_type) : id(id){
	for(int i = 0; i < num; i++){
		course_history.insert(history[i]);
	}
	if(cp_type == BST_CP){
		course_plan = new BST<Course, int>;
	}else if(cp_type == AVL_CP){
		course_plan = new AVL<Course, int>;
	}
}


/* TODO: Add a course into course_history
 *   course_db is a database containing all valid courses, stored in an STL map
 *   The key values used in the STL map are the course code
 */
void Student::update_course_history(const map<int, Course>& course_db, int code){
    //Write your codes here.
    //Check whether the course code is valid, i.e., it exists in the course_db.
	if(course_db.find(code) != course_db.end()){
		//If it is valid, add it to course_history.
		this->course_history.insert(code);
	}else{
		//Otherwise print an appropriate message, please refer to the sample output.
		cout << id << ": Fail to update history with an invalid course COMP" << code << endl;
	}
}


/* TODO:
 * Print completed courses in ascending order of the course codes
 * Remark: You should use the STL iterator to go through the course history
 *         which is an STL set.
 */
void Student::print_course_history() const{
    cout << id << ": Course history: ";
    //Write your codes here
    set<int>::iterator historyIterator = course_history.begin();
    for(; historyIterator != course_history.end(); historyIterator++){
    	cout << *historyIterator << " ";
    }
    cout << endl;
}


/* TODO: Add a course into course_plan
 *   course_db is a database containing all valid courses, stored in an STL map
 *   The key values used in the STL map are the course code
 */
void Student::enroll(const map<int, Course>& course_db, int code){
    //Write your codes here
    //Check whether the course code is valid, if not then print an appropriate message.
	if(course_db.find(code) != course_db.end()){
	    //If the course code is valid, further check whether its pre-requisites are all completed.7
		bool prerequisitesCompleted = true;
		Course course = course_db.find(code)->second;
		for(int i = 0; i < course.get_num_prerequisites(); i++){
			if(course_history.find(course.get_prerequisites(i)) != course_history.end()){
				prerequisitesCompleted = true;
			}else{
				prerequisitesCompleted = false;
				break;
			}
		}
		//If all pre-requisites are completed, add the course into course_plan, otherwise print an appropriate message.
		if(prerequisitesCompleted == false){
		    cout << id << ": Can't enroll COMP" << code << ". Not all pre-requisites are satisfied yet." << endl;
		}else{
			course_plan->insert(course_db.find(code)->second, code);
		}
	}else{
		cout << id << ": Fail to enroll an invalid course COMP" << code << endl;
	}
    //Please refer to the sample output for all messages.
}

/* TODO:
 * Remove a course from course_plan
 */
void Student::drop(const int code){
    //Write your codes here
	course_plan->remove(code);
}


/* TODO: Select courses with course_code larger than base from course_plan
 * Remark: Print the selected courses in ascending order of the course codes
 */
void Student::select_by_code(int base){
    cout << "Student ID: " << id << endl;
    //Write your codes here
    course_plan->iterator_init();
    while(!course_plan->iterator_end()){
    	Course course = course_plan->iterator_next();
    	if(course.get_code() > base){
    		cout << course << endl;
    	}
    }

}

/* TODO: Select courses that have lectures on day from the course_plan
 * Remark: Print the selected courses in ascending order of the course codes
 */
void Student::select_by_day(weekday day){
    cout << "Student ID: " << id << endl;
    //Write your codes here
    course_plan->iterator_init();
    while(!course_plan->iterator_end()){
    	Course course = course_plan->iterator_next();
    	if(course.get_time().match(day)){
    		cout << course << endl;
    	}
    }

}

/* TODO: Check the details of an enrolled course
 * Remark: Print an appropriate message if the course is not in the course plan
 */
void Student::check_course(int code) const{
    //Write your codes here
    //Please refer to the sample output for the output message.
	if(course_plan->search(code) != NULL){
	    course_plan->iterator_init();
	    while(!course_plan->iterator_end()){
	    	Course course = course_plan->iterator_next();
	    	if(course.get_code() == code){
	    		cout << course << endl;
	    		break;
	    	}
	    }
	}else{
		cout << "No" << endl;
	}

}
    


/* TODO: Print all courses students plan to take 
 * Remark: Print the courses stored in the BT in preorder format
 */
void Student::list_course_plan() const{
    cout << "Student ID: " << id << endl;
    //Write your codes here
    course_plan->preorder_traversal();

}

/* Print course_plan in a readable tree format.
 * DON'T MODIFY THIS FUNCTION
 */
void Student::print_course_plan_tree() const{
    cout << "Student ID: " << id << endl;
    course_plan->print();
}
