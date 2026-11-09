# Native animation surface audio

`BasicAudio::surface` implements complete 1B8D70 using the canonical World RNG,
Actor, current room lease, existing collision region owner and native bank
Session. It does not add another region pool. The actor's position selects the
region even when the special motion2B/secondary6D case plays at the listener.
The original byte9 is `secondary`, not `phase`.

Kinds0/1/4 consume the original random draw before footwear and room queries;
kinds2/3 use fixed cues. Category0 adds the signed footwear offset. Other
categories still play but do not inspect footwear. The two region selector bytes
produce one or two bank3 requests in order, including a second request after a
first rejected request. Actual native outcomes remain available separately.

Footwear uses24 bounded player appearances and125 admitted model variants,
extracted independently from owned o2 bytes. Character, appearance and model
variant are distinct canonical fields. Missing/unknown profiles refuse. Unknown
kinds also refuse: the source leaves a caller register unassigned on that path.
No runtime guest memory or register interpreter is introduced.

Paired LLVM/GCC comparisons each cover26820 complete surface calls and149
footwear leaf cases, issuing24585 real bank commands and comparing858240
mixed frames exactly. Four refusals check missing/stale room identity, invalid
appearance and invalid kind, including the preceding RNG effects. The bank is a
controlled valid128-sequence fixture. Original commands drive an independent
native Session for request-state and PCM comparison.

The original region-selection call deliberately reuses the already qualified
native `regions::World`; this cohort does not independently re-prove geometry
selection. Its separate qualification compares complete574680 against164 owned
assets. Canonical camera surroundings similarly reuse the audio qualification.
Node/scenario-remapped audio, named bank installation, real gameplay acceptance
and the rest of Stage4 remain open. No game is launched by these checks.
