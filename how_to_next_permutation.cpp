//#include<iostream>
//#include<algorithm>//next_permutation
#include<bits/stdc++.h>
using namespace std;
int main(){
    int array[]={1,2,3,4};
    do{
        for(int i=0; i<4; i++){
            cout<<array[i];
            if(i!=3)cout<<" ";
        }
        cout<<endl;
    }while(next_permutation(array,array+4));
    return 0;
  }
  //https://qiita.com/siser/items/a91022071b24952d27d9を参照
/*
next_permutationについて
C++

0.はじめに
std::next_permutationは順列を生成する...といってもいまいちよくわからなかったので
私が理解したことを簡単に整理しました。

1.そもそも順列とは
順列の定義について確認しましょう。
高校数学Aでは順列を次のように定義しています。

いくつかのものを順序をつけて並べたものを順列という
異なるn個のものからr個を取り出して一列に並べたものをn個からr個とる順列といいnPrで表す
nPr=n(n-1)(n-2)...(n-r+1)=n!/(n-r)!

例えば,{1,2,3}という要素の順列は
{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2}{3,2,1}
の6通り。(3!)
{a,b,c,d}から3個を取り出して1列に並べる順列は24通り。(4!/(4-3)!)
また{1,1,2}という要素の順列は
{1,1,2}
{1,2,1}
{2,1,1}
の3通り

この全ての組み合わせをプログラムで生成するのは難しいので
next_permutationを使います。

2.まずは使ってみる
辞書順なので、例えば{1,3,2}{2,1,3}{1,2,3}とあるとき
{1,2,3}
{1,3,2}
{2,1,3}と並べます。

実はnext_permutationは自動的にこれを行ってくれます(詳しくは後述)
まずはコードを見てみましょう。

#include<iostream>
#include<algorithm>//next_permutation
using namespace std;

int main(){
    int array[]={1,2,3,4};
    do{
        for(int i=0; i<4; i++){
            cout<<array[i];
            if(i!=3)cout<<" ";
        }
        cout<<endl;
    }while(next_permutation(array,array+4));
    return 0;
}
上から見ていきましょう。
next_permutationを使うときはalgorithmヘッダをインクルードしておく必要があります。
array[]には並べ替えたい数列を入れておきます。(後述しますがこの数列は昇順でないと全列挙はしてくれません)
次にdo～while文で、doの中に配列array[]の要素の全列挙、whileにnext_permutation()を使っています。
next_permutation()には配列の範囲を渡します。(sort()と同じように使えます)
まずarray[]の中の文字列を順に全列挙し、next_permutationで並べ替えるということです。
これを実行すると、

1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
//...(順列が生成されるが長いので割愛)
4 3 1 2
4 3 2 1
このようになります
まず着目してほしいのは、順列が生成されていく順番です。

3.next_permutationの仕組みについて
上のコードでは、順列は{1,2,3,4}の次は{1,2,4,3}でした。
これは以前述べているように、辞書順になっています。
{1,2,3,4}の順列は、{1,3,2,4},{2,4,1,3},{4,3,1,2},...とたくさんありますが、これらを全て書いて辞書順に並べたときに、その次に並んでいるものに配列を置き換えています。
つまりnext_permutationのやっていることは、指定された配列(又はコンテナクラス)の順列を全て並べたときに、その配列を辞書順で次のものに置き換えることです。
ではarray[]に{1,2,3,4}を入れる代わりに{4,3,2,1}を入れるとどうなるでしょうか。
出力はこのようになります。

4 3 2 1
この時、まずdo{}の中のarrayの要素を全列挙して4 3 2 1と出力した後、while()のnext_permutationでは{4,3,2,1}を全列挙した時の辞書順で次にある物に置き換えようとしますが、{4,3,2,1}がその中でも辞書順で一番最後にあるものなのでこれ以上置き換えることは出来ずnext_permutationは-1を返してwhile()ループは終了します。
実はこの時next_permutationは-1を返してから辞書順で最初の配列{1,2,3,4}に置き換えています。
なので組み合わせの総数が分かっていればforループを使い、全ての順列を列挙することも可能です。

また、これはvector等のコンテナクラスを使って書くこともできます。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v={1,2,3,4};
    do{
        for(int i=0; i<4; i++){
            cout<<v[i];
            if(i!=3)cout<<" ";
        }
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}
これでも全く同じことができます。

4.prev_permutation
prev_permutationを使うとnext_permutationの逆のこと、つまり指定された配列(又はコンテナクラス)の順列を全て並べたときに、その配列を辞書順で前のものに置き換えることができます。
上でv={4,3,2,1}としてnext_permutationの代わりにprev_permutationを使うと、

4 3 2 1
4 3 1 2
4 2 3 1
//...(順列が生成されるが長いので割愛)
1 2 4 3
1 2 3 4
こうなります。

5.使い方について
next_permutationは大小関係があれば使えるので文字列も扱うことができます。
入力された文字列の順列を辞書順に並べるプログラムはこのようにして実装することができます。
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
    return 0;
}
最後に計算量について説明します。
要素nの順列はn!通りあるので計算量はO(n!)です。
O(n!)のアルゴリズムはnが10を超えるあたりから間に合わなくなるので工夫が必要です。(工夫の仕方については今回は触れません)
*/
