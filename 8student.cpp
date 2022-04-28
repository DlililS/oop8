#include <iostream>
#include <string>
using namespace std;
class Student {
public:
	friend ostream& operator << (ostream& out, const Student& student);
	friend istream& operator>>(istream& in, Student& student);
	Student operator=(const Student& student);
private:
	std::string name, fam, group;
	float score;
	int debt;
};
ostream& operator<<(ostream& out, const Student& student) {
	out << student.name << ' ' << student.fam << ' ' << student.group << ' ' << student.score << ' ' << student.debt << endl;
	return out;
}

Student Student::operator=(const Student& student) {
	this->name = student.name;
	this->fam = student.fam;
	this->group = student.group;
	this->score = student.score;
	return student;
}
istream& operator>>(istream& in, Student& student) {
	in >> student.name;
	in >> student.fam;
	in >> student.group;
	in >> student.score;
	in >> student.debt;
	return in;

}
void number(Student*& a, int n) {
	a = new Student[n];
}

int main() {
	Student* student;
	int n;
	cout << "Enter the number of students: " << endl;
	cin >> n;
	number(student, n);
	cout << "Enter the student's name, surname, group, grade and amount of debt: " << endl;

	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ";
		cin >> student[i];
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ";
		cout << student[i];
	}
	return 0;
}