/*Ex2 - Devoir 3 CSI2772A*/

#include "myLinkedList.h"

int main()
{
	Evaluation* first = NULL;	//Pointer on the first element of the list
	//the list is empty, so initialization to NULL
	int number = 0;			//number of elements in the linked  list 
	int choice;			//choice for the menu

	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
	//VOTRE CODE VIENT ICI
	int position;
	char newstudent[capacity];
	int newgrade;
	Evaluation* temporalcontener = new Evaluation;

	cout << "After which element you want to insert ? (0 for start):" ;
	cin >> position;
	while (position< 0 || position > number) {
		cout << "After which element you want to insert ? (0 for start): ";
		cin >> position;
	}

	cout << endl<<"           Entering the item from the chained list. " << endl;

	cout <<endl<< "Enter the name of the student: ";
	cin.getline(newstudent, capacity, '\t');
	cin.ignore(INT_MAX, '\n');

	//On rempli temporalcontener->student
	for (int i = 0; i < capacity; i++) {
		temporalcontener->student[i] = newstudent[i];
	}

	//On rempli temporalcontener->grade
	cout << "Enter the grade: ";
	cin >> temporalcontener->grade;

	temporalcontener->next = NULL;

	//Cas du premier element
	if (position == 0) {
		temporalcontener->next = p;
		p = temporalcontener;
	}
	//Cas du dernier element
	else if (position == number) {
		Evaluation* reference = new Evaluation;
		reference = p;
		for (int i = 1; i < position; i++) {
			reference = reference->next;
		}
		temporalcontener->next = reference->next;
		reference->next = temporalcontener;
		
	}
	//Cas d'insertion entre deux "Evaluation"
	else {
		Evaluation* reference = new Evaluation;
		reference = p;
		for (int i = 1; i < position; i++) {
			reference = reference->next;
		}
		temporalcontener->next = reference->next;
		reference->next = temporalcontener;
	}
	number++;
	return p;

}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	//VOTRE CODE VIENT ICI
	int position;

	cout << "what is the number of the element to delete ?: " ;
	cin >> position;

	//On verifie la validite de l'entree
	while (position< 0 || position > number) {   
		cout << "Enter a correct value" <<endl<<"what is the number of the element to delete ?: " << endl;
		cin >> position;
	}


	Evaluation* reference = new Evaluation;
	reference->next = p;

	if (position == 1) {
		p = reference->next->next;
	}
	else if (position == number) {
		for (int i = 1; i < position; i++) {
			reference = reference->next;
		}
		reference->next = NULL;
	}
	else {
		for (int i = 1; i < position; i++) {
			reference = reference->next;
		}
		reference->next = reference->next->next;
	}

	number--;
	return p;
}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	//VOTRE CODE VIENT ICI
	Evaluation* reference = new Evaluation;
	reference = p;
	while (reference != NULL) {
		//On affiche le nom
		cout << endl<<"Student :"<<reference->student << endl;
		//On affiche la note
		cout << "The grade is :"<<reference->grade << endl;
		reference = reference->next;
	}
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	//VOTRE CODE VIENT ICI
	if (nbre == 0) {
		cout << 0;
		return 0;
	}
	Evaluation* reference = new Evaluation;
	reference->next = p;
	int totalGrade = 0;
	int averagegrades = 0;
	while (reference->next != NULL) {
		reference = reference->next;
		//On additionne toutes les valeurs
		totalGrade = totalGrade + reference->grade;
	}
	//On calcule la moyenne
	averagegrades = totalGrade / nbre;
	cout << averagegrades;
	return 1;
}
