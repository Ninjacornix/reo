# Scenario startup scene state

The native scenario interpreter handles the cutscene request wrapper (`0x62`),
actor roster condition (`0xEA`), and auxiliary scene controls (`0x120`–`0x122`).
The canonical Session owns the requests, limit override, row selection, and
hold timers. The update owner advances the timers after the sequence worker
and skips that work during pause, in the original order.

The cutscene wrapper packs five low halfwords into a 16-entry queue and sets
the canonical pause state. Selected actor flags can substitute the owned
fallback request, skip the append, or return early. The forced terminal branch
requires a typed provider and refuses a missing provider before mutating the
queue. Playback, forced terminal effects, and scene transitions still need
their actual native consumers.

The roster condition checks character presence in the full admitted primary
population, including inactive actors. The auxiliary row importer verifies
relative offsets and uses the original row and room indexing. Successful
scenario binding publishes the rows with the new script channels. A failed
import keeps the previous rows and channels. Timer commands preserve the
original signed-index aliases from −31 through −1.

LLVM and GCC each pass 21,395,327 checks, including 2,048 original cutscene
wrapper calls, 512 ordinary/offline roster dispatches, 512 combined scene
dispatches, 4,096 auxiliary timer checks, and 1,043 owned row cells from the five
retail EVBs. The original forced terminal child is represented by an explicit
test port. The comparisons use isolated native owners and original source
bodies. Live scenario installation and game testing remain open.
