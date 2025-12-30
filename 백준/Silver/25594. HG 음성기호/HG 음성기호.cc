using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<char, string> map;

    map.insert({ 'a',"aespa" });
    map.insert({ 'b',"baekjoon"});
    map.insert({ 'c',"cau"    });
    map.insert({ 'd',"debug"   });
    map.insert({ 'e',"edge"   });
    map.insert({ 'f',"firefox" });
    map.insert({ 'g',"golang" });
    map.insert({ 'h',"haegang" });
    map.insert({ 'i',"iu"     });
    map.insert({ 'j',"java"    });
    map.insert({ 'k',"kotlin"  });
    map.insert({ 'l',"lol"   });
    map.insert({ 'm',"mips"    });
    map.insert({ 'n',"null"    });
    map.insert({ 'o',"os"      });
    map.insert({ 'p',"python"  });
    map.insert({ 'q',"query"   });
    map.insert({ 'r',"roka"    });
    map.insert({ 's',"solvedac"});
    map.insert({ 't',"tod"     });
    map.insert({ 'u',"unix"    });
    map.insert({ 'v',"virus"   });
    map.insert({ 'w',"whale"   });
    map.insert({ 'x',"xcode"   });
    map.insert({ 'y',"yahoo"   });
    map.insert({ 'z',"zebra"   });

    string s;
    cin >> s;

    int pos{ 0 };

    string result{};
    while (pos < s.size())
    {
        char key = s[pos];

        auto it = map.find(key);
        if (it == map.end())
        {
            cout << "ERROR!";
            return 0;
        }

        const string& word = it->second;

        if (pos + word.size() <= s.size() && s.compare(pos, word.size(), word) == 0)
        {
            result += key;
            pos += word.size();
        }
        else
        {
            cout << "ERROR!";
            return 0;
        }
    }
    
    cout << "It's HG!\n" << result;

    return 0;
}
