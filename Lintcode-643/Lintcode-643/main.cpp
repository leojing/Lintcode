//
//  main.cpp
//  Lintcode-643
//
//  Created by Jing Luo on 5/28/20.
//  Copyright © 2020 Jing Luo. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

int lengthLongestPath(string &input) {
    int result = 0;
    stack<pair<int, int>> folder;
    int currentLen = 0;
    int currentLevel = 0;
    bool isFile = false;
    int n = int(input.size());
    for (int i = 0; i < n; i ++) {
        // first folder
        if (folder.empty()) {
            if (input[i] == '\n' || i == n-1) {
//            if ((i+1<n && input[i] == '\\' && input[i+1] == 'n') || i == n-1) {
                if (isFile) {
                    currentLen += 1;
                    result = result < currentLen ? currentLen : result;
                    isFile = false;
                }
                folder.push(make_pair(currentLen, 0));
                currentLevel = 0;
                currentLen = 0;
//                i += 1;
                continue;
            }
            if (input[i] == '.') {
                isFile = true;
            }
            if (input[i] == ' ') {
                continue;
            }
            currentLen ++;
        } else {
            if (input[i] == '\t') {
//            if (i+1 < n && input[i] == '\\' && input[i+1] == 't') {
//                i += 1;
                currentLevel ++;
                continue;
            }
            if (input[i] == '\n' || i == n-1) {
//            if ((i+1<n && input[i] == '\\' && input[i+1] == 'n') || i == n-1) {
                pair<int, int> last = folder.top();
                while (last.second >= currentLevel) {
                    folder.pop();
                    if (folder.empty()) {
                        break;
                    }
                    last = folder.top();
                }
                if (!folder.empty()) {
                    last = folder.top();
                    currentLen += last.first;
                }
                
                currentLen += 1;
                if (i == n-1) {
                    currentLen += 1;
                }
                if (isFile) {
                    result = result < currentLen ? currentLen : result;
                    isFile = false;
                }
                
                folder.push(make_pair(currentLen, currentLevel));
                currentLevel = 0;
                currentLen = 0;
//                i += 1;
                continue;
            }
            if (input[i] == '.') {
                isFile = true;
            }
            if (input[i] == ' ') {
                continue;
            }
            currentLen ++;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    string input = //"dir\n file.txt";
    //"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    //"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    "sladjf\n\tlkjlkv\n\t\tlkjlakjlert\n\t\t\tlaskjglaksjf\n\t\t\t\tlakjgfljrtlj\n\t\t\t\t\tlskajflakjsvlj\n\t\t\t\t\t\tlskgjflkjrtlrjt\n\t\t\t\t\t\t\tlkjglkjlvkjdlvkj\n\t\t\t\t\t\t\t\tlfjkglkjfljdlv\n\t\t\t\t\t\t\t\t\tlkdfjglerjtkrjkljsd.lkvjlkajlfk\n\t\t\t\t\t\t\tlskfjlksjljslvjxjlvkzjljajoiwjejlskjslfj.slkjflskjldfkjoietruioskljfkljf\n\t\t\t\t\tlkasjfljsaljlxkcjzljvl.asljlksaj\n\t\t\t\tasldjflksajf\n\t\t\t\talskjflkasjlvkja\n\t\t\t\twioeuoiwutrljsgfjlskfg\n\t\t\t\taslkjvlksjvlkjsflgj\n\t\t\t\t\tlkvnlksfgk.salfkjaslfjskljfv\n\t\t\tlksdjflsajlkfj\n\t\t\tlasjflaskjlk\n\t\tlsakjflkasjfkljas\n\t\tlskjvljvlkjlsjfkgljfg\n\tsaljkglksajvlkjvkljlkjvksdj\n\tlsakjglksajkvjlkjdklvj\n\tlskjflksjglkdjbkljdbkjslkj\n\t\tlkjglkfjkljsdflj\n\t\t\tlskjfglkjdfgkljsdflj\n\t\t\t\tlkfjglksdjlkjbsdlkjbk\n\t\t\t\t\tlkfgjlejrtljkljsdflgjl\n\t\t\t\t\tsalgkfjlksfjgkljsgfjl\n\t\t\t\t\tsalkflajwoieu\n\t\t\t\t\t\tlaskjfglsjfgljkkvjsdlkjbklds\n\t\t\t\t\t\t\tlasjglriotuojgkjsldfgjsklfgjl\n\t\t\t\t\t\t\t\tlkajglkjskljsdljblkdfjblfjlbjs\n\t\t\t\t\t\t\t\t\tlkajgljroituksfglkjslkjgoi\n\t\t\t\t\t\t\t\t\t\tlkjglkjkljkljdkbljsdfljgklfdj\n\t\t\t\t\t\t\t\t\t\t\tlkjlgkjljgslkdkldjblkj\n\t\t\t\t\t\t\t\t\t\t\t\tlkjfglkjlkjbsdklj.slgfjalksjglkfjglf\n\t\t\t\t\t\t\t\t\t\t\t\tlkasjrlkjwlrjljsl\n\t\t\t\t\t\t\t\t\t\t\t\t\tlksjgflkjfklgjljbljls\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjsglkjlkjfkljdklbjkldf\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjglkjdlsfjdglsdjgjlxljjlrjsgjsjlk\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjsgkllksjfgjljdslfkjlkasjdflkjxcljvlkjsgkljsfg\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlaskjlkjsakljglsdjfgksdjlkgjdlskjb\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkajsgfljfklgjlkdjgfklsdjklj\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjfglkjlkgjlkjl.aslkjflasjlajglkjaf\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjasflgjlskjglkfjgklgsdjflkbjsdklfjskldfjgklsfdjgklfdjgl\n\tlskadjlkjsldwwwwwfj\n\t\tlkjflkasjlfjlkjajslfkjlasjkdlfjlaskjalvwwwwwwwwwwwwwwwkjlsjfglkjalsjgflkjaljlkdsjslbjsljksldjlsjdlkjljvblkjlkajfljgasljfkajgfljfjgldjblkjsdljgsldjg.skljf";
    std::cout << lengthLongestPath(input) << "\n";
    return 0;
}



/*
###算法
使用 stack 来存 (curr_len, level), curr_len include the first folder until current， 当发现一个新folder 或者 file与 栈顶的同一级别或者更高级别，就把栈顶弹出，把更新后的 curr_len 和它对于level一起加入栈， 只有当前是file的时候，才把 curr_len 更新到max_len
 
 注意网站上提交代码的时候要用//的方法判断'\n'和'\t'


###时空复杂度
Time Complexity: O(n)
Space Complexity: O(n)

###代码实现
***有什么要注意的地方
参考代码注释
***有什么要优化的地方
*/
