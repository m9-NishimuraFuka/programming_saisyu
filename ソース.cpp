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
	cout << "���ϓ_�́A" << E << "�_" << endl;
	return E;
}



int main() {
	int num;
	string subject2;
	int score2;
	
	vector<int>v2;

	ofstream outfile("test.txt");
	cout << "���͂������Ƃ���1���A���͂��I�����瑼�̃L�[�������AEnter�������Ă��������B\n";
	cin >> num;

	while (num == 1) {
		cout << "���Ȃ���͂��āAEnter�L�[�������Ă��������B\n";
		cin >> subject2;

		cout << "�_������͂��āAEnter�L�[�������Ă��������B\n";
		cin >> score2;

		outfile << subject2 << " " << score2 <<  endl;

		cout << "���͂������Ƃ���1���A���͂��I�����瑼�̃L�[�������AEnter�������Ă��������B\n";
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
		cout << v1[i].getSubject() << "�́A" << v1[i].getScore() << "�_" << endl;
	}

	cout << "���v�_�́A" << total(v2.begin(), v2.end()) << "�_" << endl;

	ave(total(v2.begin(), v2.end()), v2.size());

}