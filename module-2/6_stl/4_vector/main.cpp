#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<string> v)
{
    cout << "Ваш вектор." << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1 << ". " << v[i] << endl;
    }
}

int main()
{
    vector<string> v;
    std::string buff = "";

    do
    {
        getline(cin, buff);
        if (buff.size() > 0)
        {
            v.push_back(buff);
        }
    } while (buff != "");

    print(v);

    v.erase(v.begin()+2);

    print(v);

    return 0;
}