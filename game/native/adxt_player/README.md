# Independent single-resource ADXT player

The [contract](../../../docs/native-media/ADXT_PLAYER_COMPOSITION_CONTRACT.md)
defines source, decode, PCM-copy, playback-control and output-provider ownership.
This is an isolated composition, not a production backend or complete stage3.

Only the callback renderer may run concurrently with the serialized control
owner. Callback storage contains no decoder/player alias. Stereo copies become
visible atomically; decoder credit returns after an accepted output copy.
Provider and encoded-source joins remain separate observations. Failed joins
retain both queues for retry. The fixed test provider opens no audio device.

Build `adxt_player_tests` from the standalone `game/native` CMake project.
`verify.py` pins exact sources and reruns the inherited original decoder
comparisons plus real-source/composed-output ownership checks. Asset checks
compare copied payload prefixes with the separately qualified native decoder.
Neither comparison establishes original whole-player scheduling or audible PCM
parity. The player does not implement the full pause/clock API, LSC or shared
bank/stream output routing.
