#include "mutex.h"

void Mutex::lock() {
    locked = true;
}

void Mutex::unlock() {
    locked = false;
}

bool Mutex::is_locked() const {
    return locked;
}