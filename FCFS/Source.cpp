#include<iostream>
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
    cout << "\n Nhap so luong phan tu: ";
    cin >> n;
    process p[100];
    for (int i = 0; i < n; i++)
    {
        cout << "\nQuá trình: " << i + 1 << "\n";
        cout << "\nThời điểm đến: ";
        cin >> p[i].a_time;
        cout << "\nThời gian CPU: ";
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
    cout << "\nPID\t\tAT\t\tBT\t\tTAT\t\tWT";
    for (int i = 0; i < n; i++)
    {
        cout << "\n" << p[i].pid << "\t\t" << p[i].a_time << "\t\t" << p[i].b_time << "\t\t" << p[i].t_time << "\t\t" << p[i].w_time;

    }
    cout << "\nThời gian chờ trung bình: " << avg_wt;
    cout << "\nThời gian xoay vòng: " << avg_tt;
    return 0;
}

/*
3
0 24
0 3
0 3
*/



/*
4
0 10
1 1
2 2
3 1
4 5
*/