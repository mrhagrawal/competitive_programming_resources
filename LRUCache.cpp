#include<bits/stdc++.h>
using namespace std;


// in this we use map and list 



class LRUCache
{
    int c=0;
    list<pair<int,int>> l;  // list is use to create cache
    unordered_map<int,list<pair<int,int>>::iterator> m;  // map is use to store the location
    
    public:
    LRUCache(int capacity)
    {
        c=capacity;
    }
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        else
        {
            pair<int,int> p=*(m[key]);
            l.erase(m[key]);
            l.push_front(p);
            m[key]=l.begin();
            return m[key]->second;
        }
    }
    void set(int key, int value) {
        if(m.find(key)==m.end())
        {
            if(l.size()<c)
            {
                l.push_front({key,value});
                m[key]=l.begin();
            }
            else
            {
                auto it=l.end();
                it--;
                int k=it->first;
                l.erase(it);
                m.erase(k);
                l.push_front({key,value});
                m[key]=l.begin();
            }
        }
        else
        {
            m[key]->second=value;
            pair<int,int> p=*(m[key]);
            l.erase(m[key]);
            l.push_front(p);
            m[key]=l.begin();
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int capacity;
        cin>>capacity;
        LRUCache *cache = new LRUCache(capacity);
        int query;
        cin>>query;
        while(query--)
        {
            string q;
            cin>>q;
            if(q=="SET")
            {
                int key;cin>>key;
                int value;cin>>value;
                cache->set(key,value);
            }
            else
            {
                int key;cin>>key;
                cout<<cache->get(key)<<" ";
                cout<<endl;
            }
            
        }
        return 0;
    }
}
