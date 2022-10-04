#include <bits/stdc++.h>

// Debug
#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<" = "; deb(x); cerr<<endl;
#else
#define dbg(x)
#endif

// Macros
#define pr(x) cout<<(x)<<nline // From my python template
#define prl(x) cout<<(x)<<' ' // same as above
#define nline '\n' // Copied from a friend 
#define f first // But I never use pair
#define s second // Same as above
#define pb push_back

// Namespace
using namespace std;

// Typrdefs
typedef long long ll; 
typedef unsigned long long ull;
typedef long double lld;
typedef string str; // copied from Benq's code 

// Debug Functions
template<typename T>void deb(T avar){cerr<<avar;}
template<typename T, typename V>void deb(pair<T,V> apair){cerr<<"(";deb(apair.f);cerr<<", ";deb(apair.s);cerr<<")";}
template<typename T>void deb(vector<T> avec){ cerr<<"[ ";for(const auto &i: avec){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T, typename V>void deb(map<T,V> amap){cerr<<"[ ";for(const auto &i: amap){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T, typename V>void deb(unordered_map<T,V> amap){cerr<<"[ ";for(const auto &i: amap){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(set<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(unordered_set<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(multiset<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}
template<typename T>void deb(unordered_multiset<T> aset){cerr<<"[ ";for(const auto &i: aset){deb(i);cerr<<' ';}cerr<<"] ";}

// Constants (uncomment for use)
// const int MOD = 1e9+7; 
// const int MX = 2e5+5; 
// const ll INF = 1e18; 
// const lld PI = acos((lld)-1);

// Structs (uncomment for use)
// typedef struct some_name{
//     ll a;
//     str b;
// }real_name_of_struct;

// Classes
class single_node{
public:
    // Data memebers
    ll data;
    single_node * next;

    // Functions
    single_node(){
        this->data = LLONG_MIN;
        this->next = nullptr;
    }
    single_node(ll data, single_node * next){
        this->data = data;
        this->next = next;
    }

    // WARNING : Memeory Leak
    // Reason for not defining destructor 
    // Link : https://stackoverflow.com/questions/68998679/how-to-delete-this-in-c-class-so-that-it-doesnt-enter-infinte-loop
    // ~single_node(){
    //     cerr<<"destructor is called\n";
    //     if(this->next != nullptr){
    //         delete this->next;
    //     }
    // }

    void show(){ 
        // For Debugging
        single_node * temp = next;
        cout << data << "\n";
        while(temp != nullptr){
            cout << data << " - ";
            temp = temp->next;
        } 
        cout << "\n";
    }
    
};

class single_linked_list{
public:
    // Data members
    single_node * head = new single_node;

    // Functions
    single_linked_list(){
        head->data = LLONG_MIN;
        head->next = nullptr;
    }

    void add_after(ll data){
        // Clearly O(n) as we need to find the end to add the element
        if(head->data == LLONG_MIN){
            head->data = data;
            head->next = nullptr;
        }
        else{
            single_node * temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            single_node * z = new single_node;
            temp->next = z;
            z->data = data;
        }
    }

    void traversing(bool flag = false){
        // O(n)
        if(flag){
            single_node * temp = this->head;
            while(temp != nullptr){
                // cout << "(" << temp << ")";
                // cout << temp->data << " -> ";
                cout << temp->data << "(" << temp << ")" << " -> ";
                temp = temp->next;

            }
            cout << "null" << "(" << temp << ")\n";
        }
        else{
            single_node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }
};

class double_node{
public:
    // Data memebers
    ll data;
    double_node * next;
    double_node * prev;

    // Functions
    double_node(){
        this->next = nullptr;
        this->prev = nullptr;
        this->data = LLONG_MIN;
    }

    double_node(ll data, double_node * next, double_node * prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    // WARNING : Memeory Leak
    // Reason for not defining destructor 
    // Link : https://stackoverflow.com/questions/68998679/how-to-delete-this-in-c-class-so-that-it-doesnt-enter-infinte-loop
    // ~double_node(){
    //     cerr << "~double_node() is called\n";
    //     double_node * temp = this;
    //     if(temp != nullptr){
    //         delete temp;
    //     }
    //     temp = nullptr;
    // }
};

class double_linked_list{
public:
    double_node * head = new double_node;
    double_node * tail = new double_node;

    double_linked_list(){
        // Head part
        head->data = LLONG_MIN;
        head->next = tail;
        head->prev = nullptr;
        // Tail part
        tail->data = LLONG_MIN;
        tail->next = nullptr;
        tail->prev = head;
        
    }
    void append(ll data){
        if(head->data == LLONG_MIN){
            head->data = data;
        }
        else if(tail->data == LLONG_MIN){
            tail->data = data;
        }
        else{
            double_node * temp = tail;
            double_node * last = new double_node;
            
            // Setting up last
            last->data = data;

            temp->next = last;
            last->prev = temp;
            last->next = nullptr;

            tail = last;
        }
        
    }

    void add_after(ll where, ll data){
        double_node * temp = head;
        while(temp != nullptr and temp->data != where){
            temp = temp->next;
        }
        //    x <=> y  
        //       z
        // x <=> z <=> y
        double_node * x = temp;
        double_node * y = temp->next;
        double_node * z = new double_node;
        z->data = data;
        
        // adding z next to x
        x->next = z;
        z->prev = x;

        // adding z prev to y
        z->next = y;
        if(y != nullptr){
            y->prev = z;
        }
    }

    void remove(ll data){
        double_node * temp = head;
        while(temp != nullptr and temp->data != data){
            temp = temp->next;
        }
        if(temp->data == data){
            double_node * y = temp->prev;
            double_node * x = temp;
            double_node * z = temp->next;
            if (z != nullptr){
                z->prev = y;
            }
            if(y != nullptr){
                y->next = z;
            }
            if(x == head){
                head = z;
            }
            if(temp != nullptr){
                x->next = nullptr;
                x->prev = nullptr;
                delete x;
            }

        }
    }

    void traversing(bool flag = false){
        // O(n)
        if(flag){
            double_node * temp = this->head;
            while(temp != nullptr){
                // cout << "(" << temp << ")";
                // cout << temp->data << " -> ";
                cout << temp->data << "(" << temp << ")" << " <=> ";
                temp = temp->next;

            }
            cout << "null" << "(" << temp << ")\n";
        }
        else{
            double_node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " <=> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }

    void traversing_reverse(){
        double_node * temp = this->tail;
        while(temp != nullptr){
            cout << temp->data << " <=> ";
            temp = temp->prev;

        }
        cout << "null\n";
    }
};

class Stack{
private:
    // Data Members
    single_node * head = nullptr;
    ll n ;
public:
    // Functions
    Stack(){
        // Heap allocation and default constructor of single_node is called
        single_node * head = new single_node;
        n = 0; 
    }
    
    void push(ll x){
        single_node * temp = new single_node;
        temp->data = x;
        temp->next = head;
        head = temp;
        n++;
    }

    ll pop(){
        if(n != 0){
            n--;
            single_node * res = head;
            ll ans = res->data;
            head = head->next;
            delete res;
            return ans;
        }
        else{
            cerr << "Cannot pop a empty stack" << "\n";
            return LLONG_MIN;
        }
    }

     void traversing(bool flag = false){
        // O(n)
        if(flag){
            single_node * temp = this->head;
            while(temp != nullptr){
                // cout << "(" << temp << ")";
                // cout << temp->data << " -> ";
                cout << temp->data << "(" << temp << ")" << " -> ";
                temp = temp->next;

            }
            cout << "null" << "(" << temp << ")\n";
        }
        else{
            single_node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }
};

class Queue{
private:
    // Data Members
    single_node * head = nullptr;
    single_node * tail = nullptr;
    ll n;
public:
    // Functions
    Queue(){
        head = new single_node;
        tail = head;
        n = 0;
    }

    void add(ll x){
        
        if(n == 0 and head != nullptr){
            head->data = x;
        }
        else if(head == nullptr){
            head = new single_node;
            tail = head;
            head->data = x;
        }
        else{
            single_node * temp = new single_node;
            temp->data = x;
            tail->next = temp;
            tail = temp;
        }
        n++;
    }

    ll remove(){
        single_node * res = head;
        if(n == 0){
           cerr << "Cannot remove element from a empty Queue";
           return LLONG_MIN; 
        }
        else{
            n--;
            ll ans = head->data;
            head = head->next;
            return ans;
        }
    }

    void traversing(bool flag = false){
        // O(n)
        if(flag){
            single_node * temp = this->head;
            while(temp != nullptr){
                // cout << "(" << temp << ")";
                // cout << temp->data << " -> ";
                cout << temp->data << "(" << temp << ")" << " -> ";
                temp = temp->next;

            }
            cout << "null" << "(" << temp << ")\n";
        }
        else{
            single_node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "null\n";
        }
    }

};

// Functions


// Solution
void solve(){
    // Somehow working 
    single_linked_list alinklist;
    for(ll i = 1 ; i < 11 ; i++){
        alinklist.add_after(i);
    }
    alinklist.traversing();

    double_linked_list adll;
    for(ll i = 1; i < 11 ; i++){
        adll.append(i);
    }
    adll.traversing();
    // adll.traversing_reverse();
    for(ll i = 1; i < 11 ; i++){
        adll.remove(i);
        adll.traversing();
        // adll.traversing_reverse();
    }

    cout << "Stack : \n";
    Stack st;
    for(ll i = 1; i < 11 ; i++){
        st.push(i);
    }
    st.traversing();
    for(ll i = 1; i < 11 ; i++){
        cout << st.pop() << ' ';
    }
    cout << '\n';
    st.traversing();
    
    st.pop();
    st.push(111);
    st.traversing();

    cout << "Queue : \n";
    Queue qu;
    for(ll i = 1; i < 11 ; i++){
        qu.add(i);
    }
    qu.traversing();

    for(ll i = 1; i < 11 ; i++){
        cout << qu.remove() << ' ';
    }
    cout << "\n";

    qu.traversing();
    qu.remove();
    qu.add(111);
    qu.traversing();
}

// Main
int main(){
    // Fast IO
    ios::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL); 

    // For local code 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif // ONLINE_JUDGE    

    // Complete Solution
    ll T;cin>>T;while(T--)
    solve();
    return 0;
}

// Read this if you ever get stuck 
// Benq's advice : stuff you should look for
// 	* int overflow, array bounds
// 	* special cases (n=1?)
// 	* do smth instead of nothing and stay organized
// 	* WRITE STUFF DOWN
// 	* DON'T GET STUCK ON ONE APPROACH