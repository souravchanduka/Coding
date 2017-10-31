#include <bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insList(ListNode* l, int x)
{
    ListNode* n= new ListNode;
    n->val=x;
    n->next=NULL;
    ListNode* t=l;
    if(t)
    {
        while(t->next)
            t=t->next;
        t->next=n;
    }
    else
        l=n;
    return l;

}

void prinList(ListNode* l)
{
    while(l)
    {
        cout<<(l->val)<<" -> ";
        l=l->next;
    }
    cout<<endl;
}

ListNode* rev(ListNode* q)
{
    ListNode* t=NULL;
    ListNode* a=q;
    while(q)
    {
        a=q;
        q=q->next;
        a->next=NULL;
        if(!t)
            t=a;
        else
        {
            a->next=t;
            t=a;
        }
    }
    return t;
}

int main()
{
    ListNode* l=NULL;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        l=insList(l,x);
    }
    l=rev(l);
    prinList(l);
    return 0;
}