```plantuml
title

High-level design of "accelerometer"

end title

actor "Client"

component "Board control plain" {
entity "ProtocolBuffers"
node "Scheduler"
node "Device driver"


[Client] <--> [ProtocolBuffers]: " Send requests"
[ProtocolBuffers] --> [Scheduler]: " Schedule task"
[Scheduler] --> [Device driver]: " Retrieve ongoing data"
```