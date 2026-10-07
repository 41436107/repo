#include <iostream>
#include <algorithm>
using namespace std;

int m;						 // 去重複元素後的集合大小
bool is_first_subset = true; // 控制 subset 之間的逗號

void powerset(int index, bool* chosen, char* p)
{

    if (index == m)
    {
        if (!is_first_subset)
            cout << ", ";
        is_first_subset = false;

        cout << "(";
        bool first_element = true;
        for (int i = 0; i < m; i++)// 掃過全部 m 個元素，看哪些被選進 subset
        {
            if (chosen[i])
            {
                if (!first_element)// 如果不是 subset 的第一個元素，先逗號隔開
                    cout << ", ";
                cout << p[i];
                first_element = false;
            }
        }
        cout << ")";
        return;
    }

    // false：不選
    chosen[index] = false;
    powerset(index + 1, chosen, p);

    // true：選
    chosen[index] = true;
    powerset(index + 1, chosen, p);
}

int main()
{
    int n;
    cout << "有幾個元素?: ";
    cin >> n;
	cout << "有"<<n<<"個元素 "<<"\n";
	
    char* input = new char[n];
    cout << "請輸入元素:";
    for (int i = 0; i < n; i++)
        cin >> input[i];

    // 排序並去掉重複元素 
    sort(input, input + n);
    m = unique(input, input + n) - input;

    bool* chosen = new bool[m];// 初始化：一開始所有元素都設為「沒選」
    for (int i = 0; i < m; i++)
        chosen[i] = false;

    cout << "powerset(S) = { ";
    powerset(0, chosen, input);// 呼叫遞迴函式，從 index = 0（第一個元素）開始決定
    cout << " }" << endl;
    
	//釋放配置的記憶體
    delete[] chosen;
    delete[] input;
    return 0;
}
