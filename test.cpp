#include<iostream>
#include <cstdlib>
#include <string>
#include<vector>
#include <stack>
#include<algorithm>
#include <chrono>
#include <utility>
#include <map>
using namespace std;
using namespace std::chrono;
string removeKdigits(string num, int k) {
    vector<string>poss;
    int min = INT_MAX;
    if (num.length() == k)return "0";
    else {
        string copy = "";
        for (int i = 0; i < num.length() - 2; i++) {
            copy = num;
            copy.erase(i, k);
            if (stoi(copy) < min)
                min = stoi(copy);
            //poss.push_back(num);
        }

    }
    return to_string(min);
}
long long reverse(long long  x) {
    string xs = to_string(x);
    string output = "";
    if (xs[0]=='-') {
        output += '-';
        for (int i = xs.length()-1; i >= 1; i--) {
            output = output + xs[i];
        }

    }
    else {

        for (int i = xs.length() - 1; i >= 0; i--) {
            output = output + xs[i];
        }

    }
    return stoll(output);

}
string removeDuplicates(string str) {
    string oou = "";
    for (int i = 0; i < str.length();i++) {
        size_t found=(oou.find(str[i]));
        //if ((oou.find(str[i]))<0|| (oou.find(str[i]))>str.length()) {
        if(found == string::npos){
            oou += str[i];
        }
    }

    return oou;
}
vector <int> CharWithFreq(string str) {
    int freq[26];
    vector <int> output;
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < str.length(); i++)
        freq[str[i] - 'a']++;
    for (int i = 0; i < str.length(); i++) {

        // if frequency of character str[i] is not
        // equal to 0
        if (freq[str[i] - 'a'] != 0) {
            output.push_back(freq[str[i] - 'a']);
            freq[str[i] - 'a'] = 0;
        }
    }
    return output;
}
vector<int >CharWithFreqV1(string str) {
    vector<int >freq(26,0);
    for (int i = 0; i < str.length(); i++)
        freq[str[i] - 'a']++;
    
    return freq;
}
int minDeletions(string s) {
    vector <int>freq = CharWithFreq(s);
    int deletion = 0;
    for (int i = 0; i < freq.size(); i++) {
        for (int j = i + 1; j < freq.size(); j++) {
            if (freq[i] == freq[j]) {
                deletion++;
                freq[j]--;
            }
        }
    }
    return deletion;
}
bool CheckAnagram(string s1,string s2) {
    vector <int> freqS1 = CharWithFreqV1(s1);
    vector <int> freqS2 = CharWithFreqV1(s2);
    for (int i = 0; i < freqS1.size(); i++) {
        if (freqS1[i] != freqS2[i]) {
            return false;
        }
    }
    return true;
}
void sortString(string &s) {
    sort(s.begin(), s.end());
}
pair <int, int> RangeOfTarget(vector<int> arr,int target) {
    int flag = 0;
    pair <int, int>range;
    for (int i = 0; i < arr.size(); i++) {
        if ((arr[i] == target) ) {
            if (flag == 0) {
                range.first = i;
                flag = 1;
            }
            if (arr[i + 1] != target)
                range.second = i;
        }
        
    }
    if (range.first == 0 && range.second == 0) { range.first = -1; range.second = -1; }
    return range;
}

void minimumBribes(vector<int> q) {
    vector<int>no_swaps( q.size(),0);
    vector<int>::iterator it;
    int index = 0;
    int temp = 0;
    int first_elemnt = 0, second_element = 0;
    for (int i = 0; i < q.size(); i++) {
        if (q[i] != (i + 1)) {
            //need swaping
            temp = q[i];
            first_elemnt = i;
            second_element = q[i] - 1;
            //index = find(q.begin(), q.end(), (q[i])) - q.begin();
            q[first_elemnt] = q[second_element];
            q[second_element] = temp;
            no_swaps[q[first_elemnt]-1]++;
            no_swaps[q[second_element]-1]++;
        }
    }
    int sum = 0;
    int flag = 0;
    for (int it = 0; it < no_swaps.size(); it++) {
        if (no_swaps[it] > 2) {
            flag = 1;
            cout << "Too chaotic";
            break;
        }
        else
            sum = sum + no_swaps[it];
    }
    if (flag != 1)
        cout << sum / 2;
}
int findDigits(int n) {
    string a = "";
    string number_digit = to_string(n);
    int sum = 0;
    for (int i = 0; i < number_digit.length();i++) {
        a = number_digit[i];
        if (stoi(a)!=0 && (n % stoi(a) == 0))sum++;
    }
    return sum;
}


