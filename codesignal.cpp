//
//  codesignal.cpp
//  
//
//  Created by Alice on 9/25/20.
//

#include <stdio.h>

// zigzag array
// can make triangle.
// 一个string 找相邻三个字符都是不一样的个数
vector<int> zigzag(vector<int>& A){
    int n = A.size();
    vector<bool> ret;
    
    for (int i = 2; i < n; i++){
        int a = A[i - 2];
        int b = A[i - 1];
        int c = A[i];
        bool zigzag_ = ((b > a && b < c) || (b < a && b > c));
        ret.push_back(zigzag_);
    }
    return ret;
}

// k-occurrence
vector<int> solution(vector<string>& words, string sequence){
    vector<int> res;
    for (int i = 0; i < words.size(); i++){
        int num = 0;
        string word = words[i];
        while (sequence.find(word) != string::npos){
            word += words[i];
            num++;
        }
        cout << num << endl;
        res.push_back(num);
    }
    return res;
}

// broken keyboard
// u r given an array letters representing the working letter keys, as well as a string
// text, and ur task is to determine how many of the words from text can be typed using the
// broken keyboard. All of the non-letter keys are working.
// A word is defined as a sequence of consecutive chars which does not contain spaces.
bool type(string& text, unordered_set<char>& dict){
    for (int i = 0; i < text.size(); i++){
        if (isalpha(text[i]) == false) continue;
        if (dict.find(tolower(text[i])) == dict.end()) return false;
    }
    return true;
}
int brokenKeyboard(string text, vector<char>& letters){
    unordered_set<char> dict (letters.begin(), letters.end());
    string delimiter = " ";
    int count = 0;
    int start = 0;
    size_t pos = 0;
    string token;
    while ((pos = text.find(delimiter, start)) != string::npos) {
        token = text.substr(start, pos - start + 1);
        cout << token << endl;
        if (type(token, dict) == true) count++;
        start = pos + 1;
        while (text[start] == ' ') start++;
    }
    token = text.substr(start);
    cout << token << endl;
    if (type(token, dict) == true) return count + 1;
    return count;
}

// isSubmatrixfull
// 给一个3*n的矩阵，里面是数字1-9，现在一个3*3的sliding window从左到右，要求找出有多少个sliding window里面包含全部1-9九个数字：sliding window标准思路
vector<bool> isSubmatrixfull(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    //cout << row << " " << col << endl;
    vector<bool> res;
    vector<int> num (9, 0);
    int count = 0;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < 3; j++){
            if (num[matrix[i][j] - 1]++ == 0){
                count++;
            }
        }
    }
    //cout << count;
    res.push_back(count == 9);
    cout << res.back() << endl;
    for (int j = 3; j < col; j++){
        for (int i = 0; i < row; i++){
            if (num[matrix[i][j] - 1]++ == 0) count++;
            if (--num[matrix[i][j-3] - 1] == 0) count--;
        }
        res.push_back(count == 9);
        //cout << res.back() << endl;
    }
    return res;
}

// reverse pairs
int reverseDigitsInPairs(int n){
    string w = to_string(n);
    for (int i = 1; i < w.size(); i += 2){
        swap(w[i], w[i - 1]);
    }
    return stoi(w);
}

//给一个数“456”，看里面有多少个可以被3整除，比如“4”，“5，”，“6”，“45”， “56”，“456”
//int solution(String num){
//    if(num == null || num.length() == 0) return 0;
//    int res = 0;
//    Set<Integer> set = new HashSet<>();
//    for(int i=0; i<num.length(); i++){
//        for(int j=i+1; j<=num.length(); j++){
//            String val = num.substring(i, j);
//            int temp = Integer.parseInt(val);
//            if(!set.contains(temp) && temp%3==0){
//                res++;
//            }
//            set.add(temp);
//        }
//    }
//    return res;
//}
int helper(string number, int len, int k){
    int count = 0;
    for (int i = 0; i < len; i++){
        int num = 0;
        for (int j = i; j < len; j++){
            if (number[i] == '0' && i != j) continue;
            num = num * 10 + (number[j] '0');
            if (n % k == 0) count++;
        }
    }
    return count;
}
int threeDivSubsequences(string number){
    return helper(number, number.length(), 3);
}

// justify newspaper
string repeat(string str, int count){
    string ret = "";
    for(int i = 0; i < count; i++){
        ret += str;
    }
    return ret;
}
string buildLine(string& s, string& pos, int width) {
    int spaces = width - sb.length();
    String ret = "*";
    if (pos == "LEFT") {
        ret += (s + repeat(" ", spaces) + "*");
    }
    else if (pos == "RIGHT") {
        ret += (repeat(" ", spaces) + s + "*");
    }
    return ret;
}
vector<string> justifyNewspaperText(vector<vector<string>>& lines, vector<string>& aligns, int width) {
    string border = repeat("*", width + 2);
    vector<string> output;
    output.push_back(border);
    
    for (int i = 0; i < lines.size(); i++) {
        string cur = "";
        for (int j = 0; j < lines[i].size(); j++) {
            string word = lines[i][j];
            if (cur.length() + word.length() + 1 <= width) {
                cur += (" " + word);
            }
            else {
                output.push_back(buildLine(cur, aligns[i], width));
                cur = word;
            }
        }
    }
    output.push_back(bar);
    return output;
}

//min diff of arrays
//现在可以使用数组a中的一个值替换数组a中的另一个值（是直接替换而不是swap），最多替换一次，也可以不替换，使得两个数组绝对值的差(|a[0]-b[0]| + |a[1]-b[1]| + |a[2]-b[2]|+.....)最小，并求出最小的diff：第一遍brute force，n2的复杂度，只过了前十个case，后来改成先sort a数组，每次遍历的时候在a里面binary search一个最接近b的数，复杂度降到nlogn，就过了所有的case了
int getClosest(int val1, int val2, int target){
    if (target - val1 >= val2 - target) return val2;
    return val1;
}

