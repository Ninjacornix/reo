# Retained native AFS hierarchy

Bounded numeric archive traversal over immutable, retained native byte views.
The original-qualified AFS binder supplies real sector extents. Logical leaf
lengths never authorize synthetic padding or reads outside the retained parent.

See the [contract](../../../docs/native-media/IMPORTED_ADXT_SOURCE_CONTRACT.md)
and [implementation evidence](../../../docs/native-media/IMPORTED_ADXT_SOURCE_IMPLEMENTATION.md).
`manifest.json` freezes the implementation and actual-import fixture inputs;
`qualification.json` separately pins the later verifier, comparator and reports.
No production selector, dependency build or default is changed.