int solution(string& S, vector<int>& C) {
    // write your code in C++14 (g++ 6.2.0)
    int cost = 0;
   /* vector<int>::iterator it;
    it = C.begin();*/
    for (int i = 0; i < S.length()-1;i++) {
        if (S[i] == S[i + 1]) {
            if (C[i]<C[i+1]) {
                S.erase(i,1);
                //S[i] = '-';
                cost += C[i];
                C.erase((C.begin() +i));
                i = i - 1;
            }
            else {
                S.erase(i+1, 1);
                cost += C[i+1];
                C.erase(C.begin() + i + 1);
                i = i - 1;
            }
        }
        
    
    }
    return cost;
}
int solutionWithDiscard(string& S, vector<int>& C) {
    // write your code in C++14 (g++ 6.2.0)
    int cost = 0;
    /* vector<int>::iterator it;
     it = C.begin();*/
    for (int i = 0; i < S.length() - 1; i++) {
        if (S[i] == '-') {
            if ( S[i] == S[i + 1]) {
                if (C[i] < C[i + 1]) {
                    //S.erase(i, 1);
                    S[i] = '-';
                    cost += C[i];
                    //C.erase((C.begin() + i));
                    C[i] = -1;
                    i = i - 1;
                }
                else {
                    S[i + 1] = '-';

                    //S.erase(i + 1, 1);
                    cost += C[i + 1];
                    C[i + 1] = -1;
                    //C.erase(C.begin() + i + 1);
                    i = i - 1;
                }
            }
        }
        else if (S[i+1]=='-') {
            if (S[i] == S[i + 1]) {
                if (C[i] < C[i + 1]) {
                    //S.erase(i, 1);
                    S[i] = '-';
                    cost += C[i];
                    //C.erase((C.begin() + i));
                    C[i] = -1;
                    i = i - 1;
                }
                else {
                    S[i + 1] = '-';

                    //S.erase(i + 1, 1);
                    cost += C[i + 1];
                    C[i + 1] = -1;
                    //C.erase(C.begin() + i + 1);
                    i = i - 1;
                }
            }
        }
        else {
            if (S[i] == S[i + 1]) {
                if (C[i] < C[i + 1]) {
                    //S.erase(i, 1);
                    S[i] = '-';
                    cost += C[i];
                    //C.erase((C.begin() + i));
                    C[i] = -1;
                    i = i - 1;
                }
                else {
                    S[i + 1] = '-';

                    //S.erase(i + 1, 1);
                    cost += C[i + 1];
                    C[i + 1] = -1;
                    //C.erase(C.begin() + i + 1);
                    i = i - 1;
                }
            }
        }

    }
    return cost;
}
int solve(string s, vector<int>& nums) {
    stack<int> st;
    int cost = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (st.size() && s[st.top()] == s[i]) {
            if (nums[st.top()] > nums[i]) {
                cost += nums[i];
            }
            else {
                cost += nums[st.top()];
                st.pop();
                st.push(i);
            }
        }
        else {
            st.push(i);
        }
    }
    return cost;
}
//int solution(string& S, vector<int>& C) {
//    // write your code in C++14 (g++ 6.2.0)
//    int cost = 0;
//    vector<int>::iterator it;
//    it = C.begin();
//    string copy = "";  
//    vector <int>costs;
//    for (int i = 0; i < S.length() - 1; i++) {
//        if (S[i] == copy[copy.length()-1]) {
//            if (C[i] < C[i + 1]) {
//                cost += C[i];
//                i = i - 1;
//            }
//            else {
//                S.erase(i + 1, 1);
//                cost += C[i + 1];
//                C.erase(it + i + 1);
//                i = i - 1;
//            }
//        }
//        else {
//            copy += S[i];
//            costs.push_back(C[i]);
//        }
//
//    }
//    return cost;
//}
//int solution(string& S, vector<int>& C) {
//    int cost = 0;
//    for (int i = 0; i < S.length() - 1;i++) {
//        if (S[i] == S[i + 1])
//            if (C[i] < C[i + 1])
//                cost += C[i];
//            else
//                cost += C[i + 1];
//        
//    }
//    return cost;
//}
int solutionSum(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum = 0;
    int noRealocation = 0;
   /* vector<int>::iterator it;
    it = A.begin();*/
    for (int i = 0; i < A.size(); i++) {
        if (sum + A[i] < 0) {
            //search for largest negative number that i already sum it

            if (i > 0) {
                for (int x = i - 1; x >= 0; x--) {
                    if (A[i] > A[x]) {
                        int index_from_last = A.size() - 1;
                        sum += ( - 1 * A[x]);
                        while (A[x] < A[index_from_last]) {

                        }
                        A.push_back(A[x]);
                        A.erase(A.begin() + x);
                        /* int temp = A[i];
                         A[i] = A[A.size()-noSwaps-1];
                         A[A.size() - noSwaps - 1] = temp;*/
                        i = i - 2;
                        noRealocation++;
                        break;
                    }
                    else {
                        A.push_back(A[i]);
                        A.erase(A.begin() + i);
                        /* int temp = A[i];
                         A[i] = A[A.size()-noSwaps-1];
                         A[A.size() - noSwaps - 1] = temp;*/
                        i = i - 2;
                        noRealocation++;
                        break;
                    }
                }
               
            }
            else {
                if (A[i] < 0)
                {
                    A.push_back(A[i]);
                    A.erase(A.begin() + i);
                    /* int temp = A[i];
                     A[i] = A[A.size()-noSwaps-1];
                     A[A.size() - noSwaps - 1] = temp;*/
                    i = i - 1;
                    noRealocation++;
                }
            }
            
        }
    
   
        
        //else {
        //        A.push_back(A[i]);
        //        A.erase(A.begin() + i);
        //        /* int temp = A[i];
        //         A[i] = A[A.size()-noSwaps-1];
        //         A[A.size() - noSwaps - 1] = temp;*/
        //        i = i - 1;
        //        noRealocation++;

        //}
      /*  }*/
        
        else {
            sum = sum + A[i];
        }
    }
    return noRealocation;
}
int solutionSumV(vector<int>& A) {
    // write your code in C++14 (g++ 6.2.0)
    int sum = 0;
    int noRealocation = 0;
    /* vector<int>::iterator it;
     it = A.begin();*/
    int index_of_largest_negative = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < index_of_largest_negative)index_of_largest_negative = i;
        if (sum + A[i] < 0) {
            //search for largest negative number that i already sum it

            if (i > 0) {
                for (int x = i - 1; x >= 0; x--) {
                    if (A[i] > A[x]) {
                        sum += (-1 * A[x]);

                       /* A.push_back(A[x]);
                        A.erase(A.begin() + x);*/
                         int temp = A[x];
                         A[x] = A[A.size()-1];
                         A[A.size()- 1] = temp;
                        i = i - 2;
                        noRealocation++;
                        break;
                    }
                    else {
                        A.push_back(A[i]);
                        A.erase(A.begin() + i);
                        /* int temp = A[i];
                         A[i] = A[A.size()-noSwaps-1];
                         A[A.size() - noSwaps - 1] = temp;*/
                        i = i - 2;
                        noRealocation++;
                        break;
                    }
                }

            }
            else {
                if (A[i] < 0)
                {
                    A.push_back(A[i]);
                    A.erase(A.begin() + i);
                    /* int temp = A[i];
                     A[i] = A[A.size()-noSwaps-1];
                     A[A.size() - noSwaps - 1] = temp;*/
                    i = i - 1;
                    noRealocation++;
                }
            }

        }



        //else {
        //        A.push_back(A[i]);
        //        A.erase(A.begin() + i);
        //        /* int temp = A[i];
        //         A[i] = A[A.size()-noSwaps-1];
        //         A[A.size() - noSwaps - 1] = temp;*/
        //        i = i - 1;
        //        noRealocation++;

        //}
      /*  }*/

        else {
            sum = sum + A[i];
        }
    }
    return noRealocation;
}
int delCost(string s, vector<int>& cost)
{

    // Store the minimum cost required
    int ans = 0;

    // Create a dictionary to store the
    // maximum cost of removal a character
    map<char, int> forMax;

    // Create a dictionary to store the total
    // deletion cost of a character
    map<char, int> forTot;

    // Traverse the string, S
    for (int i = 0; i < s.length(); i++) {

        // Keep track of maximum cost of each character
        if (!forMax[s[i]]) {
            forMax[s[i]] = cost[i];
        }
        else {

            // Update the maximum deletion cost
            forMax[s[i]] = max(cost[i], forMax[s[i]]);
        }

        // Keep track of the total cost of each character
        if (!forTot[s[i]]) {
            forTot[s[i]] = cost[i];
        }
        else {

            // Update the total deletion cost
            forTot[s[i]] = forTot[s[i]] + cost[i];
        }
    }

    // Traverse through all the unique characters
    for (auto i : forMax) {

        // Keep the maximum cost character and
        // delete the rest
        ans += forTot[i.first] - i.second;
    }

    // Return the answer
    return ans;
}

