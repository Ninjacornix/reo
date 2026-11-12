# Facial matrix blending

blend_facial_pose implements complete67C990 over one node's six MAT matrices.
It preserves the original separate multiply/add order for the first two basis
directions and translation. The six weights are used directly, without an
invented sum-to-one normalization. Source matrix W lanes and the third direction
are not consumed. A private result is published only after evaluation completes.

facial_basis implements1A5050 and its scalar1A5180/1A51B0/1A5220 children.
It normalizes the first two directions, normalizes their cross product, then
reconstructs the second direction from the third and first. Exact zero vectors
remain zero. Output W lanes become0/0/0/1 and the supplied translation words
survive unchanged, including arbitrary bit patterns which this helper does not
consume arithmetically. The surrounding67C990 path uses the verified initialized
identity profile through complete18FDF0 and copies the final matrix through191500.

Both compilers pass1,055,527 checks in v5:265,600 blends,262,144 direct basis
rebuilds,224,695 input/output aliases and5,546,496 original calls. Synthetic
cases include zero weights, zero/parallel directions, negative weights and
arbitrary unconsumed lanes. The whole seven original source bodies execute;
195E50 is word-audited static authority for the identity-cache initialization,
rather than a claim that the complete bootstrap executes in this fixture.

The owned asset portion pairs all18 HP/HN MAT payloads with their corresponding
base actor NBDs. Their actual raw skeletons each contain six track4 nodes, so
3,456 samples exercise exactly those six consumed ordinals. This bound matters:
HP03/HN39 contain nonfinite data in unused matrix ordinal6. The earlier v2/v3
fixture incorrectly tried all eight storage slots, and the finite-profile refusal
exposed that mistake. The corrected asset audit retains those bytes and derives
the admitted ordinal count from the real model graph. It does not substitute
zeros, broaden the numeric contract or establish every later runtime relabel.

V1 retained missing oracle-macro and strict fixture-indentation failures. V2/v3
retained the actual unused-slot boundary finding. V4/v5 include the paired NBD
audit and pass both compilers. Production contains ordinary typed matrix/vector
math; original contexts and addressed test memory remain in the offline oracle.

This is the reached mathematical component. Facial workspace lifetime and
overlapping sector loads, matrix-key reload behavior, lip curves, eight-instance
ownership, actual actor joint patching and complete cinematic/session/game
installation remain separate work. Finite consumed FP32 inputs/intermediates and
nearest rounding are admitted; physical PS2 exceptional arithmetic is not claimed.

Current actor-model-classes parent28 v2 passes both compilers with the production
Animation CMake registration and no source drift. This establishes the current
library build; actual facial owner/joint adoption is still separate. The
[scoped seal](../../tools/native_reconstruction/native_facial_pose_math_qualification_v1.json)
records the exact four component/current-build receipts.