int findClosest(vector<int>& arr, int target){
    int n = arr.size();
    // Corner cases
    if (target <= arr[0]) return arr[0];
    if (target >= arr.back()) return arr.back();
  
    // Doing binary search
    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = i + (j - i) / 2;
  
        if (arr[mid] == target) return arr[mid];

        if (target < arr[mid]) {
            // If target is greater than previous
            // to mid, return closest of two
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1], arr[mid], target);
            j = mid;
        }
  
        // If target is greater than mid
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid], arr[mid + 1], target);
            // update i
            i = mid + 1;
        }
    }
    return arr[mid];
}

// process queries to deactivate active cells and calculate minimal cells.
int[] solution(int[][] queries, int m, int n){
    int[] memo = new int[2];
    int minval = Integer.MAX_VALUE;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if((i+1)*(j+1)<minval){
                memo[0] = i;
                memo[1] = j;
                minval = (i+1)*(j+1);
            }
        }
    }
    Set<Integer> row = new HashSet<>();
    Set<Integer> col = new HashSet<>();
    List<Integer> res = new ArrayList<>();
    for(int[] query: queries){
        if(query.length==1){
            if(!row.contains(memo[0]) && !col.contains(memo[1])){
                res.add(minval);
            }else{
                minval = Integer.MAX_VALUE;
                for(int i=0; i<m; i++){
                    if(row.contains(i)) continue;
                    for(int j=0; j<n; j++){
                        if(col.contains(j)) continue;
                        if((i+1)*(j+1)<minval){
                            memo[0] = i;
                            memo[1] = j;
                            minval = (i+1)*(j+1);
                        }
                    }
                }
                res.add(minval);
            }
        }else{
            if(query[0] == 1){
                row.add(query[1]-1);
            }else if(query[0] == 2){
                col.add(query[1]-1);
            }
        }
    }
    int[] result = new int[res.size()];
    for(int i=0; i<res.size(); i++){
        result[i] = res.get(i);
    }
    return result;
}
//给int n, m，想象n*m的矩阵M, M[i,j] = (i+1)*(j+1)，0-based ​​​​​​​​​​​​​​​​​​​一系列query，有三种类型，第一种是查询矩阵中最小的元素，第二、三分别是禁用某一行、列。 一个2D array的min number的query
//题目是说给你一个2d array。其中array​[j] = (i+1)*(j+1)。这个给定。 然后给一堆query，有三种不同的格式:
//第一种是让你返回当前array中的最小值
//第二种是让你把某一行disable
//第三种是把某一列disab​​​​​​​​​​​​​​​​​​​le
//当然disable了之后最小值就不能用了

public class matrixSearch {
    private int m;
    private int n;
    private List<Integer> col;
    private List<Integer> row;
    public matrixSearch(int m, int n){
        this.m = m;
        this.n = n;
        col = new ArrayList<>();
        row = new ArrayList<>();
    }

    public int querymin(){
        int min = Integer.MAX_VALUE;
        for(int i=0; i<m; i++){
            if(row.contains(i)) continue;
            for(int j=0; j<n; j++){
                if(col.contains(j)) continue;
                if((i+1)*(j+1)<min){
                    min = (i+1)*(j+1);
                }
            }
        }
        return min;
    }

    public void ban_col(int val){
        if(val<n && val>=0) {
            col.add(val);
        }
    }

    public void ban_row(int val){
        if(val>=0 && val<m) {
            row.add(val);
        }
    }

    public static void main(String[] args){
        matrixSearch ms = new matrixSearch(2,3);
        System.out.print(ms.querymin());
        ms.ban_col(0);
        System.out.print(ms.querymin());
        ms.ban_col(1);
        System.out.print(ms.querymin());
    }
}

// 找最长的 prefix 同时 prefix也是Palindrome， 然后去掉 直到找不到长度大于等于2的这样的prefix
bool isPalindrome(string& p, int len){
    for (int i = 0, j = len - 1; i < j; i++, j--){
        if (p[i] != p[j]) return false;
    }
    return true;
}

string c(string s){
    while (!s.empty()){
        int len = s.length();
        while (len > 1){
            if (isPalindrome(s, len) == true){
                break;
            }
            len--;
        }
        if (len > 1){
            s = s.substr(len);
        }
        else{
            return s;
        }
    }
    return s;
}

// textEditor
// INSERT <text>, DELETE: erase the last character of the current text
// COPY <index>: copy the substr of the current text starting from index.
// PASTE: add the last copied text to the end of current text
// UNDO: undo the last successful INSERT, DELETE or PASTE.
string textEditor(vector<string>& operations){
    string text = "";
    string clipBoard = "";
    stack<string> prev;
    
    for (auto& op: operations){
        char first = op[0];
        int idx = -1;
        size_t pos = op.find(" ");
        switch(first){
            case 'I':
                prev.push(text);
                text += op.substr(pos + 1);
                break;
                
            case 'C':
                idx = stoi(op.substr(pos + 1));
                if (idx >= text.length() || idx < 0){
                    clipBoard = "";
                }
                else clipBoard = text.substr(idx);
                break;
                
            case 'D':
                if (text.empty()) break;
                prev.push(text);
                text.pop_back();
                break;
                
            case 'U':
                text = prev.top();
                prev.pop();
                break;
                
            case 'P':
                if (clipBoard.empty()) break;
                prev.push(text);
                text += clipBoard;
                break;
        }
        //cout << text << endl;
    }
    return text;
}

//給兩個字串 a, b: 求從字串b刪掉一個數字以後 a字串小於b的可能有幾種 (alphanumeric sort)
//例如: a="d1c" b = "1b2z"
//則可能有b = "b2z", 及 b = "1bz", 兩種情況做比較
int solution(string a, string b){
    if (a.length() == 0 || b.length() == 0) return 0;
    int res = 0;
    for (int i = 0; i < b.length(); i++){
        if (b[i] < '0' || b[i] > '9') continue;
        string b_;
        if (i == 0){
            b_ = b.substr(1);
        }
        else if (i == b.length() - 1){
            b_ = b.substr(0, b.length()-1);
        }
        else{
            b_ = (b.substr(0, i) + b.substr(i + 1));
        }
        if(a < b_) res++;
    }
    return res;
}

// 把一个int array 分成三个连续的subarray 要求第一个的sum小于等于第二个 第二个小于等于第三个

