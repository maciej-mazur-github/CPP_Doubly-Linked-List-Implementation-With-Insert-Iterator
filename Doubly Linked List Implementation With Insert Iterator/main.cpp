#include <iostream>
#include "Dll_with_insert_iterator.h"
#include "person.h"


int main()
{
	List<int> list1("List<int>");
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4, e = 5;
	list1.addElement(a);
	list1.addElement(b);
	list1.addElement(c);
	cout << list1;


	IteratorDll<int> iter1(list1);
	list1.addElement(c, iter1);
	cout << list1;
	iter1++;
	list1.addElement(e, iter1);
	cout << list1;

	iter1.moveToPosition(2);
	list1.addElement(e, iter1);
	cout << list1;

	iter1.setChosenAfterLast();
	list1.addElement(e, iter1);
	cout << list1;

	list1.removeElement(iter1);
	cout << list1;

	iter1.setChosenAsLast();
	list1.removeElement(iter1);
	cout << list1;

	list1.removeElement(iter1);
	cout << list1;

	iter1.setChosenAsFirst();
	list1.removeElement(iter1);
	cout << list1;

	iter1.moveToPosition(10);
	list1.removeElement(iter1);
	cout << list1;

	iter1.setChosenAsFirst();
	list1.removeElement(iter1);
	cout << list1;


	try
	{
		*iter1 = 99;
		cout << *iter1 << endl;
		cout << *(iter1++) << endl;

		iter1++;
		cout << *iter1 << endl;

		iter1++;
		cout << *iter1 << endl;
	}
	catch (const char* msg) {
		cerr << "Iterator pointing at no object" << endl;
	}
	

	List<string> list2("List<string>");
	string s1 = "word1",
		s2 = "word2",
		s3 = "word3";

	list2.addElement(s1);
	list2.addElement(s2);
	list2.addElement(s3);

	IteratorDll<string> iter2(list2);

	try
	{
		cout << "\n\n" << *iter2 << endl;
	}
	catch (const char* msg) {
		cerr << "Iterator pointing at no object" << endl;
	}




	List<Person> list3("List<Person>");
	Person person1("Caroline"), person2("Meggy"), person3("Jenny");
	IteratorDll<Person> iter3(list3);

	list3.addElement(person1);
	list3.addElement(person2);
	list3.addElement(person3);

	cout << "\n\n" << list3;

	iter3.setChosenAsFirst();

	try
	{
		*iter3 = "Judith";
		cout << "\n\n" << *iter3 << endl;
		iter3.setChosenAfterLast();
		cout << "\n\n" << *iter3 << endl;
	}
	catch (const char* msg) {
		cerr << "Iterator pointing at no object" << endl;
	}

	
	cout << "\n\n" << list3;

	List<int> list4("List<int> with Insert Iterator");
	int x = 1, y = 2, z = 3;

	list4.addElement(x);
	list4.addElement(y);
	list4.addElement(z);
	cout << list4;
	InsertIterator<int> iit(list4);
	IteratorDll<int> iter5(list4);

	try
	{
		cout << *iter5;
		int number1 = 777;
		int number2 = 123;
		//iit++;
		iit = 3333333;
		cout << "\n\n" << list4;
		
		*(++iit) = number1;
		cout << "\n\n" << list4;
		iit++;
		*(iit) = number1;
		//iit++;
		//*iit = 9999;
		cout << "\n\n" << list4;
		*iit = number2;
		cout << "\n\n" << list4;
	}
	catch (const char* msg) {
		cerr << "Iterator pointing at no object" << endl;
	}

	
	cout << "\n\n" << list4;

}