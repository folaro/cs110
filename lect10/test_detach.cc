#include <iostream>
#include <thread>
#include<unistd.h>
using namespace std;

void func()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "from func():" << i << endl;
    }
}

int main()			//主线程
{
    thread t=thread(func);
	cout << "main()" << endl;
    cout << "main()" << endl;
    cout << "main()" << endl;
    t.detach();	    //分离子线程
    return 0;
}

