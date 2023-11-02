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

    // // Menginisialisasi smallestData dan largestData dengan nilai yang valid
    // int smallestData = data[0].score;
    // int largestData = data[0].score;

    // // Mencari nilai terbesar dan terkecil dalam data
    // for (int i = 1; i < n; i++)
    // {
    //     if (data[i].score < smallestData)
    //     {
    //         smallestData = data[i].score;
    //     }
    //     if (data[i].score > largestData)
    //     {
    //         largestData = data[i].score;
    //     }
    // }

    // // Menghitung rentang
    // int range = largestData - smallestData;

    // // Menampilkan rentang
    // cout << "Range: " << range << endl;
}