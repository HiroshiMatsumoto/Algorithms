#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

/*
要素へのアクセス(at(), data())
容量クエリ
イテレータ
フィリング
スワップ
*/

template <class T, size_t R, size_t C>
class Array{
    // defining two-dimension vector with T type 
    vector<vector <T>> arr;
    public:
    // initializing R by C 2D-vector 
    Array(): Array(R, vector<T>(C)){};
    // initializing with given data;
    // https://stackoverflow.com/questions/22133909/how-can-i-use-an-initializer-list-to-initialize-a-2d-vector-member
    Array(std::initializer_list<vector<T>> arr): arr(arr){};

    constexpr T at(const size_t r, const size_t c){
        return arr[r][c];
    }

    constexpr size_t size(int const rank){
        if(rank == 1){
            return R;
        }
        else if(rank == 2){
            return C;
        } 
        throw std::out_of_range("out of range");        
    }

    vector<T> *data(){
        return arr.data();
    }
};


int main(){
    Array<int, 2, 3> array {{1, 2, 3}, {4, 5, 6}};
    
    for(size_t i = 0; i < array.size(1); i++ ){
        for(size_t j = 0; j < array.size(2); j++ ){
            cout << i << ", " << j << ": " << array.at(i, j) << endl;
        }        
    }

    return 0;
}