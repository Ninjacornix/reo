# Actor construction and shadow rendering

The File #1 o0 filename table at388B60 names SDT shadow assets such as
`data\rom\model\shadow\shadow_0000.sdt`. The pointer at388CA0 selects that
table for the actor constructors'377560 path. Its category2 branch reads the
definition's signed byteD and halfwordE, loads the selected shadow data, and
binds it through3777C0. That binder publishes the shadow header and its74
subsection into model1460/1464.

Direct actor-model loads of1460/1464 occur in the o0 shadow builders377800 and
377E30. The o2 consumer6B28E0 tests those bindings and chooses the shadow
rendering route377A70 or its fallback6B2AE0. The constructor follow-up3777B0
is a complete no-op. Main1AA740 also publishes the shadow data embedded in an
actor NBD bundle. These observations refine the earlier general auxiliary
geometry label into a concrete rendering role.

Native actor construction needs the definition's shadow selection and a
rendering request at its renderer boundary. Recreating the original SDT scratch
cache and original model pointers is outside Step4 gameplay ownership.
Shadow resource conversion and rendering belong to Step5. The actor's material
scroll task5D0C90 remains scheduling work in Step4 and can use the existing
native32-entry Scheduler. Its two float outputs are linked-family material
parameters atD24/D28.

This is a bounded static source and owned-data finding. It establishes the
reviewed constructor/render dependency, with no game execution or performance
measurement. Other source dataflow and actual renderer installation require
their own verification.
