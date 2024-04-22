#ifndef LIGHT_DETECTOR_MUTEX_H
#define LIGHT_DETECTOR_MUTEX_H

/**
 * Represents mutex thread-safe implementation. Due to STM32 limitations, mutex represents simple state machine.
 */
class Mutex {
public:
    /**
     * Locks mutex state.
     */
    void lock();

    /**
     * Unlocks mutex state.
     */
    void unlock();

    /**
     * Retrieves current state of the mutex.
     *
     * @return retrieved state of the mutex.
     */
    bool is_locked() const;
private:
    /**
     * Represents current state of the mutex.
     */
    bool locked;
};

#endif //LIGHT_DETECTOR_MUTEX_H
