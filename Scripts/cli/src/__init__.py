import logging
from pathlib import Path

import sys

sys.path.insert(0, "./")

# Initializes logger general configuration.
logging.basicConfig(
    filename=f"{str(Path.home())}/accelerometer-cli.log", level=logging.INFO, filemode='w', format='%(name)s - %(message)s')