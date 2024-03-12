#include <windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>



class BazeClass {
public:
	static int count;
	BazeClass() = default;

	BazeClass(std::string name) {
		count++;
		id = count;
	}

	int get_num() {
		return this->num_;
	}

	std::string get_ans() {
		return this->answer;
	}
	int get_num2() {
		return this->num_2;
	}
	int get_id() {
		return this->id;
	}
	void set_answer(std::string ans) {
		this->answer = ans;
	}
	virtual void FirstOne() {};
	virtual void SecondOne() {};
	~BazeClass() {}

private:
	int id;
	std::string answer;
	int num_;
	int num_2;

};

class Formal : public BazeClass {
public:

	void FirstOne() override {
		std::cout << "да" << '\n';
		this->set_answer("да");
	}

	void SecondOne() override {
		std::cout << "нет" << '\n';
		this->set_answer("нет");
	}
};

class Approving : public BazeClass {
public:

	void FirstOne() override {
		std::cout << "вполне";
		this->set_answer("вполне");
	}

	void SecondOne()  override {
		std::cout << "скорее всего";
		this->set_answer("скорее всего");
	}
};

class Skeptical : public BazeClass{
public:

	void FirstOne()  override {
		std::cout << "хорошо подумайте";
	}

	void SecondOne() override {
		std::cout << "вряд ли";
	}

private:

};

class MagicSphere : public BazeClass {
public:
	MagicSphere() {
		answers.push_back(new Skeptical);
		answers.push_back(new Approving);
		answers.push_back(new Formal);
	}

	void ForAnswer() {
		int numm = rand() % 3 + 1;
		int num2 = rand() % 2 + 1;
		if (num2 == 1) {
			answers[numm]->FirstOne();

			std::string path = "myHistory.txt";
			std::ofstream fileOut;

			fileOut.open(path, std::ofstream::app);

			if (!fileOut.is_open()) {
				std::cout << "ERROR" << std::endl;
			}
			else {
				fileOut << "\n" << answers[numm]->get_ans() << "\n";
			}
			fileOut.close();
		}
		else if (num2 == 2) {
			answers[numm]->SecondOne();

			//записывает ответы в файл
			std::string path = "myHistory.txt";
			std::ofstream fileOut;

			fileOut.open(path, std::ofstream::app);

			if (!fileOut.is_open()) {
				std::cout << "ERROR" << std::endl;
			}
			else {
				fileOut << "\n" << answers[numm]->get_ans() << "\n";
			}
			fileOut.close();
		}


	}

	void History() {


	}

private:
	std::vector<BazeClass*> answers;

};

void Console() {

	std::string putTheAnswer;

	std::cout << "Введите интересующий вас вопрос: ";
	std::getline(std::cin, putTheAnswer);

	MagicSphere obj;
	obj.ForAnswer();

	//записывает ответы в файл
	std::string path = "myHistory.txt";
	std::ofstream fileOut;

	fileOut.open(path, std::ofstream::app);

	if (!fileOut.is_open()) {
		std::cout << "ERROR" << std::endl;
	}
	else {
		fileOut << "\n" << putTheAnswer << "\n";
	}
	fileOut.close();

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	Console();



	return 0;
}

