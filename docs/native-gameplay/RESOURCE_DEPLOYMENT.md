# Native resource deployment and position messages

`ResourceDeployment` implements5B5AF0 deployed-instance counting,5B2770 admission
(including its5B2890 deployment branch),5B26D0 effect dispatch and5B5CB0 placement.
It borrows the actual recipe/descriptor,64-model, factory, World and update owners.
Construction rejects foreign or unavailable owners. It creates no guest-layout
state or second gameplay pool.

Placement changes3201 to3200 through the actual content/rebind consumer, clears
ownership, adjusts flags, copies the actor room byte and position with Y+2, and
clears authored ID/angles. The current room comparison uses the full World room
against that stored byte. It creates the model and its actual bound visual
companions before assigning position/flags/resource identity and querying the
canonical floor grid for the draw layer. There is no height adjustment.

The original operation retains an existing primary and shared secondary. A
successful allocation replaces only the descriptor primary; the previous model
remains owned and live. Repeated placement can therefore leave several models
referencing one descriptor. Counting follows the actual model owner and tests
activity, visibility, content3200 and descriptor activity; it does not deduplicate
references. Eleven such instances reject the effect before actor/message work.
A naturally full model pool retains the converted descriptor and prior primary,
and the effect still returns4. Missing required capabilities refuse after their
known mutation prefix rather than inventing a successful placement.

The5B5940 position-message frontend belongs to the same `StatePublication` and
`Owner` as other gameplay messages. It preserves low16 resource, low8 actor and
operation, and the three raw float fields. Message phases1/2 require the input
position even when raw mode skips dispatch. Other phases need no input. The
actual queue/transport is an explicit required consumer; a completed dispatch
operation can include its intentional queue drop and does not promise delivery.

Qualification includes all six owned effect banks, four admitted primary NBD
banks and five ITEM banks. Source comparisons cover direct placement/effect,
room-byte truncation, mutation during the synchronous message callback,
repeated placement with real existing primary/secondary ownership, duplicate
references, all64 model counts, the eleven-instance limit and natural full-pool
behavior. Frontend comparisons include the complete16-bit narrowing domain,
every raw mode byte and raw floating-point payloads, without claiming arithmetic
parity for exceptional floats. Placement admits finite coordinates only.

The original factory, companion and floor helper boundaries use the already
qualified native consumers. Final message sinks remain declared ports; source
stack padding is not a native network format. Parent composition checks use
actual descriptors/models/update and verify off-room conversion, missing visual
consumers and full capacity. Exact paired compiler receipts and source identities
are sealed in `native_resource_deployment_qualification_v1.json`.

The outer item-effect dispatcher, weapon depletion, UI/network consumers, actor
families, actual gameplay installation and coherent scenario acceptance remain
open. Installed V39 is unchanged. This component does not close Stage4, and no
game or physical audio device was launched for these checks.
