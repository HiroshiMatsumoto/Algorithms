#include <iostream>
/*
最小値を返す関数テンプレートの作成

任意の個数の引数をとる
比較にoperator<演算子を使う
*/

template <typename T>
T min(T t1, T t2){
    return t1 < t2 ? t1 : t2;
}

template <typename T, typename... Ts>
T min(T t1, Ts... ts){
    return min(t1, min(ts...));
}

int main(){
  int a = min(11, 10, 24, 100, 132);
  std::cout << a << std::endl;
  return 0;
}