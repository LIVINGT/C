#include<string>

#include<iostream>

using namespace std;

/**
 * 牛客最近来了一个新员工Fish，
 * 每天早晨总是会拿着一本英文杂志，
 * 写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
 * 有一天他向Fish借来翻看，但却读不懂它的意思。
 * 例如，“student. a am I”。后来才意识到，
 * 这家伙原来把句子单词的顺序翻转了，
 * 正确的句子应该是“I am a student.”。
 * Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
**/
string ReverseSentence(string str) {
        string rs;
		int k = 0;
        for(int i = 0;i < str.length();i ++)
        {
            if(str[i] == ' ')
			{
				string temp(str,k,i - k);
				k = i + 1;
				rs.insert(0,temp);
				rs.insert(0," ");
			}
			
        }
		string temp(str,k,str.length());
		rs.insert(0,temp);
		return rs;
}

	int main()
	{

		cout<<ReverseSentence("student. a am I")<<endl;
		string s = "dadada";
		string rs(s.rbegin(),s.rend());
		cout<<rs<<endl;
		return 0;
	}