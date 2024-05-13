#ifndef LIGHT_DETECTOR_SEQUENCE_H
#define LIGHT_DETECTOR_SEQUENCE_H

#include <queue>
#include <functional>
#include <cstdlib>

#include "stm32l4xx_hal.h"

#include "request.h"

/**
 * Represents sequence wrapper implementation.
 *
 * @tparam T given type of the content for sequence.
 */
template <typename T>
class Sequence {
public:
    /**
     * Iterates over all available content and removes it from the sequence. If error occurs, then the execution
     * is stopped and task is still present in the loop.
     *
     * @param callback - given callback to be called for each iteration.
     * @return status of the performed operation.
     */
    int traverse_with_break(std::function<int(T)> callback);

    /**
     * Iterates over all available content and removes it from the sequence. If error occurs, then the execution is skipped
     * and task is still present in the loop.
     *
     * @param callback - given callback to be called for each iteration.
     */
    void traverse_with_skip(std::function<int(T)> callback);

    /**
     * Iterates over all available content and removes it from the sequence. If error occurs, then the execution
     * continues until all the operations are successful.
     *
     * @param callback - given callback to be called for each iteration.
     */
    void traverse_until_succeed(std::function<int(T)> callback);

    /**
     * Adds new value to the sequence.
     *
     * @param src - given value to be added to the sequence.
     */
    void add(const T& src);

    /**
     * Checks if the sequence is empty.
     *
     * @return result of the check.
     */
    bool is_empty();
private:
    std::queue<T> sequence;
};

#endif //LIGHT_DETECTOR_SEQUENCE_H
