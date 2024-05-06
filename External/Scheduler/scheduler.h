#ifndef LIGHT_DETECTOR_SCHEDULER_H
#define LIGHT_DETECTOR_SCHEDULER_H

#include "scheduler_handler.h"
#include "state.h"
#include "indicator.h"

/**
 * Represents task scheduler implementation. Its methods are intended to be called to schedule tasks to be executed
 * in a main loop.
 */
class Scheduler {
public:
    /**
     * Schedules external loop tick action.
     */
    static void schedule_tick();

    /**
     * Schedules external button status check action.
     */
    static void schedule_status_check();

    /**
     * Schedules device configuration action.
     */
    static void schedule_configuration();
};

#endif //LIGHT_DETECTOR_SCHEDULER_H
