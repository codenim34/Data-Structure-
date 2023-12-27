//In The Name Of ALlah, The most Gracious The Most Merciful
#include<bits/stdc++.h>
#define ll long long
#define shoot           ios_base::sync_with_stdio(false); cin.tie(0);
#define tc             int t; cin>>t;
#define vi vector<int> 
#define pp pair<int,int>
#define cy cout<<"YES"<<"\n"
#define cn cout<<"NO"<<"\n"
using namespace std;
struct node {
    bool endmark;
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

void insert(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = 1;
}
bool search(char* str, int len)
{
    node* curr = root;
    for (int i = 0; i < len; i++) {
        int id = str[i] - 'a';
        if (curr->next[id] == NULL)
            return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}

void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);
    delete (cur);
}
int main()
{
shoot;
int n;


return 0;
}