// border sort
void solution(vector<vector<int>>& matrix){
    int row = matrix.size();
    if (row == 0) return;
    int col = matrix[0].size();
    int rowstart = 0, rowend = row - 1;
    int colstart = 0, colend = col - 1;
    
    while (rowstart <= rowend && colstart <= colend){
        priority_queue<int> pq;
        for (int i = colstart; i <= colend; i++){
            pq.push(matrix[rowstart][i]);
        }
        rowstart++;
        for (int i = rowstart; i <= rowend; i++){
            pq.push(matrix[i][colend]);
        }
        colend--;
        if (rowstart <= rowend){
            for (int i = colend; i >= colstart; i--){
                pq.push(matrix[rowend][i]);
            }
            rowend--;
        }
        if (colstart <= colend){
            for (int i = rowend; i >= rowstart; i--){
                pq.push(matrix[i][colstart]);
            }
            colstart++;
        }
        matrix_.push_back(pq);
    }
    int idx = 0;
    rowstart = 0;
    rowend = row - 1;
    colstart = 0;
    colend = col - 1;
    
    while (rowstart <= rowend && colstart <= colend){
        auto pq = ;
        for (int i = colstart; i <= colend; i++){
            matrix[rowstart][i] = pq.front();
            pq.pop();
        }
        rowstart++;
        for (int i = rowstart; i <= rowend; i++){
            matrix[i][colend] = pq.front();
            pq.pop();
        }
        colend--;
        if (rowstart <= rowend) {
            for (int i = colend; i >= colstart; i--) {
                matrix[rowend][i]= pq.front();
                pq.pop();
            }
            rowend--;
        }

        if (colstart <= colend) {
            for (int i = rowend; i >= rowstart; i--){
                matrix[i][colstart] = pq.front();
                pq.pop();
            }
            colstart++;
        }
        idx++;
    }
}

//第四题是给出两种操作(0,a,b)和(1,a,b)，前者表示给你一个axb的矩形，后者是一次询问，询问你当前收到的所有矩形是否都能放进一个axb的盒子里，并不是问能否同时塞进盒子。而是只要矩形1能放进去，矩形2也能放进，就算OK。
//输入一个操作序列，返回询问的结果数组
public boolean[] solution(int[][] queries){
    int size1 = 0;
    int size0 = 0;
    for(int[] query: queries){
        if(query[0] == 1){
            size1++;
        }else if(query[0] == 0){
            size0++;
        }
    }
    boolean[] res = new boolean[size1];
    if(size1!=0 && size0 == 0){
        Arrays.fill(res, true);
        return res;
    }
    int i=0;
    int maxlength = 0;
    int maxwidth = 0;
    size1 = 0;
    size0 = 0;
    for(int[] query: queries){
        int length = Math.max(query[1], query[2]);
        int width = Math.min(query[1], query[2]);
        if(query[0]==0){
            maxlength = Math.max(maxlength, length);
            maxwidth = Math.max(maxwidth, width);
            size0++;
        }else{
            if(size1>=0 && size0 == 0){
                res[i] = true;
            }else if(length>maxlength || width>maxwidth){
                res[i] = false;
            }else if(length<=maxlength && width<=maxwidth){
                res[i] = true;
            }
            i++;
            size1++;
        }
    }
    return res;
}

//最开始有3个case超时，原因是每次执行问加起来等于target的情况有多少种的那个query时，我都是 重新算一遍记录b数组每个数出现次数的HashMap，其实只用最开始构好，然后每次做第二种 query([index, num])，更新一下HashMap就行。改了就过了。
//输入a，b两个array， 一个query array。query有两种type， 一种是[1, target]查从a中取一个数， b中取一个数，求加起来等于target的情况有多少种。第二种query是[0, index, num], 把b中在 in​​​​​​​​​​​​​​​​​​​dex位置的数字改成num，这种query不需要输出。最后输出所有第一种query的result。
//Give three array a, b and query. 看例子更好理解
//Input:
//a = [1, 2, 3]
//b = [3, 4]
//query = [[1, 5], [0, 1 , 1], [1, 5]]
//Output:
//[2, 1]

//Give three array ​a​, ​b​ and ​query​. This one is hard to explain. Just read the example.
//Input:
//a = [1, 2, 3]
//b = [3, 4]
//query = [[1, 5], [1, 1, 1], [1, 5]]
//Output:
//[2, 1]
//Explain:
//Just ignore every first element in sub-array in the query.
//So we will get a new query like this query = [[5], [1, 1], [5]]
//Only record the result when meet the single number in new query array.
//And the rule of record is find the sum of the single number.
//The example above is 5 = 1 + 4 and 5 = 2 + 3, there are two result.
//So currently the output is [2]
//When we meet the array length is larger than 1, such as [1, 1]. That means we will replace the b[x] = y, x is the first element, y is second element. So in this example, the b will be modify like this b = [1, 4]
//And finally, we meet the [5] again. So we will find sum again. This time the result is 5 = 1 + 4. So currently the output is [2, 1]
//note: Don't have to modify the query array, just ignore the first element.
//Time:
//Function findSum is O(a * b)
//Function modifyArrayb is O(1)
//Function treverse is O(query)
//So total maybe O(a * b * query)
//I think this problem must has some better solution, but I am almost run out of time.
//动态修改mapB
public class CoolFeature {
    public List<Integer> solution(int[] a, int[] b, int[][] query){
        if(a==null || b== null || query==null) return new ArrayList<>();
        Map<Integer, Integer> mapA = new HashMap<>();
        Map<Integer, Integer> mapB = new HashMap<>();
        for(int i=0; i<a.length; i++){
            mapA.put(a[i], mapA.getOrDefault(a[i], 0)+1);
        }

        for(int i=0; i<b.length; i++){
            mapB.put(b[i], mapB.getOrDefault(b[i], 0)+1);
        }
        List<Integer> res = new ArrayList<>();
        for(int[] arr: query){
            if(arr.length == 3){
                int oldval = b[arr[1]];
                mapB.put(oldval, mapB.get((oldval))-1);
                int newval = arr[2];
                mapB.put(newval, mapB.getOrDefault(newval, 0)+1);
            }
            else{
                int target = arr[1];
                int count = 0;
                for(int key : mapA.keySet()){
                    int val = target-key;
                    if(mapB.containsKey(val)){
                        count+=mapA.get(key)*mapB.get(val);
                    }
                }
                res.add(count);
            }
        }

        return res;
    }

