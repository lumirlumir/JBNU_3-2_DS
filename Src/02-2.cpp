//#include<iostream>
//#include<string>
//#define MAX_STACK_SIZE 20
//
///* Class */
//class ArrayStack {
//private:
//    int top;
//    char data[MAX_STACK_SIZE];
//
//public:
//    /* Constructor & Destructor */
//    ArrayStack() : top(-1) {
//    }
//    ~ArrayStack() {
//    }
//    /* Method */
//    bool isEmpty() {
//        return top == -1;
//    }
//    bool isFull() {
//        return top == MAX_STACK_SIZE - 1;
//    }
//    void push(int e) {
//        if (isFull())
//            printf("���� ��ȭ ����");
//
//        data[++top] = e;
//    }
//    int pop() {
//        if (isEmpty())
//            printf("���� ���� ����");
//
//        return data[top--];
//    }
//};
//
///* Function */
//bool checkMatching(std::string ch) {
//    /* Init */
//    ArrayStack st;
//    int nLine = 0;
//    int nChar = 0;
//    int nQuot = 0;
//    bool s_q = false;
//    bool b_q = false;
//    bool anno1 = false;
//    bool anno2 = false;
//
//    /* Calculation */
//    for (int i = 0; i < ch.length(); i++) {
//        /* �ּ� */
//        if (ch[i] == '\/' && ch[i + 1] == '\/' && s_q == false && b_q == false)
//            anno1 = true;
//        if (ch[i] == '\/' && ch[i + 1] == '*')
//            anno2 = true;
//        /* ���� ����ǥ */
//        if (ch[i] == '\'' && anno1 == false && anno2 == false && s_q == false)
//            s_q = true;
//        else if (ch[i] == '\'' && s_q == true)
//            s_q = false;
//        /* ū ����ǥ */
//        if (ch[i] == '\"' && anno1 == false && anno2 == false && b_q == false)
//            b_q = true;
//        else if (ch[i] == '\"' && b_q == true)
//            b_q = false;
//        /* ��ȣ */
//        if ((ch[i] == '\'') && s_q == false && b_q == false && anno1 == false && anno2 == false)
//            st.push(ch[i]);
//        if ((ch[i] == '\'') && s_q == false && b_q == false && anno1 == false && anno2 == false) {
//            if (st.isEmpty()) {
//                nLine++;
//                std::cout << "Error, Line_count : " << nLine << ", " << "quotes_count : " << nChar;
//            }
//            char prev = st.pop();
//            nChar++;
//            nQuot++;
//
//            if ((prev != '[' && ch[i] == ']') || (prev != '(' && ch[i] == ')') || (prev != '{' && ch[i] == '}')) {
//                nChar--;
//                nLine++;
//                break;
//            }
//        }
//        if (ch[i] == '\n') {
//            nLine++;
//            anno1 = false;
//        }
//        if (ch[i] == '*' && ch[i + 1] == '\/')
//            anno2 = false;
//    }
//
//    /* Output */
//    if (st.isEmpty() && s_q == false)
//        std::cout << "OK, Line_count : " << nLine << ", " << "quotes_count : " << nQuot;
//    else
//        std::cout << "Error, Line_count : " << nLine << ", " << "quotes_count : " << nQuot;
//
//    /* Return */
//    return st.isEmpty();
//}
//
//int main() {
//    std::string Str, temp;
//    while (true) {
//        std::getline(std::cin, temp);
//        if (temp == "EOF")break;
//        Str.append(temp);
//        Str.append("\n");
//        std::cin.clear();
//    }
//
//    checkMatching(Str);
//
//    return 0;
//}