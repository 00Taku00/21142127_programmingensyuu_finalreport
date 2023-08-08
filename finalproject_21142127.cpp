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

//クラスの定義
struct savedeta {
	string name;
	int record;
	void save() {
		ofstream outfile("savedata_name.txt");
		outfile << name << ", " << record << endl;
	}
};

int main() {
	cout << "★スピード計算マスター★\n\n" << "スピード計算マスターを目指して計算問題に挑戦しよう！\n"
		<< "　2ケタの計算に挑戦するなら「1」を\n　"
		<< "　記録を見るなら「きろく」\nを入力してね!\n\n入力...";
	string str;
	cin >> str; //標準入力から文字列を読み込む

	//エラー処理
	int i = 0;
	while (i == 0) {
		if (str == "1") i = 1;
		else if (str == "きろく") i = 1;
		else {
			cout << "\n入力エラー\n\n入力...";
			cin >> str; //標準入力から文字列を読み込む
			i = 0;
		}
	}
	
	//条件分岐
	if (str == "1") {
		cout << "\n2ケタの計算に挑戦！\n\n<ルール>\n"  << "・問題は全部で10問。\n・タイムアタック\n・不正解は5秒のペナルティ\n・「Enterキー」を押してスタート！\n\n";
		getchar();
		int z = getchar(); //Enterキーが入力されるまで待機
		cout << "　3\n";
		sleep_for(seconds(1));
		cout << "　2\n";
		sleep_for(seconds(1));
		cout << "　1\n";
		sleep_for(seconds(1));
		cout << "　スタート!!\n\n";
		auto t0 = high_resolution_clock::now();//開始時間の計測
		int Correct = 0;//正答数計算のための変数設定
		int Incorrect = 0;
		random_device engine;
		uniform_int_distribution<unsigned> ran1(10, 99);//乱数設定
		vector<string> vec(10);
		//出題
		for (int i = 0; i < 10; ++i) {
			cout << "\n第" << i+1 << "問\n";
			int a = ran1(engine);
			int b = ran1(engine);
			cout << a << " + " << b << " = ";
			int c = a + b;
			string Ans;
			cin >> Ans;//答えの入力
			regex rx("\\d+");
			//数字以外の入力を不正解扱いにする
			if (regex_match(Ans, rx)) {
				int Answer = stoi(Ans);
				//正誤判定
				if (Answer == c) {
					cout << "\n　★正解★\n";
						++Correct;
						vec[i] = "正解";
				}
				else {
					cout << "\n　不正解\n　　答えは" << c << endl;
					++Incorrect;
					vec[i] = "不正解";
				}
			}
			else {
				cout << "\n　不正解\n　　答えは" << c << endl;
				++Incorrect;
				vec[i] = "不正解";
			}
		}
		cout << "\n　終了!!\n\n";
		auto t1 = high_resolution_clock::now();//終了時間の計測
		sleep_for(seconds(1));
		cout << "\n結果は...\n";
		sleep_for(seconds(3));
		cout << "　" << Correct << "問正解!\n";
		auto time = Incorrect * 5 + duration_cast<milliseconds>(t1 - t0).count() / 1000.;//タイム計算
		cout << " タイム　[ " << time << "秒 ]\n";
		int n = 1;
		for (auto i = vec.begin(); i != vec.end(); ++i) {
			cout << n << "問目　" << *i << endl;
			++n;
		}
		cout << "記録する？「はい」か「いいえ」で答えてね。\n入力...";
		string str_save;
		cin >> str_save;
		i = 0;
		//エラー処理
		while (i == 0) {
			if (str_save == "はい") i = 1;
			else if (str_save == "いいえ") i = 1;
			else {
				cout << "\n入力エラー\n\n入力...";
				cin >> str_save; //標準入力から文字列を読み込む
				i = 0;
			}
		}
		//記録のファイル出力
		if (str_save == "はい") {
			cout << "ニックネームを入力してね!\n入力...";
			string nickname;
			cin >> nickname;
			savedeta nickname{nickname, time};
			nickname.save();
		}
		cout << "遊んでくれてありがとう\n";
	
	}

	else cout << "\nきろく\n";

}