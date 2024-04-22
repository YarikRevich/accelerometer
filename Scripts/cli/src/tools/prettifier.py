import beeprint


def print_output(src: object) -> None:
    """Prints given object in a pretty way. Given object is supposed to be a data holder."""

    beeprint.pp(src)
