/*myFile1b.h, Ex1 devoir4 CSI2772A*/


#include <iostream>
using namespace std;

class Student {
	int numID;
	int nbCourses;
	int maxCourses;
	int* List_grades;
	Course** List_courses;
public:
	Student(int, int); 	//constructor
	~Student(); 		//destructor
	double average();
	int totalHours();
	bool addCourse(Course*, int);
};

Student::Student(int id, int maxC) {
	numID = id;
	maxCourses = maxC;
	nbCourses = 0;
	List_grades = new int[maxCourses];
	List_courses = new Course*[maxCourses];

}

Student::~Student() {
	delete List_grades;
	delete List_courses;
}

double Student::average() {
	double sum = 0;
	for (int i = 0; i < nbCourses; i++) {
		sum += *(List_grades + i);
	}
	return sum / nbCourses;

}

int Student::totalHours() {
	int sum = 0;
	if (nbCourses > 0) {
		for (int i = 0; i < nbCourses; i++) {
			sum += (*(List_courses + i))->getHours();
		}
		return sum;
	}
	return 0;
}


bool Student::addCourse(Course* c, int grade){
	if (maxCourses == nbCourses)
		return false;
	List_grades[nbCourses] = grade;
	List_courses[nbCourses] = c;
	nbCourses++;
	return true;
}
