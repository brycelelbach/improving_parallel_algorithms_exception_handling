#include <algorithm>
#include <iterator>

using std::iterator_traits;
using std::sort;
using std::unique;

template <class ExecutionPolicy, class It, class Compare, class Predicate>
It unique_sort(ExecutionPolicy&& policy, It first, It last, Compare comp, Predicate pred) noexcept
{
    sort(policy, first, last, comp);
    return unique(policy, first, last, pred); 
}

