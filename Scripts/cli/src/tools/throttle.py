import time

# Represents throttle shutdown duration time.
THROTTLE_SHUTDOWN_DURATION: int = 30

# Represents throttle request duration time.
THROTTLE_REQUEST_DURATION: float = 0.2


def perform_shutdown_await() -> None:
    """Performs throttle shutdown operation."""

    time.sleep(THROTTLE_SHUTDOWN_DURATION)


def perform_request_await() -> None:
    """Performs throttle request operation."""

    time.sleep(THROTTLE_REQUEST_DURATION)
