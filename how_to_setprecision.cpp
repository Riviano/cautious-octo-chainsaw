#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  double a=3.141592;
  cout << setprecision(4) << a << endl;
  cout << fixed << setprecision(4) << a << endl;
  cout << scientific << setprecision(4) << a << endl;

}
//http://www.proton.jp/main/programming/cpp/manipulator.html#fixed　参照

/*output:
3.142
3.1416
3.1416e+00
*/


/*
マニピュレータを用いた数値の整形
1.書式フラグを設定するには
2.数値を固定小数点形式で表示するには
3.数値を指数形式で表示するには
4.小数の桁数を指定するには
5.幅を指定するには
6.書式フラグを設定するには




1書式フラグを設定するにはストリーム形式で設定する方法と，coutのメンバ関数setf()を用いる方法がある。

ストリーム形式でscentificとshowposを設定して倍精度実数を表示する。

#include <iostream>
using namespace std;
int main(){
  double a=5.23e3;
  cout << scientific << showpos << a << endl;
}
+5.230000e+03
メンバ関数setf()を使って同じものを実現するには，次のようにすればよい。

#include <iostream>
using namespace std;
int main(){
  double a=5.23e3;
  cout.setf(ios::scientific | ios::showpos);
  cout << a << endl;
}
+5.230000e+03
複数のフラグは「|」(OR)を使って同時に設定することができる。
setf()を使って書式フラグを設定するときに注意することがある。 例えばscientificとfixedのように同時に設定できないフラグがある場合，必ずどちらかをOFFにしておかなければ表示がおかしくなる。

#include <iostream>
using namespace std;
int main(){
  double a=5.23e3;
  cout.setf(ios::fixed | ios::scientific); // 両方ON
  cout << a << endl;

  cout.unsetf(ios::scientific); // scientific -> OFF
  cout << a << endl;

  cout.unsetf(ios::fixed); // 両方OFF
  cout << a << endl;

}
0x1.46ep+12
5230.000000
5230



2.数値を固定小数点形式で表示するには
倍精度実数型変数に入っている数値を，小数点以下の桁数を指定して固定小数点形式で表示するには，fixedとsetprecision()というマニピュレータを使う。

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  double a=1.23;
  cout << fixed << setprecision(4) << a << endl;
}
1.2300

3.数値を指数形式で表示するには
  倍制度実数型に入っている数値を，指数形式で表示するにはscientificというマニピュレータを使う。

  double b=4.56e9;;
  cout << scientific << setprecision(4) << b << endl;
  4.5600e+09
  指数形式の"e"を大文字の"E"にするには，マニピュレータuppercaseを使う。

  double b=4.56e9;;
  cout << scientific << setprecision(4) << uppercase << b << endl;
  4.5600E+09


4.小数の桁数を指定するには
小数点以下の桁数を指定するにはsetprecision(int)を用いる。 setprecision()を使うにはヘッダファイルiomanipを読み込む。

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  double a=3.141592;
  cout << setprecision(4) << a << endl;
  cout << fixed << setprecision(4) << a << endl;
  cout << scientific << setprecision(4) << a << endl;

}
3.142
3.1416
3.1416e+00
fixedもscientificも指定していないデフォルトでは，なぜか桁数が一つ小さくなるので注意。
5.幅を指定するには
出力の幅を固定するにはsetw(int)を用いる。 デフォルトでは余った部分には空白が入り，全体が右寄せされる。 マニピュレータleftを使うと全体が左寄せされ，右側に空白が入る。

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  double a=3.141592;
  cout.setf(ios::fixed);
  cout << setw(10) << a << endl;
  cout << setw(10) << left << a << endl;
}
__3.141592
3.141592__
*/
