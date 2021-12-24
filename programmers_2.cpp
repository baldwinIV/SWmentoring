#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    while (progresses.size() > 0)
    {
        // cout << "\n first now is :" << progresses[0] << endl;
        while (progresses[0] < 100)
        {
            for (int i = 0; i < progresses.size(); i++)
            {
                progresses[i] += speeds[i];
            }
        }

        // for (int i = 0; i < progresses.size(); i++)
        // {
        //     cout << progresses[i] << " ";
        // }

        int prognum = 0;
        while (progresses[0] >= 100)
        {
            prognum++;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
            if (progresses.size() == 0)
            {
                break;
            }
        }
        answer.push_back(prognum);
    }
    return answer;
}
int main(void)
{
    vector<int> input = {93, 30, 55};
    vector<int> speed = {1, 30, 5};
    vector<int> answer = solution(input, speed);
    vector<int>::iterator iter;
    std::cout << "Hello\n";
    for (iter = answer.begin(); iter != answer.end(); iter++)
    {
        std::cout << *iter << " ";
    }
    return 0;
}