void Test1() {
    auto start = high_resolution_clock::now();
    string S = "ababa";
    vector <int> C = { 10,5,10,5,10};
  cout<< solution(S, C);
  auto stop = high_resolution_clock::now();

  // Get duration. Substart timepoints to
  // get duration. To cast it to proper unit
  // use duration cast method
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by function: "
      << duration.count() << " microseconds" << endl;
}

void Test2() {
    auto start = high_resolution_clock::now();
     vector<int> A= { -1,-1,-1,1,1,1,1 };
    cout << solutionSum(A);
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
        << duration.count() << " microseconds" << endl;

}

int main() {
    //vector<int>a = {10,-10,-1,-1,10};
    //vector<int>a = { -1,-1,-1,1,1,1,1 };
    //cout<<findDigits(1012);
    //cout << solution(a);
   /* vector <int>q = { 1,2,5,3,7,8,6,4};
    minimumBribes(q);*/
   // cout << removeKdigits("10", 1);
   /* vector<int> A= { -1,-1,-1,1,1,1,1 };
    cout << solution(A);*/
   /* vector<int> in = { 2,4,7,9,9 };
    pair <int, int> out=RangeOfTarget(in,5);
    cout << out.first << "   " << out.second;*/
   
    Test1();
    Test2();

   // string s1 = "nameless";
   // string s2 = "salesman";
   // sortString(s1);  sortString(s2);
   //// cout <<  CheckAnagram(s1, s2);
   // if (s1==s2)
   //     cout << "Done";
   // else cout << "not";
   // cout << removeDuplicates("geeksforgeeks");
    //cout << minDeletions("bbcebab");
   // long long  x = reverse(1534236469);
    //cout << x;
}
