# Real resource consumers behind scenario commands

ResourceFactory now implements SceneEffects with the actual qualified primary
placement, alternate collision construction, primary/shared-secondary release
and descriptor deactivation consumers. It validates canonical descriptor/world
ownership; release/deactivation preserve the caller's byte instance index. These
are real native state changes through existing owners, replacing construction
and release-only fixture seams for the admitted command profiles.

SceneEffects now returns SceneStatus. SceneResources propagates a failed effect,
including release during detach, and the existing interpreter converts it into
provider_unavailable. Earlier flag changes remain visible. A missing scene
binding, special unimplemented companion or unknown attachment can no longer
be reported as a completed effect. Natural pool exhaustion remains a measured
known absence, as in the original command flow. Actor detach/refresh providers
and extended actor ownership remain separate gates.

Both compiler suites pass14,304,213 combined assertions.384 real command cases
cover active/kind eligibility, room mismatch, three ownership profiles, four
primary/secondary combinations and ordered enable/force/alternate/disable
sequences.96 direct retirement cases use the actual deactivation consumer.
Four failure cases check missing scene binding, an unimplemented companion,
secondary release refusal with a still-live primary and a foreign owner.
The complete original command, lookup and release bodies execute together with
the existing actual native factory/placement/delayed/static/visual consumers.

Both current, unpinned full scenario regressions additionally pass14,067,135
checks and30,185 original invocations. Their ordinary327/offline300 admitted
entries include no-op entries; these figures are not game migration percentages
and do not claim every required stock script is runnable. The focused descriptor
regressions pass10,610 checks and2,589 invocations. Parent builds and all four
World/collision checks pass. Sources and outputs are sealed in
`native_resource_scenario_actions_qualification_v1.json`.

The four command consumers are available for the admitted native context. Actual
room/asset installers, actor inventory detachment, the remaining special visual
families and coherent gameplay installation are still open. No game was launched;
the installed game remains V39 and Stage4 remains incomplete.
