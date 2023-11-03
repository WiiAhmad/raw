#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct raw
{
    float score;
    double frequency;
};

struct classInterval
{
    float lowerBound = 0;
    float upperBound = 0;
    int frequency = 0;
};

bool compareScores(const raw &a, const raw &b)
{
    return a.score < b.score;
}

int main()
{
    raw data[100];
    int n = 0, score;
    double totalFrequency;

    //I need input with direct scores and frequencies, not raw data

    // do
    // {
    //     cout << "Enter the score : ";
    //     cin >> score;
    //     if (score == 000)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         bool found = false;

    //         for (int i = 0; i < n; i++)
    //         {
    //             if (data[i].score == score)
    //             {
    //                 data[i].frequency++;
    //                 found = true;
    //                 break;
    //             }
    //         }

    //         if (!found)
    //         {
    //             data[n].score = score;
    //             data[n].frequency = 1;
    //             n++;
    //         }
    //     }
    // } while (score != 000);

    do{
        cout << "Enter the score : ";
        cin >> score;
        if (score == 000)
        {
            break;
        }
        else
        {
            data[n].score = score;
            cout << "Enter the frequency : ";
            cin >> data[n].frequency;  
            n++;
        }
    }while (score != 000);
    

    cout << "Raw Data" << endl;
    cout << "========================" << endl;
    sort(data, data + n, compareScores);

    for (int i = 0; i < n; i++)
    {
        if (data[i].score != 0 || data[i].frequency != 0)
        {
            cout << "Score : " << data[i].score;
            cout << " Frequency : " << data[i].frequency << endl;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        totalFrequency += data[i].frequency;
    }
    cout << "Total Frequency : " << totalFrequency << endl;

    // Menginisialisasi smallestData dengan nilai dari elemen pertama dalam data
    float smallestData = data[0].score;
    //cout << "small sebelum" << smallestData << endl;
    // Menginisialisasi largestData dengan nilai dari elemen pertama dalam data
    float largestData = data[n-1].score;
    // Menghitung rentang
    float range = largestData - smallestData;

    // Menampilkan rentang
    cout << "Range: " << range << endl;

    for (int i = 0; i < n; i++)
    {
        if (data[i].score != 0 || data[i].frequency != 0)
        {
            cout << "Score : " << data[i].score;
            cout << " Frequency : " << data[i].frequency << endl;
        }
    }
    double logTotalFrequency = log10(totalFrequency);
    cout << "Log Total Frequency : " << logTotalFrequency << endl;
    int k2 = 1 + (3.3 * logTotalFrequency);
    cout << "K2 : " << k2 << endl;
    int k = k2 + 1;
    cout << "Kelas : " << k << endl;
    int interval = (range / k)+1;
    cout << "Interval : " << interval << endl;

}