#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::iterator_traits;
using std::sort;
using std::unique;

template <class ExecutionPolicy, class It, class Compare, class Predicate>
vector<typename iterator_traits<It>::value_type>
unique_sorted(ExecutionPolicy&& policy, It first, It last, Compare comp, Predicate pred) noexcept
{
    using vector = vector<typename iterator_traits<It>::value_type>;

    try {
        sort(policy, first, last, comp);
        return vector(unique(policy, first, last, pred), last); 
    } catch (...) {
        return vector();
    }
}

