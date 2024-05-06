#include "indicator.h"

void Indicator::toggle_initialization_success() {
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(1000);
    }

    HAL_Delay(2000);
};

void Indicator::toggle_initialization_failure() {
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(200);
    }

    HAL_Delay(1000);
};

void Indicator::toggle_action_success() {
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(1000);
    }

    HAL_Delay(2000);
};

void Indicator::toggle_action_failure() {
    for (int i = 0; i < 4; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(200);
    }

    HAL_Delay(1000);
};

void Indicator::toggle_invalid_request() {
    for (int i = 0; i < 2; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(400);
    }

    HAL_Delay(1000);
}

void Indicator::toggle_invalid_response() {
    for (int i = 0; i < 2; i++) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        HAL_Delay(900);
    }

    HAL_Delay(2000);
}
