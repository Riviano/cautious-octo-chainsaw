#include<iostream>
#include<set>
using namespace std;
int main(){
  set<int>st{1,2,3,4,5,6};
  for(auto itr=st.begin();itr!=st.end();){
    if(*itr%2==0) itr = st.erase(itr);
    else ++itr;
  }
  for(auto ITR = st.begin();ITR!=st.end();++ITR){
    cout << *ITR << endl;
  }
}
//https://qiita.com/tell0120xxx/items/84b8750ba87cd2ab2633参照
