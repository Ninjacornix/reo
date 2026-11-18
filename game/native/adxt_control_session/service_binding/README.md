# Canonical serviced-clock binding qualification

The private control owner supplies the actual group and retained target to the
qualified completion and publishes its result into the same player's clock.
Callers provide a session/generation key and tick, never a replacement port.

See the [contract](../../../../docs/native-media/ADXT_SERVICE_BINDING_CONTRACT.md)
and [evidence](../../../../docs/native-media/ADXT_SERVICE_BINDING_IMPLEMENTATION.md).
Verification freezes actual plain/scheduled measurements before original replay.
Scheduled and stale sources are generated only under private build artifacts;
the production control session contains no callback scheduling hook.
