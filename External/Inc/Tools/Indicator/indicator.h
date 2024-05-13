#ifndef LIGHT_DETECTOR_INDICATOR_H
#define LIGHT_DETECTOR_INDICATOR_H

#include "gpio.h"

/**
 * Represents indicator state machine.
 */
class Indicator {
public:
    /**
     * Indicated initialization process success.
     */
    static void toggle_initialization_success();

    /**
     * Indicated initialization process failure.
     */
    static void toggle_initialization_failure();

    /**
     * Indicated operation action success.
     */
    static void toggle_action_success();

    /**
     * Indicated operation action failure.
     */
    static void toggle_action_failure();

    /**
     * Indicated invalid incoming request.
     */
    static void toggle_invalid_request();

    /**
     * Indicated invalid outcoming response.
     */
    static void toggle_invalid_response();
};

#endif //LIGHT_DETECTOR_INDICATOR_H
