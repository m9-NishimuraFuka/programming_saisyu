#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<regex>
using namespace std;

class Test {
protected:
	string subject;
	int score;

public:
	void setSubject(const string& newSubject) { subject = newSubject; }
	string getSubject() { return subject; }
	void setScore(int newScore) { score = newScore; }
	int getScore() { return score; }

};



template<typename T>
int total(T first, T last) {
	int sum = 0;
	for (T p = first; p != last; ++p)sum += *p;
	return sum;
}

auto ave(float all, float size) {
	int E = all / size;
	cout << "平均点は、" << E << "点" << endl;
	return E;
}



int main() {
	int num;
	string subject2;
	int score2;
	
	vector<int>v2;

	ofstream outfile("test.txt");
	cout << "入力したいときは1を、入力を終えたら他のキーを押し、Enterを押してください。\n";
	cin >> num;

	while (num == 1) {
		cout << "教科を入力して、Enterキーを押してください。\n";
		cin >> subject2;

		cout << "点数を入力して、Enterキーを押してください。\n";
		cin >> score2;

		outfile << subject2 << " " << score2 <<  endl;

		cout << "入力したいときは1を、入力を終えたら他のキーを押し、Enterを押してください。\n";
		cin >> num;

		v2.emplace_back(score2);

	}

	ifstream datafile("test.txt");
	vector<Test>v1;
	int j = 0;
	string subject;
	int score;
	
	while (datafile >> subject >> score ) {
		v1.emplace_back();
		v1[j].setSubject(subject);
		v1[j].setScore(score);
		j++;
	}
	size_t u = v1.size();
	for (size_t i = 0; i < u; ++i) {
		cout << v1[i].getSubject() << "は、" << v1[i].getScore() << "点" << endl;
	}

	cout << "合計点は、" << total(v2.begin(), v2.end()) << "点" << endl;

	ave(total(v2.begin(), v2.end()), v2.size());

}