#include "scheduler.h"

void Scheduler::schedule_tick() {
    State::get_task_sequence()->add([]() -> int {
        if (SchedulerHandler::handle_request() != EXIT_SUCCESS) {
            Indicator::toggle_invalid_request();

            return EXIT_FAILURE;
        }
//
//        if (SchedulerHandler::handle_response() != EXIT_SUCCESS) {
//            Indicator::toggle_invalid_response();
//
//            return EXIT_FAILURE;
//        }

        return EXIT_SUCCESS;
    });
}

void Scheduler::schedule_status_check() {
    State::get_task_sequence()->add([]() -> int {
        if (State::is_device_configured() && LIS2DW12::is_available()) {
            Indicator::toggle_action_success();
        } else {
            Indicator::toggle_action_failure();
        }

        State::get_button_mutex().unlock();

        return EXIT_SUCCESS;
    });
}

void Scheduler::schedule_configuration() {
    State::get_task_sequence()->add([]() -> int {
        if (LIS2DW12::is_available()) {
            LIS2DW12::init();

            State::set_device_configured(true);

            Indicator::toggle_initialization_success();

            return EXIT_SUCCESS;
        } else {
            Indicator::toggle_initialization_failure();

            return EXIT_FAILURE;
        }
    });
}