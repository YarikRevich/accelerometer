#include "sequence.h"

template <typename T>
int Sequence<T>::traverse_with_break(std::function<int(T)> callback) {
    while (!sequence.empty()) {
        if (callback(sequence.front()) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }

        sequence.pop();
    }

    return EXIT_SUCCESS;
}

template <typename T>
void Sequence<T>::traverse_with_skip(std::function<int(T)> callback) {
    std::queue<T> vacated_queue;

    while (!sequence.empty()) {
        if (callback(sequence.front()) != EXIT_SUCCESS) {
            vacated_queue.push(sequence.front());
        }

        sequence.pop();
    }

    while (!vacated_queue.empty()) {
        sequence.push(vacated_queue.front());

        vacated_queue.pop();
    }
}

template <typename T>
void Sequence<T>::traverse_until_succeed(std::function<int(T)> callback) {
    while (!sequence.empty()) {
        if (callback(sequence.front()) != EXIT_SUCCESS) {
            continue;
        }

        sequence.pop();
    }
}

template <typename T>
void Sequence<T>::add(const T& src) {
    sequence.push(src);
}

template <typename T>
bool Sequence<T>::is_empty() {
    return sequence.empty();
}

template class Sequence<accelerometer::RequestContainer>;
template class Sequence<std::function<int()>>;