#include "state.h"

bool State::device_configured = false;

int State::current_response_nonce = 1;

Mutex State::button_mutex = Mutex();

Sequence<std::function<int()>> State::task_sequence =
        Sequence<std::function<int()>>();

Sequence<accelerometer::RequestContainer> State::request_container_sequence =
        Sequence<accelerometer::RequestContainer>();

bool State::is_device_configured() {
    return device_configured;
}

void State::set_device_configured(bool value) {
    device_configured = value;
}

int State::allocate_response_nonce() {
    return current_response_nonce++;
}

Mutex& State::get_button_mutex() {
    return button_mutex;
}

Sequence<std::function<int()>>* State::get_task_sequence() {
    return &task_sequence;
}

Sequence<accelerometer::RequestContainer>* State::get_request_container_sequence() {
    return &request_container_sequence;
}