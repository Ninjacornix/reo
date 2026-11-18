# Native actor and menu input

The game-facing input core owns button edges, held history, repeat timing,
eight analog values, layout remapping and actor/controller routing. Its input
is a normalized native controller frame. It does not parse PS2 packets, perform
RPC, simulate registers or read guest memory.

Mode 1 updates the selected actor from controller zero. Mode 0 updates a
non-AI actor from controller zero. Other modes use the actor's explicit signed
controller binding, with -1 meaning no source. These skipped paths leave the
previous actor frame intact. Remapping happens before actor edges are computed;
menu edges are computed before direction bits are folded and the action mask
is remapped. Actor routing preserves the repeat fields that its original entry
does not write.

Repeat timers count invocations. A fresh directional press repeats the entire
pressed word and starts at 12. Held directions decrement the signed wrapping
timer and repeat the entire held word when it becomes negative, restarting at
2. Other buttons retain their separate mask behavior. No host key-repeat or
wall-clock conversion is substituted.

Both compilers pass 196,608 comparisons executing the three complete owned
original entry bodies: repeat, actor routing, and menu snapshot construction.
The actor cohort updates 36,453 frames and preserves 29,083 skipped frames.
All six owned layout rows are used. Four additional cases verify atomic
rejection of invalid negative/out-of-range source, actor and layout indices.
Those refused invalid inputs are a native admission policy, not asserted
original behavior. The [qualification](../../tools/native_reconstruction/native_gameplay_actor_input_qualification_v1.json)
binds compiled sources, owned instruction/data evidence, tools and results.

This does not yet replace actual actor/menu callers, migrate platform sampling
and deadzone/direction normalization, or validate physical controls in a game.
The original session-mode getters are declared pure fixture providers. Earlier
failed compilations retained missing fixture declarations/macros and GCC
indentation diagnostics; final matching sources pass both cohorts.