    public static void main(String[] args){
        int[] a = new int[]{1,2,3};
        int[] b = new int[]{3,4};
        int[][] query = new int[][]{{1,5}, {1,1,1}, {1,5}};
        CoolFeature cf = new CoolFeature();
        System.out.print(cf.solution(a, b, query));

    }
}

// 第二题 数字以string表示，每一位相加，返回每一位相加所得数字拼起来的string。
// 第三题 矩阵每个对角线上的字母拼接起来，得到很多string，按字母序排序string后返回原有拼接string后下标的顺序

// 模拟alloc。 给你一个int[] 代表memory location，0=可用，1=被占用。 给你一串query，有两种query： alloc & remove. alloc 会告诉你要alloc多少size， 每次alloc成功你要track一下这次alloc的id是多少。如果能alloc就返回alloc的memory的第一位角标， 不然就返回-1。remove告诉你要remove的id，没有这个id就返回-1，可以remove就返回1. 最后返回这一串query的执行结果

//给a b两个数组，上限和下限，返回在上限和下限之间的 a[i]平方 + b[j]平方 的所有组合的数量。
int findLower(vector<int>& arr, int a_, int lower) {
    int left = 0, right = arr.size() - 1;
    int res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = a_ + arr[mid] * arr[mid];
        if (sum < lower) {
            left = mid + 1;
        }
        else{
            right = mid - 1;
            res = mid;
        }
        //cout << right << endl;
    }
    return res;
}
int findUpper(vector<int>& arr, int a_, int upper) {
    int left = 0, right = arr.size() - 1;
    int res = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = a_ + arr[mid] * arr[mid];
        if (sum > upper) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
            res = mid;
        }
    }
    return res;
}
int solution(vector<int>& a, vector<int>& b, int lower, int upper){
    if (lower > upper) return 0;
    int count = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (auto &num: a){
        int start = findLower(b, num * num, lower);
        if (start == -1) continue;
        int end = findUpper(b, num * num, upper);
        if (start > end) continue;
        count += (end - start + 1);
    }
    return count;
}

// boolean deque
// u r given n, an integer representing the length of a binary string a,
string booleanDeque(int n, vector<string>& operations){
    int firstIdx = 0;
    string a = string(n, '0');
    //cout << a.size() << endl;
    
    for (auto &op: operations){
        if (op[0] == 'L'){
            if (firstIdx == n) continue;
            a[firstIdx] = '1';
            while (firstIdx < n && a[firstIdx] == '1') firstIdx++;
        }
        else{
            int idx = stoi(op.substr(1));
            a[idx] = '0';
            firstIdx = min(firstIdx, idx);
        }
    }
    return a;
}

// 给一个string target和一个string[] 问array里的能不能通过swap变成target 返回boolean 必须用到array里的每一个string 我写的recursion dfs hidden test没过可能是因为没有判断是不是用了array里的每一个string

