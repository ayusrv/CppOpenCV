    #include<bits/stdc++.h>
    using namespace std;

    class dyna{
        public:
        int a;
        int b;
        dyna():a(10),b(10){}
        dyna(int a, int b):a(a),b(b){}
    };

    int main(){
        dyna* d= new dyna[5];
        for(int i=0;i<5;i++){
            d[i] = dyna(i+1,i-1);
        }
        for(int i=0;i<5;i++){
            cout<<"Value for "<<i+1<<" is "<<d[i].a<<" "<<d[i].b<<endl;
        }
        delete[] d;

        dyna **dd = new dyna*[5];
        for(int i=0;i<5;i++){
            dd[i] = new dyna(i+1,i-1);
        }
        for(int i=0;i<5;i++){
            cout<<"Value for "<<i+1<<" is "<<dd[i]->a<<" "<<dd[i]->b<<endl;
        }
        delete[] dd;
    }