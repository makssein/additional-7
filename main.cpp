/*
Вариант-3.
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
Удалить из последовательности числа, сумма цифр которых кратна шести.
Среди оставшихся продублировать числа, начинающиеся цифрой 1.
 */



#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::vector<int> mas;
    int n,s,b=0,a=0,sum=0,it=0, it2=0, count=0, num=0;
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    in >> n;
    for(int i = 0; i < n; i++){
        in >> s;
        mas.push_back(s);
    }

    while(it<mas.size()){
        b = mas[it];
        while(b>0){
            a = b%10;
            b /=10;
            sum+=a;
        }
        if(sum%6 == 0) {
            auto iter = mas.cbegin();
            mas.erase(iter + it);
        } else{
            it++;
        }
        sum=0;
    }
    int old_size = mas.size();
    while(it2 < old_size+count){
        num = mas[it2];
        while(num>9){
            num/=10;
        }
        if(num == 1) {
            auto iter2 = mas.cbegin();
            mas.insert(iter2+it2, mas[it2]);
            count++;
            it2++;
        }
        it2++;
    }



    for (auto const &element: mas)
        out << element << ' ';
    return 0;
}
