#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "split.h"
#include "nrand.h"

using namespace std;


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


// 주어진 입력 스트림으로 문법 테이블을 읽음.
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // 입력 데이터를 읽음.
    while (getline(in, line)) {
	// 입력 데이터를 단어로 나눔.
	vector<string> entry = split(line);
	if (!entry.empty())
	    // 카테고리 및 연관된 규칙을 맵에 저장
	    ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
    }
    return ret;
}


bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}


void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)) {
	ret.push_back(word);
    }
    else {
	// word와 연관된 규칙을 찾음.
	Grammar::const_iterator it = g.find(word);
	if (it == g.end())
	    throw logic_error("empty rule");

	// 선택 가능한 규칙을 모아 놓은 벡터를 가져옴.
	const Rule_collection& c = it->second;

	// 임의로 하나를 선택
	const Rule& r = c[nrand(c.size())];

	// 선택한 규칙을 재궈적으로 학장
	for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
	    gen_aux(g, *i, ret);
    }
}


vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}


int main() {

    srand(time(NULL));
    
    // 문장 생성
    vector<string> sentence = gen_sentence(read_grammar(cin));

    // 첫 번째 단어 출력
    vector<string>::const_iterator it = sentence.begin();
    if (!sentence.empty()) {
	cout << *it;
	++it;
    }

    // 공백과 함께 나머지 단어 출력
    while (it != sentence.end()) {
	cout << " " << *it;
	++it;
    }
    cout << endl;
    return 0;
}
