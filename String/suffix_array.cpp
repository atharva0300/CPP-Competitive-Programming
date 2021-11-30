#iclude<bits/stdc++.h>
using namespace std;


/*
    DEFINITION

    Let s be a string of length n. The i-th suffix of s is the substring s[i…n−1].

A suffix array will contain integers that represent the starting indexes of the all the suffixes of a given string, after the aforementioned suffixes are sorted.

As an example look at the string s=abaab. All suffixes are as follows

0.1.2.3.4.abaabbaabaababb
After sorting these strings:

2.3.0.4.1.aabababaabbbaab
Therefore the suffix array for s will be (2, 3, 0, 4, 1).

As a data structure it is widely used in areas such as data compression, bioinformatics and, in general, in any area that deals with strings and string matching problems.

*/


/* 
    O(nlogn) approach
Strictly speaking the following algorithm will not sort the suffixes, but rather the cyclic shifts of a string. However we can very easily derive an algorithm for sorting suffixes from it: it is enough to append an arbitrary character to the end of the string which is smaller than any character from the string. It is common to use the symbol $. Then the order of the sorted cyclic shifts is equivalent to the order of the sorted suffixes, as demonstrated here with the string dabbb.

1.4.3.2.0.abbb$db$dabbbb$dabbbb$dadabbb$abbbbbbbbbdabbb
Since we are going to sort cyclic shifts, we will consider cyclic substrings. We will use the notation s[i…j] for the substring of s even if i>j. In this case we actually mean the string s[i…n−1]+s[0…j]. In addition we will take all indices modulo the length of s, and will omit the modulo operation for simplicity.

The algorithm we discuss will perform ⌈logn⌉+1 iterations. In the k-th iteration (k=0…⌈logn⌉) we sort the n cyclic substrings of s of length 2k. After the ⌈logn⌉-th iteration the substrings of length 2⌈logn⌉≥n will be sorted, so this is equivalent to sorting the cyclic shifts altogether.

In each iteration of the algorithm, in addition to the permutation p[0…n−1], where p[i] is the index of the i-th substring (starting at i and with length 2k) in the sorted order, we will also maintain an array c[0…n−1], where c[i] corresponds to the equivalence class to which the substring belongs. Because some of the substrings will be identical, and the algorithm needs to treat them equally. For convenience the classes will be labeled by numbers started from zero. In addition the numbers c[i] will be assigned in such a way that they preserve information about the order: if one substring is smaller than the other, then it should also have a smaller class label. The number of equivalence classes will be stored in a variable classes.

Let's look at an example. Consider the string s=aaba. The cyclic substrings and the corresponding arrays p[] and c[] are given for each iteration:

0:1:2:(a, a, b, a)(aa, ab, ba, aa)(aaba, abaa, baaa, aaab)p=(0, 1, 3, 2)p=(0, 3, 1, 2)p=(3, 0, 1, 2)c=(0, 0, 1, 0)c=(0, 1, 2, 0)c=(1, 2, 3, 0)
It is worth noting that the values of p[] can be different. For example in the 0-th iteration the array could also be p=(3, 1, 0, 2) or p=(3, 0, 1, 2). All these options permutation the substrings into a sorted order. So they are all valid. At the same time the array c[] is fixed, there can be no ambiguities.

Let us now focus on the implementation of the algorithm. We will write a function that takes a string s and returns the permutations of the sorted cyclic shifts.

*/

vector<int>sort_cyclic_shifts(string const& s)
{
    int n = s.size();
    const int alphabet = 256;
}

/* 
    At the beginning (in the 0-th iteration) we must sort the cyclic substrings of length 1, that is we have to sort all characters of the string and divide them into equivalence classes (same symbols get assigned to the same class). This can be done trivially, for example, by using counting sort. For each character we count how many times it appears in the string, and then use this information to create the array p[]. After that we go through the array p[] and construct c[] by comparing adjacent characters.
*/


vector<int>p(n) ,c(n) , cnt(max(alphabet , n) ,0);
for(int i=0;i<n;i++)
{
    cnt[s[i]]++;
}
for(int i=1;i<alphabet;i++)
{
    cnt[i] += cnt[i-1];
}
for(int i=0;i<n;i++)
{
    p[--cnt[s[i]]] = i;
}
c[p[0]] =0;
int classes = 1;
for(int i=1;i<n;i++)
{
    if(s[p[i]] ! s[p[i-1]])
    {
        classes++;
    }
    c[p[i]] = classes -1;
}


vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}


vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int main()
{

    return 0;
}