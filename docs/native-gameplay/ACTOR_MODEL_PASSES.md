# Native primary and auxiliary model frame passes

Status: implemented native components, uninstalled in the game. Stage 4 remains
incomplete. No game, window, device or rendering backend was started for these
checks.

`ActorModelPasses` reconstructs the complete primary `3769F0` and auxiliary
`376AE0` traversals. The primary pass examines all eight physical slots in order.
The auxiliary pass reads the canonical pool head and follows its next link after
each update. Both gate only on activity; hidden actors still receive model work.

The primary pass calls the existing complete native model/constraint owner, then
attaches the selected resource at node19 and the secondary resource at node15.
The auxiliary pass uses the original standard publication policy and attaches
only the selected resource at node19. They borrow the canonical World, resource
attachment owner, immutable floor grid and admitted correction metadata. They do
not create a second actor, resource table, model instance or simulation clock.

The passes retain original mutation prefixes on failures, validate actor identity
after lower consumers, and release traversal guards on exceptions. World close
and pass reentry are refused while a pass runs. Auxiliary allocation/removal keep
the existing source-backed pool policy; the pass does not add a blanket ban on
same-pass entity mutation. Retained pose snapshots remain independent.

`ActorModelWorkers` binds both passes at the actual
`primary_model_poses`/`auxiliary_model_poses` positions in `Update::Owner`.
Remaining workers and phase effects stay with their explicit owner. Closed or
foreign Update owners refuse before publication. Missing script programs or
failed model publication do not produce a successful frame result.

## Source comparison

Run `animation/verify_constrained_attachments.py --actor-passes` with the owned
model corpus and current collision-response receipt. The qualifier freezes the
complete source/include closure and executes complete original model, hierarchy,
constraint and attachment bodies. The `actor-model-passes-{llvm,gcc}-v5` cohorts
both pass873,149 checks and11,976,168 original boundary invocations:

- 512 primary and512 auxiliary traversal cases, each with two consecutive visits;
- all primary activity masks, auxiliary lengths/list insertion orders, hidden
  active actors and inactive records;
- exact node parameters, caches, local/world matrices and every actor basis;
- 928 retained snapshot checks and four lifetime/failure/reentry checks;
- the parent800 grounded cases,1,600 actual resource attachments,480 surface-one
  queries,255 pause patterns and600 sampled poses.

The traversal fixture deliberately shares one real imported model between its
actors, making traversal order observable in the final publication. It uses
both owned skeletons. Independent model/constraint/resource-attachment
composition runs in the same cohort. This is not a claim of loading a complete
stock room with every actor's distinct model and equipment.

Draft failures remain recorded: v1 used the wrong receipt status label; v2 found
a missing navigation-library unit in the old qualifier closure; v4 imposed an
incorrect fixture expectation that auxiliary allocation was forbidden during
updates. The production pass was not changed to satisfy that incorrect policy.

The focused CMake worker test exercises actual Update traversal, late activation
before model work, publication before hit work, old-pose retention, pause,
missing-program admission, a missing model, failure recovery and foreign owners.
It supplies explicit fixture providers for other frame work; it does not claim
those other services have been migrated.

## Remaining integration

A native session still must construct these owners with actual room/model,
resource and floor assets and bind the remaining behavior, postprocess,
collision, scene, UI, input and media consumers. Ordinary `5FED00` calls these
model stages before `66A3A0`; cinematic `5FF1B0` calls the auxiliary stage after
the separate temporary-player model publication and before reactions. Full
cinematic orchestration, coherent native gameplay installation and controlled
game acceptance remain open. Renderer migration belongs to Stage 5.
