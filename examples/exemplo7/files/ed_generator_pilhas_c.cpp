#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int MIN_N = 0;
const int MAX_N = 2147483647;


const int number_of_rnd_tests = 0;

template <typename T> void append(vector<T> &dest, const vector<T> &orig) {
    dest.insert(dest.end(), orig.begin(), orig.end());
}

// Generate sample tests
vector<string> generate_sample_tests(void) {
    vector<string> tests = {"(**)\n", "(*(**)*)*\n", "())\n", "(****)*((*))\n", "*(**)\n", "********************(*)\n", "(*(*(*(**))))\n", "*******(***********)****()()*()\n", "(*)()\n", "***())**(*)\n", "*()()()()()()()()()()()()(**********)(*******************)***()(***)((****)*)\n", "(((((***))))*)\n", "(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)(*)\n", "(((((((****************))))))**((((((*******************))))))**((((((*****************))))))*((((((****************))))))*((((((*********************))))))******()*((((((*********************)))))))\n", "*******************************************************************((((((((((((((((*************))))))))))))))))\n",
"((((((((((((((((*************))))))))))))))))((((((((((((((((*************))))))))))))))))********************************************************************\n", "(*)(*)(*()(())*)()(*())***))**()()(**())*)_)(*())(**())(**)(*())(()(*())(**()(**()))***))(*)(*)(*()(())*)()(*())***))**()()(**())*)_)(*())(**())(**)(*())(()(*())(**()(**()))***))(*)(*)(*()(())*)()*()\n", "(**)*(*(*(*()))))\n", "((((((((((((((((((((((((((((((((((((((((((\n", ")))))))))))))))))))))))))))))))))))))))*\n", "*(*(*(*(*(**)*)*)*)*)\n", ")*)*)*)*()()()(*)))***)()***)(*******)****\n","(*)*****************(*)))))(((((\n","(*****)**(*****))*)(*)\n","***((****))***()()())**(***)\n"};
    return tests;
}



int main(int argc, char *argv[]) {
    
    registerGen(argc, argv, 1);
    vector<string> tests;
    size_t test = 0;
    append(tests, generate_sample_tests());
    //append(tests, generate_random_tests());
    //append(tests, generate_max_test());
    //append(tests, generate_min_test());

    for (const auto &t : tests) {
        startTest(++test);
        cout << t;
    }
    
    return 0;
}
