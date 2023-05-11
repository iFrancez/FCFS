#include<iostream>
#include<iomanip>
using namespace std;

struct process
{
	int pid;
	int s_time;
	int c_time;
	int t_time;
	int w_time;
	int b_time;
	int a_time;
	int r_time;

};
static bool compare(process a, process b)
{
	return a.a_time < b.a_time;
}
static bool compare2(process a, process b)
{
	return a.pid < b.pid;
}
int main()
{
	int n;
	float avg_tt = 0, avg_wt = 0, total_tt = 0, total_wt = 0;
	cout << "\nNhap so luong tien trinh: ";
	cin >> n;
	process p[100];
	for (int i = 0; i < n; i++)
	{
		//mã màu cam
		cout << "\n\x1b[33mQua trinh P\x1b[0m" << "\x1b[33m"<<i + 1 <<"\x1b[0m" << "\n";
		cout << "\nThoi diem den: ";
		cin >> p[i].a_time;
		cout << "\nThoi gian CPU: ";
		cin >> p[i].b_time;
		p[i].pid = i + 1;

	}
	//sort(p, p + n, compare);
	for (int i = 0; i < n; i++)
	{
		p[i].s_time = (i == 0) ? p[i].a_time : p[i - 1].c_time;
		p[i].c_time = p[i].s_time + p[i].b_time;
		p[i].t_time = p[i].c_time - p[i].a_time;
		p[i].w_time = p[i].t_time - p[i].b_time;
		p[i].r_time = p[i].s_time - p[i].a_time;

		total_wt += p[i].w_time;
		total_tt += p[i].t_time;

	}
	avg_wt = (total_wt / n);
	avg_tt = (total_tt / n);
	//sort(p, p + n, compare2);
	cout << "\t\t\t+----+---------------+---------------+---------------+---------------+\n";
	//cout << "| ID | Thoi diem den | Thoi gian CPU | Thoi gian xoay| Thoi gian cho |\n";
	cout << "\t\t\t| \x1b[33mID\x1b[0m | \x1b[33mThoi diem den\x1b[0m | \x1b[33mThoi gian CPU\x1b[0m | \x1b[33mThoi gian xoay\x1b[0m| \x1b[33mThoi gian cho\x1b[0m |\n";

	cout << "\t\t\t+----+---------------+---------------+---------------+---------------+\n";
	for (int i = 0; i < n; i++)
	{
		//cout << "\n" << p[i].pid << "\t\t" << p[i].a_time << "\t\t\t" << p[i].b_time << "\t\t\t" << p[i].t_time << "\t\t\t" << p[i].w_time;
		cout << "\t\t\t| " << setw(2) << p[i].pid << " | " << setw(13) << p[i].a_time << " | " << setw(13) << p[i].b_time << " | " << setw(13) << p[i].t_time << " | " << setw(13) << p[i].w_time << " |\n";
	}
	cout << "\t\t\t+----+---------------+---------------+---------------+---------------+\n";
	cout << "\n\x1b[33mThoi gian cho trung binh:\x1b[0m ";
	for (int i = 0; i < n - 1; i++) {
		cout << p[i].w_time << " + ";
	}
	cout << p[n - 1].w_time;
	cout << " / " << n << " = " << avg_wt;
	cout << "\n\x1b[33mThoi gian xoay vong trung binh:\x1b[0m ";
	for (int i = 0; i < n - 1; i++) {
		cout << p[i].t_time << " + ";
	}
	cout << p[n - 1].t_time;
	cout << " / " << n << " = " << avg_tt << "\n\n";
	return 0;
}

/*
3
0 24
0 3
0 3
*/



/*
5
0 10
1 1
2 2
3 1
4 5
*/