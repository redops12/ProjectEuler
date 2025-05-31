#include "prime.h"

using namespace std;

FactorizationIterator::FactorizationIterator(uint32_t num): done(false) {
    DFS start;
    start.max_div = 2;
    start.number = num;
    this->queue.push_back(start);

    // increment to find first value
    ++(*this);
}

std::vector<uint32_t> FactorizationIterator::operator*() const {
    return this->expansion;
}


FactorizationIterator& FactorizationIterator::operator++() {
    if (queue.empty()) {
        done = true;
        return *this;
    }

    while (!queue.empty()) {
        DFS curr = std::move(queue.back());
        queue.pop_back();
        if (curr.number == 1) {
            expansion = std::move(curr.current);
            break;
        }
        for (uint32_t i = curr.max_div; i <= curr.number; i++) {
            if (curr.number % i == 0) {
                DFS new_node;
                new_node.current = curr.current;
                new_node.current.push_back(i);
                new_node.max_div = i;
                new_node.number = curr.number / i;
                this->queue.push_back(new_node);
            }
        }
    }

    return *this;
}

bool FactorizationIterator::end() {
    return done;
}
