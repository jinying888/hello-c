#include <stdio.h>
#include <fstream>
using namespace std;
int main()
{
    ofstream out("test.bin",ios_base::out|ios_base::binary);
    if(!out.is_open()){
        printf("file open fail");
        return -1;
    }
    float f1 = 3.141592f;
    out.write((char*) &f1, sizeof(f1));
    out.close();
    float f2 = 0;
    ifstream in("test.bin",ios_base::in|ios_base::binary);
    if(!in.is_open()){
        printf("read file fail");
    }
    in.read((char*)&f2,sizeof(f2));
    cout.setf(ios_base::fixed);
    cout<<f2<<endl;
    in.close();
    return 0;
}
