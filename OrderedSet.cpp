#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set st;
#define ll long long
int n, k;
 
void myerase(int v) {
    int rank = st.order_of_key(v);//Number of elements that are less than v in t
    ordered_set::iterator it = st.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    st.erase(it);
}
// ordered multiset 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl '\n'
// using namespace __gnu_pbds;
// template<typename T>
// using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;//ordered set
 
// template<typename T>
// using o_mset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;//ordered multiset
int main() {
 
    st.order_of_key(6);
 
}
