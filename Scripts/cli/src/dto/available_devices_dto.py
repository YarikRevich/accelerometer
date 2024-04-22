class AvailableDevicesDto:
    """Represents dto used to hold result of 'list_available_devices' command."""

    # Represents a shortened description of the connected device.
    description: str

    # Represents a manufacturer of the connected device.
    manufacturer: str

    # Represents physical location of the device in the operating system.
    location: str

    def __init__(self, description: str, manufacturer: str, location: str):
        self.description = description
        self.manufacturer = manufacturer
        self.location = location
