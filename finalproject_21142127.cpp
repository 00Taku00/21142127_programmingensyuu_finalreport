#include<iostream>
#include<string>
#include<chrono>
#include<thread>
#include<stdio.h>
#include<random>
#include<regex>
#include<fstream>
#include<vector>
using namespace std;
using namespace this_thread;
using namespace chrono;

//�N���X�̒�`
struct savedeta {
	string name;
	int record;
	void save() {
		ofstream outfile("savedata_name.txt");
		outfile << name << ", " << record << endl;
	}
};

int main() {
	cout << "���X�s�[�h�v�Z�}�X�^�[��\n\n" << "�X�s�[�h�v�Z�}�X�^�[��ڎw���Čv�Z���ɒ��킵�悤�I\n"
		<< "�@2�P�^�̌v�Z�ɒ��킷��Ȃ�u1�v��\n�@"
		<< "�@�L�^������Ȃ�u���낭�v\n����͂��Ă�!\n\n����...";
	string str;
	cin >> str; //�W�����͂��當�����ǂݍ���

	//�G���[����
	int i = 0;
	while (i == 0) {
		if (str == "1") i = 1;
		else if (str == "���낭") i = 1;
		else {
			cout << "\n���̓G���[\n\n����...";
			cin >> str; //�W�����͂��當�����ǂݍ���
			i = 0;
		}
	}
	
	//��������
	if (str == "1") {
		cout << "\n2�P�^�̌v�Z�ɒ���I\n\n<���[��>\n"  << "�E���͑S����10��B\n�E�^�C���A�^�b�N\n�E�s������5�b�̃y�i���e�B\n�E�uEnter�L�[�v�������ăX�^�[�g�I\n\n";
		getchar();
		int z = getchar(); //Enter�L�[�����͂����܂őҋ@
		cout << "�@3\n";
		sleep_for(seconds(1));
		cout << "�@2\n";
		sleep_for(seconds(1));
		cout << "�@1\n";
		sleep_for(seconds(1));
		cout << "�@�X�^�[�g!!\n\n";
		auto t0 = high_resolution_clock::now();//�J�n���Ԃ̌v��
		int Correct = 0;//�������v�Z�̂��߂̕ϐ��ݒ�
		int Incorrect = 0;
		random_device engine;
		uniform_int_distribution<unsigned> ran1(10, 99);//�����ݒ�
		vector<string> vec(10);
		//�o��
		for (int i = 0; i < 10; ++i) {
			cout << "\n��" << i+1 << "��\n";
			int a = ran1(engine);
			int b = ran1(engine);
			cout << a << " + " << b << " = ";
			int c = a + b;
			string Ans;
			cin >> Ans;//�����̓���
			regex rx("\\d+");
			//�����ȊO�̓��͂�s���������ɂ���
			if (regex_match(Ans, rx)) {
				int Answer = stoi(Ans);
				//���딻��
				if (Answer == c) {
					cout << "\n�@��������\n";
						++Correct;
						vec[i] = "����";
				}
				else {
					cout << "\n�@�s����\n�@�@������" << c << endl;
					++Incorrect;
					vec[i] = "�s����";
				}
			}
			else {
				cout << "\n�@�s����\n�@�@������" << c << endl;
				++Incorrect;
				vec[i] = "�s����";
			}
		}
		cout << "\n�@�I��!!\n\n";
		auto t1 = high_resolution_clock::now();//�I�����Ԃ̌v��
		sleep_for(seconds(1));
		cout << "\n���ʂ�...\n";
		sleep_for(seconds(3));
		cout << "�@" << Correct << "�␳��!\n";
		auto time = Incorrect * 5 + duration_cast<milliseconds>(t1 - t0).count() / 1000.;//�^�C���v�Z
		cout << " �^�C���@[ " << time << "�b ]\n";
		int n = 1;
		for (auto i = vec.begin(); i != vec.end(); ++i) {
			cout << n << "��ځ@" << *i << endl;
			++n;
		}
		cout << "�L�^����H�u�͂��v���u�������v�œ����ĂˁB\n����...";
		string str_save;
		cin >> str_save;
		i = 0;
		//�G���[����
		while (i == 0) {
			if (str_save == "�͂�") i = 1;
			else if (str_save == "������") i = 1;
			else {
				cout << "\n���̓G���[\n\n����...";
				cin >> str_save; //�W�����͂��當�����ǂݍ���
				i = 0;
			}
		}
		//�L�^�̃t�@�C���o��
		if (str_save == "�͂�") {
			cout << "�j�b�N�l�[������͂��Ă�!\n����...";
			string nickname;
			cin >> nickname;
			savedeta nickname{nickname, time};
			nickname.save();
		}
		cout << "�V��ł���Ă��肪�Ƃ�\n";
	
	}

	else cout << "\n���낭\n";

}