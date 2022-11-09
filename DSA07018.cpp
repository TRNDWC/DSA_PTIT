#include <bits/stdc++.h>
using namespace std;

int t;
string s1, s2, so;

struct node
{
    int heso, mu;
    struct node *next = NULL;
};

class dathuc
{
public:
    node *dau;
    void build(node *);
    node *tao(int, int);
    void add(int, int);
    void xoa();
};

void dathuc::build(node *s)
{
    dau = s;
    return;
}

node *dathuc::tao(int hs, int sm)
{
    node *temp;
    temp = new (node);
    if (temp == NULL)
    {
        return NULL;
    }
    else
    {
        temp->heso = hs;
        temp->mu = sm;
        temp->next = NULL;
        return temp;
    }
}

void dathuc::add(int hs, int sm)
{
    node *temp, *s;
    temp = tao(hs, sm);
    if (dau == NULL)
    {
        dau = temp;
        dau->next = NULL;
        return;
    }
    s = dau;
    while (s->next != NULL)
    {
        s = s->next;
    }
    temp->next = NULL;
    s->next = temp;
}

void dathuc::xoa()
{
    if (dau == NULL)
        return;
    node *temp;
    temp = dau;
    dau = temp->next;
}
int main()
{
    cin >> t;
    while (t--)
    {
        scanf("\n");
        getline(cin, s1);
        scanf("\n");
        getline(cin, s2);
        dathuc so1;
        so1.build(NULL);
        int a = -1, b = -1;
        s1 += ' ';
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ')
            {
                if (a == -1 && b == -1)
                    continue;
                stringstream ss;
                int gt;
                ss << so;
                ss >> gt;
                b = gt;
                so1.add(a, b);
                a = -1;
                b = -1;
                so = "";
            }
            else if (s1[i] >= '0' && s1[i] <= '9')
                so += s1[i];
            else if (s1[i] == '*')
            {
                stringstream ss;
                int gt;
                ss << so;
                ss >> gt;
                a = gt;
                so = "";
            }
        }

        dathuc so2;
        so2.build(NULL);

        a = -1;
        b = -1;
        s2 += ' ';
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == ' ')
            {
                if (a == -1 && b == -1)
                    continue;
                stringstream ss;
                int gt;
                ss << so;
                ss >> gt;
                b = gt;
                so2.add(a, b);
                a = -1;
                b = -1;
                so = "";
            }
            else if (s2[i] >= '0' && s2[i] <= '9')
                so += s2[i];
            else if (s2[i] == '*')
            {
                stringstream ss;
                int gt;
                ss << so;
                ss >> gt;
                a = gt;
                so = "";
            }
        }

        node *it1, *it2;
        it1 = so1.dau;
        it2 = so2.dau;
        while (it1 != NULL || it2 != NULL)
        {
            if (it1->mu > it2->mu)
            {
                cout << it1->heso << "*x^" << it1->mu;
                it1 = it1->next;
            }
            else if (it2->mu > it1->mu)
            {
                cout << it2->heso << "*x^" << it2->mu;
                it2 = it2->next;
            }
            else if (it2->mu == it1->mu)
            {
                cout << it2->heso + it1->heso << "*x^" << it2->mu;
                it2 = it2->next;
                it1 = it1->next;
            }
            if (it1 != NULL || it2 != NULL)
                cout << " + ";
        }
        while (it1 != NULL)
        {
            if (it1->next != NULL)
            {
                cout << it1->heso << "*x^" << it1->mu << " + ";
                it1 = it1->next;
            }
            else
            {
                cout << it1->heso << "*x^" << it1->mu;
            }
        }
        while (it2 != NULL)
        {
            if (it2->next != NULL)
            {
                cout << it2->heso << "*x^" << it2->mu << " + ";
                it2 = it2->next;
            }
            else
            {
                cout << it2->heso << "*x^" << it2->mu;
            }
        }
        cout << endl;
    }
}