// matrix + query: 0, rotate 90 degree clockwise. 1, flip1. 2, flip2.
public class matrixManipulate {
    public void solution(int[][] matrix, int[] action){
        for(int i=0; i<action.length; i++){
            if(action[i] == 0){
                rotate(matrix);
            }else if(action[i]==1){
                flip1(matrix);
            }else if(action[i]==2){
                flip2(matrix);
            }
        }
    }
    private void rotate(int[][] matrix){
        int m = matrix.length;
        int n = matrix[0].length;
        for(int i=0; i<m; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix,i ,j, j, i);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix, i, j, i, n-1-j);
            }
        }
    }

    private void flip1(int[][] matrix){
        for(int i=0; i<matrix.length; i++){
            for(int j=i+1; j<matrix[0].length; j++){
                swap(matrix, i, j, j, i);
            }
        }
    }

    private void flip2(int[][] matrix){
        int n = matrix.length;
        int end = matrix[0].length-1;
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<=end; j++){
                swap(matrix, i, j, n-1-j, n-1-i);
            }
            end--;
        }
    }

    private void swap(int[][]matrix, int x, int y, int i, int j){
        int temp = matrix[x][y];
        matrix[x][y] = matrix[i][j];
        matrix[i][j] = temp;
    }

    public static void main(String[] args){
        int[][] matrix = new int[][]{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
        int[] action = new int[]{2,2,1,1,0,0,0,0};
        matrixManipulate mm = new matrixManipulate();
        mm.solution(matrix, action);
        for(int i=0; i<matrix.length; i++){
            for(int j=0; j<matrix[0].length; j++){
                System.out.print(matrix[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}

// black white matrix
void solution(vector<vector<int>>& matrix, vector<vector<int>>& queries){
    if (matrix.empty()) return;
    
    for (auto &query: queries){
        int starti = query[0];
        int startj = query[1];
        int m = query[2];
        priority_queue<int, vector<int>, greater<int>> black;
        priority_queue<int, vector<int>, greater<int>> white;
        for (int i = starti; i < starti + m; i++){
            for (int j = startj; j < startj + m; j++){
                if((i+j)%2==0){
                    black.offer(matrix[i][j]);
                }
                if((i+j)%2==1){
                    white.offer(matrix[i][j]);
                }
            }
        }

        for(int i=starti; i<starti+m; i++){
            for(int j=startj; j<startj+m; j++){
                if((i+j)%2==0){
                    matrix[i][j] = black.poll();
                }
                if((i+j)%2==1){
                    matrix[i][j] = white.poll();
                }
            }
        }
    }
}

// threeDivSubsequences
// 给两个String n和k。n是一个integer的string representation，问你n里面有多少个substring of length k that is divisible by n。比如n = 120， k = 2。n有两个长度为2的substring number 12和20，都可以整除120所以返回2。这里注意如果给你的数字是1005，k = 2，他只有俩substring number，10和5（0不能作为除数，leading zero去掉）
int solution(int n, int k){
    if (n == 0 || k == 0) return 0;
    int count = 0;
    string n_ = to_string(n);
    unordered_set<int> divisors;
    for (int i = 0; i <= n_.length() - k; i++){
        int divisor = stoi(n_.substr(i, k));
        if (divisor == 0 || divisors.find(divisor) != divisors.end()) continue;
        divisors.insert(divisor);
        if (n % divisor == 0) count++;
    }
    return count;
}

// digit anagram
string sort_(string s) {
    vector<int> counter (10, 0);
    for (char &c: s) {
        counter[c - '0']++;
    }
    string t;
    for (int c = 0; c < 10; c++) {
        t += string(counter[c], c + '0');
    }
    return t;
}
int groupAnagrams(vector<int>& a) {
    int count = 0;
    unordered_map<string, int> m;
    for (auto &num: a) {
        m[sort_(to_string(num))]++;
    }
    for (auto &p: m) {
        int n = p.second;
        int pairs = n * (n - 1) / 2;
        count += pairs;
    }
    return count;
}
//第四题: given an array of integers arr, count the number of contiguous subarrays that represent a sawtooth sequence (alternate between increasing and decreasing) of at least 2 elements

/*
已知一个4*4n的矩阵，从左至右每个4*4的矩阵都是1~16的不重复数字，其中一个被“？”替代。找出被替代的数字补全，并将n个方阵按被替代的数字顺序重新排列。
把矩阵拆开，遍历，重排，拼接即可
*/



/* bouncing diagonal
 matrix = [[2, 3, 2],
           [0, 2, 5],
           [1, 0, 1]]
 Let's define a bouncing diagonal as a sequence which starts from a cell of the leftmost column,
 and continues diagonally(up-right) until it reaches the rightmost column, bouncing vertically if
 it reaches the top of the matrix.
 For each cell of the leftmost column, let's define its weight as the sum of the elements in the
 boucing diagonal starting from that cell.
 The weight of the first element is 2 + 2 + 1 = 5
 The weight of the second element is 0 + 3 + 5 = 8
 The weight of the third element is 1 + 2 + 2 = 5
 The second element weight is greater than the others, so its value (0) goes to the end of the resulting array. There's a tie between the first and third elements, so they must be sorted by their values (1, 2). Therefore, the final order       of the elements in the leftmost column is [1, 2, 0].
*/
class ele{
public:
    int val;
    int sum;
    //ele();
    explicit ele(int v) : val(v), sum(0) {}
};
struct comp{
    bool operator()(const ele& a, const ele& b){
        if (a.sum != b.sum) return a.sum < b.sum;
        return a.val < b.val;
    }
};
vector<int> bouncingDiagonal(vector<vector<int>>& matrix){
    vector<ele> weights;
    int row = matrix.size();
    if (row == 0) return {};
    int col = matrix[0].size();
    for (int idx = 0; idx < row; idx++){
        int i = idx, j = 0;
        bool flag = true;
        ele cur(matrix[i][j]);
        while (j < col){
            cur.sum += matrix[i][j];
            if (i == 0 || i == row)
                flag = !flag;
            if (flag == true){
                i--;
                j++;
            }else{
                i++;
                j++;
            }
        }
        weights.push_back(cur);
    }
    sort(weights.begin(), weights.end(), comp());
    
    vector<int> ret;
    for (auto &weight: weights){
        //cout << weight.val << " " << weight.sum << endl;
        ret.push_back(weight.val);
    }
    return ret;
}

// constructorNames


// diagonalSort
void solution(vector<vector<int>>& matrix){
    if (matrix.empty()) return;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++){
        int r = i;
        int c = 0;
        vector<int> cur;
        while (r >= 0 && c < col){
            cur.push_back(matrix[r][c]);
            r--;
            c++;
        }
        sort(cur.begin(), cur.end());
//        for (auto &n: cur) cout << n << " ";
//        cout << endl;
        r = i;
        c = 0;
        for (auto &num: cur){
            matrix[r][c] = num;
            r--;
            c++;
        }
    }
    for (int j = 1; j < col; j++){
        int r = row - 1;
        int c = j;
        vector<int> cur;
        while (r >= 0 && c < col){
            cur.push_back(matrix[r][c]);
            r--;
            c++;
        }
        sort(cur.begin(), cur.end());
//        for (auto &n: cur) cout << n << " ";
//        cout << endl;
        r = row - 1;
        c = j;
        for (int num : cur){
            matrix[r][c] = num;
            r--;
            c++;
        }
    }
//    for (int i = 0; i < row; i++){
//        for (int j = 0; j < col; j++){
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
    return;
}

// opposite Sum
// consider a function rev which reverses the digits in an integer. rev(2400) = 42.
// given an array of non-negative integers arr, ur task is to count the number of pairs
// (i, j) such that i <= j and arr[i] + rev(arr[j]) = arr[j] + rev(arr[i]).
int oppositeSum(vector<int>& arr){
    
}

// buy shoes
// 给一个n*m的二位区域，从家(x1, y1)到超市(x2, y2)买东西，只能沿着两条对角线方向行进(初始方向向量(1, 1))，碰到边缘则改变方向，返回需要移动的步数，如果无法到达则返回-1。
// 例：n = 5, m = 5, x1 = 1, y1 = 2, x2 = 2, y2 = 1 --> return ==>  7
// 这道题一共过了20/21， 需要注意x,y和n,m的对应关系，因为地图不一定是方的，同时要记录走过的位置
int buyNewShoes(int x1, int y1, int x2, int y2, int n, int m){
    if (n <= 1 || m <= 1) return -1;
    int step = 0;
    
    vector<vector<bool>> board (n, vector<bool> (m, false));
    int rowdir = 1, coldir = 1;
    
    while (1){
        bool bounce = false;
        if (x1 + rowdir == n){
            rowdir = -1;
            bounce = true;
        }
        else if (x1 + rowdir < 0){
            rowdir = 1;
            bounce = true;
        }
        if (y1 + coldir == m){
            coldir = -1;
            bounce = true;
        }
        else if (y1 + coldir < 0){
            coldir = 1;
            bounce = true;
        }
        if (bounce == true) step++;
        x1 += rowdir;
        y1 += coldir;
        if (x1 == x2 && y1 == y2){
            return step + 1;
        }
        if (board[x1][y1] == true) break;
        board[x1][y1] = true;
        step++;
    }
    return -1;
}


// shuffle the piece
bool shuffleThePiece(vector<int>& arr, vector<vector<int>>& pieces){
    int count = 0;
    int len = arr.size();
    unordered_map<int, int> pos;
    for (int i = 0; i < arr.size(); i++){
        pos[arr[i]] = i;
    }
    for (auto &piece: pieces){
        if (piece.empty()) continue;
        count += piece.size();
        if (pos.find(piece[0]) == pos.end()) return false;
        int prev = pos[piece[0]];
        pos.erase(piece[0]);
        for (int i = 1; i < piece.size(); i++){
            if (pos.find(piece[i]) == pos.end() ||
                pos[piece[i]] != prev + 1) return false;
            prev = pos[piece[i]];
            pos.erase(piece[i]);
        }
    }
    return count == len;
}

// restoreArray
// u had an array a of length  n containing integer numbers with no duplicates, but it's been
// corrupted! Given pairs, an array of n-1 elements, where pairs[i] is a 2-element array of elements
// from a, either in the form [a[j], a[j+1]] or [a[j+1], a[j]] for some j. your task is to return
// the original array a.
vector<int> restoreArray(vector<vector<int>>& pairs){
    unordered_map<int, int> m;
    for (auto &pair: pairs){
        
    }
}

vector<int> restoreNumbersOnCircle(vector<vector<int>>& pairs){
    vector<int> ret;
    unordered_set<int> hasPrev;
    unordered_map<int, int> circle;
    
    for (auto &pair: pairs){
        int x = pair[0], y = pair[1];
        bool x_ = hasPrev.find(x) != hasPrev.end();
        bool y_ = hasPrev.find(y) != hasPrev.end();
        if (x_ == false && y_ == false){
            circle[x] = y;
            hasPrev.insert(y);
        }
        else if (x_ == false){
            circle[y] = x;
            hasPrev.erase(y);
            hasPrev.insert(x);
            
        }
        else if (y_ == false){
            circle[x] = y;
            hasPrev.erase(x);
            hasPrev.insert(y);
        }
    }
//    for (auto &ite: circle){
//        cout << ite.first << ' ' << ite.second << endl;
//    }
    auto ele = circle.begin()->first;
    ret.push_back(ele);
    ele = circle[ele];
    
    while (ele != ret[0]){
        ret.push_back(ele);
        ele = circle[ele];
    }
//    for (auto &num: ret){
//        cout << num << endl;
//    }
    return ret;
}

// labyrinth
bool labyrinth(int n, int m, vector<vector<int>>& obstacles, vector<vector<int>>& teleports){
    unordered_map<string, pair<int, int>> tp;
    //vector<vector<bool>> visited (n, vector<int> (m, false));
    vector<vector<int>> board (n, vector<int> (m, 0));
    for (auto &obstacle: obstacles){
        board[obstacle[0]][obstacle[1]] = -1;
    }
    for (auto &teleport: teleports){
        board[teleport[0]][teleport[1]] = 1;
        string start = to_string(teleport[0]) + "," + to_string(teleport[1]);
        tp[start] = {teleport[2], teleport[3]};
    }
    
    int r = 0, c = 0;
    while (1){
        if (r == n || c == m || board[r][c] == -1 || board[r][c] == 2) return false;
        if (r == n - 1 && c == m - 1) return true;
        
        if (board[r][c] == 0){
            board[r][c] = 2;
            c += 1;
        }
        else{
            string start = to_string(r) + "," + to_string(c);
            board[r][c] = 2;
            r = tp[start].first;
            c = tp[start].second;
        }
    }
    return false;
}

//定義sawtooth代表一連串數字中，上升和下降交替出現 （a sequence of numbers that alternate between increasing and decreasing) ，給你一串數字陣列
//請你output總共有幾組sawtooth （至少兩個數字）
//ex: arr = [1,2,1,2,1], output = 10

// 给一个string s，分成3个substring a，b，c， 使得 s = a + b + c, 并且a + b, b + c, c + a 都是不同的string，返回符合条件的分法个数.
// 给一个string，问你分成a,b,c三个substring，有多少种a+b, b+c, c+a都不一样的unique的分法（+代表concat）

// almostTetris
bool one(vector<vector<int>>& board, int i, int j, int idx){
    if (board[i][j] != 0) return false;
    board[i][j] = idx;
    return true;
}
bool two(vector<vector<int>>& board, int i, int j, int idx){
    if (board[i][j] != 0) return false;
    if (j + 1 == board[0].size() || board[i][j+1] != 0) return false;
    if (j + 2 == board[0].size() || board[i][j+2] != 0) return false;
    board[i][j] = idx;
    board[i][j+1] = idx;
    board[i][j+2] = idx;
    return true;
}
bool three(vector<vector<int>>& board, int i, int j, int idx){
    if (board[i][j] != 0) return false;
    if (i + 1 == board.size() || board[i+1][j] != 0) return false;
    if (j + 1 == board[0].size() || board[i][j+1] != 0) return false;
    if (board[i+1][j+1] != 0) return false;
    board[i][j] = idx;
    board[i][j+1] = idx;
    board[i+1][j] = idx;
    board[i+1][j+1] = idx;
    return true;
}
bool four(vector<vector<int>>& board, int i, int j, int idx){
    if (board[i][j] != 0) return false;
    if (i + 1 == board.size() || board[i+1][j] != 0) return false;
    if (i + 2 == board.size() || board[i+2][j] != 0) return false;
    if (j + 1 == board[0].size() || board[i+1][j+1] != 0) return false;
    board[i][j] = idx;
    board[i+1][j] = idx;
    board[i+1][j+1] = idx;
    board[i+2][j] = idx;
    return true;
}
bool five(vector<vector<int>>& board, int i, int j, int idx){
    if (board[i][j] != 0) return false;
    if (j + 1 == board[0].size() || board[i][j+1] != 0) return false;
    if (j + 2 == board[0].size() || board[i][j+2] != 0) return false;
    if (i - 1 < 0 || board[i-1][j+1] != 0) return false;
    board[i][j] = idx;
    board[i][j+1] = idx;
    board[i][j+2] = idx;
    board[i-1][j+1] = idx;
    return true;
}

vector<vector<int>> almostTetris(int n, int m, vector<int>& figures){
    int idx = 1;
    vector<vector<int>> board (n, vector<int> (m, 0));
    for (auto &figure: figures){
        bool find = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (figure == 1){
                    find = one(board, i, j, idx);
                }
                else if (figure == 2){
                    find = two(board, i, j, idx);
                }
                else if (figure == 3){
                    find = three(board, i, j, idx);
                }
                else if (figure == 4){
                    find = four(board, i, j, idx);
                }
                else{
                    find = five(board, i, j, idx);
                }
                if (find == true) break;
            }
            if (find == true) break;
        }
        idx++;
    }
    return board;
}


// allocate和free的一个题目: 给一个boolean array表示内存blocks，1是allocated 0 是free。然后给你一堆allocate和free的操作，比如[[0,2],[0,3],[1,1]]. 第一位表示allocate还是free，第二位表示要allocate多少blocks，或者free哪个allocated region。比如这个array就表示先allocate 两个block的区域，标记为region 1，然后allocate 3 blocks 标记为region 2，然后free region 1的内存。题目让返回一个和operations等长的array表示操作结果。对于allocate操作返回allocate的第一个block的index，对于free操作返回free了多少block，如果操作失败就标记为-1
vector<int> solution(vector<int>& a, vector<vector<int>>& queries){
    int atomicCounter = 1;
    string mem = "";
    unordered_map<int, pair<int, int>> blocks;
    vector<int> ret;
    for (auto &num: a){
        mem.push_back(num + '0');
    }
    for (auto &query: queries){
        if (query[0] == 0){
            // alloc
            string token = "";
            for (int i = 0; i < query[1]; i++)
                token.push_back('0');
            size_t pos = mem.find(token);
            if (pos == string::npos){
                ret.push_back(-1);
            }
            else{
                for (int i = pos; i < pos + query[1]; i++)
                    mem[i] = '1';
                blocks[atomicCounter] = {pos, pos + query[1]};
                atomicCounter++;
                ret.push_back(pos);
            }
        }
        else{
            if (blocks.find(query[1]) == blocks.end()){
                ret.push_back(-1);
            }
            else{
                int start = blocks[query[1]].first;
                int end = blocks[query[1]].second;
                for (int i = start; i < end; i++)
                    mem[i] = '0';
                ret.push_back(end - start);
            }
        }
    }
    return ret;
}

// maxRavenueFromStocks
// u r given prices, an array of positive integers where prices[i] represents the stock price on ith
// day. u r also given algo, an array of 0s and 1s representing the bot's schedule, 0: buy, 1: sell
// set a range of k consecutive elements from algo to 1 to maximize the ravenue.
int maxRavenueFromStocks(vector<int>& prices, vector<int>& algo, int k){
    int size = prices.size();
    int ravenue = 0, sell = 0;
    vector<int> ravenues;
    vector<int> sells;
    
    for (int i = 0; i < size; i++){
        sell += prices[i];
        ravenue += prices[i];
        if (algo == 0) ravenue -= (2 * prices[i]);
        
        ravenues.push_back(ravenue);
        sells.push_back(sell);
    }
    int maxRavenue = 0;
    for (int i = 0; i <= size - k; i++){
        int prevpos = i - 1, nextpos = i + k;
        int prev = 0, next = 0, cur = 0;
        if (prevpos >= 0){
            prev += ravenues[prevpos];
        }
        else{
            cur = sells[i + k - 1];
        }
        if (nextpos < size){
            next += (ravenues.back() - ravenues[i + k - 1]);
        }

        cur = sells[i + k - 1] - sells[prevpos];
        maxRavenue = max(maxRavenue, prev + next + cur);
    }
    return maxRavenue;
}

class square{
public:
    int missing;
    
};
// sortByMissingNumber
vector<vector<int>> sortByMissingNumber(vector<vector<int>>& matrix, int n){
    
}

// rotateOverDiagonals，就是顺时针转动矩阵，对角线数不变，具体参照利扣肆拾罢
// given an MxM matrix (M is odd) and an integer k, your task is to clockwise rotate the given matrix "over diagonals" k times.
void solution(vector<vector<int>>& matrix, int k){
    int row = matrix.size();
    int col = matrix[0].size();
    while (k > 0) {
        for (int i = 0; i < row; i++) {
            for (int j = i + 1; j < col; j++) {
                if (i != j && i != col - 1 - j) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col / 2; j++) {
                if (i != j && i != col - 1 - j) {
                    swap(matrix[i][j], matrix[i][col-1-j]);
                }
            }
        }
        k--;
    }
//    for (int i = 0; i < row; i++){
//        for (int j = 0; j < col; j++){
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
}

// 4 . removePairsGame
// 题干：Alice和Bob玩游戏，给出一个数组例如 [3,4,1,1,4,5]，每次可以从数组中移除2个连续且相等的数字，比如 [3,4,1,1,4,5] -> [3,4,4,5] -> [3,5]，游戏进行直到无法移除更多的数字。谁动不了谁就输。Alice先行。

// 解法：看起来有点DP，但实际上并没有，是个Greedy。
// 1. Brute Force，每次都遍历数组，发现则移除： nums == nums[i+1] -> nums = nums[:i] + nums[i+2L]
// 过不了hidden case，得分为209/300
// 2. Stack，从头往后遍历数组，如果栈顶元素跟当前元素相等则pop，并把游玩者turn+1，不相等则push。test cases就能全过



// duplicateOnSegment
// given an array of integers. ur task is to count the number of contiguous subarrays that each
// element of the subarray appears at least twice.
int duplicateOnSegment(vector<int>& arr){
    int count = 0;
    for (int r = 0; r < arr.size(); r++){
        unordered_map<int, int> m;
        int distinct = 0;
        for (int l = r; l >= 0; l--){
            int num = arr[l];
            m[num]++;
            if (m[num] == 1) distinct++;
            else if (m[num] == 2) distinct--;
            
            if (distinct == 0) count++;
        }
    }
    return count;
}


// PairSummingToPowerOfTwo
// Given an array of distinct integer a, ut task is to find the number of pairs of indices (i, j)
// such that i <= j and the sum a[i] + a[j] is equal to some power of two.
int PairSummingToPowerOfTwo(vector<int>& a){
    int size = a.size();
    int largest = a[0];
    int secLargest = a[1];
    unordered_map<int, int> m;
    m[a[0]] = 0;
    m[a[1]] = 1;
    for (int i = 2; i < size; i++){
        if (a[i] > largest) largest = a[i];
        if (a[i] > secLargest) secLargest = a[i];
        m[a[i]] = i;
    }
    int target = 1, count = 0;
    while (target <= largest + secLargest){
        for (int i = 0; i < size; i++){
            int diff = target - a[i];
            if (m.find(diff) == m.end() ||
                m[diff] < i) continue;
            count++;
        }
        target *= 2;
    }
    return count;
}

// maxArithmaticLength
int maxArithmaticLength(vector<int>& a, vector<int>& b){
    unordered_set<int> a_;
    vector<pair<int, char>> ab;
    int i = 0, j = 0;
    int lenA = a.size(), lenB = b.size();
    while (i < lenA && j < lenB){
        if (a[i] < b[j]){
            ab.push_back({a[i++], 'a'});
        }
        else if (a[i] > b[j]){
            ab.push_back({b[j++], 'b'});
        }
        else{
            ab.push_back({a[i++], 'a'});
            j++;
        }
    }
    while (i < lenA) ab.push_back({a[i++], 'a'});
    while (j < lenB) ab.push_back({b[j++], 'b'});
    
    int maxLen = -1, idxA = 0;
    int size = ab.size();
    // dp[num][diff] = len;
    if (ab[0].second == 'a') idxA++;
    
    unordered_map<int, unordered_map<int, int>> dp;
    for (int i = 1; i < size; i++){
        if (ab[i].second == 'a'){
            idxA++;
        }
        for (int j = i - 1; j >= 0; j--){
            int diff = ab[i].first - ab[j].first;
            auto status = make_pair(ab[i].first, diff);
            auto prevStatus = make_pair(ab[j].first, diff);
            auto iter = dp[prevStatus.first].find(prevStatus.second);
            if (iter == dp[prevStatus.first].end() && ){
                dp[prevStatus.first][prevStatus.second] = 2;
                if (idxA == lenA - 1)
                    maxLen = max(maxLen, dp[prevStatus.first][prevStatus.second]);
            }
            else if (iter != dp[prevStatus.first].end()){
                dp[status.first][status.second] = dp[prevStatus.first][prevStatus.second] + 1;
                if (idxA == lenA - 1)
                    maxLen = max(maxLen, dp[status.first][status.second]);
            }
            
            if (ab[j].second == 'a') break;
        }
    }
    return maxLen;
}

// 给数组内的所有数字按频率排序然后从右下角交错输出，频率相等就按大小排。
//例子:
//[[2,2,3],
//[1,1,1],
//[2,2,4]]
//按频率排序结果:
//[3,4,1,1,1,2,2,2,2]
//输出的时候从右下斜着填 (先填m[2][2], 然后m[2][1],然后m[1][2], 然后m[2][0], 然后[1][1] .... 最后m[0][0])
//[[2,2,2],
//[2,1,1],
//[1,4,3]]
class ele{
public:
    int val;
    int freq;
    //ele();
    explicit ele(int v) : val(v), freq(1) {}
};
struct comp{
    bool operator()(ele* a, ele* b){
        if (a->freq != b->freq) return a->freq < b->freq;
        return a->val < b->val;
    }
};
void solution(vector<vector<int>>& matrix){
    if (matrix.empty()) return;
    int row = matrix.size();
    int col = matrix[0].size();
    
    unordered_map<int, ele*> m;
    
    for (int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if (m.find(matrix[i][j]) == m.end()){
                ele *cur = new ele(matrix[i][j]);
                m[matrix[i][j]] = cur;
            }
            else{
                m[matrix[i][j]]->freq++;
            }
        }
    }
    vector<ele*> l;
    for (auto &pair: m) l.push_back(pair.second);
    sort(l.begin(), l.end(), comp());
    
    int idx = 0;
    for (int i = row + col -1; i >= x1; i--) {

        int startCol = max(0, i - row);
        int count = min(min(i, col - startCol), row);

        for (int j = 0; j < count; j++){
            matrix[min(row, i) - j - 1][startCol + j] = l[idx]->val;
            if (--l[idx]->freq == 0){
                idx++;
            }
        }
    }
//    for (int i = 0; i < row; i++){
//        for(int j = 0; j < col; j++){
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
}

//"." empty
//"#" box
//"*" obstacle
//"...##.....*#."
//"...####......"
//rotate後變成
//..
//..
//..
//##
//##
//#.
//#.
//..
//..
//..
//.*
//.#
//..
//然後
//box會往下掉
//obstacle則不動
//output:
//..
//..
//..
//..
//..
//..
//..
//..
//.#
//##
//#*
//#.
//##
public class obmatrix {
    public char[][] solution(char[][] matrix){
        int m = matrix.length;
        int n = matrix[0].length;
        char[][] res = new char[n][m];
        for(int i=0; i<m; i++){
            int end = n-1;
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j] == '#'){
                    matrix[i][j] = '.';
                    matrix[i][end] = '#';
                    end--;
                }else if(matrix[i][j] == '*'){
                    end = j-1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res[i][j] = matrix[j][i];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m/2; j++){
                char temp = res[i][j];
                res[i][j] = res[i][m-j-1];
                res[i][m-j-1] = temp;
            }
        }

        return res;
    }

    public static void main(String[] args){
        char[][] matrix = new char[][]{{'.','.','#','.','*','#','.','.'},{'#','.','*','#','#','.','.','.'},{'.','#','#','.','.','.','.','#'},{'.','.','.','#','#','*','#','.'}};
        obmatrix ob = new obmatrix();
        char[][] res = ob.solution(matrix);
        for(int i=0; i<res.length; i++){
            for(int j=0; j<res[0].length; j++){
                System.out.print(res[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}
