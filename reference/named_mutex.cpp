#include <boost/interprocess/sync/scoped_lock.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <fstream>
#include <iostream>
#include <cstdio>

using std::vector;
using std::for_each;

int main()
{
    namespace ipc = boost::interprocess;

    ipc::named_mutex mutex(ipc::open_or_create, "my_mutex");

    ipc::scoped_lock<ipc::named_mutex> lock(mutex);

    vector<double> d = // ...

    try {
        for_each(par_vec, d.begin(), d.end(), my_function);
    } catch (my_exception& me) {
        // ...
    }
}

