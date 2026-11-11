# Owned cutscene descriptor inventory

This is a bounds-checked asset layout inventory, not original parser execution,
game acceptance, a new slowdown measurement or proof that a file is reachable.
The reproducible tool is audit_cutscene_descriptors.py. Its immutable receipt
is build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json.

The five selected File1 scenario archives contain690 named DM members in the
inspected naming scope. Every selected payload matches the prior owned member
inventory's size/hash. Header versions are548 `0950`,132 `0930` and10 `0940`.
The bounded5F15A0 layout walk admits all548 version0950 members, including the
complete extension/tail sections. None requires the terminal-only optional
tail branch. Other versions remain unadmitted; they are not asserted unused.

The0950 inputs contain1469 actor groups and10283 actor command streams,
excluding their eighth header streams. Of these,7007 are single-record
terminal-only streams. Other first-seven stream counts range2..6. A parser
that demands a real event before every terminal would reject valid authored
content. The native stream owner now retains the single terminal as idle
state during ordinary scene frames. If the caller advances to a frame that
would consume beyond that last record, native code refuses the unsupported
continuation rather than reading a neighboring section.

Seventeen0950 inputs declare more than16 actor groups; the maximum is32.
Examples include r028's dm0000A and dm1600A..H/dm1601A..dm1607A/dm1700A.
In dm1600A the32 header streams are live, with one reused actor and31 linked
actors. The decimal actor definition5500 splits into type55/variant0 in the
actual5F0610 caller; it is not a literal out-of-range model type5500. This
inventory motivates the native32-group ownership bound. It does not establish
that these particular inputs run in a player session or that every constructor
and asset combination is currently admitted.

The original parser's actor stream pointer array accommodates32 groups, but
the later scene actor descriptor writes have a different footprint. For
example, group31 kind at38ECA0+8C*31+138 is38FECC, the same address as group27
stream3's pointer at38FB60+20*27+C. The following actor pointer aliases stream4.
This is static address arithmetic, not a measured corruption diagnosis. Whether
those writes and reads occur in a reachable scene and affect its valid frame
range still needs source/lifecycle and game acceptance evidence. Native typed
group ownership keeps those domains separate and does not reproduce that RAM
alias as a compatibility requirement.

The preliminary v1 inventory walked versions without explicit admission and
reported132 bounds failures plus ten superficially walkable old-version files.
The reproducible v2 tool selects0950 explicitly and classifies the142 other
versions separately. It does not call those older payloads malformed based on
the wrong layout. The next native descriptor importer must preserve this
distinction and investigate required legacy formats before stock-wide install.

The audit verifies complete original5F15A0 and5ED900 instruction words. The
latter appends a-1 word after a successful read, so an optional-tail EOF has an
explicit caller contract rather than arbitrary synthetic padding. No inspected
0950 member needs that interpretation, but controlled parser qualification
must cover it alongside the explicit terminal branch and untouched prior views.

The package contains the548 unchanged owned0950 payloads for local comparisons.
Its SHA-256 is047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c.
It is not distributed game content. Complete typed descriptor import, actual
actor/resource assignment, remaining stream consumers, legacy reachability and
installed gameplay acceptance remain open. Step4 remains incomplete.
