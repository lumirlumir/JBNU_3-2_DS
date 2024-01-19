//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int bracket_count = 0;
//int line_count = 0;
//
//void checkmatching(string str) {
//    /* Init */
//    stack<char> s;
//
//    bool error = false;     //flag ����
//    bool b_q = false;       //flag ū����ǥ
//
//    /* Calculate */
//    for (int i = 0; i < str.size(); i++) {
//        /* ū����ǥ */
//        if (str[i] == '"') {
//            if (b_q == false) {
//                b_q = true;
//            }
//            else {
//                b_q = false;
//            }
//
//            continue;
//        }
//
//        /* ��ȣ */
//        if (!b_q) {
//            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
//                s.push(str[i]);
//            }
//            else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
//                if (s.empty() ||
//                    (str[i] == ')' && s.top() != '(') ||
//                    (str[i] == '}' && s.top() != '{') ||
//                    (str[i] == ']' && s.top() != '[')) {
//                    error = true;
//                    break;
//                }
//                else {
//                    s.pop();
//                    bracket_count++;
//                }
//            }
//        }       
//    }
//
//    /* Output */
//    if (!s.empty() || error || b_q)
//        std::cout << "Error";
//    else
//        std::cout << "OK";
//
//    std::cout << ", Line_count : " << line_count << ", bracket_count : " << bracket_count;
//
//    /* Return */
//    return;
//}
//
//int main(int argc, char* argv[]) {
//    /* Faster */
//    ios::sync_with_stdio(0);
//    cin.tie(0); std::cout.tie(0);
//
//    /* Init */
//    string str;
//    while (true) {
//        string tmp; getline(cin, tmp);
//        if (tmp == "EOF") break;
//
//        str.append(tmp);
//        str.append("\n");
//
//        line_count++;
//            
//        cin.clear();
//    }
//
//    /* Output */
//    checkmatching(str);
//
//    /* End */
//    return 0;
//}
//
///*
//'\'\'a'
//'\'\'a
//EOF
//
//Error, Line_count : 2, quotes_count : 1
//-----------------------
//'\'\'a'
//'\'\'a'
//EOF
//
//OK, Line_count : 2, quotes_count : 2
//-----------------------
//*/