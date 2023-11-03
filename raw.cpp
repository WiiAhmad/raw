#include <iostream>
#include <algorithm>

using namespace std;

struct raw
{
    float score = 0;
    int frequency = 0;
};

bool compareScores(const raw &a, const raw &b)
{
    return a.score < b.score;
}

int main()
{
    raw data[100];
    int n, score, totalFrequency = 0;

    cout << "input raw data" << endl;
    cout << "========================" << endl;
    cout << "Enter the number of data : ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Data " << i + 1 << endl;
        cout << "Enter score : ";
        cin >> score;

        bool found = false;
        for (int j = 0; j < i; j++)
        {
            if (data[j].score == score)
            {
                data[j].frequency++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            data[i].score = score;
            data[i].frequency = 1;
        }
    }

    cout << endl;
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

    // // Menginisialisasi smallestData dengan nilai dari elemen pertama dalam data
    float smallestData = data[0].score;
    cout << "small sebelum" << smallestData << endl;
    // Menginisialisasi largestData dengan nilai dari elemen pertama dalam data
    float largestData = data[0].score;

    // Mencari nilai terbesar dan terkecil dalam data
    for (int i = 0; i < n; i++)
    {
        if (data[i].score != 0)
        {
            cout << "data" << data[i].score << endl;
            if (smallestData < data[i].score)
            {
                smallestData = data[i].score;
                cout << "small data" << smallestData << endl;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (data[i].score > largestData)
        {
            largestData = data[i].score;
        }
    }

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
}