# Picture admission arithmetic and hysteresis

Next complete arithmetic cut: `1770F0`, `177240`, `1772B8` and the actual
`1501E8` cross-product comparator. The cached-clock query `176350` is an explicit
sample boundary here; its selected/cache owner is qualified separately. Preserve
its raw in/out words, opaque initial scratch and scripted post-query facts in
original execution. This cut does not qualify a live clock/provider binding.

A sampled denominator of 1 with numerator -2 admits immediately. Other
denominator-1 samples use the auxiliary counter: a negative counter becomes 0
and admits; otherwise compare signed64 cross-products, without float conversion
or denominator normalization. Other samples first add the signed quotient of
low32(sample denominator * slack) / global frequency to the sample numerator,
modulo32. The original integer divide-by-zero is excluded, not fabricated.

Convert signed query numerator/denominator and shifted sample words to binary32,
multiply numerators by 10000 before division, preserving each rounding. Selector
exactly 1 uses query <= current directly. Other selectors use the actual
tolerance/duplicate/hysteresis state machine. Keep raw cached decisions and
signed word count comparisons, including the special 59940 / signed rate < 3 /
increment 1000 threshold. Far-ahead/far-behind returns do not clear all state.

Original current-runtime FP emission is authoritative for this comparison,
including its ordered comparisons, NaN behavior and signed maximum-finite
zero-divisor result. Qualify all new compare/branch words against audited public
generated statements and pinned runtime macros before original execution. Do
not call Python float an original oracle or claim measured PS2 FPU equivalence.
The native core admits the verified nearest-rounding/masked-exception/no-flush
profile and restores the host FP environment after its work.

The native arithmetic core owns ordinary hysteresis fields and typed value
inputs. Mechanical guest layouts and register/FCR transport belong only in the
oracle/fixture. Original incidental FP register/FCR effects are recorded but are
not a native timestamp API or a complete guest ABI adapter. Public admission
bypass policies, frame returns, skip paths, shared guards, real provider lifetime
and one movie context remain separate stage 3 requirements; stages 4–6 follow.
