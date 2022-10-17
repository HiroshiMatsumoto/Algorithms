#include <iostream>
#include <vector>
#include <initializer_list>

/*
要素へのアクセス(at(), data())
容量クエリ
イテレータ
フィリング
スワップ
*/

template <typename T>
class array_iterator{
    T & t;
    array_iterator(T & t): t(t) {}
};


template <class T, size_t R, size_t C>
class array{
    using iterator = array_iterator<array>;
    std::vector<T> _array;
    public:
    // init.
    array():_array(R*C){}
    array(std::initializer_list<T> v):_array(v){};

    T at(size_t i, size_t j){
        return _array[C * i + j];
    }

    const size_t size(){
        return _array.size();
    }

    const size_t rsize(){
        return R;
    }

    const size_t csize(){
        return C;
    }

    T* data(){
        return _array.data();
    }

    iterator begin(){
        return this.data();
    }

    iterator end(){
        return this.data() + _array.size();
    }
};




int main(){
    array<int, 2, 3> M {2,3,4,5,6,7}; 
   
    for(int i = 0; i < M.rsize(); i++){
        for(int j = 0; j < M.csize(); j++){
            std::cout << M.at(i,j) << std::endl;
        }
    }
   
   int* a = M.data();
   std::cout << *a << std::endl;

   // イテレータ
   /*
   for(auto itr = M.begin(); itr != M.end(); ++itr){
    std::cout << *itr << std::endl;
   }
   */
   return 0;
}